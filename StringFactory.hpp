#include <iostream>
#include "LLHW8.hpp"

using namespace std;

class StringFactory
{
    public:
        static LinkedList* stringLL(string s);
        static LinkedList* split(string s);
        static LinkedList* nodeSplit(LinkedList* s);
};