#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct NOTEBOOK {
    struct disp_res {
        int x;
        int y;
    } res;
    int f;
    float d;
    float hdd;
    int price;
    char model[21];
};

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

int main() {
    int k = 0;
    NOTEBOOK new_a[16], tmp[1];
    read();
    for (int i = 0; i < 16; i++) {
        if (a[i].hdd > 1.0) {
            strncpy(new_a[k].model, a[i].model, 19);
            new_a[k].price = a[i].price;
            new_a[k].d = a[i].d;
            new_a[k].f = a[i].f;
            new_a[k].res.x = a[i].res.x;
            new_a[k].res.y = a[i].res.y;
            k++;
        }
    }
    for (int i = 0; i < k - 1; i++) {
        if (new_a[i].d < new_a[i + 1].d) {
            tmp[0] = new_a[i];
            new_a[i] = new_a[i + 1];
            new_a[i + 1] = tmp[0];
        }
    }
    write(k, new_a);
    cout << "OK" << endl;
    return 0;
}
