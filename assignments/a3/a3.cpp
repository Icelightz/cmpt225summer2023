// a3.cpp

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : <put your full name here!>
// St.# : <put your full SFU student number here>
// Email: <put your SFU email address here>
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

//
// Do not #include any other files!
//
#include "Announcement.h"
#include "JingleNet_announcer.h"
#include "Queue_base.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;


class Queue : public Queue_base<Announcement>
{
private:
    struct Node 
    {
        Announcement data;
        Node* next = nullptr;
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    int current_size = 0;

    //helper functions


public:
    Queue() {}     // default constructor
    ~Queue() {}    // default destructor

    // methods
    bool empty() const { return head==nullptr; }
    const Announcement &front() const { return head->data; }

    void enqueue(const Announcement &item);
    void dequeue();

    // selectors
    int size() const { return current_size; }

    // output
    friend ostream& operator<<(ostream& out, const Queue& s);

};

void Queue::enqueue(const Announcement &item) {
    Node* n = new Node{ Announcement(item) };
    if (empty()) {     //queue empty
        head = n;
        tail = n;
    }
    else {      //queue not empty
        tail->next = n;
    }
    current_size++; //size change
}

void Queue::dequeue() {
    if (!empty()) {     // queue not empty
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    else {      // queue empty
        cerr << "error: attempting to dequeue empty queue" << endl;
    }
    current_size--;     // size change
}

ostream& operator<<(ostream& out, const Queue& s) {
    Queue::Node* current = s.head;
    if (!s.empty()) {   // queue not empty
        for (int i=0; i < s.current_size; i++) {
            cout << current->data << "   ";
            current = current->next;
        }
        cout << endl;
    }
    else {      // queue empty
        cout << "{ }" << endl;
    }
    return out;
}

class JingleNet
{
private:
    

public:
    JingleNet() {}     //default constructor
    ~JingleNet() {}    //default destructor
};


int main(int argc, char const *argv[])
{
    cout << "Welcome to Assignment 3!" << endl;

    Announcement a1("yumyum", Rank::SANTA, "I love Christmas!");
    Announcement a2("user1 santa I love Christmas!");

    Queue q1;
    cout << q1 << endl;
    q1.enqueue(a1);
    cout << q1 << endl;
    q1.enqueue(a2);
    cout << q1 << endl;
    q1.dequeue();
    cout << q1 << endl;
    q1.dequeue();
    cout << q1 << endl;
    q1.dequeue();


}
