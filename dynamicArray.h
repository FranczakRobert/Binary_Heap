//
// Created by Robert Franczak on 14/12/2022.
//
#include <iostream>

#ifndef BINARYHEAP_DYNAMICARRAY_H
#define BINARYHEAP_DYNAMICARRAY_H
#include <algorithm>
#include <iostream>

template<typename T>
class dynamicArray{
public:
    dynamicArray():size(2){dynamicTab = new T[newSize];}
    ~dynamicArray(){ delete [] dynamicTab;}

    int add(const T& element)
    {
        if(nullptr == dynamicTab)
            dynamicTab = new T[newSize];

        if(size > elementCount)
        {
            dynamicTab[elementCount] = element;
        }
        else
        {
            T* helper = new T[size *= newSize];
            std::copy(dynamicTab, dynamicTab+size, helper);
            delete [] dynamicTab;
            dynamicTab = helper;
            dynamicTab[elementCount] = element;

        }
        elementCount++;

        return elementCount;
    }

    void clearArray()
    {
        if(nullptr != dynamicTab)
        {
            delete[] dynamicTab;
            dynamicTab = nullptr;
            size = 2;
            elementCount = 0;
            std::cout << "Array cleard..." << std::endl;
        }
        else
        {
            std::cout << "Array already cleared..." << std::endl;
        }

    }

    int getSize() {return size;}
    int getElementCount() {return elementCount;}

    void showArray()
    {
        if(getElementCount())
        {
            for (int i = 0; i < elementCount; ++i) {
                std::cout << i + 1 << " : " <<  dynamicTab[i] << std::endl;
            }
        }
        else
        {
            std::cout << "Empty...." << std::endl;
        }
    }

    T* dynamicTab;
    int elementCount = 0;
private:
    int size = 2;
    int newSize = 2;
};


#endif //BINARYHEAP_DYNAMICARRAY_H
