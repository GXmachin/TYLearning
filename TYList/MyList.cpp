#include "MyList.h"
#include <iostream>
#include <cstring>

class Node
{
    friend class MyList;
    private:
        char value;
        Node* next;
};

void MyList::construct_members(const char* str) //O(N)
{
    int str_size=strlen(str);
    if(str_size>0)
    {
        head = new Node;
        head->value=str[0];
        head->next = NULL;
    }

    Node* cur_node=head;

    for(int char_idx=1; char_idx<str_size;char_idx++)
    {
        cur_node->next= new Node; //create a new node.
        cur_node=cur_node->next;
        cur_node->value=str[char_idx];
        cur_node->next=NULL;
    }
}

MyList::MyList():head(NULL){}

MyList::MyList(const char* str):head(NULL)
{
  construct_members(str);
}

MyList::MyList(const std::string& val):head(NULL)
{
    const char* str = val.c_str();
    construct_members(str);
}

void MyList::print()const
{

    Node* curr_node = head;

    while (curr_node != NULL)
    {
        cout << curr_node->value;
        curr_node = curr_node->next;
    }

    cout << endl;

}

MyList::~MyList()
{


    Node* temp = head;
    while(temp)
    {
        Node* curr_node = temp->next;
        delete temp;
        temp = curr_node;
    }
}


void MyList::push_front(char val)
{

    if (!head)
    {
        head = new Node;
        head->value = val;
        head->next = NULL;
        return;
    }
    Node* new_node = new Node;
    new_node-> next = head;
    new_node->value = val;
    head = new_node;
}


void MyList::push_back(char val)
{
    if(!head)
    {
        head = new Node;
        head->value = val;
        head->next = NULL;
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

void MyList::pop_front()
{
    if(!head)
    {
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;

}

void MyList::pop_back()
{
    if(!head)
    {
        return;
    }
    Node* temp = head;
    Node* curr_node = head;
    if (head->next == NULL)
    {
        temp = head;
        head = NULL;
        delete temp;
    }
    else
    {
        while(temp->next)
        {
            curr_node = temp;
            temp = temp->next;
        }
        curr_node->next = NULL;
        delete temp;
    }


}
int MyList::size()const
{
    if(!head) return 0;

    int count=0;
    Node* temp = head;

    while(temp)
    {
        temp = temp->next;
        count++;
    }

    return count;
}

MyList::MyList(const MyList& val):head(NULL)
{
  *this = val;
}

MyList& MyList::operator=(const MyList& list2)
{
    Node* temp = list2.head;

    while(temp)
    {
        push_back(temp->value);
        temp = temp->next;
    }
    return *this;
}

MyList MyList::operator+(const MyList& str)
{

    MyList new_list = *this;
    Node* temp = str.head;
    while(temp)
    {
        new_list.push_back(temp->value);
        temp = temp->next;
    }
    return new_list;
}

void MyList::merge_list(MyList A, MyList B)
{
    *this = A + B;
}

char& MyList::operator[](const int i)
{
    assert_out_of_bounds(i);
    Node* temp = head;
    int index = i;
    while(index)
    {
        temp = temp->next;
        index--;
    }
    return temp->value;
}

void MyList::insert_at_pos(int i, char val)
{

  assert_out_of_bounds(i);
  Node* temp = head;
  Node* prev_node = head;

  for(int indx=0; indx<i; indx++)
  {
    prev_node = temp;
    temp = temp->next;
  }

  Node* new_node = new Node;
  prev_node->next = new_node;
  new_node->value = val;
  new_node->next = temp;
}

int MyList::find(char value)const
{
    int count =0;
    Node* temp = head;
    while(temp->value != value)
    {
        count++;
        if(!temp->next && temp->value!= value)
        {
            count = -1;
            break;
        }
        temp = temp->next;
    }
    return count;
}


void MyList::assert_out_of_bounds(const int index)const
{
    if(index > size() || index < 0)
    {
        std::cout << "index " << index << " is out of bounds" << std::endl;
        std::cerr << "index " << index << " is out of bounds" << std::endl;
        std::terminate();
    }
}

const char& MyList::operator[](const int i) const
{
    assert_out_of_bounds(i);
    Node* temp = head;
    int index = i;
    while(index)
    {
        temp = temp->next;
        index--;
    }
    return temp->value;
}

char MyList::front()const
{
    return head->value;
}

bool MyList::remove_char(char c)
{
    int item = find(c);
    if (item == -1){return false;}
    Node* temp = head;
    Node* prev = head;
    while(item)
    {
        prev = temp;
        temp= temp->next;
        item--;
    }
    prev->next = temp->next;
    delete temp;
    return true;
}

void MyList::swap(int i, int j)
{
    assert_out_of_bounds(i);
    assert_out_of_bounds(j);

    char temp = (*this)[i];
    (*this)[i] = (*this)[j];
    (*this)[j] = temp;

}

void MyList::reverse()
{
    if(!head){return;}

    Node* curr_node = head;
    Node* prev_node = NULL;
    Node* next_node = NULL;

    while(curr_node)
    {

        next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;

    }
    head = prev_node;
}

bool MyList::is_palindrome()const
{
    MyList reversed_list = *this;
    reversed_list.reverse();
    Node* reversed = reversed_list.head;
    Node* non_reversed = (*this).head;

    while(reversed)
    {
        if(reversed->value != non_reversed->value){return false;}
        reversed = reversed->next;
        non_reversed = non_reversed->next;
    }
    return true;
}

int MyList::find(MyList& query_str)const
{
    if(!head || !query_str.head){return -1;}
    int pos = 0;
    int str_counter = 0;
    Node* temp = head;
    Node* node1  = head;
    Node* query_node  = query_str.head;
    int size_ = query_str.size();
    while(node1->next)
    {
        while(query_node && temp)
        {
            std::cout << query_node->value << " : " << temp->value << std::endl;
            if(query_node->value == temp->value){str_counter++;}
            else{str_counter=0;}
            if(!(query_node->next) && str_counter==size_){return pos;}
            temp = temp->next;
            query_node = query_node->next;
        }
        query_node = query_str.head;
        temp = node1->next;
        node1 = node1->next;
        pos++;
    }
    return -1;
}

