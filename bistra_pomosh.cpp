#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int N, L;
    input >> N >> L;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        input >> a[i];
    }

    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

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