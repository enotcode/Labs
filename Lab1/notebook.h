#ifndef NOTEBOOK_H
#define NOTEBOOK_H

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

#endif
