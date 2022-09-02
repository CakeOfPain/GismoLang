/*
 * Gismo Compiler-tool for the Gismo Language
 * Written by: Leo Englert
 * Creates an AST from Gismo-Sourcecode and compiles it to GVM-Bytecode
 */

#define VERSION         "G3.0.0"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>

#ifdef _WIN32
#include <windows.h>

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

#include <io.h>
#define F_OK 0
#define access _access
#endif

#include <ctype.h>

char* readFile(const char*);

#define GISMOHOME "C:\\Gismolang"
#define GISMOHOMELIBS "C:\\Gismolang\\libs\\"

// ANSI COLOR..
#define ACEC "\e"

unsigned char DEBUGGING_MODE = 0;

void getLibraryIdOfPath(const char *path, char *lib_id) {
    int x = 0;
    int i = 0;
    for(char ch = path[0]; ch != '\0' && ch != '.'; ch = path[i]) {
        ch = path[i];

        if(ch == '/' || ch == '\\') {
            lib_id[0] = '\0';
            x = 0;
        } else {
            lib_id[x++] = ch;
            lib_id[x] = '\0';
        }

        i++;
    }
}

#include "header.h"
#include "ByteWriter.h"
#include "tokenizer.h"
#include "parser.h"
#include "CodeGenerator.h"

void adx_store_data(const char *filepath, const char *data, unsigned int data_lenght);
void printHelp();

int main(int argc, char const *argv[]) {
    // Checks for enough arguments


    if(argc < 2) {
        printHelp();
        return 0;
    }

    const char* mode = argv[1];

    if(strcmp(mode, "help") == 0) {
        printHelp();
        return 0;
    }
    else if(strcmp(mode, "version") == 0) {
        printf("\nGismo Version: %s\n", VERSION);
        return 0;
    }

    if(argc < 3) {
        puts("Missing file path!");
        exit(1);
    }

    // Will read in the file to parse
    char* buffer = readFile(argv[2]);
    char libraryId[256] = "";
    getLibraryIdOfPath(argv[2], libraryId);
    fullIncludes[fullIncludesSize++] = libraryId;
    

    // Init the Tokenizer
    Tokenizer* tokenizer = (Tokenizer*) malloc(sizeof(Tokenizer));
    if(!tokenizer) {
        puts("Out of Memory!");
        exit(1);
    }
    *tokenizer = Tokenizer_getTokens(buffer, argv[2]);

    // Init Parser
    Parser *parser = (Parser*) malloc(sizeof(Parser));
    *parser = Parser_build(tokenizer);

    if(strcmp(mode, "build") == 0) {
        CodeGenerator* generator = CodeGenerator_build(parser);
        if(argc < 4) {
            puts("Missing export file path!");
            exit(1);
        }
        adx_store_data(argv[3], generator->code, generator->codeLength);
        free(generator);

        // Optimize code
        char optCommand[900] = "";
        const char optModPath[] = GISMOHOME "/modifications/bin/optimization.gim";
        sprintf(optCommand, GISMOHOME "/GVM %s %s %s", optModPath, argv[3], argv[3]);
        system(optCommand);
    }
    else if(strcmp(mode, "bytecode") == 0) {
        CodeGenerator* generator = CodeGenerator_build(parser);
        for(unsigned int i = 0; i < generator->codeLength; i++) {
            printf("%x ", (unsigned char) generator->code[i]);
        } // Can be used to visualize the bytecode after generation
        free(generator);
    }
    else if(strcmp(mode, "symboltable") == 0) {
        CodeGenerator* generator = CodeGenerator_build(parser);
        VariableTable_listAll(&generator->table);
        free(generator);
    }
    else if (strcmp (mode, "dependencies") == 0) {
        for (unsigned int i = 0; i < parser->numberOfLibrarys; i ++) {
            printf (" * %s\n", parser->librarys[i]);
        }
    }
    else if(strcmp(mode, "ast") == 0) {
        // Outputs the abstract syntax tree
        Parser_prettyPrint(parser->ast);
    }
    else if(strcmp(mode, "run") == 0) {
        CodeGenerator* generator = CodeGenerator_build(parser);
        adx_store_data(".temp.gim", generator->code, generator->codeLength);
	
        // Optimize code
        system("GVM " GISMOHOME "/modifications/bin/optimization.gim ./.temp.gim ./.temp.gim");

        // Passing code to GVM
        system("GVM ./.temp.gim");

        // Clean up made file
        system("del .temp.gim");
        free(generator);
    }
    else if(strcmp(mode, "run=debug") == 0) {
        DEBUGGING_MODE = 1;
        CodeGenerator* generator = CodeGenerator_build(parser);
        adx_store_data(".temp.gim", generator->code, generator->codeLength);
	
        // Optimize code
        system("GVM " GISMOHOME "/modifications/bin/optimization.gim ./.temp.gim ./.temp.gim");

        // Passing code to GVM
        system("GVM ./.temp.gim");

        // Clean up made file
        system("del .temp.gim");
        free(generator);
    }
    else if(strcmp(mode, "build=debug") == 0) {
        DEBUGGING_MODE = 1;
        CodeGenerator* generator = CodeGenerator_build(parser);
        if(argc < 4) {
            puts("Missing export file path!");
            exit(1);
        }
        adx_store_data(argv[3], generator->code, generator->codeLength);
        free(generator);

        // Optimize code
        char optCommand[900] = "";
        const char optModPath[] = GISMOHOME "/modifications/bin/optimization.gim";
        sprintf(optCommand, GISMOHOME "/GVM %s %s %s", optModPath, argv[3], argv[3]);
        system(optCommand);
    }
    else {
        puts("Gismo doesn't support this mode!");
    }

    // Clears all up
    Parser_clear(*parser);
    Tokenizer_clear(*tokenizer);
    free(buffer);
    free(parser);
    free(tokenizer);

    return 0;
}

// Quelle: https://stackoverflow.com/questions/3747086/reading-the-whole-text-file-into-a-char-array-in-c (Edited)
char* readFile(const char* path) {
    FILE *fp;
    long lSize;
    char *buffer;

    fp = fopen ( path , "rb" );
    if( !fp ) perror(path),exit(1);

    fseek( fp , 0L , SEEK_END);
    lSize = ftell( fp );
    rewind( fp );

    /* allocate memory for entire content */
    buffer = calloc( 1, lSize+1 );
    if( !buffer ) fclose(fp),fputs("memory alloc fails",stderr),exit(1);

    /* copy the file into the buffer */
    if( 1!=fread( buffer , lSize, 1 , fp) )
    fclose(fp),free(buffer),fputs("entire read fails",stderr),exit(1);

    /* do your work here, buffer is a string contains the whole text */

    fclose(fp);
    return buffer;
}

// Source: https://stackoverflow.com/questions/4182876/how-to-write-a-string-to-a-file-in-c (Edited)
void adx_store_data(const char *filepath, const char *data, unsigned int data_lenght)
{
    FILE *fp = fopen(filepath, "wb");
    if (fp != NULL)
    {
        for(unsigned int i = 0; i < data_lenght; i++) {
            fputc(data[i], fp);
        }
        fclose(fp);
    }
}

void printHelp() {
    #ifdef _WIN32
    // For enabling ANSI-Colors in the cmd
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING ;
    SetConsoleMode(hOut, dwMode);
    #endif

    puts(""ACEC"[97mModes: \n"
        "* Use "ACEC"[36mgismo build xyz.gsm xyz.gim"ACEC"[97m to generate an\n"
        "  Gismo Instruction Mode Executable ("ACEC"[36mbuild=debug"ACEC"[97m for debugging)\n"
        "* Use "ACEC"[36mgismo run xyz.gsm"ACEC"[97m to directly execute a file\n"
        "  in the Gismo Source Mode("ACEC"[37run=debug"ACEC"[97m for debugging)\n"
        "* Use "ACEC"[36mgismo bytecode xyz.gsm"ACEC"[97m for dumping it's\n"
        "  bytecode as hex\n"
        "* Use "ACEC"[36mgismo symboltable xyz.gsm"ACEC"[97m for listing all symbols\n"
        "* Use "ACEC"[36mgismo dependencies xyz.gsm"ACEC"[97m for listing all\n"
        "  xyz@xyz dependencies\n"
        "* Use "ACEC"[36mgismo ast xyz.gsm"ACEC"[97m for showing a AST\n"
        "  representation of the file (Not the project, only file)\n"
        "* Use "ACEC"[36mgismo version"ACEC"[97m for showing the version of this\n"
        "  Gismo Compiler.\n"ACEC"[0m"
    );
}
