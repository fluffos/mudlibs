// SilberLand MUDlib
//
// sys/thing/moving.h -- object moving header
//
// $Date: 1998/09/20 15:20:39 $
/* $Revision: 1.4 $
 * $Log: moving.h,v $
 * Revision 1.4  1998/09/20 15:20:39  Woody
 * P_LAST_MOVE
 *
 * Revision 1.3  1997/03/31 16:00:45  Woody
 * prepared for revision control
 *
 * Revision 1.2  1997/02/10  Woody
 * P_SENSITIVE
 *
 * Revision 1.1  1994/09/23  20:30:43  Hate
 * Initial revision
 *
 */
 
#ifndef __THING_MOVING_H__
#define __THING_MOVING_H__

// properties
#define P_NODROP        "nodrop"  // can't be dropped
#define P_NOGET         "noget"   // can't be taken
#define P_SENSITIVE     "sensitive"  // array of objects to inform on move
#define P_LAST_MOVE     "last_move"

#endif // __THING_MOVING_H__

#ifdef NEED_PROTOTYPES

#ifndef __THING_MOVING_H_PROTO__
#define __THING_MOVING_H_PROTO__

// prototypes
// move the object from current position to dest using the method
varargs int move(mixed dest, int method);

// remove the object return 1 for successful destruction
varargs int remove();

#endif // __THING_MOVING_H_PROTO__

#endif // NEED_PROTOYPES
