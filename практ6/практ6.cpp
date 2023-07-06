#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool is_palindrome(const string& word)
{
    int len = word.length();
    for (int i = 0; i < len / 2; ++i) {
        if (tolower(word[i]) != tolower(word[len - i - 1])) {
            return false;
        }
    }
    return true;
}

int main()
{
    ifstream input("input.txt");
    if (!input.is_open()) {
        cerr << "Failed to open input file\n";
        return 1;
    }

    ofstream output("output.txt");
    if (!output.is_open()) {
        cerr << "Failed to open output file\n";
        return 1;
    }
 
    string line;
    string word;
    while (getline(input, line)) {
        int start = -1;
        int end = -1;
        for (int i = 0; i < line.length(); i++) {
            if (isalpha(line[i])) {
                if (start == -1) {
                    start = i;
                }
                end = i;
            }
            else {
                if (start != -1) {
                    word = line.substr(start, end - start + 1);
                    if (is_palindrome(word)) {
                        output << word << '\n';
                    }
                }
                start = -1;
                end = -1;
            }
        }
        if (start != -1) {
            word = line.substr(start, end - start + 1);
            if (is_palindrome(word)) {
                output << word << '\n';
            }
        }
    }

    input.close();
    output.close();

    return 0;
}