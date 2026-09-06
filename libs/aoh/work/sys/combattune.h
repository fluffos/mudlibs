#ifndef _COMBAT_TUNE_
#define _COMBAT_TUNE_ 1

#include "combat.h"

// --- Stunning? ---
// Stunning sounds like a neat idea, but at the moment happens too often.
// It should (in average) happen just once per fight.
// To (re)activate it, define this symbol:

#undef CT_USE_STUN

// === Combat formulas for livings ===

// Most formulas are in fact short sequences of statements which
// are inserted inmidst of the combat functions. In most places
// the formulaes may define local variables without extra { }.
// If not defined, default formulas are used.

// --- Hitzones ---
// Ordered according to the target zone armour types, each target
// zone is described by two integers: first the hit propability
// (measured against the sum of all propabilities), second the
// damage reduction factor (0..10, 10 being full damage).
// Expected median factor is 7.59

#define CT_HITZONES ({ \
  1,  4, \
  3,  6, \
 14,  9, \
  1,  4, \
  1, 10, \
  4,  8, \
  3,  6, \
})


// --- Dodge ability ---
// This sequence of statements has to compute and assign to 'rc' the
// value by which the attack success is to be reduced. Values below
// zero will be mapped onto 0.
// Available variables:
//   global int damageMalus: (0..50)
//     The nominal penalty for skills due to last round damage.
//   local  mixed weapon : the weapon to dodge.
//   local  int   success: attack success so far.
// Local variables may be defined.

#define CT_DODGE \
  rc = UseSkill(CS_DODGE, damageMalus+QueryLoad()/2); \
  damageMalus = 0;


// --- Load penalty ---
// Compute the penalty the load of a living has on its attack
// success, and reduce the 'success' value.
// Available variables:
//   local int success: the attack success so far, to be modified.
//   local int rc     : freely available.
// Local variables may be defined.

#define CT_LOAD_PENALTY \
  // Load = 40%..200%: success reduces down to 1/20        \
  rc = QueryLoad() - LOAD_THRESH/2;                        \
  if (rc > 0)                                              \
    success -= (success * 9 * rc) / (1000 - 5*LOAD_THRESH);


// --- Self-hit damage ---
// If a hit misses, the living may damage itself (and has to in
// case of hand combat!). The self-damage done (multiplied by 10
// to compensate for a later division) has to be added to 'degradeHand'.
// CT_SELF_HAND is for hand combat, CT_SELF_WEAPON for 'real weapon' combat.
// Available variables:
//   local mixed weapon    : the weapon this attack used.
//   local int   success   : (0..-100) the failure 'success'.
//   global int degradeHand: the self-damage the living collected
//     by its actions, in 1/10 HP, to be modified.
// Local variables may be defined.

#define CT_SELF_HAND \
  degradeHand += (-success)/4;

#define CT_SELF_WEAPON \
  degradeHand += (-success)/2;


// --- Damage/Success evaluation ---
// After determining the target zone, the damage mapping of the attack
// is walked through and each damage is modified according to the
// attacks success. The formula is placed in the body of loop walking
// through the mapping.
// Note that no damage should fall below 1.
//
// Available variables:
//   local mixed   weapon : the attacking weapon.
//   local mapping damage : the damage mapping, to be modified.
//   local int     success: the attack success.
//   local int     factor : damage reduction factor according to hitzone.
//   local int     dt     : damage type of this iteration.
//   local int     j      : free available.
// Local variables may not be defined.

#define CT_DAMAGE_EVAL \
  if (!(damage[dt] = (damage[dt] * (success+25)) / 100)) \
    damage[dt] = 1;


// --- Final damage evaluation ---
// As last step, the damage mapping of the attack, already reduces
// by the armour defenses,  is walked through and the total damage
// is collected in 'damhp'. The formula is placed in the body of
// loop walking through the mapping.
//
// Available variables:
//   local mixed weapon : the attacking weapon.
//   local int   success: the attack success.
//   local int   factor : damage reduction factor according to hitzone.
//   local int   damhp  : total damage, to be modified.
//   local int   dt     : damage type of this iteration.
//   local int   i      : damage amount of this iteration.
//   local int   j      : free available.
// Local variables may not be defined.

#define CT_FINAL_DAMAGE \
  if (dt >= 0)             \
    j = (j * factor) / 10; \
  if (j > 0)               \
    damhp += j;


// --- Damage malus computation ---
// Depending on the amount of damage a living received in one round,
// it gets a malus on its (combat) skills the next round.
// The value stored in damageMalus should not exceed (0..50).
// Available variables:
//   global int   damageMalus: to be modified/set.
//   local  int   damhp      : the received damage.
//   local  mixed weapon     : the attacking weapon.
//   local  int   success    : the attack success.
//   local  int   damage     : the damage mapping damhp was computed from.
//   local  int   target     : hitzone.
//   local  int   i, j       : freely available.
// Local variables may not be defined.

#define CT_DAMAGE_MALUS \
  damageMalus = (damhp * 100) / QueryMaxHP(); \
  if (damageMalus > 50)                       \
    damageMalus = 50;


// --- Stunning threshhold ---
// Determine the difficulty for an ApplyStat(A_CON,) to become unconscious
// because of a severe hit. The larger <diff> is set, the less likely
// unconsciousness becomes. Set <diff> to 101 to make unconsciousness
// impossible.
// Available variables:
//   local int diff  : the difficulty to set.
//   local int reldam: the relative damage done (0..100).
//   local int amount: the absolute damage done.
//   local int hp    : the remaining HP.
// Local variables may not be defined.

#define CT_STUN_DIFF \
  diff = 80-(reldam/2);

// Define this to activate the old unconsciousness trigger.
// The old and the new method may work in parallel.

/* #define CT_OLD_STUN */

// --- Default Kill-XP computation ---
// Compute the amount of XP someone gets for killing a living.
// xp is the experience of the victim (divided by the number of victors)
// and has to be modified to the amount of XP to actually give away.
// No local variables may be defined.
// MAX_XP_ADD and XP_GAIN are defined in combat.h

#define CT_KILL_XP \
  xp = XP_GAIN(xp);                           \
  if (xp > MAX_XP_ADD/2)                      \
    xp = MAX_XP_ADD/2 + (xp-MAX_XP_ADD/2)/10; \
  if (xp > MAX_XP_ADD)                        \
    xp = MAX_XP_ADD + (xp-MAX_XP_ADD)/100;

#endif
