/*
 * basic/timedep.h
 * Time dependant references
 */

#ifndef _basic_timedep_h
#define _basic_timedep_h

// The following include is only for compatibility
#include "timedep.h"

string *set_timedep(int *when, mixed *what, string *space, string which);
mixed query_timedep(string *space);
string *add_timedep(int when, mixed what, string *space);
mixed *query_timedep_table(string *space);
void set_default_depspace(string *depspace);

#endif /* _basic_timedep_h */
