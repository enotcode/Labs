#ifndef NOTE
#define NOTE

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "notebook.h"

using namespace std;

NOTEBOOK a[16];
char s[76];
char tmp[10];

void read() {
    ifstream fin("note.txt");
    int i = 0;
    while (!fin.eof()) {
        fin.getline(s, 76);

        strncpy(a[i].model, s, 19);

        strncpy(tmp, s + 19, 4);
        a[i].price = atoi(tmp);

        strncpy(tmp, s + 50, 4);
        a[i].d = atof(tmp);

        strncpy(tmp, s + 70, 5);
        a[i].hdd = atof(tmp);

        strncpy(tmp, s + 67, 2);
        a[i].f = atoi(tmp);

        strncpy(tmp, s + 57, 4);
        a[i].res.x = atoi(tmp);

        strncpy(tmp, s + 62, 4);
        a[i].res.y = atoi(tmp);

        i++;
    }
    fin.close();
}

void write(int k, NOTEBOOK arr[16]) {
    ofstream fout("note.bin", ios::binary);
    for (int i = 0; i < k; i++) {
        fout << &k << &arr[i].model << &arr[i].price << &arr[i].d << &arr[i].f << &arr[i].res.x << &arr[i].res.y;
    }
    fout.close();
}

#endif
