#include <iostream>
#include "StringFactory.hpp"
int main()
{
    string never = "123*12/12+100-100";
    LinkedList* inter = StringFactory::split(never);
    int count = inter->getcount();
    
    LinkedList* intput = StringFactory::stringLL(never);
    count = intput->getcount();
    LinkedList* intputQ = StringFactory::nodeSplit(intput);
    count = intputQ->getcount();
    for(int i = 0; i < count; i++)
    {
        cout << intputQ->removeFront() << "\n";
    }
    return 0;
    
}