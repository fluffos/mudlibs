// SilberLand MUDlib
//
// sys/laden.h -- standard shop header
//
// $Date: 1997/03/31 12:56:47 $
/* $Revision: 1.1 $
 * $Log: laden.h,v $
 * Revision 1.1  1997/03/31 12:56:47  Woody
 * prepared for revision control
 *
 */

#ifndef __LADEN_H__
#define __LADEN_H__

// defines
// values for shop flags
#define SHOP_HASKEEPER     1    // Der Laden hat einen Besitzer
#define SHOP_NEEDSKEEPER   2    // Der muss fuer alle Aktionen anwesend sein!

// properties
#define P_SHOP_FLAGS         "shop_flags"         // siehe SHOP_*
#define P_SHOPKEEPER_ID      "shopkeeper_id"      // ID des Besitzers
#define P_SHOPKEEPER_NAME    "shopkeeper_name"    // "Lena", "der Haendler"...
#define P_SHOPKEEPER_GENDER  "shopkeeper_gender"  // MALE/FEMALE

#endif // __LADEN_H__

#ifdef NEED_PROTOTYPES

#ifndef __LADEN_H_PROTO__
#define __LADEN_H_PROTO__

// prototypes
void SetStorageRoom(string str);
varargs AddFixedObject(string str, int val, mixed ids);
// no prototypes

#endif // __LADEN_H_PROTO__

#endif  // NEED_PROTOYPES

