#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctype.h"

char* cipher(char *string, int offset) {
    // Array
    int *alphabet = malloc(26 * sizeof(char *));
    alphabet[0] = 'a';
    alphabet[1] = 'b';
    alphabet[2] = 'c';
    alphabet[3] = 'd';
    alphabet[4] = 'e';
    alphabet[5] = 'f';
    alphabet[6] = 'g';
    alphabet[7] = 'h';
    alphabet[8] = 'i';
    alphabet[9] = 'j';
    alphabet[10] = 'k';
    alphabet[11] = 'l';
    alphabet[12] = 'm';
    alphabet[13] = 'n';
    alphabet[14] = 'o';
    alphabet[15] = 'p';
    alphabet[16] = 'q';
    alphabet[17] = 'r';
    alphabet[18] = 's';
    alphabet[19] = 't';
    alphabet[20] = 'u';
    alphabet[21] = 'v';
    alphabet[22] = 'w';
    alphabet[23] = 'x';
    alphabet[24] = 'y';
    alphabet[25] = 'z';
    // String loop
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == " ") {
            continue;
        }
        if (string[i] == "\0") {
            string[i] = "";
            continue;
        }
            // Alphabet loop
            for (int k = 0; k < 26; k++) {
                // Check corresponding array value to letter
                if (alphabet[k] == string[i]) {
                    // Calculate new array value
                    if ((k + offset) > 25) {
                        string[i] = alphabet[k + offset - 26];
                        break;
                    }
                    else {
                        string[i] = alphabet[k + offset];
                        break;
                    }
                }
                else if (toupper(alphabet[k]) == string[i]) {
                    if ((k + offset) > 25) {
                        string[i] = toupper(alphabet[k + offset - 26]);
                        break;
                    }
                    else {
                        string[i] = toupper(alphabet[k + offset]);
                        break;
                    }
                }
            }
    }
    free(alphabet);
    return string;
}


int main() {
    int *cipher_offset = malloc(sizeof (int) * 26);
    char *answer;
    printf("Caesar Cipher generator\n");
    printf("Enter phrase:");
    answer = malloc(sizeof (char) * 5000);
    fgets(answer,5000 * sizeof(char),stdin);
    printf("Enter the cipher Offset(0-25):");
    *cipher_offset = atoi(fgets(cipher_offset,5000 * sizeof(char),stdin));
    printf("The encrypted phrase is %s", cipher(answer, *cipher_offset));
    free(answer);
    free(cipher_offset);
    printf("Press Enter to close...");
    getchar();
    return 0;
}
