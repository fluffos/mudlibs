// Written by Softbyte, 29mar97
// * Checks magic resistsance
// * Checks whether a player can cast a spell


#include <magic.h>
#include <properties.h>
#include <secure/wizlevels.h>
#include <config.h>

#define TP this_player()
#define TO this_object()
#define PO previous_object()
// ------------------------------------------------------------------- //
// Example: We want to cast a FIRE spell with 50 spellpoints cost doing
//          75 HP fire damage on a selected monster present in the room
//
//   int cmd_cast(string arg)
//   {
//   string s;
//   object enemy;
//     if (!arg) return (int)notify_fail("Cast on whom?\n");
//     enemy=present(arg,environment(this_player()));
//     if (enemy && enemy->QueryInvis()) enemy=0;
//     if (!enemy) return (int)notify_fail("This one is not here.\n");
//     if (s=CannotCast(ST_FIRE,this_player(),50)) 
//        return (int)notify_fail(s);
//     this_player()->ReduceSP(50);   // Check already done above
//     if (IsResistant(ST_FIRE,enemy))
//     {
//       write("The enemy is resistant.\n");
//       return 1;
//     }
//     enemy->Defend(75,DT_FIRE,0);   // hit enemy with 75 HP fire damage
//     return 1;
//   }
// ------------------------------------------------------------------- //
// Checks whether an enemy is resistant against a certain spelltype
// or damagetype (e.g. ST_FIRE) enemy is the one on whom the spell acts 
// All arguments are optional. Defaults are: IsResistant(0,0,TP)
// Returns: 1: Enemy is resistant, 0: enemy is not resistant
varargs int IsResistant(mixed sptype,object enemy)
{
int mdefence,mresistance;
int protection;
int chance;

  if (!enemy) enemy=TP;
  if (!enemy) return 0;

  // Get the general resistance against magic
  mdefence = enemy->QueryAttr("MagicDefence");

  // Get any particular reistance against a type of magic or a spell
  mresistance=0;
  if (sptype) mresistance+=enemy->Resistance(sptype);

  protection=mdefence+mresistance;

  if (protection > 100 && ( mdefence>100 || mresistance>100) )
  {
    return 1;    // enemy is protected (>100%)
  }

  chance=random(101);

  if ( chance > protection )
  {
    return 0;    // enemy is not protected
  }

  return 1;      // enemy is protected
}
// ------------------------------------------------------------------- //
// Checks whether caster (default this_player()) is allowed to cast
// a spell. sptype is the type of the spell (e.g. ST_FIRE)
// if spellpoints are given they are checked as well, i.e. it is
// checked whether caster has more or equal spellpoints left
// All arguemnts are optinal: defaul is CannotCast(ST_ALL,TP,0);
// Result: 0: Cast can be performed, (string) Cast cannot be performed
//         due to (string)
varargs string CannotCast(mixed sptype,object caster,int spellpoints)
{
mixed res;
int sp;
  if (!caster) caster=TP;
  if (!caster)
    return "Who should do that?\n";

  if (!sptype) sptype=ST_ALL;

  if (caster->QueryGhost())
    return "You can't do that in your current state.\n";

  if (caster->QueryCombatDelay()>0)
    return ("You can't do that: "+(caster->QueryCombatDelayMsg()||"You are unconcious.\n"));
 
 if (res = environment(caster)->QueryIsMagicForbidden(sptype))
    return res;

  sp=caster->QuerySP();
  if (spellpoints>sp)
    return "You don't have enough spellpoints left.\n";

  return 0;
}
// ------------------------------------------------------------------- //
