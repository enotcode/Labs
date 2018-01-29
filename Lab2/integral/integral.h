#ifndef PROJECT_INTEGRAL_H
#define PROJECT_INTEGRAL_H

#include <vector>

double f(double arg);

class Box;

class Integral {
private:
    double I;
    double a, b, h, n;
    static int counter;
    friend Box;

public:
    Integral();

    Integral(double, double, double);

    Integral(const Integral &In);

    ~Integral();

    void rectangles();

    void trapezium();

    void simpson();

    int getCounter();

    double getIntegral();
};

class Box {
private:
    std::vector<double> arr;
    double s;

public:
    Box();

    ~Box();

    void save(Integral &);

    void print();

    double sum();
};

#endif
