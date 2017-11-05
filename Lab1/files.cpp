#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream fin("data.dat");
    char buff[70];
    while (!fin.eof()){
    fin.getline(buff, 70);
    cout << buff << endl;
    }
    cout << endl << "Enter word: ";
    char word[25], ch[1];
    cin >> word;
    fin.clear();
    fin.seekg(0, ios::beg);
    while (!fin.eof()){
        fin >> ch;
        if (ch[0] != '.'){
            cout << ch << word;
        }
        else{
            cout << ch;
        }
    }
    fin.close();
    cout << endl;
}
