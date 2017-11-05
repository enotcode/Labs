#include <iostream>

using namespace std;

int main() {
    double a, b, c, x, Xend, dX, f;
    cout << "Enter a, b, c, x, Xend, dX: ";
    cin >> a >> b >> c >> x >> Xend >> dX;
    while (x <= Xend) {
        if (x + 10 < 0) {
            f = a * x * x - c * x + b;
        } else if (x + 10 > 0) {
            f = (x - a) / (x - c);
        } else {
            f = (-x) / (a - c);
        }
        if ((int(a) | int(b)) & !(int(a) | int(b)) == 0) {
            f = int(f);
        }
        cout << "x = " << x << " f = " << f << endl;
        x += dX;
    }
    return 0;
}