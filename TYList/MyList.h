#ifndef MYLIST_H_INCLUDED
#define MYLIST_H_INCLUDED
#include <iostream>

using namespace std;



class MyList
{
private:
    Node* head;

public:
    MyList();
    MyList(const char* val);
    MyList(const std::string& val);
    //A deep copy means you are copying all the values pointed to by nodes and creating new node objects from them
    MyList(const MyList& val); //do a deep copy of the strings in val
    ~MyList();
    void construct_members(const char* val);

  /* Mutators */
  void push_front(char val); //add val at the front of the list e.g "ty" -> "aty" if val is 'a'
  void push_back(char val); //add val at the back of the list e.g "ty" -> "tya" if val is 'a'
  void pop_front(); //Remove the character at the front of the list e.g "aty" -> "ty"
  void pop_back(); //Remove the last character from the list e.g "aty" -> "at"
  void insert_at_pos(int i, char val); //insert val at position i of the list
  void reverse();
  void swap(int i, int j);


  /* Accessors */
  int size()const;
  int find(char value)const;
  void print()const;
  int find(MyList& query_str)const;


  /* Operator overloaders */
  MyList operator+(const MyList& str); //concatenate two lists
  MyList& operator=(const MyList& list2);
  char& operator[](const int i);
  const char& operator[](const int i) const;
  void assert_out_of_bounds(const int index) const;


  /* Newly Assigned functions */
  void merge_list(MyList A, MyList B);
  bool is_palindrome()const;
  bool remove_char(char c);
  char front()const;

};


#endif // MyLIST_H_INCLUDED

