#include <iostream>

using namespace std;

const int size = 7;

static int value;

class Number {
private:
    int n;
public:
    Number(int n) {
        this->n = n;
    }

    friend ostream &operator<<(ostream &stream, Number &item) {
        return stream << item.n;
    }

};


void create() {
    class Array : public Number {
    public:
        Array() : Number(value++) {}
    };

    Array array[size];

    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
}

int main() {
    create();
    return 0;
}
