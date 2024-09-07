#include <stdio.h>
#include <stdlib.h>

#include "bmh.h"
#include "bruteForce.h"
#include "io.h"
#include "shiftAnd.h"

#define MAX_PATTERN 100
#define MAX_TEXT 10000

int main(int argc, char const *argv[]) {
    (void)argc;
    FILE* file; FILE* out;
    char* pattern; char* text;
    int cont, position, patternSize, textSize;

    file = fopen(argv[1], "r");
    out = fopen("output.txt", "w");
    
    int algorithm = atoi(argv[2]);

    fscanf(file, "%d ", &cont);
    for (int i = 0; i < cont; i++) {
        pattern = createString(file, &patternSize, 0, MAX_PATTERN);
        text = createString(file, &textSize, patternSize, (MAX_TEXT+patternSize));

        switch (algorithm) {
            case 1:
                position = bruteForce(text, textSize, pattern, patternSize);
                break;
            case 2:
                position = bmh(text, textSize, pattern, patternSize);
                break;
            case 3:
                position = shift_and(text, textSize, pattern, patternSize);
                break;
            default:
                printf("O algoritmo escolhido não existe!\n");
                break;  
        }

        output(out, position);
        free(pattern);
        free(text);
    }

    fclose(file);
    fclose(out);
}