#include "common.h"
#include <stdio.h>

void print_result(List *head, List *tail) {
    printf("Result: ");
    while (head) {
        printf("%d", head->data);
        head=head->next;
    }
    printf("\n");
}
