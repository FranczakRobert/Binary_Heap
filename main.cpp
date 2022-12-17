#include <algorithm>
#include <iostream>
#include "binaryHeap.h"
struct dummyStruct{
    int data;

    bool operator<(const dummyStruct sec)
    {
        return data < sec.data;
    }
    bool operator>(const dummyStruct sec)
    {
        return data > sec.data;
    }
    bool operator==(const dummyStruct sec)
    {
        return data == sec.data;
    }
};

std::ostream& operator<<(std::ostream& os, dummyStruct s)
{
    os << s.data;
    return os;
}

void test1()
{
    binaryHeap<dummyStruct> binaryHeap;
    int tab[5] = {10,5,3,2,4};
    for (int i = 0; i < 10; ++i) {
        dummyStruct z = {i};
        binaryHeap.push(z);
    }

    std::cout << "BEFORE" << std::endl;
    binaryHeap.showArray();

    for (int i = 0; i < 10; ++i) {
        std::cout << binaryHeap.deleteRoot() << std::endl;
    }
//    binaryHeap.deleteRoot();
//    std::cout << "AFTER" << std::endl;
//    binaryHeap.showArray();
//    std::cout << "CLEAR" << std::endl;
//    binaryHeap.clearTab();
    binaryHeap.showArray();
}
#include "math.h"
#include <random>

void test2()
{
    clock_t start,end,start2,end2;
    binaryHeap<dummyStruct> binaryHeap;
    std::random_device rd;
    std::mt19937 gen(time(nullptr));
    std::uniform_int_distribution<> DISTaa(0, 1000000);

    for (int i = 0; i < 4; ++i) {
        const int n = pow(6, i);
        start = clock();
        for (int i = 0; i < n; i++) {
//            start = clock();
            int randomINT = DISTaa(gen);
            dummyStruct so = {randomINT};
            binaryHeap.push(so);

            float val = (float)end/ CLOCKS_PER_SEC;
           // std::cout << "Add time: " << val << std::endl;
        }
        end = clock() - start;
//        float val = (float)end/ CLOCKS_PER_SEC;
//        std::cout << "Add time: " << val << std::endl;

//        start2 = clock();
//        for (int j = 0; j < n; ++j) {
//            binaryHeap.deleteRoot();
//        }
//        end = clock() - start2;
//        float value = (float)end/ CLOCKS_PER_SEC;
//        std::cout << "Del time: " << value << std::endl;
    }



    std::cout << "BEFORE" << std::endl;
    binaryHeap.showArray();
    binaryHeap.deleteRoot();
    std::cout << "AFTER" << std::endl;
    binaryHeap.showArray();
    std::cout << "CLEAR" << std::endl;
    binaryHeap.clearTab();
    binaryHeap.showArray();
//    dummyStruct x = {56};
//    binaryHeap.push(x);
//    binaryHeap.showArray();

}



int main() {
    test1();
//    test2();

    return 0;
}
