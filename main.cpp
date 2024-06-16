#include <iostream>
#include <stdio.h>

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
    
    typedef char*(*CaesarEncr_ptr_t)(char*, int);
    typedef char*(*CaesarDecr_ptr_t)(char*, int);

    #if defined(_WIN32) || defined(_WIN64)
        #include <windows.h>
        HINSTANCE handle = LoadLibrary(TEXT("CaesarEncr.dll"));
        if (handle == nullptr || handle == INVALID_HANDLE_VALUE) {
            cout << "Library not found" << endl;
        return 1;
        CaesarEncr_ptr_t CaesarEncr_ptr = (CaesarEncr_ptr_t)GetProcAddress(handle, "CaesarEncr");
        if (CaesarEncr_ptr == nullptr) {
            cout << "CaesarEncr function not found" << endl;
            FreeLibrary(handle);
            return 1;
        }

        CaesarDecr_ptr_t CaesarDecr_ptr = (CaesarDecr_ptr_t)GetProcAddress(handle, "CaesarDecr");
        if (CaesarDecr_ptr == nullptr) {
            cout << "CaesarDecr function not found" << endl;
            FreeLibrary(handle);
            return 1;
        }
    }
    #else
        #include <dlfcn.h>
        void* handle = dlopen("./caesar.so", RTLD_LAZY);
        if (!handle) {
            cout << "Library not found: " << dlerror() << endl;
        return 1;
        }
        dlerror(); 

        CaesarEncr_ptr_t CaesarEncr_ptr = (CaesarEncr_ptr_t)dlsym(handle, "CaesarEncr");
        const char* dlsym_error = dlerror();
        if (dlsym_error) {
            cout << "CaesarEncr function not found: " << dlsym_error << endl;
            dlclose(handle);
            return 1;
        }

        CaesarDecr_ptr_t CaesarDecr_ptr = (CaesarDecr_ptr_t)dlsym(handle, "CaesarDecr");
        dlsym_error = dlerror();
        if (dlsym_error) {
            cout << "CaesarDecr function not found: " << dlsym_error << endl;
            dlclose(handle);
            return 1;
        }
    #endif

    cout << "Enter the words which needs to be encrypted:" << endl;
    char* text = takeInput();

    int key;
    cout << "Enter the key of encryption (int from 1 to 25):" << endl;
    cin >> key;

    char* encrypted = CaesarEncr_ptr(text, key);
    cout << encrypted << endl;

    char* decrypted = CaesarDecr_ptr(text, key);
    cout << decrypted << endl;
    return 0;
}