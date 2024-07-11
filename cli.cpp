#include <iostream>
#include <string>
#include <unordered_map>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream corpus("/home/ibrab00/Prog/Textualyzer/output.txt");

    string input;

    
    while(input != "quit") {
        cout << "$ ";
        getline(cin, input);
        cin.ignore();
        if (input != "quit") {
            cout << "To be developed... " << '\n';
        } 
    }

}