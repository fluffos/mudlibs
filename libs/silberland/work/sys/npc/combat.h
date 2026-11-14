// SilberLand MUDlib
//
// sys/npc/combat.h -- NPC spell handler
//
// $Date: 2004/09/19 23:04:10 $
/* $Revision: 1.6 $
 * $Log: combat.h,v $
 * Revision 1.6  2004/09/19 23:04:10  Feyaria
 * DS_DRAIN_MANA
 *
 * Revision 1.5  2001/03/28 16:17:21  Feyaria
 * DS_ANTIMAGIC
 *
 * Revision 1.4  2001/03/28 11:58:34  Feyaria
 * Defines fuer neue default-spells
 *
 * Revision 1.3  1999/10/09 11:07:23  Zordan
 * Default Spell PARALYZE
 *
 * Revision 1.2  1997/07/01 20:27:26  Feyaria
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
#define DS_PARALYZE      "default_spell_paralyze"
#define DS_DISARM        "default_spell_disarm"
#define DS_FEAR          "default_spell_fear"
#define DS_CURSE_WEAPON  "default_spell_curse_weapon"
#define DS_CURSE_ARMOUR  "default_spell_curse_armour"
#define DS_REDUCE_WC     "default_spell_reduce_wc"
#define DS_REDUCE_AC     "default_spell_reduce_ac"
#define DS_SLOW          "default_spell_slow"
#define DS_MASS_FEAR     "default_spell_mass_fear"
#define DS_MASS_DAMAGE   "default_spell_mass_damage"
#define DS_MASS_BLIND    "default_spell_mass_blind"
#define DS_MASS_DEAF     "default_spell_mass_deaf"
#define DS_MASS_POISON   "default_spell_mass_poison"
#define DS_ANTIMAGIC     "default_spell_antimagic"
#define DS_DRAIN_MANA    "default_spell_drain_mana"

#endif // __NPC_COMBAT_H__

#ifdef NEED_PROTOTYPES

#ifndef __NPC_COMBAT_H_PROTO__
#define __NPC_COMBAT_H_PROTO__

// prototypes
varargs void AddSpell(int rate, int damage, string TextForEnemy,
                                            string TextForOthers,
                                            mixed dam_type, mixed sp_info);

varargs void AddDefaultSpell(int rate, int damage, string type,
                             string msg1, string msg2, mixed special );



#endif // __NPC_COMBAT_H_PROTO__

#endif	// NEED_PROTOYPES
