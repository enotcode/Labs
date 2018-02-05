#include <iostream>

using namespace std;

class figure {
protected:
    double x, y;
public:
    void set(double x, double y) {
        this->x = x;
        this->y = y;
    }

    virtual void getArea() = 0;
};

class Rectangle : public figure {
public:
    void getArea() {
        cout << x * y << endl;
    }
};

class Triangle : public figure {
public:
    void getArea() {
        cout << x * y / 2 << endl;
    }
};

int main() {
    Rectangle R;
    Triangle T;

    R.set(5.2, 2.5);
    T.set(1.0, 5.5);

    R.getArea();
    T.getArea();
    return 0;
}
