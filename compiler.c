/*
 * Gismo Compiler-tool for the Gismo Language
 * Written by: Leo Englert
 * Creates an AST from Gismo-Sourcecode and compiles it to GVM-Bytecode
 */

#define VERSION         "G2.9"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>

#ifdef _WIN32
#include <io.h>
#define F_OK 0
#define access _access
#endif

#include <ctype.h>

char* readFile(const char*);

#define GISMOHOME "/Applications/Gismolang"
#define GISMOHOMELIBS "/Applications/Gismolang/libs/"

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
    else if(strcmp(mode, "modification") == 0) {
        
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
        const char optModPath[] = "/Applications/Gismolang/modifications/bin/optimization.gim";
        sprintf(optCommand, "/Applications/GismoLang/GVM %s %s %s", optModPath, argv[3], argv[3]);
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
    else if(strcmp(mode, "prettyPrint") == 0) {
        // Outputs the abstract syntax tree
        Parser_prettyPrint(parser->ast);
    }
    else if(strcmp(mode, "run") == 0) {
        CodeGenerator* generator = CodeGenerator_build(parser);
        adx_store_data(".temp.gim", generator->code, generator->codeLength);
	
        // Optimize code
        system("GVM /Applications/Gismolang/modifications/bin/optimization.gim ./.temp.gim ./.temp.gim");

        // Passing code to GVM
        system("GVM ./.temp.gim");

        // Clean up made file
        system("rm -r .temp.gim");
        free(generator);
    }
    else if(strcmp(mode, "debug=run") == 0) {
        DEBUGGING_MODE = 1;
        CodeGenerator* generator = CodeGenerator_build(parser);
        adx_store_data(".temp.gim", generator->code, generator->codeLength);
	
        // Optimize code
        system("GVM /Applications/Gismolang/modifications/bin/optimization.gim ./.temp.gim ./.temp.gim");

        // Passing code to GVM
        system("GVM ./.temp.gim");

        // Clean up made file
        system("rm -r .temp.gim");
        free(generator);
    }
    else if(strcmp(mode, "debug=build") == 0) {
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
        const char optModPath[] = "/Applications/Gismolang/modifications/bin/optimization.gim";
        sprintf(optCommand, "/Applications/GismoLang/GVM %s %s %s", optModPath, argv[3], argv[3]);
        system(optCommand);
    }
    else if(strcmp(mode, "modify")) {
        
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
    puts("Modes: ");
    puts("\tbuild:                      Creates an executable GVM-Bytecode file for the GVM");
    puts("\trun:                        Runs an Gismo-Sourcefile");
    puts("\tdebug=(run|build)           Runs an Gismo-Sourcefile or compiles it with debugging mode");
    puts("\tbytecode:                   Prints the generated bytecode to the console");
    puts("\tsymboltable:                Prints out the symbole table");
    puts("\tdependencies:               Prints a list of all libraries that it uses");
    puts("\tprettyPrint:                Prints the whole AST in a simple representation");
    puts("\tversion:                    Prints out the current version of this compiler");
    puts("\tmodfiy:                     Add a step in compiling with a .gim file");
    puts("\tmodifications:              Lists all current modifications"); 
}
