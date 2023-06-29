// a3.cpp

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : Hugo Zhou
// St.# : 301546101
// Email: hhz1@sfu.ca
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

    // internal data
    struct Node 
    {
        Announcement data;
        Node* next = nullptr;
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    int current_size = 0;

    //helper functions
    void clear() 
    {
        while(!empty()) {
            dequeue();
        }
    }

public:

    Queue() {}     // default constructor

    ~Queue() { clear(); }    //  destructor



    // selectors    -------------------

    bool empty() const { return head==nullptr; }
    
    int size() const { return current_size; }

    const Announcement &front() const;



    // mutators    -------------------
 
    // empty: head, tail, size
    // !empty: tail, size, connect (means link item)
    void enqueue(const Announcement &item);

    // empty: throws exception
    // !empty:  size, head, tail
    void dequeue();



    // output    -------------------

    // empty: print "{ }"
    // !empty: print all items
    friend ostream& operator<<(ostream& out, const Queue& s);

};

const Announcement &Queue::front() const 
{
    if (empty())
    {
        throw runtime_error("front: queue is empty");
    }
    else
    {
        return head->data;
    }
}

void Queue::enqueue(const Announcement &item) 
{
    Node* n = new Node{ Announcement(item) };
    if (empty()) 
    {     //queue empty
        head = n;
        tail = n;
    }
    else 
    {      //queue not empty
        tail->next = n;
        tail=n;
    }
    current_size++; //size change
}

void Queue::dequeue() 
{
    if (empty())
    {      // queue empty
        throw runtime_error("dequeue: queue is empty");
    }
    else 
    {     // queue not empty
        if (current_size==1) 
        {   // 1 item left
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else 
        {   // more than 1 item left
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }

        current_size--;     // change size
    }
}

ostream& operator<<(ostream& out, const Queue& s)
{
    Queue::Node* current = s.head;
    if (!s.empty()) {   // queue not empty
        for (int i=0; i < s.current_size; i++) 
        {
            cout << current->data << "   ";
            current = current->next;
        }
        cout << endl;
    }
    else 
    {      // queue empty
        cout << "{ }" << endl;
    }
    return out;
}


class JingleNet
{
private:
    Queue snowman; // lowest rank
    Queue elf1;
    Queue elf2;
    Queue reindeer;
    Queue santa;       // highest rank
    Queue* list[5] = { &snowman, &elf1, &elf2, &reindeer, &santa };

    

public:
    JingleNet() {}     //default constructor
    ~JingleNet() {}    //default destructor
};


int main(int argc, char const *argv[])
{
    if (argc==1) {

    }
    if (argv[0]==nullptr) {

    }
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

    cout << "front is: " << q1.front() << endl;

    JingleNet j1;

    //Queue& test1 = *j1.list[int(Rank::SNOWMAN)-1];
    //j1.snowman.enqueue(a1);
    //cout << test1 << endl;

    return EXIT_SUCCESS;
}
