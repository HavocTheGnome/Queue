#include "StringFactory.hpp"
using namespace std;
LinkedList* StringFactory::split(string s)
{
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
        cout << "we're here" << "\n";
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
    for(int i = 0; i < count; i++)
    {
        string hello = list->getIndex(i);
        cout << hello << "\n";
    }
    return list;
}