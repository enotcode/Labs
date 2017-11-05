#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "notebook.h"
#include "note.h"

using namespace std;


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
