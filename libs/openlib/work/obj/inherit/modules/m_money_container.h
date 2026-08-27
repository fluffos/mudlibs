// m_money_container:  Functions for objects which contain money
// Tim 24 Apr 96
#ifndef M_MONEY_CONTAINER_H
#define M_MONEY_CONTAINER_H

// You should inherit M_CONTAINER to define query_weight_capacity() if you
// don't define it yourself
#include "m_container.h"
#include <money.h>

void initialize();
int add_money(int*);
int remove_money(int*);
int* query_money();
int query_weight_contained();      // also in M_CONTAINER

#endif /* M_MONEY_CONTAINER_H */
