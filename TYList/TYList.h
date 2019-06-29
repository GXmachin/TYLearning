#ifndef TYLIST_H_INCLUDED
#define TYLIST_H_INCLUDED
#include <iostream>

using namespace std;

struct Node
{
    char value;
    Node* next;
};

class TYList
{
    private:
        Node* head;
    public:
        TYList();
        TYList(const string& val);
        TYList(char* val);
        TYList(TYList& val);
        ~TYList();
      /* Mutators */
        void push_front(char val); //add val at the front of the list e.g "ty" -> "aty" if val is 'a'
        void push_back(char val); //add val at the back of the list e.g "ty" -> "tya" if val is 'a'
        void pop_front(); //Remove the character at the front of the list e.g "aty" -> "ty"
        void pop_back(); //Remove the last character from the list e.g "aty" -> "at"
        void insert_at_pos(int i, char val); //insert val at position i of the list
        int size();
        int find(char value) const;
        void print();
        void construct_members(const char* val);
        /* Operator overloaders */
        TYList operator+(const TYList& str); //concatenate two lists
};


#endif // TYLIST_H_INCLUDED
