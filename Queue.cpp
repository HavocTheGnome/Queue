#include "Queue.hpp"
#include <iostream>
#include <string>
using namespace std;
Queue::Queue()
{
    this->top = 0;
    this->counter = 0;
}
void Queue::push(string payload)
{
    Node* n = new Node(payload);
    if(this->top)
    {
        n->setNextNode(this->top);
        this->top = n;
    }
    else
    {
        this->top = n;
    }
    this->counter++;
}
string Queue::peek()
{
    if(this->top)
    {
        return this->top->getPayload();
    }
    else
    {
        return 0;
    }
}
void Queue::display()
{
    if(this->top)
    {
        Node* currNode = this->top;
        while(currNode)
        {
            std::cout << currNode->getPayload() << "\n";
            currNode = currNode->getNextNode();
        }
    }
    else
    {
        std::cout<< "Empty Stack" << "\n";
    }
    
}