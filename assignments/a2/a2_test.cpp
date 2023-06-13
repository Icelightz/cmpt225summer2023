// a2_test.cpp

#include "Stringlist.h"
#include <cassert>

using namespace std;

int main() {
    cout << " ... put your tests here ...\n";

    Stringlist lst;
    lst.insert_back("hello");
    lst.insert_back("nice");
    cout << lst << endl;

    lst.undo();
    cout << lst << endl;

    lst.remove_all();
    cout << lst << endl;
    
    lst.undo();
    cout << lst << endl;

    cout << lst << endl;

    //assert();
}
