#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void bucketSort(vector<string>& words) {
    vector<vector<string>> buckets(256);
    
    for (int i = 0; i < words.size(); i++) {
        unsigned char firstChar = words[i][0];
        buckets[firstChar].push_back(words[i]);
    }
    
    for (int i = 0; i < 256; i++) {
        if (!buckets[i].empty()) {
            vector<vector<string>> secondaryBuckets(256);
            
            for (const string& word : buckets[i]) {
                unsigned char secondChar = word[1];
                secondaryBuckets[secondChar].push_back(word);
            }
            
            for (int j = 0; j < 256; j++) {
                if (!secondaryBuckets[j].empty()) {
                    vector<vector<string>> tertiaryBuckets(256);
                    
                    for (const string& word : secondaryBuckets[j]) {
                        unsigned char thirdChar = word[2];
                        tertiaryBuckets[thirdChar].push_back(word);
                    }
                    
                    secondaryBuckets[j].clear();
                    for (int k = 0; k < 256; k++) {
                        for (const string& word : tertiaryBuckets[k]) {
                            secondaryBuckets[j].push_back(word);
                        }
                    }
                }
            }
            
            buckets[i].clear();
            for (int j = 0; j < 256; j++) {
                for (const string& word : secondaryBuckets[j]) {
                    buckets[i].push_back(word);
                }
            }
        }
    }
    
    words.clear();
    for (int i = 0; i < 256; i++) {
        for (const string& word : buckets[i]) {
            words.push_back(word);
        }
    }
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    
    if (!input.is_open() || !output.is_open()) {
        cerr << "Error opening files" << endl;
        return 1;
    }
    
    int N;
    input >> N;
    
    vector<string> words(N);
    for (int i = 0; i < N; i++) {
        input >> words[i];
    }
    
    bucketSort(words);
    
    for (const auto& word : words) {
        output << word << endl;
    }
    
    input.close();
    output.close();
    
    return 0;
}