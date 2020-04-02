#include <iostream>
#include <string>
#include "Stack.hpp"

using namespace std;

Stack::Stack()
{
    this->top = 0;
    this->counter = 0;
    this->bot = 0;
}
void Stack::pushB(string payload)
{
    Node* n = new Node(payload);
    if(this->bot)
    {
        n->setNextNode(this->bot);
        this->bot = n;
    }
    else
    {
        this->top = n;
        this->bot = n;
    }
    this->counter++;
}
string Stack::popB()
{
    if(counter == 1)
    {
        string valueToReturn = this->bot->getPayload();
        this->bot = 0;
        this->top = 0;
        this->counter--;
        return valueToReturn; 
    }
    else if(counter > 0)
    {
        string valueToReturn = this->bot->getPayload();
        bot = bot->getNextNode();
        cout << bot->getPayload() << "\n";
        this->counter--;
        return valueToReturn;; 
    }
    else
    {
        return 0;
    }
}
void Stack::push(string payload)
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
        this->bot = n;
    }
    this->counter++;
    
}
string Stack::pop()
{
    if(counter == 1)
    {
        string valueToReturn = this->top->getPayload();
        this->top = 0;
        this->counter--;
        return valueToReturn; 
    }
    else if(counter > 0)
    {
        string valueToReturn = this->top->getPayload();
        Node* temp = this->top;
        top = top->getNextNode();
        temp->setNextNode(0);
        delete temp;
        this->counter--;
        return valueToReturn; 
    }
    else
    {
        return 0;
    }
        
}

void Stack::display()
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
        std::cout << "Empty Stack" << "\n";
    }
}