#include <iostream>
using namespace std;

string word(const string& s, int n) {   // gets the n_th word in non-empty string
    // idea: use start and index of " " immediately after start to find words
    // use substr(start, end) to retreive a word
    //assumes legal input

    int start = 0;  //index of start of word
    int end = s.find(" ");    //end is a cursor that keeps index of spaces
    string word = s.substr(0,end);  //first word
    int count = 1;  //counts how many words have been found
    if (n == 1) {   //1 word
        return word;
    }
    while(count<n) {   // > 1 word
        start = end;
        end=s.find(" ",end+1);    // gets index of next space
        count++;
    }
    word = s.substr(start+1,end-start-1);
    string result = word;
    return result;
}


int main() {
    string s1 = "hello my name is zoe!";
    string w1 = word(s1,3);
    cout << w1 << "T" << endl;

    int x = 1;
    int y = x;
    x++;
    cout << y << endl;
    return EXIT_SUCCESS;
}