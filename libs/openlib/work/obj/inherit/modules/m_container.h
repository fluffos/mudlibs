/*  -*- LPC -*-  */
// container.h:  Functions for containers
// Tim 23 Apr 96
#ifndef _M_CONTAINER_H
#define _M_CONTAINER_H

//
// You should inherit M_VISIBLE and M_DIMENSIONS and M_OBJECT_CLASS
// before this one so the proper functions are available.
//
#include "m_object_class.h"
#include "m_visible.h"
#include "m_dimensions.h"

//
// Prototypes
//
void initialize();               // make sure you call this in your routine
int set_rigid(int);
int query_weight_contained();
int query_bulk_contained();
int query_weight();
int query_bulk();
int receive_object(object);
int set_weight_capacity(int);
int query_weight_capacity();
int set_bulk_capacity(int);
int query_bulk_capacity();
string long();

#endif /* _M_CONTAINER_H */
