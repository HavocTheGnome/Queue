#include "StringFactory.hpp"
using namespace std;

LinkedList* StringFactory::stringLL(string s)
{
    LinkedList* list = new LinkedList();
    string tracker;
    int strSize = s.size();
    int count = 0;
    for(int i = 0; i < strSize; i++)
    {
        string modifiers = "+-/*";
        char plus = modifiers[0];
        char minus = modifiers[1];
        char div = modifiers[2];
        char mult = modifiers[3];
        char hi = s[i];
        if(hi == plus or hi == minus or hi == div or hi == mult)
        {
            list->addFront(tracker);
            tracker = "";
            tracker = tracker + hi;
            list->addFront(tracker);
            tracker = "";
            count = count + 1;
            count = count + 1;
        }
        else if(i == s.size()-1)
        {
            tracker = tracker + hi;
            list->addFront(tracker);
            count = count + 1;
        }
        else
        {
            tracker = tracker + hi;
        }
    }
    return list;
}
LinkedList* StringFactory::split(string s)
{
    LinkedList* finalList = new LinkedList();
    LinkedList* list = new LinkedList();
    LinkedList* modList = new LinkedList();
    string tracker;
    int strSize = s.size();
    int count = 0;
    int modCount = 0;
    for(int i = 0; i < strSize; i++)
    {
        string modifiers = "+-/*";
        char plus = modifiers[0];
        char minus = modifiers[1];
        char div = modifiers[2];
        char mult = modifiers[3];
        char hi = s[i];
        if(hi == plus or hi == minus or hi == div or hi == mult)
        {
            list->addFront(tracker);
            tracker = "";
            if(hi == plus or hi == minus)
            {
                tracker = tracker + hi;
                modList->addFront(tracker);
                tracker = "";
                modCount = modCount + 1;
            }
            else
            {
                tracker = tracker + hi;
                list->addFront(tracker);
                tracker = "";
                count = count + 1;
            }
            count = count + 1;
        }
        else if(i == s.size()-1)
        {
            tracker = tracker + hi;
            list->addFront(tracker);
            count = count + 1;
        }
        else
        {
            tracker = tracker + hi;
        }
    }
    for(int i = 0; i < modCount; i++)
    {
        tracker = modList->getIndex(i);
        list->addFront(tracker);
        count = count+1;
    }
    return list;
}

LinkedList* StringFactory::nodeSplit(LinkedList* s)
{
    LinkedList* currNode = s;
    LinkedList* finalList = new LinkedList();
    LinkedList* list = new LinkedList();
    LinkedList* modList = new LinkedList();
    int count = s->getcount();
    int modlength = 0;
    int length = 0;
    for(int i = 0; i < count; i++)
    {
        string currValue = currNode->getIndex(i);
        if(currValue == "+" or currValue == "-" or currValue == "*" or currValue == "/")
        {
            if(currValue == "+" or currValue == "-")
            {
                modList->addFront(currValue);
                modlength++;
            }
            else
            {
                finalList->addFront(currValue);
                length++;
            }
        }
        else
        {
            finalList->addFront(currValue);
            length++;
        }
    }
    for(int i = modlength-1; 0 <= i; i--)
    {
        string hello = modList->getIndex(i);
        list->addFront(hello);
    }
    for(int i = length-1; 0 <= i; i--)
    {
        string hello = finalList->getIndex(i);
        list->addFront(hello);
    }
    return list;
}
