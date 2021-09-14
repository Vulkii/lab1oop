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

int main(){

    // Свое заполнение
    int p, l, k;
    struct Node* modified = NULL;
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
    
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < l; j++) {
            std::cout << "Enter [" << j + 1 << "] elem into [" << i + 1 << "] line = " << std::endl;
            do {
                if (!(std::cin >> k))
                    return -1;
            } while (k < -1);
            
            if (k > 0) {
                create_new_node(&modified, k, i, j);
            }
        }
    }


    PrintList(modified);
    std::cout << "\nOur Matrix\n";
    PrintMatr(modified, p, l);
    std::cout << "\nNew Matrix\n";
    PrintNewMatr(modified, p, l);

    DeleteList(modified);


    _CrtDumpMemoryLeaks();
    return 0;
}














    /*
    // Свое заполнение
    int p, l;
    struct Node* start = NULL;
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

    int **TestMatric = new int*[p];

    for (int i = 0; i < p; i++) {
        TestMatric[i] = new int[i];
    }

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < l; j++) {
            std::cout << "Enter [" << j + 1 << "] elem into [" << i + 1 << "] line = " << std::endl;
            do {
                if (!(std::cin >> TestMatric[i][j]))
                    return -1;
            } while (TestMatric[i][j] < -1);
        }
    }
    for (int i = 0; i < p; i++)
        for (int j = 0; j < l; j++)
             if (TestMatric[i][j] != 0)
                create_new_node(&start, TestMatric[i][j], i, j);

    PrintList(start);
    std::cout << "\nOur Matrix\n";
    PrintMatr(start, p, l);
    std::cout << "\nNew Matrix\n";
    PrintNewMatr(start, p, l);

    DeleteList(start);
    
   for (int i = 0; i < p; i++) {  // fix
      delete[] TestMatric[i];

    }
    delete[] TestMatric;
 
    _CrtDumpMemoryLeaks();
    return 0;
}
*/

    /*
    // АВТОЗАПОЛНЕНИЕ
    struct Node* start = NULL;
    int sparseMatric[4][5] =

    {

        {1 , 1 , 3 , 0 , 1 },

        {0 , 0 , 5 , 7 , -1 },

        {0 , 0 , 0 , 1 , 0 },

        {0 , 2 , 0 , 6 , 0 }

    };

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (sparseMatric[i][j] != 0)
                create_new_node(&start, sparseMatric[i][j], i, j);

    PrintList(start);
    std::cout << "\nOur Matrix\n";
    PrintMatr(start, 4, 5);
    std::cout << "\nNew Matrix\n";
    PrintNewMatr(start, 4, 5);

    DeleteList(start);
    _CrtDumpMemoryLeaks();

    return 0;

}
*/

