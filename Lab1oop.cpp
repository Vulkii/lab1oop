#pragma once
#include "Lab1.h"
#include <iostream>
#define _CRTDBG_MAP_ALLOC

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

using namespace Prog1;

int main() {
    int p, l, k, choose;
    struct Node* initmatr = NULL;
    struct Node* newmatr = NULL;

    do {
        std::cout << "Enter number of lines in your sparse Matrix = ";
        if (!(std::cin >> p))
            return -1;
    } while (p < 1);
    do {
        std::cout << std::endl << "Enter number of items in lines = ";
        if (!(std::cin >> l))
            return -1;
    } while (l < 1);


    initmatr = input(p, l);


    std::cout << "\nOld Matrix\n";
    PrintMatr(initmatr, p, l);

    do {
        std::cout << std::endl << "Enter which mode do you want \nIf you want all digits > 2 type: 1. \nIf you want all digits are even - type: 2.\n";
        if (!(std::cin >> choose))
            return -1;
    } while ((choose < 0) && (choose > 2));

    switch (choose) {
        case 1:
            newmatr = modify(initmatr, p, l, digitsmorethen2);
            break;
        case 2:
            newmatr = modify(initmatr, p, l, onlyevendigits);
            break;
    }   
   std::cout << "\nNew Matrix\n";
   PrintMatr(newmatr, p, l);

   DeleteList(initmatr);
   DeleteList(newmatr);


    _CrtDumpMemoryLeaks();
    return 0;
}
/*

         0 2 3 -> 1 0 5 -> 1 1 61 -> 1 2 44 -> 2 0 14 -> 2 1 39 -> 2 2 4

     0  0 0 3 
     1  5 61 44
     2  14 39 4

        0  1  2
        
*/