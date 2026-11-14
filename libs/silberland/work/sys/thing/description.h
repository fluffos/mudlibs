// SilberLand MUDlib
//
// sys/thing/description.h -- standard thing description header
//
// $Date: 2003/12/26 01:02:53 $
/* $Revision: 2.9 $
 * $Log: description.h,v $
 * Revision 2.9  2003/12/26 01:02:53  Woody
 * MSGFLAG_* und MESSAGE_* Definitionen hierher verlegt
 *
 * Revision 2.8  2003/12/19 00:33:39  Woody
 * added "extra" parameter to Message()
 *
 * Revision 2.7  2003/07/14 22:18:12  Feyaria
 * P_ORIG_FILENAME
 *
 * Revision 2.6  2000/10/20 23:21:19  Woody
 * P_CLONER herverlegt, P_CLONE_TIME neu
 *
 * Revision 2.5  1999/09/16 10:04:50  Woody
 * Message() prototype vom Player-Object hierher verlegt
 *
 * Revision 2.4  1998/10/20 00:24:36  Woody
 * IsPlural(), prototypes name() und Name()
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
#define P_ORIG_NAME  "orig_name"  // original name of the object (corpse)
#define P_ORIG_FILENAME "orig_filename"  // original file_name of the object (corpse)
#define P_NAME_ADJ   "name_adj"   // adjective of the name of the object
#define P_SHORT      "short"      // short desciption of the object
#define P_LONG       "long"       // long description of the object
#define P_IDS        "ids"        // identifier of the object
#define P_ADJECTIVES "adjectives" // adjectives of the object
#define P_SHOW_INV   "show_inv"   // Show in inventory of player
#define P_NO_INVIS   "no_invis"   // can't be made invisible
#define P_CLASS      "class"      // class, like "undead" or "explosive"

#define P_CLONER     "cloner"     // cloner of the object
#define P_CLONE_TIME "clone_time" // creation (cloning) time of the object

#define P_DETAILS         "details"             // details of the object
#define P_SPECIAL_DETAILS "special_details"     // special details
#define P_READ_DETAILS    "read_details"        // read details

#define P_SOUND "sound"         // specific sound of an object
#define P_SMELL "smell"         // specific smell of an object

// definitions for Message()

// for players only (OOC messages etc.):
#define MSGFLAG_CHANNEL         0x00000001  // messages from channeld.c
#define MSGFLAG_CHIST           0x00000002
#define MSGFLAG_SOUL            0x00000004  // messages from soul.c
#define MSGFLAG_REMOTE          0x00000008  // remote emotes
#define MSGFLAG_SHOUT           0x00000010  // communication commands
#define MSGFLAG_TELL            0x00000020
#define MSGFLAG_SAY             0x00000040
#define MSGFLAG_WHISPER         0x00000080
#define MSGFLAG_MECHO           0x00000100
#define MSGFLAG_RTELL           0x00000200  // tell from other mud
#define MSGFLAG_SILENT          0x00000400  // "silent" - no ignore messages

// mainly for rooms (generic messages):
#define MSGFLAG_SOUND           0x00010000  // etwas, was man hoert
#define MSGFLAG_VISUAL          0x00020000  // ...sieht
#define MSGFLAG_SMELL           0x00040000  // ...riecht
#define MSGFLAG_SENSE           0x00080000  // ...spuert (Lufthauch, o.ae.)
#define MSGFLAG_NO_TP           MSGFLAG_SILENT  // Keine Ausgabe an this_player()

// index strings for extra parameter:
#define MSGFLAG_EXCLUDE         "exclude"   // Liste von exclude-Objekten
#define MSGFLAG_INCLUDE         "include"   // Liste von include-Objekten
#define MSGFLAG_PERM_FUNC       "perm_func" // Permutations-Funktion

// Was geht in den Kobold?
#define MSGFLAG_CACHE   (MSGFLAG_TELL | MSGFLAG_REMOTE | \
                         MSGFLAG_WHISPER | MSGFLAG_RTELL)

// Was kommt in welche History?
#define MSGFLAG_THIST   (MSGFLAG_TELL | MSGFLAG_RTELL)
#define MSGFLAG_SHIST   (MSGFLAG_SAY)
#define MSGFLAG_HIST    (MSGFLAG_THIST | MSGFLAG_SHIST)

// Wo pruefen wir auf Taubheit?
#define MSGFLAG_DEAFCHK (MSGFLAG_SHOUT | MSGFLAG_TELL | MSGFLAG_SAY \
        | MSGFLAG_WHISPER | MSGFLAG_CHANNEL | MSGFLAG_RTELL)

// Rueckgabewerte von Message()
#define MESSAGE_OK           1  // alles klar
#define MESSAGE_CACHE        0  // Meldung steht im Kobold
#define MESSAGE_IGNORE_YOU  -1  // Meldung/Sender wird ignoriert
#define MESSAGE_IGNORE_VERB -2
#define MESSAGE_IGNORE_MUD  -3
#define MESSAGE_DEAF        -4  // Empfaenger hoert nicht zu
#define MESSAGE_CACHE_FULL  -5  // Kobold kann nichts mehr merken

#endif // __THING_DESCRIPTION_H__

#ifdef NEED_PROTOTYPES

#ifndef __THING_DESCRIPTION_H_PROTO__
#define __THING_DESCRIPTION_H_PROTO__

// prototypes

// detail handling
void AddDetail(mixed *keys, mixed descr);
void RemoveDetail(mixed *keys);
void AddSpecialDetail(mixed keys, string function);
void RemoveSpecialDetail(mixed keys);
void AddReadDetail(mixed keys, string descr);
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
varargs string name(int casus, int demon, int plural);

// capitalize(name())
varargs string Name(int casus, int demon, int plural);

// check whether object is plural (or unit with amount != 1)
int IsPlural();

// send a message to an object (or -e.g. for rooms- to its inventory)
varargs int Message(string msg, int flag, mixed extra);

#endif // __THING_DESCRIPTION_H_PROTO__

#endif	// NEED_PROTOYPES

