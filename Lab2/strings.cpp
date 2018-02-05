#include <iostream>

using namespace std;

class Str {
private:
    string str;
public:
    Str(string str) {
        this->str = str;
    }

    void operator+(string str1) {
        str += str1;
    }

    void operator-(string str1) {
        unsigned long t = str.find(str1);
        if (t != string::npos)
            str.erase(t, str1.length());

    }

    void operator*(int n) {
        for (int i = 0; i < n - 1; i++) {
            str += str;
        }
    }

    string getStr() {
        return str;
    }
};


int main() {
    Str S("Lorem ipsum");
    S + " dolor sit amet,\n";
    S - ",";
    S * 3;
    cout << S.getStr();
    return 0;
}
