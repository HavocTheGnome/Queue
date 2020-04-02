#include "Node.hpp"
#include <string>

using namespace std;

Node::Node(string payload)
{
    //this is a Node*
    //(*this).payload
    //(*0x123abc).payload
    //this->payload
    this->payload = payload;
}

string Node::getPayload()
{
    return this->payload;
}

Node* Node::getNextNode()
{
    return this->nextNode;
}

Node* Node::getLastNode()
{
    return this->lastNode;
}
void Node::setNextNode(Node* n)
{
    this->nextNode = n;
}

void Node::setLastNode(Node* n)
{
    this->lastNode = n;
}