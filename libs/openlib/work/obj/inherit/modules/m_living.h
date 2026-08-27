/*  -*- LPC -*-  */
// m_living:  Functions for living objects
// Tim 24 Apr 96
#ifndef _M_LIVING_H
#define _M_LIVING_H

// Make sure you also inherit M_MOVE
#include "m_move.h"

string short();   // get this defined somewhere

//
// Prototypes
//
void low_setup();          // make sure you call thisthis
void remove();             // and this
int is_living();
int set_name(string);
string query_name();
string query_cap_name();
void set_gender(int s);
int query_gender();
int receive_damage(int);
int id(string);
string long();
int receive_object(object);
void die();

#endif /* _M_LIVING_H */
