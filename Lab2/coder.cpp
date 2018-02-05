#include <iostream>

using namespace std;

class People {
private:
    int health;
public:
    People(int h) : health(h) {}

    void getHealth() {
        cout << health << endl;
    }
};


class Programmer : virtual public People {
private:
    int codeSpeed;
public:
    Programmer(int h, int s) : People(h), codeSpeed(s) {}

    void getCodeSpeed() {
        cout << codeSpeed << endl;
    }
};


class SuperCoder : virtual public People, virtual public Programmer {
private:
    int coffeeLiters;
public:
    SuperCoder(int h, int s, int l) : People(h), Programmer(h, s), coffeeLiters(l) {}

    void getCoffeeLiters() {
        cout << coffeeLiters << endl;
    }
};


int main() {
    SuperCoder Coder(10, 15, 20);

    Coder.getHealth();
    Coder.getCodeSpeed();
    Coder.getCoffeeLiters();
    return 0;
}
