#include <iostream>
#include "StringFactory.hpp"

int main()
{
    string s = "123+42-8*2+3+3";
    LinkedList* intputQ = StringFactory::split(s);
    for(int i = 0; i < 11; i++)
    {
        string input = intputQ->getIndex(i);
        cout << input << "\n";
    }
}