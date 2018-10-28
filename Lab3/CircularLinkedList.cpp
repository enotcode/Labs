#include <iostream>

using namespace std;

template<typename T>
struct Node {
    T data;
    Node *next;
    Node *prev;
};

template<typename T>
class List {
public:
    List();

    ~List();

    T end() const;

    T begin() const;

    bool is_empty() const;

    void push_front(T);

    T pop_front();

    void push_back(T);

    T pop_back();

    void print() const;

    int size() const;

    void sort();

private:
    Node<T> *head;
};

template<typename T>
T List<T>::begin() const {
    if (!is_empty()) {
        return head->data;
    } else {
        cout << "List is empty.";
        exit(1);
    }
}

template<typename T>
T List<T>::end() const {
    if (!is_empty()) {
        return head->prev->data;
    } else {
        cout << "List is empty.";
        exit(1);
    }
}

template<typename T>
void List<T>::sort() {
    if (!is_empty()) {
        Node<T> *i = head, *j = head;
        do {
            do {
                if (j->data > j->next->data) {
                    T tmp = j->data;
                    j->data = j->next->data;
                    j->next->data = tmp;
                }
                j = j->next;
            } while (j != head->prev);
            i = i->next;
        } while (i != head);
    } else {
        cout << "List is empty.";
        exit(1);
    }
}

template<typename T>
List<T>::~List() {
    if (!is_empty()) {
        Node<T> *cur = head->next;
        while (cur != head) {
            cur = cur->next;
            delete cur->prev;
        }
        delete cur;
    }
}


template<typename T>
int List<T>::size() const {
    if (is_empty())
        return 0;
    else {
        Node<T> *cur = head;
        int cnt = 0;
        do {
            ++cnt;
            cur = cur->next;
        } while (cur != head);
        return cnt;
    }
}

template<typename T>
List<T>::List() : head(0) {}

template<typename T>
bool List<T>::is_empty() const {
    return !head;
}

template<typename T>
void List<T>::push_front(T d) {
    if (is_empty()) {
        head = new Node<T>;
        head->data = d;
        head->next = head;
        head->prev = head;
    } else {
        Node<T> *tmp = new Node<T>;
        tmp->data = d;
        tmp->next = head;
        tmp->prev = head->prev;
        (head->prev)->next = tmp;
        head->prev = tmp;
        head = tmp;
    }
}

template<typename T>
void List<T>::print() const {
    if (!is_empty()) {
        Node<T> *cur = head;
        do {
            cout << cur->prev << " / " << cur->data << " " << cur << " / " << cur->next << endl;
            cur = cur->next;
        } while (cur != head);
    } else
        cout << "List is empty";
}

template<typename T>
T List<T>::pop_front() {
    if (!is_empty()) {
        T d = head->data;
        Node<T> *tmp = head;

        (head->next)->prev = head->prev;
        (head->prev)->next = head->next;
        if (head == head->next)
            head = 0;
        else
            head = head->next;
        delete tmp;

        return d;
    } else {
        cout << "List is empty";
        exit(1);
    }

}

template<typename T>
void List<T>::push_back(T d) {
    if (is_empty()) {
        head = new Node<T>;
        head->data = d;
        head->next = head;
        head->prev = head;
    } else {
        Node<T> *tmp = new Node<T>;
        tmp->data = d;
        tmp->next = head;
        tmp->prev = head->prev;
        (head->prev)->next = tmp;
        head->prev = tmp;
    }
}

template<typename T>
T List<T>::pop_back() {
    if (!is_empty()) {
        Node<T> *tmp = head->prev;
        T d = tmp->data;
        if (tmp == head) {
            head = 0;
        } else {
            ((head->prev)->prev)->next = head;
            head->prev = (head->prev)->prev;
        }
        delete tmp;
        return d;
    } else {
        cout << "List is empty.";
        exit(1);
    }
}


int main() {
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_front(3);

    l.sort();
    l.pop_back();
    l.pop_front();

    l.print();
    return 0;
}