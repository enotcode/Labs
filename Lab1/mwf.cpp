#include <iostream>

using namespace std;

void read(int n, double **a) {
    cout << "Enter matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}

void write(int n, double **a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void swap(int n, double **a) {
    double max;
    int imax, jmax;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
                imax = i;
                jmax = j;
            }
        }
    }
    a[imax][jmax] = a[0][0];
    a[0][0] = max;
    for (int count = 1; count < n; count++) {
        max = a[0][1];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (((i != j) or ((i >= count) and (j >= count))) and (a[i][j] > max)) {
                    max = a[i][j];
                    imax = i;
                    jmax = j;
                }
        a[imax][jmax] = a[count][count];
        a[count][count] = max;
    }
}

int findPositive(int n, double **a) {
    for (int i = 0; i < n; i++) {
        int number = 0;
        for (int j = 0; j < n; j++)
            if (a[i][j] < 0) {
                number++;
            }
        if (number == n) {
            cout << "Line #" << i + 1 << " does not contain any positive elements";
            return 0;
        }
    }
    cout << "All lines contain positive elements";
    return 0;
}

int main() {
    int n;
    cout << "Enter matrix size: ";
    cin >> n;
    double **arr = new double *[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new double[n];
    }

    read(n, arr);
    swap(n, arr);
    write(n, arr);
    findPositive(n, arr);
    return 0;
}
