#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter matrix size: ";
    cin >> n;
    double max;
    int imax, jmax;

    double **arr = new double *[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new double[n];
    }

    cout << "Enter matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] > max) {
                max = arr[i][j];
                imax = i;
                jmax = j;
            }
        }
    }
    arr[imax][jmax] = arr[0][0];
    arr[0][0] = max;
    for (int count = 1; count < n; count++) {
        max = arr[0][1];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (((i != j) or ((i >= count) and (j >= count))) and (arr[i][j] > max)) {
                    max = arr[i][j];
                    imax = i;
                    jmax = j;
                }
        arr[imax][jmax] = arr[count][count];
        arr[count][count] = max;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    for (int i = 0; i < n; i++) {
        int number = 0;
        for (int j = 0; j < n; j++)
            if (arr[i][j] < 0) {
                number++;
            }
        if (number == n) {
            cout << "Line #" << i + 1 << " does not contain any positive elements";
            return 0;
        }
    }
    cout << "All lines contain positive elements";
    delete[] arr;
    return 0;
}
