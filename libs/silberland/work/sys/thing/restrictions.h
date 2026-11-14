// SilberLand MUDlib
//
// sys/thing/restrictions.h -- restrictions of the object (weight)
//
// $Date: 1999/03/01 17:59:41 $
/* $Revision: 1.2 $
 * $Log: restrictions.h,v $
 * Revision 1.2  1999/03/01 17:59:41  Woody
 * P_TOTAL_OBJECTS definiert
 *
 * Revision 1.1  1997/03/31 16:03:11  Woody
 * prepared for revision control
 *
 */
 
#ifndef __THING_RESTRICTIONS_H__
#define __THING_RESTRICTIONS_H__

// properties
#define P_WEIGHT       "weight"       // weight of an object
#define P_TOTAL_WEIGHT "total_weight" // total weight, with all objects inside
#define P_TOTAL_OBJECTS "total_objects" // total number of objects inside

#endif // __THING_RESTRICTIONS_H__

#ifdef NEED_PROTOTYPES

#ifndef __THING_RESTRICTIONS_H_PROTO__
#define __THING_RESTRICTIONS_H_PROTO__

// prototypes
// no prototypes

#endif // __THING_RESTRICTIONS_H_PROTO__

#endif // NEED_PROTOYPES
