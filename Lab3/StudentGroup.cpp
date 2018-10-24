#include <iostream>
#include <vector>

using namespace std;

class Student {
public:
    string name;
    string surname;
    string date;
    string phone;

    Student(string name, string surname, string date, string phone) {
        this->name = name;
        this->surname = surname;
        this->date = date;
        this->phone = phone;
    }
};

class StudentGroup {
    vector<Student> group;
public:
    void addStudent(Student st) {
        group.push_back(st);
    }

    void deleteStudent(int id) {
        group.erase(group.begin() + id);
    }

    void sortByDate() {
        for (int i = 0; i < group.size() - 1; i++) {
            for (int j = 0; j < group.size() - i - 1; j++) {
                if (group[j].date > group[j + 1].date) std::swap(group[j], group[j + 1]);
            }
        }
    }

    void FindByName(string name) {
        for (int i = 0; i < group.size(); i++) {
            if (group[i].name == name) {
                cout << i << ". " << group[i].name << " " << group[i].surname << "\t" << group[i].date << "\t"
                     << group[i].phone
                     << endl;
                break;
            }
        }
    }

    void FindBySurname(string surname) {
        for (int i = 0; i < group.size(); i++) {
            if (group[i].surname == surname) {
                cout << i << ". " << group[i].name << " " << group[i].surname << "\t" << group[i].date << "\t"
                     << group[i].phone
                     << endl;
                break;
            }
        }
    }

    void print() {
        for (int i = 0; i < group.size(); i++)
            cout << i << ". " << group[i].name << " " << group[i].surname << "\t" << group[i].date << "\t"
                 << group[i].phone
                 << endl;
    }
};

int main() {
    int n;
    string name, surname, date, phone;
    StudentGroup MyGroup;

    cout << "Меню:\n" << "1. Добавить студента\n" << "2. Удалить студента" << "3. Сортировать по дате рождения\n"
         << "4. Найти студента по имени\n" << "5. Найти студента по фамилии\n" << "6. Вывести список" << endl;
    cout << "Чтобы выйти введите 0" << endl;

    while (cin >> n and n != 0)
        switch (n) {
            case 1: {
                cout << "--- Добавление студента ---" << endl;
                cout << "Введите имя: ";
                cin >> name;
                cout << "Введите фамилию: ";
                cin >> surname;
                cout << "Введите дату рождения: ";
                cin >> date;
                cout << "Введите номер телефона: ";
                cin >> phone;

                Student st(name, surname, date, phone);
                MyGroup.addStudent(st);
                cout << "Студент добавлен!" << endl;

            }
                break;
            case 2: {
                cout << "Введите номер студента, чтобы удалить его из списка: ";
                int number;
                cin >> number;
                MyGroup.deleteStudent(number);
                cout << "Студент удален!" << endl;

            }
                break;
            case 3: {
                MyGroup.sortByDate();
                cout << "Список отсортирован!" << endl;
            }
                break;
            case 4: {
                cout << "Введите имя: ";
                cin >> name;
                MyGroup.FindByName(name);
            }
                break;
            case 5: {
                cout << "Введите фамилию: ";
                cin >> surname;
                MyGroup.FindBySurname(surname);
            }
                break;
            case 6: {
                MyGroup.print();
            }
                break;
        }
    return 0;
}