#include <stdio.h>
#include "error.h"
#include "../common/colors.h"

/**
 * Posibles mensaxes de erro
 */
static const char *error_strings[] = {
    FOREACH_ERROR(GENERATE_STRING)
};

void handleError(ErrorType errorType){
    printf(ANSI_COLOR_RED"error"ANSI_COLOR_RESET" (%s)"ANSI_COLOR_RED": "ANSI_COLOR_RESET, error_strings[errorType]);
    
    switch (errorType){
        case COMMAND_LINE_PARAMS:
            printf("uso: ./compiler path/to/file");
            break;
        case IO:
            printf("file not found");
            break;
        case LEXICAL:
            printf("lexical error found in file");
            break;
        default:
            printf("an error has ocurred");
            break;
    }
    printf("\n");
}

void handleErrorWithFileStats(ErrorType errorType, char *msg, char *filename, unsigned long line){
    printf("%s: line %ld: ",filename, line);
    printf(ANSI_COLOR_RED"error"ANSI_COLOR_RESET" (%s)"ANSI_COLOR_RED": "ANSI_COLOR_RESET, error_strings[errorType]);
    
    switch (errorType){
        case LEXICAL:
            printf("lexical error found in file (%s found)", msg);
            break;
        default:
            printf("an error has ocurred");
            break;
    }
    printf("\n");
}