#include "LLHW8.hpp"
#include <string>
#include <iostream>

LinkedList::LinkedList()
{
    this->count = 0;
}

void LinkedList::addFront(string payload)
{
    Node* n = new Node(payload); //Node n = new Node(payload); in Java

    //if list is currently empty
    if(!this->head) //tests the pointer count of this->head (boils down to 0 if nothing points here)
                        //Java: this.head == null
    {
        this->head = n;
        this->butt = this->head;
    }
    else //list has at least 1 thing in it
    {
        this->head->setLastNode(n);
        n->setNextNode(this->head);
        this->head = n;
    }
    this->count++;
}

string LinkedList::getFront()
{
    return this->head->getPayload();
}

string LinkedList::removeFront()
{
    Node* nodeToReturn = this->head;
    this->head = this->head->getNextNode();
    this->head->setLastNode(0);
    string val = nodeToReturn->getPayload();
    delete nodeToReturn;
    this->count--;
    return val;
}

Node* LinkedList::runToEndOfList()
{
    Node* currNode = this->head;
    while(currNode->getNextNode()) //returns true when currNode has a next node
    {
        currNode = currNode->getNextNode(); // (*currNode).getNextNode()
    }
    return currNode;
}

void LinkedList::addEnd(string payload)
{
    if(!this->head)
    {
        this->addFront(payload);
    }
    else
    {
        //we have at least one thing in our list
        //traverse to end of list and connect new node

        Node* n = new Node(payload);
        Node* currNode = this->butt;
        //currNode now points to the end of our list (ie the last Node)
        n->setLastNode(currNode);
        currNode->setNextNode(n);
        this->butt = currNode;
        this->count++;

    } 
}

string LinkedList::getEnd()
{
    //currnode points to the end of the list
    return this->butt->getPayload();
}


string LinkedList::removeEnd()
{
    //we are assuming the list has at least one element in it for now
    //is this a list with a single element in it?
    if(!this->head->getNextNode())
    {
        return this->removeFront();
    }
    else
    {
        //we have at least two elements in our list
        Node* theLastGuy = this->butt;
        Node* theGuyBeforeTheLastGuy = this->head;
        while(theGuyBeforeTheLastGuy->getNextNode() != theLastGuy)
        {
            theGuyBeforeTheLastGuy = theGuyBeforeTheLastGuy->getNextNode();
        }
        //theGuyBeforeTheLastGuy now points to the Node right before theLastGuy
        theGuyBeforeTheLastGuy->setNextNode(0);
        this->butt = theGuyBeforeTheLastGuy;
        string valueToReturn = theLastGuy->getPayload();
        delete theLastGuy;
        this->count--;
        return valueToReturn;
    }
    
}

void LinkedList::display()
{
    Node* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        std::cout << currNode->getPayload() << "\n";
        currNode = currNode->getNextNode();
    }
}
void LinkedList::addAtIndex(string payload, int index)
{
    if(index == 0)
    {
        this->addFront(payload);
    }
    else if(index == this->count)
    {
        this->addEnd(payload);
    }
    else
    {
        Node* addNode = new Node(payload);
        Node* mainNode = this->head->getNextNode();
        Node* secNode = this->head;
        for(int i = 1; i<index; i++)
        {
            mainNode = mainNode->getNextNode();
            secNode = secNode->getNextNode();
        }
        addNode->setNextNode(mainNode);
        mainNode->setLastNode(addNode);
        secNode->setNextNode(addNode);
        addNode->setLastNode(secNode);
        this->count++;
    }
    
}
string LinkedList::getIndex(int index)
{
    Node* lister = this->head;
    string val;
    for(int i = 0; i < index; i++)
    {
        lister = lister->getNextNode();
    }
    val = lister->getPayload();
    return val;
}
string LinkedList::removeIndex(int index)
{
    string val;
    if(index == 0)
    {
        val = this->removeFront();
    }
    else if(index == this->count-1)
    {
        val = this->removeEnd();
    }
    else
    {
        Node* mainNode = this->head->getNextNode();
        Node* secNode = this->head;
        Node* thirNode = mainNode->getNextNode();

        for(int i = index-1; i>0; i--)
        {
            mainNode = mainNode->getNextNode();
            secNode = secNode->getNextNode();        
        }
        val = mainNode->getPayload();
        secNode->setNextNode(mainNode->getNextNode());
        mainNode->setNextNode(0);
        thirNode->setLastNode(secNode);
        this->count--;
    }
    return val;
}

void LinkedList::sortIndex()
{
    for(int i = 0; i < count; i++)
    {
        string currNode = this->getIndex(i);
        for(int a = 0; a < i; a++)
        {
            if(this->getIndex(a) > currNode)
            {
                this->removeIndex(i);
                this->addAtIndex(currNode, a);
                a = i;
            }
        }
    }
}