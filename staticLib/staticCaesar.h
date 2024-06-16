#pragma once

#if defined(_WIN32) || defined(_WIN64)
    #define EXPORT __declspec(dllexport)
#else
    #define EXPORT __attribute__((visibility("default")))
#endif
extern "C" {
    EXPORT char* caesarEncr(char* text, int encrKey);
    EXPORT char* caesarDecr(char* text, int decrKey);
}
