#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void quickSort(vector<int> &a, int left, int right) {
    if (left > right) return;
    
    int p = a[(left + right) / 2];
    int i = left;
    int j = right;
    
    while (i <= j) {
        while (a[i] < p) {
            i++;
        }
        while (a[j] > p) {
            j--;
        }
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    
    quickSort(a, left, j);
    quickSort(a, i, right);
}

int main() {
    ifstream input("C:\\c++ projectX\\input.txt");
    ofstream output("output.txt");

    int N, L;
    input >> N >> L;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        input >> a[i];
    }

    quickSort(a, 0, N - 1);

    long long totalTime = 0;
    for (int i = 0; i < N; ++i) {
        if (i == 0) {
            totalTime = a[i] + L;
        } else {
            totalTime = max(totalTime, (long long)a[i]) + L;
        }
    }

    output << totalTime;

    input.close();
    output.close();

    return 0;
}
