/*
 * /sys/formulas.h
 *
 * This file holds all system game formulas, like that of combat.
 */

#ifndef WA_TYPES_DEF
#include "/sys/wa_types.h"
#endif

#ifndef SS_TYPES_DEF
#include "/sys/ss_types.h"
#endif

#ifndef PROP_DEF
#include "/sys/stdproperties.h"
#endif

#ifndef F_FORMULAS
#include "/config/sys/formulas2.h"
#endif

#ifndef MACROS_DEF
#include "/sys/macros.h"
#endif

#ifndef F_FORMULAS
#define F_FORMULAS

/*
 * Stats
 *
 * F_EXP_TO_STAT - conversion from (acc) experience points to the stat.
 * F_STAT_TO_EXP - conversion from a stat to experience points.
 *
 * 0.27777777 ~= 1.0/3.6; the one point extra in F_STAT_TO_EXP is to account
 * for rounding errors.
 */
 
#define F_EXP_TO_STAT(xp)   (ftoi(pow((10.0 * itof(xp)), 0.27777777)))
#define F_STAT_TO_EXP(stat) (ftoi(pow(itof(stat), 3.6) / 10.0) + 1)

/*
 * Armour
 *
 * Note that these are only valid for humanoid armours.
 */
#define ARMOUR_FILE 				"/std/armour"
#define F_VALUE_ARMOUR(ac) 			(this_object()->query_default_value())
#define F_ARMOUR_DEFAULT_AT 			A_TORSO
#define F_ARMOUR_DEFAULT_SHIELD_SIZE		3000 /* Ok. 60 cm srednicy */
#define F_LEGAL_AM(list) 			(sizeof(list) == 3)
#define F_ARMOUR_CLASS_PROC(proc_of_max) 	(proc_of_max)
/* Stara wersja, aczkolwiek wartosci bez zmian
#undef F_LEGAL_ARMOUR_REPAIR(rep, cond)		((rep) <= (cond)  && \
							(rep) < (cond) / 2 + 3)
*/
#define F_ARMOUR_MAX_REPAIR(cond)		(MIN(((cond) / 2 + 2), (cond)))
#define F_LEGAL_ARMOUR_REPAIR(rep, cond)	((rep) <= (cond)  && \
						 (rep) <= F_ARMOUR_MAX_REPAIR(cond))
#define F_ARMOUR_VALUE_REDUCE(m_cond)		(100 - (m_cond) * 5)
#define F_ARMOUR_BREAK(m_cond, likely)		((m_cond)>(20 - (likely) / 2 ) \
		|| (m_cond) > random(40 - (likely)))

#define F_ARMOUR_CONDITION_WORSE(hits, ac, lik)	((hits) > random(1000) + \
		4 * (40 - (lik)))

#define F_AT_WEIGHT_FACTOR(type) \
   ((type == A_SHIELD) ? 20 : ((type & A_BODY) ? 40 : 0) + \
    ((type & A_LEGS) ? 30 : 0) + \
    ((type & A_HEAD) ? 10 : 0) + \
    ((type & A_R_ARM) ? 10 : 0) + \
    ((type & A_L_ARM) ? 10 : 0) + \
    ((type & A_FEET) ? 10 : 0) + \
    ((type & A_ROBE) ? 20 : 0))

#define F_WEIGHT_DEFAULT_ARMOUR(ac, at) \
    (this_object()->query_default_weight())

// Alvin: Propozycja zmiany - dla ac > 14: ac *1100 - 9000.

#define F_WEIGHT_FAULT_ARMOUR(w, std_weight)\
    ((std_weight) * 7 / 10 > (w))

/* 
 * Weapon       (Observe that F_VALUE_WEAPON takes two args)
 *
 * Note also that these are only valid for humanoid weapons.
 */
#define WEAPON_FILE 				"/std/weapon"
#define F_VALUE_WEAPON(wch, wcp) 		(20 + (wch * wcp))
#define F_WEAPON_DEFAULT_WT 			W_FIRST
#define F_WEAPON_DEFAULT_DT 			W_IMPALE
#define F_WEAPON_DEFAULT_HANDS			W_ANYH
#define F_WEAPON_CLASS_PROC(proc_of_max)        (proc_of_max)
#define F_WEAPON_VALUE_REDUCE(du, co)		(100 - (du)* 3 - (co)* 6)
#define F_WEAPON_MAX_REPAIR_DULL(dull)		(MIN((2 * (dull) / 3 + 2), (dull)))
#define F_WEAPON_MAX_REPAIR_CORR(corr)		(MIN(((corr) / 2), (corr)))
/* Stare wersje, aczkolwiek wartosci bez zmian
#undef F_LEGAL_WEAPON_REPAIR_DULL(rep, dull)	((rep) <= (dull) && \
							(rep)< 2*(dull)/ 3 + 3)
#undef F_LEGAL_WEAPON_REPAIR_CORR(rep, corr)	((rep) <= (corr) && \
							(rep) < (corr) / 2 + 1)
*/
#define F_LEGAL_WEAPON_REPAIR_DULL(rep, dull)	((rep) <= (dull) && \
						 (rep) <= F_WEAPON_MAX_REPAIR_DULL(dull))
#define F_LEGAL_WEAPON_REPAIR_CORR(rep, corr)	((rep) <= (corr) && \
						 (rep) <= F_WEAPON_MAX_REPAIR_CORR(corr))
#define F_WEAPON_BREAK(dull, corr, likely)	((dull) > (20 - (likely)) || \
		(corr) > (5 -(likely)/ 4) || (dull) > random(40 -(likely)) || \
		(corr) > random(10 - (likely) / 4))

#define F_WEAPON_CONDITION_DULL(hits, pen, lik)	((hits) > random(1000) + \
		10 * (30 - (lik)))

#define F_WEIGHT_FAULT_WEAPON(w, wp, wt) \
		((w) < 800 * F_WEIGHT_DEFAULT_WEAPON(wp, wt) / 1000)

#define F_WEIGHT_DEFAULT_WEAPON(wp, wt)		((wp) < 14 ? 400 :	\
						 ((wp) * 10 * ((wp) - 11)))

#define F_LEGAL_DT(type) ((type) &        \
			  (W_IMPALE |   \
			   W_SLASH |    \
			   W_BLUDGEON))

#define F_LEGAL_HANDS(which) ((which) == W_ANYH ||  \
			      (which) == W_LEFT ||  \
			      (which) == W_RIGHT || \
			      (which) == W_BOTH)

#define F_LEGAL_WCHIT(wc, type)	      (F_LEGAL_TYPE(type)       && \
				       ((wc) <= W_MAX_HIT[type]))
#define F_LEGAL_WCPEN(wc, type)	      (F_LEGAL_TYPE(type)       && \
				       ((wc) <= W_MAX_PEN[type]))


/* 
 * Living
 */
#define F_KILL_NEUTRAL_ALIGNMENT        (10)
#define F_MAX_ABS_ALIGNMENT		(1200)
#define F_KILL_ADJUST_ALIGN(killer_al,victim_al)                             \
                                 ((killer_al) * (victim_al) < 0              \
			             ? -(((victim_al) * 4000) /              \
			                ((killer_al) * (killer_al) + 20000)) \
			             : -((victim_al) / 5))
#define F_QUEST_ADJUST_ALIGN(my_align, quest_align) \
		(F_KILL_ADJUST_ALIGN((my_align), -(quest_align)))

#define F_DIE_REDUCE_XP(xp) 		((xp) / 3)

#define F_KILL_GIVE_EXP(av)	        (((av) * (av) * 400) / ((av) + 50))
#define F_DIE_START_HP(max_hp) 		((max_hp) / 10)
#define F_MAX_SCAR			(10)
#define F_SCAR_DESCS ({ 					       \
			  "left leg", "right leg", "nose", "left arm", \
			  "right arm", "left hand", "right hand",      \
			  "forehead", "left cheek", "right cheek"       \
		     })
/*
 * The following constants define how quickly a living heals.
 */
/* #define F_INTERVAL_BETWEEN_HEALING	10  */ /*(in heartbeats - Obsolete!)*/
#define F_INTERVAL_BETWEEN_HP_HEALING		20  /*(in sec)*/
#define F_INTERVAL_BETWEEN_MANA_HEALING		30  /*(in sec)*/
#define F_INTERVAL_BETWEEN_FATIGUE_HEALING	60  /*(in sec)*/
#define F_INTERVAL_BETWEEN_STUFFED_HEALING	20  /*(in sec)*/
#define F_INTERVAL_BETWEEN_SOAKED_HEALING	20  /*(in sec)*/
#define F_INTERVAL_BETWEEN_INTOX_HEALING	20  /*(in sec)*/
#define F_INTERVAL_BETWEEN_HEADACHE_HEALING	20  /*(in sec)*/
#define F_INTERVAL_BETWEEN_PANIC_HEALING	20  /*(in sec)*/

#define MAX_MANA_UPDATE				4

/* Amount to heal per interval for various stats */
#define F_HEADACHE_RATE                 1
#define F_SOBER_RATE                    1
#define F_MANA_HEAL_RATE                1
#define F_UNSTUFF_RATE                  1
#undef	F_UNSOAK_RATE                   16
#define F_UNSOAK_RATE			8
#define F_HEAL_FORMULA(con, intox) (((con) * 5 + (intox) + 100) / 20)
#define F_FATIGUE_FORMULA(stuffed, max) (15 + (stuffed) * 25 / (max))
#define F_NPC_FATIGUE_HEAL		35

/* Formula to heal mana with respect to spellcasting, int and intox */
#define F_MANA_HEAL_FORMULA(sc,pintox,intel) \
    (((sc) < 31) ? 2 : ((((((sc) - 30) * MAX_MANA_UPDATE * (intel)) / \
	1000 + 5) * (100 - (pintox)) / 1000) + 2))


/*
 * How long can a temporary stat addition be? (In heartbeats)
 */
#define F_TMP_STAT_MAX_TIME 30

#define F_TRACK_MANA_COST	4

/*
 * F_MAX_REMEMBERED(int, wis) returns the maximum number of players a
 * person can remember. It is based on both intelligence and wisdom.
 */
#define F_MAX_REMEMBERED(int, wis) ((((int) + (wis)) / 3) + 10)

/*
 * These macros convert from seconds to heart beats and back.
 * Obsolete! 
 * #define F_SECONDS_PER_BEAT 		2
 * #define F_NUM_BEATS(seconds) 	((seconds) / F_SECONDS_PER_BEAT)
 */

/* 
 * Death
 */
#define F_GHOST_MSGIN 	     "przydryfowuje."
#define F_GHOST_MSGOUT 	     "dryfuje"
#define F_NAME_OF_GHOST	     "some mist"

/*
 * Combat 
 */

#define F_MAX_HP(con)  (((con) < 10) ? ((con) * 10) : (((con) * 20) - 100))

/*
 * Najstarszy F_PENMOD (oryuginalny z Genesis).
 
#define F_PENMOD(pen, skill) ((((pen) > (skill) ? (skill) : (pen)) + 50) * \
	(((skill) > (pen) ? (pen) + ((skill) - (pen)) / 2 : (skill)) + 50) / \
	30 - 8
 * Pierwsza poprawka, dalej zly, ale nieco lepszy.

#define F_PENMOD(pen, skill) ((((pen) > (skill) ? (skill) : (pen)) + 50) *   \
        ((((skill) + 2 * (pen)) / 3) + 50) / 30 - 80)
*/

#define F_PENMOD(pen, skill)					\
	(10 + (13 + 18 * (pen) / 7) * ((pen) > (skill)		\
		? (skill) * 100 / (pen)				\
		: (100 + ((skill) - (pen)) * 110 / (100 - (pen)))) / 100)

/* Stary F_TOHITMOD.

#define F_TOHITMOD(pen, skill) ((((pen) > (skill) ? (skill) : (pen)) + 50) * \
	(((skill) > (pen) ? (pen) + ((skill) - (pen)) / 2 : (skill)) + 50) / \
	30 - 80)
*/

#define F_TOHITMOD(hit, skill)	((skill+15) * (skill+20) * \
				(8 * (hit) - 40) / 15000 + 50)


#define F_PARRYMOD(hit, skill) (((hit) + 15) * ((skill) + 5) / 50)

#define F_SHIELD_PARRYMOD(shield_parry, skill) ((shield_parry) * (skill) / 100)

#define F_AC_MOD(ac) (((ac) + 50) * ((ac) + 50) / 50 - 50)

#define F_DAMAGE(pen, dam) ((pen) - (dam))

#define F_STRENGTH_DAMAGE_MOD(mod) ((mod) / 3)

#define F_MAX_WEP_WEIGHT(str)	((str) * ((str) / 2 + 65) + 1000)

#define F_DARE_ATTACK(ob1, ob2) \
	((ob1)->query_prop(NPC_I_NO_FEAR) || \
	 ((ob2)->query_average_stat() <= ((ob1)->query_stat(SS_DIS) * 2)))

#define F_UNARMED_HIT(skill, dex)    ((skill) / 7 + (dex) / 20)
#define F_UNARMED_PEN(skill, str)    ((skill) / 10 + (str) / 20)

/*
 * Healing alco
 */
#define F_VALUE_ALCO(alco)		(10 + ((alco) * (alco) / 10))

/*
 * Magic 
 */
#define F_VALUE_MAGICOB_HEAL(hp)	(5 * (hp) + (hp) * (hp) / 4)
#define F_VALUE_MAGIC_COMP(hp)		((hp) * 20)

/*
 * Some general values
 *
 */
#define F_VALUE_FOOD(amount)		(5 + (amount) * (amount) / 600)

/*
 * wg in grams (weight it can support), l in centimeters (length of rope)
 */
#define F_VALUE_ROPE(wg, l)		(((wg) / 10000) * ((l) / 100))

/*
 * Some string defines that are only used indirectly.
 *
 * All these kinds of string constants are defined in a /sys/file_desc.h
 * Where 'file' is the original filename. The constants below are
 * referenced by default from those files for backwards compatibilty
 * reasons.
 */
#define F_ALIVE_MSGIN 			"przybywa."
#define F_ALIVE_MSGOUT 			"podaza"
#define F_ALIVE_TELEIN 			"pojawia sie w klebach dymu."
#define F_ALIVE_TELEOUT 		"znika w klebach dymu."

#endif
