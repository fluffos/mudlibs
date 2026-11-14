// SilberLand MUDlib
//
// sys/container.h -- container header
//
// $Date: 1997/10/16 15:50:07 $
/* $Revision: 1.2 $
 * $Log: container.h,v $
 * Revision 1.2  1997/10/16 15:50:07  Woody
 * Neuer Prototyp fuer MayAddWeight() (mixed als Parameter)
 *
 * Revision 1.1  1997/03/31 12:43:07  Woody
 * prepared for revision control
 *
 * Revision 1.0  22/02/96  23:00:00  Hadra
 * Definition von make_invlist() geaendert
 *
 */
 
#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include <thing/restrictions.h>

// properties

#define P_MAX_WEIGHT 			"max_weight"
#define P_CONTENTS   			"contents"
#define P_CNT_STATUS 			"cnt_status"
#define P_CNT_KEY			"cnt_key"
#define P_TRANSPARENT			"transparent"

// special defines
#define CNT_STATUS_OPEN   0
#define CNT_STATUS_CLOSED 1
#define CNT_STATUS_LOCKED 2

#define R_INSERT "insert"

#endif // __CONTAINER_H__

#ifdef NEED_PROTOTYPES

#ifndef __CONTAINER_H_PROTO__
#define __CONTAINER_H_PROTO__

// prototypes
// from: container/description.c
string make_invlist(object viewer, mixed inv, int shortflag);

// from: container/restrictions.c
int query_weight_contents();

varargs int MayAddWeight(mixed weight);
varargs int PreventInsert(object ob);
object *present_objects(string complex_desc);
object *locate_objects(string complex_desc,int info);

#endif // __CONTAINER_H_PROTO__

#endif // NEED_PROTOTYPES

