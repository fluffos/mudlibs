// SilberLand MUDlib
//
// sys/living/combat.h -- combat header
//
// $Date: 2008/05/11 16:00:00 $
/* $Revision: 1.7 $
 * $Log: combat.h,v $
 *
 * Revision 1.7  2008/05/11 16:00:00  TamTam
 * P_LAST_DAMAGE
 *
 * Revision 1.6  1997/06/25 12:15:23  Woody
 * P_LAST_DAMTYPES, P_HANDS_USED_BY, P_FREE_HANDS
 *
 * Revision 1.5  1997/03/31 14:16:52  Woody
 * prepared for revision control
 *
 * Revision 1.4  1997/02/01  13:00:00  Woody
 * P_RESISTANCE_STRENGTHS, P_PREFERED_ENEMY, neue Prototypen...
 *
 * Revision 1.3  1995/02/28  17:49:27  Jof
 * QueryPlAttcked oder so ..
 *
 * Revision 1.2  1995/01/24  16:18:44  Kirk
 * P_ATTACK_BUSY added
 *
 * Revision 1.1  1994/01/18  01:06:38  mud
 * Initial revision
 *
 */

#ifndef __LIVING_COMBAT_H__
#define __LIVING_COMBAT_H__

// properties

#define P_RESISTANCE_STRENGTHS 	"resistance_strengths"
#define P_RESISTANCE 		"resistance"
#define P_VULNERABILITY 	"vulnerability"
#define P_TOTAL_AC 		"total_ac"

#define P_HANDS 		"hands"
#define P_MAX_HANDS 		"max_hands"
#define P_USED_HANDS 		"used_hands"
#define P_FREE_HANDS            "free_hands"
#define P_HANDS_USED_BY         "hands_used_by"

#define P_ATTACK_BUSY		"attack_busy"

#define P_PREFERED_ENEMY        "pref_enemy"

#define P_LAST_DAMTYPES         "last_damtypes"
#define P_LAST_DAMAGE           "last_damage"

#define ENEMY_HUNTTIME          0

#endif // __LIVING_COMBAT_H__

#ifdef NEED_PROTOTYPES

#ifndef __LIVING_COMBAT_H_PROTO__
#define __LIVING_COMBAT_H_PROTO__

// prototypes

int Kill(object ob);
int InsertEnemy(object ob);
int IsEnemy(object wer);
mixed EnemyPresent();

varargs int StopHuntFor(object arg, int silent);
varargs int StopHuntID(string str, int silent);
varargs mixed StopHuntingMode(int silent);
int QueryPlAttacked(object pl);

void Attack(object enemy);
int Defend(int dam, mixed dam_type, mixed spell, object enemy);
varargs void Flee(object oldenv);

float CheckResistance(string* dam_type);

mixed InFight();

object *PresentEnemies();
varargs object SelectEnemy(object *here);
object QueryEnemy();
mixed QueryEnemies();
mapping GetEnemies();
mapping SetEnemies(<object*|int*>* *myenemies);

#endif // __LIVING_COMBAT_H_PROTO__

#endif	// NEED_PROTOYPES
