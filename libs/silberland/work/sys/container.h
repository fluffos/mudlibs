// SilberLand MUDlib
//
// sys/container.h -- container header
//
// $Date: 2004/09/08 11:07:19 $
/* $Revision: 1.6 $
 * $Log: container.h,v $
 * Revision 1.6  2004/09/08 11:07:19  Woody
 * prototypes from container/moving.c
 *
 * Revision 1.5  2004/08/26 17:47:44  Woody
 * moved from properties.h: P_CONTAINER, P_WEIGHT_PERCENT, P_LAST_CONTENT_CHANGE
 *
 * Revision 1.4  2003/03/19 15:52:02  Woody
 * function prototypes des locking Moduls
 *
 * Revision 1.3  2003/03/19 10:50:12  Woody
 * P_CNT_OPENCLOSE, P_CNT_FLAGS, P_CNT_CRACK_CHANCE, CNT_STATUS_BROKEN,
 * CNT_RESET*, CNT_NO_CRACK
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

#define P_CONTAINER                     "container"
#define P_MAX_WEIGHT 			"max_weight"
#define P_WEIGHT_PERCENT                "weight_percent"
#define P_CONTENTS   			"contents"
#define P_LAST_CONTENT_CHANGE           "last_content_change"
#define P_CNT_STATUS 			"cnt_status"
#define P_CNT_KEY			"cnt_key"
#define P_TRANSPARENT			"transparent"
#define P_CNT_OPENCLOSE                 "cnt_openclose"
#define P_CNT_FLAGS                     "cnt_flags"
#define P_CNT_CRACK_CHANCE              "cnt_crack_chance"

// special defines
#define CNT_STATUS_OPEN   0
#define CNT_STATUS_CLOSED 1
#define CNT_STATUS_LOCKED 2
#define CNT_STATUS_BROKEN 4

#define CNT_RESET_OPEN    1
#define CNT_RESET_CLOSE   2
#define CNT_RESET_LOCK    4
#define CNT_NO_CRACK      8

#define R_INSERT "insert"

#endif // __CONTAINER_H__

#ifdef NEED_PROTOTYPES

#ifndef __CONTAINER_H_PROTO__
#define __CONTAINER_H_PROTO__

// prototypes
// from: container/description.c
string make_invlist(object viewer, mixed inv, int shortflag);

// from: container/moving.c
varargs int deep_remove(int silent);

// from: container/restrictions.c
int query_weight_contents();

varargs int MayAddWeight(mixed weight);
varargs int PreventInsert(object ob);
object *present_objects(string complex_desc);
object *locate_objects(string complex_desc,int info);

// from: container/locking.c
int IsOpen();
int IsClosed();
int IsLocked();
int BeforeOpen();
void AfterOpen();
int BeforeClose();
void AfterClose();
int ResetFunc();
int KeyOpenFunc();
int KeyCloseFunc();

#endif // __CONTAINER_H_PROTO__

#endif // NEED_PROTOTYPES

