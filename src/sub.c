#include "sub.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>

void subtraction_op(List *head1, List *tail1, List *head2, List *tail2, List **res_head, List **res_tail) {
    List *t1 = head1, *t2 = head2;
    int l1_size = 0, l2_size = 0;
    while (t1!=NULL) {
        l1_size++;
        t1=t1->next;
    }
    while (t2!=NULL) {
        l2_size++;
        t2=t2->next;
    }

    //Zeros Padding
    t1=head1;
    t2=head2;
    if (l1_size > l2_size) {
        int diff = l1_size - l2_size;
        for (int i=0; i<diff; i++) {
            if (t2->prev == NULL) {
                List* temp = malloc(sizeof(List));

                temp->data=0;
                temp->prev=NULL;
                temp->next=head2;

                head2->prev=temp;
                head2=temp;
            }
            t2=t2->prev;
        }

        //Subtraction Operation
        int borrow=0, difference=0;
        t1=tail1;
        t2=tail2;
        for (int i=0; i<l1_size-1; i++) {
            if (t1->data-borrow >= t2->data) {
                difference=(t1->data-borrow)-t2->data;
                borrow=0;
            } else {
                difference=(t1->data+10)-t2->data;
                borrow=1;
            }
            List* new_node = malloc(sizeof(List));
            new_node->data=difference;
            new_node->next=NULL;
            new_node->prev=NULL;

            if (*res_head == NULL) {
                *res_head=new_node;
                *res_tail=new_node;
            } else {
                // Insert at the beginning
                new_node->next = *res_head;
                (*res_head)->prev = new_node;
                *res_head = new_node;
            }

            t1=t1->prev;
            t2=t2->prev;
        }

        difference=(t1->data-borrow)-t2->data;
        List* new_node = malloc(sizeof(List));
        new_node->data=difference;
        new_node->next = *res_head;
        (*res_head)->prev = new_node;
        *res_head = new_node;
    }
}
