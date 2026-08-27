/*  -*- LPC -*-  */
// m_move.c:  Functions for movable objects
// Tim 23 Apr 96
#ifndef _M_MOVE_H
#define _M_MOVE_H

//
// Prototypes
//
int move(mixed);                     // returns 1 for successful move
int receive_object(object);          // returns 1 if we can contain the object
void set_prevent_get(int);
void set_prevent_drop(int);
int get();                           // returns 1 if we can get this object
int drop();                          // returns 1 if we can drop this object

#endif /* _M_MOVE_H */
