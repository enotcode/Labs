#include <iostream>

using namespace std;

const int LEN = 50, SIZE = 8;

struct ZNAK {
    char name[LEN];
    char sname[LEN];
    char zodiac[LEN];
    int birthday[3];
};


int main() {
    ZNAK a[SIZE];
    int month, count = 0;
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter your first name and second name: ";
        cin >> a[i].name >> a[i].sname;
        cout << "Enter your zodiac sign: ";
        cin >> a[i].zodiac;
        cout << "Enter day of your birth: ";
        cin >> a[i].birthday[0];
        cout << "Enter month of your birth: ";
        cin >> a[i].birthday[1];
        cout << "Enter year of your birth: ";
        cin >> a[i].birthday[2];
    }
    cout << endl;
    cout << "Enter month: ";
    cin >> month;
    for (int i = 0; i < SIZE; i++) {
        if (a[i].birthday[1] == month) {
            cout << a[i].name << " " << a[i].sname << endl << a[i].zodiac << endl << a[i].birthday[0] << "/"
                 << a[i].birthday[1] << "/" << a[i].birthday[2] << endl;
            count++;
        }
    }
    if (count == 0) {
        cout << "Not found!";
    }
    return 0;
}
