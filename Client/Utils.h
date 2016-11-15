#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <windows.h>
using namespace std;

int length(string a);
bool issame(string a, string b);
bool contains(string a, char b);
bool is_number(char a);
LPCSTR LPCSTRfromString(char* a);

#endif // UTILS_H
