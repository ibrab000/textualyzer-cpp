#include <iostream>
#include <string>
#include <unordered_map>
#include <bits/stdc++.h>
#include <fstream>
#include <vector>

using namespace std;



unordered_map<char, int>   to_letters(string s);
unordered_map<string, int> to_bigrams(string s);
unordered_map<string, int> to_trigrams(string s);
unordered_map<string, int> to_tetragrams(string s);
vector<string> vectorize(string s);

vector<string> vectorize(string s) {
    vector<string> a;
    string assembled = "";
    
    for(auto i: s) {
        if (i != ' ') {
            assembled += i;
        } else {
            a.push_back(assembled);
            assembled.clear();
        }
    }
    
    if (!assembled.empty()) {
        a.push_back(assembled);
        assembled.clear();
    }
    
    return a;
}

unordered_map<char, int> to_letters(string s) {
    unordered_map<char, int> letters;

    for(int i = 0; i < s.size(); ++i) {
        if (letters.find(s[i]) != letters.end()) {
            letters[s[i]] = letters[s[i]] + 1;
        } else {
            letters.insert(make_pair(s[i], 1));
        }
    }

    return letters;
}

unordered_map<string, int> to_bigrams(string s) {
    unordered_map<string, int> bigrams;

    for (int i = 0; i < s.size(); ++i) {
        string assembled = "";
        assembled += s[i];
        assembled += s[i + 1];
        
        if (bigrams.find(assembled) != bigrams.end()) {
            bigrams[assembled] = bigrams[assembled] + 1;
        } else {
            bigrams.insert(make_pair(assembled, 1));
        }
    }

    return bigrams;
}

unordered_map<string, int> to_trigrams(string s) {
    unordered_map<string, int> trigrams;

    for (int i = 0; i < s.size(); ++i) {
        string assembled = "";
        assembled += s[i];
        assembled += s[i + 1];
        assembled += s[i + 2];
        
        if (trigrams.find(assembled) != trigrams.end()) {
            trigrams[assembled] = trigrams[assembled] + 1;
        } else {
            trigrams.insert(make_pair(assembled, 1));
        }
    }

    return trigrams;
}

unordered_map<string, int> to_tetragrams(string s) {
    unordered_map<string, int> tetragrams;

    for (int i = 0; i < s.size(); ++i) {
        string assembled = "";
        assembled += s[i];
        assembled += s[i + 1];
        assembled += s[i + 2];
        assembled += s[i + 3];
        
        if (tetragrams.find(assembled) != tetragrams.end()) {
            tetragrams[assembled] = tetragrams[assembled] + 1;
        } else {
            tetragrams.insert(make_pair(assembled, 1));
        }
    }

    return tetragrams;
}