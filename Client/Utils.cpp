#include "Utils.h"
#include <windows.h>
#include <iostream>

#include <stdio.h>
#include <stdlib.h>

int length(string a){
    int i = 0;
    for(i = 0; a[i] != '\0'; i++);
    return i;
}

bool issame(string a, string b){
    bool ret = false;
    if(length(a) == length(b)){
        int c = 0;
        for(int i = 0; a[i] != '\0'; i++){
            if(a[i] == b[i]){
                c++;
            } else break;
        }
        if(c == length(a)) ret = true;
    }

    return ret;
}

bool contains(string a, char b){
    bool res = false;
    for(int i = 0; a[i] != '\0'; i++){
        if(a[i] == b){
            res = true;
            break;
        }
    }

    return res;
}
bool is_number(char a){
    bool f = false;
    for(int i = 0; i < 10; i++){
        if((int)a == (i+48)){
            f = true;
            break;
        }
    }
    return f;
}

LPCSTR LPCSTRfromString(char* a){
    return (LPCSTR) a;
}
