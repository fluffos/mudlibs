/**
 * This includes some of combat specific defines and classes.
 * @author Sandoz
 */

/** @ignore yes */
#define MELEE   "fighting.combat.melee."

/** This is the cost of the mid-level special attack commands. */
#define MEDIUM_SPECIAL_COST        50

/** This is the level at which the mid-level special attacks can be learnt. */
#define MEDIUM_SPECIAL_LEARN_LEVEL 50

#define LEARNABLE_MELEE_CMDS ({"chop", "hack", "pierce", "slash", "slice", \
                               "smash", "stab"})

#ifdef __ATTACK_DATA_CLASS__
#ifndef __MESSAGE_DATA_CLASS__
#define __MESSAGE_DATA_CLASS__
#endif
#endif

#ifdef __MESSAGE_DATA_CLASS__
class message_data {
    string attacker;
    string defender;
    string others;
}
#endif

/** This marks the stage of selecting an attack for the round. */
#define PREPARE_ATTACK  1
/** This marks the stage of modifying the attack for the round. */
#define MODIFY_ATTACK   2
/** This marks the stage of modifying the damage of the attack. */
#define MODIFY_DAMAGE   4
/** This marks the stage of modifying the attack messages. */
#define MODIFY_MESSAGES 8
/** This marks the stage when the attack has successfully hit. */
#define FINISH_ATTACK   16

#ifdef __ATTACK_DATA_CLASS__
class attack_data {
    object attacker;
    object target;
    object weapon;
    int damage;
    string skill;
    string type;
    string name;
    string focus;
    int difficulty;
    int final_damage;
    int attack_bonus;
    int success;
    string area;
    class message_data messages;
    int unprotectable;
    mixed data;
    int flags;
}
#endif

#ifdef __SPECIAL_ATTACK_DATA__

/** The flag for tactical special attacks. */
#define SP_TACTICAL 1
/** The flag for special melee attacks. */
#define SP_MELEE    2
/** The flag for specials executed when dodging. */
#define SP_DODGE    3
/** The flag for specials executed when parrying. */
#define SP_PARRY    4

/**
 * This class stores some data about a special attack.
 * @member type the type of the special attack
 * @member flags the stage flags of the special attack
 * @member ob the special attack callback object
 * @member fun the special attack callback function
 * @member data specific data used by the special attack
 * @member time the time after which this special attack should expire
 */
class special_attack_data {
    int type;
    int flags;
    string ob;
    string fun;
    mixed data;
    int time;
}
#endif
