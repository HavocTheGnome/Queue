#include "Node.hpp"
#include <iostream>
using namespace std;

class Queue 
{
private:
    int counter;
    Node* top;
    
public:
    Queue();
    void push(string payload);
    string pop();
    string peek();
    void display();
};
