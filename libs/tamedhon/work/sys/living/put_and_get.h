// SilberLand MUDlib
//
// sys/living/put_and_get.h -- put/get handling header
//
// $Date: 1997/03/31 14:31:22 $
/* $Revision: 1.1 $
 * $Log: put_and_get.h,v $
 * Revision 1.1  1997/03/31 14:31:22  Woody
 * prepared for revision control
 *
 */
 
#ifndef __LIVING_PUT_AND_GET_H__
#define __LIVING_PUT_AND_GET_H__

// properties
// no special properties

#endif // __LIVING_PUT_AND_GET_H__

// prototypes
#ifdef NEED_PROTOTYPES

#ifndef __LIVING_PUT_AND_GET_H_PROTO__
#define __LIVING_PUT_AND_GET_H_PROTO__

varargs object *select_objects(string str, mixed info, int inv_first);
void add_put_and_get_commands();
int drop_obj(object ob);
int give_obj(object ob, object where);

#endif // __LIVING_PUT_AND_GET_H_PROTO__

#endif	// NEED_PROTOYPES

