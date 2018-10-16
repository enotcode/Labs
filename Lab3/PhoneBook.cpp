#include <iostream>
#include <vector>

using namespace std;

struct Base {
    string from;
    string to;
    string date;
    string time;
    int duration;
};

vector<Base> add(vector<Base> &data, string from, string to, string date, string time, int duration) {
    Base tmp = {from, to, date, time, duration};
    data.push_back(tmp);
    return data;
}

vector<Base> del(vector<Base> &data, int i) {
    data.erase(data.begin() + i);
    return data;
}

vector<Base> sortByDate(vector<Base> &data) {
    for (int i = 0; i < data.size() - 1; i++) {
        for (int j = 0; j < data.size() - i - 1; j++) {
            if (data[j].date > data[j + 1].date) std::swap(data[j], data[j + 1]);
        }
    }
    return data;
}

vector<Base> sortByTime(vector<Base> &data) {
    for (int i = 0; i < data.size() - 1; i++) {
        for (int j = 0; j < data.size() - i - 1; j++) {
            if (data[j].time > data[j + 1].time) std::swap(data[j], data[j + 1]);
        }
    }
    return data;
}

vector<Base> sortByDuration(vector<Base> &data) {
    for (int i = 0; i < data.size() - 1; i++) {
        for (int j = 0; j < data.size() - i - 1; j++) {
            if (data[j].duration > data[j + 1].duration) std::swap(data[j], data[j + 1]);
        }
    }
    return data;
}

vector<Base> findByFrom(vector<Base> &data, string from) {
    bool flag = false;
    cout << "ID\t\tFrom\t\tTo\t\t\tDate\t\t\tTime\t\tDuration" << endl;
    for (int i = 0; i < data.size(); i++) {
        if (data[i].from == from) {
            cout << i << "\t\t" << data[i].from << "\t\t" << data[i].to << "\t\t" << data[i].date << "\t\t"
                 << data[i].time << "\t\t"
                 << data[i].duration << endl;
            flag = true;
        }
    }
    if (!flag) cout << "Not found" << endl;
    return data;
}

vector<Base> findByTo(vector<Base> &data, string to) {
    bool flag = false;
    cout << "ID\t\tFrom\t\tTo\t\t\tDate\t\t\tTime\t\tDuration" << endl;
    for (int i = 0; i < data.size(); i++) {
        if (data[i].to == to) {
            cout << i << "\t\t" << data[i].from << "\t\t" << data[i].to << "\t\t" << data[i].date << "\t\t"
                 << data[i].time << "\t\t"
                 << data[i].duration << endl;
            flag = true;
        }
    }
    if (!flag) cout << "Not found" << endl;
    return data;
}

void show(vector<Base> d) {
    cout << "ID\t\tFrom\t\tTo\t\t\tDate\t\t\tTime\t\tDuration" << endl;
    for (int i = 0; i < d.size(); i++)
        cout << i << "\t\t" << d[i].from << "\t\t" << d[i].to << "\t\t" << d[i].date << "\t\t" << d[i].time << "\t\t"
             << d[i].duration << endl;
}

int main() {
    vector<Base> data;

    add(data, "Petya", "Vasya", "04.09.2018", "12:07", 12);
    add(data, "Vasya", "Petya", "07.09.2018", "11:07", 4);
    add(data, "Vasya", "Alina", "02.09.2018", "09:07", 2);

    del(data, 1);

    sortByDate(data);
    show(data);

    sortByTime(data);
    show(data);

    sortByDuration(data);
    show(data);

    findByFrom(data, "Petya");

    findByTo(data, "Alina");

    return 0;
}
