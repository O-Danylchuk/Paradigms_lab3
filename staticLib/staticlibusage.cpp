#include <iostream>
#include "staticCaesar.h"

int main() {
    char text[] = "HelloWorld";
    int key = 3;

    std::cout << "Original text: " << text << std::endl;
    caesarEncr(text, key);
    std::cout << "Encrypted text: " << text << std::endl;
    caesarDecr(text, key);
    std::cout << "Decrypted text: " << text << std::endl;

    return 0;
}
