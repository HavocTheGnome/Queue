
#include <iostream>
#include <string>

using namespace std;

class Node 
{
private:
    string payload;
    Node* nextNode; //Node nextNode - java treats this as a Node* automatically
    Node* lastNode;
public:
    Node(string payload);
    string getPayload();
    Node* getNextNode();
    Node* getLastNode();
    void setNextNode(Node* n);
    void setLastNode(Node* n);
    
};
