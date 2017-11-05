#include <iostream>

using namespace std;


int main() {
    int n, count = 0, number, sum = 0, tmp;
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
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            count++;
        }
    }
    for (int i = number; i < n; i++) {
        sum += arr[i];
    }
    cout << count << " " << sum << endl;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;

}
