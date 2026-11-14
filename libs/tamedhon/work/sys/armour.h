// SilberLand MUDlib
//
// sys/armour.h -- armour header
//
// 2024/04/09 - includes als absolutpfad, damit auch das masterobjekt laden kann - Aloy
//
// $Date: 1997/10/08 13:48:39 $
/* $Revision: 1.10 $
 * $Log: armour.h,v $
 * Revision 1.10  1997/10/08 13:48:39  Woody
 * T_COLD_PROT, T_HEAT_PROT
 *
 * Revision 1.9  1997/08/25 12:01:58  Feyaria
 * P_DAM_PROTECTION eingefuehrt
 *
 * Revision 1.8  1997/04/19 20:55:46  Feyaria
 * P_WEAR_RESTRICTIONS
 *
 * Revision 1.7  1997/03/31 16:10:02  Woody
 * syntaktisch falsche Prototypen raus, QueryDefend() dafuer richtig rein
 *
 * Revision 1.6  1997/03/31 12:34:22  Woody
 * prepared for revision control
 *
 * Revision 1.5  1996/10/27  Woody
 * P_DEFEND_FUNC, P_WEAR_FUNC, P_REMOVE_FUNC
 *
 * Revision 1.4  1996/09/21  12:30:00  Woody
 * P_WORN_TEXT, P_(UN)WEAR_TEXT eingefuehrt
 *
 * Revision 1.3  1996/02/19  20:20:00  Mupfel
 * P_TOTAL_TEMPERATURE_PROTECTION nach /sys/living/life.h verlegt
 *
 * Revision 1.2  1996/02/19  19:35:00  Mupfel
 * P_TEMPERATURE_PROTECTION, P_TOTAL_TEMPERATURE_PROTECTION
 * von /sys/environment.h verlegt
 *
 * Revision 1.1  1994/11/30  01:03:30  Jof
 * Initial revision
 *
 */
 
#ifndef __ARMOUR_H__
#define __ARMOUR_H__

#include "/sys/thing.h"

// properties
#define P_AC          "ac"      // armour class
#define P_WORN        "worn"    // contains the object that wears this armour
#define P_ARMOUR_TYPE "armour_type"
#define P_WORN_TEXT   "worn_text"
#define P_WEAR_TEXT   "wear_text"
#define P_UNWEAR_TEXT "unwear_text"
#define P_DEFEND_FUNC "defend_func"
#define P_WEAR_FUNC   "wear_func"
#define P_REMOVE_FUNC "remove_func"
#define P_DAM_PROTECTION    "dam_prot"
#define P_WEAR_RESTRICTIONS "wear_restrictions"

// von /sys/environment.h verlegt
#define P_TEMPERATURE_PROTECTION  "temperature_protection"
#define T_COLD_PROT   0
#define T_HEAT_PROT   1

#endif // __ARMOUR_H__

#ifdef NEED_PROTOTYPES

#ifndef __ARMOUR_H_PROTO__
#define __ARMOUR_H_PROTO__

// prototypes

// function that will be called if one issues a wear command
// or to manually wear this armour
varargs int do_wear(string str, int silent);

// function that will be called if one issues an unwear command
// or to manually unwear the armour
varargs int do_unwear(string str, int silent);

// function is the rest of do_wear() -- msgs etc, needs no id
varargs int DoWear(int silent, int all);

// function is the rest of do_unwear() -- msgs etc, needs no id
varargs int DoUnwear(int silent);

// function that returns the protection value of the armour
int QueryDefend (string* dam_type, mixed spell, object enemy);

// TO BE REMOVED

void SetDefendFunc(object ob);
object QueryDefendFunc();

void SetWearFunc(object ob);
object QueryWearFunc();

void SetRemoveFunc(object ob);
object QueryRemoveFunc();

object QueryWorn();  // do not use  -- use QueryProp(P_WORN) instead

#endif  // __ARMOUR_H_PROTO__

#endif  // NEED_PROTOYPES

