// Tamedhon MUDlib
//
// sys/container.h -- container header
//
// 2024/04/09 - includes als absolutpfad, damit auch das masterobjekt laden kann - Aloy
//
// $Date: 1997/10/16 15:50:07 $
/* $Revision: 1.2 $
 * $Log: container.h,v $
 *
 * Revision 1.5  Tue Sep 09 22:20:00 2003, Serii
 * /std/living/put_and_get.c will dass CNT_(_STATUS_)OPEN == 0.
 * hoffe das bringt keine probleme mit sich :)
 *
 * Revision 1.4  Mon Jul 28 23:00:00 2003, Serii@Tamedhon
 * da hat alles moegliche rumgebugt weil wohl einige props entfernt bzw.
 * geaendert wurden
 * (P_CNT_KEY,CNT_STATUS_LOCKED,CNT_STATUS_OPEN,CNT_STATUS_CLOSED, P_CNT_STATUS)
 * habs wieder alles ordentlich gemacht unds geht
 * (also /obj/container.c hat nimma gefunkt, nun tuts wieder)
 *
 * (Ohne RCS)
 * Revision 1.3  Wed Apr 21 23:02:54 1999, Shannara@Turithil
 * Ueberfluessige Properties und Flags geloescht
 * 
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

#include "/sys/thing/restrictions.h"

// properties

#define P_WEIGHT_PERCENT		"weight_percent"
#define P_MAX_WEIGHT 			"max_weight"
#define P_CONTENTS   			"contents"
#define P_TRANSPARENT			"transparent"

#define P_KEYLOCK			"keylock"
#define P_TRAP_CHANCE			"trap_chance"

#define R_INSERT "insert"

// Containerstatus
#define CNT_LOCKED			-1
#define CNT_CLOSED			1
#define CNT_OPENED			0
#define CNT_STATUS_CLOSED	CNT_CLOSED
#define CNT_STATUS_LOCKED	CNT_LOCKED
#define CNT_STATUS_OPEN		CNT_OPENED

#define P_CNT_STATUS			"cnt_status"
#define P_CNT_KEY			"cnt_key"

#endif // __CONTAINER_H__

#ifdef NEED_PROTOTYPES

#ifndef __CONTAINER_H_PROTO__
#define __CONTAINER_H_PROTO__

// prototypes
// from: container/description.c
string make_invlist(object viewer, mixed inv, int flags);

// from: container/restrictions.c
int query_weight_contents();

varargs int MayAddWeight(mixed weight);
varargs int PreventInsert(object ob);
object *present_objects(string complex_desc);
object *locate_objects(string complex_desc,int info);

#endif // __CONTAINER_H_PROTO__

#endif // NEED_PROTOTYPES

