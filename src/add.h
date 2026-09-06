#ifndef ADD_H
#define ADD_H
#define MAX(x1, x2) x1 > x2 ? x1 : x2
#include "types.h"

void addition_op(List *head1, List *tail1, List *head2, List *tail2, List **res_head, List **res_tail);

#endif
