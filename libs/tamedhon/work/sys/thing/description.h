// SilberLand MUDlib
//
// sys/thing/description.h -- standard thing description header
//
// $Date: 2008/06/30 14:12:00 $
/* $Revision: 2.6 $
 * $Log: description.h,v $
 *
 * Revision 2.61  2012/06/15 09:23:00  Serii
 * P_ORIG_IDS
 *
 * Revision 2.6  2008/06/30 14:12:00  TamTam
 * P_ORIG_HP
 *
 * Revision 2.5  2002/12/29 14:12:00  Serii
 * P_ORIG_GENDER
 *
 * Revision 2.4  2002/12/24 02:56:00  Serii
 * P_ORIG_FULL_NAME
 *
 * Revision 2.3  1997/03/31 15:51:00  Woody
 * Prototyp fuer Name()
 *
 * Revision 2.2  1997/03/31 15:48:09  Woody
 * prepared for revision control
 *
 * Revision 2.1  1996/05/25  15:00:00  Woody
 * P_SOUND und P_SMELL eingefuehrt
 *
 * Revision 2.0  1996/04/17  02:15:00  Woody
 * details hier reingepflanzt
 *
 * Revision 1.41 1996/01/23  20:00:00  Hadra
 * P_NO_INVIS eingefuehrt
 *
 * Revision 1.4  1995/08/07  19:09:16  Wargon
 * Prototypes fuer RemoveId/Adjective
 *
 * Revision 1.3  1994/11/03  00:31:51  Jof
 * *** empty log message ***
 *
 * Revision 1.2  1994/09/29  15:40:27  Jof
 * *** empty log message ***
 *
 * Revision 1.1  1994/09/23  20:30:43  Hate
 * Initial revision
 *
 */

#ifndef __THING_DESCRIPTION_H__
#define __THING_DESCRIPTION_H__

// properties
#define P_NAME       "name"       // name of the object
#define P_NAME_FLAG   "name_flag"    // name specific properties
#define P_NAME_AMOUNT "name_amount"  // description of amount
#define P_NAME_OWNER  "name_owner"   // owner of the object
#define P_ORIG_NAME  "orig_name"  // original name of the object (corpse)
#define P_ORIG_FULL_NAME "orig_full_name" // the complete original P_NAME, for\
					  // it might have been an ({})
#define P_ORIG_IDS	"orig_ids"	// original P_IDS (corpse)
#define P_ORIG_GENDER	"orig_gender"	// original gender (corpse)
#define P_ORIG_HP	"orig_hp"	// original P_MAX_HP (corpse)
#define P_NAME_ADJ   "name_adj"   // adjective of the name of the object
#define P_SHORT      "short"      // short desciption of the object
#define P_LONG       "long"       // long description of the object
#define P_IDS        "ids"        // identifier of the object
#define P_ADJECTIVES "adjectives" // adjectives of the object
#define P_SHOW_INV   "show_inv"   // Show in inventory of player
#define P_NO_INVIS   "no_invis"   // can't be made invisible
#define P_CLASS      "class"      // class, like "undead" or "explosive"

#define P_DETAILS         "details"
#define P_SPECIAL_DETAILS "special_details"
#define P_READ_DETAILS    "read_details"

#define P_SOUND "sound"
#define P_SMELL "smell"

// Modi fuer name()
#define NAME_INDEF        0       // unbestimmter Artikel
#define NAME_DEF          1       // bestimmter Artikel
#define NAME_AUTO         2       // Artikel automatisch bestimmen
#define NAME_NONE         3       // kein Artikel (nur Libintern!)
#define NAME_DESCR        4       // Beschreibender Modus mit P_DESCR
#define NAME_PLURAL       8       // Plural erzeugen wenn moeglich
#define NAME_UACT        16       // Units vorher aktualisieren
#define NAME_CAP         32       // String capitalizen
#define NAME_STATE       64       // Status-Infos mitausgeben
#define NAME_NO_NUMBER  128       // Name von units ohne die Zahlenangabe
#define NAME_V_IS_WIZ   256       // Viewer ist Magier
#define NAME_PLURAL_ART 512       // Plural mit Artikel erzeugen
#define NAME_OWNER     1024       // Besitzer mit anzeigen
#define NAME_NO_ADJ    2048       // Adjektive unterdruecken

#define NAME_DEM     (NAME_INDEF|NAME_DEF|NAME_AUTO|NAME_NONE)

// Flags in P_NAME_FLAG
#define NAME_PERSONAL         0x0001 // Der Name ist ein Rufname
#define NAME_ADJECTIVE        0x0002 // Der Name ist ein substanti. Adjektiv
#define NAME_AMOUNT_INDEF     0x0004 
#define NAME_PLURALOBJ        0x0008 // Das Objekt repraesentiert mehrere Obj
#define NAME_AMOUNT_NOT_DECL  0x0010
#define NAME_NOCOMBINE        0x0020 // Mehrere Objekte nicht zusammenfassen
#define NAME_AMOUNT_SINGULAR  0x0040
#define NAME_WEAK_DECL        0x0080 // Maskulina des Typs II (+en gebeugt)
#define NAME_STRONG_DECL      0x0100 // Maskulina des Typs I  (ungebeugt)


#endif // __THING_DESCRIPTION_H__

#ifdef NEED_PROTOTYPES

#ifndef __THING_DESCRIPTION_H_PROTO__
#define __THING_DESCRIPTION_H_PROTO__

// prototypes

// detail handling
void AddDetail(mixed *keys, mixed descr);
void RemoveDetail(mixed *keys);
void AddSpecialDetail(mixed keys, string func);
void RemoveSpecialDetail(mixed keys);
void AddReadDetail(mixed keys, mixed descr);
void RemoveReadDetail(mixed keys);

// sound/smell handling
varargs string GetSmell(mixed race);
varargs string GetSound(mixed race);

// check if the objects can by identified by str
varargs int id(string str, int lvl);

// add an id to the current object
void AddId(mixed str);

// remove an id from the object
void RemoveId(mixed str);

// add an adjective to describe the object
void AddAdjective(mixed str);

// remove an adjective from the object
void RemoveAdjective(mixed str);

// get the name with casus and demonstrative
varargs string name(int casus, int demon);

// capitalize(name())
varargs string Name(int casus, int demon);

// check whether object is plural (or unit with amount != 1)
int IsPlural();

// send a message to an object (or -e.g. for rooms- to its inventory)
varargs int Message(string msg, int flag, mixed extra);

#endif // __THING_DESCRIPTION_H_PROTO__

#endif	// NEED_PROTOYPES
