#include "staticCaesar.h"

char* caesarEncr(char* text, int encrKey) {
    int textLen = 0;
    while (text[textLen] != '\0') {
        if (65 <= (int)text[textLen] && (int)text[textLen] <= 90) {
            text[textLen] = char((int(text[textLen] + encrKey - 65) % 26 + 26) % 26 + 65);
        }
        else if (97 <= (int)text[textLen] && (int)text[textLen] <= 122) {
            text[textLen] = char((int(text[textLen] + encrKey - 97) % 26 + 26) % 26 + 97);
        }
        textLen++;
    }
    return text;  
}

char* caesarDecr(char* text, int decrKey) {
    int textLen = 0;
    while (text[textLen] != '\0') {
        if (65 <= (int)text[textLen] && (int)text[textLen] <= 90) {
            text[textLen] = char((int(text[textLen] - decrKey - 65) % 26 + 26) % 26 + 65);
        }
        else if (97 <= (int)text[textLen] && (int)text[textLen] <= 122) {
            text[textLen] = char((int(text[textLen] - decrKey - 97) % 26 + 26) % 26 + 97);
        }
        textLen++;
    }
    return text;  
}


