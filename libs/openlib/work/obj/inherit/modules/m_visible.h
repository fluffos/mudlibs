/*  -*- LPC -*-  */
// m_visible.c:  Functions for objects which can be seen
// Tim 23 Apr 96
#ifndef _M_VISIBLE_H
#define _M_VISIBLE_H

//
// Prototypes
//
void initialize();        // make sure to call this in your routine
void set_short(string);
void set_long(string);
string short();
string long();
void add_ids(string*);
string* query_ids();
int id(string);

#endif /* _M_VISIBLE_H */
