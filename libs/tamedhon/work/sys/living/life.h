// Tamedhon MUDlib
//
// sys/living/life.h -- living life header
//
// $Date: 2003/07/05 11:11:00 $
/* $Revision: 1.13 $
 * $Log: life.h,v $
 * Revision 1.13  2003/07/05 11:11:00  Querolin
 * P_HP_STORE, P_HP_STORE_PERCENT sowie SP... eingefuehrt
 *
 * Revision 1.12  1998/01/24 19:57:59  Feyaria
 * P_PARALYZED und PARALYZE_.... eingefuehrt
 *
 * Revision 1.11  1997/10/08 13:50:46  Woody
 * Temperatur-Properties umdefiniert
 *
 * Revision 1.10  1997/10/07 09:24:59  Woody
 * neue Prototypen fuer drink_alcohol(), drink_drink() usw.
 *
 * Revision 1.9  1997/09/17 14:47:01  Woody
 * P_FOOD/DRINK/ALCOHOL/HP/SP/POISON_DELAY Properties definiert
 *
 * Revision 1.8  1997/06/25 12:15:40  Woody
 * do_exhaust()
 *
 * Revision 1.7  1997/04/17 16:12:02  Feyaria
 * AddPoison
 *
 * Revision 1.6  1997/03/31 14:24:58  Woody
 * prepared for revision control
 *
 * Revision 1.5  1997/02/02  Woody
 * P_ALIGN_STRING
 *
 * Revision 1.4  1996/10/05  Woody
 * die() declaration korrigiert
 *
 * Revision 1.3  1996/02/19  20:20:00  Mupfel
 * P_TEMPERATURE_RANGE, P_TEMPERATURE_OFFSET aus environment.h, 
 * P_TOTAL_TEMPERATURE_PROTECTION aus armour.h verlegt
 *
 * Revision 1.2  1994/11/30  01:02:11  Kirk
 * num_deads -> deads
 *
 * Revision 1.1  1994/01/06  10:56:47  mud
 * Initial revision
 *
 */
 
#ifndef __LIVING_LIFE_H__
#define __LIVING_LIFE_H__

// properties

#define P_AGE           "age"
#define P_ALIGN         "align"
#define P_ALIGN_STRING  "align_string"

#define P_DEADS         "deads"
#define P_GHOST         "ghost"
#define P_FROG          "frog"

#define P_FOOD          "food"
#define P_MAX_FOOD      "max_food"
#define P_DRINK         "drink"
#define P_MAX_DRINK     "max_drink"
#define P_ALCOHOL       "alcohol"
#define P_MAX_ALCOHOL   "max_alcohol"

#define P_HP            "hp"
#define P_MAX_HP        "max_hp"
#define P_SP            "sp"
#define P_MAX_SP        "max_sp"
#define P_HP_STORE      "hp_store"
#define P_HP_STORE_PERCENT    "hp_store_percent"
#define P_SP_STORE      "sp_store"
#define P_SP_STORE_PERCENT    "sp_store_percent"
#define P_XP            "xp"

#define P_FOOD_DELAY    "food_delay"
#define P_DRINK_DELAY   "drink_delay"
#define P_ALCOHOL_DELAY "alcohol_delay"
#define P_HP_DELAY      "hp_delay"
#define P_SP_DELAY      "sp_delay"
#define P_POISON_DELAY  "poison_delay"

// temperature system

#define P_TEMPERATURE_RANGE             "temperature_range"
#define P_TEMPERATURE_OFFSET            "temperature_offset"
#define P_TOTAL_TEMPERATURE_PROTECTION  "total_temp_prot"

// temperature range defines

#define T_RANGE_MIN     0
#define T_RANGE_MAX     1

#define P_PARALYZED         "paralyzed"
#define PARALYZE_TIME       "paralyze_time"
#define PARALYZE_MSG        "paralyze_msg"
#define PARALYZE_MSG_OTHER  "paralyze_msg_other"
#define PARALYZE_END        "paralyze_end"
#define PARALYZE_END_OTHER  "paralyze_end_other"

#endif // __LIVING_LIFE_H__

#ifdef NEED_PROTOTYPES

#ifndef __LIVING_LIFE_H_PROTO__
#define __LIVING_LIFE_H_PROTO__         

// prototypes

int AddExp(int e);
int AddPoison(int strength);

void show_age();

varargs int drink_alcohol(int strength, int silent);
varargs int drink_soft(int strength, int silent);
varargs int drink_drink(int soak, int alc, int silent);
varargs int eat_food(int strength, int silent);
varargs int do_exhaust(int exhaust, int silent);

int do_damage(int dam, mixed enemy);
int reduce_hit_point(int dam);
void restore_spell_points(int h);
varargs void die(int poisondeath);

void heal_self(int h);

#endif // __LIVING_LIFE_H_PROTO__

#endif // NEED_PROTOYPES
