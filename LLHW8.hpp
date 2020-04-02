#ifndef LinkedList_hpp
#define LinkedList_hpp
#include "Node.hpp"
#include <iostream>

class LinkedList 
{
private:
    Node* head;
    Node* butt;
    int count;
    Node* runToEndOfList();
    
public:
    LinkedList();
    void addFront(string payload);
    string getFront();
    string removeFront();
    //hw 3 methods below
    void addEnd(string payload);
    string getEnd();
    string removeEnd();
    void display();
    void addAtIndex(string payload, int index);
    string getIndex(int index);
    string removeIndex(int index);
    void sortIndex();
};
#endif /* LLHW8_hpp */