#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

// Complexity: theta(1)
SMIterator::SMIterator(const SortedMap& m) : map(m){
	//TODO - Implementation
    this->currentElement = this->map.head;
}

// Complexity: theta(1)
void SMIterator::first(){
	//TODO - Implementation
    this->currentElement = this->map.head;
}

// Complexity: theta(1)
void SMIterator::next(){
	//TODO - Implementation
    if (SMIterator::valid())
    {
        this->currentElement = this->currentElement->next;
    }
    else
    {
        exception E;
        throw E;
    }
}

// Complexity: theta(1)
bool SMIterator::valid() const{
	//TODO - Implementation
    return this->currentElement!=NULL;
}

// Complexity: theta(1)
TElem SMIterator::getCurrent() const{
	//TODO - Implementation
    if (SMIterator::valid())
    {
        return this->currentElement->info;
    }
    else
    {
        exception E;
        throw E;
    }
}


