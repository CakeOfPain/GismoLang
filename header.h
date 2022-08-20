#ifndef header_h
#define header_h

// **Structs & Unions**

// Tokenizer:

struct Token;
struct Tokenizer;
enum TokenTypes;
union TokenValue;

// Parser:

struct Parser;

enum NodeTypes;
struct SyntaxNode;

struct BinOpNode;
struct UnaryOpNode;
struct ValueNode;
struct FunctionCallNode;
struct SquareCallNode;

struct FunctionNode;
struct IfNode;
struct ForNode;
struct StatementsNode;
struct ReturnNode;
struct ArgumentNode;
struct VanguardNode;

struct ProgramsNode;
struct ImplementNode;
struct UnaryInstructionNode;

// CodeGenerator:

struct CodeGenerator;
struct SymbolTable;
struct Symbol;
struct Scope;

// ByteWriter:

struct ByteWriter;


// **Functions**

// Tokenizer: 

struct Tokenizer Tokenizer_getTokens(const char* code, const char* file_path);
void Tokenizer_clear(struct Tokenizer tokenizer);
char Tokenizer_nextCharacter(struct Tokenizer* tokenizer);
void Tokenizer_addToken(struct Tokenizer* tokenizer, struct Token token);
struct Token Tokenizer_getNumber(struct Tokenizer* tokenizer, char firstCharacter);
char Tokenizer_peekNextCharacter(struct Tokenizer* tokenizer);
void Tokenizer_getWord(struct Tokenizer* tokenizer, char beginning, char* buffer);
char isIdentifierCharacter(char character);
struct Token Tokenizer_readString(struct Tokenizer* tokenizer);

void markPosError(const char* srcCode, unsigned int line, unsigned short begin, unsigned short end);
void markTokenError(struct Token token);

// Parser:
struct Parser Parser_build(struct Tokenizer* tokenizer);
void Parser_clear(struct Parser parser);
struct Token Parser_nextToken(struct Parser* parser);
struct Token Parser_peekNextToken(struct Parser* parser);
struct Token Parser_peekTwiceNextToken(struct Parser* parser);
void Parser_getBracket(struct Parser* parser, struct Token* tokens);

void Parser_addLibPath(struct Parser* parser, char* path);

struct SyntaxNode newBinOpNode(struct SyntaxNode left, struct Token operator, struct SyntaxNode right);
struct SyntaxNode newUnaryOpNode(struct Token operator, struct SyntaxNode operand);

struct SyntaxNode newFunctionNode(struct SyntaxNode arguments, struct SyntaxNode statements, struct Token name, struct Token returnType, unsigned char returns_array);
struct SyntaxNode newIfNode(struct SyntaxNode statements, struct SyntaxNode elseStatements, struct SyntaxNode condition, struct Token ifNode);
struct SyntaxNode newForNode(struct SyntaxNode statements, struct SyntaxNode init, struct SyntaxNode contition, struct SyntaxNode action);
struct SyntaxNode newStatementsNode(struct SyntaxNode first, struct SyntaxNode second);
struct SyntaxNode newReturnNode(struct SyntaxNode expression);
struct SyntaxNode newArgumentNode(struct Token type, unsigned char is_array, struct Token name, struct SyntaxNode next);
struct SyntaxNode newVanguardNode(struct SyntaxNode functionDeclaration);
struct SyntaxNode newValueNode(struct Token value);
struct SyntaxNode newImplementNode(struct Token implementToken, struct Token declaration, struct Token library, struct Token identifier);

struct SyntaxNode newFunctionCallNode(struct SyntaxNode identifier);
struct SyntaxNode newSquareCallNode(struct SyntaxNode identifier);
void FunctionCallNode_add(struct SyntaxNode functionCallNode, struct SyntaxNode argument);
void SquareCallNode_add(struct SyntaxNode squareCallNode, struct SyntaxNode argument);

struct SyntaxNode Parser_parseLiteral(struct Parser* parser);
int Parser_getBinOpPrecedence(struct Token token);
int Parser_getUnaryOpPrecedence(struct Token token);
struct SyntaxNode Parser_parseExpression(struct Parser* parser, int parentPrecedence);

struct SyntaxNode Parser_parseStatement(struct Parser* parser);
struct SyntaxNode Parser_parseGlobalDeclaration(struct Parser* parser);

void Parser_parseSeperator(struct Parser* parser);
void Parser_ignoreNewLine(struct Parser* parser);

struct SyntaxNode Parser_parseArguments(struct Parser* parser);
struct SyntaxNode Parser_parseFunctionDeclaration(struct Parser* parser);

struct SyntaxNode Parser_parse(struct Parser* parser);

void Parser_prettyPrint(struct SyntaxNode tree);
void Parser_clearAST(struct SyntaxNode node);

// CodeGenerator:

struct CodeGenerator* CodeGenerator_build(struct Parser* parser);
void CodeGenerator_clear(struct CodeGenerator codeGenerator);

// Function definitions
void CodeGenerator_generate(struct CodeGenerator* codeGenerator);
void CodeGenerator_generateProgram(struct CodeGenerator* codeGenerator, struct SyntaxNode program);
unsigned char CodeGenerator_generateStatement(struct CodeGenerator* codeGenerator, struct SyntaxNode node, struct Scope scope, struct ByteWriter* byteWriter);
unsigned char CodeGenerator_generateExpression(struct CodeGenerator* codeGenerator, struct SyntaxNode node, struct Scope scope, struct ByteWriter* byteWriter);
void CodeGenerator_includeLibWithOutNamespace (struct CodeGenerator* codeGenerator, char* path);
void CodeGenerator_generateLogFunctionEnter(struct CodeGenerator *codeGenerator, struct FunctionCallNode fncall, struct Symbol fn, struct Scope scope, struct ByteWriter *byteWriter);
void CodeGenerator_generateLogFunctionLeave(struct CodeGenerator *codeGenerator, struct FunctionCallNode fncall, struct Symbol fn, struct Scope scope, struct ByteWriter *byteWriter);

// DAO things

unsigned char CodeGenerator_storeSymbol(struct CodeGenerator* codeGenerator, struct Symbol symbol, unsigned char type, struct Scope scope, struct ByteWriter* byteWriter);

// There must be a function for declaring a variable and a function for define one.
// So that the compiler is able to know at least the variable exists and then can allocate it.

// Allocation
struct Symbol VariableTable_declareVariable(struct SymbolTable* table, struct Token value, struct Scope scope);
unsigned int VariableTable_defineVariable(struct SymbolTable* table, struct Token name, unsigned char type);
// Query
struct Symbol VariableTable_findVariableByName(struct SymbolTable* table, struct Token value);
// Private:
struct Symbol* VariableTable_findVariableReferenceByName(struct SymbolTable* table, struct Token value);
struct Symbol VariableTable_findVariableByIndex(struct SymbolTable* table, unsigned int index, unsigned char type, struct Scope scope);
// Private:
struct Symbol VariableTable_findConstantByIndex(struct SymbolTable* table, unsigned int index, unsigned char type);

unsigned int VariableTable_createReferenceByName(struct SymbolTable* table, struct Token value, struct Token refName);

void VariableTable_setVariableByName(struct SymbolTable* table, struct Token value, struct Symbol vardec);
void VariableTable_setConstantByIndex(struct SymbolTable* table, unsigned int index, unsigned char type, struct Symbol vardec);

void VariableTable_removeAllLocal(struct SymbolTable* table);
void VariableTable_removeDeclaration(struct SymbolTable* table, unsigned int index);
void VariableTable_listAll(struct SymbolTable* table);

// struct VarDec* VariableTable_matchVariable(struct VariableTable* table, struct Token value, unsigned char scope, unsigned int location);
// void VariableTable_setVariable(struct VariableTable* table, struct Token value, unsigned char type, unsigned char scope, unsigned int location, struct VarDec vardec);

struct Symbol* VariableTable_addDeclaration(struct SymbolTable* table);

// ByteWriter:

struct ByteWriter ByteWriter_init(char** str, unsigned int* length);

void ByteWriter_writeByte(struct ByteWriter* byteWriter, unsigned char byte);
void ByteWriter_writeUShort(struct ByteWriter* byteWriter, unsigned short value);
void ByteWriter_writeShort(struct ByteWriter* byteWriter, short value);
void ByteWriter_writeUInt(struct ByteWriter* byteWriter, unsigned int value);
void ByteWriter_writeInt(struct ByteWriter* byteWriter, int value);
void ByteWriter_writeFloat(struct ByteWriter* byteWriter, float value);
void ByteWriter_writeULongLong(struct ByteWriter* byteWriter, unsigned long long value);
void ByteWriter_writeLongLong(struct ByteWriter* byteWriter, long long value);
void ByteWriter_writeDouble(struct ByteWriter* byteWriter, double value);
void ByteWriter_addOps(struct ByteWriter* byteWriter, char* ops, unsigned int length);


#endif