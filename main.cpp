#include <iostream>
#include <stdio.h>
#include "CaesarEncr.cpp"

using namespace std;

char* takeInput() {
    char* result;
    char ch;
    int idx = 0;
    while (cin.get(ch) && ch != '\n') {
        result[idx] = ch;
        idx++;
    }
    result[idx] = '\0';
    return result;
}
int main() {
    
    cout << "Enter the word which needs to be encrypted" << endl;
    char* text = takeInput();

    int key;
    cout << "Enter the key of encryption (int from 1 to 25)" << endl;
    cin >> key;

    char* encrypted = CaesarEncr(text, key);
    cout << encrypted << endl;

    char* decrypted = CaesarDecr(text, key);
    cout << decrypted << endl;
    return 0;
}