// SilberLand MUDlib
//
// sys/pub.h -- standard pub header
//
// $Date: 1998/01/17 00:39:41 $
/* $Revision: 1.1 $
 * $Log: pub.h,v $
 * Revision 1.1  1998/01/17 00:39:41  Woody
 * Initial revision
 *
 */

#ifndef __PUB_H__
#define __PUB_H__

// defines
// values for pub flags
#define PUB_HASKEEPER     1    // Die Kneipe hat einen Besitzer
#define PUB_NEEDSKEEPER   2    // Der muss fuer alle Aktionen anwesend sein!
#define PUB_SERVEENEMIES  4    // Er serviert auch Feinden etwas
#define PUB_SERVESINFIGHT 8    // Er serviert auch, waehrend er kaempft

// properties
#define P_PUB_FLAGS         "pub_flags"         // siehe PUB_*
#define P_PUBKEEPER_ID      "pubkeeper_id"      // ID des Besitzers
#define P_PUBKEEPER_NAME    "pubkeeper_name"    // "Max", "der Wirt"...
#define P_PUBKEEPER_GENDER  "pubkeeper_gender"  // MALE/FEMALE

#define P_PUBMSG_NOKEEPER   "pubmsg_nokeeper"   // Meldung, wenn Wirt nicht da
#define P_PUBMSG_NOENEMY    "pubmsg_noenemy"    // Meldung, wenn Feind was will
#define P_PUBMSG_NOINVITE   "pubmsg_noinvite"   // Meldung, wenn jmd. einem
                                                // Feind was spendieren will
#define P_PUBMSG_FIGHTING   "pubmsg_fighting"   // Meldung, wenn Wirt kaempft

#endif // __PUB_H__

#ifdef NEED_PROTOTYPES

#ifndef __PUB_H_PROTO__
#define __PUB_H_PROTO__

// prototypes
varargs void AddFood (string nameOfFood, mixed ids, int price, mixed heal,
    mixed soak, mixed myFunction);
varargs void AddDrink (string nameOfDrink, int ids, int price, mixed heal,
    int strength, int soak, mixed myFunction);

#endif // __PUB_H_PROTO__

#endif  // NEED_PROTOYPES

