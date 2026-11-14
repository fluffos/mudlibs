// SilberLand MUDlib
//
// sys/living/attributes.h -- living attributes
//
// $Date: 2004/10/15 17:26:44 $
/* $Revision: 1.12 $
 * $Log: attributes.h,v $
 * Revision 1.12  2004/10/15 17:26:44  Feyaria
 * P_X_MAX_HEALTH_MOD, P_M_MAX_HEALTH_MOD
 *
 * Revision 1.11  2001/08/03 10:45:30  Feyaria
 *  MAX_HEALTH 400
 *
 * Revision 1.10  1999/09/16 09:59:23  Woody
 * Defines fuer Attributmodifierlimits, P_M_ATTR_MOD, P_[XM]_HEALTH_MOD
 *
 * Revision 1.9  1997/11/05 16:35:02  Woody
 * A_MAX wieder auf 28
 *
 * Revision 1.8  1997/10/23 15:28:34  Woody
 * A_MAX auf 30 angehoben
 *
 * Revision 1.7  1997/06/25 12:15:03  Woody
 * A_SUM von 80 auf 100, A_MAX von 25 auf 27
 *
 * Revision 1.6  1997/03/31 14:15:54  Woody
 * prepared for revision control
 *
 * Revision 1.5  1997/02/10  Woody
 * P_X_ATTR_MOD, UpdateAttributes() prototype
 *
 * Revision 1.4  1996/10/01  Woody
 * Neue Konstanten/Props fuers neue Attributsystem (P_AP, A_MIN, A_MAX, A_SUM)
 *
 * Revision 1.3  1995/02/23  18:53:47  Rochus
 * P_ATTRIBUTES_MODIFIER eingebaut.
 * (Fuer gespeicherte Attribut-Modifikation, die nur
 * ein Objekt rueckgaengig machen kann)
 *
 * Revision 1.2  1994/09/13  10:47:15  Rochus
 * Offsets aufgenommen.
 *
 * Revision 1.1  1994/01/06  10:56:47  mud
 * Initial revision
 *
 */
 
#ifndef __LIVING_ATTRIBUTES_H__
#define __LIVING_ATTRIBUTES_H__

// properties

#define P_AP "ap"
#define P_ATTRIBUTES "attributes"
#define P_ATTRIBUTES_OFFSETS "attributes_offsets"
#define P_ATTRIBUTES_MODIFIER "attributes_modifier"
#define P_X_ATTR_MOD "extern_attributes_modifier"
#define P_X_HEALTH_MOD "extern_health_modifier"
#define P_M_ATTR_MOD "magic_attributes_modifier"
#define P_M_HEALTH_MOD "magic_health_modifier"
#define P_X_ATTR_LOCK "extern_attributes_lock"
#define P_X_MAX_HEALTH_MOD "extern_max_health_modifier"
#define P_M_MAX_HEALTH_MOD "magic_max_health_modifier"
#define P_ABILITIES "abilities"

// special defines

/* standard attributes */
#define A_STR "str"
#define A_INT "int"
#define A_DEX "dex"
#define A_CON "con"

#define ATTRIBUTE_STRING ([ A_STR: "Kraft",            A_INT: "Intelligenz", \
                            A_DEX: "Geschicklichkeit", A_CON: "Ausdauer" ])

/* maximum and minimum for an attribute */
#define A_MIN            1      // minimum real value
#define A_MAX           28      // maximum real value
#define A_SUM          100      // maximum total sum
#define A_MAX_MODIFIED  40      // maximum modified value (hard limit)
#define A_MAX_MODIFIERS  2      // maximum modifiers per attribute
#define A_MAX_TOTAL_MOD 10      // maximum total positive modifier value

#define MAX_HEALTH 400  // Maximum for P_MAX_HP and P_MAX_SP for players

#endif // __LIVING_ATTRIBUTES_H__

#ifdef NEED_PROTOTYPES

#ifndef __LIVING_ATTRIBUTES_H_PROTO__
#define __LIVING_ATTRIBUTES_H_PROTO__

// prototypes

int SetAttr(string attr, int val);

int SetAttribute(string attr, int val);
int SetRealAttribute(string attr, int val);
int QueryAttribute(string attr);
int QueryRealAttribute(string attr);
int QueryAttributeOffset(string attr);

int SetAbility(string abil, int val);
int QueryAbility(string abil);

void UpdateAttributes();
string TestAttributeLock(mapping check);

#endif // __LIVING_ATTRIBUTES_H_PROTO__

#endif // NEED_PROTOYPES
