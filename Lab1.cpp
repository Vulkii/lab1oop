#include <stdlib.h>

#include<stdio.h>
#include <iostream>
#include <crtdbg.h>
#include "Lab1.h"

namespace Prog1 {

    void create_new_node(struct Node** start, int non_zero_element, int row_index, int column_index){

        struct Node* temp, * r;
        temp = *start;

        if (temp == NULL){
            temp = (struct Node*)malloc(sizeof(struct Node));
            temp->value = non_zero_element;
            temp->row_position = row_index;
            temp->column_postion = column_index;
            temp->next = NULL;
            *start = temp;
        }

        else{
            while (temp->next != NULL) {
                temp = temp->next;
            }

            r = (struct Node*)malloc(sizeof(struct Node));
            r->value = non_zero_element;
            r->row_position = row_index;
            r->column_postion = column_index;
            r->next = NULL;
            temp->next = r;
        }
    }



    void DeleteList(struct Node* start) {
        struct Node* r;
         r = start;

        while (start != NULL) {
            start = r->next;
            delete r;
            r = start;
        }

    }




    void PrintList(struct Node* start)

    {
        struct Node* temp, * r, * s;
        temp = r = s = start;
        printf("row_position: ");
        while (temp != NULL) {
            printf("%d ", temp->row_position);
            temp = temp->next;
        }

        printf("\n");
        printf("column_postion: ");

        while (r != NULL){
            printf("%d ", r->column_postion);
            r = r->next;
        }

        printf("\n");
        printf("Value: ");

        while (s != NULL){
            printf("%d ", s->value);
            s = s->next;
        }
        printf("\n");
    }

    void PrintMatr(struct Node* start, int p, int l) {
        struct Node* end = NULL;
        end = start;
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < l; j++) {
                if ((i == end->row_position) && (j == end->column_postion)) {
                    std::cout << end->value << " ";
                    if (end->next != NULL)
                        end = end->next;
                }
                else {
                    std::cout << "0 ";
                }
            }
            std::cout << "\n";
        }
    }

    void PrintNewMatr(struct Node* start, int p, int l) {
        struct Node* end = NULL;
        end = start;
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < l; j++) {
                if ((i == end->row_position) && (j == end->column_postion)) {
                    if (end->value > 2)
                            std::cout << end->value << " ";
                        if (end->next!=NULL)
                    end = end->next;
                }
                else {
                    std::cout << "0 ";
                }
            }
            std::cout << "\n";
        }
    }



}
