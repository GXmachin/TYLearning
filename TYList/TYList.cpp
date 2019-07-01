#include "TYList.h"
#include <iostream>
#include <cstring>

using namespace std;

TYList::TYList()
{
    //default constructor
}

void TYList::construct_members(const char* str) //O(N)
{
    int str_size=strlen(str); //Get the length of characters

    if(str_size>0)
    {
        head = new Node; //We initialize the head
        head->value=str[0];
    }

    Node* cur_node=head; //Set current node to head 1->2->3

    for(int char_idx=1; char_idx<str_size;char_idx++)
    {
        cur_node->next= new Node; //create a new node.
        cur_node=cur_node->next;
        cur_node->value=str[char_idx]; // We set the value
        cur_node->next=NULL; //Set next to null
    }
}

TYList::TYList(const string& val)
{
    const char* str = val.c_str();
    construct_members(str);
}


TYList::TYList(char* str)
{
    construct_members(str);
}


void TYList::print()//O(N)
{
   //First thing to print is head
    Node* curr_node = head;

    while (curr_node != NULL)
    {
        cout << curr_node->value;
        curr_node = curr_node->next;
    }
    cout << endl;

}

TYList::~TYList()
{
    //int* is also a variable type (an integer pointer type)
    //char* a character pointer variable type
    //float* is a float pointer variable type

    Node* temp = head;
    while(temp)
    {
        Node* curr_node = temp->next;
        cout << "deleting..." << temp->value << endl;
        delete temp; //frees a previusly allocated memory in line 46
        temp = curr_node;
    }
}


//TYList.cpp
void TYList::push_front(char val)//O(1) -> constant time
{
    //push front
    Node* new_node = new Node; //create new node for new char
    new_node-> next = head; // let that node point to the old head
    new_node->value = val; // let that node have the new val
    head = new_node; //new node becomes the new head
}
//End TYList.cpp

void TYList::push_back(char val) //O(N)
{
    if(!head)
    {
        head = new Node;
        head->value = val;
        return;
    }
    Node* temp = head;

    while(temp->next)
    {
        temp = temp->next;
    }

    Node* tail = new Node;
    tail->next = NULL;
    tail->value = val;
    temp->next = tail;
}

void TYList::pop_front() // O(1) what is the run time?
{
    if(!head)
    {
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;

}

void TYList::pop_back() //O(N)
{
    if(!head)
    {
        return;
    }
    Node* temp = head;
    Node* curr_node = head;

    while(temp->next)
    {
        curr_node = temp;
        temp = temp->next;
    }
    curr_node->next = NULL;
    delete temp;

}
