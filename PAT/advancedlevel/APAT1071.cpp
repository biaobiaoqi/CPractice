#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
bool isAlpha(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main() {
    string str;
    getline(cin, str);
    map<string, int> words;
    
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    
    int s, e, i = 0;
    int max = 0;
    string max_str;
    while ( i < str.length()) {
        while (!isAlpha(str[i]) && i < str.length())
            ++ i;
        if (i == str.length())
            break;
        s = i;
        
        while (isAlpha(str[i]) && i < str.length())
            ++ i;
        e = i;
        
        string word = str.substr(s, e - s);
        if (words.count(word) == 0)
            words[word] = 1;
        else
            words[word] ++;

        if (words[word] > max) {
            max = words[word];
            max_str = word;
        }else if (words[word] == max && word < max_str) {
            max_str = word;
        }
    }
    
    cout << max_str << " " << max << endl;
}
