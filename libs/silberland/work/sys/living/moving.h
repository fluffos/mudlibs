// SilberLand MUDlib
//
// sys/living/moving.h -- living moving header
//
// $Date: 1998/09/20 15:19:09 $
/* $Revision: 1.1 $
 * $Log: moving.h,v $
 * Revision 1.1  1998/09/20 15:19:09  Woody
 * Initial revision
 *
 */
 
#ifndef __LIVING_MOVING_H__
#define __LIVING_MOVING_H__

// properties
#define P_PURSUERS              "pursuers"

#endif // __LIVING_MOVING_H__

// prototypes
#ifdef NEED_PROTOTYPES

#ifndef __LIVING_MOVING_H_PROTO__
#define __LIVING_MOVING_H_PROTO__

void AddPursuer(object ob);
void RemovePursuer(object ob);
object *QueryPursuers();
int QueryNeededMv();
int TryMove(mixed dest, int methods);
void TakeFollowers();
int PreventFollow(object dest);

#endif // __LIVING_MOVING_H_PROTO__

#endif	// NEED_PROTOYPES

