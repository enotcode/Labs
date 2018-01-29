#include <iostream>
#include <cmath>
#include "integral.h"

using namespace std;

double f(double x) {
    return cos(x * x);
}

int main() {
    Box myBox;

    Integral I1;
    Integral I2(-2.0, 2.0, 0.01);
    Integral I3(I1);

    I1.rectangles();
    I2.trapezium();
    I3.simpson();

    myBox.save(I1);
    myBox.save(I2);
    myBox.save(I3);

    myBox.print();
    cout << "Sum: " << myBox.sum() << endl;
    cout << "Count: " << I1.getCounter();
    return 0;
}
