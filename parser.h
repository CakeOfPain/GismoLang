#ifndef parser_h
#define parser_h

#include <ctype.h>

enum NodeTypes {
    ID_None,

    // Expressions:
    ID_BinOpNode,
    ID_UnaryOpNode,
    ID_ValueNode,
    ID_FunctionCallNode,
    ID_SquareCallNode,

    // Statements:
    ID_IfNode,
    ID_ForNode,
    ID_StatementsNode,
    ID_ReturnNode,

    // Program:
    ID_FunctionNode,
    ID_ArgumentNode,
    ID_VanguardNode,
    ID_Include,
    ID_ProgramsNode,
    ID_UnaryInstructionNode
};

typedef struct SyntaxNode {
    unsigned char type;
    // All different kinds of Nodes will be here represented:
    union {
        struct BinOpNode* binOpNode;
        struct UnaryOpNode* unaryOpNode;
        struct ValueNode* valueNode;
        struct FunctionCallNode* functionCallNode;
        struct SquareCallNode* squareCallNode;

        struct FunctionNode* functionNode;
        struct IfNode* ifNode;
        struct ForNode* forNode;
        struct StatementsNode* statementsNode;
        struct ReturnNode* returnNode;
        struct ArgumentNode* argumentNode;
        struct VanguardNode* vanguardNode;
        struct IncludeNode* includeNode;
        struct ProgramsNode* programsNode;
        struct UnaryInstructionNode* unaryInstructionNode;
    };
} SyntaxNode;

typedef struct BinOpNode {
    SyntaxNode left;
    Token operator;
    SyntaxNode right;
} BinOpNode;

typedef struct UnaryOpNode {
    Token operator;
    SyntaxNode operand;
} UnaryOpNode;

typedef struct ValueNode {
    Token value;
} ValueNode;


typedef struct FunctionNode {
    SyntaxNode arguments;
    SyntaxNode statements;
    Token name;
    Token returnType;
    unsigned char returns_array;
} FunctionNode;

typedef struct IfNode {
    SyntaxNode statements;
    SyntaxNode elseStatements;
    SyntaxNode condition;
    Token ifWord;
} IfNode;

typedef struct ForNode {
    Token forWord;
    SyntaxNode statements;
    SyntaxNode init;
    SyntaxNode condition;
    SyntaxNode action;
} ForNode;

typedef struct StatementsNode {
    SyntaxNode first;
    SyntaxNode second;
} StatementsNode;

typedef struct ReturnNode {
    Token returnWord;
    SyntaxNode expression;
} ReturnNode;

typedef struct UnaryInstructionNode {
    Token instruction;
} UnaryInstructionNode;

typedef struct ArgumentNode {
    Token type;
    Token name;
    SyntaxNode next;
    unsigned char is_array;
} ArgumentNode;

typedef struct VanguardNode {
    SyntaxNode functionDeclaration;
} VanguardNode;

typedef struct ProgramsNode {
    SyntaxNode* declarations;
    unsigned int size;
} ProgramsNode;

typedef struct IncludeNode {
    Token includeNode;
    Token library;
    Token declaration;
    Token identifier;
} IncludeNode;

typedef struct FunctionCallNode {
    SyntaxNode identifier;
    unsigned int numbersOfArguments;
    SyntaxNode* arguments;
} FunctionCallNode;

typedef struct SquareCallNode {
    SyntaxNode identifier;
    unsigned int numbersOfArguments;
    SyntaxNode* arguments;
} SquareCallNode;

typedef struct Parser {
    Tokenizer* tokenizer;
    unsigned int pos;
    SyntaxNode ast;
    unsigned int numberOfLibrarys;
    char* librarys[600];
} Parser;

// null protected
char* strconcat(const char *s1, const char *s2)
{
	char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

Parser Parser_build(Tokenizer* tokenizer) {
    Parser parser = (Parser) {
        .pos = 0,
        .tokenizer = tokenizer,
        .ast.type = ID_None,
        .numberOfLibrarys = 0
    };

    parser.ast = Parser_parse(&parser);
    return parser;
}

void Parser_clear(Parser parser) {
    SyntaxNode ast = parser.ast;
    Parser_clearAST(ast);
}

Token Parser_peekLastToken(Parser* parser) {
    if(parser->pos == 0) {
        return (Token) {
            .type = TT_End, .begin = strlen(parser->tokenizer->code)+1, 
            .end = strlen(parser->tokenizer->code), .lineNumber = parser->tokenizer->line
        };
    }
    return parser->tokenizer->tokens[parser->pos-1];
}

Token Parser_nextToken(Parser* parser) {
    if(parser->pos >= parser->tokenizer->length) {
        parser->pos++;
        return (Token) {
            .type = TT_End, .begin = strlen(parser->tokenizer->code)-1, 
            .end = strlen(parser->tokenizer->code), .lineNumber = parser->tokenizer->line
        };
    }
    return parser->tokenizer->tokens[parser->pos++];
}

Token Parser_peekNextToken(Parser* parser) {
    if(parser->pos >= parser->tokenizer->length)
        return (Token) {
            .type = TT_End, .begin = strlen(parser->tokenizer->code)-1, 
            .end = strlen(parser->tokenizer->code), .lineNumber = parser->tokenizer->line
        };
    return parser->tokenizer->tokens[parser->pos];
}

Token Parser_peekTwiceNextToken(Parser* parser) {
    if((parser->pos+1) >= parser->tokenizer->length)
        return (Token) {
            .type = TT_End, .begin = strlen(parser->tokenizer->code)-1, 
            .end = strlen(parser->tokenizer->code), .lineNumber = parser->tokenizer->line
        };
    return parser->tokenizer->tokens[parser->pos+1];
}

int stricmp (const char *p1, const char *p2)
{
  register unsigned char *s1 = (unsigned char *) p1;
  register unsigned char *s2 = (unsigned char *) p2;
  unsigned char c1, c2;

  do
  {
      c1 = (unsigned char) toupper((int)*s1++);
      c2 = (unsigned char) toupper((int)*s2++);
      if (c1 == '\0')
      {
	        return c1 - c2;
      }
  }
  while (c1 == c2);

  return c1 - c2;
}


void Parser_addLibPath(Parser* parser, char* path) {
    for(unsigned int i = 0; i < parser->numberOfLibrarys; i++) {
        if(stricmp(path, parser->librarys[i]) == 0)
            return;
    }
    parser->librarys[parser->numberOfLibrarys++] = path;
}

// Expressions:

SyntaxNode newBinOpNode(SyntaxNode left, Token operator, SyntaxNode right) {
    BinOpNode* binOpNode = (BinOpNode*) malloc(sizeof(BinOpNode));
    if(!binOpNode)
        puts("Out of Memory!"),
        exit(1);
    binOpNode->left = left;
    binOpNode->right = right;
    binOpNode->operator = operator;
    return (SyntaxNode) {
        .type = ID_BinOpNode,
        .binOpNode = binOpNode
    };
}

SyntaxNode newUnaryOpNode(Token operator, SyntaxNode operand) {
    UnaryOpNode* unaryOpNode =  (UnaryOpNode*) malloc(sizeof(UnaryOpNode));
    if(!unaryOpNode)
        puts("Out of Memory!"),
        exit(1);
    unaryOpNode->operator = operator;
    unaryOpNode->operand = operand;
    return (SyntaxNode) {
        .type = ID_UnaryOpNode,
        .unaryOpNode = unaryOpNode
    };
}

SyntaxNode newValueNode(Token value) {
    ValueNode* intNode = (ValueNode*) malloc(sizeof(ValueNode));
    if(!intNode)
        puts("Out of Memory!"),
        exit(1);
    intNode->value = value;
    return (SyntaxNode) {
        .type = ID_ValueNode,
        .valueNode = intNode
    };
}


SyntaxNode newFunctionNode(SyntaxNode arguments, SyntaxNode statements, Token name, Token returnType, unsigned char returns_array) {
    FunctionNode* functionNode = (FunctionNode*) malloc(sizeof(FunctionNode));
    if(!functionNode) {
        puts("Out of Memory!");
        exit(1);
    }
    functionNode->arguments = arguments;
    functionNode->name = name;
    functionNode->statements = statements;
    functionNode->returnType = returnType;
    functionNode->returns_array = returns_array;
    return (SyntaxNode) {
        .functionNode = functionNode,
        .type = ID_FunctionNode
    };
}

SyntaxNode newIfNode(SyntaxNode statements, SyntaxNode elseStatements, SyntaxNode condition, Token iftoken) {
    IfNode* ifNode = (IfNode*) malloc(sizeof(IfNode));
    if(!ifNode) {
        puts("Out of Memory!");
        exit(1);
    }
    ifNode->statements = statements;
    ifNode->elseStatements = elseStatements;
    ifNode->condition = condition;
    ifNode->ifWord = iftoken;
    return (SyntaxNode) {
        .type = ID_IfNode,
        .ifNode = ifNode
    };
}

SyntaxNode newForNode(Token forWord, SyntaxNode statements, SyntaxNode init, SyntaxNode condition, SyntaxNode action) {
    ForNode* forNode = (ForNode*) malloc(sizeof(ForNode));
    if(!forNode) {
        puts("Out of Memory!");
        exit(1);
    }
    forNode->forWord = forWord;
    forNode->statements = statements;
    forNode->init = init;
    forNode->condition = condition;
    forNode->action = action;

    return (SyntaxNode) {
        .type = ID_ForNode,
        .forNode = forNode
    };
}

SyntaxNode newStatementsNode(SyntaxNode first, SyntaxNode second) {
    StatementsNode* statementsNode = (StatementsNode*) malloc(sizeof(StatementsNode));
    if(!statementsNode) {
        puts("Out of Memory!");
        exit(1);
    }
    statementsNode->first = first;
    statementsNode->second = second;
    return (SyntaxNode) {
        .type = ID_StatementsNode,
        .statementsNode = statementsNode
    };
}

SyntaxNode newIncludeNode(Token includeToken, Token declaration, Token library, Token identifier) {
    IncludeNode *includeNode = (IncludeNode*) malloc(sizeof(IncludeNode));
    if(!includeNode) {
        puts("Out of Memory!");
        exit(1);
    }
    includeNode->includeNode = includeToken;
    includeNode->declaration = declaration;
    includeNode->library = library;
    includeNode->identifier = identifier;

    return (SyntaxNode) {
        .type = ID_Include,
        .includeNode = includeNode
    };
}

SyntaxNode newReturnNode(Token returnWord, SyntaxNode expression) {
    ReturnNode* returnNode = (ReturnNode*) malloc(sizeof(ReturnNode));
    if(!returnNode) {
        puts("Out of Memory!");
        exit(1);
    }
    returnNode->returnWord = returnWord;
    returnNode->expression = expression;
    return (SyntaxNode) {
        .type = ID_ReturnNode,
        .returnNode = returnNode
    };
}

SyntaxNode newUnaryInstructionNode (Token instruction) {
    UnaryInstructionNode* instructionNode = (UnaryInstructionNode*) malloc(sizeof(UnaryInstructionNode));
    if (!instructionNode) {
        puts ("Out of Memory!");
        exit (1);
    }
    instructionNode->instruction = instruction;
    return (SyntaxNode) {
        .type = ID_UnaryInstructionNode,
        .unaryInstructionNode = instructionNode
    };
}

SyntaxNode newArgumentNode(Token type, unsigned char is_array, Token name, SyntaxNode next) {
    ArgumentNode* argumentNode = (ArgumentNode*) malloc(sizeof(ArgumentNode));
    if(!argumentNode) {
        puts("Out of Memory!");
        exit(1);
    }
    argumentNode->type = type;
    argumentNode->name = name;
    argumentNode->next = next;
    argumentNode->is_array = is_array;
    return (SyntaxNode) {
        .type = ID_ArgumentNode,
        .argumentNode = argumentNode
    };
}

SyntaxNode newVanguardNode(SyntaxNode functionDeclaration) {
    VanguardNode* vanguardNode = (VanguardNode*) malloc(sizeof(VanguardNode));
    if(!vanguardNode) {
        puts("Out of Memory!");
        exit(1);
    }
    vanguardNode->functionDeclaration = functionDeclaration;
    return (SyntaxNode) {
        .type = ID_VanguardNode,
        .vanguardNode = vanguardNode
    };
}

SyntaxNode newFunctionCallNode(SyntaxNode identifier) {
    FunctionCallNode* functionCallNode = (FunctionCallNode*) malloc(sizeof(FunctionCallNode));
    if(!functionCallNode) {
        puts("Out of Memory!");
        exit(1);
    }
    functionCallNode->identifier = identifier;
    functionCallNode->numbersOfArguments = 0;
    functionCallNode->arguments = NULL;

    return (SyntaxNode) {
        .functionCallNode = functionCallNode,
        .type = ID_FunctionCallNode
    };
}

SyntaxNode newSquareCallNode(SyntaxNode identifier) {
    SquareCallNode* squareCallNode = (SquareCallNode*) malloc(sizeof(SquareCallNode));
    if(!squareCallNode) {
        puts("Out of Memory!");
        exit(1);
    }
    squareCallNode->identifier = identifier;
    squareCallNode->numbersOfArguments = 0;
    squareCallNode->arguments = NULL;

    return (SyntaxNode) {
        .squareCallNode = squareCallNode,
        .type = ID_SquareCallNode
    };
}

void FunctionCallNode_add(SyntaxNode functionCallNode, SyntaxNode argument) {
    if(argument.type == ID_None) return;
    functionCallNode.functionCallNode->numbersOfArguments++;
    functionCallNode.functionCallNode->arguments = 
        (SyntaxNode*) realloc(functionCallNode.functionCallNode->arguments, 
        sizeof(SyntaxNode) * functionCallNode.functionCallNode->numbersOfArguments);
    functionCallNode.functionCallNode->arguments[functionCallNode.functionCallNode->numbersOfArguments-1] = argument;
}

void SquareCallNode_add(SyntaxNode squareCallNode, SyntaxNode argument) {
    squareCallNode.squareCallNode->numbersOfArguments++;
    squareCallNode.squareCallNode->arguments = 
        (SyntaxNode*) realloc(squareCallNode.squareCallNode->arguments, 
        sizeof(SyntaxNode) * squareCallNode.squareCallNode->numbersOfArguments);
    squareCallNode.squareCallNode->arguments[squareCallNode.squareCallNode->numbersOfArguments-1] = argument;
}

SyntaxNode Parser_parseLiteral(Parser* parser) {
    Token before = Parser_peekLastToken(parser);

    if(Parser_peekNextToken(parser).type == TT_LBracket) {
        Parser_nextToken(parser);
        if(Parser_peekNextToken(parser).type == TT_RBracket) {
            Token closingBracket = Parser_nextToken(parser);
            closingBracket.type = TT_Comma;
            return newBinOpNode((SyntaxNode) {.type = ID_None}, closingBracket, (SyntaxNode) {.type = ID_None});
        }
        SyntaxNode inside = Parser_parseExpression(parser, 0);
        Token rbracket = Parser_nextToken(parser);
        if(rbracket.type != TT_RBracket) {
            markTokenError( rbracket);
            puts("Expected an closing bracket!");
            exit(1);
        }
        return inside;
    } else if(Parser_peekNextToken(parser).type == TT_LCurlyBracket) {
        SyntaxNode statementNode = Parser_parseStatement(parser);
        return statementNode;
    }
    else {
        Token token = Parser_peekNextToken(parser);
        switch(token.type) {
            case TT_Identifier:
                if(Parser_peekTwiceNextToken(parser).type == TT_At) {
                    Parser_nextToken(parser);
                    Token atToken = Parser_nextToken(parser);
                    Token library = Parser_nextToken(parser);
                    Token libVarName;
                    libVarName = library;
                    unsigned int newNameSize = strlen(token.value.word) + 2 + strlen(library.value.word);
                    libVarName.value.word = (char*) malloc(sizeof(char) * (newNameSize+1));
                    libVarName.value.word[0] = '\0';
                    libVarName.value.word = strcat(libVarName.value.word, "@");
                    libVarName.value.word = strcat(libVarName.value.word, library.value.word);
                    libVarName.value.word = strcat(libVarName.value.word, "_");
                    libVarName.value.word = strcat(libVarName.value.word, token.value.word);
                    Parser_addLibPath(parser, library.value.word);
                    return newValueNode(libVarName);
                }
            case TT_Int:
            case TT_Uint:
            case TT_Float:
            case TTK_True:
            case TTK_False:
            case TT_String:
            case TTK_Int:
            case TTK_Float:
            case TTK_Txt:
            case TTK_Byte:
            case TTK_Ubyte:
            case TTK_Short:
            case TTK_Ushort:
            case TTK_Uint:
            case TTK_Long:
            case TTK_Ulong:
            case TTK_Double:
                Parser_nextToken(parser);
                return newValueNode(token);
                break;
            default:
                if(before.type == TT_Comma) {
                    return (SyntaxNode) {.type = ID_None}; 
                }

                markTokenError(token);
                //printf("Type id %u\n", token.type);
                puts("Expected a variable/value/datatype! Please don't use keywords!");
                exit(1);
        }
    }
}

int Parser_getBinOpPrecedence(Token token) {
    switch(token.type) {
        case TT_Dot:
            return 15;
            break;
        case TTK_As:
            return 14;
        case TT_Plus:
        case TT_Minus:
            return 12;
            break;
        case TT_Multiply:
        case TT_Divide:
        case TT_Modulo:
            return 13;
            break;
        case TT_ShiftL:
        case TT_ShiftR:
            return 10;
            break;
        case TT_Less:
        case TT_LessEquals:
        case TT_Greater:
        case TT_GreaterEquals:
            return 9;
            break;
        case TT_EqualsEquals:
        case TT_NotEquals:
            return 8;
            break;
        case TT_And:
            return 7;
            break;
        case TT_Or:
            return 6;
            break;
        case TT_AndAnd:
            return 5;
            break;
        case TT_OrOr:
            return 4;
        case TT_Colon:
            return 3;

        case TT_Comma:
            return 2;

        case TT_Equalsign:
        case TT_PlusEqual:
        case TT_SubEqual:
        case TT_MulEqual:
        case TT_DivEqual:
        case TT_ModEqual:
        case TT_HashEqual:
        case TTK_Is:
        case TT_DefineOnce:
            return 1;
        default:
            return 0;
    }
}

int Parser_getUnaryOpPrecedence(Token token) {
    switch(token.type) {
        case TT_Plus:
        case TT_Minus:
            return 2;
            break;
        case TT_Exclamationmark:
        case TT_HashSymbol:
            return 10;
            break;
        case TT_Multiply:
            return 17;
            break;
        default:
            return 0;
    }
}

SyntaxNode Parser_parseExpression(Parser* parser, int parentPrecedence) {
    SyntaxNode left;
    int unaryOperatorPrecedence = Parser_getUnaryOpPrecedence(Parser_peekNextToken(parser));
    // Prefix
    if(unaryOperatorPrecedence != 0 && unaryOperatorPrecedence >= parentPrecedence) {
        Token operator = Parser_nextToken(parser);
        SyntaxNode operand = Parser_parseExpression(parser, unaryOperatorPrecedence);
        left = newUnaryOpNode(operator, operand);
    }
    else {
        left = Parser_parseLiteral(parser);
    }

    // Postfix => () functioncall
    if(Parser_peekNextToken(parser).type == TT_LBracket && 16 >= parentPrecedence) {
        SyntaxNode functionCallNode = newFunctionCallNode(left);
        Parser_nextToken(parser);
        Parser_ignoreNewLine(parser);
        
        if(Parser_peekNextToken(parser).type != TT_RBracket) {
            SyntaxNode tuple = Parser_parseExpression(parser, 0);
            while(tuple.type == ID_BinOpNode && tuple.binOpNode->operator.type == TT_Comma) {
                FunctionCallNode_add(functionCallNode, tuple.binOpNode->right);
                tuple = tuple.binOpNode->left;
            }
            FunctionCallNode_add(functionCallNode, tuple);
        }

        SyntaxNode reversedFunctionCallNode = newFunctionCallNode(left);
        for(unsigned int i = 0; i < functionCallNode.functionCallNode->numbersOfArguments; i++) {
            FunctionCallNode_add(
                reversedFunctionCallNode,
                functionCallNode.functionCallNode->arguments[functionCallNode.functionCallNode->numbersOfArguments - i - 1]
            );
        }
        functionCallNode = reversedFunctionCallNode;


        Parser_ignoreNewLine(parser);

        Token closingBracket = Parser_nextToken(parser);
        if(closingBracket.type != TT_RBracket) {
            markTokenError(closingBracket);
            puts("Expected a closing bracket!");
            exit(1);
        }

        left = functionCallNode;
    } else if(Parser_peekNextToken(parser).type == TT_LSquardBracket) { // => [a,b, type]
        SyntaxNode squareCallNode = newSquareCallNode(left);
        Parser_nextToken(parser);
        Parser_ignoreNewLine(parser);
        
        if(Parser_peekNextToken(parser).type != TT_RSquardBracket) {
            SyntaxNode tuple = Parser_parseExpression(parser, 0);
            while(tuple.type == ID_BinOpNode && tuple.binOpNode->operator.type == TT_Comma) {
                SquareCallNode_add(squareCallNode, tuple.binOpNode->right);
                tuple = tuple.binOpNode->left;
            }
            SquareCallNode_add(squareCallNode, tuple);
        }

        SyntaxNode reversedSquareCallNode = newSquareCallNode(left);
        for(unsigned int i = 0; i < squareCallNode.squareCallNode->numbersOfArguments; i++) {
            SquareCallNode_add(reversedSquareCallNode, squareCallNode.squareCallNode->arguments[squareCallNode.squareCallNode->numbersOfArguments - i - 1]);
        }
        squareCallNode = reversedSquareCallNode;

        Parser_ignoreNewLine(parser);

        Token closingBracket = Parser_nextToken(parser);
        if(closingBracket.type != TT_RSquardBracket) {
            markTokenError(closingBracket);
            puts("Expected a closing squared bracket!");
            exit(1);
        }

        left = squareCallNode;
    }
    
    while(1) {
        int precedence = Parser_getBinOpPrecedence(Parser_peekNextToken(parser));
        if(precedence == 0 || precedence <= parentPrecedence)
            break;
        Token operator = Parser_nextToken(parser);
        Parser_ignoreNewLine(parser);
        SyntaxNode right = Parser_parseExpression(parser, precedence);

        left = newBinOpNode(left, operator, right);
    }

    return left;
}

SyntaxNode Parser_parseStatement(Parser* parser) {
    Parser_ignoreNewLine(parser);
    Token token = Parser_peekNextToken(parser);
    switch(token.type) {

        case TT_LCurlyBracket:
        {
            Parser_nextToken(parser);
            Parser_ignoreNewLine(parser);
            token = Parser_peekNextToken(parser);
            if(token.type == TT_RCurlyBracket) {
                Parser_nextToken(parser);
                return (SyntaxNode) {
                    .type = ID_None
                };
            }
            else {
                SyntaxNode node;
                SyntaxNode* refnode = &node;
                while(1) {
                    *refnode = Parser_parseStatement(parser);
                    while(Parser_peekNextToken(parser).type == TT_Newline)
                        Parser_nextToken(parser);
                    token = Parser_peekNextToken(parser);
                    if(token.type == TT_RCurlyBracket) {
                        Parser_nextToken(parser);
                        return node;
                    }
                    else if(token.type == TT_End) {
                        markTokenError( Parser_peekNextToken(parser));
                        puts("Missing }");
                        exit(1);
                    }
                    else {
                        *refnode = newStatementsNode(*refnode, (SyntaxNode){.type = ID_None});
                        refnode = &refnode->statementsNode->second;
                    }
                }
            }
        }
            break;

        case TTK_If:
        {
            Token iftoken = Parser_nextToken(parser);
            SyntaxNode condition = Parser_parseExpression(parser, 0);
            SyntaxNode statements = Parser_parseStatement(parser);
            SyntaxNode elseStatements = (SyntaxNode) {.type = ID_None};
            token = Parser_peekNextToken(parser);
            Parser_ignoreNewLine(parser);
            if(token.type == TTK_Else) {
                Parser_nextToken(parser);
                elseStatements = Parser_parseStatement(parser);
            }
            return newIfNode(statements, elseStatements, condition, iftoken);
        }
            break;
        
        case TTK_For:
        {
            SyntaxNode init = {.type = ID_None};
            SyntaxNode condition = {.type = ID_None};
            SyntaxNode action = {.type = ID_None};

            Token forWord = Parser_nextToken(parser);

            SyntaxNode expression1 = Parser_parseExpression(parser, 0);
            if(Parser_peekNextToken(parser).type == TT_Semicolon) {
                Parser_nextToken(parser);
                SyntaxNode expression2 = Parser_parseExpression(parser, 0);
                if(Parser_peekNextToken(parser).type == TT_Semicolon) {
                    Parser_nextToken(parser);
                    SyntaxNode expression3 = Parser_parseExpression(parser, 0);
                    init = expression1;
                    condition = expression2;
                    action = expression3;
                } else {
                    condition = expression1;
                    action = expression2;
                }
            } else {
                condition = expression1;
            }

            SyntaxNode statements = Parser_parseStatement(parser);

            if(condition.type == ID_ValueNode) {
                Token conditionValue = condition.valueNode->value;
                if(conditionValue.type == TTK_False) {
                    return (SyntaxNode) {.type = ID_None};
                } else if(conditionValue.type == TTK_True) {
                    condition = (SyntaxNode) {.type = ID_None};
                }
            }

            return newForNode(forWord, statements, init, condition, action);
        }
            break;
        
        case TTK_Return:
        {
            Token returnWord = Parser_nextToken(parser);
            SyntaxNode expression = Parser_parseExpression(parser, 0);
            Parser_parseSeperator(parser);
            return newReturnNode(returnWord, expression);
        }
            break;

        case TTK_Break:
        {
            Token break_token = Parser_nextToken (parser);
            Parser_parseSeperator (parser);
            return newUnaryInstructionNode (break_token);
        }
            break;

        case TTK_Continue:
        {
            Token continue_token = Parser_nextToken (parser);
            Parser_parseSeperator (parser);
            return newUnaryInstructionNode (continue_token);
        }
            break;

        case TTK_Include:
        {
            Token implement_token = Parser_nextToken(parser);
            Token library = (Token) {.type = TT_None};
            Token declaration = (Token) {.type = TT_None};
            Token identifier = (Token) {.type = TT_None};

            if(Parser_peekNextToken(parser).type == TT_Multiply) {
                Parser_nextToken(parser);
                Token atToken;
                if((atToken = Parser_nextToken(parser)).type != TT_At) {
                    puts("Expected an @ Symbol!");
                    markTokenError(atToken);
                    exit(1);
                }
                
                library = Parser_nextToken(parser);
                if(library.type != TT_Identifier) {
                    puts("Expected an Identifier!");
                    markTokenError(library);
                    exit(1);
                }
                while(Parser_peekNextToken(parser).type == TT_Dot) {
                    Parser_nextToken(parser);
                    
                    Token nextLib = Parser_nextToken(parser);
                    if(nextLib.type != TT_Identifier) {
                        puts("Expected an Identifier!");
                        markTokenError(library);
                        exit(1);
                    }

                    library.value.word = strconcat(library.value.word, "/");
                    library.value.word = strconcat(library.value.word, nextLib.value.word);
                }


            } else {
                identifier = Parser_peekNextToken(parser);
                ValueNode *valueNode = Parser_parseLiteral(parser).valueNode;
                declaration = valueNode->value;
                if(declaration.type != TT_Identifier) {
                    puts("Expected an Identifier!");
                    markTokenError(declaration);
                    exit(1);
                }
            }

            Parser_parseSeperator(parser);
            return newIncludeNode(implement_token, declaration, library, identifier);
        }
            break;

        case TT_End:
            break;
        case TT_Semicolon:
            Parser_nextToken(parser);
            break;

        default:
        {
            SyntaxNode expression = Parser_parseExpression(parser, 0);
            Parser_parseSeperator(parser);
            return expression;
        }
    }
    return (SyntaxNode) {.type = ID_None};
}

SyntaxNode Parser_parseGlobalDeclaration(Parser* parser) {
    Parser_ignoreNewLine(parser);
    Token token = Parser_peekNextToken(parser);
    switch(token.type) {
        case TTK_Vanguard:
        {
            Parser_nextToken(parser);
            // function declaration
            return newVanguardNode(Parser_parseFunctionDeclaration(parser));
        }
            break;
        case TT_End:
            break;

        
        case TTK_Include:
        {
            Token implement_token = Parser_nextToken(parser);
            Token library = (Token) {.type = TT_None};
            Token declaration = (Token) {.type = TT_None};
            Token identifier = (Token) {.type = TT_None};

            if(Parser_peekNextToken(parser).type == TT_Multiply) {
                Parser_nextToken(parser);
                Token atToken;
                if((atToken = Parser_nextToken(parser)).type != TT_At) {
                    puts("Expected an @ Symbol!");
                    markTokenError( atToken);
                    exit(1);
                }
                library = Parser_nextToken(parser);
                if(library.type != TT_Identifier) {
                    puts("Expected an Identifier!");
                    markTokenError( library);
                    exit(1);
                }
                while(Parser_peekNextToken(parser).type == TT_Dot) {
                    Parser_nextToken(parser);
                    
                    Token nextLib = Parser_nextToken(parser);
                    if(nextLib.type != TT_Identifier) {
                        puts("Expected an Identifier!");
                        markTokenError(library);
                        exit(1);
                    }

                    library.value.word = strconcat(library.value.word, "/");
                    library.value.word = strconcat(library.value.word, nextLib.value.word);
                }
                
            } else {
                identifier = Parser_peekNextToken(parser);
                ValueNode *valueNode = Parser_parseLiteral(parser).valueNode;
                declaration = valueNode->value;
                if(declaration.type != TT_Identifier) {
                    puts("Expected an Identifier!");
                    markTokenError( declaration);
                    exit(1);
                }
            }

            Parser_parseSeperator(parser);
            return newIncludeNode(implement_token, declaration, library, identifier);
        }
            break;

        case TT_Identifier:
        {
            Token functionbracket = Parser_peekTwiceNextToken(parser);
            if(functionbracket.type == TT_LBracket) {
                // function declaration
                return Parser_parseFunctionDeclaration(parser);
            }
        }
        default:
        {
            SyntaxNode expression = Parser_parseExpression(parser, 0);
            Parser_parseSeperator(parser);
            return expression;
        }
    }
    return (SyntaxNode) {
        .type = ID_None
    };
}

SyntaxNode Parser_parseArguments(Parser* parser) {
    Parser_ignoreNewLine(parser);
    Token tokentype = Parser_nextToken(parser);
    switch(tokentype.type) {
        case TTK_Ubyte:
        case TTK_Byte:
        case TTK_Short:
        case TTK_Ushort:
        case TTK_Uint:
        case TTK_Int:
        case TTK_Float:
        case TTK_Long:
        case TTK_Ulong:
        case TTK_Double:
        case TT_Identifier:
        case TTK_Txt:
        {
            unsigned char is_array = 0;
            if(Parser_peekNextToken(parser).type == TT_LSquardBracket) {
                Parser_nextToken(parser);
                if(Parser_nextToken(parser).type != TT_RSquardBracket) {
                    markTokenError( tokentype);
                    puts("Unusable name for an argument!");
                    exit(1);
                }
                is_array = 1;
            }
            Token name = Parser_nextToken(parser);
            if(name.type != TT_Identifier) {
                markTokenError( tokentype);
                puts("Unusable name for an argument!");
                exit(1);
            }
            SyntaxNode argument;
            if(Parser_peekNextToken(parser).type != TT_Comma) {
                argument = newArgumentNode(tokentype, is_array, name, (SyntaxNode) {.type = ID_None});
                Parser_ignoreNewLine(parser);
                Token bracket = Parser_nextToken(parser);
                if(bracket.type != TT_RBracket) {
                    markTokenError( bracket);
                    puts("Expected a closing bracket!");
                    exit(1);
                }
            }
            else {
                Parser_nextToken(parser);
                argument = newArgumentNode(tokentype, is_array, name, Parser_parseArguments(parser));
            }
            return argument;
        }
            break;
        default:
            markTokenError( tokentype);
            puts("Not existing datatype!");
            exit(1);
    }
}

void Program_addGlobalDeclaration(ProgramsNode* program, SyntaxNode globalDeclaration) {
    program->size++;
    program->declarations = (SyntaxNode*) realloc(program->declarations, sizeof(SyntaxNode) * program->size);
    program->declarations[program->size-1] = globalDeclaration;
}

SyntaxNode Parser_parseFunctionDeclaration(Parser* parser) {
    
    // We've need a name for the function to be refered
    Token name = Parser_nextToken(parser);
   
    // The token shouldn't be anything else than an identifier
    if(name.type != TT_Identifier){
        markTokenError( name);
        puts("Unusable name for a function!");
        exit(1);
    }

    // Next we need an tuple, where function parameters are given
    Token bracket = Parser_nextToken(parser);
    // Of course, we want it to be surrounded by brackets
    if(bracket.type != TT_LBracket) {
        markTokenError( bracket);
        puts("Exprected a opening bracket!");
        exit(1);
    }

    // now parse the arguments or an star for any argument

    SyntaxNode arguments = (SyntaxNode) {.type = ID_None};

    if(Parser_peekNextToken(parser).type == TT_Multiply) {
        arguments = newValueNode(Parser_nextToken(parser));
        Token closingBracket = Parser_nextToken(parser);
        if(closingBracket.type != TT_RBracket) {
            markTokenError( closingBracket);
            puts("Exprected a closing bracket!");
            exit(1);
        }
    } else if(Parser_peekNextToken(parser).type != TT_RBracket)
        arguments = Parser_parseArguments(parser);
    else
        Parser_nextToken(parser);
    unsigned char returns_array = 0;
    Token returnType = Parser_peekNextToken(parser);
    switch(returnType.type) {
        case TTK_Ubyte:
        case TTK_Byte:
        case TTK_Ushort:
        case TTK_Short:
        case TTK_Uint:
        case TTK_Int:
        case TTK_Float:
        case TTK_Ulong:
        case TTK_Long:
        case TTK_Double:
        case TTK_Txt:
        case TT_Identifier:
            Parser_nextToken(parser);
            if(Parser_peekNextToken(parser).type == TT_LSquardBracket) {
                Parser_nextToken(parser);
                if(Parser_nextToken(parser).type != TT_RSquardBracket) {
                    markTokenError( returnType);
                    puts("Unusable Return-Datatype!");
                    exit(1);
                }
                returns_array = 1;
            }
            break;
        default:
            returnType = (Token) {
                .begin = 0,
                .end = 0,
                .lineNumber = 0,
                .type = -1,
                .value.u = 0
            };
    }
    
    // Oneliner

    if(Parser_peekNextToken(parser).type == TT_Equalsign) {
        Token returnNode = Parser_nextToken(parser);

        return newFunctionNode(arguments, newReturnNode(returnNode, Parser_parseExpression(parser, 0)), name, returnType, returns_array);
    }
    
    return newFunctionNode(arguments, Parser_parseStatement(parser), name, returnType, returns_array);
}

void Parser_parseSeperator(Parser* parser) {
    if(Parser_peekNextToken(parser).type == TT_End)
        return;
    Token token = Parser_nextToken(parser);
    if(token.type == TT_Newline || token.type == TT_Semicolon)
        return;
    markTokenError( token);
    puts("Expected a semicolon!");
    exit(1);
}

void Parser_ignoreNewLine(Parser* parser) {
    while(Parser_peekNextToken(parser).type == TT_Newline)
        Parser_nextToken(parser);
}

SyntaxNode Parser_parse(Parser* parser) {
    ProgramsNode* program = (ProgramsNode*) malloc(sizeof(ProgramsNode));
    if(!program) {
        puts("Out of Memory");
        exit(1);
    }
    program->size = 0;
    program->declarations = NULL;

    Parser_ignoreNewLine(parser);
    while(Parser_peekNextToken(parser).type != TT_End) {
        Program_addGlobalDeclaration(program, Parser_parseGlobalDeclaration(parser));
        Parser_ignoreNewLine(parser);
    }

    return (SyntaxNode) {
        .type = ID_ProgramsNode,
        .programsNode = program
    };
}

void Parser_prettyPrint(SyntaxNode tree) {
    putchar('(');
    switch(tree.type) {
        case ID_BinOpNode:
            switch(tree.binOpNode->operator.type) {
                case TT_Comma:
                    putchar(',');
                    break;
                case TT_Plus:
                    putchar('+');
                    break;
                case TT_Minus:
                    putchar('-');
                    break;
                case TT_Multiply:
                    putchar('*');
                    break;
                case TT_Divide:
                    putchar('/');
                    break;
                case TT_EqualsEquals:
                    printf("==");
                    break;
                case TT_NotEquals:
                    printf("!=");
                    break;
                case TT_And:
                    printf("&");
                    break;
                case TT_Or:
                    printf("|");
                    break;
                case TT_AndAnd:
                    printf("&&");
                    break;
                case TT_OrOr:
                    printf("||");
                    break;
                case TT_Equalsign:
                    printf("=");
                    break;
                case TT_Colon:
                    printf(":");
                    break;
                case TT_DefineOnce:
                    printf(":=");
                    break;
                case TTK_Is:
                    printf("is");
                    break;
                case TT_Modulo:
                    printf("%%");
                    break;
                case TT_Dot:
                    printf("get .");
                    break;
                case TT_At:
                    printf("@ ");
                    break;
                case TT_Less:
                    printf("<");
                    break;
                case TT_LessEquals:
                    printf("<=");
                    break;
                case TT_Greater:
                    printf(">");
                    break;
                case TT_GreaterEquals:
                    printf(">=");
                    break;
                case TT_ShiftL:
                    printf("<<");
                    break;
                case TT_ShiftR:
                    printf(">>");
                    break;
                case TTK_As:
                    printf("as conv ");
                    break;
            }
            putchar(' ');
            Parser_prettyPrint(tree.binOpNode->left);
            Parser_prettyPrint(tree.binOpNode->right);
            break;
        case ID_UnaryOpNode:
            switch(tree.unaryOpNode->operator.type) {
                case TT_Plus:
                    putchar('+');
                    break;
                case TT_Minus:
                    putchar('-');
                    break;
                case TT_Exclamationmark:
                    putchar('!');
                    break;
                case TT_HashSymbol:
                    putchar('#');
                    break;
                case TT_Multiply:
                    putchar('*');
                    break;
            }
            Parser_prettyPrint(tree.unaryOpNode->operand);
            break;
        case ID_ValueNode:
            switch(tree.valueNode->value.type) {
                case TT_Int:
                    printf("%lld", tree.valueNode->value.value.i);
                    break;
                case TT_Uint:
                    printf("%llu", tree.valueNode->value.value.u);
                    break;
                case TT_Float:
                    printf("%lf", tree.valueNode->value.value.f);
                    break;
                case TTK_True:
                    printf("true");
                    break;
                case TTK_False:
                    printf("false");
                    break;
                case TT_String:
                    printf("'%s'", tree.valueNode->value.value.word);
                    break;
                case TT_Identifier:
                    printf("%s", tree.valueNode->value.value.word);
                    break;
                
                case TTK_Int:
                    printf("type: integer");
                    break;
                case TTK_Float:
                    printf("type: float");
                    break;
                case TTK_Txt:
                    printf("type: text");
                    break;
                case TTK_Byte:
                    printf("type: byte");
                    break;
                case TTK_Ubyte:
                    printf("type: unsigned byte");
                    break;
                case TTK_Short:
                    printf("type: short");
                    break;
                case TTK_Ushort:
                    printf("type: unsigned short");
                    break;
                case TTK_Uint:
                    printf("type: unsigned int");
                    break;
                case TTK_Long:
                    printf("type: long");
                    break;
                case TTK_Ulong:
                    printf("type: unsigned long");
                    break;
                case TTK_Double:
                    printf("type: double");
                    break;
            }
            break;
    
        case ID_IfNode:
            printf("if ");
            Parser_prettyPrint(tree.ifNode->condition);
            Parser_prettyPrint(tree.ifNode->statements);
            Parser_prettyPrint(tree.ifNode->elseStatements);
            break;
        case ID_ForNode:
            printf("for ");
            Parser_prettyPrint(tree.forNode->init);
            Parser_prettyPrint(tree.forNode->condition);
            Parser_prettyPrint(tree.forNode->action);
            Parser_prettyPrint(tree.forNode->statements);
            break;
        case ID_StatementsNode:
            Parser_prettyPrint(tree.statementsNode->first);
            Parser_prettyPrint(tree.statementsNode->second);
            break;
        case ID_ReturnNode:
            printf("return ");
            Parser_prettyPrint(tree.returnNode->expression);
            break;

        case ID_UnaryInstructionNode:
            printf ("instruction: ");
            switch (tree.unaryInstructionNode->instruction.type) {
                case TTK_Break:
                    printf ("break");
                    break;
                case TTK_Continue:
                    printf ("continue");
                    break;
                default:;
            }
            break;
        
        case ID_FunctionNode:
            printf("fn %s ", tree.functionNode->name.value.word);
            Parser_prettyPrint(tree.functionNode->arguments);
            Parser_prettyPrint(tree.functionNode->statements);
            break;
        case ID_ArgumentNode:
            printf("arg %s ", tree.argumentNode->name.value.word);
            switch(tree.argumentNode->type.type) {
                case TTK_Int:
                printf("type: integer");
                break;
                case TTK_Float:
                    printf("type: float");
                    break;
                case TTK_Txt:
                    printf("type: text");
                    break;
                case TTK_Byte:
                    printf("type: byte");
                    break;
                case TTK_Ubyte:
                    printf("type: unsigned byte");
                    break;
                case TTK_Short:
                    printf("type: short");
                    break;
                case TTK_Ushort:
                    printf("type: unsigned short");
                    break;
                case TTK_Uint:
                    printf("type: unsigned int");
                    break;
                case TTK_Long:
                    printf("type: long");
                    break;
                case TTK_Ulong:
                    printf("type: unsigned long");
                    break;
                case TTK_Double:
                    printf("type: double");
                    break;
                case TT_Identifier:
                    printf("progression: %s", tree.argumentNode->type.value.word);
                    break;
            }
            if(tree.argumentNode->is_array) {
                printf("[]");
            }
            break;
        case ID_VanguardNode:
            printf("vanguard ");
            Parser_prettyPrint(tree.vanguardNode->functionDeclaration);
            break;
        case ID_Include:
            printf("implements from %s -> %s as %s", tree.includeNode->library.value.word, tree.includeNode->declaration.value.word, tree.includeNode->identifier.value.word);
            break;
        case ID_ProgramsNode:
            puts("Program: ");
            for(unsigned int i = 0; i < tree.programsNode->size; i++) {
                Parser_prettyPrint(tree.programsNode->declarations[i]);
                putchar('\n');
            }
            break;
        case ID_FunctionCallNode:
            printf("functioncall: ");
            Parser_prettyPrint(tree.functionCallNode->identifier);
            for(unsigned int i = 0; i < tree.functionCallNode->numbersOfArguments; i++) {
                Parser_prettyPrint(tree.functionCallNode->arguments[i]);
            }
            break;
        case ID_SquareCallNode:
            printf("squarecall []: ");
            Parser_prettyPrint(tree.squareCallNode->identifier);
            for(unsigned int i = 0; i < tree.squareCallNode->numbersOfArguments; i++) {
                Parser_prettyPrint(tree.squareCallNode->arguments[i]);
            }
            break;
        case ID_None:
            printf("nil");
            break;
    }
    putchar(')');
} 

void Parser_clearAST(SyntaxNode node) {
    if(node.type == ID_None)
        return;
    switch(node.type) {
        case ID_BinOpNode:
        {
            BinOpNode* next = node.binOpNode;
            Parser_clearAST(next->left);
            Parser_clearAST(next->right);
            free(next);
        }
            break;
        case ID_UnaryOpNode:
        {
            UnaryOpNode* next = node.unaryOpNode;
            Parser_clearAST(next->operand);
            free(next);
        }
            break;
        case ID_ValueNode:
        {
            ValueNode* next = node.valueNode;
            free(next);
        }
            break;
        
        case ID_FunctionNode:
        {
            FunctionNode* next = node.functionNode;
            Parser_clearAST(next->arguments);
            Parser_clearAST(next->statements);
            free(next);
        }
            break;
        case ID_IfNode:
        {
            IfNode* next = node.ifNode;
            Parser_clearAST(next->condition);
            Parser_clearAST(next->elseStatements);
            Parser_clearAST(next->statements);
            free(next);
        }
            break;
        case ID_ForNode:
        {
            ForNode* next = node.forNode;
            Parser_clearAST(next->condition);
            Parser_clearAST(next->statements);
            free(next);
        }
            break;
        case ID_StatementsNode:
        {
            StatementsNode* next = node.statementsNode;
            Parser_clearAST(next->first);
            Parser_clearAST(next->second);
            free(next);
        }
            break;
        case ID_ReturnNode:
        {
            ReturnNode* next = node.returnNode;
            Parser_clearAST(next->expression);
            free(next);
        }
            break;
        case ID_UnaryInstructionNode:
        {
            UnaryInstructionNode* next = node.unaryInstructionNode;
            free (next);
        }
            break;
        case ID_ArgumentNode:
        {
            ArgumentNode* next = node.argumentNode;
            Parser_clearAST(next->next);
            free(next);
        }
            break;
        case ID_VanguardNode:
        {
            VanguardNode* next = node.vanguardNode;
            Parser_clearAST(next->functionDeclaration);
            free(next);
        }
            break;
        case ID_Include:
        {
            // Noting to be cleaned
        }
            break;
        case ID_ProgramsNode:
        {
            for(unsigned int i = 0; i < node.programsNode->size; i++) {
                Parser_clearAST(node.programsNode->declarations[i]);
            }
            free(node.programsNode->declarations);
        }
            break;
        case ID_FunctionCallNode:
        {
            for(unsigned int i = 0; i < node.functionCallNode->numbersOfArguments; i++) {
                Parser_clearAST(node.functionCallNode->arguments[i]);
            }
            free(node.functionCallNode->arguments);
        }
            break;
        case ID_SquareCallNode:
        {
            for(unsigned int i = 0; i < node.squareCallNode->numbersOfArguments; i++) {
                Parser_clearAST(node.squareCallNode->arguments[i]);
            }
            free(node.squareCallNode->arguments);
        }
            break;
    }
}

#endif