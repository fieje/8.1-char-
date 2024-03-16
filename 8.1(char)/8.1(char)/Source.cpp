#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int Count(char* s) {
    int k = 0, pos = 0;
    char* t;
    while ((t = strchr(s + pos, '+'))) {
        if (t[1] && t[1] == '-') 
            k++;
        pos = t - s + 1;
    }
    return k;
}

char* Change(char* s) {
    char* t = new char[strlen(s) * 4 + 1]; 
    char* p;
    int pos1 = 0, pos2 = 0;
    *t = 0;
    while ((p = strstr(s + pos1, "+-"))) { 
        pos2 = p - s + 2; 
        strncat(t, s + pos1, pos2 - pos1 - 2); 
        strcat(t, "****"); 
        pos1 = pos2; 
    }

    strcat(t, s + pos1);
 
    int len = strlen(t);
    for (int i = 0; i < len; i++) {
        if (t[i] == '.') {
            strcat(t, "**");
            len += 2; 
            i++; 
        }
    }
    strcpy(s, t); 
    delete[] t; 
    return s;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    int countDots = 0, dotIndex = -1;
    for (int i = strlen(str) - 1; i >= 0; i--) {
        if (str[i] == '.') {
            countDots++;
            if (countDots == 4) {
                dotIndex = i;
                break;
            }
        }
    }
    if (dotIndex != -1)
        cout << "Index of the fourth dot from the end: " << dotIndex << endl;
    else
        cout << "There are less than four dots in the string." << endl;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '.')
            str[i] = '*';
    }

    cout << "String contained " << Count(str) << " groups of '+ -'" << endl;

    Change(str);

    cout << "Modified string: " << str << endl;

    return 0;
}