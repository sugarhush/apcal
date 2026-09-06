#include <stdio.h>
#include "sub.h"
#include "types.h"
#include "validate.h"
#include "add.h"
#include "common.h"

int main(int argc, char **argv)
{
    // Usage: ./a.out <num1> <op> <num2>
    // Example: ./a.out 1593408239 + 9345021885
    if (argc != 4)
    {
        printf("Usage: ./a.out <num1> <op> <num2>\n");
        return FAILURE;
    }

    // Validate arguments
    if (validate_args(argv[1], argv[2], argv[3]) == FAILURE)
    {
        return FAILURE;
    }

    List *head1 = NULL;
    List *tail1 = NULL;
    List *head2 = NULL;
    List *tail2 = NULL;

    // Initialize linked lists
    if (list_initialization(&head1, &head2, &tail1, &tail2, argv[1], argv[3]) == FAILURE)
    {
        printf("ERROR: List initialization failed\n");
        return FAILURE;
    }

    // print_list(head1, tail1, head2, tail2);

    //Addition Operation
    List *res_head=NULL, *res_tail=NULL;
    addition_op(head1, tail1, head2, tail2, &res_head, &res_tail);

    print_result(res_head, res_tail);

    //Subtraction Operation
    res_head=NULL; res_tail=NULL;
    subtraction_op(head1, tail1, head2, tail2, &res_head, &res_tail);

    print_result(res_head, res_tail);
    return SUCCESS;
}

