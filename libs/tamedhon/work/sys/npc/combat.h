// SilberLand MUDlib
//
// sys/npc/combat.h -- NPC spell handler
//
// $Date: 1997/07/01 20:27:26 $
/* $Revision: 1.2 $
 * $Log: combat.h,v $
 * Revision 1.2  1997/07/01 20:27:26  Feyaria
 * [A[A[A
 * defaulspells
 *
 * Revision 1.1  1997/03/31 14:40:31  Woody
 * prepared for revision control
 *
 * Revision 1.0  1996/03/12  15:22:00  Mupfel
 * neu angelegt, Defines aus /sys/properties.h,
 * Prototypen aus /std/npc/combat.c
 *
 */
 
#ifndef __NPC_COMBAT_H__
#define __NPC_COMBAT_H__

// properties

#define P_AGGRESSIVE "aggressive"
#define P_NOATTACK "noattack"
#define P_SPELLS "spells"
#define P_SPELLRATE "spellrate"

// special properties (internal use)

#define P_NPC_SPELL_VECTOR "npc:rate_array"
#define P_NPC_HB_OFF_COUNT "npc:beat_off_num"

#define DS_POISON        "default_spell_poison"
#define DS_FROG          "default_spell_frog"
#define DS_BLIND         "default_spell_blind"
#define DS_DEAF          "default_spell_deaf"
#define DS_DISARM        "default_spell_disarm"
#define DS_FEAR          "default_spell_fear"
#define DS_CURSE_WEAPON  "default_spell_curse_weapon"
#define DS_CURSE_ARMOUR  "default_spell_curse_armour"
#define DS_REDUCE_WC     "default_spell_reduce_wc"
#define DS_REDUCE_AC     "default_spell_reduce_ac"

#endif // __NPC_COMBAT_H__

#ifdef NEED_PROTOTYPES

#ifndef __NPC_COMBAT_H_PROTO__
#define __NPC_COMBAT_H_PROTO__

// prototypes
varargs int AddSpell(int rate, int damage, string TextForEnemy,
                                            string TextForOthers,
                                            mixed dam_type, mixed sp_info);

varargs void AddDefaultSpell(int rate, int damage,string type);



#endif // __NPC_COMBAT_H_PROTO__

#endif	// NEED_PROTOYPES
