#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
#include <iostream>
using namespace std;

// Complexity: theta(1)
SortedMap::SortedMap(Relation r) {
	//TODO - Implementation
    this->rel = r;
    this->head = NULL;
    this->tail = NULL;
}

// Best case: theta(1) - insert after tail / before head / update tail / update head value
// Average case: theta(n)
// Worst case: theta(n)
// Complexity: O(n)
TValue SortedMap::add(TKey k, TValue v) {
    //TODO - Implementation
    DLLNode *newNode;
    newNode = new DLLNode;
    newNode->info = std::pair<TKey, TValue>(k, v);
    // if the linked list is empty -> change head, tail
    if (this->head == NULL) {
        newNode->prev = NULL;
        newNode->next = NULL;
        this->head = newNode;
        this->tail = newNode;
    }
    else if (this->rel(this->tail->info.first,k))
    {
        // tail contains the given key -> update value
        if (this->tail->info.first == k)
        {
            TValue copy = this->tail->info.second;
            tail->info.second = v;

            // we don't need the new Node
            newNode->next = NULL;
            newNode->prev = NULL;
            delete newNode;

            return copy;
        }
        // insert node after tail -> new tail
        else {
            newNode->next = NULL;
            newNode->prev = this->tail;
            this->tail->next = newNode;
            this->tail = newNode;
        }
    }
    else {
        // find correct posititon
        DLLNode *current;
        current = this->head;
        while (current != NULL && !this->rel(k, current->info.first)) {
            current = current->next;
        }
        if (current != NULL) {
            // check if the key is already present -> update value
            if (current->info.first == k) {
                TValue copy = current->info.second;
                current->info.second = v;
                // we don't need the new Node
                newNode->next = NULL;
                newNode->prev = NULL;
                delete newNode;
                return copy;
            }
            // node before head -> new head
            else if (current == this->head) {
                newNode->next = this->head;
                newNode->prev = NULL;
                this->head->prev = newNode;
                this->head = newNode;
            }
            // insert node before current
            else
            {
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;
            }
        }
    }
    return NULL_TVALUE;
}

// Best Case: theta(1)  - head / tail has key k
// Average Case: theta(n)
// Worst Case: theta(n)
// Complexity: O(n)
TValue SortedMap::search(TKey k) const {
	//TODO - Implementation
    if (!SortedMap::isEmpty())
    {
        // check if tail has key k
        if (this->tail->info.first == k)
        {
            return this->tail->info.second;
        }
        else {
            DLLNode *current;
            current = this->head;
            while (current != NULL && !this->rel(k, current->info.first)) {
                current = current->next;
            }

            if (current != NULL) {
                // if key found, return value
                if (current->info.first == k) {
                    return current->info.second;
                }
            }
        }
    }
    return NULL_TVALUE;
}

// Best Case: theta(1) - first/last element will be removed
// Worst Case: theta(n) - the one before the last
// Average Case: theta(n)
// Complexity: O(n)
TValue SortedMap::remove(TKey k) {
	//TODO - Implementation
    if (!SortedMap::isEmpty()) {
        DLLNode *deletedNode;
        // check if the first element will be deleted
        if (this->head->info.first == k) {
            TValue copy = this->head->info.second;
            // check if contains only one element
            if (this->head == this->tail) {
                delete this->head;
                this->head = NULL;
                this->tail = NULL;
            } else {
                deletedNode = this->head;
                this->head = deletedNode->next;
                deletedNode->next = NULL;
                this->head->prev = NULL;
                delete deletedNode;
            }
            return copy;
        }

        // check if the last node will be deleted
        if (this->tail->info.first == k) {
            TValue copy = this->tail->info.second;
            deletedNode = this->tail;
            this->tail = deletedNode->prev;
            deletedNode->prev = NULL;
            this->tail->next = NULL;
            delete deletedNode;
            return copy;
        }

        // find node and then delete
        deletedNode = this->head;
        while (deletedNode != NULL && !rel(k, deletedNode->info.first)) {
            deletedNode = deletedNode->next;
        }
        if (deletedNode != NULL && deletedNode->info.first == k) {
            TValue copy = deletedNode->info.second;
            deletedNode->prev = deletedNode->next;
            deletedNode->next->prev = deletedNode->prev;
            deletedNode->next = NULL;
            deletedNode->prev = NULL;
            delete deletedNode;
            return copy;
        }
    }
    return NULL_TVALUE;
}

// Complexity: theta(n)
int SortedMap::size() const {
	//TODO - Implementation
    int count=0;
    DLLNode *current;
    current = this->head;
    while (current!= NULL)
    {
        current = current->next;
        count++;
    }
    return count;
}

// Complexity: theta(1)
bool SortedMap::isEmpty() const {
	//TODO - Implementation
    return this->head == NULL;
}

SMIterator SortedMap::iterator() const {
	return SMIterator(*this);
}

// Complexity: theta(n)
SortedMap::~SortedMap() {
	//TODO - Implementation
    while (!SortedMap::isEmpty())
        SortedMap::remove(this->head->info.first);
}


