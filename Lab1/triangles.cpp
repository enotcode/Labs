#include <iostream>

using namespace std;

struct points {
    int x, y;
};

int main() {
    int result = 0;
    int n;

    cout << "Enter count points: ";
    cin >> n;
    points arr[n];
    triangles T[n];

    cout << "Enter coordinates: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i].x * (arr[j].y - arr[k].y) - arr[i].y * (arr[j].x - arr[k].x) +
                    1 * (arr[j].x * arr[k].y - arr[j].y * arr[k].x)) {
                    result++;
                }
            }
        }
    }
    cout << "Number of triangles: " << result;
    return 0;
}
