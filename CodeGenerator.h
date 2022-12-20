#ifndef CodeGenerator_h
#define CodeGenerator_h

#define BC_NOP                      0

// *** NUMBER OPERATORS:

// Load and Store:
#define BC_LOAD_CONST_NUM8          1
#define BC_LOAD_CONST_NUM16         2
#define BC_LOAD_CONST_NUM32         3
#define BC_LOAD_CONST_NUM64         4

#define BC_LOAD_GLOBAL_NUM8         5
#define BC_LOAD_GLOBAL_NUM16        6
#define BC_LOAD_GLOBAL_NUM32        7
#define BC_LOAD_GLOBAL_NUM64        8

#define BC_STORE_GLOBAL_NUM8        9
#define BC_STORE_GLOBAL_NUM16       10
#define BC_STORE_GLOBAL_NUM32       11
#define BC_STORE_GLOBAL_NUM64       12

#define BC_LOAD_STACK_NUM8          13
#define BC_LOAD_STACK_NUM16         14
#define BC_LOAD_STACK_NUM32         15
#define BC_LOAD_STACK_NUM64         16

#define BC_STORE_STACK_NUM8         17
#define BC_STORE_STACK_NUM16        18
#define BC_STORE_STACK_NUM32        19
#define BC_STORE_STACK_NUM64        20


// Aritmetic:
#define BC_ADD_I                    21
#define BC_ADD_U                    22
#define BC_ADD_F                    23

#define BC_SUB_I                    24      
#define BC_SUB_U                    25
#define BC_SUB_F                    26

#define BC_MUL_I                    27
#define BC_MUL_U                    28
#define BC_MUL_F                    29

#define BC_DIV_I                    30
#define BC_DIV_U                    31
#define BC_DIV_F                    32


// Logical:
#define BC_AND                      33
#define BC_OR                       34
#define BC_NOT                      35

// Compare:
#define BC_EQ_I                     36
#define BC_EQ_U                     37
#define BC_EQ_F                     38

#define BC_EQ_IU                    39
#define BC_EQ_FI                    40
#define BC_EQ_FU                    41

#define BC_BIGGER_I                 42
#define BC_BIGGER_U                 43
#define BC_BIGGER_F                 44

#define BC_BIGGER_IU                45
#define BC_BIGGER_FI                46
#define BC_BIGGER_FU                47

#define BC_SMALLER_I                48
#define BC_SMALLER_U                49
#define BC_SMALLER_F                50

#define BC_SMALLER_IU               51
#define BC_SMALLER_FI               52
#define BC_SMALLER_FU               53

// *** COLLECTION OPERATORS:

#define BC_LOAD_GLOBAL_COLLECTION   54
#define BC_LOAD_STACK_COLLECTION    55

#define BC_STORE_GLOBAL_COLLECTION  56
#define BC_STORE_STACK_COLLECTION   57

#define BC_ADD_ELEMENT              58

#define BC_REMOVE_ELEMENT           59

#define BC_SIZEOF_COLLECTION        60

#define BC_LOAD_ELEMENT             61

#define BC_STORE_ELEMENT            62

// *** FUNCTION OPERATORS:

#define BC_LOAD_CONST_FUNC          63
#define BC_LOAD_GLOBAL_FUNC         64
#define BC_LOAD_STACK_FUNC          65

#define BC_STORE_GLOBAL_FUNC        66
#define BC_STORE_STACK_FUNC         67

#define BC_CALL_FUNC                68
#define BC_RETURN_ELEMENT           69

// *** STACK OPERATORS:

#define BC_POP                      70
#define BC_SWAP                     71
#define BC_ROT                      72

// *** EXIT OPERATORS:

#define BC_EXIT                     73

// *** TEXT OPERATORS:

#define BC_LOAD_CONST_TEXT          74
#define BC_LOAD_GLOBAL_TEXT         75
#define BC_LOAD_STACK_TEXT          76

#define BC_STORE_GLOBAL_TEXT        77
#define BC_STORE_STACK_TEXT         78

#define BC_TEXT_ADD_CHAR            79
#define BC_TEXT_REMOVE_CHAR         80
#define BC_TEXT_POP_CHAR            81
#define BC_TEXT_GETSIZE             82
#define BC_TEXT_GET_CHAR            83

// *** COPY/CLEAR OPS:
#define BC_COPY_COLLECTION          84
#define BC_COPY_TEXT                85

// *** CONSOLE OPS:

#define BC_PRINT_I                  86
#define BC_PRINT_U                  87
#define BC_PRINT_F                  88
#define BC_PRINT_C                  89
#define BC_PRINT_TEXT               90
#define BC_NEWLINE                  91
// Coming soon
#define COLLECTION2TEXT             92

// *** INSTANCE

// Coming soon
#define BC_GET_INSTANCE             93

// *** JUMP OPS:

#define BC_JUMP_ABS                 94
#define BC_JUMP_NEG                 95
#define BC_JUMP_POS                 96
#define BC_JUMP_IF_TRUE_ABS         97
#define BC_JUMP_IF_FALSE_ABS        98
#define BC_JUMP_IF_TRUE_NEG         99
#define BC_JUMP_IF_FALSE_NEG        100
#define BC_JUMP_IF_TRUE_POS         101
#define BC_JUMP_IF_FALSE_POS        102

// Extras

#define BC_MOD_I                    103
#define BC_MOD_U                    104

#define BC_BUILD_EMPTYCOLLECTION    105
#define BC_BUILD_COLLECTION         106

#define BC_INPUT_I                  107
#define BC_INPUT_U                  108
#define BC_INPUT_F                  109
#define BC_INPUT_TEXT               110
#define BC_INPUT_LINE               111

#define BC_TEXT_SET_CHAR            112

#define BC_LOAD_ARGUMENT            113
#define BC_I2U                      114
#define BC_I2F                      115
#define BC_U2I                      116
#define BC_U2F                      117
#define BC_F2I                      118
#define BC_F2U                      119

#define BC_IS_NUM                   120
#define BC_IS_TXT                   121
#define BC_IS_COLLECTION            122
#define BC_IS_FUNC                  123
#define BC_IS_NOTHING               124

#define BC_Float2Double             125
#define BC_Double2Float             126

#define BC_BNOT                     127

#define BC_COLLECTION_INIT          128

#define BC_TO_STRING_I              129
#define BC_TO_STRING_F              130
#define BC_TO_STRING_U              131

#define BC_STR_TO_I                 132
#define BC_STR_TO_F                 133
#define BC_STR_TO_U                 134

#define BC_UNARY_MINUS_I            135
#define BC_UNARY_MINUS_F            136
#define BC_CONCAT                   137


#define BC_INPUT_CHAR               138

#define BC_CALL_VANGUARD            139

#define BC_CLOCK                    140
#define BC_TIME                     141

// GLL IMPLEMENTATIONS


#define BC_GLL_LOAD                 142
#define BC_GLL_SYMBOL               143
#define BC_GLL_EXEC                 144
#define BC_GLL_CLOSE                145

// INTERATOR OPERATIONS

#define BC_SETUP_ITER               146
#define BC_NEXT_ITER                147

// Hashing

#define BC_TEXT_HASH                148

// Debugging
#define BC_HINT                     149

// Const definition:

#define CONST_NOP                   0
#define CONST_NUM8                  1
#define CONST_NUM16                 2
#define CONST_NUM32                 3
#define CONST_NUM64                 4
#define CONST_TEXT                  5
#define CONST_FUNCTION              6
#define CONST_RECOVER               7

enum Scopes {
    scope_undefined,
    scope_constant,
    scope_global,
    scope_local
};

enum VariableIDs {
    type_undefined,
    type_none,
    type_ubyte,
    type_byte,
    type_ushort,
    type_short,
    type_uint,
    type_int,
    type_float,
    type_ulong,
    type_long,
    type_double,
    type_text,
    type_function,
    type_Collection,
    type_complex,
    type_any
};

typedef struct Scope {
    unsigned char rgtr;       // Register
    Token function;  // only necessary if the register is in the stack
} Scope;

typedef struct Symbol {
    Token value;           // name, value
    unsigned int index;    // position
    Scope scope;           // Scope where the variable is defined
    unsigned char type;    // type of the variable
    struct {
        unsigned int num8s;
        unsigned int num16s;
        unsigned int num32s;
        unsigned int num64s;
        unsigned int functions;
        unsigned int texts;
        unsigned int collections;
    } memoryDeclaration;
    char* code;
    unsigned int codelength;
    struct{
        Token type;
        Token name;
        unsigned char is_array;
    } arguments[255];
    unsigned char argumentsCount;
    unsigned char returnType;
    unsigned char returnType_isArray;
    unsigned char is_argument;
    unsigned char argument_index;
    unsigned char free_arguments;

    unsigned char storingType;

    unsigned char is_extern;

    // Complex
    Token mothertype;

    SyntaxNode functionDefininiton;
} Symbol;

Token Complex_return = (Token) {.type = type_none};

unsigned char returnComplex (Symbol variable) {
    Complex_return = variable.mothertype;
    return variable.type;
}

typedef struct SymbolTable {
    struct {
    // ConstantsScope
        unsigned int const_num8s;
        unsigned int const_num16s;
        unsigned int const_num32s;
        unsigned int const_num64s;
        unsigned int const_functions;
        unsigned int const_texts;
    // GlobalScope
        unsigned int global_num8s;
        unsigned int global_num16s;
        unsigned int global_num32s;
        unsigned int global_num64s;
        unsigned int global_functions;
        unsigned int global_texts;
        unsigned int global_collections;
    } memoryDeclaration;

    // functions

    // Variables
    unsigned int numberOfDeclarations;
    Symbol* declarations;
} SymbolTable;

typedef struct CodeGenerator {
    // The Parser contains the AST and the Tokenizer, 
    // which the CodeGenerator needs to work with
    Parser* parser;
    

    // The generated Bytecode will be stored in 'code'
    char* code;
    unsigned int codeLength;
    unsigned int currentLine;

    // The Symboltable is responsible for tracking 
    // all variables, literals and etc
    Token currentFunction;
    SymbolTable table;

    // The '$$main$$' Function will setup all variables
    // that has been defined in the global scope and
    // stores the setup-code inside 'global_ops'
    char* global_ops;
    unsigned int global_ops_len;

    // globalwriter is responsible for writing into the
    // string 'global_ops' and allocate space and update
    // 'global_ops_len'
    ByteWriter globalwriter;

    // The Compiler can currently only handle 255
    // 'Vanguard Functions' (Functions that have their own thread
    // And that are executed at first)
    // They will be marked with this array of Symbols
    Symbol vanguardFunctions[255];
    unsigned int vanguards_size;

    // A list of libraries that will be imported and handled
    //    This list will be filled by the parser
    //       The parser will replace the @library with 'Atlibrary'
    //       and will register the library inside this list
    char* libraries[600];
    unsigned int numberOfLibraries;

    // The codeGenerator has to memorise where the current continue and break locations are
    unsigned short continueLocationIndex;
    unsigned int continueLocation[300];
    unsigned short breakLocationIndex;
    unsigned int breakLocation[300];
} CodeGenerator;

// Will append a new library (needs path of file) to a list (library will be imported)
unsigned char CodeGenerator_addLibPath (CodeGenerator* codeGenerator, char* path) {
    
    // Looks that this library wasn't imported yet (Is not in the list yet)
    for (unsigned int i = 0; i < codeGenerator->numberOfLibraries; i++) {
        if (strcmp (path, codeGenerator->libraries[i]) == 0)
            // If the library is included already it will return 0
            return 0;
    }

    // If the library wasn't imported yet it will append the path to the list
    codeGenerator->libraries[codeGenerator->numberOfLibraries++] = path;

    // After successful adding the library the function will return 1
    return 1;
}

// Functions that reverse the bits of a double float
double reverseDouble (double value) {
    unsigned char* buffer = (unsigned char*) &value;
    unsigned char new[8];
    new[0] = buffer[4];
    new[1] = buffer[5];
    new[2] = buffer[6];
    new[3] = buffer[7];
    new[0] = buffer[0];
    new[1] = buffer[1];
    new[2] = buffer[2];
    new[3] = buffer[3];
    return * ( (double*) new);
}

// Will convert a type of a token to a variable type
unsigned char tokenTypeToDataType (Token token, CodeGenerator *codeGenerator) {
    switch (token.type) {
        case TTK_Ubyte:
            return type_ubyte;
            break;
        case TTK_Byte:
            return type_byte;
            break;
        case TTK_Ushort:
            return type_ushort;
            break;
        case TTK_Short:
            return type_short;
            break;
        case TTK_Uint:
            return type_uint;
            break;
        case TTK_Int:
            return type_int;
            break;
        case TTK_Float:
            return type_float;
            break;
        case TTK_Ulong:
            return type_ulong;
            break;
        case TTK_Long:
            return type_long;
            break;
        case TTK_Double:
            return type_double;
            break;
        case TTK_Txt:
            return type_text;
            break;
        case TT_Identifier:
            {
                if(strcmp(token.value.word, "table") == 0)
                    return type_complex;
                Symbol fnDeclaration = VariableTable_findVariableByName(&codeGenerator->table, token);
                // printf("fnDeclaration search: %s\n", token.value.word);
                if(fnDeclaration.functionDefininiton.functionNode->returnType.type == TT_Identifier) {
                    if(strcmp(fnDeclaration.functionDefininiton.functionNode->returnType.value.word, "table") == 0) {
                        return type_complex;
                    }
                }
            }
            return type_function;
            break;
        default:
            return type_none;
            break;
    }
}

// Will convert for example a int to a long
// and a ubyte to ulong -> the stack works only with 64 bit numbers
unsigned char typeToStackType (unsigned char type) {
    switch (type) {
        case type_ubyte:
        case type_uint:
        case type_ushort:
        case type_ulong:
            return type_ulong;
            break;
        case type_byte:
        case type_short:
        case type_int:
        case type_long:
            return type_long;
            break;
        case type_float:
        case type_double:
            return type_double;
            break;
    }
    return type;
}

char *getTypeRepresentation(unsigned char type) {
    switch (type) {
        case type_ubyte:
        case type_uint:
        case type_ushort:
        case type_ulong:
            return "uint";
        case type_byte:
        case type_short:
        case type_int:
        case type_long:
            return "int";
        case type_float:
        case type_double:
            return "float";
        case type_Collection:
            return "Collection";
        case type_text:
        case type_complex:
            return "text";
        case type_function:
            return "function";
    }
    return "unknown";
}

// Will create a new instance of a codeGenerator and will set all
// inner variables to 0/NULL (like a constructor)
CodeGenerator* CodeGenerator_build (Parser* parser) {
    CodeGenerator* codeGenerator = (CodeGenerator*) malloc (sizeof (CodeGenerator));
    if (!codeGenerator) {
        puts ("Out of Memory!");
        exit (1);
    }
    codeGenerator->parser = parser;
    codeGenerator->code = NULL;
    codeGenerator->codeLength = 0;
    codeGenerator->currentLine = 0;
    codeGenerator->currentFunction = (Token) {.type = TT_Identifier, .value.word = ""};
    codeGenerator->table = (SymbolTable) {
        .declarations = NULL,
        .memoryDeclaration.const_functions = 0,
        .memoryDeclaration.const_num16s = 0,
        .memoryDeclaration.const_num32s = 0,
        .memoryDeclaration.const_num64s = 0,
        .memoryDeclaration.const_num8s = 0,
        .memoryDeclaration.const_texts = 0,
        .memoryDeclaration.global_collections = 0,
        .memoryDeclaration.global_functions = 0,
        .memoryDeclaration.global_num16s = 0,
        .memoryDeclaration.global_num32s = 0,
        .memoryDeclaration.global_num64s = 0,
        .memoryDeclaration.global_num8s = 0,
        .memoryDeclaration.global_texts = 0,
        .numberOfDeclarations = 0
    };
    codeGenerator->global_ops = NULL;
    codeGenerator->global_ops_len = 0;
    codeGenerator->globalwriter = ByteWriter_init (&codeGenerator->global_ops, &codeGenerator->global_ops_len);
    codeGenerator->vanguards_size = 0;
    codeGenerator->numberOfLibraries = 0;
    codeGenerator->continueLocationIndex = 0;
    codeGenerator->breakLocationIndex = 0;
    CodeGenerator_generate (codeGenerator);
    return codeGenerator;
}

// Will clear every allocated variable by a codeGenerator
void CodeGenerator_clear (CodeGenerator codeGenerator) {
    free (codeGenerator.code);
}

char* fullIncludes[512];
unsigned int fullIncludesSize = 0;

void syncFunctionSymbol(Symbol *newVariable, Symbol motherFunction) {
    newVariable->functionDefininiton = motherFunction.functionDefininiton;
    newVariable->returnType_isArray = motherFunction.returnType_isArray;
    newVariable->returnType = motherFunction.returnType;
    newVariable->memoryDeclaration = motherFunction.memoryDeclaration;
    newVariable->free_arguments = motherFunction.free_arguments;
    newVariable->codelength = motherFunction.codelength;
    newVariable->code = motherFunction.code;
    newVariable->argumentsCount = motherFunction.argumentsCount;
    for(int args_counter = 0; args_counter < motherFunction.argumentsCount; args_counter += 1)
        newVariable->arguments[args_counter] = motherFunction.arguments[args_counter];
}

// CodeGenerator_includeLibWithOutNamespace
// Will search for the library and compiles it + imports it
char CodeGenerator_includeLibWithOutNamespaceDirect (CodeGenerator* codeGenerator, char* path) {

    // // Checks that the library is inside the list
    // if (CodeGenerator_addLibPath (codeGenerator, path) == 0) {
    //     return;
    // }
    for(unsigned int i = 0; i < fullIncludesSize; ++i) {
        if(strcmp(fullIncludes[i], path) == 0) return 0;
    }

    fullIncludes[fullIncludesSize++] = path;

    char base[512] = "";
    char* abspath = NULL;
    char* incCode = NULL;
    // current path
    abspath = strcat (base, "./");
    abspath = strcat (base, path);
    abspath = strcat (base, ".gsm");
    //printf ("including: %s\n", abspath);
    if (access (abspath, F_OK ) == 0) {
        // Must be a lib. inside the compiling folder
        incCode = readFile (abspath);
        Tokenizer incTokenizer = Tokenizer_getTokens (incCode, abspath);
        Parser incParser = Parser_build (&incTokenizer);

        // include direct with insert
        
        for(unsigned int i = 0; i < incParser.ast.programsNode->size; ++i)
            Program_addGlobalDeclaration(codeGenerator->parser->ast.programsNode, incParser.ast.programsNode->declarations[i]);
        
        for(unsigned int i = 0; i < incParser.numberOfLibrarys; ++i) {
            Parser_addLibPath(codeGenerator->parser, incParser.librarys[i]);
        }
        return 1;
    }
    base[0] = '\0';
    abspath = strcat (base, "./libs/");
    abspath = strcat (base, path);
    abspath = strcat (base, ".gsm");
    //printf ("including: %s\n", abspath);
    if (access (abspath, F_OK ) == 0) {
        // Must be a lib. inside the compiling folder
        incCode = readFile (abspath);
        Tokenizer incTokenizer = Tokenizer_getTokens (incCode, abspath);
        Parser incParser = Parser_build (&incTokenizer);

        // Include direct with insert
        for(unsigned int i = 0; i < incParser.ast.programsNode->size; ++i)
            Program_addGlobalDeclaration(codeGenerator->parser->ast.programsNode, incParser.ast.programsNode->declarations[i]);
        
        for(unsigned int i = 0; i < incParser.numberOfLibrarys; ++i) {
            Parser_addLibPath(codeGenerator->parser, incParser.librarys[i]);
        }
        return 1;
    }

    base[0] = '\0';
    abspath = strcat (base, GISMOHOMELIBS);
    abspath = strcat (base, path);
    abspath = strcat (base, ".gsm");
    //printf ("including: %s\n", abspath);
    if (access (abspath, F_OK ) == 0) {
        // Must be a lib. inside the compiling folder
        incCode = readFile (abspath);
        Tokenizer incTokenizer = Tokenizer_getTokens (incCode, abspath);
        Parser incParser = Parser_build (&incTokenizer);

        // Include direct with insert
        for(unsigned int i = 0; i < incParser.ast.programsNode->size; ++i)
            Program_addGlobalDeclaration(codeGenerator->parser->ast.programsNode, incParser.ast.programsNode->declarations[i]);
        
        for(unsigned int i = 0; i < incParser.numberOfLibrarys; ++i) {
            Parser_addLibPath(codeGenerator->parser, incParser.librarys[i]);
        }
        return 1;
    }

    printf ("Library '%s' Not found!\n", path);
    exit (1);
    return 0;
}

// CodeGenerator_includeLibWithOutNamespace
// Will search for the library and compiles it + imports it
void CodeGenerator_includeLibWithOutNamespace (CodeGenerator* codeGenerator, char* path) {

    // // Checks that the library is inside the list
    // if (CodeGenerator_addLibPath (codeGenerator, path) == 0) {
    //     return;
    // }
    for(unsigned int i = 0; i < fullIncludesSize; ++i) {
        if(strcmp(fullIncludes[i], path) == 0) return;
    }

    fullIncludes[fullIncludesSize++] = path;

    char base[512] = "";
    char* abspath = NULL;
    char* incCode = NULL;
    // current path
    abspath = strcat (base, "./");
    abspath = strcat (base, path);
    abspath = strcat (base, ".gsm");
    //printf ("including: %s\n", abspath);
    if (access (abspath, F_OK ) == 0) {
        // Must be a lib. inside the compiling folder
        incCode = readFile (abspath);
        Tokenizer incTokenizer = Tokenizer_getTokens (incCode, abspath);
        Parser incParser = Parser_build (&incTokenizer);
        unsigned int beginTableSize = codeGenerator->table.numberOfDeclarations;
        Parser* realPaser = codeGenerator->parser;
        codeGenerator->parser = &incParser;
        // Program will be compiled

        /*puts ("including:");
        for (unsigned int j = 0; j < incParser.numberOfLibrarys; j++) {
            puts (incParser.librarys[j]);
        }*/

        CodeGenerator_generateProgram (codeGenerator, incParser.ast);
        codeGenerator->parser = realPaser;

        // Rename all new declarations as <Name>At<Library>

        // for (unsigned int j = beginTableSize; j < codeGenerator->table.numberOfDeclarations; j++) {
        //     Symbol vardec = codeGenerator->table.declarations[j];
        //     if (!vardec.is_extern)
        //         if (vardec.value.type == TT_Identifier) {
        //             unsigned int newNameSize = strlen (vardec.value.value.word) + 2 + strlen (path);
        //             char* newName = (char*) malloc (sizeof (char) * (newNameSize+1));
        //             newName[0] = '\0';
        //             newName = strcat (newName, vardec.value.value.word);
        //             vardec.value.value.word = newName;
        //             vardec.is_extern = 1;
        //         }
        //     codeGenerator->table.declarations[j] = vardec;
        // }
        return;
    }
    base[0] = '\0';
    abspath = strcat (base, "./libs/");
    abspath = strcat (base, path);
    abspath = strcat (base, ".gsm");
    //printf ("including: %s\n", abspath);
    if (access (abspath, F_OK ) == 0) {
        // Must be a lib. inside the compiling folder
        incCode = readFile (abspath);
        Tokenizer incTokenizer = Tokenizer_getTokens (incCode, abspath);
        Parser incParser = Parser_build (&incTokenizer);
        unsigned int beginTableSize = codeGenerator->table.numberOfDeclarations;
        Parser* realPaser = codeGenerator->parser;
        codeGenerator->parser = &incParser;
        // Program will be compiled

        

        CodeGenerator_generateProgram (codeGenerator, incParser.ast);
        codeGenerator->parser = realPaser;

        // Rename all new declarations as <Name>At<Library>

        // for (unsigned int j = beginTableSize; j < codeGenerator->table.numberOfDeclarations; j++) {
        //     Symbol vardec = codeGenerator->table.declarations[j];
        //     if (!vardec.is_extern)
        //         if (vardec.value.type == TT_Identifier) {
        //             unsigned int newNameSize = strlen (vardec.value.value.word) + 2 + strlen (path);
        //             char* newName = (char*) malloc (sizeof (char) * (newNameSize+1));
        //             newName[0] = '\0';
        //             newName = strcat (newName, vardec.value.value.word);
        //             vardec.value.value.word = newName;
        //             vardec.is_extern = 1;
        //         }
        //     codeGenerator->table.declarations[j] = vardec;
        // }
        return;
    }

    base[0] = '\0';
    abspath = strcat (base, GISMOHOMELIBS);
    abspath = strcat (base, path);
    abspath = strcat (base, ".gsm");
    //printf ("including: %s\n", abspath);
    if (access (abspath, F_OK ) == 0) {
        // Must be a lib. inside the compiling folder
        incCode = readFile (abspath);
        Tokenizer incTokenizer = Tokenizer_getTokens (incCode, abspath);
        Parser incParser = Parser_build (&incTokenizer);
        unsigned int beginTableSize = codeGenerator->table.numberOfDeclarations;
        Parser* realPaser = codeGenerator->parser;
        codeGenerator->parser = &incParser;
        // Program will be compiled

        CodeGenerator_generateProgram (codeGenerator, incParser.ast);
        codeGenerator->parser = realPaser;

        // Rename all new declarations as <Name>At<Library>

        // for (unsigned int j = beginTableSize; j < codeGenerator->table.numberOfDeclarations; j++) {
        //     Symbol vardec = codeGenerator->table.declarations[j];
        //     if (!vardec.is_extern)
        //         if (vardec.value.type == TT_Identifier) {
        //             unsigned int newNameSize = strlen (vardec.value.value.word) + 2 + strlen (path);
        //             char* newName = (char*) malloc (sizeof (char) * (newNameSize+1));
        //             newName[0] = '\0';
        //             newName = strcat (newName, vardec.value.value.word);
        //             vardec.value.value.word = newName;
        //             vardec.is_extern = 1;
        //         }
        //     codeGenerator->table.declarations[j] = vardec;
        // }
        return;
    }

    printf ("Library '%s' Not found!\n", path);
    exit (1);
    return;
}

// Will search for the library and compiles it + imports it
void CodeGenerator_includeLib (CodeGenerator* codeGenerator, char* path) {

    // Checks that the library is inside the list
    if (CodeGenerator_addLibPath (codeGenerator, path) == 0) {
        return;
    }

    char base[512] = "";
    char* abspath = NULL;
    char* incCode = NULL;
    // current path
    abspath = strcat (base, "./");
    abspath = strcat (base, path);
    abspath = strcat (base, ".gsm");
    //printf ("including: %s\n", abspath);
    if (access (abspath, F_OK ) == 0) {
        // Must be a lib. inside the compiling folder
        incCode = readFile (abspath);
        Tokenizer incTokenizer = Tokenizer_getTokens (incCode, abspath);
        Parser incParser = Parser_build (&incTokenizer);
        unsigned int beginTableSize = codeGenerator->table.numberOfDeclarations;
        Parser* realPaser = codeGenerator->parser;
        codeGenerator->parser = &incParser;
        // Program will be compiled

        /*puts ("including:");
        for (unsigned int j = 0; j < incParser.numberOfLibrarys; j++) {
            puts (incParser.librarys[j]);
        }*/

        CodeGenerator_generateProgram (codeGenerator, incParser.ast);
        codeGenerator->parser = realPaser;

        // Rename all new declarations as <Name>At<Library>

        for (unsigned int j = beginTableSize; j < codeGenerator->table.numberOfDeclarations; j++) {
            Symbol vardec = codeGenerator->table.declarations[j];
            if (!vardec.is_extern)
                if (vardec.value.type == TT_Identifier) {
                    unsigned int newNameSize = strlen (vardec.value.value.word) + 2 + strlen (path);
                    char* newName = (char*) malloc (sizeof (char) * (newNameSize+1));
                    newName[0] = '\0';
                    newName = strcat (newName, "@");
                    newName = strcat (newName, path);
                    newName = strcat (newName, "_");
                    newName = strcat (newName, vardec.value.value.word);
                    vardec.value.value.word = newName;
                    vardec.is_extern = 1;
                }
            codeGenerator->table.declarations[j] = vardec;
        }
        return;
    }
    base[0] = '\0';
    abspath = strcat (base, "./libs/");
    abspath = strcat (base, path);
    abspath = strcat (base, ".gsm");
    //printf ("including: %s\n", abspath);
    if (access (abspath, F_OK ) == 0) {
        // Must be a lib. inside the compiling folder
        incCode = readFile (abspath);
        Tokenizer incTokenizer = Tokenizer_getTokens (incCode, abspath);
        Parser incParser = Parser_build (&incTokenizer);
        unsigned int beginTableSize = codeGenerator->table.numberOfDeclarations;
        Parser* realPaser = codeGenerator->parser;
        codeGenerator->parser = &incParser;
        // Program will be compiled

        

        CodeGenerator_generateProgram (codeGenerator, incParser.ast);
        codeGenerator->parser = realPaser;

        // Rename all new declarations as <Name>At<Library>

        for (unsigned int j = beginTableSize; j < codeGenerator->table.numberOfDeclarations; j++) {
            Symbol vardec = codeGenerator->table.declarations[j];
            if (!vardec.is_extern)
                if (vardec.value.type == TT_Identifier) {
                    unsigned int newNameSize = strlen (vardec.value.value.word) + 2 + strlen (path);
                    char* newName = (char*) malloc (sizeof (char) * (newNameSize+1));
                    newName[0] = '\0';
                    newName = strcat (newName, "@");
                    newName = strcat (newName, path);
                    newName = strcat (newName, "_");
                    newName = strcat (newName, vardec.value.value.word);
                    vardec.value.value.word = newName;
                    vardec.is_extern = 1;
                }
            codeGenerator->table.declarations[j] = vardec;
        }
        return;
    }

    base[0] = '\0';
    abspath = strcat (base, GISMOHOMELIBS);
    abspath = strcat (base, path);
    abspath = strcat (base, ".gsm");
    //printf ("including: %s\n", abspath);
    if (access (abspath, F_OK ) == 0) {
        // Must be a lib. inside the compiling folder
        incCode = readFile (abspath);
        Tokenizer incTokenizer = Tokenizer_getTokens (incCode, abspath);
        Parser incParser = Parser_build (&incTokenizer);
        unsigned int beginTableSize = codeGenerator->table.numberOfDeclarations;
        Parser* realPaser = codeGenerator->parser;
        codeGenerator->parser = &incParser;
        // Program will be compiled

        CodeGenerator_generateProgram (codeGenerator, incParser.ast);
        codeGenerator->parser = realPaser;

        // Rename all new declarations as <Name>At<Library>

        for (unsigned int j = beginTableSize; j < codeGenerator->table.numberOfDeclarations; j++) {
            Symbol vardec = codeGenerator->table.declarations[j];
            if (!vardec.is_extern)
                if (vardec.value.type == TT_Identifier) {
                    unsigned int newNameSize = strlen (vardec.value.value.word) + 2 + strlen (path);
                    char* newName = (char*) malloc (sizeof (char) * (newNameSize+1));
                    newName[0] = '\0';
                    newName = strcat (newName, "@");
                    newName = strcat (newName, path);
                    newName = strcat (newName, "_");
                    newName = strcat (newName, vardec.value.value.word);
                    vardec.value.value.word = newName;
                    vardec.is_extern = 1;
                }
            codeGenerator->table.declarations[j] = vardec;
        }
        return;
    }

    printf ("Library '%s' Not found!\n", path);
    exit (1);
}


// Will generate the Bytecode for the Gismo Program
void CodeGenerator_generate (CodeGenerator* codeGenerator) {

    
    SyntaxNode program = codeGenerator->parser->ast;
    ByteWriter byteWriter = ByteWriter_init (&codeGenerator->code, &codeGenerator->codeLength);
    Symbol mainfunction = VariableTable_declareVariable (&codeGenerator->table, (Token) {.type = TT_Identifier, .value.word = "$$main$$"}, (Scope) {.rgtr = scope_constant});
    VariableTable_defineVariable (&codeGenerator->table, mainfunction.value, type_function);

    // {
    //     char hint[1024] = "fl;";

    //     strcat(hint, codeGenerator->parser->tokenizer->file_path);
    //     strcat(hint, ":$$main$$");

    //     ByteWriter_writeByte(&codeGenerator->globalwriter, BC_HINT);
    //     unsigned int hint_len = strlen(hint);
    //     ByteWriter_writeUInt(&codeGenerator->globalwriter, hint_len);
    //     for(unsigned int i = 0; i < hint_len; ++i) {
    //         ByteWriter_writeByte(&codeGenerator->globalwriter, hint[i]);
    //     }

    //     codeGenerator->currentLine = 0;
    // }

    CodeGenerator_generateProgram (codeGenerator, codeGenerator->parser->ast);
    

    // Code Generation

    // Magic
    ByteWriter_writeByte(&byteWriter, '\0');
    ByteWriter_writeByte(&byteWriter, 'g');
    ByteWriter_writeByte(&byteWriter, 'i');
    ByteWriter_writeByte(&byteWriter, 'm');

    // Const Register
    ByteWriter_writeUInt (&byteWriter, codeGenerator->table.memoryDeclaration.const_num8s);
    ByteWriter_writeUInt (&byteWriter, codeGenerator->table.memoryDeclaration.const_num16s);
    ByteWriter_writeUInt (&byteWriter, codeGenerator->table.memoryDeclaration.const_num32s);
    ByteWriter_writeUInt (&byteWriter, codeGenerator->table.memoryDeclaration.const_num64s);
    ByteWriter_writeUInt (&byteWriter, codeGenerator->table.memoryDeclaration.const_functions);
    ByteWriter_writeUInt (&byteWriter, codeGenerator->table.memoryDeclaration.const_texts);

    // Global Register
    ByteWriter_writeUInt (&byteWriter, codeGenerator->table.memoryDeclaration.global_num8s);
    ByteWriter_writeUInt (&byteWriter, codeGenerator->table.memoryDeclaration.global_num16s);
    ByteWriter_writeUInt (&byteWriter, codeGenerator->table.memoryDeclaration.global_num32s);
    ByteWriter_writeUInt (&byteWriter, codeGenerator->table.memoryDeclaration.global_num64s);
    ByteWriter_writeUInt (&byteWriter, codeGenerator->table.memoryDeclaration.global_functions);
    ByteWriter_writeUInt (&byteWriter, codeGenerator->table.memoryDeclaration.global_texts);
    ByteWriter_writeUInt (&byteWriter, codeGenerator->table.memoryDeclaration.global_collections);

    for (unsigned int i = 0; i < codeGenerator->table.memoryDeclaration.const_num8s; i++) {
        ByteWriter_writeByte (&byteWriter, CONST_NUM8);
        Symbol declaration = VariableTable_findConstantByIndex (&codeGenerator->table, i, type_byte); // 1 Byte
        if(declaration.value.type == TT_Int)
            ByteWriter_writeByte (&byteWriter, (declaration.value.value.u >> 63) ^ (declaration.value.value.u << 1));
        else
            ByteWriter_writeByte (&byteWriter, declaration.value.value.u);
    }

    for (unsigned int i = 0; i < codeGenerator->table.memoryDeclaration.const_num16s; i++) {
        ByteWriter_writeByte (&byteWriter, CONST_NUM16);
        Symbol declaration = VariableTable_findConstantByIndex (&codeGenerator->table, i, type_short); // 2 Byte
        if(declaration.value.type == TT_Int)
            ByteWriter_writeUShort(&byteWriter, (declaration.value.value.u >> 63) ^ (declaration.value.value.u << 1));
        else
            ByteWriter_writeUShort(&byteWriter, declaration.value.value.u);
    }

    for (unsigned int i = 0; i < codeGenerator->table.memoryDeclaration.const_num32s; i++) {
        ByteWriter_writeByte (&byteWriter, CONST_NUM32);
        Symbol declaration = VariableTable_findConstantByIndex (&codeGenerator->table, i, type_int); // 4 Byte
        switch (declaration.type) {
            case type_uint:
                ByteWriter_writeUInt (&byteWriter, (unsigned int) declaration.value.value.u);
                break;
            case type_int:
                ByteWriter_writeInt (&byteWriter, (int) ((declaration.value.value.u >> 63) ^ (declaration.value.value.u << 1)));
                break;
            case type_float:
                ByteWriter_writeFloat (&byteWriter, (float) declaration.value.value.f);
                break;
        }
    }

    for (unsigned int i = 0; i < codeGenerator->table.memoryDeclaration.const_num64s; i++) {
        ByteWriter_writeByte (&byteWriter, CONST_NUM64);
        Symbol declaration = VariableTable_findConstantByIndex (&codeGenerator->table, i, type_long); // 8 Byte
        if (declaration.type == type_double) {
            ByteWriter_writeDouble (&byteWriter, reverseDouble (declaration.value.value.f));
        } else if (declaration.type == type_long)
            ByteWriter_writeULongLong (&byteWriter, ((declaration.value.value.u >> 63) ^ (declaration.value.value.u << 1)));
        else
            ByteWriter_writeULongLong (&byteWriter, declaration.value.value.u);
    }

    for (unsigned int i = 0; i < codeGenerator->table.memoryDeclaration.const_texts; i++) {
        ByteWriter_writeByte (&byteWriter, CONST_TEXT);
        Symbol declaration = VariableTable_findConstantByIndex (&codeGenerator->table, i, type_text);
        ByteWriter_writeUInt (&byteWriter, strlen (declaration.value.value.word));
        for (unsigned int ci = 0; ci < strlen (declaration.value.value.word); ci++){
            ByteWriter_writeByte (&byteWriter, declaration.value.value.word[ci]);
        }
    }

    ByteWriter_writeByte (&byteWriter, CONST_FUNCTION);
    ByteWriter_writeUInt (&byteWriter, 0);
    ByteWriter_writeUInt (&byteWriter, 0);
    ByteWriter_writeUInt (&byteWriter, 0);
    ByteWriter_writeUInt (&byteWriter, 0);
    ByteWriter_writeUInt (&byteWriter, 0);
    ByteWriter_writeUInt (&byteWriter, 0);
    ByteWriter_writeUInt (&byteWriter, 0);

    ByteWriter_writeByte (&codeGenerator->globalwriter, BC_LOAD_ARGUMENT);
    ByteWriter_writeUInt (&codeGenerator->globalwriter, 0);
    for (unsigned int i = 0; i < codeGenerator->vanguards_size; i++) {
        ByteWriter_writeByte (&codeGenerator->globalwriter, BC_COPY_COLLECTION);
        ByteWriter_writeByte (&codeGenerator->globalwriter, BC_LOAD_CONST_FUNC);
        //ByteWriter_writeUInt (&codeGenerator->globalwriter, VariableTable_findVariableByName (&codeGenerator->table, codeGenerator->vanguardFunctions[i].value).index);
        ByteWriter_writeUInt (&codeGenerator->globalwriter, codeGenerator->vanguardFunctions[
            codeGenerator->vanguards_size-i-1
        ].index);
        if (i == codeGenerator->vanguards_size-1) {
            ByteWriter_writeByte (&codeGenerator->globalwriter, BC_CALL_FUNC);
            ByteWriter_writeUInt(&codeGenerator->globalwriter, 1); // Only the collection
            ByteWriter_writeByte (&codeGenerator->globalwriter, BC_POP);
        }
        else
            ByteWriter_writeByte (&codeGenerator->globalwriter, BC_CALL_VANGUARD);
    }

    // ByteWriter_writeUInt (&byteWriter, (codeGenerator->vanguards_size) * 8 + 5 + codeGenerator->global_ops_len + (codeGenerator->vanguards_size != 0 ? 1 : 0));
    ByteWriter_writeUInt (&byteWriter, codeGenerator->global_ops_len);
    ByteWriter_addOps (&byteWriter, codeGenerator->global_ops, codeGenerator->global_ops_len);

    free (codeGenerator->global_ops);

    for (unsigned int i = 1; i < codeGenerator->table.memoryDeclaration.const_functions; i++) {
        Symbol fn = VariableTable_findConstantByIndex (&codeGenerator->table, i, type_function);
        if(strstr(fn.value.value.word, "$$GVMErrorHandler$$") != NULL) {
            ByteWriter_writeByte (&byteWriter, CONST_RECOVER);
        } else {
            ByteWriter_writeByte (&byteWriter, CONST_FUNCTION);
        }
        ByteWriter_writeUInt (&byteWriter, fn.memoryDeclaration.num8s);
        ByteWriter_writeUInt (&byteWriter, fn.memoryDeclaration.num16s);
        ByteWriter_writeUInt (&byteWriter, fn.memoryDeclaration.num32s);
        ByteWriter_writeUInt (&byteWriter, fn.memoryDeclaration.num64s);
        ByteWriter_writeUInt (&byteWriter, fn.memoryDeclaration.functions);
        ByteWriter_writeUInt (&byteWriter, fn.memoryDeclaration.texts);
        ByteWriter_writeUInt (&byteWriter, fn.memoryDeclaration.collections);
        ByteWriter_writeUInt (&byteWriter, fn.codelength);
        ByteWriter_addOps (&byteWriter, fn.code, fn.codelength);
    }
}

// char startsWith(const char *a, const char *b)
// {
//    if(strncmp(a, b, strlen(b)) == 0) return 1;
//    return 0;
// }

// char endsWith(const char *str, const char *suffix)
// {
//     if (!str || !suffix)
//         return 0;
//     size_t lenstr = strlen(str);
//     size_t lensuffix = strlen(suffix);
//     if (lensuffix >  lenstr)
//         return 0;
//     return strncmp(str + lenstr - lensuffix, suffix, lensuffix) == 0;
// }

// char isMetaPhysicName(char *name) {
//     return startsWith(name, "$_") && endsWith(name, "_$");
// }

void CodeGenerator_generateProgram (struct CodeGenerator* codeGenerator, struct SyntaxNode program) {
    
    // Including System
    char includedSystem = CodeGenerator_includeLibWithOutNamespaceDirect(codeGenerator, "system");
    
    SyntaxNode node;

    // Direct Including
    for (unsigned int i = 0; i < program.programsNode->size; i++) {
        node = program.programsNode->declarations[i];
        switch (node.type) {

            case ID_Include:
            {
                IncludeNode includeNode = *node.includeNode;

                if(includeNode.library.type != TT_None) {
                    CodeGenerator_includeLibWithOutNamespaceDirect(codeGenerator, includeNode.library.value.word);
                } else {
                    puts("Cannot implement from library!");
                    markTokenError(includeNode.includeNode);
                    exit(1);
                }
            }
                break;
        }
    }


    if(includedSystem) {
        for (unsigned int i = 0; i < program.programsNode->size; i++) {
            node = program.programsNode->declarations[i];
            switch (node.type) {

                case ID_FunctionNode:
                {
                    // Function declaration:
                    FunctionNode functionNode = *node.functionNode;
                    
                    char lib_id[256] = "";
                    getLibraryIdOfPath(functionNode.name.file_path, lib_id);
                    if(strcmp(lib_id, "system") != 0) continue;
                    Symbol functiondeclaration = VariableTable_declareVariable (&codeGenerator->table, functionNode.name, (Scope) {.rgtr = scope_constant});
                    VariableTable_defineVariable (&codeGenerator->table, functiondeclaration.value, type_function);
                    functiondeclaration = VariableTable_findVariableByName (&codeGenerator->table, functiondeclaration.value);
                    functiondeclaration.functionDefininiton = node;
                    if(functionNode.arguments.type == ID_ValueNode) {
                        functiondeclaration.free_arguments = 1;
                    } else if (functionNode.arguments.type != ID_None) {
                        unsigned char j = 0;
                        ArgumentNode next = *functionNode.arguments.argumentNode;
                        unsigned char is_next = 1;
                        while (is_next) {
                            functiondeclaration.arguments[j].name = next.name;
                            functiondeclaration.arguments[j].type = next.type;
                            functiondeclaration.arguments[j].is_array = next.is_array;
                            j++;
                            if (next.next.type == ID_None)
                                is_next = 0;
                            else
                                next = *next.next.argumentNode;
                        }
                        functiondeclaration.argumentsCount = j;
                    }
                    //functiondeclaration.returnType = tokenTypeToDataType (functionNode.returnType, codeGenerator);

                    functiondeclaration.returnType_isArray = functionNode.returns_array;
                    VariableTable_setVariableByName (&codeGenerator->table, functiondeclaration.value, functiondeclaration);
                }
                    break;
            }
        }
    }

    for (unsigned int i = 0; i < codeGenerator->parser->numberOfLibrarys; i++) {
        char* path = codeGenerator->parser->librarys[i];
        CodeGenerator_includeLib (codeGenerator, path);
    }

    for (unsigned int i = 0; i < program.programsNode->size; i++) {
        node = program.programsNode->declarations[i];
        switch (node.type) {

            case ID_FunctionNode:
            {
                // Function declaration:
                FunctionNode functionNode = *node.functionNode;

                char lib_id[256] = "";
                getLibraryIdOfPath(functionNode.name.file_path, lib_id);
                if(strcmp(lib_id, "system") == 0) continue;

                char name[4096] = "";
                strcat(name, functionNode.name.value.word);
                strcat(name, "/");

                Symbol functiondeclaration = VariableTable_declareVariable (&codeGenerator->table, functionNode.name, (Scope) {.rgtr = scope_constant});
                VariableTable_defineVariable (&codeGenerator->table, functiondeclaration.value, type_function);
                functiondeclaration = VariableTable_findVariableByName (&codeGenerator->table, functiondeclaration.value);
                functiondeclaration.functionDefininiton = node;
                if(functionNode.arguments.type == ID_ValueNode) {
                    functiondeclaration.free_arguments = 1;
                } else if (functionNode.arguments.type != ID_None) {
                    unsigned char j = 0;
                    ArgumentNode next = *functionNode.arguments.argumentNode;
                    unsigned char is_next = 1;
                    while (is_next) {
                        if(functiondeclaration.arguments[j].is_array)
                            strcat(name, "*");
                        else if(next.type.type == TT_Identifier) {
                            strcat(name, next.type.value.word);
                        }
                        else if(next.type.type == TTK_Txt)
                            strcat(name, "txt");

                        strcat(name, "/");
                        functiondeclaration.arguments[j].name = next.name;
                        functiondeclaration.arguments[j].type = next.type;
                        functiondeclaration.arguments[j].is_array = next.is_array;
                        j++;
                        if (next.next.type == ID_None)
                            is_next = 0;
                        else
                            next = *next.next.argumentNode;
                    }
                    functiondeclaration.argumentsCount = j;
                }
                //functiondeclaration.returnType = tokenTypeToDataType (functionNode.returnType, codeGenerator);

                functiondeclaration.returnType_isArray = functionNode.returns_array;

                Symbol newFunctionDec = functiondeclaration;
                if(!(functionNode.returnType.type == TT_Identifier && strcmp(functionNode.returnType.value.word, "table") == 0)) { 
                    char *identifier;
                    identifier = copyString(name);
                    newFunctionDec.value.value.word = identifier;
                    newFunctionDec.functionDefininiton.functionNode->name.value.word = identifier;
                }

                VariableTable_setVariableByName (&codeGenerator->table, functiondeclaration.value, newFunctionDec);
                // printf("Funcdec: %s\n", newFunctionDec.value.value.word);
            }
                break;
            case ID_VanguardNode:
                // Vanguard declaration:
            {
                FunctionNode functionNode = *node.vanguardNode->functionDeclaration.functionNode;
                Symbol functiondeclaration = VariableTable_declareVariable (&codeGenerator->table, functionNode.name, (Scope) {.rgtr = scope_constant, .function = (Token) {.type = TT_Identifier}});
                VariableTable_defineVariable (&codeGenerator->table, functiondeclaration.value, type_function);
                functiondeclaration = VariableTable_findVariableByName (&codeGenerator->table, functiondeclaration.value);
                functiondeclaration.functionDefininiton = node;
                if(functionNode.arguments.type == ID_ValueNode) {
                    functiondeclaration.free_arguments = 1;
                } else if (functionNode.arguments.type != ID_None) {
                    unsigned char j = 0;
                    ArgumentNode next = *functionNode.arguments.argumentNode;
                    unsigned char is_next = 1;
                    while (is_next) {
                        functiondeclaration.arguments[j].name = next.name;
                        functiondeclaration.arguments[j].type = next.type;
                        functiondeclaration.arguments[j].is_array = next.is_array;
                        j++;
                        if (next.next.type == ID_None)
                            is_next = 0;
                        else
                            next = *next.next.argumentNode;
                    }
                    functiondeclaration.argumentsCount = j;
                }
                // functiondeclaration.returnType = tokenTypeToDataType (functionNode.returnType, codeGenerator);
                // We need to store what motherclass it constructs
                if(functiondeclaration.returnType == type_complex) {
                    functiondeclaration.mothertype = functionNode.returnType;
                } else {
                    functiondeclaration.mothertype = (Token) {
                        .type = TT_None
                    };
                }
                functiondeclaration.returnType_isArray = functionNode.returns_array;
                VariableTable_setVariableByName (&codeGenerator->table, functiondeclaration.value, functiondeclaration);
                codeGenerator->vanguardFunctions[codeGenerator->vanguards_size++] = functiondeclaration;
            }
                break;
        }
    }

    // Set returntypes
    for (unsigned int i = 0; i < program.programsNode->size; i++) {
        // For each node in Program
        node = program.programsNode->declarations[i];

        // Check for Function/Vanguard and generate code for execution
        if (node.type == ID_FunctionNode) {
            FunctionNode functionNode = *node.functionNode;
            Symbol functiondeclaration = VariableTable_findVariableByName (&codeGenerator->table, functionNode.name);
            functiondeclaration.returnType = tokenTypeToDataType (functionNode.returnType, codeGenerator);
            // complex type
                
            // We need to store what motherclass it constructs
            if(functiondeclaration.returnType == type_complex) {
                functiondeclaration.mothertype = functionNode.returnType;
            } else {
                functiondeclaration.mothertype = (Token) {
                    .type = TT_None
                };
            }
            VariableTable_setVariableByName(&codeGenerator->table, functiondeclaration.value, functiondeclaration);
        }
    }
   
    // Implementating some library
    for (unsigned int i = 0; i < program.programsNode->size; i++) {
        node = program.programsNode->declarations[i];
        if (node.type == ID_BinOpNode || node.type == ID_Include) {
            unsigned char type = CodeGenerator_generateExpression (codeGenerator, node, (Scope) {.rgtr = scope_global}, &codeGenerator->globalwriter);
            if (type != type_none) {
                puts ("Must be a declaration!");
                markTokenError (node.binOpNode->operator);
                exit (1);
            }
        }
    }


    // Generate Functions
    for (unsigned int i = 0; i < program.programsNode->size; i++) {
        // For each node in Program
        node = program.programsNode->declarations[i];

        // Check for Function/Vanguard and generate code for execution
        if (node.type == ID_FunctionNode) {

            // First loading the function Node for generate the function
            FunctionNode functionNode = *node.functionNode;

            // Next we
            Symbol functiondeclaration = VariableTable_findVariableByName (&codeGenerator->table, functionNode.name);
            
            ByteWriter tempWriter = ByteWriter_init (&functiondeclaration.code, &functiondeclaration.codelength); 
            Scope fscope = (Scope) {
                .rgtr = scope_local,
                .function = functiondeclaration.value
            };

            // Loading Arguments
            for (unsigned char argsIndex = 0; argsIndex < functiondeclaration.argumentsCount; argsIndex++) {
                Symbol argumentvar = VariableTable_declareVariable (&codeGenerator->table, functiondeclaration.arguments[argsIndex].name, fscope);
                unsigned index;
                if (functiondeclaration.arguments[argsIndex].is_array)
                    index = VariableTable_defineVariable (&codeGenerator->table, functiondeclaration.arguments[argsIndex].name, type_Collection);
                else
                    index = VariableTable_defineVariable (&codeGenerator->table, functiondeclaration.arguments[argsIndex].name, tokenTypeToDataType (functiondeclaration.arguments[argsIndex].type, codeGenerator));

                argumentvar.is_argument = 1;
                argumentvar.argument_index = (functiondeclaration.argumentsCount - argsIndex)-1;
                argumentvar.index = index;
                argumentvar.type = functiondeclaration.arguments[argsIndex].is_array ? type_Collection : tokenTypeToDataType (functiondeclaration.arguments[argsIndex].type, codeGenerator);

                if(argumentvar.type == type_complex || argumentvar.type == type_function) {
                    if(functiondeclaration.arguments[argsIndex].type.type == TT_Identifier)
                        argumentvar.mothertype = functiondeclaration.arguments[argsIndex].type;
                    else
                        argumentvar.mothertype = (Token) {.type = TT_None};
                }

                if(argumentvar.type == type_function && argumentvar.mothertype.type == TT_Identifier) {
                    Symbol motherfunction = VariableTable_findVariableByName(&codeGenerator->table, argumentvar.mothertype);
                    syncFunctionSymbol(&argumentvar, motherfunction);
                }
                
                if (functiondeclaration.arguments[argsIndex].is_array) {
                    argumentvar.storingType = tokenTypeToDataType (functiondeclaration.arguments[argsIndex].type, codeGenerator);
                }
                VariableTable_setVariableByName (&codeGenerator->table, functiondeclaration.arguments[argsIndex].name, argumentvar);

                ByteWriter_writeByte (&tempWriter, BC_LOAD_ARGUMENT);
                ByteWriter_writeUInt (&tempWriter, argumentvar.argument_index);
                if (functiondeclaration.arguments[argsIndex].is_array) {
                    ByteWriter_writeByte (&tempWriter, BC_STORE_STACK_COLLECTION);
                }
                else {

                    switch (tokenTypeToDataType (functiondeclaration.arguments[argsIndex].type, codeGenerator)) {
                        case type_ubyte:
                        case type_byte:
                            ByteWriter_writeByte (&tempWriter, BC_STORE_STACK_NUM8);
                            break;
                        case type_ushort:
                        case type_short:
                            ByteWriter_writeByte (&tempWriter, BC_STORE_STACK_NUM16);
                            break;
                        case type_uint:
                        case type_int:
                        case type_float:
                            if (tokenTypeToDataType (functiondeclaration.arguments[argsIndex].type, codeGenerator) == type_float) {
                                ByteWriter_writeByte (&tempWriter, BC_Double2Float);
                            }
                            ByteWriter_writeByte (&tempWriter, BC_STORE_STACK_NUM32);
                            break;
                        case type_ulong:
                        case type_long:
                        case type_double:
                            ByteWriter_writeByte (&tempWriter, BC_STORE_STACK_NUM64);
                            break;
                        
                        case type_complex:
                        case type_text:
                            ByteWriter_writeByte (&tempWriter, BC_STORE_STACK_TEXT);
                            break;
                        case type_function:
                            ByteWriter_writeByte (&tempWriter, BC_STORE_STACK_FUNC);
                            break;
                        default:
                            markTokenError (functiondeclaration.arguments[argsIndex].name);
                            switch (argumentvar.value.type) {
                                case TT_String:
                                    printf ("Problem with Variable: %s\n", argumentvar.value.value.word);
                                    break;
                                case TT_Int:
                                    printf ("Problem with Variable: %lld\n", argumentvar.value.value.i);
                                    break;
                                case TT_Uint:
                                    printf ("Problem with Variable: %llu\n", argumentvar.value.value.u);
                                    break;
                                case TT_Float:
                                    printf ("Problem with Variable: %lf\n", argumentvar.value.value.f);
                                    break;
                                default: puts ("Something went wrong...");
                            }
                            puts ("This kind of type isn't supported yet!");
                            exit (1);
                    }
                }
                ByteWriter_writeUInt (&tempWriter, argumentvar.index);
            }
            // End Loading Arguments

            // set name of current Function in codeGenerator
            // for later refering
            codeGenerator->currentFunction = functionNode.name;

            // generating debugging hints for file
            {
                char hint[1024] = "fl;";

                strcat(hint, functionNode.name.file_path);
                strcat(hint, ":");
                strcat(hint, functionNode.name.value.word);

                ByteWriter_writeByte(&tempWriter, BC_HINT);
                unsigned int hint_len = strlen(hint);
                ByteWriter_writeUInt(&tempWriter, hint_len);
                for(unsigned int i = 0; i < hint_len; ++i) {
                    ByteWriter_writeByte(&tempWriter, hint[i]);
                }

                codeGenerator->currentLine = 0;
            }

            // generating the whole code corresponding to the execution of the function
            unsigned char functionRType = CodeGenerator_generateStatement (codeGenerator, functionNode.statements, fscope, &tempWriter);

            // Select Function in Symboltable
            Symbol datafunctiondeclaration = VariableTable_findVariableByName (&codeGenerator->table, functionNode.name);

            // Now would be the time to generate the table class
            if(datafunctiondeclaration.mothertype.type != TT_None) {
                if(strcmp(datafunctiondeclaration.mothertype.value.word, "table") == 0) {

                    // We need next to implement some kind of macro
                    // that will executes a function
                    SyntaxNode constructionFnCallNode = newFunctionCallNode(newValueNode((
                        (Token) {
                            .type = TT_Identifier,
                            .value.word = "$_constructor_$"
                        }
                    )));


                    char *tableIndex = (char*) malloc(sizeof(char) * 1024);
                    tableIndex[0u] = '\0';

                    // Generating table Index
                    strcat(tableIndex, datafunctiondeclaration.value.value.word);
                    strcat(tableIndex, "(");
                    for(unsigned int fnArgumentIndex = 0u; fnArgumentIndex < datafunctiondeclaration.argumentsCount; fnArgumentIndex++) {
                        strcat(tableIndex, datafunctiondeclaration.arguments[fnArgumentIndex].name.value.word);
                        strcat(tableIndex, ":");
                        strcat(tableIndex, getTypeRepresentation(tokenTypeToDataType(datafunctiondeclaration.arguments[fnArgumentIndex].type, codeGenerator)));
                        if((fnArgumentIndex+1u) < datafunctiondeclaration.argumentsCount)
                            strcat(tableIndex, ",");
                    }
                    strcat(tableIndex, ")");

                    FunctionCallNode_add(constructionFnCallNode, newValueNode( (Token) {
                        .type = TT_String,
                        .value.word = tableIndex
                    }));

                    // Now we add all the arguments to the function call
                    for(unsigned int fnArgumentIndex = 0u; fnArgumentIndex < datafunctiondeclaration.argumentsCount; fnArgumentIndex++) {
                        FunctionCallNode_add(constructionFnCallNode, newValueNode( (Token) {
                            .type = TT_Identifier,
                            .value.word = datafunctiondeclaration.arguments[fnArgumentIndex].name.value.word
                        }));
                    }

                    // Next we execute this functioncall!

                    unsigned char type = CodeGenerator_generateExpression(codeGenerator, constructionFnCallNode, fscope, &tempWriter);

                    ByteWriter_writeByte(&tempWriter, BC_RETURN_ELEMENT);
                }
            } 
            
            if (functionRType != type_none) {
                // If the last returning type of the last statement
                // Is able to be returned, we simply returning it.

                ByteWriter_writeByte (&tempWriter, BC_RETURN_ELEMENT);
                if(functiondeclaration.returnType == type_none) {
                    functiondeclaration.returnType = functionRType;
                }
            }

            // Updating Function
            functiondeclaration.memoryDeclaration = datafunctiondeclaration.memoryDeclaration;
            VariableTable_setVariableByName (&codeGenerator->table, functiondeclaration.value, functiondeclaration);

            // Forget about all these local variables in the function
            VariableTable_removeAllLocal (&codeGenerator->table);
        }
        else if (node.type == ID_VanguardNode) {
            FunctionNode functionNode = *node.vanguardNode->functionDeclaration.functionNode;
            Symbol functiondeclaration = VariableTable_findVariableByName (&codeGenerator->table, functionNode.name);
            ByteWriter tempWriter = ByteWriter_init (&functiondeclaration.code, &functiondeclaration.codelength);
            Scope fscope = (Scope) {
                .rgtr = scope_local,
                .function = functiondeclaration.value
            };
            for (unsigned char argsIndex = 0; argsIndex < functiondeclaration.argumentsCount; argsIndex++) {
                Symbol argumentvar = VariableTable_declareVariable (&codeGenerator->table, functiondeclaration.arguments[argsIndex].name, fscope);
                unsigned index;
                if (functiondeclaration.arguments[argsIndex].is_array)
                    index = VariableTable_defineVariable (&codeGenerator->table, functiondeclaration.arguments[argsIndex].name, type_Collection);
                else
                    index = VariableTable_defineVariable (&codeGenerator->table, functiondeclaration.arguments[argsIndex].name, tokenTypeToDataType (functiondeclaration.arguments[argsIndex].type, codeGenerator));
                argumentvar.is_argument = 1;
                argumentvar.argument_index = (functiondeclaration.argumentsCount - argsIndex)-1;
                argumentvar.index = index;
                argumentvar.type = functiondeclaration.arguments[argsIndex].is_array ? type_Collection : tokenTypeToDataType (functiondeclaration.arguments[argsIndex].type, codeGenerator);
                if (functiondeclaration.arguments[argsIndex].is_array) {
                    argumentvar.storingType = tokenTypeToDataType (functiondeclaration.arguments[argsIndex].type, codeGenerator);
                }
                VariableTable_setVariableByName (&codeGenerator->table, functiondeclaration.arguments[argsIndex].name, argumentvar);

                ByteWriter_writeByte (&tempWriter, BC_LOAD_ARGUMENT);
                ByteWriter_writeUInt (&tempWriter, argumentvar.argument_index);
                if (functiondeclaration.arguments[argsIndex].is_array) {
                    ByteWriter_writeByte (&tempWriter, BC_STORE_STACK_COLLECTION);
                }
                else
                    switch (tokenTypeToDataType (functiondeclaration.arguments[argsIndex].type, codeGenerator)) {
                        case type_ubyte:
                        case type_byte:
                            ByteWriter_writeByte (&tempWriter, BC_STORE_STACK_NUM8);
                            break;
                        case type_ushort:
                        case type_short:
                            ByteWriter_writeByte (&tempWriter, BC_STORE_STACK_NUM16);
                            break;
                        case type_uint:
                        case type_int:
                        case type_float:
                            if (tokenTypeToDataType (functiondeclaration.arguments[argsIndex].type, codeGenerator) == type_float) {
                                ByteWriter_writeByte (&tempWriter, BC_Double2Float);
                            }
                            ByteWriter_writeByte (&tempWriter, BC_STORE_STACK_NUM32);
                            break;
                        case type_ulong:
                        case type_long:
                        case type_double:
                            ByteWriter_writeByte (&tempWriter, BC_STORE_STACK_NUM64);
                            break;
                        case type_text:
                            ByteWriter_writeByte (&tempWriter, BC_STORE_STACK_TEXT);
                            break;
                        default:
                            markTokenError (functiondeclaration.arguments[argsIndex].name);
                            switch (functiondeclaration.arguments[argsIndex].name.type) {
                                case TT_String:
                                    printf ("Problem with Function Argument: %s, in Function: %s\n", functiondeclaration.arguments[argsIndex].name.value.word, functiondeclaration.value.value.word);
                                    break;
                                case TT_Int:
                                    printf ("Problem with Function Argument: %lld, in Function: %s\n", functiondeclaration.arguments[argsIndex].name.value.i, functiondeclaration.value.value.word);
                                    break;
                                case TT_Uint:
                                    printf ("Problem with Function Argument: %llu, in Function: %s\n", functiondeclaration.arguments[argsIndex].name.value.u, functiondeclaration.value.value.word);
                                    break;
                                case TT_Float:
                                    printf ("Problem with Function Argument: %lf, in Function: %s\n", functiondeclaration.arguments[argsIndex].name.value.f, functiondeclaration.value.value.word);
                                    break;
                                default: puts ("Something went wrong...");
                            }
                            puts ("This kind of type isn't supported yet!");
                            exit (1);
                    }
                ByteWriter_writeUInt (&tempWriter, argumentvar.index);
            }
            codeGenerator->currentFunction = functionNode.name;

            // generating debugging hints for file
            {
                char hint[1024] = "fl;";

                strcat(hint, functionNode.name.file_path);
                strcat(hint, ":");
                strcat(hint, functionNode.name.value.word);

                ByteWriter_writeByte(&tempWriter, BC_HINT);
                unsigned int hint_len = strlen(hint);
                ByteWriter_writeUInt(&tempWriter, hint_len);
                for(unsigned int i = 0; i < hint_len; ++i) {
                    ByteWriter_writeByte(&tempWriter, hint[i]);
                }

                codeGenerator->currentLine = 0;
            }

            unsigned char functionRType = CodeGenerator_generateStatement (codeGenerator, functionNode.statements, fscope, &tempWriter);
            if (functionRType != type_none) {
                ByteWriter_writeByte (&tempWriter, BC_RETURN_ELEMENT);
                if(functiondeclaration.returnType == type_none) {
                    functiondeclaration.returnType = functionRType;
                }
            }
            Symbol datafunctiondeclaration = VariableTable_findVariableByName (&codeGenerator->table, functionNode.name);
            functiondeclaration.memoryDeclaration = datafunctiondeclaration.memoryDeclaration;
            VariableTable_setVariableByName (&codeGenerator->table, functiondeclaration.value, functiondeclaration);
            VariableTable_removeAllLocal (&codeGenerator->table);
        }
    }
}


unsigned char CodeGenerator_generateStatement (struct CodeGenerator* codeGenerator, struct SyntaxNode node, struct Scope scope, struct ByteWriter* byteWriter) {
    unsigned char result_type = type_none;
    switch (node.type) {
        case ID_Include:
        {

            IncludeNode includeNode = *node.includeNode;

            unsigned int line_count = includeNode.identifier.lineNumber;
            if(DEBUGGING_MODE)
            if(line_count != 0 && codeGenerator->currentLine != line_count) {
                codeGenerator->currentLine = line_count;
                char hint[1024] = "";

                sprintf(hint, "ln;%d", line_count);

                ByteWriter_writeByte(byteWriter, BC_HINT);
                unsigned int hint_len = strlen(hint);
                ByteWriter_writeUInt(byteWriter, hint_len);
                for(unsigned int i = 0; i < hint_len; ++i) {
                    ByteWriter_writeByte(byteWriter, hint[i]);
                }
            }

            if(includeNode.declaration.type != TT_None) {
                if(VariableTable_findVariableByName(&codeGenerator->table, includeNode.identifier).type == type_undefined) {
                    Symbol symbol = VariableTable_findVariableByName(&codeGenerator->table, includeNode.declaration);
                    if(symbol.type == type_undefined) {
                        puts("Cannot find implementation in library!");
                        markTokenError(includeNode.includeNode);
                        exit(1);
                    }
                    VariableTable_createReferenceByName(&codeGenerator->table, symbol.value, includeNode.identifier); 
                }
            } else if(includeNode.library.type != TT_None) {
                CodeGenerator_includeLibWithOutNamespace(codeGenerator, includeNode.library.value.word);
            } else {
                puts("Cannot implement from library!");
                markTokenError(includeNode.includeNode);
                exit(1);
            }
        }
            break;

        case ID_IfNode:
        {
            // If-Statement
            IfNode ifNode = *node.ifNode;

            unsigned int line_count = ifNode.ifWord.lineNumber;
            if(DEBUGGING_MODE)
            if(line_count != 0 && codeGenerator->currentLine != line_count) {
                codeGenerator->currentLine = line_count;
                char hint[1024] = "";

                sprintf(hint, "ln;%d", line_count);

                ByteWriter_writeByte(byteWriter, BC_HINT);
                unsigned int hint_len = strlen(hint);
                ByteWriter_writeUInt(byteWriter, hint_len);
                for(unsigned int i = 0; i < hint_len; ++i) {
                    ByteWriter_writeByte(byteWriter, hint[i]);
                }
            }

            unsigned char rexpression = CodeGenerator_generateExpression (codeGenerator, ifNode.condition, scope, byteWriter);
            
            if(rexpression == type_none || rexpression == type_undefined) {
                puts("expression in if doesn't provide an return...");
                markTokenError(ifNode.ifWord);
                exit(1);
            }
            
            char* statementsCode = NULL;
            unsigned int statementsCodeLength = 0;
            char* elseStatementsCode = NULL;
            unsigned int elseStatementsCodeLength = 0;
            ByteWriter tempWriter = ByteWriter_init (&statementsCode, &statementsCodeLength);
            unsigned char ifRType = CodeGenerator_generateStatement (codeGenerator, ifNode.statements, scope, &tempWriter);
            if(ifRType != type_none) {
                ByteWriter_writeByte(&tempWriter, BC_POP);
            }
            tempWriter = (ByteWriter) ByteWriter_init (&elseStatementsCode, &elseStatementsCodeLength); 
            unsigned char elseRType = CodeGenerator_generateStatement (codeGenerator, ifNode.elseStatements, scope, &tempWriter);
            if(elseRType != type_none) {
                ByteWriter_writeByte(&tempWriter, BC_POP);
            }
            ByteWriter_writeByte (byteWriter, BC_JUMP_IF_TRUE_POS);
            ByteWriter_writeUShort (byteWriter, elseStatementsCodeLength+3);
            ByteWriter_addOps (byteWriter, elseStatementsCode, elseStatementsCodeLength);
            ByteWriter_writeByte (byteWriter, BC_JUMP_POS);
            ByteWriter_writeUShort (byteWriter, statementsCodeLength);
            ByteWriter_addOps (byteWriter, statementsCode, statementsCodeLength);
        }
            break;
        case ID_ForNode:
        {
            // For-Statement

            // to work with the for statement we need to directly access it
            ForNode forNode = *node.forNode;

            unsigned int line_count = forNode.forWord.lineNumber;
            if(DEBUGGING_MODE)
            if(line_count != 0 && codeGenerator->currentLine != line_count) {
                codeGenerator->currentLine = line_count;
                char hint[1024] = "";

                sprintf(hint, "ln;%d", line_count);

                ByteWriter_writeByte(byteWriter, BC_HINT);
                unsigned int hint_len = strlen(hint);
                ByteWriter_writeUInt(byteWriter, hint_len);
                for(unsigned int i = 0; i < hint_len; ++i) {
                    ByteWriter_writeByte(byteWriter, hint[i]);
                }
            }

            // The producting statements, we'll store in here
            char* statements = NULL;
            unsigned int statementsLength = 0;

            // In the case that the for loop does have an initalization,
            // we're now need to generate the bytecode so it will be
            // executed once
            if(forNode.init.type != ID_None) {
                unsigned char initRType = CodeGenerator_generateExpression(codeGenerator, forNode.init, scope, byteWriter);
                if(initRType != type_none) {
                    ByteWriter_writeByte(byteWriter, BC_POP);
                }
            }

            // mark the begin in order to return there back later
            unsigned int begin = *byteWriter->length;
            
            // Store the continueLocationIndex into a stack inside codeGenerator
            // we do it, because if later the keyword 'continue' is used,
            // we do want to return to this point and have stored it in a stack in case
            // of nested for loops
            codeGenerator->continueLocation[codeGenerator->continueLocationIndex++] = begin;

            // Now we need a buffer, so we know how big the whole statement will be in order to jump over it.
            ByteWriter tempWriter = ByteWriter_init (&statements, &statementsLength);

            // And make sure that the number of declarations do not grow in this process
            unsigned int before = codeGenerator->table.numberOfDeclarations;

            // Now we're generating the Statement (Statements)
            unsigned char forStatementReturnType = CodeGenerator_generateStatement (codeGenerator, forNode.statements, scope, &tempWriter);

            // Statements can now return values, thus we make sure to clean up this..
            if (forStatementReturnType != type_none)
                ByteWriter_writeByte (&tempWriter, BC_POP);

            // if there is a post action, after every circle, we need to add this to our code!
            if(forNode.action.type != ID_None) {
                unsigned char forActionRType = CodeGenerator_generateExpression(codeGenerator, forNode.action, scope, &tempWriter);
                
                // Also here, its important to clean up returning values
                if(forActionRType != type_none) {
                    ByteWriter_writeByte (&tempWriter, BC_POP);
                }
            }

            // Now we're generate the condition for the 'for' loop to circle
            if(forNode.condition.type != ID_None) {
                CodeGenerator_generateExpression (codeGenerator, forNode.condition, scope, byteWriter);
                // If the condition returns true, the virtual machine enters the loop and eventually 
                // reach the end of the loop, where it starts again
                ByteWriter_writeByte (byteWriter, BC_JUMP_IF_FALSE_POS);

                // But if the condition doesn't returns true, we'll must end the loop and
                // jump to the exit of the loop
                ByteWriter_writeUShort (byteWriter, statementsLength+3);
            }
            // If the condition is true, we simple want a endless loop and
            // therefore we simple don't need an evaluation

            // Now we can also log the location were the virtual machine must jump
            // if an break statement from the loop has been invoke
            codeGenerator->breakLocation[codeGenerator->breakLocationIndex++] = *byteWriter->length + 3 + statementsLength;
            
            // Now that we know the exact size of the statement, we can release the buffer
            // beeing used for writing it into
            free (statements);
            statements = NULL;
            statementsLength = 0;

            // Now we'll start again
            tempWriter = ByteWriter_init (&statements, &statementsLength);

            // All variables that have been registered have to be removed from the table
            // Otherwise they would be defined twice and thats bad for memory and causes bugs
            for (unsigned int variableIndex = 0; variableIndex < codeGenerator->table.numberOfDeclarations; variableIndex++) {
                if (variableIndex < before || codeGenerator->table.declarations[variableIndex].scope.rgtr == scope_constant) continue;
                VariableTable_removeDeclaration (&codeGenerator->table, variableIndex);
                variableIndex--;
            }

            // Here comes the same statement but with jump positions
            unsigned char forStatementReturnType2 = CodeGenerator_generateStatement (codeGenerator, forNode.statements, scope, &tempWriter);
            
            // Again, statements return values, we have to clean them up
            if (forStatementReturnType2 != type_none)
                ByteWriter_writeByte (&tempWriter, BC_POP);

            // Again, if there is a post action, after every circle, we need to add this to our code!
            if(forNode.action.type != ID_None) {
                unsigned char forActionRType = CodeGenerator_generateExpression(codeGenerator, forNode.action, scope, &tempWriter);
                
                // Again Also here, its important to clean up returning values
                if(forActionRType != type_none) {
                    ByteWriter_writeByte (&tempWriter, BC_POP);
                }
            }
            
            // Eventually we'll add these operations to our offical code
            ByteWriter_addOps (byteWriter, statements, statementsLength);

            // Restart the loop via simple negative jump
            unsigned int end = *byteWriter->length;
            unsigned short spann = end - begin;
            ByteWriter_writeByte (byteWriter, BC_JUMP_NEG);
            ByteWriter_writeUShort (byteWriter, spann);

            // We don't need these anymore
            codeGenerator->continueLocationIndex--;
            codeGenerator->breakLocationIndex--;
            free (statements);
        }
            break;

        case ID_UnaryInstructionNode:
        {
            UnaryInstructionNode instructionNode = *node.unaryInstructionNode;

            unsigned int line_count = instructionNode.instruction.lineNumber;
            if(DEBUGGING_MODE)
            if(line_count != 0 && codeGenerator->currentLine != line_count) {
                codeGenerator->currentLine = line_count;
                char hint[1024] = "";

                sprintf(hint, "ln;%d", line_count);

                ByteWriter_writeByte(byteWriter, BC_HINT);
                unsigned int hint_len = strlen(hint);
                ByteWriter_writeUInt(byteWriter, hint_len);
                for(unsigned int i = 0; i < hint_len; ++i) {
                    ByteWriter_writeByte(byteWriter, hint[i]);
                }
            }

            switch (instructionNode.instruction.type) {
                case TTK_Break:
                    if (codeGenerator->breakLocationIndex != 0) {
                        ByteWriter_writeByte (byteWriter, BC_JUMP_ABS);
                        ByteWriter_writeUInt (byteWriter, codeGenerator->breakLocation[codeGenerator->breakLocationIndex-1]);
                    } else {
                        ByteWriter_writeByte (byteWriter, BC_JUMP_ABS);
                        ByteWriter_writeUInt (byteWriter, 0);
                    }
                    break;
                case TTK_Continue:
                    if (codeGenerator->continueLocationIndex != 0) {
                        ByteWriter_writeByte (byteWriter, BC_JUMP_ABS);
                        ByteWriter_writeUInt (byteWriter, codeGenerator->continueLocation[codeGenerator->continueLocationIndex-1]);
                    } else {
                        ByteWriter_writeByte (byteWriter, BC_JUMP_ABS);
                        ByteWriter_writeUInt (byteWriter, 0);
                    }
                    break;
                default:;
            }
        }
            break;

        case ID_StatementsNode:
        {
            StatementsNode statementNode = *node.statementsNode;
            unsigned char lreturnType = CodeGenerator_generateStatement (codeGenerator, statementNode.first, scope, byteWriter);
            if (lreturnType != type_none)
                ByteWriter_writeByte (byteWriter, BC_POP);
            
            unsigned char rreturnType = CodeGenerator_generateStatement (codeGenerator, statementNode.second, scope, byteWriter);
            result_type = rreturnType;
        }
            break;
        case ID_ReturnNode:
        {
            ReturnNode returnNode = *node.returnNode;

            unsigned int line_count = returnNode.returnWord.lineNumber;
            if(DEBUGGING_MODE)
            if(line_count != 0 && codeGenerator->currentLine != line_count) {
                codeGenerator->currentLine = line_count;
                char hint[1024] = "";

                sprintf(hint, "ln;%d", line_count);

                ByteWriter_writeByte(byteWriter, BC_HINT);
                unsigned int hint_len = strlen(hint);
                ByteWriter_writeUInt(byteWriter, hint_len);
                for(unsigned int i = 0; i < hint_len; ++i) {
                    ByteWriter_writeByte(byteWriter, hint[i]);
                }
            }

            unsigned char type = type_none;
            Symbol fn = VariableTable_findVariableByName (&codeGenerator->table, scope.function);
            unsigned char returntype = fn.returnType;
            if (returntype != type_none)
                type = CodeGenerator_generateExpression (codeGenerator, returnNode.expression, scope, byteWriter);
            else {
                puts("Function is claimed to return nothing... you lied to the compiler :(");
                markTokenError(fn.value);
                exit(1);
            }

            returntype = typeToStackType (returntype);
            type = typeToStackType (type);

            // if the function has no implicit type and it returns something, it will take the type of the return
            //if (returntype == type_none) {
            //    fn.returnType = type;
            //    VariableTable_setVariableByName (&codeGenerator->table, fn.value, fn);
            //    fn = VariableTable_findVariableByName (&codeGenerator->table, fn.value);
            //    returntype = type;
            //}

            if (returntype != type) {
                switch (type) {
                    case type_ulong:
                        if (returntype == type_long)
                            ByteWriter_writeByte (byteWriter, BC_U2I);
                        else if (returntype == type_double)
                            ByteWriter_writeByte (byteWriter, BC_U2F);
                        else {
                            puts ("The Function returns a different Datatype!");
                            markTokenError( fn.value);
                            exit (1);
                        }
                        break;
                    case type_long:
                        if (returntype == type_ulong)
                            ByteWriter_writeByte (byteWriter, BC_I2U);
                        else if (returntype == type_double)
                            ByteWriter_writeByte (byteWriter, BC_I2F);
                        else {
                            puts ("The Function returns a different Datatype!");
                            markTokenError( fn.value);
                            exit (1);
                        }
                        break;
                    case type_double:
                        if (returntype == type_ulong)
                            ByteWriter_writeByte (byteWriter, BC_F2U);
                        else if (returntype == type_long)
                            ByteWriter_writeByte (byteWriter, BC_F2I);
                        else {
                            puts ("The Function returns a different Datatype!");
                            markTokenError( fn.value);
                            exit (1);
                        }
                        break;
                    case type_text:
                        puts ("The Function returns a different Datatype!");
                        markTokenError( fn.value);
                        exit (1);
                        break;
                    case type_Collection:
                        if (fn.returnType_isArray) {
                            break;
                        }
                        puts ("The Function returns a different Datatype!");
                        markTokenError( fn.value);
                        exit (1);
                        break;
                    case type_complex:
                        // We need to check that
                        // The returning complex
                        // has the right motherclass
                        puts ("The Function returns a different Datatype!");
                        markTokenError( fn.value);
                        exit (1);
                        break;
                    case type_none:
                        ByteWriter_writeByte (byteWriter, BC_BUILD_EMPTYCOLLECTION);
                        break;
                }
            }

            ByteWriter_writeByte (byteWriter, BC_RETURN_ELEMENT);
        }
            break;
        default:;
            // Expression
            unsigned char type = CodeGenerator_generateExpression (codeGenerator, node, scope, byteWriter);
            return type;
    }

    return result_type;
}

void CodeGenerator_generateLogFunctionEnter(struct CodeGenerator *codeGenerator, struct FunctionCallNode fncall, struct Symbol fn, struct Scope scope, struct ByteWriter *byteWriter) {
    if(DEBUGGING_MODE != 0) return;
    Symbol tracerFunction = VariableTable_findVariableByName(&codeGenerator->table, (Token) {
        .type = TT_Identifier, .value.word = "function_tracer_enter"
    });
    if((strcmp(codeGenerator->currentFunction.value.word, "function_tracer_enter") != 0) && (strcmp(codeGenerator->currentFunction.value.word, "function_tracer_leave") != 0))
    if((tracerFunction.type == type_function) && (strcmp(fn.value.value.word, "function_tracer_enter") != 0) && (strcmp(fn.value.value.word, "function_tracer_leave") != 0)) {
        SyntaxNode fnCallNode = newFunctionCallNode(newValueNode((Token) {
            .type = TT_Identifier, .value.word = "function_tracer_enter"
        }));

        FunctionCallNode_add(fnCallNode, newValueNode(
            (Token) {.type = TT_String, .value.word = fn.value.value.word}
        ));

        FunctionCallNode_add(fnCallNode, newValueNode(
            (Token) {.type = TT_Uint, .value.u = fncall.identifier.valueNode->value.lineNumber}
        ));

        CodeGenerator_generateExpression(codeGenerator, fnCallNode, scope, byteWriter);
        ByteWriter_writeByte(byteWriter, BC_POP);
    }
}

void CodeGenerator_generateLogFunctionLeave(struct CodeGenerator *codeGenerator, struct FunctionCallNode fncall, struct Symbol fn, struct Scope scope, struct ByteWriter *byteWriter) {
    if(DEBUGGING_MODE != 2) return;
    Symbol tracerFunction = VariableTable_findVariableByName(&codeGenerator->table, (Token) {
        .type = TT_Identifier, .value.word = "function_tracer_leave"
    });
    if((strcmp(codeGenerator->currentFunction.value.word, "function_tracer_enter") != 0) && (strcmp(codeGenerator->currentFunction.value.word, "function_tracer_leave") != 0))
    if((tracerFunction.type == type_function)  && (strcmp(fn.value.value.word, "function_tracer_enter") != 0) && (strcmp(fn.value.value.word, "function_tracer_leave") != 0)) {
        SyntaxNode fnCallNode = newFunctionCallNode(newValueNode((Token) {
            .type = TT_Identifier, .value.word = "function_tracer_leave"
        }));

        FunctionCallNode_add(fnCallNode, newValueNode(
            (Token) {.type = TT_String, .value.word = fn.value.value.word}
        ));

        FunctionCallNode_add(fnCallNode, newValueNode(
            (Token) {.type = TT_Uint, .value.u = fncall.identifier.valueNode->value.lineNumber}
        ));

        CodeGenerator_generateExpression(codeGenerator, fnCallNode, scope, byteWriter);
        ByteWriter_writeByte(byteWriter, BC_POP);
    }
}

// returns a type
unsigned char CodeGenerator_generateExpression (struct CodeGenerator* codeGenerator, struct SyntaxNode node, struct Scope scope, struct ByteWriter* byteWriter) {

    switch (node.type) {
        
        case ID_Include:
        {
            IncludeNode implementNode = *node.includeNode;
            unsigned int line_count = implementNode.identifier.lineNumber;

            if(DEBUGGING_MODE)
            if(line_count != 0 && codeGenerator->currentLine != line_count) {
                codeGenerator->currentLine = line_count;
                char hint[1024] = "";

                sprintf(hint, "ln;%d", line_count);

                ByteWriter_writeByte(byteWriter, BC_HINT);
                unsigned int hint_len = strlen(hint);
                ByteWriter_writeUInt(byteWriter, hint_len);
                for(unsigned int i = 0; i < hint_len; ++i) {
                    ByteWriter_writeByte(byteWriter, hint[i]);
                }
            }
            
            if(implementNode.declaration.type != TT_None) {
                if(VariableTable_findVariableByName(&codeGenerator->table, implementNode.identifier).type == type_undefined) {
                    Symbol symbol = VariableTable_findVariableByName(&codeGenerator->table, implementNode.declaration);
                    if(symbol.type == type_undefined) {
                        puts("Cannot find implementation in library!");
                        markTokenError(implementNode.includeNode);
                        exit(1);
                    }
                    VariableTable_createReferenceByName(&codeGenerator->table, symbol.value, implementNode.identifier); 
                }
            } else if(implementNode.library.type != TT_None) {
                CodeGenerator_includeLibWithOutNamespace(codeGenerator, implementNode.library.value.word);
            } else {
                puts("Cannot implement from library!");
                markTokenError(implementNode.includeNode);
                exit(1);
            }

            return type_none;
        }
            break;
        
        case ID_IfNode:
        case ID_ForNode:
        case ID_UnaryInstructionNode:
        case ID_ReturnNode:
        case ID_StatementsNode:
        {

            unsigned char statementResultType = CodeGenerator_generateStatement(codeGenerator, node, scope, byteWriter);

            return statementResultType;
            
        }
            break;

        case ID_BinOpNode:
        {
            BinOpNode* binOpNode = node.binOpNode;
            unsigned int line_count = binOpNode->operator.lineNumber;
            if(DEBUGGING_MODE)
            if(line_count != 0 && codeGenerator->currentLine != line_count) {
                codeGenerator->currentLine = line_count;
                char hint[1024] = "";

                sprintf(hint, "ln;%d", line_count);

                ByteWriter_writeByte(byteWriter, BC_HINT);
                unsigned int hint_len = strlen(hint);
                ByteWriter_writeUInt(byteWriter, hint_len);
                for(unsigned int i = 0; i < hint_len; ++i) {
                    ByteWriter_writeByte(byteWriter, hint[i]);
                }
            }

            switch (binOpNode->operator.type) {

                // New In node

                // case TTK_In:
                // {
                //     // TODO: Finish to implement the In-Operator
                //     // 1. Get Variables on both sides
                //     // 2. Create Variable on left side
                //     // 3. check what mode it uses
                //     // 4. react accordingly
                //     // 5. generate bytecode

                //     if (binOpNode->left.type != ID_ValueNode) {
                //         puts ("In Loop needs an identifier as variable");
                //         markTokenError( binOpNode->operator);
                //         exit (1);
                //     }

                //     SyntaxNode right = binOpNode->right;
                //     // Making sure that right is a list or a range

                //     ValueNode iter_identifier = *binOpNode->left.valueNode;
                //     Symbol iter = VariableTable_findVariableByName (&codeGenerator->table, iter_identifier.value);
                // }
                //     break;

                case TT_Plus:
                {
                    char* left_ops = NULL;
                    unsigned int left_ops_length = 0;
                    char* right_ops = NULL;
                    unsigned int right_ops_length = 0;
                    ByteWriter tmpWriter = ByteWriter_init (&right_ops, &right_ops_length);

                    // Actually it parses it in the wrong order so here it gets fixed
                    unsigned char type_right = CodeGenerator_generateExpression (codeGenerator, binOpNode->right, scope, &tmpWriter);

                    tmpWriter = ByteWriter_init (&left_ops, &left_ops_length);

                    unsigned char type_left = CodeGenerator_generateExpression (codeGenerator, binOpNode->left, scope, &tmpWriter);

                    // Int + Int = Int
                    // UInt + UInt = UInt
                    // Float + Float = Float
                    // Int + Float = Float
                    // UInt + Float = Float
                    // Int + UInt = Int
                    switch (type_left) {
                        case type_ubyte:
                        case type_ushort:
                        case type_uint:
                        case type_ulong:
                            // UInt
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_ADD_U);
                                    return type_ulong;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_U2I);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_ADD_I);
                                    return type_long;
                                    break;
                                case type_float:
                                case type_double:
                                    // Float
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_U2F);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_ADD_F);
                                    return type_double;
                                    break;
                                default:
                                    puts ("Cannot use this Datatype with + Operator!");
                                    markTokenError(binOpNode->operator);
                                    exit (1);
                            }
                            break;
                        case type_byte:
                        case type_short:
                        case type_int:
                        case type_long:
                            // Int
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_U2I);
                                    ByteWriter_writeByte (byteWriter, BC_ADD_I);
                                    return type_long;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_ADD_I);
                                    return type_long;
                                    break;
                                case type_float:
                                case type_double:
                                    // Float
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_I2F);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_ADD_F);
                                    return type_double;
                                    break;
                                default:
                                    puts ("Cannot use this Datatype with + Operator!");
                                    markTokenError(binOpNode->operator);
                                    exit (1);
                            }
                            break;
                        case type_float:
                        case type_double:
                            // Float
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_U2F);
                                    ByteWriter_writeByte (byteWriter, BC_ADD_F);
                                    return type_double;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_I2F);
                                    ByteWriter_writeByte (byteWriter, BC_ADD_F);
                                    return type_double;
                                    break;
                                case type_float:
                                case type_double:
                                    // Float
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_ADD_F);
                                    return type_double;
                                    break;
                                default:
                                    puts ("Cannot use this Datatype with + Operator!");
                                    markTokenError(binOpNode->operator);
                                    exit (1);
                            }
                            break;
                        case type_text:
                            if (type_right == type_text) {
                                ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                ByteWriter_writeByte (byteWriter, BC_CONCAT);
                                return type_text;
                            } else {
                                puts ("Cannot use this Datatype with + Operator!");
                                markTokenError(binOpNode->operator);
                                exit (1);
                            }
                            break;
                        case type_Collection:
                            puts ("Cannot work with collections yet!");
                            markTokenError(binOpNode->operator);
                                exit (1);
                            break;
                        default:
                            puts ("Unusable Datatype!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                    }
                }
                    break;
                case TT_Minus:
                {
                    char* left_ops = NULL;
                    unsigned int left_ops_length = 0;
                    char* right_ops = NULL;
                    unsigned int right_ops_length = 0;
                    ByteWriter tmpWriter = ByteWriter_init (&right_ops, &right_ops_length);

                    // Actually it parses it in the wrong order so here it gets fixed
                    unsigned char type_right = CodeGenerator_generateExpression (codeGenerator, binOpNode->right, scope, &tmpWriter);

                    tmpWriter = ByteWriter_init (&left_ops, &left_ops_length);

                    unsigned char type_left = CodeGenerator_generateExpression (codeGenerator, binOpNode->left, scope, &tmpWriter);

                    // Int - Int = Int
                    // UInt - UInt = UInt
                    // Float - Float = Float
                    // Int - Float = Float
                    // UInt - Float = Float
                    // Int - UInt = Int
                    switch (type_left) {
                        case type_ubyte:
                        case type_ushort:
                        case type_uint:
                        case type_ulong:
                            // UInt
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_SUB_U);
                                    return type_ulong;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_U2I);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_SUB_I);
                                    return type_long;
                                    break;
                                case type_float:
                                case type_double:
                                    // Float
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_U2F);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_SUB_F);
                                    return type_double;
                                    break;
                            }
                            break;
                        case type_byte:
                        case type_short:
                        case type_int:
                        case type_long:
                            // Int
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_U2I);
                                    ByteWriter_writeByte (byteWriter, BC_SUB_I);
                                    return type_long;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_SUB_I);
                                    return type_long;
                                    break;
                                case type_float:
                                case type_double:
                                    // Float
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_I2F);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_SUB_F);
                                    return type_double;
                                    break;
                            }
                            break;
                        case type_float:
                        case type_double:
                            // Float
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_U2F);
                                    ByteWriter_writeByte (byteWriter, BC_SUB_F);
                                    return type_double;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_I2F);
                                    ByteWriter_writeByte (byteWriter, BC_SUB_F);
                                    return type_double;
                                    break;
                                case type_float:
                                case type_double:
                                    // Float
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_SUB_F);
                                    return type_double;
                                    break;
                            }
                            break;
                        case type_text:
                            puts ("Cannot work with text yet!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                        case type_Collection:
                            puts ("Cannot work with collections yet!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                        default:
                            puts ("Unusable Datatype!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                    }
                }
                    break;
                case TT_Multiply:
                {
                    char* left_ops = NULL;
                    unsigned int left_ops_length = 0;
                    char* right_ops = NULL;
                    unsigned int right_ops_length = 0;
                    ByteWriter tmpWriter = ByteWriter_init (&right_ops, &right_ops_length);

                    // Actually it parses it in the wrong order so here it gets fixed
                    unsigned char type_right = CodeGenerator_generateExpression (codeGenerator, binOpNode->right, scope, &tmpWriter);

                    tmpWriter = ByteWriter_init (&left_ops, &left_ops_length);

                    unsigned char type_left = CodeGenerator_generateExpression (codeGenerator, binOpNode->left, scope, &tmpWriter);

                    // Int * Int = Int
                    // UInt * UInt = UInt
                    // Float * Float = Float
                    // Int * Float = Float
                    // UInt * Float = Float
                    // Int * UInt = Int
                    switch (type_left) {
                        case type_ubyte:
                        case type_ushort:
                        case type_uint:
                        case type_ulong:
                            // UInt
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_MUL_U);
                                    return type_ulong;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_U2I);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_MUL_I);
                                    return type_long;
                                    break;
                                case type_float:
                                case type_double:
                                    // Float
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_U2F);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_MUL_F);
                                    return type_double;
                                    break;
                            }
                            break;
                        case type_byte:
                        case type_short:
                        case type_int:
                        case type_long:
                            // Int
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_U2I);
                                    ByteWriter_writeByte (byteWriter, BC_MUL_I);
                                    return type_long;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_MUL_I);
                                    return type_long;
                                    break;
                                case type_float:
                                case type_double:
                                    // Float
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_I2F);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_MUL_F);
                                    return type_double;
                                    break;
                            }
                            break;
                        case type_float:
                        case type_double:
                            // Float
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_U2F);
                                    ByteWriter_writeByte (byteWriter, BC_MUL_F);
                                    return type_double;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_I2F);
                                    ByteWriter_writeByte (byteWriter, BC_MUL_F);
                                    return type_double;
                                    break;
                                case type_float:
                                case type_double:
                                    // Float
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_MUL_F);
                                    return type_double;
                                    break;
                            }
                            break;
                        case type_text:
                            puts ("Cannot work with text yet!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                        case type_Collection:
                            puts ("Cannot work with collections yet!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                        default:
                            puts ("Unusable Datatype!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                    }
                }
                    break;
                case TT_Divide:
                {
                    char* left_ops = NULL;
                    unsigned int left_ops_length = 0;
                    char* right_ops = NULL;
                    unsigned int right_ops_length = 0;
                    ByteWriter tmpWriter = ByteWriter_init (&right_ops, &right_ops_length);

                    // Actually it parses it in the wrong order so here it gets fixed
                    unsigned char type_right = CodeGenerator_generateExpression (codeGenerator, binOpNode->right, scope, &tmpWriter);

                    tmpWriter = ByteWriter_init (&left_ops, &left_ops_length);

                    unsigned char type_left = CodeGenerator_generateExpression (codeGenerator, binOpNode->left, scope, &tmpWriter);

                    // Int / Int = Int
                    // UInt / UInt = UInt
                    // Float / Float = Float
                    // Int / Float = Float
                    // UInt / Float = Float
                    // Int / UInt = Int
                    switch (type_left) {
                        case type_ubyte:
                        case type_ushort:
                        case type_uint:
                        case type_ulong:
                            // UInt
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_DIV_U);
                                    return type_ulong;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_U2I);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_DIV_I);
                                    return type_long;
                                    break;
                                case type_float:
                                case type_double:
                                    // Float
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_U2F);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_DIV_F);
                                    return type_double;
                                    break;
                            }
                            break;
                        case type_byte:
                        case type_short:
                        case type_int:
                        case type_long:
                            // Int
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_U2I);
                                    ByteWriter_writeByte (byteWriter, BC_DIV_I);
                                    return type_long;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_DIV_I);
                                    return type_long;
                                    break;
                                case type_float:
                                case type_double:
                                    // Float
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_I2F);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_DIV_F);
                                    return type_double;
                                    break;
                            }
                            break;
                        case type_float:
                        case type_double:
                            // Float
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_U2F);
                                    ByteWriter_writeByte (byteWriter, BC_DIV_F);
                                    return type_double;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_I2F);
                                    ByteWriter_writeByte (byteWriter, BC_DIV_F);
                                    return type_double;
                                    break;
                                case type_float:
                                case type_double:
                                    // Float
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_DIV_F);
                                    return type_double;
                                    break;
                            }
                            break;
                        case type_text:
                            puts ("Cannot work with text yet!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                        case type_Collection:
                            puts ("Cannot work with collections yet!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                        default:
                            puts ("Unusable Datatype!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                    }
                }
                    break;
                case TT_Modulo:
                {
                    char* left_ops = NULL;
                    unsigned int left_ops_length = 0;
                    char* right_ops = NULL;
                    unsigned int right_ops_length = 0;
                    ByteWriter tmpWriter = ByteWriter_init (&right_ops, &right_ops_length);

                    // Actually it parses it in the wrong order so here it gets fixed
                    unsigned char type_right = CodeGenerator_generateExpression (codeGenerator, binOpNode->right, scope, &tmpWriter);

                    tmpWriter = ByteWriter_init (&left_ops, &left_ops_length);

                    unsigned char type_left = CodeGenerator_generateExpression (codeGenerator, binOpNode->left, scope, &tmpWriter);


                    switch (type_left) {
                        case type_ubyte:
                        case type_ushort:
                        case type_uint:
                        case type_ulong:
                            // UInt
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_MOD_U);
                                    return type_ulong;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_U2I);
                                    ByteWriter_writeByte (byteWriter, BC_MOD_I);
                                    return type_long;
                                    break;
                            }
                            break;
                        case type_byte:
                        case type_short:
                        case type_int:
                        case type_long:
                            // Int
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_U2I);
                                    ByteWriter_writeByte (byteWriter, BC_MOD_I);
                                    return type_long;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_MOD_I);
                                    return type_long;
                                    break;
                            }
                            break;
                        case type_text:
                            puts ("Cannot work with text yet!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                        case type_Collection:
                            puts ("Cannot work with collections yet!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                        default:
                            puts ("Unusable Datatype!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                    }
                }
                    break;

                case TT_EqualsEquals:
                {
                    char* left_ops = NULL;
                    unsigned int left_ops_length = 0;
                    char* right_ops = NULL;
                    unsigned int right_ops_length = 0;
                    ByteWriter tmpWriter = ByteWriter_init (&right_ops, &right_ops_length);

                    // Actually it parses it in the wrong order so here it gets fixed
                    unsigned char type_right = CodeGenerator_generateExpression (codeGenerator, binOpNode->right, scope, &tmpWriter);

                    tmpWriter = ByteWriter_init (&left_ops, &left_ops_length);

                    unsigned char type_left = CodeGenerator_generateExpression (codeGenerator, binOpNode->left, scope, &tmpWriter);

                    // Int == Int = ubyte
                    // UInt == UInt = ubyte
                    // Float == Float = ubyte
                    // Int == Float = ubyte
                    // UInt == Float = ubyte
                    // Int == UInt = ubyte
                    switch (type_left) {
                        case type_ubyte:
                        case type_ushort:
                        case type_uint:
                        case type_ulong:
                            // UInt
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_EQ_U);
                                    return type_ubyte;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_SWAP);
                                    ByteWriter_writeByte (byteWriter, BC_EQ_IU);
                                    return type_ubyte;
                                    break;
                                case type_float:
                                case type_double:
                                    // Float
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_SWAP);
                                    ByteWriter_writeByte (byteWriter, BC_EQ_FU);
                                    return type_ubyte;
                                    break;
                            }
                            break;
                        case type_byte:
                        case type_short:
                        case type_int:
                        case type_long:
                            // Int
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_EQ_IU);
                                    return type_ubyte;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_EQ_I);
                                    return type_ubyte;
                                    break;
                                case type_float:
                                case type_double:
                                    // Float
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_SWAP);
                                    ByteWriter_writeByte (byteWriter, BC_EQ_FI);
                                    return type_ubyte;
                                    break;
                            }
                            break;
                        case type_float:
                        case type_double:
                            // Float
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_EQ_FU);
                                    return type_ubyte;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_EQ_FI);
                                    return type_ubyte;
                                    break;
                                case type_float:
                                case type_double:
                                    // Float
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_EQ_F);
                                    return type_ubyte;
                                    break;
                            }
                            break;
                        case type_text:
                            

                            puts ("Cannot work with text yet!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                        case type_Collection:
                            puts ("Cannot work with collections yet!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                        default:
                            puts ("Unusable Datatype!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                    }
                }
                    break;

                case TT_Less:
                {
                    char* left_ops = NULL;
                    unsigned int left_ops_length = 0;
                    char* right_ops = NULL;
                    unsigned int right_ops_length = 0;
                    ByteWriter tmpWriter = ByteWriter_init (&right_ops, &right_ops_length);

                    // Actually it parses it in the wrong order so here it gets fixed
                    unsigned char type_right = CodeGenerator_generateExpression (codeGenerator, binOpNode->right, scope, &tmpWriter);

                    tmpWriter = ByteWriter_init (&left_ops, &left_ops_length);

                    unsigned char type_left = CodeGenerator_generateExpression (codeGenerator, binOpNode->left, scope, &tmpWriter);

                    // Int < Int = ubyte
                    // UInt < UInt = ubyte
                    // Float < Float = ubyte
                    // Int < Float = ubyte
                    // UInt < Float = ubyte
                    // Int < UInt = ubyte
                    switch (type_left) {
                        case type_ubyte:
                        case type_ushort:
                        case type_uint:
                        case type_ulong:
                            // UInt
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_SMALLER_U);
                                    return type_ubyte;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_SWAP);
                                    ByteWriter_writeByte (byteWriter, BC_BIGGER_IU);
                                    return type_ubyte;
                                    break;
                                case type_float:
                                case type_double:
                                    // Float
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_SWAP);
                                    ByteWriter_writeByte (byteWriter, BC_BIGGER_FU);
                                    return type_ubyte;
                                    break;
                            }
                            break;
                        case type_byte:
                        case type_short:
                        case type_int:
                        case type_long:
                            // Int
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_SMALLER_IU);
                                    return type_ubyte;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_SMALLER_I);
                                    return type_ubyte;
                                    break;
                                case type_float:
                                case type_double:
                                    // Float
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_SWAP);
                                    ByteWriter_writeByte (byteWriter, BC_BIGGER_FI);
                                    return type_ubyte;
                                    break;
                            }
                            break;
                        case type_float:
                        case type_double:
                            // Float
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_SMALLER_FU);
                                    return type_ubyte;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_SMALLER_FI);
                                    return type_ubyte;
                                    break;
                                case type_float:
                                case type_double:
                                    // Float
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_SMALLER_F);
                                    return type_ubyte;
                                    break;
                            }
                            break;
                        case type_text:
                            puts ("Cannot work with text yet!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                        case type_Collection:
                            puts ("Cannot work with collections yet!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                        default:
                            puts ("Unusable Datatype!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                    }
                }
                    break;

                case TT_Greater:
                {
                    char* left_ops = NULL;
                    unsigned int left_ops_length = 0;
                    char* right_ops = NULL;
                    unsigned int right_ops_length = 0;
                    ByteWriter tmpWriter = ByteWriter_init (&right_ops, &right_ops_length);

                    // Actually it parses it in the wrong order so here it gets fixed
                    unsigned char type_right = CodeGenerator_generateExpression (codeGenerator, binOpNode->right, scope, &tmpWriter);

                    tmpWriter = ByteWriter_init (&left_ops, &left_ops_length);

                    unsigned char type_left = CodeGenerator_generateExpression (codeGenerator, binOpNode->left, scope, &tmpWriter);

                    // Int < Int = ubyte
                    // UInt < UInt = ubyte
                    // Float < Float = ubyte
                    // Int < Float = ubyte
                    // UInt < Float = ubyte
                    // Int < UInt = ubyte
                    switch (type_left) {
                        case type_ubyte:
                        case type_ushort:
                        case type_uint:
                        case type_ulong:
                            // UInt
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_BIGGER_U);
                                    return type_ubyte;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte(byteWriter, BC_SWAP);
                                    ByteWriter_writeByte (byteWriter, BC_SMALLER_IU);
                                    return type_ubyte;
                                    break;
                                case type_float:
                                case type_double:
                                    // Float
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte(byteWriter, BC_SWAP);
                                    ByteWriter_writeByte (byteWriter, BC_SMALLER_FU);
                                    return type_ubyte;
                                    break;
                            }
                            break;
                        case type_byte:
                        case type_short:
                        case type_int:
                        case type_long:
                            // Int
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_BIGGER_IU);
                                    return type_ubyte;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_SWAP);
                                    ByteWriter_writeByte (byteWriter, BC_SMALLER_I);
                                    return type_ubyte;
                                    break;
                                case type_float:
                                case type_double:
                                    // Float
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_SWAP);
                                    ByteWriter_writeByte (byteWriter, BC_SMALLER_FI);
                                    return type_ubyte;
                                    break;
                            }
                            break;
                        case type_float:
                        case type_double:
                            // Float
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_BIGGER_FU);
                                    return type_ubyte;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_BIGGER_FI);
                                    return type_ubyte;
                                    break;
                                case type_float:
                                case type_double:
                                    // Float
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_BIGGER_F);
                                    return type_ubyte;
                                    break;
                            }
                            break;
                        case type_text:
                            puts ("Cannot work with text yet!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                        case type_Collection:
                            puts ("Cannot work with collections yet!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                        default:
                            puts ("Unusable Datatype!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                    }
                }
                    break;


                case TT_LessEquals:
                {
                    SyntaxNode nodeleft = binOpNode->left;
                    SyntaxNode noderight = binOpNode->right;
                    Token lessToken = binOpNode->operator;
                    lessToken.type = TT_Less;
                    Token subToken = binOpNode->operator;
                    subToken.type = TT_Minus;
                    Token oneToken = binOpNode->operator;
                    oneToken.type = TT_Uint;
                    oneToken.value.u = 1;
                    SyntaxNode nodeOne = newValueNode(oneToken);
                    SyntaxNode nodeSub = newBinOpNode(noderight, subToken, nodeOne);
                    SyntaxNode nodeLess = newBinOpNode(nodeleft, lessToken, nodeSub);
                    return CodeGenerator_generateExpression(codeGenerator, nodeLess, scope, byteWriter);
                }
                    break;

                case TT_GreaterEquals:
                
                { 
                    SyntaxNode nodeleft = binOpNode->left;
                    SyntaxNode noderight = binOpNode->right;
                    Token lessToken = binOpNode->operator;
                    lessToken.type = TT_Greater;
                    Token subToken = binOpNode->operator;
                    subToken.type = TT_Minus;
                    Token oneToken = binOpNode->operator;
                    oneToken.type = TT_Uint;
                    oneToken.value.u = 1;
                    SyntaxNode nodeOne = newValueNode(oneToken);
                    SyntaxNode nodeSub = newBinOpNode(noderight, subToken, nodeOne);
                    SyntaxNode nodeLess = newBinOpNode(nodeleft, lessToken, nodeSub);
                    return CodeGenerator_generateExpression(codeGenerator, nodeLess, scope, byteWriter);
                }
                    break;

                case TT_NotEquals:
                {
                    SyntaxNode nodeleft = binOpNode->left;
                    SyntaxNode noderight = binOpNode->right;
                    Token eqToken = binOpNode->operator;
                    eqToken.type = TT_EqualsEquals;
                    Token notToken = binOpNode->operator;
                    notToken.type = TT_Exclamationmark;
                    SyntaxNode nodeEquals = newBinOpNode(nodeleft, eqToken, noderight);
                    SyntaxNode nodeNot = newUnaryOpNode(notToken, nodeEquals);
                    return CodeGenerator_generateExpression(codeGenerator, nodeNot, scope, byteWriter);
                }
                    break;

                case TT_And:
                {
                    char* left_ops = NULL;
                    unsigned int left_ops_length = 0;
                    char* right_ops = NULL;
                    unsigned int right_ops_length = 0;
                    ByteWriter tmpWriter = ByteWriter_init (&right_ops, &right_ops_length);

                    // Actually it parses it in the wrong order so here it gets fixed
                    unsigned char type_right = CodeGenerator_generateExpression (codeGenerator, binOpNode->right, scope, &tmpWriter);

                    tmpWriter = ByteWriter_init (&left_ops, &left_ops_length);

                    unsigned char type_left = CodeGenerator_generateExpression (codeGenerator, binOpNode->left, scope, &tmpWriter);

                    // Int + Int = Int
                    // UInt + UInt = UInt
                    // Float + Float = Float
                    // Int + Float = Float
                    // UInt + Float = Float
                    // Int + UInt = Int
                    switch (type_left) {
                        case type_ubyte:
                        case type_ushort:
                        case type_uint:
                        case type_ulong:
                            // UInt
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_AND);
                                    return type_ulong;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_U2I);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_AND);
                                    return type_long;
                                    break;
                            }
                            break;
                        case type_byte:
                        case type_short:
                        case type_int:
                        case type_long:
                            // Int
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_U2I);
                                    ByteWriter_writeByte (byteWriter, BC_AND);
                                    return type_long;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_AND);
                                    return type_long;
                                    break;
                            }
                            break;
                        case type_text:
                            puts ("Cannot work with text yet!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                        case type_Collection:
                            puts ("Cannot work with collections yet!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                        default:
                            puts ("Unusable Datatype!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                    }
                }
                    break;

                case TT_Or:
                {
                    char* left_ops = NULL;
                    unsigned int left_ops_length = 0;
                    char* right_ops = NULL;
                    unsigned int right_ops_length = 0;
                    ByteWriter tmpWriter = ByteWriter_init (&right_ops, &right_ops_length);

                    // Actually it parses it in the wrong order so here it gets fixed
                    unsigned char type_right = CodeGenerator_generateExpression (codeGenerator, binOpNode->right, scope, &tmpWriter);

                    tmpWriter = ByteWriter_init (&left_ops, &left_ops_length);

                    unsigned char type_left = CodeGenerator_generateExpression (codeGenerator, binOpNode->left, scope, &tmpWriter);

                    // Int + Int = Int
                    // UInt + UInt = UInt
                    // Float + Float = Float
                    // Int + Float = Float
                    // UInt + Float = Float
                    // Int + UInt = Int
                    switch (type_left) {
                        case type_ubyte:
                        case type_ushort:
                        case type_uint:
                        case type_ulong:
                            // UInt
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_OR);
                                    return type_ulong;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_U2I);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_OR);
                                    return type_long;
                                    break;
                            }
                            break;
                        case type_byte:
                        case type_short:
                        case type_int:
                        case type_long:
                            // Int
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_U2I);
                                    ByteWriter_writeByte (byteWriter, BC_OR);
                                    return type_long;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_OR);
                                    return type_long;
                                    break;
                            }
                            break;
                        case type_text:
                            puts ("Cannot work with text yet!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                        case type_Collection:
                            puts ("Cannot work with collections yet!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                        default:
                            puts ("Unusable Datatype!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                    }
                }
                    break;

                case TT_AndAnd:
                {
                    char* left_ops = NULL;
                    unsigned int left_ops_length = 0;
                    char* right_ops = NULL;
                    unsigned int right_ops_length = 0;
                    ByteWriter tmpWriter = ByteWriter_init (&right_ops, &right_ops_length);

                    // Actually it parses it in the wrong order so here it gets fixed
                    unsigned char type_right = CodeGenerator_generateExpression (codeGenerator, binOpNode->right, scope, &tmpWriter);

                    tmpWriter = ByteWriter_init (&left_ops, &left_ops_length);

                    unsigned char type_left = CodeGenerator_generateExpression (codeGenerator, binOpNode->left, scope, &tmpWriter);

                    // Int + Int = Int
                    // UInt + UInt = UInt
                    // Float + Float = Float
                    // Int + Float = Float
                    // UInt + Float = Float
                    // Int + UInt = Int
                    switch (type_left) {
                        case type_ubyte:
                        case type_ushort:
                        case type_uint:
                        case type_ulong:
                            // UInt
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_AND);
                                    return type_ubyte;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_I2U);
                                    ByteWriter_writeByte (byteWriter, BC_AND);
                                    return type_ubyte;
                                    break;
                            }
                            break;
                        case type_byte:
                        case type_short:
                        case type_int:
                        case type_long:
                            // Int
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_I2U);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_AND);
                                    return type_ubyte;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_I2U);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_I2U);
                                    ByteWriter_writeByte (byteWriter, BC_AND);
                                    return type_ubyte;
                                    break;
                            }
                            break;
                        case type_text:
                            puts ("Cannot work with text yet!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                        case type_Collection:
                            puts ("Cannot work with collections yet!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                        default:
                            puts ("Unusable Datatype!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                    }
                }
                    break;

                case TT_OrOr:
                {
                    char* left_ops = NULL;
                    unsigned int left_ops_length = 0;
                    char* right_ops = NULL;
                    unsigned int right_ops_length = 0;
                    ByteWriter tmpWriter = ByteWriter_init (&right_ops, &right_ops_length);

                    // Actually it parses it in the wrong order so here it gets fixed
                    unsigned char type_right = CodeGenerator_generateExpression (codeGenerator, binOpNode->right, scope, &tmpWriter);

                    tmpWriter = ByteWriter_init (&left_ops, &left_ops_length);

                    unsigned char type_left = CodeGenerator_generateExpression (codeGenerator, binOpNode->left, scope, &tmpWriter);

                    // Int + Int = Int
                    // UInt + UInt = UInt
                    // Float + Float = Float
                    // Int + Float = Float
                    // UInt + Float = Float
                    // Int + UInt = Int
                    switch (type_left) {
                        case type_ubyte:
                        case type_ushort:
                        case type_uint:
                        case type_ulong:
                            // UInt
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_OR);
                                    return type_ubyte;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_I2U);
                                    ByteWriter_writeByte (byteWriter, BC_OR);
                                    return type_ubyte;
                                    break;
                            }
                            break;
                        case type_byte:
                        case type_short:
                        case type_int:
                        case type_long:
                            // Int
                            switch (type_right) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    // UInt
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_I2U);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_OR);
                                    return type_ubyte;
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    // Int
                                    ByteWriter_addOps (byteWriter, left_ops, left_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_I2U);
                                    ByteWriter_addOps (byteWriter, right_ops, right_ops_length);
                                    ByteWriter_writeByte (byteWriter, BC_I2U);
                                    ByteWriter_writeByte (byteWriter, BC_OR);
                                    return type_ubyte;
                                    break;
                            }
                            break;
                        case type_text:
                            puts ("Cannot work with text yet!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                        case type_Collection:
                            puts ("Cannot work with collections yet!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                        default:
                            puts ("Unusable Datatype!");
                            markTokenError(binOpNode->operator);
                            exit (1);
                            break;
                    }
                }
                    break;

                case TTK_Is:
                {
                    
                    if (binOpNode->left.type != ID_ValueNode) 
                        if (binOpNode->left.valueNode->value.type != TT_Identifier){
                            puts ("Expected an identifier!");
                            markTokenError( binOpNode->left.valueNode->value);
                            exit (1);
                        }
                    Token variableName = binOpNode->left.valueNode->value;

                    if (VariableTable_findVariableByName (&codeGenerator->table, variableName).type == type_undefined) {
                        VariableTable_declareVariable (&codeGenerator->table, variableName, scope);
                    } 
                    if (VariableTable_findVariableByName (&codeGenerator->table, variableName).type != type_none) {
                        puts ("Variable has already a type!");
                        markTokenError( variableName);
                        exit (1);
                    }
                    Symbol variableDeclaration = VariableTable_findVariableByName (&codeGenerator->table, variableName);

                    if (variableDeclaration.is_argument) {
                        puts ("Variable is a function-argument!");
                        markTokenError( variableName);
                        exit (1);
                    }

                    if (binOpNode->right.type == ID_ValueNode) {
                        Token variableType = binOpNode->right.valueNode->value;
                        switch (variableType.type) {
                            case TTK_Ubyte:
                                VariableTable_defineVariable (&codeGenerator->table, variableDeclaration.value, type_ubyte);
                                return type_none;
                                break;
                            case TTK_Byte:
                                VariableTable_defineVariable (&codeGenerator->table, variableDeclaration.value, type_byte);
                                return type_none;
                                break;
                            case TTK_Ushort:
                                VariableTable_defineVariable (&codeGenerator->table, variableDeclaration.value, type_ushort);
                                return type_none;
                                break;
                            case TTK_Short:
                                VariableTable_defineVariable (&codeGenerator->table, variableDeclaration.value, type_short);
                                return type_none;
                                break;
                            case TTK_Uint:
                                VariableTable_defineVariable (&codeGenerator->table, variableDeclaration.value, type_uint);
                                return type_none;
                                break;
                            case TTK_Int:
                                VariableTable_defineVariable (&codeGenerator->table, variableDeclaration.value, type_int);
                                return type_none;
                                break;
                            case TTK_Float:
                                VariableTable_defineVariable (&codeGenerator->table, variableDeclaration.value, type_float);
                                return type_none;
                                break;
                            case TTK_Ulong:
                                VariableTable_defineVariable (&codeGenerator->table, variableDeclaration.value, type_ulong);
                                return type_none;
                                break;
                            case TTK_Long:
                                VariableTable_defineVariable (&codeGenerator->table, variableDeclaration.value, type_long);
                                return type_none;
                                break;
                            case TTK_Double:
                                VariableTable_defineVariable (&codeGenerator->table, variableDeclaration.value, type_double);
                                return type_none;
                                break;

                            case TTK_Txt:
                                VariableTable_defineVariable (&codeGenerator->table, variableDeclaration.value, type_text);
                                return type_none;
                                break;

                           /*  case TTK_Collection:
                            {

                                VariableTable_defineVariable (&codeGenerator->table, variableDeclaration.value, type_Collection);
                            }
                                return type_none;
                                break; */

                            default:
                                puts ("Expected a type!");
                                markTokenError( variableType);
                                exit (1);
                        }
                        
                    }
                    else if (binOpNode->right.type == ID_SquareCallNode) {
                        SquareCallNode squareCallNode = *binOpNode->right.squareCallNode;
                        if (squareCallNode.identifier.type == ID_ValueNode) {
                            ValueNode collectionType = *squareCallNode.identifier.valueNode;
                            /*switch (collectionType.value.type) {
                                case TTK_Collection:
                                {
                                    if (squareCallNode.numbersOfArguments == 0 || squareCallNode.arguments[0].type != ID_ValueNode) {
                                        puts ("Cannot create Collection without type!");
                                        markTokenError( variableName);
                                        exit (1);
                                    }
                                    Token storingType = squareCallNode.arguments[0].valueNode->value;
                                    VariableTable_defineVariable (&codeGenerator->table, variableDeclaration.value, type_Collection);
                                    VarDec collection = VariableTable_findVariableByName (&codeGenerator->table, variableDeclaration.value);
                                    collection.storingType = tokentypeToDatatype (storingType, codeGenerator);
                                    VariableTable_setVariableByName (&codeGenerator->table, variableDeclaration.value, collection);

                                    // Initzalisation
                                    ByteWriter_writeByte (byteWriter, BC_BUILD_EMPTYCOLLECTION);
                                    switch (scope.rgtr) {
                                        case scope_local:
                                            ByteWriter_writeByte (byteWriter, BC_STORE_STACK_COLLECTION);
                                            break;
                                        case scope_global:
                                            ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_COLLECTION);
                                            break;
                                    }
                                    ByteWriter_writeUInt (byteWriter, collection.index);
                                    return type_none;
                                }
                                    break;
                                default:
                                    puts ("Cannot create Collection!");
                                    markTokenError( variableName);
                                    exit (1);
                            }*/
                            unsigned char arrayType = typeToStackType (tokenTypeToDataType (collectionType.value, codeGenerator));


                            VariableTable_defineVariable (&codeGenerator->table, variableDeclaration.value, type_Collection);
                            Symbol collection = VariableTable_findVariableByName (&codeGenerator->table, variableDeclaration.value);
                            collection.storingType = arrayType;
                            if(collection.storingType == type_complex || collection.storingType == type_function)
                                collection.mothertype = collectionType.value;
                            else
                                collection.mothertype = (Token) {.type = type_none};
                            VariableTable_setVariableByName (&codeGenerator->table, variableDeclaration.value, collection);

                            // Initzalisation
                            ByteWriter_writeByte (byteWriter, BC_BUILD_EMPTYCOLLECTION);
                            for (unsigned int e = 0; e < squareCallNode.numbersOfArguments; e++) {
                                unsigned char etype = CodeGenerator_generateExpression (codeGenerator, squareCallNode.arguments[e], scope, byteWriter);
                                etype = typeToStackType (etype);
                                if (etype != arrayType) {
                                    puts ("All elements must be the same type of the array!");
                                    markTokenError( variableName);
                                    exit (1);
                                }
                                ByteWriter_writeByte (byteWriter, BC_ADD_ELEMENT);
                            }
                            switch (collection.scope.rgtr) {
                                case scope_local:
                                    ByteWriter_writeByte (byteWriter, BC_STORE_STACK_COLLECTION);
                                    break;
                                case scope_global:
                                    ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_COLLECTION);
                                    break;
                            }
                            ByteWriter_writeUInt (byteWriter, collection.index);
                            return type_none;
                        } else {
                            puts ("Cannot create Collection!");
                            markTokenError( variableName);
                            exit (1);
                        }
                    }
                    else if (binOpNode->right.type == ID_FunctionCallNode) {
                        FunctionCallNode functionCallNode = *binOpNode->right.functionCallNode;

                        char identifier[4096] = "";
                        strcat(identifier, functionCallNode.identifier.valueNode->value.value.word);
                        strcat(identifier, "/");

                        char *arg_writer_buffer = NULL;
                        unsigned int arg_writer_length = 0;
                        ByteWriter arg_writer = ByteWriter_init(&arg_writer_buffer, &arg_writer_length);

                        for (unsigned int i = 0; i < functionCallNode.numbersOfArguments; i++) {
                            unsigned char arg_type = CodeGenerator_generateExpression(codeGenerator, functionCallNode.arguments[i], scope, &arg_writer);
                            switch(arg_type) {
                                case type_text:
                                    strcat(identifier, "txt");
                                    break;
                                case type_complex:
                                    strcat(identifier, Complex_return.value.word);
                                    break;
                                case type_Collection:
                                    strcat(identifier, "*");
                                default:
                                    break;
                            }

                            strcat(identifier, "/");
                        }

                        char *before_id = functionCallNode.identifier.valueNode->value.value.word;
                        functionCallNode.identifier.valueNode->value.value.word = copyString(identifier);

                        Symbol fn = VariableTable_findVariableByName (&codeGenerator->table, functionCallNode.identifier.valueNode->value);

                        // printf("FunctionCall: [%s]. vs. [%s]\n", identifier, functionCallNode.identifier.valueNode->value.value.word);

                        free(functionCallNode.identifier.valueNode->value.value.word);
                        functionCallNode.identifier.valueNode->value.value.word = before_id;

                        if(strcmp(binOpNode->right.functionCallNode->identifier.valueNode->value.value.word, "$$args$$") == 0) {
                            ByteWriter_writeByte(byteWriter, BC_LOAD_ARGUMENT);
                            ByteWriter_writeUInt(byteWriter, 1);
                            VariableTable_defineVariable (&codeGenerator->table, variableDeclaration.value, type_Collection);
                            Symbol collection = VariableTable_findVariableByName (&codeGenerator->table, variableDeclaration.value);
                            collection.storingType = type_any;
                            VariableTable_setVariableByName (&codeGenerator->table, variableDeclaration.value, collection);
                            switch (collection.scope.rgtr) {
                                case scope_local:
                                    ByteWriter_writeByte (byteWriter, BC_STORE_STACK_COLLECTION);
                                    break;
                                case scope_global:
                                    ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_COLLECTION);
                                    break;
                            }
                            ByteWriter_writeUInt (byteWriter, collection.index);
                        } else if(strcmp(binOpNode->right.functionCallNode->identifier.valueNode->value.value.word, "$$argt$$") == 0) {
                            ByteWriter_writeByte(byteWriter, BC_LOAD_ARGUMENT);
                            ByteWriter_writeUInt(byteWriter, 0);
                            VariableTable_defineVariable (&codeGenerator->table, variableDeclaration.value, type_Collection);
                            Symbol collection = VariableTable_findVariableByName (&codeGenerator->table, variableDeclaration.value);
                            collection.storingType = type_ulong;
                            VariableTable_setVariableByName (&codeGenerator->table, variableDeclaration.value, collection);
                            switch (collection.scope.rgtr) {
                                case scope_local:
                                    ByteWriter_writeByte (byteWriter, BC_STORE_STACK_COLLECTION);
                                    break;
                                case scope_global:
                                    ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_COLLECTION);
                                    break;
                            }
                            ByteWriter_writeUInt (byteWriter, collection.index);
                        } else if (fn.returnType_isArray) {
                            unsigned char rtype = CodeGenerator_generateExpression (codeGenerator, binOpNode->right, scope, byteWriter);
                            unsigned char arraytype = fn.returnType;
                            VariableTable_defineVariable (&codeGenerator->table, variableDeclaration.value, type_Collection);
                            Symbol collection = VariableTable_findVariableByName (&codeGenerator->table, variableDeclaration.value);
                            collection.storingType = arraytype;
                            VariableTable_setVariableByName (&codeGenerator->table, variableDeclaration.value, collection);
                            switch (collection.scope.rgtr) {
                                case scope_local:
                                    ByteWriter_writeByte (byteWriter, BC_STORE_STACK_COLLECTION);
                                    break;
                                case scope_global:
                                    ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_COLLECTION);
                                    break;
                            }
                            ByteWriter_writeUInt (byteWriter, collection.index);
                            return type_none;
                        } else {
                            puts ("Must be a type/array or function that returns these kinds!");
                            markTokenError( variableName);
                            exit (1);
                        }
                    }
                    else {
                        puts ("Missing Type!");
                        markTokenError( variableName);
                        exit (1);
                    }
                }
                
                break;

                case TT_Colon:
                {
                    SyntaxNode nodeleft = binOpNode->left;
                    SyntaxNode noderight = binOpNode->right;

                    puts("Warning Deprecated: Colon is in this version of Gismo deprecated!");
                    markTokenError(binOpNode->operator);

                    if (nodeleft.type == ID_SquareCallNode) {
                        unsigned char type = CodeGenerator_generateExpression (codeGenerator, noderight, scope, byteWriter);
                        SquareCallNode squareCallNode = *nodeleft.squareCallNode;
                        Token name = squareCallNode.identifier.valueNode->value;
                        Symbol collection = VariableTable_findVariableByName (&codeGenerator->table, name);
                        unsigned char ctype = typeToStackType (collection.storingType);

                        if (ctype != typeToStackType (type)) {
                            puts ("No given index!");
                            markTokenError( name);
                            exit (1);
                        }
                        
                        // Loading Collection
                        if (collection.scope.rgtr == scope_local)
                            ByteWriter_writeByte (byteWriter, BC_LOAD_STACK_COLLECTION);
                        else
                            ByteWriter_writeByte (byteWriter, BC_LOAD_GLOBAL_COLLECTION);

                        ByteWriter_writeUInt (byteWriter, collection.index);
                        ByteWriter_writeByte (byteWriter, BC_SWAP);

                        if (squareCallNode.numbersOfArguments == 0) {
                            puts ("No given index!");
                            markTokenError( name);
                            exit (1);
                        }

                        unsigned char index_type = CodeGenerator_generateExpression (codeGenerator, squareCallNode.arguments[0], scope, byteWriter);
                        if(typeToStackType(type) == type_long) {
                            ByteWriter_writeByte(byteWriter, BC_I2U);
                        } else if (typeToStackType(type) == type_double) {
                            ByteWriter_writeByte(byteWriter, BC_F2U);
                        } else if (typeToStackType(type) != type_ulong) {
                            puts ("Accessing an array requires a number!");
                            markTokenError( squareCallNode.identifier.valueNode->value);
                            exit (1);
                        }

                        ByteWriter_writeByte (byteWriter, BC_STORE_ELEMENT);

                        // Cleaning up by storing the collection back
                        if (collection.scope.rgtr == scope_local)
                            ByteWriter_writeByte (byteWriter, BC_STORE_STACK_COLLECTION);
                        else
                            ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_COLLECTION);

                        ByteWriter_writeUInt (byteWriter, collection.index);
                        return type_none;
                    }

                    if (nodeleft.type != ID_ValueNode) 
                        if (nodeleft.valueNode->value.type != TT_Identifier) {
                            puts ("Only except an identifier; no 'is' statement with an colon operator!");
                            markTokenError( binOpNode->operator);
                            exit (1);
                        }
                    unsigned char type = CodeGenerator_generateExpression (codeGenerator, noderight, scope, byteWriter);
                    Symbol vardec = VariableTable_findVariableByName (&codeGenerator->table, nodeleft.valueNode->value);


                    unsigned int index = 0;
                    if (vardec.type == type_undefined) {
                        vardec = VariableTable_declareVariable (&codeGenerator->table, nodeleft.valueNode->value, scope);
                        index = VariableTable_defineVariable (&codeGenerator->table, nodeleft.valueNode->value, type_text);
                    }
                    else {
                        index = vardec.index;
                    }
                    if (type != type_text) {
                        puts ("Only except an text value!");
                        markTokenError( binOpNode->operator);
                        exit (1);
                    }
                    switch (vardec.scope.rgtr) {
                        case scope_global:
                            ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_TEXT);
                            break;
                        case scope_local:
                            ByteWriter_writeByte (byteWriter, BC_STORE_STACK_TEXT);
                            break;
                        
                        default:
                            puts ("Unsupported scope!");
                            markTokenError( binOpNode->operator);
                            exit (1);
                    }
                    ByteWriter_writeUInt (byteWriter, index);
                    return type_none;
                }
                    break;

                case TT_DefineOnce:
                {
                    // We need the left node in order to know were to store
                    SyntaxNode nodeleft = binOpNode->left;

                    // Now we generate the Expression that we're need and emit it's type
                    // Operation have already been created by now
                    unsigned char type = CodeGenerator_generateExpression (codeGenerator, binOpNode->right, scope, byteWriter);


                    // Lets check if the left operation is an <name> is <type> expression
                    // if its such expression, we'll evaluate and create it, variable by calling generateExpression
                    if (nodeleft.type == ID_BinOpNode) {
                        puts (":= is used for defining immutable Variables, there is no 'is' operator, etc needed!");
                        markTokenError( nodeleft.binOpNode->operator);
                        exit (1);
                    }

                    // We look for an ValueNode, because then it's an variable identifier and we store something inside a variable
                    if (nodeleft.type == ID_ValueNode) {

                        // We get the valueNode in order to access it's Token, which have got the variables name
                        ValueNode valueNode = *nodeleft.valueNode;

                        // Make sure that it's really an identifier
                        if (valueNode.value.type == TT_Identifier) {

                            // Now we need to access the variable to store its new value in it
                            Symbol variable = VariableTable_findVariableByName (&codeGenerator->table, valueNode.value);

                            // In the case that this variable is undefined, we'll just create this variable for this purpose
                            if (variable.type == type_undefined) {

                                // now we're continue to work with our new created variable, because the other one doesn't exist!
                                Symbol newVariable = VariableTable_declareVariable (&codeGenerator->table, valueNode.value, scope);
                                
                                // depending on its type, we must choose how to store, which command do we need?
                                switch (type) {
                                    case type_ubyte:
                                    {
                                        unsigned int index = VariableTable_defineVariable (&codeGenerator->table, newVariable.value, type_ubyte);
                                        switch (newVariable.scope.rgtr) {
                                            case scope_global:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_NUM8);
                                                break;
                                            case scope_local:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_STACK_NUM8);
                                                break;
                                            default:
                                                puts ("Inmutable Variable!");
                                                markTokenError( newVariable.value);
                                                exit (1);
                                        }
                                        ByteWriter_writeUInt (byteWriter, index);
                                        return type_none;
                                    }
                                        break;
                                    case type_ushort:
                                    {
                                        unsigned int index = VariableTable_defineVariable (&codeGenerator->table, newVariable.value, type_ushort);
                                        switch (newVariable.scope.rgtr) {
                                            case scope_global:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_NUM16);
                                                break;
                                            case scope_local:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_STACK_NUM16);
                                                break;
                                            default:
                                                puts ("Inmutable Variable!");
                                                markTokenError( newVariable.value);
                                                exit (1);
                                        }
                                        ByteWriter_writeUInt (byteWriter, index);
                                        return type_none;
                                    }
                                        break;
                                    case type_uint:
                                    {
                                        unsigned int index = VariableTable_defineVariable (&codeGenerator->table, newVariable.value, type_uint);
                                        switch (newVariable.scope.rgtr) {
                                            case scope_global:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_NUM32);
                                                break;
                                            case scope_local:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_STACK_NUM32);
                                                break;
                                            default:
                                                puts ("Inmutable Variable!");
                                                markTokenError( newVariable.value);
                                                exit (1);
                                        }
                                        ByteWriter_writeUInt (byteWriter, index);
                                        return type_none;
                                    }
                                        break;
                                    case type_ulong:
                                        // unsigned integer
                                    {
                                        unsigned int index = VariableTable_defineVariable (&codeGenerator->table, newVariable.value, type_ulong);
                                        switch (newVariable.scope.rgtr) {
                                            case scope_global:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_NUM64);
                                                break;
                                            case scope_local:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_STACK_NUM64);
                                                break;
                                            default:
                                                puts ("Inmutable Variable!");
                                                markTokenError( newVariable.value);
                                                exit (1);
                                        }
                                        ByteWriter_writeUInt (byteWriter, index);
                                        return type_none;
                                    }
                                        break;
                                    case type_byte:
                                    {
                                        unsigned int index = VariableTable_defineVariable (&codeGenerator->table, newVariable.value, type_byte);
                                        switch (newVariable.scope.rgtr) {
                                            case scope_global:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_NUM8);
                                                break;
                                            case scope_local:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_STACK_NUM8);
                                                break;
                                            default:
                                                puts ("Inmutable Variable!");
                                                markTokenError( newVariable.value);
                                                exit (1);
                                        }
                                        ByteWriter_writeUInt (byteWriter, index);
                                        return type_none;
                                    }
                                        break;
                                    case type_short:
                                    {
                                        unsigned int index = VariableTable_defineVariable (&codeGenerator->table, newVariable.value, type_short);
                                        switch (newVariable.scope.rgtr) {
                                            case scope_global:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_NUM16);
                                                break;
                                            case scope_local:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_STACK_NUM16);
                                                break;
                                            default:
                                                puts ("Inmutable Variable!");
                                                markTokenError( newVariable.value);
                                                exit (1);
                                        }
                                        ByteWriter_writeUInt (byteWriter, index);
                                        return type_none;
                                    }
                                        break;
                                    case type_int:
                                    {
                                        unsigned int index = VariableTable_defineVariable (&codeGenerator->table, newVariable.value, type_int);
                                        switch (newVariable.scope.rgtr) {
                                            case scope_global:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_NUM32);
                                                break;
                                            case scope_local:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_STACK_NUM32);
                                                break;
                                            default:
                                                puts ("Inmutable Variable!");
                                                markTokenError( newVariable.value);
                                                exit (1);
                                        }
                                        ByteWriter_writeUInt (byteWriter, index);
                                        return type_none;
                                    }
                                        break;
                                    case type_long:
                                        // integer
                                    {
                                        unsigned int index = VariableTable_defineVariable (&codeGenerator->table, newVariable.value, type_long);
                                        switch (newVariable.scope.rgtr) {
                                            case scope_global:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_NUM64);
                                                break;
                                            case scope_local:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_STACK_NUM64);
                                                break;
                                            default:
                                                puts ("Inmutable Variable!");
                                                markTokenError( newVariable.value);
                                                exit (1);
                                        }
                                        ByteWriter_writeUInt (byteWriter, index);
                                        return type_none;
                                    }
                                        break;
                                    case type_float:
                                    {
                                        unsigned int index = VariableTable_defineVariable (&codeGenerator->table, newVariable.value, type_float);
                                        switch (newVariable.scope.rgtr) {
                                            case scope_global:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_NUM32);
                                                break;
                                            case scope_local:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_STACK_NUM32);
                                                break;
                                            default:
                                                puts ("Inmutable Variable!");
                                                markTokenError( newVariable.value);
                                                exit (1);
                                        }
                                        ByteWriter_writeUInt (byteWriter, index);
                                        return type_none;
                                    }
                                        break;
                                    case type_double:
                                        // float
                                    {
                                        unsigned int index = VariableTable_defineVariable (&codeGenerator->table, newVariable.value, type_double);
                                        switch (newVariable.scope.rgtr) {
                                            case scope_global:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_NUM64);
                                                break;
                                            case scope_local:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_STACK_NUM64);
                                                break;
                                            default:
                                                puts ("Inmutable Variable!");
                                                markTokenError( newVariable.value);
                                                exit (1);
                                        }
                                        ByteWriter_writeUInt (byteWriter, index);
                                        return type_none;
                                    }
                                        break;

                                    case type_text:
                                    {
                                        unsigned int index = VariableTable_defineVariable (&codeGenerator->table, newVariable.value, type_text);
                                        switch (newVariable.scope.rgtr) {
                                            case scope_global:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_TEXT);
                                                break;
                                            case scope_local:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_STACK_TEXT);
                                                break;
                                            
                                            default:
                                                puts ("Unsupported scope!");
                                                markTokenError( binOpNode->operator);
                                                exit (1);
                                        }
                                        ByteWriter_writeUInt (byteWriter, index);
                                        return type_none;
                                    }
                                    break;

                                    case type_complex:
                                    {
                                        unsigned int index = VariableTable_defineVariable (&codeGenerator->table, newVariable.value, type_complex);
                                        switch (newVariable.scope.rgtr) {
                                            case scope_global:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_TEXT);
                                                break;
                                            case scope_local:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_STACK_TEXT);
                                                break;
                                            
                                            default:
                                                puts ("Unsupported scope!");
                                                markTokenError( binOpNode->operator);
                                                exit (1);
                                        }
                                        ByteWriter_writeUInt (byteWriter, index);
                                        
                                        newVariable = VariableTable_findVariableByName(&codeGenerator->table, newVariable.value);
                                        newVariable.mothertype = Complex_return;

                                        VariableTable_setVariableByName(&codeGenerator->table, newVariable.value, newVariable);

                                        return type_none;
                                    }
                                    break;

                                    case type_function:
                                    {
                                        unsigned int index = VariableTable_defineVariable(&codeGenerator->table, newVariable.value, type_function);

                                        switch(newVariable.scope.rgtr) {
                                            case scope_global:
                                                ByteWriter_writeByte(byteWriter, BC_STORE_GLOBAL_FUNC);
                                                break;
                                            case scope_local:
                                                ByteWriter_writeByte(byteWriter, BC_STORE_STACK_FUNC);
                                                break;
                                            default:
                                                puts ("Unsupported scope!");
                                                markTokenError( binOpNode->operator);
                                                exit (1);
                                        }

                                        ByteWriter_writeUInt (byteWriter, index);

                                        newVariable = VariableTable_findVariableByName(&codeGenerator->table, newVariable.value);
                                        newVariable.mothertype = Complex_return;

                                        Symbol motherFunction = VariableTable_findVariableByName(&codeGenerator->table, newVariable.mothertype);

                                        syncFunctionSymbol(&newVariable, motherFunction);

                                        VariableTable_setVariableByName(&codeGenerator->table, newVariable.value, newVariable);
                                        return type_none;
                                    }
                                    break;
                                    
                                    default:
                                        puts ("Unsupported Datatype!");
                                        markTokenError( binOpNode->operator);
                                        exit (1);
                                }
                            }
                            else {
                                // We only want to define a variable once, therfore if it's have been already defined,
                                // we would we want to define it again???

                                puts ("Variable has already been defined!");
                                markTokenError( valueNode.value);
                                exit (1);

                                return type_none;
                            }
                        }
                        else {
                            // But if the variable isn't even a identifier, we cannot store it and we have to stop the compilation
                            puts ("Expected an Identifier!");
                            markTokenError( valueNode.value);
                            exit (1);
                        }
                    } else {
                        // But if the variable isn't even a identifier, we cannot store it and we have to stop the compilation
                        puts ("Cannot define an immutable variable inside an collection or etc.");
                        markTokenError( binOpNode->operator);
                        exit (1);
                    }
                }
                    break;

                case TT_PlusEqual:
                {
                    SyntaxNode nodeleft = binOpNode->left;
                    SyntaxNode noderight = binOpNode->right;
                    Token plusToken = binOpNode->operator;
                    plusToken.type = TT_Plus;
                    Token equalToken =  binOpNode->operator;
                    equalToken.type = TT_Equalsign;
                    SyntaxNode nodeAdd = newBinOpNode(nodeleft, plusToken, noderight);
                    SyntaxNode assignmentNode = newBinOpNode(nodeleft, equalToken, nodeAdd);
                    return CodeGenerator_generateExpression(codeGenerator, assignmentNode, scope, byteWriter);
                }
                    break;

                case TT_SubEqual:
                {
                    SyntaxNode nodeleft = binOpNode->left;
                    SyntaxNode noderight = binOpNode->right;
                    Token minusToken = binOpNode->operator;
                    minusToken.type = TT_Minus;
                    Token equalToken =  binOpNode->operator;
                    equalToken.type = TT_Equalsign;
                    SyntaxNode nodeAdd = newBinOpNode(nodeleft, minusToken, noderight);
                    SyntaxNode assignmentNode = newBinOpNode(nodeleft, equalToken, nodeAdd);
                    return CodeGenerator_generateExpression(codeGenerator, assignmentNode, scope, byteWriter);
                }
                    break;

                case TT_MulEqual:
                {
                    SyntaxNode nodeleft = binOpNode->left;
                    SyntaxNode noderight = binOpNode->right;
                    Token mulToken = binOpNode->operator;
                    mulToken.type = TT_Multiply;
                    Token equalToken =  binOpNode->operator;
                    equalToken.type = TT_Equalsign;
                    SyntaxNode nodeAdd = newBinOpNode(nodeleft, mulToken, noderight);
                    SyntaxNode assignmentNode = newBinOpNode(nodeleft, equalToken, nodeAdd);
                    return CodeGenerator_generateExpression(codeGenerator, assignmentNode, scope, byteWriter);
                }
                    break;

                case TT_DivEqual:
                {
                    SyntaxNode nodeleft = binOpNode->left;
                    SyntaxNode noderight = binOpNode->right;
                    Token divToken = binOpNode->operator;
                    divToken.type = TT_Divide;
                    Token equalToken =  binOpNode->operator;
                    equalToken.type = TT_Equalsign;
                    SyntaxNode nodeAdd = newBinOpNode(nodeleft, divToken, noderight);
                    SyntaxNode assignmentNode = newBinOpNode(nodeleft, equalToken, nodeAdd);
                    return CodeGenerator_generateExpression(codeGenerator, assignmentNode, scope, byteWriter);
                }
                    break;

                case TT_ModEqual:
                {
                    SyntaxNode nodeleft = binOpNode->left;
                    SyntaxNode noderight = binOpNode->right;
                    Token modToken = binOpNode->operator;
                    modToken.type = TT_Modulo;
                    Token equalToken =  binOpNode->operator;
                    equalToken.type = TT_Equalsign;
                    SyntaxNode nodeAdd = newBinOpNode(nodeleft, modToken, noderight);
                    SyntaxNode assignmentNode = newBinOpNode(nodeleft, equalToken, nodeAdd);
                    return CodeGenerator_generateExpression(codeGenerator, assignmentNode, scope, byteWriter);
                }
                    break;

                case TT_HashEqual:
                {
                    SyntaxNode nodeleft = binOpNode->left;
                    SyntaxNode noderight = binOpNode->right;
                    Token hashToken = binOpNode->operator;
                    hashToken.type = TT_HashSymbol;
                    Token equalToken =  binOpNode->operator;
                    equalToken.type = TT_Equalsign;
                    SyntaxNode nodeAdd = newUnaryOpNode(hashToken, noderight);
                    SyntaxNode assignmentNode = newBinOpNode(nodeleft, equalToken, nodeAdd);
                    return CodeGenerator_generateExpression(codeGenerator, assignmentNode, scope, byteWriter);
                }
                    break;
                
                case TT_Equalsign:
                {
                    SyntaxNode nodeleft = binOpNode->left;

                    if (nodeleft.type == ID_BinOpNode) {
                        BinOpNode binOpNode_def = *nodeleft.binOpNode;
                        if (binOpNode_def.operator.type == TTK_Is) {
                            CodeGenerator_generateExpression (codeGenerator, nodeleft, scope, byteWriter);
                            nodeleft = nodeleft.binOpNode->left;
                        } else if(binOpNode_def.operator.type == TT_Dot) {
                            // Converting to simple functioncall
                            SyntaxNode left = nodeleft.binOpNode->left;
                            SyntaxNode right = nodeleft.binOpNode->right;

                            if(left.type != ID_ValueNode || right.type != ID_ValueNode) {
                                puts ("Expected right and left an identifier!");
                                markTokenError( binOpNode_def.operator);
                                exit (1);
                            }

                            Token name = left.valueNode->value;
                            Token memberName = right.valueNode->value;

                            Symbol leftComplex = VariableTable_findVariableByName (&codeGenerator->table, name);
                            
                            // Now this only works with complexes
                            if(leftComplex.type == type_complex) {

                                // Now we simply need to find out if that variable is an field within the mothertype
                                // and get its type

                                Symbol mothertype = VariableTable_findVariableByName(&codeGenerator->table, leftComplex.mothertype);
                                
                                for(unsigned int member = 0u; member < mothertype.argumentsCount; member++) {
                                    if(strcmp(mothertype.arguments[member].name.value.word, memberName.value.word) == 0) {
                                        SyntaxNode fnCallNode = newFunctionCallNode(newValueNode((Token) {
                                            .type = TT_Identifier,
                                            .value.word = "$_update_$"
                                        }));

                                        FunctionCallNode_add(fnCallNode, newValueNode((Token) {
                                            .type = TT_Identifier,
                                            .value.word = name.value.word
                                        }));

                                        FunctionCallNode_add(fnCallNode, newValueNode((Token) {
                                            .type = TT_String,
                                            .value.word = memberName.value.word
                                        }));

                                        FunctionCallNode_add(fnCallNode, binOpNode->right);

                                        return CodeGenerator_generateExpression(codeGenerator, fnCallNode, scope, byteWriter);
                                    }
                                }
                                puts ("Field in table object doesn't exist: ");
                                puts (memberName.value.word);
                                markTokenError( binOpNode->operator);
                                exit (1);
                            } 
                        } else {
                            puts ("Expected an Operator like 'is' or '.'!");
                            markTokenError( binOpNode_def.operator);
                            exit (1);
                        }
                    }

                    unsigned char type = CodeGenerator_generateExpression (codeGenerator, binOpNode->right, scope, byteWriter);

                    if (nodeleft.type == ID_ValueNode) {
                        ValueNode valueNode = *nodeleft.valueNode;
                        if (valueNode.value.type == TT_Identifier) {
                            Symbol variable = VariableTable_findVariableByName (&codeGenerator->table, valueNode.value);

                            if(type == type_function) {
                                // Checking now that the functions will be with equal type
                                if(Complex_return.type == TT_Identifier) {

                                    Symbol motherFunction = VariableTable_findVariableByName(&codeGenerator->table, Complex_return);
                                    if(motherFunction.type != type_function) {
                                        puts ("Not same type of Function1!");
                                        markTokenError( binOpNode->operator);
                                        exit (1);
                                    }

                                    if((motherFunction.argumentsCount != variable.argumentsCount) ? (motherFunction.free_arguments && variable.free_arguments) : 0 ||
                                        variable.returnType != motherFunction.returnType ||
                                        variable.returnType_isArray != motherFunction.returnType_isArray
                                    ) {
                                        puts ("Not same type of Function2!");
                                        markTokenError( binOpNode->operator);
                                        exit (1);
                                    }

                                    for(unsigned int args_counter = 0; args_counter < variable.argumentsCount; args_counter++) {
                                        if((variable.arguments[args_counter].type.type != motherFunction.arguments[args_counter].type.type) || 
                                           (variable.arguments[args_counter].is_array != motherFunction.arguments[args_counter].is_array)) {
                                            puts ("Not same type of Function3!");
                                            markTokenError( binOpNode->operator);
                                            exit (1);
                                        }

                                        if(variable.arguments[args_counter].type.type == TT_Identifier) {
                                            if(strcmp(variable.arguments[args_counter].type.value.word, motherFunction.arguments[args_counter].type.value.word) != 0) {
                                                puts ("Not same type of Function4!");
                                                markTokenError( binOpNode->operator);
                                                exit (1);
                                            }
                                        }
                                    }
                                } else {
                                    puts ("Cannot work with constant functions5!");
                                    markTokenError( binOpNode->operator);
                                    exit (1);
                                }
                            }

                            if (variable.type == type_undefined) {
                                Symbol newVariable = VariableTable_declareVariable (&codeGenerator->table, valueNode.value, scope);
                                switch (type) {
                                    case type_ubyte:
                                    case type_ushort:
                                    case type_uint:
                                    case type_ulong:
                                        // unsigned integer
                                    {
                                        unsigned int index = VariableTable_defineVariable (&codeGenerator->table, newVariable.value, type_ulong);
                                        switch (newVariable.scope.rgtr) {
                                            case scope_global:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_NUM64);
                                                break;
                                            case scope_local:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_STACK_NUM64);
                                                break;
                                            default:
                                                puts ("Inmutable Variable!");
                                                markTokenError( newVariable.value);
                                                exit (1);
                                        }
                                        ByteWriter_writeUInt (byteWriter, index);
                                        return type_none;
                                    }
                                        break;
                                    case type_byte:
                                    case type_short:
                                    case type_int:
                                    case type_long:
                                        // integer
                                    {
                                        unsigned int index = VariableTable_defineVariable (&codeGenerator->table, newVariable.value, type_long);
                                        switch (newVariable.scope.rgtr) {
                                            case scope_global:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_NUM64);
                                                break;
                                            case scope_local:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_STACK_NUM64);
                                                break;
                                            default:
                                                puts ("Inmutable Variable!");
                                                markTokenError( newVariable.value);
                                                exit (1);
                                        }
                                        ByteWriter_writeUInt (byteWriter, index);
                                        return type_none;
                                    }
                                        break;
                                    case type_float:
                                    case type_double:
                                        // float
                                    {
                                        unsigned int index = VariableTable_defineVariable (&codeGenerator->table, newVariable.value, type_double);
                                        switch (newVariable.scope.rgtr) {
                                            case scope_global:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_NUM64);
                                                break;
                                            case scope_local:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_STACK_NUM64);
                                                break;
                                            default:
                                                puts ("Inmutable Variable!");
                                                markTokenError( newVariable.value);
                                                exit (1);
                                        }
                                        ByteWriter_writeUInt (byteWriter, index);
                                        return type_none;
                                    }
                                        break;
                                    case type_complex:
                                    case type_function:
                                        puts ("table objects or functions must be defined with the := operator!");
                                        markTokenError( binOpNode->operator);
                                        exit (1);
                                        break;

                                    case type_text:
                                    {
                                        unsigned int index = VariableTable_defineVariable (&codeGenerator->table, newVariable.value, type_text);
                                        switch (newVariable.scope.rgtr) {
                                            case scope_global:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_TEXT);
                                                break;
                                            case scope_local:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_STACK_TEXT);
                                                break;
                                            default:
                                                puts ("Inmutable Variable!");
                                                markTokenError( newVariable.value);
                                                exit (1);
                                        }
                                        ByteWriter_writeUInt (byteWriter, index);
                                        return type_none;
                                    }
                                        break;
                                }
                            }
                            else {
                                switch (variable.type) {
                                    case type_ubyte:
                                    case type_ushort:
                                    case type_uint:
                                    case type_ulong:
                                        // unsigned integer
                                        switch (type) {
                                            case type_byte:
                                            case type_short:
                                            case type_int:
                                            case type_long:
                                                ByteWriter_writeByte (byteWriter, BC_I2U);
                                                type = type_ulong;
                                                break;
                                            case type_float:
                                            case type_double:
                                                ByteWriter_writeByte (byteWriter, BC_F2U);
                                                type = type_ulong;
                                                break;
                                            case type_text:
                                                ByteWriter_writeByte (byteWriter, BC_STR_TO_U);
                                                type = type_ulong;
                                                break;
                                        }
                                        break;
                                    case type_byte:
                                    case type_short:
                                    case type_int:
                                    case type_long:
                                        // integer
                                        switch (type) {
                                            case type_ubyte:
                                            case type_ushort:
                                            case type_uint:
                                            case type_ulong:
                                                ByteWriter_writeByte (byteWriter, BC_U2I);
                                                type = type_long;
                                                break;
                                            case type_float:
                                            case type_double:
                                                ByteWriter_writeByte (byteWriter, BC_F2I);
                                                type = type_long;
                                                break;
                                            case type_text:
                                                ByteWriter_writeByte (byteWriter, BC_STR_TO_I);
                                                type = type_long;
                                                break;
                                        }
                                        break;
                                    case type_float:
                                    case type_double:
                                        switch (type) {
                                            case type_ubyte:
                                            case type_ushort:
                                            case type_uint:
                                            case type_ulong:
                                                ByteWriter_writeByte (byteWriter, BC_U2F);
                                                type = type_double;
                                                break;
                                            case type_byte:
                                            case type_short:
                                            case type_int:
                                            case type_long:
                                                ByteWriter_writeByte (byteWriter, BC_I2F);
                                                type = type_double;
                                                break;
                                            case type_text:
                                                ByteWriter_writeByte (byteWriter, BC_STR_TO_F);
                                                type = type_double;
                                                break;
                                        }
                                        break;
                                    case type_complex:
                                        if(type == type_complex)
                                            if(strcmp(Complex_return.value.word, variable.mothertype.value.word) != 0) {
                                                printf("Cannot convert from table object %s to %s!\n", Complex_return.value.word, variable.mothertype.value.word);
                                                markTokenError( binOpNode->operator);
                                                exit (1);
                                            }
                                    case type_text:
                                        switch (type) {
                                            case type_ubyte:
                                            case type_ushort:
                                            case type_uint:
                                            case type_ulong:
                                                ByteWriter_writeByte (byteWriter, BC_TO_STRING_U);
                                                type = type_text;
                                                break;
                                            case type_byte:
                                            case type_short:
                                            case type_int:
                                            case type_long:
                                                ByteWriter_writeByte (byteWriter, BC_TO_STRING_I);
                                                type = type_text;
                                                break;
                                            case type_float:
                                            case type_double:
                                                ByteWriter_writeByte (byteWriter, BC_TO_STRING_F);
                                                type = type_long;
                                                break;
                                        }
                                        break;
                                }

                                // depending on the register writing a store operator
                                switch (variable.scope.rgtr) {
                                    case scope_global:
                                        switch (variable.type) {
                                            case type_ubyte:
                                            case type_byte:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_NUM8);
                                                break;
                                            case type_ushort:
                                            case type_short:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_NUM16);
                                                break;
                                            case type_uint:
                                            case type_int:
                                            case type_float:
                                                if (type == type_double || type == type_float) {
                                                    ByteWriter_writeByte (byteWriter, BC_Double2Float);
                                                }
                                                ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_NUM32);
                                                break;
                                            case type_ulong:
                                            case type_long:
                                            case type_double:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_NUM64);
                                                break;
                                            case type_function:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_FUNC);
                                                break;
                                            case type_complex:
                                            case type_text:
                                                ByteWriter_writeByte(byteWriter, BC_STORE_GLOBAL_TEXT);
                                                break;
                                            default:
                                                markTokenError( variable.value);
                                                switch (variable.value.type) {
                                                    case TT_String:
                                                        printf ("Problem with Variable: %s\n", variable.value.value.word);
                                                        break;
                                                    case TT_Int:
                                                        printf ("Problem with Variable: %lld\n", variable.value.value.i);
                                                        break;
                                                    case TT_Uint:
                                                        printf ("Problem with Variable: %llu\n", variable.value.value.u);
                                                        break;
                                                    case TT_Float:
                                                        printf ("Problem with Variable: %lf\n", variable.value.value.f);
                                                        break;
                                                    default: puts ("Something went wrong...");
                                                }
                                                switch (variable.scope.rgtr) {
                                                    case scope_constant:
                                                        puts ("Scope: Constant");
                                                        break;
                                                    case scope_global:
                                                        puts ("Scope: Global");
                                                        break;
                                                    case scope_local:
                                                        printf ("Scope: Local, in Function: %s\n", variable.scope.function.value.word);
                                                        break;
                                                    case scope_undefined:
                                                        puts ("Undefined");
                                                        break;
                                                    default:;
                                                }
                                                puts ("This kind of type isn't supported yet!");
                                                exit (1);
                                        }
                                        break;
                                    case scope_local:
                                        switch (variable.type) {
                                            case type_ubyte:
                                            case type_byte:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_STACK_NUM8);
                                                break;
                                            case type_ushort:
                                            case type_short:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_STACK_NUM16);
                                                break;
                                            case type_uint:
                                            case type_int:
                                            case type_float:
                                                if (type == type_float || type == type_double) {
                                                    ByteWriter_writeByte (byteWriter, BC_Double2Float);
                                                }
                                                ByteWriter_writeByte (byteWriter, BC_STORE_STACK_NUM32);
                                                break;
                                            case type_ulong:
                                            case type_long:
                                            case type_double:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_STACK_NUM64);
                                                break;
                                            case type_complex:
                                            case type_text:
                                                ByteWriter_writeByte (byteWriter, BC_STORE_STACK_TEXT);
                                                break;
                                            case type_function:
                                                ByteWriter_writeByte(byteWriter, BC_STORE_STACK_FUNC);
                                                break;
                                            default:
                                                markTokenError( variable.value);
                                                switch (variable.value.type) {
                                                    case TT_String:
                                                        printf ("Problem with Variable: %s\n", variable.value.value.word);
                                                        break;
                                                    case TT_Int:
                                                        printf ("Problem with Variable: %lld\n", variable.value.value.i);
                                                        break;
                                                    case TT_Uint:
                                                        printf ("Problem with Variable: %llu\n", variable.value.value.u);
                                                        break;
                                                    case TT_Float:
                                                        printf ("Problem with Variable: %lf\n", variable.value.value.f);
                                                        break;
                                                    default: puts ("Something went wrong...");
                                                }
                                                switch (variable.scope.rgtr) {
                                                    case scope_constant:
                                                        puts ("Scope: Constant");
                                                        break;
                                                    case scope_global:
                                                        puts ("Scope: Global");
                                                        break;
                                                    case scope_local:
                                                        printf ("Scope: Local, in Function: %s\n", variable.scope.function.value.word);
                                                        break;
                                                    case scope_undefined:
                                                        puts ("Undefined");
                                                        break;
                                                    default:;
                                                }
                                                puts ("This kind of type isn't supported yet!");
                                                exit (1);
                                        }
                                        break;
                                    default:
                                        puts ("The variable is a const, therefore it is Inmutable!");
                                        markTokenError(valueNode.value);
                                        exit (1);
                                }
                                ByteWriter_writeUInt (byteWriter, variable.index);
                                return type_none;
                            }
                        }
                        else {
                            puts ("Expected an Identifier!");
                            markTokenError( valueNode.value);
                            exit (1);
                        }
                    } else if (nodeleft.type == ID_SquareCallNode) {
                        SquareCallNode squareCallNode = *nodeleft.squareCallNode;
                        Token name = squareCallNode.identifier.valueNode->value;
                        Symbol collection = VariableTable_findVariableByName (&codeGenerator->table, name);
                        unsigned char ctype = typeToStackType (collection.storingType);

                        if (ctype != typeToStackType (type)) {
                            puts ("No given index!");
                            markTokenError( name);
                            exit (1);
                        }
                        
                        // Loading Collection
                        if (collection.scope.rgtr == scope_local)
                            ByteWriter_writeByte (byteWriter, BC_LOAD_STACK_COLLECTION);
                        else
                            ByteWriter_writeByte (byteWriter, BC_LOAD_GLOBAL_COLLECTION);

                        ByteWriter_writeUInt (byteWriter, collection.index);
                        ByteWriter_writeByte (byteWriter, BC_SWAP);

                        if (squareCallNode.numbersOfArguments == 0) {
                            puts ("No given index!");
                            markTokenError( name);
                            exit (1);
                        }
                        
                        unsigned char type = CodeGenerator_generateExpression (codeGenerator, squareCallNode.arguments[0], scope, byteWriter);
                        if(typeToStackType(type) == type_long) {
                            ByteWriter_writeByte(byteWriter, BC_I2U);
                        } else if (typeToStackType(type) == type_double) {
                            ByteWriter_writeByte(byteWriter, BC_F2U);
                        } else if (typeToStackType(type) != type_ulong) {
                            puts ("Accessing an array requires a number!");
                            markTokenError( squareCallNode.identifier.valueNode->value);
                            exit (1);
                        }

                        ByteWriter_writeByte (byteWriter, BC_STORE_ELEMENT);

                        // Cleaning up by storing the collection back
                        if (collection.scope.rgtr == scope_local)
                            ByteWriter_writeByte (byteWriter, BC_STORE_STACK_COLLECTION);
                        else
                            ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_COLLECTION);

                        ByteWriter_writeUInt (byteWriter, collection.index);
                        return type_none;
                    }
                }
                    break;

                case TTK_As:
                {
                    unsigned char type = CodeGenerator_generateExpression (codeGenerator, binOpNode->left, scope, byteWriter);
                    unsigned char stype = typeToStackType (type);
                    if (binOpNode->right.type != ID_ValueNode) {
                        puts ("Type conversation have to be an existing Type!");
                        markTokenError( binOpNode->operator);
                        exit (1);
                    }
                    unsigned char rtype = tokenTypeToDataType (binOpNode->right.valueNode->value, codeGenerator);
                    unsigned char srtype = typeToStackType (rtype);
                    switch (stype) {
                        case type_long:
                            switch (srtype) {
                                case type_ulong:
                                    ByteWriter_writeByte (byteWriter, BC_I2U);
                                    break;
                                case type_long:
                                    break;
                                case type_double:
                                    ByteWriter_writeByte (byteWriter, BC_I2F);
                                    break;
                                case type_text:
                                    ByteWriter_writeByte (byteWriter, BC_TO_STRING_I);
                                    break;
                                default:
                                    puts ("Type conversation, unsupported datatype!");
                                    markTokenError( binOpNode->operator);
                                    exit (1);
                            }
                            break;
                        case type_ulong:
                            switch (srtype) {
                                case type_ulong:
                                    break;
                                case type_long:
                                    ByteWriter_writeByte (byteWriter, BC_U2I);
                                    break;
                                case type_double:
                                    ByteWriter_writeByte (byteWriter, BC_U2F);
                                    break;
                                case type_text:
                                    ByteWriter_writeByte (byteWriter, BC_TO_STRING_U);
                                    break;
                                default:
                                    puts ("Type conversation, unsupported datatype!");
                                    markTokenError( binOpNode->operator);
                                    exit (1);
                            }
                            break;
                        case type_double:
                            switch (srtype) {
                                case type_ulong:
                                    ByteWriter_writeByte (byteWriter, BC_F2U);
                                    break;
                                case type_long:
                                    ByteWriter_writeByte (byteWriter, BC_F2I);
                                    break;
                                case type_double:
                                    break;
                                case type_text:
                                    ByteWriter_writeByte (byteWriter, BC_TO_STRING_F);
                                    break;
                                default:
                                    puts ("Type conversation, unsupported datatype!");
                                    markTokenError( binOpNode->operator);
                                    exit (1);
                            }
                            break;
                        case type_text:
                            switch (srtype) {
                                case type_ulong:
                                    ByteWriter_writeByte (byteWriter, BC_STR_TO_U);
                                    break;
                                case type_long:
                                    ByteWriter_writeByte (byteWriter, BC_STR_TO_I);
                                    break;
                                case type_double:
                                    ByteWriter_writeByte (byteWriter, BC_STR_TO_F);
                                    break;
                                case type_text:
                                    break;
                                default:
                                    puts ("Type conversation, unsupported datatype!");
                                    markTokenError( binOpNode->operator);
                                    exit (1);
                            }
                            break;
                        case type_any:
                            break;
                        default:
                            puts ("Type conversation, unsupported datatype!");
                            markTokenError( binOpNode->operator);
                            exit (1);
                    }
                    return srtype;
                }
                    break;

                case TT_Dot:
                {
                    SyntaxNode left = binOpNode->left;
                    SyntaxNode right = binOpNode->right;
                    if (right.type == ID_FunctionCallNode) {
                        FunctionCallNode fn = *right.functionCallNode;
                        if (left.type == ID_ValueNode)
                            if (left.valueNode->value.type == TT_Identifier) {
                                Token name = left.valueNode->value;
                                Symbol collection = VariableTable_findVariableByName (&codeGenerator->table, name);
                                unsigned char rtype = type_none;
                                if (collection.type == type_Collection) {
                                    if (collection.scope.rgtr == scope_local)
                                        ByteWriter_writeByte (byteWriter, BC_LOAD_STACK_COLLECTION);
                                    else
                                        ByteWriter_writeByte (byteWriter, BC_LOAD_GLOBAL_COLLECTION);
                                    ByteWriter_writeUInt (byteWriter, collection.index);
                                    if (strcmp (fn.identifier.valueNode->value.value.word, "Size") == 0) {
                                        if (fn.numbersOfArguments != 0) {
                                            puts ("The function does not have any argument!!");
                                            markTokenError( fn.identifier.valueNode->value);
                                            exit (1);
                                        }
                                        ByteWriter_writeByte (byteWriter, BC_SIZEOF_COLLECTION);
                                        rtype =  type_ulong;
                                    } else if (strcmp (fn.identifier.valueNode->value.value.word, "Remove") == 0) {
                                        if (fn.numbersOfArguments != 1) {
                                            puts ("The function must have 1 argument!");
                                            markTokenError( fn.identifier.valueNode->value);
                                            exit (1);
                                        }
                                        unsigned char ttype = CodeGenerator_generateExpression (codeGenerator, fn.arguments[0], scope, byteWriter);
                                        if (typeToStackType (ttype) != type_ulong) {
                                            puts ("The Index must be an unsigned!");
                                            markTokenError( fn.identifier.valueNode->value);
                                            exit (1);
                                        }
                                        ByteWriter_writeByte (byteWriter, BC_REMOVE_ELEMENT);
                                        rtype =  collection.storingType;
                                    } else if (strcmp (fn.identifier.valueNode->value.value.word, "Add") == 0) {
                                        if (fn.numbersOfArguments != 1) {
                                            puts ("The function must have 1 argument!");
                                            markTokenError( fn.identifier.valueNode->value);
                                            exit (1);
                                        }
                                        CodeGenerator_generateExpression (codeGenerator, fn.arguments[0], scope, byteWriter);
                                        ByteWriter_writeByte (byteWriter, BC_ADD_ELEMENT);
                                    } else if (strcmp (fn.identifier.valueNode->value.value.word, "Clear") == 0) {
                                        if (fn.numbersOfArguments != 0) {
                                            puts ("The function must not have none argument!");
                                            markTokenError( fn.identifier.valueNode->value);
                                            exit (1);
                                        }
                                        ByteWriter_writeByte (byteWriter, BC_POP);
                                        ByteWriter_writeByte (byteWriter, BC_BUILD_EMPTYCOLLECTION);
                                    }
                                    if (collection.scope.rgtr == scope_local)
                                        ByteWriter_writeByte (byteWriter, BC_STORE_STACK_COLLECTION);
                                    else
                                        ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_COLLECTION);
                                    ByteWriter_writeUInt (byteWriter, collection.index);
                                    return rtype;
                                }
                            }
                        if (strcmp (fn.identifier.valueNode->value.value.word, "Length") == 0) {

                            unsigned char type = CodeGenerator_generateExpression (codeGenerator, left, scope, byteWriter);
                            if (type != type_text) {
                                puts ("Object must be a text!");
                                markTokenError(fn.identifier.valueNode->value);
                                exit (1);
                            }

                            if (fn.numbersOfArguments != 0) {
                                puts ("Too many function-arguments!");
                                markTokenError( fn.identifier.valueNode->value);
                                exit (1);
                            }
                            ByteWriter_writeByte (byteWriter, BC_TEXT_GETSIZE);
                            return type_ulong;
                        }
                        else if (strcmp (fn.identifier.valueNode->value.value.word, "InsertChar") == 0) {
                            unsigned char type = CodeGenerator_generateExpression (codeGenerator, left, scope, byteWriter);
                            if (type != type_text) {
                                puts ("Object must be a text!");
                                markTokenError(fn.identifier.valueNode->value);
                                exit (1);
                            }
                            
                            if (fn.numbersOfArguments < 1) {
                                puts ("Too few function-arguments!");
                                markTokenError( fn.identifier.valueNode->value);
                                exit (1);
                            }
                            if (fn.numbersOfArguments > 1) {
                                puts ("Too many function-arguments!");
                                markTokenError( fn.identifier.valueNode->value);
                                exit (1);
                            }
                            unsigned char argtype = CodeGenerator_generateExpression (codeGenerator, fn.arguments[0], scope, byteWriter);
                            switch (argtype) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    ByteWriter_writeByte (byteWriter, BC_I2U);
                                    break;

                                case type_float:
                                case type_double:
                                    ByteWriter_writeByte (byteWriter, BC_F2U);
                                    break;
                                default:
                                    puts ("Wrong datatype as argument!");
                                    markTokenError( fn.identifier.valueNode->value);
                                    exit (1);
                                    break;
                            }
                            ByteWriter_writeByte (byteWriter, BC_TEXT_ADD_CHAR);
                            return type_text;
                        }
                        else if (strcmp (fn.identifier.valueNode->value.value.word, "Pop") == 0) {
                            unsigned char type = CodeGenerator_generateExpression (codeGenerator, left, scope, byteWriter);
                            if (type != type_text) {
                                puts ("Object must be a text!");
                                markTokenError(fn.identifier.valueNode->value);
                                exit (1);
                            }
                            
                            if (fn.numbersOfArguments != 0) {
                                puts ("Too many function-arguments!");
                                markTokenError( fn.identifier.valueNode->value);
                                exit (1);
                            }
                            ByteWriter_writeByte (byteWriter, BC_TEXT_POP_CHAR);
                            return type_text;
                        }
                        else if (strcmp (fn.identifier.valueNode->value.value.word, "CharAt") == 0) {
                            unsigned char type = CodeGenerator_generateExpression (codeGenerator, left, scope, byteWriter);
                            if (type != type_text) {
                                puts ("Object must be a text!");
                                markTokenError(fn.identifier.valueNode->value);
                                exit (1);
                            }
                            
                            if (fn.numbersOfArguments < 1) {
                                puts ("Too few function-arguments!");
                                markTokenError( fn.identifier.valueNode->value);
                                exit (1);
                            }
                            if (fn.numbersOfArguments > 1) {
                                puts ("Too many function-arguments!");
                                markTokenError( fn.identifier.valueNode->value);
                                exit (1);
                            }
                            unsigned char argtype = CodeGenerator_generateExpression (codeGenerator, fn.arguments[0], scope, byteWriter);
                            switch (argtype) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    ByteWriter_writeByte (byteWriter, BC_I2U);
                                    break;

                                case type_float:
                                case type_double:
                                    ByteWriter_writeByte (byteWriter, BC_F2U);
                                    break;
                                default:
                                    puts ("Wrong datatype as argument!");
                                    markTokenError( fn.identifier.valueNode->value);
                                    exit (1);
                                    break;
                            }
                            ByteWriter_writeByte (byteWriter, BC_TEXT_GET_CHAR);
                            return type_ubyte;
                        }
                        else if (strcmp (fn.identifier.valueNode->value.value.word, "Remove") == 0) {
                            unsigned char type = CodeGenerator_generateExpression (codeGenerator, left, scope, byteWriter);
                            if (type != type_text) {
                                puts ("Object must be a text!");
                                markTokenError(fn.identifier.valueNode->value);
                                exit (1);
                            }
                            
                            if (fn.numbersOfArguments < 1) {
                                puts ("Too few function-arguments!");
                                markTokenError( fn.identifier.valueNode->value);
                                exit (1);
                            }
                            if (fn.numbersOfArguments > 1) {
                                puts ("Too many function-arguments!");
                                markTokenError( fn.identifier.valueNode->value);
                                exit (1);
                            }
                            unsigned char argtype = CodeGenerator_generateExpression (codeGenerator, fn.arguments[0], scope, byteWriter);
                            switch (argtype) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    ByteWriter_writeByte (byteWriter, BC_I2U);
                                    break;

                                case type_float:
                                case type_double:
                                    ByteWriter_writeByte (byteWriter, BC_F2U);
                                    break;
                                default:
                                    puts ("Wrong datatype as argument!");
                                    markTokenError( fn.identifier.valueNode->value);
                                    exit (1);
                                    break;
                            }
                            ByteWriter_writeByte (byteWriter, BC_TEXT_REMOVE_CHAR);
                            return type_text;
                        }else if (strcmp (fn.identifier.valueNode->value.value.word, "SetChar") == 0) {
                            unsigned char type = CodeGenerator_generateExpression (codeGenerator, left, scope, byteWriter);
                            if (type != type_text) {
                                puts ("Object must be a text!");
                                markTokenError(fn.identifier.valueNode->value);
                                exit (1);
                            }
                            
                            if (fn.numbersOfArguments < 2) {
                                puts ("Too few function-arguments!");
                                markTokenError( fn.identifier.valueNode->value);
                                exit (1);
                            }
                            if (fn.numbersOfArguments > 2) {
                                puts ("Too many function-arguments!");
                                markTokenError( fn.identifier.valueNode->value);
                                exit (1);
                            }
                            unsigned char argtype = CodeGenerator_generateExpression (codeGenerator, fn.arguments[1], scope, byteWriter);
                            switch (argtype) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    ByteWriter_writeByte (byteWriter, BC_I2U);
                                    break;

                                case type_float:
                                case type_double:
                                    ByteWriter_writeByte (byteWriter, BC_F2U);
                                    break;
                                default:
                                    puts ("Wrong datatype as argument!");
                                    markTokenError( fn.identifier.valueNode->value);
                                    exit (1);
                                    break;
                            }
                            unsigned char postype = CodeGenerator_generateExpression (codeGenerator, fn.arguments[0], scope, byteWriter);
                            switch (postype) {
                                case type_ubyte:
                                case type_ushort:
                                case type_uint:
                                case type_ulong:
                                    break;
                                case type_byte:
                                case type_short:
                                case type_int:
                                case type_long:
                                    ByteWriter_writeByte (byteWriter, BC_I2U);
                                    break;

                                case type_float:
                                case type_double:
                                    ByteWriter_writeByte (byteWriter, BC_F2U);
                                    break;
                                default:
                                    puts ("Wrong datatype as argument!");
                                    markTokenError( fn.identifier.valueNode->value);
                                    exit (1);
                                    break;
                            }
                            ByteWriter_writeByte (byteWriter, BC_TEXT_SET_CHAR);
                            return type_text;
                        }
                        else if (strcmp (fn.identifier.valueNode->value.value.word, "Print") == 0) {
                            unsigned char type = CodeGenerator_generateExpression (codeGenerator, left, scope, byteWriter);
                            if (type != type_text) {
                                puts ("Object must be a text!");
                                markTokenError(fn.identifier.valueNode->value);
                                exit (1);
                            }
                            
                            if (fn.numbersOfArguments != 0) {
                                puts ("Too many function-arguments!");
                                markTokenError( fn.identifier.valueNode->value);
                                exit (1);
                            }
                            ByteWriter_writeByte (byteWriter, BC_PRINT_TEXT);
                            return type_none;
                        }
                        else if (strcmp (fn.identifier.valueNode->value.value.word, "Println") == 0) {
                            unsigned char type = CodeGenerator_generateExpression (codeGenerator, left, scope, byteWriter);
                            if (type != type_text) {
                                puts ("Object must be a text!");
                                markTokenError(fn.identifier.valueNode->value);
                                exit (1);
                            }
                            
                            if (fn.numbersOfArguments != 0) {
                                puts ("Too many function-arguments!");
                                markTokenError( fn.identifier.valueNode->value);
                                exit (1);
                            }
                            ByteWriter_writeByte (byteWriter, BC_PRINT_TEXT);
                            ByteWriter_writeByte (byteWriter, BC_NEWLINE);
                            return type_none;
                        }

                        SyntaxNode functionCallNode = newFunctionCallNode(fn.identifier);
                        FunctionCallNode_add(functionCallNode, left);
                        for(unsigned int arg_i = 0; arg_i < fn.numbersOfArguments; ++arg_i) {
                            FunctionCallNode_add(functionCallNode, fn.arguments[arg_i]);
                        }

                        return CodeGenerator_generateExpression(codeGenerator, functionCallNode, scope, byteWriter);
                    } else if(right.type == ID_ValueNode) {
                        if (left.type == ID_ValueNode) {
                            if (left.valueNode->value.type == TT_Identifier && right.valueNode->value.type == TT_Identifier) {
                                Token name = left.valueNode->value;
                                Token memberName = right.valueNode->value;
                                Symbol leftComplex = VariableTable_findVariableByName (&codeGenerator->table, name);
                                
                                // Now this only works with complexes
                                if(leftComplex.type == type_complex) {

                                    // Now we simply need to find out if that variable is an field within the mothertype
                                    // and get its type

                                    Symbol mothertype = VariableTable_findVariableByName(&codeGenerator->table, leftComplex.mothertype);
                                    
                                    for(unsigned int member = 0u; member < mothertype.argumentsCount; member++) {
                                        if(strcmp(mothertype.arguments[member].name.value.word, memberName.value.word) == 0) {
                                            
                                            // Now call the right $$select.. function

                                            SyntaxNode fnCallNode;
                                            switch(tokenTypeToDataType(mothertype.arguments[member].type, codeGenerator)) {
                                                case type_ubyte:
                                                case type_ushort:
                                                case type_uint:
                                                case type_ulong:
                                                    fnCallNode = newFunctionCallNode(newValueNode((Token) {
                                                        .type = TT_Identifier,
                                                        .value.word = "$_selectUInt_$"
                                                    }));

                                                    FunctionCallNode_add(fnCallNode, newValueNode((Token) {
                                                        .type = TT_Identifier,
                                                        .value.word = name.value.word
                                                    }));

                                                    FunctionCallNode_add(fnCallNode, newValueNode((Token) {
                                                        .type = TT_String,
                                                        .value.word = memberName.value.word
                                                    }));

                                                    return CodeGenerator_generateExpression(codeGenerator, fnCallNode, scope, byteWriter);
                                                case type_byte:
                                                case type_short:
                                                case type_int:
                                                case type_long:
                                                    fnCallNode = newFunctionCallNode(newValueNode((Token) {
                                                        .type = TT_Identifier,
                                                        .value.word = "$_selectInt_$"
                                                    }));

                                                    FunctionCallNode_add(fnCallNode, newValueNode((Token) {
                                                        .type = TT_Identifier,
                                                        .value.word = name.value.word
                                                    }));

                                                    FunctionCallNode_add(fnCallNode, newValueNode((Token) {
                                                        .type = TT_String,
                                                        .value.word = memberName.value.word
                                                    }));

                                                    return CodeGenerator_generateExpression(codeGenerator, fnCallNode, scope, byteWriter);
                                                case type_float:
                                                case type_double:
                                                    fnCallNode = newFunctionCallNode(newValueNode((Token) {
                                                        .type = TT_Identifier,
                                                        .value.word = "$_selectFloat_$"
                                                    }));

                                                    FunctionCallNode_add(fnCallNode, newValueNode((Token) {
                                                        .type = TT_Identifier,
                                                        .value.word = name.value.word
                                                    }));

                                                    FunctionCallNode_add(fnCallNode, newValueNode((Token) {
                                                        .type = TT_String,
                                                        .value.word = memberName.value.word
                                                    }));

                                                    return CodeGenerator_generateExpression(codeGenerator, fnCallNode, scope, byteWriter);
                                                case type_complex:
                                                    fnCallNode = newFunctionCallNode(newValueNode((Token) {
                                                        .type = TT_Identifier,
                                                        .value.word = "$_selectText_$"
                                                    }));

                                                    FunctionCallNode_add(fnCallNode, newValueNode((Token) {
                                                        .type = TT_Identifier,
                                                        .value.word = name.value.word
                                                    }));

                                                    FunctionCallNode_add(fnCallNode, newValueNode((Token) {
                                                        .type = TT_String,
                                                        .value.word = memberName.value.word
                                                    }));

                                                    CodeGenerator_generateExpression(codeGenerator, fnCallNode, scope, byteWriter);
                                                    
                                                    Complex_return = mothertype.arguments[member].type;
                                                    
                                                    return type_complex;
                                                case type_text:
                                                    fnCallNode = newFunctionCallNode(newValueNode((Token) {
                                                        .type = TT_Identifier,
                                                        .value.word = "$_selectText_$"
                                                    }));

                                                    FunctionCallNode_add(fnCallNode, newValueNode((Token) {
                                                        .type = TT_Identifier,
                                                        .value.word = name.value.word
                                                    }));

                                                    FunctionCallNode_add(fnCallNode, newValueNode((Token) {
                                                        .type = TT_String,
                                                        .value.word = memberName.value.word
                                                    }));

                                                    return CodeGenerator_generateExpression(codeGenerator, fnCallNode, scope, byteWriter);
                                                    
                                                    
                                            }
                                        }
                                    }

                                    puts ("Field in table object doesn't exist: ");
                                    puts (memberName.value.word);
                                    markTokenError( binOpNode->operator);
                                    exit (1);

                                } else {
                                    puts ("left value must be an table object!");
                                    markTokenError( binOpNode->operator);
                                    exit (1);
                                }
                            }
                        }
                    }
                }
                    break;
                
                default:
                    markTokenError( binOpNode->operator);
                    puts ("Unusable binary operator!");
                    exit (1);
            }
        }
            break;
        case ID_UnaryOpNode:
        {
            UnaryOpNode* unaryOpNode = node.unaryOpNode;
            unsigned int line_count = unaryOpNode->operator.lineNumber;
            if(DEBUGGING_MODE)
            if(line_count != 0 && codeGenerator->currentLine != line_count) {
                codeGenerator->currentLine = line_count;
                char hint[1024] = "";

                sprintf(hint, "ln;%d", line_count);

                ByteWriter_writeByte(byteWriter, BC_HINT);
                unsigned int hint_len = strlen(hint);
                ByteWriter_writeUInt(byteWriter, hint_len);
                for(unsigned int i = 0; i < hint_len; ++i) {
                    ByteWriter_writeByte(byteWriter, hint[i]);
                }
            }

            unsigned char type = typeToStackType (CodeGenerator_generateExpression (codeGenerator, unaryOpNode->operand, scope, byteWriter));
            switch (unaryOpNode->operator.type) {
                case TT_Minus:
                    if (type == type_ulong) {
                        puts ("Cannot use binary minus on an unsigned!");
                        markTokenError( unaryOpNode->operator);
                        exit (1);
                    }
                    else if (type == type_double) {
                        ByteWriter_writeByte (byteWriter, BC_UNARY_MINUS_F);
                        return type_double;
                    }
                    else if (type == type_long) {
                        ByteWriter_writeByte (byteWriter, BC_UNARY_MINUS_I);
                        return type_long;
                    }
                    else {
                        puts ("Cannot use binary minus other types then floats and ints");
                        markTokenError( unaryOpNode->operator);
                        exit (1);
                    }
                    break;
                case TT_Plus:
                    break;

                case TT_Exclamationmark:
                {
                    //unsigned char type = CodeGenerator_generateExpression (codeGenerator, unaryOpNode->operand, scope, byteWriter);
                    switch (type) {
                        
                        case type_ubyte:
                        case type_ushort:
                        case type_uint:
                        case type_ulong:
                        case type_byte:
                        case type_short:
                        case type_int:
                        case type_long:
                            ByteWriter_writeByte (byteWriter, BC_NOT);
                            return type_ubyte;
                            break;

                        default:
                            markTokenError( unaryOpNode->operator);
                            puts ("Unusable datatype!");
                            exit (1);
                    }
                }
                    break;
                case TT_HashSymbol:
                {
                    switch (type) {
                        
                        case type_text:
                            ByteWriter_writeByte (byteWriter, BC_TEXT_HASH);
                            return type_uint;
                            break;

                        default:
                            markTokenError( unaryOpNode->operator);
                            puts ("Unusable datatype!");
                            exit (1);
                    }
                }
                    break;

                case TT_Multiply:
                {
                    markTokenError( unaryOpNode->operator);
                    puts ("Function call required in order to insert it's statements.");
                    exit (1);
                }
                    break;
                default:
                    markTokenError( unaryOpNode->operator);
                    puts ("Unusable unary operator!");
                    exit (1);
            }
        }
            break;
        case ID_ValueNode:
        {
            ValueNode* valueNode = node.valueNode;
            unsigned int line_count = valueNode->value.lineNumber;
            if(DEBUGGING_MODE)
            if(line_count != 0 && codeGenerator->currentLine != line_count) {
                codeGenerator->currentLine = line_count;
                char hint[1024] = "";

                sprintf(hint, "ln;%d", line_count);

                ByteWriter_writeByte(byteWriter, BC_HINT);
                unsigned int hint_len = strlen(hint);
                ByteWriter_writeUInt(byteWriter, hint_len);
                for(unsigned int i = 0; i < hint_len; ++i) {
                    ByteWriter_writeByte(byteWriter, hint[i]);
                }
            }
            switch (valueNode->value.type) {
                
                case TT_Int:
                case TT_Uint:
                case TT_Float:
                case TT_String:
                    // They are all constants
                {
                    Symbol declaration = VariableTable_findVariableByName (&codeGenerator->table, valueNode->value);
                    if (declaration.type == type_undefined) {
                        Symbol constant = VariableTable_declareVariable (&codeGenerator->table, valueNode->value, (Scope) {.rgtr = scope_constant});
                        switch (valueNode->value.type) {
                            case TT_Int:
                                if (valueNode->value.value.i >= SCHAR_MIN && valueNode->value.value.i <= SCHAR_MAX) { // Byte/Char in C (64 Version)
                                    VariableTable_defineVariable (&codeGenerator->table, constant.value, type_byte);
                                }
                                else if (valueNode->value.value.i >= SHRT_MIN && valueNode->value.value.i <= SHRT_MAX) { // 16Bits/Short in C (64 Version)
                                    VariableTable_defineVariable (&codeGenerator->table, constant.value, type_short);
                                }
                                else if (valueNode->value.value.i >= INT_MIN && valueNode->value.value.i <= INT_MAX) { // 32Bits/Int in C (64 Version)
                                    VariableTable_defineVariable (&codeGenerator->table, constant.value, type_int);
                                }
                                else if (valueNode->value.value.i >= LLONG_MIN && valueNode->value.value.i <= LLONG_MAX) { // 64Bits/Long in C (64 Version)
                                    VariableTable_defineVariable (&codeGenerator->table, constant.value, type_long);
                                }
                                else {
                                    puts ("This Value is out of range!");
                                    markTokenError( valueNode->value);
                                    exit (1);
                                }
                                break;
                            case TT_Uint:
                                if (valueNode->value.value.u >= 0 && valueNode->value.value.u <= UCHAR_MAX) { // Byte/Char in C (64 Version)
                                    VariableTable_defineVariable (&codeGenerator->table, constant.value, type_ubyte);
                                }
                                else if (valueNode->value.value.u >= 0 && valueNode->value.value.u <= USHRT_MAX) { // 16Bits/Short in C (64 Version)
                                    VariableTable_defineVariable (&codeGenerator->table, constant.value, type_ushort);
                                }
                                else if (valueNode->value.value.u >= 0 && valueNode->value.value.u <= UINT_MAX) { // 32Bits/Int in C (64 Version)
                                    VariableTable_defineVariable (&codeGenerator->table, constant.value, type_uint);
                                }
                                else if (valueNode->value.value.u >= 0 && valueNode->value.value.u <= ULLONG_MAX) { // 64Bits/Long in C (64 Version)
                                    VariableTable_defineVariable (&codeGenerator->table, constant.value, type_ulong);
                                }
                                else {
                                    puts ("This Value is out of range!");
                                    markTokenError( valueNode->value);
                                    exit (1);
                                }
                                break;
                            case TT_Float:
                                if (valueNode->value.value.f >= 0 && valueNode->value.value.f <= FLT_MAX) { 
                                    VariableTable_defineVariable (&codeGenerator->table, constant.value, type_float);
                                }
                                else if (valueNode->value.value.f >= 0 && valueNode->value.value.f <= DBL_MAX) { 
                                    VariableTable_defineVariable (&codeGenerator->table, constant.value, type_double);
                                }
                                else {
                                    puts ("This Value is out of range!");
                                    markTokenError( valueNode->value);
                                    exit (1);
                                }
                                break;
                            case TT_String:
                                VariableTable_defineVariable (&codeGenerator->table, constant.value, type_text);
                                break;
                        }
                    }
                    declaration = VariableTable_findVariableByName (&codeGenerator->table, valueNode->value);
                    switch (declaration.type) {
                        case type_ubyte:
                        case type_byte:
                            ByteWriter_writeByte (byteWriter, BC_LOAD_CONST_NUM8);
                            ByteWriter_writeUInt (byteWriter, declaration.index);
                            break;
                        case type_short:
                        case type_ushort:
                            ByteWriter_writeByte (byteWriter, BC_LOAD_CONST_NUM16);
                            ByteWriter_writeUInt (byteWriter, declaration.index);
                            break;
                        case type_uint:
                        case type_int:
                        case type_float:
                            ByteWriter_writeByte (byteWriter, BC_LOAD_CONST_NUM32);
                            ByteWriter_writeUInt (byteWriter, declaration.index);
                            if (declaration.type == type_float) {
                                ByteWriter_writeByte (byteWriter, BC_Float2Double);
                            }
                            break;
                        case type_ulong:
                        case type_long:
                        case type_double:
                            ByteWriter_writeByte (byteWriter, BC_LOAD_CONST_NUM64);
                            ByteWriter_writeUInt (byteWriter, declaration.index);
                            break;
                        case type_text:
                            ByteWriter_writeByte (byteWriter, BC_LOAD_CONST_TEXT);
                            ByteWriter_writeUInt (byteWriter, declaration.index);
                            break;
                        default:
                            puts ("This type isn't supported yet!");
                            exit (1);
                    }
                    return declaration.type;
                }
                    break;

                case TTK_True:
                {
                    unsigned int index = 0;
                    if (VariableTable_findVariableByName (&codeGenerator->table,
                        (Token) {.begin = 0, .end = 0, .lineNumber = 0, .type = TT_Uint, .value.u = 1}).type == type_undefined) {
                            VariableTable_declareVariable (&codeGenerator->table,
                                (Token) {.begin = 0, .end = 0, .lineNumber = 0, .type = TT_Uint, .value.u = 1},
                                (Scope) {.rgtr = scope_constant}
                            );
                            index = VariableTable_defineVariable (&codeGenerator->table,
                                (Token) {.begin = 0, .end = 0, .lineNumber = 0, .type = TT_Uint, .value.u = 1},
                                type_ubyte
                            );
                    } else {
                        index = VariableTable_findVariableByName (&codeGenerator->table, 
                            (Token) {.begin = 0, .end = 0, .lineNumber = 0, .type = TT_Uint, .value.u = 1}).index;
                    }
                    ByteWriter_writeByte (byteWriter, BC_LOAD_CONST_NUM8);
                    ByteWriter_writeUInt (byteWriter, index);
                    return type_ubyte;
                }
                    break;

                case TTK_False:
                {
                    unsigned int index = 0;
                    if (VariableTable_findVariableByName (&codeGenerator->table,
                        (Token) {.begin = 0, .end = 0, .lineNumber = 0, .type = TT_Uint, .value.u = 0}).type == type_undefined) {
                            VariableTable_declareVariable (&codeGenerator->table,
                                (Token) {.begin = 0, .end = 0, .lineNumber = 0, .type = TT_Uint, .value.u = 0},
                                (Scope) {.rgtr = scope_constant}
                            );
                            index = VariableTable_defineVariable (&codeGenerator->table,
                                (Token) {.begin = 0, .end = 0, .lineNumber = 0, .type = TT_Uint, .value.u = 0},
                                type_ubyte
                            );
                    } else {
                        index = VariableTable_findVariableByName (&codeGenerator->table, 
                            (Token) {.begin = 0, .end = 0, .lineNumber = 0, .type = TT_Uint, .value.u = 0}).index;
                    }
                    ByteWriter_writeByte (byteWriter, BC_LOAD_CONST_NUM8);
                    ByteWriter_writeUInt (byteWriter, index);
                    return type_ubyte;
                }
                    break;
                
                case TT_Identifier:
                {
                    // Loads the corresponding variable by the variable table and checks it does exist
                    Symbol declaration = VariableTable_findVariableByName (&codeGenerator->table, valueNode->value);
                    if (declaration.type == type_undefined) {
                        puts ("Undefined Variable, therefore it's impossible to load a value!");
                        markTokenError( valueNode->value);
                        exit (1);
                    }

                    // React to the type of the variable to generate the correct bytecode
                    switch (declaration.type)
                    {
                    case type_ubyte:
                    case type_byte:
                        // Now it has to match the right scope
                        switch (declaration.scope.rgtr) {
                            
                            case scope_constant:
                                // If the scope is constant, it loads it from constants register
                                ByteWriter_writeByte (byteWriter, BC_LOAD_CONST_NUM8);
                                break;
                            case scope_global:
                                // If the scope is global, it loads it from the global register
                                ByteWriter_writeByte (byteWriter, BC_LOAD_GLOBAL_NUM8);
                                break;
                            case scope_local:
                                // If the scope is local/stack, it loads it from the stack register
                                ByteWriter_writeByte (byteWriter, BC_LOAD_STACK_NUM8);
                                break;

                            default:
                                puts ("Unusable Register Id!");
                                markTokenError( valueNode->value);
                                exit (1);
                        }
                        // then comes the matching index of the variable
                        ByteWriter_writeUInt (byteWriter, declaration.index);
                        break;
                    
                    case type_ushort:
                    case type_short:
                        // In this case the variable has a size of 16 bits / 2 bytes
                        switch (declaration.scope.rgtr) {
                            
                            // Same game as above
                            case scope_constant:
                                ByteWriter_writeByte (byteWriter, BC_LOAD_CONST_NUM16);
                                break;
                            case scope_global:
                                ByteWriter_writeByte (byteWriter, BC_LOAD_GLOBAL_NUM16);
                                break;
                            case scope_local:
                                ByteWriter_writeByte (byteWriter, BC_LOAD_STACK_NUM16);
                                break;

                            default:
                                puts ("Unusable Register Id!");
                                markTokenError( valueNode->value);
                                exit (1);
                        }
                        ByteWriter_writeUInt (byteWriter, declaration.index);
                        break;
                    
                    case type_uint:
                    case type_int:
                    case type_float:
                        // Size of 32 bits / 4 bytes
                        switch (declaration.scope.rgtr) {
                            
                            case scope_constant:
                                ByteWriter_writeByte (byteWriter, BC_LOAD_CONST_NUM32);
                                break;
                            case scope_global:
                                ByteWriter_writeByte (byteWriter, BC_LOAD_GLOBAL_NUM32);
                                break;
                            case scope_local:
                                ByteWriter_writeByte (byteWriter, BC_LOAD_STACK_NUM32);
                                break;

                            default:
                                puts ("Unusable Register Id!");
                                markTokenError( valueNode->value);
                                exit (1);
                        }
                        ByteWriter_writeUInt (byteWriter, declaration.index);
                        if (declaration.type == type_float) {
                            ByteWriter_writeByte (byteWriter, BC_Float2Double);
                        }
                        break;
                    
                    case type_ulong:
                    case type_long:
                    case type_double:
                        // Size of 64 bits / 8 bytes
                        switch (declaration.scope.rgtr) {
                            
                            case scope_constant:
                                ByteWriter_writeByte (byteWriter, BC_LOAD_CONST_NUM64);
                                break;
                            case scope_global:
                                ByteWriter_writeByte (byteWriter, BC_LOAD_GLOBAL_NUM64);
                                break;
                            case scope_local:
                                ByteWriter_writeByte (byteWriter, BC_LOAD_STACK_NUM64);
                                break;

                            default:
                                puts ("Unusable Register Id!");
                                markTokenError( valueNode->value);
                                exit (1);
                        }
                        ByteWriter_writeUInt (byteWriter, declaration.index);
                        break;

                    case type_complex:
                    case type_text:
                        // Just a string
                        switch (declaration.scope.rgtr) {
                            
                            case scope_constant:
                                ByteWriter_writeByte (byteWriter, BC_LOAD_CONST_TEXT);
                                break;
                            case scope_global:
                                ByteWriter_writeByte (byteWriter, BC_LOAD_GLOBAL_TEXT);
                                break;
                            case scope_local:
                                ByteWriter_writeByte (byteWriter, BC_LOAD_STACK_TEXT);
                                break;

                            default:
                                puts ("Unusable Register Id!");
                                markTokenError( valueNode->value);
                                exit (1);
                        }
                        ByteWriter_writeUInt (byteWriter, declaration.index);
                        break;

                    case type_Collection:
                        // a collection
                        switch (declaration.scope.rgtr) {

                            case scope_global:
                                ByteWriter_writeByte (byteWriter, BC_LOAD_GLOBAL_COLLECTION);
                                break;
                            case scope_local:
                                ByteWriter_writeByte (byteWriter, BC_LOAD_STACK_COLLECTION);
                                break;

                            default:
                                puts ("Unusable Register Id!");
                                markTokenError( valueNode->value);
                                exit (1);
                        }
                        ByteWriter_writeUInt (byteWriter, declaration.index);
                        break;
                    case type_function:
                        // Just a function
                        switch (declaration.scope.rgtr) {
                            
                            case scope_constant:
                                ByteWriter_writeByte (byteWriter, BC_LOAD_CONST_FUNC);
                                break;
                            case scope_global:
                                ByteWriter_writeByte (byteWriter, BC_LOAD_GLOBAL_FUNC);
                                break;
                            case scope_local:
                                ByteWriter_writeByte (byteWriter, BC_LOAD_STACK_FUNC);
                                break;

                            default:
                                puts ("Unusable Register Id!");
                                markTokenError( valueNode->value);
                                exit (1);
                        }
                        ByteWriter_writeUInt (byteWriter, declaration.index);
                        break;
                    default:
                        puts ("Unusable Datatype for variable!");
                        markTokenError( valueNode->value);
                        exit (1);
                        break;
                    }

                    // This is for exporing the type of the complex or function next steps
                    if(declaration.type == type_complex) {
                        returnComplex(declaration);
                    } else if(declaration.type == type_function) {
                        Complex_return = declaration.value;
                    }
                    
                    return declaration.type;
                }

                    break;
                default:
                    markTokenError( valueNode->value);
                    puts ("Unusable value");
                    exit (1);
            }
        }
            break;

        case ID_FunctionCallNode:
        {
            FunctionCallNode functionCallNode = *node.functionCallNode;

            if(functionCallNode.identifier.type == ID_UnaryOpNode) {
                // First get the function name in order to access the required function
                Token name = functionCallNode.identifier.unaryOpNode->operand.valueNode->value;

                unsigned int line_count = name.lineNumber;
                if(DEBUGGING_MODE)
                if(line_count != 0 && codeGenerator->currentLine != line_count) {
                    codeGenerator->currentLine = line_count;
                    char hint[1024] = "";

                    sprintf(hint, "ln;%d", line_count);

                    ByteWriter_writeByte(byteWriter, BC_HINT);
                    unsigned int hint_len = strlen(hint);
                    ByteWriter_writeUInt(byteWriter, hint_len);
                    for(unsigned int i = 0; i < hint_len; ++i) {
                        ByteWriter_writeByte(byteWriter, hint[i]);
                    }
                }

                // Access Function
                Symbol fn = VariableTable_findVariableByName(&codeGenerator->table, name);
                FunctionNode fnNode = *fn.functionDefininiton.functionNode;

                if (fn.type == type_undefined) {
                    puts ("Undefined function!");
                    markTokenError( functionCallNode.identifier.valueNode->value);
                    exit (1);
                }
                if (fn.free_arguments) {
                    puts ("Cannot insert function body with arguments beeing optional.");
                    markTokenError( functionCallNode.identifier.valueNode->value);
                    exit (1);
                }
                if (functionCallNode.numbersOfArguments < fn.argumentsCount) {
                    puts ("To few function-argument!");
                    markTokenError( functionCallNode.identifier.valueNode->value);
                    exit (1);
                }
                if (functionCallNode.numbersOfArguments > fn.argumentsCount) {
                    puts ("To many function-argument!");
                    markTokenError( functionCallNode.identifier.valueNode->value);
                    exit (1);
                }

                unsigned int numberOfReference = 0;
                unsigned int referenceSymbols[255];

                for(unsigned int i = 0; i < functionCallNode.numbersOfArguments; i++) {
                    SyntaxNode argument = functionCallNode.arguments[i];
                    if(argument.type == ID_ValueNode) {
                        ValueNode *argumentValue = argument.valueNode;
                        if(argumentValue->value.type == TT_Identifier) {
                            Token argumentName = argumentValue->value;
                            referenceSymbols[numberOfReference++] = VariableTable_createReferenceByName(&codeGenerator->table, argumentName, fn.arguments[i].name);
                            continue;
                        }
                    }

                    //Symbol argumentSymbol = VariableTable_declareVariable(&codeGenerator->table, fn.arguments[i].name, scope);
                    //unsigned int argumentIndex = VariableTable_defineVariable(&codeGenerator->table, fn.arguments[i].name, typeToStackType (tokenTypeToDataType (fn.arguments[i].type, codeGenerator)));

                    unsigned char argumentType = CodeGenerator_generateExpression(codeGenerator, newBinOpNode(
                        newValueNode(fn.arguments[i].name),
                        (Token) {.type = TT_Equalsign},
                        functionCallNode.arguments[i]
                    ), scope, byteWriter);
                }

                SyntaxNode functionStatements = fn.functionDefininiton.functionNode->statements;

                if(functionStatements.type == ID_ReturnNode) {
                    functionStatements = functionStatements.returnNode->expression;
                }

                unsigned char rType = CodeGenerator_generateStatement(codeGenerator, functionStatements, scope, byteWriter);

                for(unsigned int i = 0; i < numberOfReference; ++i) {
                    VariableTable_removeDeclaration(&codeGenerator->table, referenceSymbols[numberOfReference-i-1u]);
                }

                return rType;
            }

            Token name = functionCallNode.identifier.valueNode->value;

            unsigned int line_count = name.lineNumber;
            if(DEBUGGING_MODE)
            if(line_count != 0 && codeGenerator->currentLine != line_count) {
                codeGenerator->currentLine = line_count;
                char hint[1024] = "";

                sprintf(hint, "ln;%d", line_count);

                ByteWriter_writeByte(byteWriter, BC_HINT);
                unsigned int hint_len = strlen(hint);
                ByteWriter_writeUInt(byteWriter, hint_len);
                for(unsigned int i = 0; i < hint_len; ++i) {
                    ByteWriter_writeByte(byteWriter, hint[i]);
                }
            }

            if (strcmp (name.value.word, "$$printInt$$") == 0) {
                if (functionCallNode.numbersOfArguments < 1) {
                    puts ("Missing integer number as argument!");
                    markTokenError(name);
                    exit (1);
                }
                if (functionCallNode.numbersOfArguments > 1) {
                    puts ("Too many arguments!");
                    markTokenError(name);
                    exit (1);
                }
                SyntaxNode argumentNode = functionCallNode.arguments[0];
                CodeGenerator_generateExpression (codeGenerator, argumentNode, scope, byteWriter);
                ByteWriter_writeByte (byteWriter, BC_PRINT_I);
                return type_none;
            }
            else if (strcmp (name.value.word, "$$printFloat$$") == 0) {
                if (functionCallNode.numbersOfArguments < 1) {
                    puts ("Missing floating point number as argument!");
                    markTokenError(name);
                    exit (1);
                }
                if (functionCallNode.numbersOfArguments > 1) {
                    puts ("Too many arguments!");
                    markTokenError(name);
                    exit (1);
                }
                SyntaxNode argumentNode = functionCallNode.arguments[0];
                CodeGenerator_generateExpression (codeGenerator, argumentNode, scope, byteWriter);
                ByteWriter_writeByte (byteWriter, BC_PRINT_F);
                return type_none;
            }
            else if (strcmp (name.value.word, "$$printUnsigned$$") == 0) {
                if (functionCallNode.numbersOfArguments < 1) {
                    puts ("Missing unsigned integer number as argument!");
                    markTokenError(name);
                    exit (1);
                }
                if (functionCallNode.numbersOfArguments > 1) {
                    puts ("Too many arguments!");
                    markTokenError(name);
                    exit (1);
                }
                SyntaxNode argumentNode = functionCallNode.arguments[0];
                CodeGenerator_generateExpression (codeGenerator, argumentNode, scope, byteWriter);
                ByteWriter_writeByte (byteWriter, BC_PRINT_U);
                return type_none;
            }
            else if (strcmp (name.value.word, "$$newline$$") == 0) {
                if (functionCallNode.numbersOfArguments > 0) {
                    puts ("Too many arguments!");
                    markTokenError(name);
                    exit (1);
                }
                ByteWriter_writeByte (byteWriter, BC_NEWLINE);
                return type_none;
            }
            else if (strcmp (name.value.word, "$$print$$") == 0) {
                if (functionCallNode.numbersOfArguments < 1) {
                    puts ("Missing text as argument!");
                    markTokenError(name);
                    exit (1);
                }
                if (functionCallNode.numbersOfArguments > 1) {
                    puts ("Too many arguments!");
                    markTokenError(name);
                    exit (1);
                }
                SyntaxNode argumentNode = functionCallNode.arguments[0];
                CodeGenerator_generateExpression (codeGenerator, argumentNode, scope, byteWriter);
                ByteWriter_writeByte (byteWriter, BC_PRINT_TEXT);
                return type_none;
            }
            else if (strcmp (name.value.word, "exit") == 0) {
                if (functionCallNode.numbersOfArguments < 1) {
                    puts ("Missing integer number as argument!");
                    markTokenError(name);
                    exit (1);
                }
                if (functionCallNode.numbersOfArguments > 1) {
                    puts ("Too many arguments!");
                    markTokenError(name);
                    exit (1);
                }
                SyntaxNode argumentNode = functionCallNode.arguments[0];
                CodeGenerator_generateExpression (codeGenerator, argumentNode, scope, byteWriter);
                ByteWriter_writeByte (byteWriter, BC_EXIT);
                return type_none;
            }
            else if (strcmp (name.value.word, "output") == 0) {
                for (unsigned int i = 0; i < functionCallNode.numbersOfArguments; i++) {
                    SyntaxNode argumentNode = functionCallNode.arguments[i];
                    unsigned char type = CodeGenerator_generateExpression (codeGenerator, argumentNode, scope, byteWriter);
                    switch (type) {
                        case type_ubyte:
                        case type_ushort:
                        case type_uint:
                        case type_ulong:
                            ByteWriter_writeByte (byteWriter, BC_PRINT_U);
                            break;
                        case type_byte:
                        case type_short:
                        case type_int:
                        case type_long:
                            ByteWriter_writeByte (byteWriter, BC_PRINT_I);
                            break;
                        case type_float:
                        case type_double:
                            ByteWriter_writeByte (byteWriter, BC_PRINT_F);
                            break;
                        
                        case type_complex:
                        case type_text:
                            ByteWriter_writeByte (byteWriter, BC_PRINT_TEXT);
                            break;

                        default:
                            markTokenError(name);
                            puts ("Unsupported Datatype!");
                            exit (1);
                    }
                }
                ByteWriter_writeByte (byteWriter, BC_NEWLINE);
                return type_none;
            }
            else if (strcmp (name.value.word, "$$getUnsigned$$") == 0) {
                if (functionCallNode.numbersOfArguments > 0) {
                    puts ("Too many arguments!");
                    markTokenError(name);
                    exit (1);
                }
                ByteWriter_writeByte (byteWriter, BC_INPUT_U);
                return type_ulong;
            }
            else if (strcmp (name.value.word, "$$getInt$$") == 0) {
                if (functionCallNode.numbersOfArguments > 0) {
                    puts ("Too many arguments!");
                    markTokenError(name);
                    exit (1);
                }
                ByteWriter_writeByte (byteWriter, BC_INPUT_I);
                return type_long;
            }
            else if (strcmp (name.value.word, "$$getFloat$$") == 0) {
                if (functionCallNode.numbersOfArguments > 0) {
                    puts ("Too many arguments!");
                    markTokenError( name);
                    exit (1);
                }
                ByteWriter_writeByte (byteWriter, BC_INPUT_F);
                return type_double;
            }
            else if (strcmp (name.value.word, "$$get$$") == 0) {
                if (functionCallNode.numbersOfArguments > 0) {
                    puts ("Too many arguments!");
                    markTokenError( name);
                    exit (1);
                }
                ByteWriter_writeByte (byteWriter, BC_INPUT_LINE);
                return type_text;
            }
            else if (strcmp (name.value.word, "getch") == 0) {
                if (functionCallNode.numbersOfArguments > 0) {
                    puts ("Too many arguments!");
                    markTokenError( name);
                    exit (1);
                }
                ByteWriter_writeByte (byteWriter, BC_INPUT_CHAR);
                return type_ubyte;
            }
            else if (strcmp (name.value.word, "clock") == 0) {
                if (functionCallNode.numbersOfArguments > 0) {
                    puts ("Too many arguments!");
                    markTokenError( name);
                    exit (1);
                }
                ByteWriter_writeByte (byteWriter, BC_CLOCK);
                return type_ulong;
            }
            else if (strcmp (name.value.word, "time") == 0) {
                if (functionCallNode.numbersOfArguments > 0) {
                    puts ("Too many arguments!");
                    markTokenError( name);
                    exit (1);
                }
                ByteWriter_writeByte (byteWriter, BC_TIME);
                return type_ulong;
            }
            else if (strcmp (name.value.word, "type") == 0) {
                if (functionCallNode.numbersOfArguments < 1) {
                    puts ("Too few arguments!");
                    markTokenError( name);
                    exit (1);
                }
                char* tmptxt = NULL;
                unsigned int tmplen = 0;
                ByteWriter tmpWriter = ByteWriter_init (&tmptxt, &tmplen);
                unsigned char type;
                if(functionCallNode.arguments[0].type == ID_ValueNode)
                    if(functionCallNode.arguments[0].valueNode->value.type == TT_Identifier) {
                        type = VariableTable_findVariableByName(&codeGenerator->table, functionCallNode.arguments[0].valueNode->value).type;
                        if(type == type_complex) {
                            Complex_return = VariableTable_findVariableByName(&codeGenerator->table, functionCallNode.arguments[0].valueNode->value).mothertype;
                        }
                    }
                    else type = CodeGenerator_generateExpression (codeGenerator, functionCallNode.arguments[0], scope, &tmpWriter);
                else type = CodeGenerator_generateExpression (codeGenerator, functionCallNode.arguments[0], scope, &tmpWriter);

                free (tmptxt);
                unsigned int index = 0;
                char* typetxt = NULL;
                switch (type) {
                    case type_ubyte:
                        typetxt = "ubyte";
                        break;
                    case type_ushort:
                        typetxt = "ushort";
                        break;
                    case type_uint:
                        typetxt = "uint";
                        break;
                    case type_ulong:
                        typetxt = "ulong";
                        break;
                    case type_byte:
                        typetxt = "byte";
                        break;
                    case type_short:
                        typetxt = "short";
                        break;
                    case type_int:
                        typetxt = "int";
                        break;
                    case type_long:
                        typetxt = "long";
                        break;
                    case type_float:
                        typetxt = "float";
                        break;
                    case type_double:
                        typetxt = "double";
                        break;
                    case type_text:
                        typetxt = "text";
                        break;
                    case type_function:
                        typetxt = "function";
                        break;
                    case type_Collection:
                        typetxt = "Collection";
                        break;
                    case type_undefined:
                        typetxt = "undefined";
                        break;
                    case type_none:
                        typetxt = "none";
                        break;
                    case type_any:
                        typetxt = "any";
                        break;
                    case type_complex:
                        if(Complex_return.type == TT_Identifier)
                            typetxt = Complex_return.value.word;
                        else
                            typetxt = "undefined";
                        break;
                    default:
                        printf ("Unusable type! Type ID -> %d\n", type);
                        exit (1);
                }

                if (VariableTable_findVariableByName (&codeGenerator->table, 
                    (Token) {.begin = 0, .end = 0, .lineNumber = 0, .type = TT_String, .value.word = typetxt}).type == type_undefined) {

                    VariableTable_declareVariable (&codeGenerator->table, 
                        (Token) {.begin = 0, .end = 0, .lineNumber = 0, .type = TT_String, .value.word = typetxt}, 
                        (Scope) {.rgtr = scope_constant}
                    );
                    index = VariableTable_defineVariable (&codeGenerator->table, 
                        (Token) {.begin = 0, .end = 0, .lineNumber = 0, .type = TT_String, .value.word = typetxt},
                        type_text
                    );
                }
                else {
                    index = VariableTable_findVariableByName (&codeGenerator->table, 
                    (Token) {.begin = 0, .end = 0, .lineNumber = 0, .type = TT_String, .value.word = typetxt}).index;
                }

                ByteWriter_writeByte (byteWriter, BC_LOAD_CONST_TEXT);
                ByteWriter_writeUInt (byteWriter, index);

                return type_text;
            }
            else if (strcmp (name.value.word, "input") == 0) {
                for (unsigned int i = 0; i < functionCallNode.numbersOfArguments; i++) {
                    SyntaxNode argumentNode = functionCallNode.arguments[i];
                    unsigned char type = CodeGenerator_generateExpression (codeGenerator, argumentNode, scope, byteWriter);
                    switch (type) {
                        case type_ubyte:
                        case type_ushort:
                        case type_uint:
                        case type_ulong:
                            ByteWriter_writeByte (byteWriter, BC_PRINT_U);
                            break;
                        case type_byte:
                        case type_short:
                        case type_int:
                        case type_long:
                            ByteWriter_writeByte (byteWriter, BC_PRINT_I);
                            break;
                        case type_float:
                        case type_double:
                            ByteWriter_writeByte (byteWriter, BC_PRINT_F);
                            break;
                        
                        case type_text:
                            ByteWriter_writeByte (byteWriter, BC_PRINT_TEXT);
                            break;

                        default:
                            markTokenError(name);
                            puts ("Unsupported Datatype!");
                            exit (1);
                    }
                }
                ByteWriter_writeByte (byteWriter, BC_INPUT_LINE);
                return type_text;
            }
            else if (strcmp (name.value.word, "fmt") == 0) {
                for (unsigned int i = 0; i < functionCallNode.numbersOfArguments; i++) {
                    SyntaxNode argumentNode = functionCallNode.arguments[i];
                    unsigned char type = CodeGenerator_generateExpression (codeGenerator, argumentNode, scope, byteWriter);
                    switch (type) {
                        case type_ubyte:
                        case type_ushort:
                        case type_uint:
                        case type_ulong:
                            ByteWriter_writeByte (byteWriter, BC_TO_STRING_U);
                            break;
                        case type_byte:
                        case type_short:
                        case type_int:
                        case type_long:
                            ByteWriter_writeByte (byteWriter, BC_TO_STRING_I);
                            break;
                        case type_float:
                        case type_double:
                            ByteWriter_writeByte (byteWriter, BC_TO_STRING_F);
                            break;
                        
                        case type_complex:
                        case type_text:
                            break;

                        default:
                            markTokenError(name);
                            puts ("Unsupported Datatype!");
                            exit (1);
                    }
                    if (i != 0)
                        ByteWriter_writeByte (byteWriter, BC_CONCAT);
                }
                return type_text;
            }
            else if (strcmp (name.value.word, "GLL_LOAD") == 0) {
                // Will handle Library Loading
                if (functionCallNode.numbersOfArguments != 1) {
                    puts ("Missing Path for GLL Library!");
                    markTokenError( name);
                    exit (1);
                }
                
                SyntaxNode libpath = functionCallNode.arguments[0];

                unsigned char type = CodeGenerator_generateExpression (codeGenerator, libpath, scope, byteWriter);
                
                if (type != type_text) {
                    puts ("GLL Library Path must be a text value!");
                    markTokenError( name);
                    exit (1);
                }
                
                ByteWriter_writeByte (byteWriter, BC_GLL_LOAD);

                return type_ushort;
            }
            else if (strcmp (name.value.word, "GLL_SYMBOL") == 0) {
                // Will handle the symbole table for the native Librarys
                if (functionCallNode.numbersOfArguments != 2) {
                    puts ("Wrong Arguments!");
                    markTokenError( name);
                    exit (1);
                }
                
                SyntaxNode libhandle = functionCallNode.arguments[0];
                SyntaxNode symbol = functionCallNode.arguments[1];

                unsigned char libhandle_type = CodeGenerator_generateExpression (codeGenerator, libhandle, scope, byteWriter);
                unsigned char symbol_type = CodeGenerator_generateExpression (codeGenerator, symbol, scope, byteWriter);

                if (libhandle_type != type_ushort) {
                    puts ("GLL Library Handle must be a ushort value!");
                    markTokenError( name);
                    exit (1);
                }

                if (symbol_type != type_text) {
                    puts ("GLL Symbol must be a text value!");
                    markTokenError( name);
                    exit (1);
                }

                ByteWriter_writeByte (byteWriter, BC_GLL_SYMBOL);

                return type_ushort;
            }
            else if (strcmp (name.value.word, "GLL_EXEC") == 0) {
                // Will load a function pointer and executes it with some informations
                if (functionCallNode.numbersOfArguments < 3) {
                    puts ("Too few arguments!");
                    markTokenError( name);
                    exit (1);
                }

                SyntaxNode libhandle = functionCallNode.arguments[0];
                SyntaxNode fnhandle = functionCallNode.arguments[1];
                SyntaxNode rtype = functionCallNode.arguments[2];

                unsigned char libhandle_type = CodeGenerator_generateExpression (codeGenerator, libhandle, scope, byteWriter);
                unsigned char fnhandle_type  = CodeGenerator_generateExpression (codeGenerator, fnhandle, scope, byteWriter);
                unsigned char returnType = type_none;
                if (libhandle_type != type_ushort) {
                    puts ("GLL Library Handle must be a ushort!");
                    markTokenError( name);
                    exit (1);
                }

                if (fnhandle_type != type_ushort) {
                    puts ("GLL Function Handle must be a ushort!");
                    markTokenError( name);
                    exit (1);
                }

                if (rtype.type != ID_ValueNode) {
                    puts ("GLL wrong return type!");
                    markTokenError( name);
                    exit (1);
                }

                switch (rtype.valueNode->value.type) {
                    
                    case TT_Int:
                        if (rtype.valueNode->value.value.i != 0) {
                            puts ("GLL wrong return type!");
                            markTokenError( name);
                            exit (1);
                        }
                        break;

                    default:
                        returnType = tokenTypeToDataType (rtype.valueNode->value, codeGenerator);
                }

                for (unsigned int i = 3; i < functionCallNode.numbersOfArguments; i++) {
                    CodeGenerator_generateExpression (codeGenerator, functionCallNode.arguments[i], scope, byteWriter);
                }

                ByteWriter_writeByte (byteWriter, BC_GLL_EXEC);

                ByteWriter_writeUInt (byteWriter, functionCallNode.numbersOfArguments-3);

                if (returnType == type_none)
                    ByteWriter_writeByte (byteWriter, BC_POP);

                return returnType;
            }
            else if (strcmp (name.value.word, "GLL_CLOSE") == 0) {
                // Will close a native Library while execution

                puts ("Isn't supported by the VM yet!");
                markTokenError( name);
                exit (1);
            }
            else {
                // First we need to make sure enough parameters where given
                //Regulare

                Symbol vardec = (Symbol) {.type = type_undefined};
                {

                    vardec = VariableTable_findVariableByName (&codeGenerator->table, functionCallNode.identifier.valueNode->value);
                }

                if(vardec.type == type_undefined) {
                    char identifier[4096] = "";
                    strcat(identifier, functionCallNode.identifier.valueNode->value.value.word);
                    strcat(identifier, "/");

                    char *before_id = functionCallNode.identifier.valueNode->value.value.word;
                    functionCallNode.identifier.valueNode->value.value.word = copyString(identifier);
                    

                    vardec = VariableTable_findVariableByName (&codeGenerator->table, functionCallNode.identifier.valueNode->value);

                    free(functionCallNode.identifier.valueNode->value.value.word);
                    functionCallNode.identifier.valueNode->value.value.word = before_id;
                }

                if (vardec.type == type_undefined) {

                    char identifier[4096] = "";
                    strcat(identifier, functionCallNode.identifier.valueNode->value.value.word);
                    strcat(identifier, "/");

                    char *arg_writer_buffer = NULL;
                    unsigned int arg_writer_length = 0;
                    ByteWriter arg_writer = ByteWriter_init(&arg_writer_buffer, &arg_writer_length);

                    for (unsigned int i = 0; i < functionCallNode.numbersOfArguments; i++) {
                        unsigned char arg_type = CodeGenerator_generateExpression(codeGenerator, functionCallNode.arguments[i], scope, &arg_writer);
                        switch(arg_type) {
                            case type_text:
                                strcat(identifier, "txt");
                                break;
                            case type_complex:
                                strcat(identifier, Complex_return.value.word);
                                break;
                            case type_Collection:
                                strcat(identifier, "*");
                            default:
                                break;
                        }

                        strcat(identifier, "/");
                    }

                    char *before_id = functionCallNode.identifier.valueNode->value.value.word;
                    functionCallNode.identifier.valueNode->value.value.word = copyString(identifier);
                    

                    vardec = VariableTable_findVariableByName (&codeGenerator->table, functionCallNode.identifier.valueNode->value);

                    // printf("FunctionCall: [%s]. vs. [%s]\n", identifier, functionCallNode.identifier.valueNode->value.value.word);

                    free(functionCallNode.identifier.valueNode->value.value.word);
                    functionCallNode.identifier.valueNode->value.value.word = before_id;

                }
                
                if (vardec.type == type_undefined) {

                    char identifier[4096] = "";
                    strcat(identifier, functionCallNode.identifier.valueNode->value.value.word);
                    strcat(identifier, "/");

                    char *arg_writer_buffer = NULL;
                    unsigned int arg_writer_length = 0;
                    ByteWriter arg_writer = ByteWriter_init(&arg_writer_buffer, &arg_writer_length);

                    for (unsigned int i = 0; i < functionCallNode.numbersOfArguments; i++) {
                        unsigned char arg_type = CodeGenerator_generateExpression(codeGenerator, functionCallNode.arguments[i], scope, &arg_writer);
                        switch(arg_type) {
                            case type_text:
                                strcat(identifier, "txt");
                                break;
                            case type_complex:
                                strcat(identifier, "txt");
                                break;
                            case type_Collection:
                                strcat(identifier, "*");
                            default:
                                break;
                        }

                        strcat(identifier, "/");
                    }

                    char *before_id = functionCallNode.identifier.valueNode->value.value.word;
                    functionCallNode.identifier.valueNode->value.value.word = copyString(identifier);
                    

                    vardec = VariableTable_findVariableByName (&codeGenerator->table, functionCallNode.identifier.valueNode->value);

                    // printf("FunctionCall: [%s]. vs. [%s]\n", identifier, functionCallNode.identifier.valueNode->value.value.word);

                    free(functionCallNode.identifier.valueNode->value.value.word);
                    functionCallNode.identifier.valueNode->value.value.word = before_id;

                }

                if (vardec.type == type_undefined) {
                    puts ("Undefined function!");
                    markTokenError( functionCallNode.identifier.valueNode->value);
                    exit (1);
                }
                if (functionCallNode.numbersOfArguments < vardec.argumentsCount && !vardec.free_arguments) {
                    puts ("To few function-argument!");
                    markTokenError( functionCallNode.identifier.valueNode->value);
                    exit (1);
                }
                if (functionCallNode.numbersOfArguments > vardec.argumentsCount && !vardec.free_arguments) {
                    puts ("To many function-argument!");
                    markTokenError( functionCallNode.identifier.valueNode->value);
                    exit (1);
                }

                // Next we make sure we log the entering of the function for later debugging

                CodeGenerator_generateLogFunctionEnter(codeGenerator, functionCallNode, vardec, scope, byteWriter);
                
                // If arguments are defined as foo(*) than let them all pass
                if(vardec.free_arguments) {

                    ByteWriter_writeByte(byteWriter, BC_BUILD_EMPTYCOLLECTION);
                    unsigned char argt[500];

                    for(unsigned int i = 0; i < functionCallNode.numbersOfArguments; ++i)
                    {
                        argt[i] = typeToStackType (CodeGenerator_generateExpression (codeGenerator, functionCallNode.arguments[i], scope, byteWriter));
                        ByteWriter_writeByte(byteWriter, BC_ADD_ELEMENT);
                    }

                    ByteWriter_writeByte(byteWriter, BC_BUILD_EMPTYCOLLECTION);
                    for(unsigned int i = 0; i < functionCallNode.numbersOfArguments; ++i) {

                        unsigned char indexType = CodeGenerator_generateExpression(codeGenerator, newValueNode((Token) {.type = TT_Uint, .value.u = argt[i]}), scope, byteWriter);
                        ByteWriter_writeByte(byteWriter, BC_ADD_ELEMENT);
                    }
                
                // Otherwise we go through ever single parameter to load it
                } else for (unsigned int i = 0; i < vardec.argumentsCount; i++) {

                    // Next we check which type we would expect
                    unsigned char fntype = typeToStackType (tokenTypeToDataType (vardec.arguments[i].type, codeGenerator));

                    // If the parameter is an array, here we go
                    if (vardec.arguments[i].is_array) {
                        if (functionCallNode.arguments[i].type != ID_ValueNode) {
                            puts ("Missing Array!");
                            markTokenError( functionCallNode.identifier.valueNode->value);
                            exit (1);
                        }
                        Token arrayName = functionCallNode.arguments[i].valueNode->value;
                        if (arrayName.type != TT_Identifier) {
                            puts ("Missing Array!");
                            markTokenError( functionCallNode.identifier.valueNode->value);
                            exit (1);
                        }
                        Symbol array = VariableTable_findVariableByName (&codeGenerator->table, arrayName);
                        if (array.type != type_Collection) {
                            puts ("Missing Array!");
                            markTokenError( functionCallNode.identifier.valueNode->value);
                            exit (1);
                        }
                        if (fntype != array.storingType) {
                            puts ("Wrong Datatype for Array!");
                            markTokenError( functionCallNode.identifier.valueNode->value);
                            exit (1);
                        }
                        if (array.scope.rgtr == scope_local)
                            ByteWriter_writeByte (byteWriter, BC_LOAD_STACK_COLLECTION);
                        else
                            ByteWriter_writeByte (byteWriter, BC_LOAD_GLOBAL_COLLECTION);
                        ByteWriter_writeUInt (byteWriter, array.index);
                        ByteWriter_writeByte (byteWriter, BC_COPY_COLLECTION);
                        if (array.scope.rgtr == scope_local)
                            ByteWriter_writeByte (byteWriter, BC_STORE_STACK_COLLECTION);
                        else
                            ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_COLLECTION);
                        ByteWriter_writeUInt (byteWriter, array.index);
                        
                    }
                    else {

                        // Next we've got simple/complex types
                        unsigned char argtype = typeToStackType (CodeGenerator_generateExpression (codeGenerator, functionCallNode.arguments[i], scope, byteWriter));
                        
                        // Now really make sure they are the type we expected
                        if (argtype != fntype) {
                            switch (fntype) {
                                case type_ulong:
                                    if (argtype == type_long) {
                                        ByteWriter_writeByte (byteWriter, BC_I2U);
                                    }
                                    else if (argtype == type_double) {
                                        ByteWriter_writeByte (byteWriter, BC_F2U);
                                    }
                                    else {
                                        puts ("Wrong Datatype for function-argument!");
                                        markTokenError( functionCallNode.identifier.valueNode->value);
                                        exit (1);
                                    }
                                    break;
                                case type_long:
                                    if (argtype == type_ulong) {
                                        ByteWriter_writeByte (byteWriter, BC_U2I);
                                    }
                                    else if (argtype == type_double) {
                                        ByteWriter_writeByte (byteWriter, BC_F2I);
                                    }
                                    else {
                                        puts ("Wrong Datatype for function-argument!");
                                        markTokenError( functionCallNode.identifier.valueNode->value);
                                        exit (1);
                                    }
                                    break;
                                case type_double:
                                    if (argtype == type_ulong) {
                                        ByteWriter_writeByte (byteWriter, BC_U2F);
                                    }
                                    else if (argtype == type_long) {
                                        ByteWriter_writeByte (byteWriter, BC_I2F);
                                    }
                                    else {
                                        puts ("Wrong Datatype for function-argument!");
                                        markTokenError( functionCallNode.identifier.valueNode->value);
                                        exit (1);
                                    }
                                    break;
                                case type_text:
                                    if(argtype == type_complex) {
                                        // Its ok
                                    } else {
                                        puts ("Wrong Datatype for function-argument!");
                                        markTokenError( functionCallNode.identifier.valueNode->value);
                                        exit (1);
                                    }
                                    break;
                                case type_Collection:
                                    puts ("Wrong Datatype for function-argument!");
                                    markTokenError( functionCallNode.identifier.valueNode->value);
                                    exit (1);
                                    break;
                                case type_complex:
                                    if(argtype == type_text) {
                                        // Its ok
                                        if(vardec.arguments[i].type.type == TT_Identifier)
                                            Complex_return = vardec.arguments[i].type;
                                    } else {
                                        puts ("Wrong Datatype for function-argument!");
                                        markTokenError( functionCallNode.identifier.valueNode->value);
                                        exit (1);
                                    }
                                    break;
                            }
                        }

                        // now after we loaded the current argument, we now have also to make
                        // sure that if it's an complex, it has the right token for it

                        if(argtype == type_complex && fntype == type_complex) {
                            if(vardec.arguments[i].type.type == TT_Identifier && Complex_return.type == TT_Identifier)
                            if(strcmp(vardec.arguments[i].type.value.word, Complex_return.value.word) != 0) {
                                    puts ("Wrong Datatype for function-argument!");
                                    puts ("Expected a table class of:");
                                    puts (vardec.arguments[i].type.value.word);
                                    markTokenError( functionCallNode.identifier.valueNode->value);
                                    exit (1);
                            }
                        }
                    }
                }

                // Load the function to be callen (We need it on the stack first)
                switch(vardec.scope.rgtr) {
                    case scope_global:
                        ByteWriter_writeByte (byteWriter, BC_LOAD_GLOBAL_FUNC);
                        break;
                    case scope_local:
                        ByteWriter_writeByte (byteWriter, BC_LOAD_STACK_FUNC);
                        break;
                    case scope_constant:
                        ByteWriter_writeByte (byteWriter, BC_LOAD_CONST_FUNC);
                        break;
                }
                ByteWriter_writeUInt (byteWriter, vardec.index);
                
                ByteWriter_writeByte (byteWriter, BC_CALL_FUNC);
                if(vardec.free_arguments)
                    ByteWriter_writeUInt(byteWriter, 2);
                else
                    ByteWriter_writeUInt(byteWriter, functionCallNode.numbersOfArguments);
                if (vardec.returnType == type_none)
                    ByteWriter_writeByte (byteWriter, BC_POP);
                CodeGenerator_generateLogFunctionLeave(codeGenerator, functionCallNode, vardec, scope, byteWriter);

                if(DEBUGGING_MODE)
                if(line_count != 0 && codeGenerator->currentLine != line_count) {
                    codeGenerator->currentLine = line_count;
                    char hint[1024] = "";

                    sprintf(hint, "ln;%d", line_count);

                    ByteWriter_writeByte(byteWriter, BC_HINT);
                    unsigned int hint_len = strlen(hint);
                    ByteWriter_writeUInt(byteWriter, hint_len);
                    for(unsigned int i = 0; i < hint_len; ++i) {
                        ByteWriter_writeByte(byteWriter, hint[i]);
                    }
                }

                // Make sure to return the complex type
                if(vardec.mothertype.type != TT_None) {
                    if(strcmp(vardec.mothertype.value.word, "table") == 0)
                        Complex_return = vardec.value;
                    else
                        returnComplex(vardec);
                }

                return vardec.returnType;
            }
            puts ("No matching Function!");
        }
            break;

        case ID_SquareCallNode:
        {
            SquareCallNode squareCallNode = *node.squareCallNode;
            Token name = squareCallNode.identifier.valueNode->value;

            unsigned int line_count = name.lineNumber;
            if(DEBUGGING_MODE)
            if(line_count != 0 && codeGenerator->currentLine != line_count) {
                codeGenerator->currentLine = line_count;
                char hint[1024] = "";

                sprintf(hint, "ln;%d", line_count);

                ByteWriter_writeByte(byteWriter, BC_HINT);
                unsigned int hint_len = strlen(hint);
                ByteWriter_writeUInt(byteWriter, hint_len);
                for(unsigned int i = 0; i < hint_len; ++i) {
                    ByteWriter_writeByte(byteWriter, hint[i]);
                }
            }

            Symbol variable = VariableTable_findVariableByName (&codeGenerator->table, name);

            if (squareCallNode.numbersOfArguments == 0) {
                puts ("No given index!");
                markTokenError( name);
                exit (1);
            }

            if (variable.scope.rgtr == scope_local) {
                ByteWriter_writeByte (byteWriter, BC_LOAD_STACK_COLLECTION);
            } else {
                ByteWriter_writeByte (byteWriter, BC_LOAD_GLOBAL_COLLECTION);
            }
            ByteWriter_writeUInt (byteWriter, variable.index);
            
            unsigned char type = CodeGenerator_generateExpression (codeGenerator, squareCallNode.arguments[0], scope, byteWriter);

            if(typeToStackType(type) == type_long) {
                ByteWriter_writeByte(byteWriter, BC_I2U);
            } else if (typeToStackType(type) == type_double) {
                ByteWriter_writeByte(byteWriter, BC_F2U);
            } else if (typeToStackType(type) != type_ulong) {
                puts ("Accessing an array requires a number!");
                markTokenError( squareCallNode.identifier.valueNode->value);
                exit (1);
            }

            ByteWriter_writeByte (byteWriter, BC_LOAD_ELEMENT);
            if (variable.scope.rgtr == scope_local) {
                ByteWriter_writeByte (byteWriter, BC_STORE_STACK_COLLECTION);
            } else {
                ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_COLLECTION);
            }
            ByteWriter_writeUInt (byteWriter, variable.index);

            if(variable.storingType == type_function || variable.storingType == type_complex)
                Complex_return = variable.mothertype;
            return variable.storingType;
        }
            break;

        case ID_None:
            return type_none; 
            break;
        default:
            // Should never be called.
            printf ("ID => %u\n", node.type);
            puts ("Error in Expression!");
            exit (1);
    }
    return type_none;
}

unsigned char CodeGenerator_storeSymbol(CodeGenerator* codeGenerator, Symbol variable, unsigned char type, Scope scope, ByteWriter* byteWriter) {
    if (variable.type == type_undefined) {
        return type_undefined;
    }
    else {
        switch (variable.type) {
            case type_ubyte:
            case type_ushort:
            case type_uint:
            case type_ulong:
                // unsigned integer
                switch (type) {
                    case type_byte:
                    case type_short:
                    case type_int:
                    case type_long:
                        ByteWriter_writeByte (byteWriter, BC_I2U);
                        type = type_ulong;
                        break;
                    case type_float:
                    case type_double:
                        ByteWriter_writeByte (byteWriter, BC_F2U);
                        type = type_ulong;
                        break;
                }
                break;
            case type_byte:
            case type_short:
            case type_int:
            case type_long:
                // integer
                switch (type) {
                    case type_ubyte:
                    case type_ushort:
                    case type_uint:
                    case type_ulong:
                        ByteWriter_writeByte (byteWriter, BC_U2I);
                        type = type_long;
                        break;
                    case type_float:
                    case type_double:
                        ByteWriter_writeByte (byteWriter, BC_F2I);
                        type = type_long;
                        break;
                }
                break;
            case type_float:
            case type_double:
                switch (type) {
                    case type_ubyte:
                    case type_ushort:
                    case type_uint:
                    case type_ulong:
                        ByteWriter_writeByte (byteWriter, BC_U2F);
                        type = type_double;
                        break;
                    case type_byte:
                    case type_short:
                    case type_int:
                    case type_long:
                        ByteWriter_writeByte (byteWriter, BC_I2F);
                        type = type_double;
                        break;
                }
                break;
        }

        // depending on the register writing a store operator
        switch (variable.scope.rgtr) {
            case scope_global:
                switch (variable.type) {
                    case type_ubyte:
                    case type_byte:
                        ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_NUM8);
                        break;
                    case type_ushort:
                    case type_short:
                        ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_NUM16);
                        break;
                    case type_uint:
                    case type_int:
                    case type_float:
                        if (type == type_double || type == type_float) {
                            ByteWriter_writeByte (byteWriter, BC_Double2Float);
                        }
                        ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_NUM32);
                        break;
                    case type_ulong:
                    case type_long:
                    case type_double:
                        ByteWriter_writeByte (byteWriter, BC_STORE_GLOBAL_NUM64);
                        break;
                    default:
                        markTokenError( variable.value);
                        switch (variable.value.type) {
                            case TT_String:
                                printf ("Problem with Variable: %s\n", variable.value.value.word);
                                break;
                            case TT_Int:
                                printf ("Problem with Variable: %lld\n", variable.value.value.i);
                                break;
                            case TT_Uint:
                                printf ("Problem with Variable: %llu\n", variable.value.value.u);
                                break;
                            case TT_Float:
                                printf ("Problem with Variable: %lf\n", variable.value.value.f);
                                break;
                            default: puts ("Something went wrong...");
                        }
                        switch (variable.scope.rgtr) {
                            case scope_constant:
                                puts ("Scope: Constant");
                                break;
                            case scope_global:
                                puts ("Scope: Global");
                                break;
                            case scope_local:
                                printf ("Scope: Local, in Function: %s\n", variable.scope.function.value.word);
                                break;
                            case scope_undefined:
                                puts ("Undefined");
                                break;
                            default:;
                        }
                        puts ("This kind of type isn't supported yet!");
                        exit (1);
                }
                break;
            case scope_local:
                switch (variable.type) {
                    case type_ubyte:
                    case type_byte:
                        ByteWriter_writeByte (byteWriter, BC_STORE_STACK_NUM8);
                        break;
                    case type_ushort:
                    case type_short:
                        ByteWriter_writeByte (byteWriter, BC_STORE_STACK_NUM16);
                        break;
                    case type_uint:
                    case type_int:
                    case type_float:
                        if (type == type_float || type == type_double) {
                            ByteWriter_writeByte (byteWriter, BC_Double2Float);
                        }
                        ByteWriter_writeByte (byteWriter, BC_STORE_STACK_NUM32);
                        break;
                    case type_ulong:
                    case type_long:
                    case type_double:
                        ByteWriter_writeByte (byteWriter, BC_STORE_STACK_NUM64);
                        break;
                    default:
                        markTokenError( variable.value);
                        switch (variable.value.type) {
                            case TT_String:
                                printf ("Problem with Variable: %s\n", variable.value.value.word);
                                break;
                            case TT_Int:
                                printf ("Problem with Variable: %lld\n", variable.value.value.i);
                                break;
                            case TT_Uint:
                                printf ("Problem with Variable: %llu\n", variable.value.value.u);
                                break;
                            case TT_Float:
                                printf ("Problem with Variable: %lf\n", variable.value.value.f);
                                break;
                            default: puts ("Something went wrong...");
                        }
                        switch (variable.scope.rgtr) {
                            case scope_constant:
                                puts ("Scope: Constant");
                                break;
                            case scope_global:
                                puts ("Scope: Global");
                                break;
                            case scope_local:
                                printf ("Scope: Local, in Function: %s\n", variable.scope.function.value.word);
                                break;
                            case scope_undefined:
                                puts ("Undefined");
                                break;
                            default:;
                        }
                        puts ("This kind of type isn't supported yet!");
                        exit (1);
                }
                break;
            default:
                return type;
        }
        ByteWriter_writeUInt (byteWriter, variable.index);
        return type_none;
    }
}


Symbol VariableTable_declareVariable (SymbolTable* table, Token value, Scope scope) {
    Symbol* vardec = VariableTable_addDeclaration (table);
    vardec->value = value;
    vardec->scope = scope;
    vardec->type = type_none;
    vardec->index = 0;        // Because the type is none, the index has no meaning => Null
    return *vardec;
}

unsigned int VariableTable_defineVariable (SymbolTable* table, Token name, unsigned char type) {
    unsigned int index;

    Symbol vardec = VariableTable_findVariableByName (table, name);
    switch (vardec.scope.rgtr) {
        case scope_constant:
            switch (type) {
                case type_ubyte:
                case type_byte:
                    index = table->memoryDeclaration.const_num8s++;
                    break;

                case type_short:
                case type_ushort:
                    index = table->memoryDeclaration.const_num16s++;
                    break;

                case type_uint:
                case type_int:
                case type_float:
                    index = table->memoryDeclaration.const_num32s++;
                    break;
                
                case type_ulong:
                case type_long:
                case type_double:
                    index = table->memoryDeclaration.const_num64s++;
                    break;
                
                case type_function:
                    index = table->memoryDeclaration.const_functions++;
                    break;
                
                case type_complex:
                case type_text:
                    index = table->memoryDeclaration.const_texts++;
                    break;
                default:
                    puts ("Unusable Datatype!");
                    exit (1);
            }
            break;
        case scope_global:
            switch (type) {
                case type_ubyte:
                case type_byte:
                    index = table->memoryDeclaration.global_num8s++;
                    break;

                case type_short:
                case type_ushort:
                    index = table->memoryDeclaration.global_num16s++;
                    break;

                case type_uint:
                case type_int:
                case type_float:
                    index = table->memoryDeclaration.global_num32s++;
                    break;
                
                case type_ulong:
                case type_long:
                case type_double:
                    index = table->memoryDeclaration.global_num64s++;
                    break;
                
                case type_function:
                    index = table->memoryDeclaration.global_functions++;
                    break;
                
                case type_complex:
                case type_text:
                    index = table->memoryDeclaration.global_texts++;
                    break;

                case type_Collection:
                    index = table->memoryDeclaration.global_collections++;
                    break;
            }
            break;
        case scope_local:
        {
            Symbol function = VariableTable_findVariableByName (table, vardec.scope.function);
            switch (type) {
                case type_ubyte:
                case type_byte:
                    index = function.memoryDeclaration.num8s++;
                    break;

                case type_short:
                case type_ushort:
                    index = function.memoryDeclaration.num16s++;
                    break;

                case type_uint:
                case type_int:
                case type_float:
                    index = function.memoryDeclaration.num32s++;
                    break;
                
                case type_ulong:
                case type_long:
                case type_double:
                    index = function.memoryDeclaration.num64s++;
                    break;
                
                case type_function:
                    index = function.memoryDeclaration.functions++;
                    break;
                
                case type_complex:
                case type_text:
                    index = function.memoryDeclaration.texts++;
                    break;

                case type_Collection:
                    index = function.memoryDeclaration.collections++;
                    break;
            }
            VariableTable_setVariableByName (table, function.value, function);
        }
            break;
        default:
            puts ("Illegal Scope!");
            exit (1);
            break;
    }

    vardec.index = index;
    vardec.type = type;

    VariableTable_setVariableByName (table, vardec.value, vardec);

    return index;
}

Symbol VariableTable_findVariableByName (SymbolTable* table, Token value) {
    for (unsigned int i = 0; i < table->numberOfDeclarations; i++) {
        Symbol* variable = &table->declarations[i];
        if (variable->value.type != value.type)
            continue;
        switch (variable->value.type) {
            case TT_Identifier:
            case TT_String:
                if (strcmp (variable->value.value.word, value.value.word) != 0)
                    continue;
                break;
            case TT_Int:
            case TT_Uint:
            case TT_Float:
                if (variable->value.value.u != value.value.u)
                    continue;
                break;
        }
        return *variable;
    }
    return (Symbol) {
        .type = type_undefined
    };
}

Symbol* VariableTable_findVariableReferenceByName (SymbolTable* table, Token value) {
    for (unsigned int i = 0; i < table->numberOfDeclarations; i++) {
        Symbol* variable = &table->declarations[i];
        if (variable->value.type != value.type)
            continue;
        switch (variable->value.type) {
            case TT_Identifier:
            case TT_String:
                if (strcmp (variable->value.value.word, value.value.word) != 0)
                    continue;
                break;
            case TT_Int:
            case TT_Uint:
            case TT_Float:
                if (variable->value.value.u != value.value.u)
                    continue;
                break;
        }
        return variable;
    }
    puts ("Cannot find reference to variable!");
    exit (1);
}

Symbol VariableTable_findVariableByIndex (SymbolTable* table, unsigned int index, unsigned char type, Scope scope) {
    for (unsigned int i = 0; i < table->numberOfDeclarations; i++) {
        Symbol* variable = &table->declarations[i];
        if (variable->type != type)
            continue;
        if (variable->index != index)
            continue;
        if (variable->scope.rgtr != scope.rgtr)
            continue;
        if (variable->scope.rgtr == scope_local)
            if (strcmp (variable->scope.function.value.word, scope.function.value.word) != 0)
                continue;
        return *variable;
    }
    return (Symbol) {
        .type = type_undefined
    };
}

Symbol VariableTable_findConstantByIndex (struct SymbolTable* table, unsigned int index, unsigned char type) {
    for (unsigned int i = 0; i < table->numberOfDeclarations; i++) {
        Symbol* variable = &table->declarations[i];
        if (variable->index != index)
            continue;
        if (variable->scope.rgtr != scope_constant)
            continue;
        
        if ( (type == type_ubyte || type == type_byte) && (variable->type == type_ubyte || variable->type == type_byte)) {
            return *variable;
        }
        else if ( (type == type_ushort || type == type_short) && (variable->type == type_ushort || variable->type == type_short)) {
            return *variable;
        }
        else if ( (type == type_uint || type == type_int || type == type_float) && (variable->type == type_uint || variable->type == type_int || variable->type == type_float)) {
            return *variable;
        }
        else if ( (type == type_ulong || type == type_long || type == type_double) && (variable->type == type_ulong || variable->type == type_long || variable->type == type_double)) {
            return *variable;
        }
        else if (variable->type == type) {
            return *variable;
        }
    }
    puts ("Error! Something went wrong with the constants");
    exit (1);
}

// Will allocate one place for one variable declaration and returns a reference to define it
Symbol* VariableTable_addDeclaration (SymbolTable* table) {
    table->numberOfDeclarations++;
    table->declarations = (Symbol*) realloc (table->declarations, sizeof (Symbol) * table->numberOfDeclarations);
    if (!table->declarations) {
        puts ("Out of Memory!");
        exit (1);
    }

    table->declarations[table->numberOfDeclarations-1] = (Symbol) {
        .index = 0,
        .scope = (Scope) {.rgtr = scope_undefined},
        .type = 0,
        .value = (Token) {
            .begin = 0,
            .end = 0,
            .lineNumber = 0,
            .type = 0,
            .value = 0
        },
        .code = NULL,
        .codelength = 0,
        .argumentsCount = 0,
        .memoryDeclaration.collections = 0,
        .memoryDeclaration.functions = 0,
        .memoryDeclaration.num16s = 0,
        .memoryDeclaration.num32s = 0,
        .memoryDeclaration.num64s = 0,
        .memoryDeclaration.num8s = 0,
        .memoryDeclaration.texts = 0,

        .returnType = type_none,
        .returnType_isArray = 0,
        .is_argument = 0,
        .argument_index = 0,
        .mothertype = (Token) {.type = TT_None},

        .is_extern = 0,
        .functionDefininiton = (SyntaxNode) {.type = ID_None}
    };
    return &table->declarations[table->numberOfDeclarations-1];
}

void VariableTable_removeAllLocal (SymbolTable* table) {
    for (int i = 0; i < table->numberOfDeclarations; i++) {
        Symbol var = table->declarations[i];
        if (var.scope.rgtr == scope_local) {
            VariableTable_removeDeclaration (table, i--);
        }
    }
}

void VariableTable_listAll (SymbolTable* table) {
    puts ("\n### Symbol Table ###\n");
    for (unsigned int i = 0; i < table->numberOfDeclarations; i++) {
        Symbol var = table->declarations[i];
        printf ("name/value: ");
        switch (var.value.type) {
            case TT_Identifier:
                printf ("%-30s ", var.value.value.word);
                break;
            case TT_String:
                printf ("<str>%-25s ", var.value.value.word);
                break;
            case TT_Int:
                printf ("%-30lld ", var.value.value.i);
                break;
            case TT_Uint:
                printf ("%-30llu ", var.value.value.u);
                break;
            case TT_Float:
                printf ("%-31.10lf ", var.value.value.f);
                break;
        }
        printf ("type: %-10u scope: %-10u index: %-10u length: %-10u\n", var.type, var.scope.rgtr, var.index, var.codelength);
    }
    puts ("");
}

void VariableTable_removeDeclaration (SymbolTable* table, unsigned int index) {
    table->numberOfDeclarations--;
    Symbol* newList = (Symbol*) malloc (sizeof (Symbol) * table->numberOfDeclarations);
    if (!newList) {
        puts ("Out of Memory!");
        exit (1);
    }
    for (unsigned int i = 0; i < index; i++)
        newList[i] = table->declarations[i];

    for (unsigned int i = index + 1; i < table->numberOfDeclarations + 1; i++) {
        newList[i - 1] = table->declarations[i];
    }

    free (table->declarations);
    table->declarations = newList;
}

void VariableTable_setVariableByName (SymbolTable* table, Token value, Symbol vardec) {
    for (unsigned int i = 0; i < table->numberOfDeclarations; i++) {
        Symbol* variable = &table->declarations[i];
        if (variable->value.type != value.type)
            continue;
        switch (variable->value.type) {
            case TT_Identifier:
            case TT_String:
                if (strcmp (variable->value.value.word, value.value.word) != 0)
                    continue;
                break;
            case TT_Int:
            case TT_Uint:
            case TT_Float:
                if (variable->value.value.u != value.value.u)
                    continue;
                break;
        }
        *variable = vardec;
        return;
    }
    puts ("Cannot find reference to variable!");
    exit (1);
}

unsigned int VariableTable_createReferenceByName(struct SymbolTable* table, struct Token value, struct Token refName) {
    for (unsigned int i = 0; i < table->numberOfDeclarations; i++) {
        Symbol* variable = &table->declarations[i];
        if (variable->value.type != value.type)
            continue;
        switch (variable->value.type) {
            case TT_Identifier:
            case TT_String:
                if (strcmp (variable->value.value.word, value.value.word) != 0)
                    continue;
                break;
            case TT_Int:
            case TT_Uint:
            case TT_Float:
                if (variable->value.value.u != value.value.u)
                    continue;
                break;
        }
        Symbol* ref = VariableTable_addDeclaration(table);
        *ref = table->declarations[i];
        ref->value = refName;
        return table->numberOfDeclarations-1;
    }
    puts ("Cannot find reference to variable!");
    exit (1);
}

void VariableTable_setConstantByIndex (SymbolTable* table, unsigned int index, unsigned char type, Symbol vardec) {
    for (unsigned int i = 0; i < table->numberOfDeclarations; i++) {
        Symbol* variable = &table->declarations[i];
        if (variable->index != index)
            continue;
        if ( (type == type_ubyte || type == type_byte) && (variable->type == type_ubyte || variable->type == type_byte)) {
            *variable = vardec;
            return;
        }
        else if ( (type == type_ushort || type == type_short) && (variable->type == type_ushort || variable->type == type_short)) {
            *variable = vardec;
            return;
        }
        else if ( (type == type_uint || type == type_int || type == type_float) && (variable->type == type_uint || variable->type == type_int || variable->type == type_float)) {
            *variable = vardec;
            return;
        }
        else if ( (type == type_ulong || type == type_long || type == type_double) && (variable->type == type_ulong || variable->type == type_long || variable->type == type_double)) {
            *variable = vardec;
            return;
        }
        else if (variable->type == type) {
            *variable = vardec;
            return;
        }
    }
    puts ("No declaration found!");
    exit (1);
}

#endif
