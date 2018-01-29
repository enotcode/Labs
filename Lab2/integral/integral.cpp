#include <iostream>
#include <vector>
#include <cmath>

#include "integral.h"

int Integral::counter;

Integral::Integral() {
    a = 1.0;
    b = 3.0;
    h = 0.2;
    counter++;
}

Integral::Integral(double a, double b, double h) {
    this->a = a;
    this->b = b;
    this->h = h;
    counter++;
}

Integral::Integral(const Integral &In) {
    I = In.I;
    a = In.a;
    b = In.b;
    h = In.h;
    counter++;
}

Integral::~Integral() {
    counter--;
}

void Integral::rectangles() {
    n = (b - a) / h;
    for (int j = 1; j <= n; j++) {
        I = I + h * f(a + h * (j - 0.5));
    }
}

void Integral::trapezium() {
    n = (b - a) / h;
    I = h * (f(a) + f(b)) / 2.0;
    for (int j = 1; j <= n - 1; j++) {
        I = I + h * f(a + h * j);
    }
}

void Integral::simpson() {
    n = (b - a) / h;
    I = h * (f(a) + f(b)) / 6.0;
    for (int j = 1; j <= n; j++) {
        I = I + 4.0 / 6.0 * h * f(a + h * (j - 0.5));
    }
    for (int j = 1; j <= n - 1; j++) {
        I = I + 2.0 / 6.0 * h * f(a + h * j);
    }
}

double Integral::getIntegral() {
    return I;
}


int Integral::getCounter() {
    return counter;
}

Box::Box() {
    s = 0;
}

Box::~Box() {
    arr.clear();
}

void Box::save(Integral &Ix) {
    arr.push_back(Ix.getIntegral());
}

double Box::sum() {
    for (int i = 0; i < arr.size(); i++) {
        s += arr[i];
    }
    return s;
}

void Box::print() {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << std::endl;
    }
}
