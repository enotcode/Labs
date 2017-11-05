#include <iostream>

using namespace std;

template<typename T>
void positiveElements(T *array, int n) {
    int count = 0;
    for (int ix = 0; ix < n; ix++) {
        if (array[ix] > 0) {
            count++;
        }
    }
}

template<typename T>
void sortArray(T *array, int n) {
    T tmp;
    for (int ix = 0; ix < n - 1; ix++) {
        for (int jx = 0; jx < n - ix - 1; jx++) {
            if (array[jx] > array[jx + 1]) {
                tmp = array[jx];
                array[jx] = array[jx + 1];
                array[jx + 1] = tmp;
            }
        }
    }
}

template<typename T>
void outArray(T *array, int n) {
    for (int ix = 0; ix < n; ix++) {
        cout << array[ix] << " ";
    }
}

template<typename T>
void sumArray(T *array, int n, int number) {
    int sum = 0;
    for (int ix = number; ix < n; ix++) {
        sum += array[ix];
    }
    cout << "Sum = " << sum << endl;
}

int main() {
    int n, number;
    cout << "Enter amount elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 0) {
            number = i;
        }
    }

    positiveElements(arr, n);
    sumArray(arr, n, number);
    sortArray(arr, n);
    outArray(arr, n);

    cout << endl;
    return 0;
}
