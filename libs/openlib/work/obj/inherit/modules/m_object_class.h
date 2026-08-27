// m_object_class.h:  Functions for setting/checking the type of an object
// Tim 23 Apr 96

#ifndef _M_OBJECT_CLASS_H
#define _M_OBJECT_CLASS_H

#include <object_types.h>

//
// Prototypes
//
void set_object_class(int);  // Takes a bitfield as defined in <object_types.h>
int query_object_class();    // returns the object class bitfield
int query_is_class(int);     // returns 1 if this obj is the type passed

#endif /* _M_OBJECT_CLASS_H */
