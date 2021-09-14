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
    int p, l;
    struct Node* start = NULL;
    do {
        std::cout << "Enter number of lines in your sparse Matrix = ";
        if (!(std::cin >> p))
            return NULL;
    } while (p < 1);
    do {
    std::cout << std::endl << "Enter number of items in lines = ";
    if (!(std::cin >> l))
        return NULL;
    } while (l < 1);

    int **TestMatric = new int*[p];

    for (int i = 0; i < p; i++) {
        TestMatric[i] = new int[i];
    }

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < l; j++) {
            std::cout << "Enter [" << j + 1 << "] elem into [" << i + 1 << "] line = " << std::endl;
            std::cin >> TestMatric[i][j];
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

    return 0;
}


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
    PrintNewMatr(start, 4, s5);

    DeleteList(start);
    _CrtDumpMemoryLeaks();  

    return 0;

}

*/