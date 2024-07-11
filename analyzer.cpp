#include <iostream>
#include <string>
#include <unordered_map>
#include <bits/stdc++.h>
#include <fstream>
#include <vector>
#include </home/ibrab00/Prog/Textualyzer/functions.cpp>

using namespace std;

int main() {
    string s, corpus, input;

    corpus = "/home/ibrab00/Downloads/mr.txt";
    // getline(cin, in);
    // cin.ignore(100, '\n');

    ifstream input_file(corpus);
    // ofstream output_file("/home/ibrab00/Prog/Textualyzer/output.txt");

    unordered_map<char, int>   monograms;  // Size: 99
    unordered_map<string, int> bigrams;    // Size: 2284
    unordered_map<string, int> trigrams;   // Size: 15715
    unordered_map<string, int> tetragrams; // Size: 64380


    while (getline(input_file, s)) {
        for (auto i: to_letters(s)) {
            if (monograms.find(i.first) != monograms.end()) {
                monograms[i.first] += 1;
            } else {
                monograms.insert(i);
            }
        }

        for (auto i: to_bigrams(s)) {
            if (bigrams.find(i.first) != bigrams.end()) {
                bigrams[i.first] += 1;
            } else {
                bigrams.insert(i);
            }
        }

        for (auto i: to_trigrams(s)) {
            if (trigrams.find(i.first) != trigrams.end()) {
                trigrams[i.first] += 1;
            } else {
                trigrams.insert(i);
            }
        }

        for (auto i: to_tetragrams(s)) {
            if (tetragrams.find(i.first) != tetragrams.end()) {
                tetragrams[i.first] += 1;
            } else {
                tetragrams.insert(i);
            }
        }
    }

    while (true) {        
        cout << "Prompt: ";
        getline(cin, input);
        cin.ignore(100, '\n');
        auto inputv = vectorize(input);

        if (inputv[0] == "freq") {
            switch (inputv[1].length()) {
                case 1: {
                    char letter = (inputv[1])[0];
                    float count = (monograms[letter]); 
                    cout << count << '\n';
                    break;
                }
                case 2: {
                    float count = (bigrams[inputv[1]]); 
                    cout << count << '\n';
                    break;
                }
                case 3: {
                    float count = (trigrams[inputv[1]]);
                    cout << count << '\n';
                    break;
                }
                case 4: {
                    float count = (tetragrams[inputv[1]]);
                    cout << setprecision(6);
                    cout << count << '\n';
                    break;
                }
            }
        }

        if (input == "quit") {
            break;
        }
    }

    // output_file << "Letters" << '\n';

    input_file.close();
    // output_file.close();
}