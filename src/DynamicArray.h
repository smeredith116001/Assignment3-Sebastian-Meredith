//
//  DynamicArray.h
//
//  This file defines a Dynamic Array class.
//  You SHOULD modify this file.
//
//  Copyright 2019 David Kopec
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.


//Editing by Sebastian Meredith
#ifndef dynamicarray_hpp
#define dynamicarray_hpp

#include "Collection.h"
#include <cassert> // for assert()
#include <algorithm> // for copy(), min(), move_backward
#include <iostream>

#define DEFAULT_CAPACITY 10

using namespace std;

namespace csi281 {
    template
        <typename T>
        class DynamicArray : public Collection<T> {
        public:
            // Initialize the dynamic array with a starting capacity
            DynamicArray(int cap = DEFAULT_CAPACITY) {
                capacity = cap;
                backingStore = new T[capacity];
            }

            // Erase the dynamic array
            ~DynamicArray() {
                delete[] backingStore;
            }

            // Find the index of a particular item
            // Return -1 if it is not found>
            // YOUR CODE HERE
            //Finder function
            int find(const T& item) {
                std::cout << "Find the index of a item" << std::endl;
                int findIndex = 0;

                while (findIndex < capacity && this->backingStore[findIndex] != item)
                {
                    findIndex++;
                }
                if (this->backingStore[findIndex] == item)
                    return findIndex;
                else
                    return -1;
            }

            // Get the item at a particular index
            T& get(int index) {
                // YOUR CODE HERE
                cout << "Get an item from an index" << endl;

                int findIndex = 0;
                //Getting the item
                while (findIndex < index)
                {
                    findIndex++;
                }
                return this->backingStore[findIndex];
            }

            // Insert at the beginning of the collection
            // Using setCapacity() if we are too small before
            // inserting
            // Hint: May want to use moveDownFrom()
            void insertAtBeginning(const T& item) {
                // YOUR CODE HERE
                cout << "Insert at the beginning of the array " << endl;

                
                int newLength = count + 1;
                const int STARTINDEX = 0;


                if (capacity < newLength)
                {
                    this->setCapacity(newLength);
                }
                //Believe this is the way to use moveDownFrom
                this->moveDownFrom(STARTINDEX);
                this->backingStore[STARTINDEX] = item;
                count++;
            }

            // Insert at the end of the collection
            // Using setCapacity() if we are too small before
            // inserting
            void insertAtEnd(const T& item) {
                // YOUR CODE HERE
                cout << "Insert at the end of the array" << endl;

                int newLength = count + 1;
                //Inserting
                if (capacity < newLength)
                {
                    this->setCapacity(newLength);
                }
                count++;
                this->backingStore[count] = item;
            }

            // Insert at a specific index
            // Using setCapacity() if we are too small before
            // inserting
            // Hint: May want to use moveDownFrom()
            void insert(const T& item, int index) {
                // YOUR CODE HERE
                cout << "Insert at a specfic index of the array" << endl;

                int newLength = count + 1;
                //Inserting
                if (capacity < newLength)
                {
                    this->setCapacity(newLength);
                }
                this->moveDownFrom(index);
                this->backingStore[index] = item;
                count++;
            }

            // Remove the item at the beginning of the collection
            void removeAtBeginning() {
                // YOUR CODE HERE
                cout << "Remove at beginning of array" << endl;

                int i = 0;
                //Removing from the begining 
                for (i = 0; i < count; i++)
                    this->backingStore[i] = this->backingStore[i + 1];
                count--;
            }

            // Remove the item at the end of the collection
            // Hint: This might be very simple.
            void removeAtEnd() {
                // YOUR CODE HERE
                //I believe this is as simple as it should be 
                cout << "Remove at end of an array" << endl;

                count--;
            }

            // Remove the item at a specific index
            // Hint: Can be done by a combination of moving items
            // down and removing the starting beginning element
            void removeAt(int index) {
                // YOUR CODE HERE
                cout << "Remove at a specfic index of the array " << endl;

                int i = index;
                //Removing
                for (i = index; i < count; i++)
                    this->backingStore[i] = this->backingStore[i + 1];
                count--;
            }

            // Change the capacity of the dynamic array
            // If it becomes less than count, just discard excess
            void setCapacity(int cap) {
                assert(cap >= 0); // can't have negative capacity
                // don't do anything if we're already correct
                if (cap == capacity) { return; }

                int numberToCopy = min(cap, count);

                T* destination = new T[cap];

                copy(backingStore, backingStore + numberToCopy, destination);
                delete[] backingStore;
                backingStore = destination;
                capacity = cap;
                if (capacity < count) { count = capacity; }
            }

            // Return the current capacity
            int getCapacity() { return capacity; }
        protected:
            //how many slots are being used
            using Collection<T>::count;
        private:
            int capacity;
            int growthFactor = 2;
            T* backingStore;

            // Shift all of the items in backingStore starting at
            // index down by 1 place
            // Make sure you have capacity available to do this before
            // running this method
            void moveDownFrom(int index) {
                move_backward(backingStore + index, backingStore + count, backingStore + count + 1);
            }
    };






}

#endif /* dynamicarray_hpp */