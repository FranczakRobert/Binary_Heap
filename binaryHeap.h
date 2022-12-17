//
// Created by Robert Franczak on 14/12/2022.
//

#ifndef BINARYHEAP_BINARYHEAP_H
#define BINARYHEAP_BINARYHEAP_H

#include "dynamicArray.h"
template<typename T>
class binaryHeap{
public:
    binaryHeap(){};
    ~binaryHeap(){};

    void push(const T& element)
    {
        //Insert the new element at the end
        int childPosition = array.add(element);
        if(length > 0)
            heapifyBottomUp(childPosition - 1);
        length++;
    }

    T deleteRoot()
    {
        T retRoot;
        if(!array.getElementCount())
            return retRoot;

        retRoot = array.dynamicTab[0];
        array.dynamicTab[0] = array.dynamicTab[array.getElementCount() - 1];

        array.elementCount--;
        heapifyTopDown(0);

        return retRoot;
    }

    void clearTab()
    {
        array.clearArray();
    }

    void showArray(){ array.showArray();}
    void heapSize(){array.getSize();}
    void heapLength(){array.getElementCount();}

private:
    void heapifyBottomUp(int childPosition)
    {
        int parentPosition = (childPosition - 1) / 2;

            if(array.dynamicTab[parentPosition] < array.dynamicTab[childPosition])
            {
                std::swap(array.dynamicTab[parentPosition], array.dynamicTab[childPosition]);
                heapifyBottomUp(parentPosition);
            }
    }

    void heapifyTopDown(int index)
    {
        int largest = index;
        int rightChildIndex = 2 * index + 1;
        int leftChildIndex  = 2 * index + 2;

        if(leftChildIndex < array.getElementCount()  && array.dynamicTab[leftChildIndex] > array.dynamicTab[largest])
            largest = leftChildIndex;

        if(rightChildIndex < array.getElementCount() &&  array.dynamicTab[rightChildIndex] > array.dynamicTab[largest])
            largest = rightChildIndex;

        if(largest != index)
        {
            std::swap(array.dynamicTab[index],array.dynamicTab[largest]);
            heapifyTopDown(largest);
        }
    }
    dynamicArray<T> array;
    int length = 0;
};

#endif //BINARYHEAP_BINARYHEAP_H
