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

// gets the nth word in a string eg. In "hi santa", 1st word is "hi".
// read-only
string get_word(const string& s, int n) 
{
    // the nth word has n-1 spaces before it
    // countinue searching until n-1 spaces are found
    // assumes strings are in format found in jinglenet input arguments

    int index = s.find(" ");    // index of space

    // case1: get 1st word
    if (n==1)
    {
        return s.substr(0, index);
    }

    //case2: get more than 1 word

    int count = 1;  //counts number of spaces traversed

    // look for next space until n-1 spaces have been found
    while(count < n-1) {
        index = s.find(" ", index+1);
        
        count++;
    }
    // the index of space before the nth word found, now return the word
    return s.substr(index+1, s.find(" ", index+1) - index - 1);
}

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
    Queue snowman;     // = 1
    Queue elf1;
    Queue elf2;
    Queue reindeer;
    Queue santa;       // = 5

    // helps loop through queues
    Queue* list[5] = { &snowman, &elf1, &elf2, &reindeer, &santa };


    // helper functions

    //destroy objects that uses heap memory
    void clear() 
    {
        for (int i = 0; i < 5; i++)
        {
            list[i]->~Queue();
        }
    }

    // remove user from queue
    void remove_user(string const & user, Queue& q)
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            if ( q.front().get_sender_name() != user )
            {   // announcement not from user, put it back in queue
                q.enqueue(q.front());
            }   // otherwise no need to put it back
            q.dequeue();
        }
    }
    
    // return an announcement with increased rank
    Announcement rank_up(Announcement const & a)
    {
        return Announcement(a.get_sender_name(), static_cast<Rank>((int)a.get_rank()+1), a.get_text());
    }
    
    // returns queue of all announcements of a user from a input queue
    Queue collect_announcements(string const & user, Queue & q)
    {
        Queue accumulator;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            if (q.front().get_sender_name() == user)
            {
                accumulator.enqueue(q.front());
            }
            else
            {
                q.enqueue(q.front());
            }
            q.dequeue();
        }
        return accumulator;
    }
    
    

public:
    JingleNet() {}      // default constructor
    ~JingleNet() { clear(); }    // destructor

    // selects method to call based on text commands from input file
    void input(const string& s);


    // methods

    // All jinglenet commands will directly get argument list in string format from input and avoid
    // conversion to their proper format. This is for efficiency.
    void send(const string& s);
    void announce(const string& s);
    void promote_announcements(const string& s);
    void remove_all(const string& s);


    // output
    friend ostream& operator<<(ostream& out, const JingleNet& s);

};

void JingleNet::input(const string& s)
{
    string m = s.substr(0,s.find(" ")); //get method that we need to call
    string arg = s.substr(s.find(" ")+1, s.size()-1); //get argument list of method

    if (m=="SEND") 
    {
        send(arg);
    }
    else if (m=="ANNOUNCE")
    {
        announce(arg);
    }
    else if (m=="PROMOTE_ANNOUNCEMENTS")
    {
        promote_announcements(arg);
    }
    else if (m=="REMOVE_ALL")
    {
        remove_all(arg);
    }
}

void JingleNet::send(const string& s)
{
    Announcement a(s);  // create announcement a
    Rank r = a.get_rank();  // get rank r of a
    list[(int)r-1]->enqueue(a); // add a to a matching with matching rank
}

void JingleNet::announce(const string& s)
{   // s is number of announcements to announce
    int n = stoi(s);    //max number of announcements to make
    int count = 0;  //count number of announcements made so far
    for (int i = 4; i >= 0; i--)
    {
        Queue& a = *list[i];

        //announce items in a queue until it is empty or enough announcements have been made
        while(!list[i]->empty() && count<n)
        {
            jnet.announce(a.front());
            a.dequeue();
            count++;
        }
        if (count>=n)   //stop announcing once n announcements are made
        {
            break;
        }
        // the queue is empty, move to queue of next rank
    }
}

void JingleNet::promote_announcements(const string& s)
{
    for(int i = 3; i >= 0; i--)
    {
        Queue a(collect_announcements(s,*list[i]));
        while(!a.empty())
        {
            list[i+1]->enqueue(rank_up(a.front()));
            a.dequeue();
        }
    }
}

void JingleNet::remove_all(const string& s)
{
    for (int i = 0; i < 5; i++)
    {
        remove_user(s,*list[i]);
    }
}

ostream& operator<<(ostream& out, const JingleNet& s)
{
    cout << "JingleNet -------------" << endl << endl;
    for (int i = 4; i >= 0; i--)
    {
        cout << *s.list[i] << endl;
    }
    return out;
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1; 
    }
    
    cout << "Welcome to Assignment 3!" << endl;

    JingleNet net;

    string file_name = argv[1];
    ifstream infile(file_name);

    if(!infile)  // file does not exist error
    {
        cout << endl << "----- Input file is not accessible -----" << endl << endl;
    }

    string line;    // store lines read from input file

    // read file to jingle net line by line
    while (getline(infile, line))
    {
        net.input(line);
    }
    
    
    /*  tests ------------------------------
    JingleNet net;
    Announcement a1("yumyum", Rank::SANTA, "I love Christmas!");
    Announcement a2("user1 santa I love Christmas!");
    Announcement a3("yumyum", Rank::SANTA, "HellO!");

    Queue q1;
    cout << q1 << endl;
    q1.enqueue(a1);
    q1.enqueue(a2);
    q1.enqueue(a3);
    q1.enqueue(a3);
    q1.enqueue(a1);
    q1.enqueue(a2);
    cout << q1 << endl;

    net.remove_user("yumyum", q1);
    cout << q1 << endl;
*/



    

    return EXIT_SUCCESS;
}
