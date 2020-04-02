#include <iostream>
#include <string>
#include "Node.hpp"

using namespace std;
class Stack
{
    private:
        Node* bot;
        int counter;
        Node* top;
    public:
        Stack();
        void push(string payload);
        void pushB(string payload);
        string pop();
        string popB();
        string peek();
        void display();
};