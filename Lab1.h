#pragma once
#include <iostream>
namespace Prog1 {



    struct Node

    {
        int value;
        int row_position;
        int column_postion;
        struct Node* next;
    };


    void create_new_node(struct Node** start, int non_zero_element, int row_index, int column_index);
    void DeleteList(struct Node* start);
    void PrintList(struct Node* start);
    void PrintNewMatr(struct Node* start, int p, int l);
    void PrintMatr(struct Node* start, int p, int l);
}