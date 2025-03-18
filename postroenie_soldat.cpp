#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Soldier {
    double height;
    string name;
    int originalPosition;
};

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    int n;
    fin >> n;
    
    vector<Soldier> soldiers(n);
    
    for (int i = 0; i < n; i++) {
        fin >> soldiers[i].height >> soldiers[i].name;
        soldiers[i].originalPosition = i;
    }
    
    long long totalSwaps = 0;
    
    for (int i = 0; i < n; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (soldiers[j].height > soldiers[maxIndex].height) {
                maxIndex = j;
            }
        }
        
        while (maxIndex > i) {
            swap(soldiers[maxIndex], soldiers[maxIndex - 1]);
            totalSwaps++;
            maxIndex--;
        }
    }
    
    fout << totalSwaps << endl;
    
    fin.close();
    fout.close();
    
    return 0;
}