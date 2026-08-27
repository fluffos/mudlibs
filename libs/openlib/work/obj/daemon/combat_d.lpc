/*  -*- LPC -*-  */
// combatd.c:  This is the Combat Daemon.  It handles everything related to 
//             combat that doesn't need to be in the player's body.
//
// Copyright (C) 1995 Eric Peters (epeters@netcom.com)
//
// This program is part of the OpenLib Mudlib distribution; it
// is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published
// by the Free Software Foundation; either version 2 of the License,
// or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// If you acquired this program as part of the OpenLib Mudlib
// distribution, you should have received a copy of the GNU
// General Public License in the file /doc/GPL; if not,
// write to the Free Software Foundation, Inc., 675 Mass Ave,
// Cambridge, MA 02139, USA.
//
// Orig Daemon by Casper (epeters@netcom.com) 10/13/95.  Mail me for questions
// concerning this daemon and any functions written by me.
//
// 09.05.96  Tim (astasia@iastate.edu || rockford@novia.net)
//          o did a complete rewrite, mostly to change it so the
//            mappings were indexed by object instead of oid, also
//            implemented foreach() loops, message() and fixed a little
//            bit of code that was bad.
 
#include <mudlib.h>
#include <object_types.h>
#include <weapon.h>

// To be replaced later by a more generalized approach like a .h file --Tim
#define MSG_COMBAT "combat"

// 
// Vars:  (save a lot of ugly code by using mappings)
// 

// These keep the call_out() handles for the combat_crash() and
// continue_all_attacks() functions...
private int co_crash;
private int co_caattacks;

// keys are the attackers
// combatant[attacker_ob] is list of who he/she is fighting.  
// Contains objs, not names.
private mapping combatants,
                weapon_info,
                ac, num_attacks;
 
// Functions:  neccessary prototypes here.
varargs void execute_attack(object victim, object attacker, 
			    mixed *weapon_info, int hit_mod, int dmg_mod);
void execute_bow_attack(object victim, object attacker, mixed *weapon_info);

void
create()
{
  combatants = ([ ]);
  weapon_info = ([ ]);
  ac = ([ ]);
  num_attacks = ([ ]);
}
 
// Stops ALL combat in progress, and reinitalizes all global vars.

void
clear_all_combat_info()
{
  // set everybody to non-combat status.
  foreach(object combatter, object* combattees in combatants)
    combatter->set_combating(0);
 
  combatants = ([ ]);
  weapon_info = ([ ]);
  ac = ([ ]);
  num_attacks = ([ ]);
}
 
// Return damage string, 'Stolen' from Rift (mod. TMI-2 lib) by 
// Casper  9/95

string*
query_dmg_message(int damage)
{
  switch( damage ) 
  {
    case 0:
      return ({"doing no damage.",
	       "doing no damage."});
    case 1..10:
      return ({"leaving a light scratch.",
	       "leaving a light scratch."});
    case 11..20:
      return ({"doing light damage.",
	       "doing light damage."});
    case 21..25:
      return ({"delivering a soft blow.",
	       "delivering a soft blow."});
    case 26..35:
      return ({"delivering a solid blow.",
	       "delivering a solid blow."});
    case 36..45:
      return ({"hitting hard!",
	       "hitting hard!"});
    case 46..50:
      return ({"hitting VERY hard!",
	       "hitting VERY hard!"});
    case 51..60:
      return ({"smashing with a bone crunching sound!",
	       "smashing with a bone crunching sound!"});
    case 61..70:
      return ({"inflicting massive damage!",
	       "inflicting massive damage!"});
    case 71..80:
      return ({"massacring to little fragments!",
	       "massacring to little fragments!"});
    case 81..110:
      return ({"hitting with unbelievable force!",
	       "hitting with unbelievable force!"});
    case 111..130: //sp on splatterring?
      return ({"splatterring yourself with your opponent's blood!",
	       "splatterring everything with blood!"});
    case 131..150:
      return ({"spraying a thin red paste everywhere!",
	       "spraying a thin red paste everywhere!"});
    default:
      return ({"DESTROYING with your wicked blow!",
	       "DESTROYING with the wicked blow!"});
  }
}
 
// Remove people from all attack lists that are not present.  
// Orig by Casper
//
// Need to find out what happens when you index a mapping by objects and
// then destruct several of them to figure out how to filter them out
// properly and efficiently --Tim

int
clean_up_all_attackers()
{
  foreach(object combatter, object* combattees in combatants)
  {
    object* attackerlist = ({ });

    if( !combatter )                     // Combatter is destructed. see note..
    {
      map_delete(combatants, combatter); // Remove from our lists...
      continue;
    }

    // Assuming combatter exists after this point...

    foreach(object combattee in combattees)
    {
      if( !combattee )
      {
	combatants[combatter] -= ({ combattee });  // See note above...
	continue;
      }
      
      if( environment(combattee) == environment(combatter) )
	attackerlist += ({ combattee });
    }

    if( !sizeof(attackerlist) )
    {
      message(MSG_COMBAT, "The combat ends.\n", combatter);
      combatter->set_combating(0);
      
      map_delete(combatants, combatter);
      map_delete(weapon_info, combatter);
      map_delete(ac, combatter);
      map_delete(num_attacks, combatter);
    }     
    else
      combatants[combatter] = attackerlist;
  }
  return sizeof(combatants);
}
 
// Try as heart_beat and call_out, checking cpu for each.
// This auctualy implements ALL the attacks.  Orig by Casper

void
continue_all_attacks()
{
  // No combat occuring?  aw, lets close down then.
  if( !clean_up_all_attackers() )
    return;

  co_crash = call_out("combat_crash", 1); // time of 1 less than time 
                                          // between attacks.
  foreach(object combatter, object* combattees in combatants)
  {
    int k = num_attacks[combatter];
    while(k--)
    {
      foreach(mixed w_info in weapon_info[combatter])
      {
        if( w_info[WEAP_TYPE] & WEAPON_BOW )
          execute_bow_attack(combattees[0], combatter, w_info);
        else
          execute_attack(combattees[0], combatter, w_info);
      }
    }
  }
  // Place this here so if we 'bomb' somewhere above, we don't 
  // repetitivly 'bomb'.  Casper
  co_caattacks = call_out("continue_all_attacks", 2);
  // For announcing the death of the daemon
  remove_call_out(co_crash);
}
 
void
combat_crash()
{
  shout("Combat Daemon shouts: Damn!\n");
  shout("Combat Daemon tells you: I've bombed.\n");
  log_file("combatd", "Combat daemon crashed on: " + ctime(time()) +
	   ", by not completeing 'execute_all_attacks()'\n");
  destruct(this_object());
}
 
// Execute an attack.  Orig by Casper

varargs void
execute_attack(object victim, object attacker, 
	       mixed *weapon_info, int hit_mod, int dmg_mod)
{
  int damage, to_hit, dmg_rnd, i,
      drunk_mod = victim->query_drunk() - attacker->query_drunk();
  string pos = pronoun(attacker, 1);
  string wname, aname = attacker->query_cap_name(),
         vname = victim->query_cap_name();
 
  //weapon_info is divided as follows:
  //0:  int damage bonus
  //1:  int damage range(0 to ??-1)
  //2:  int to_hit bonus
  //3:  int parry modifier
  //4:  string *hit_verbs (eg, slice, chop)
  //5:  string *hit_verbs2 (eg, slices, chops)
  //6:  string *miss_verbs (eg, slice above, swing wildly at, whatever)
  //7:  string *miss_verbs2 (eg, slices above, swings wildly at, whatever)
  //8:  string *weapon_names (eg, longsword, spear, pike, etc...)
  //9:  int weapon_type (eg, bow, short sword, long sword, etc)
  //10: object weapon_object
  //11: int hand_pair_used
 
  damage = dmg_mod + weapon_info[DMG_BONUS] - ac[victim][1] 
    + drunk_mod; //(think unused args in a varargs come out as 0)
  to_hit = hit_mod + weapon_info[TOHT_BONUS] - ac[victim][0]
    + drunk_mod;

  i = random(sizeof(weapon_info[HTVBS_ACT]));
  wname = weapon_info[WEAP_NAMES][i];

  if( to_hit < 20 )
    to_hit = 20;

  if( to_hit > 980 )
    to_hit =980;

  if( random(1000) < to_hit )
  {
    // We hit code in here
    string* message;

    if( damage > 0 )
      damage = victim->receive_damage(damage + random(weapon_info[DMG_RANGE]));
    else
      damage = 0;
    message = query_dmg_message(damage);

    // Tell the attacker...
    message(MSG_COMBAT, sprintf("You %s %s with your %s, %s\n",
				weapon_info[HTVBS_ACT][i], vname, 
				wname, message[0]),
	    attacker);
    // Tell the victim...
    message(MSG_COMBAT, sprintf("%s %s you with %s %s, %s\n",
				aname, weapon_info[HTVBS_PASS][i],
				pos, wname, message[1]),
	    victim);
    // Tell everyone else...
    message(MSG_COMBAT, sprintf("%s %s %s with %s %s, %s\n",
				aname, weapon_info[HTVBS_PASS][i], vname,
				pos, wname, message[1]),
	    environment(attacker), ({ attacker, victim }));
  }
  else
  {
    // We missed code in here

    // Tell the attacker...
    message(MSG_COMBAT, sprintf("You %s %s with your %s.\n", 
				weapon_info[MSVBS_ACT][i], vname, wname),
	    attacker);
    // Tell the victim...
    message(MSG_COMBAT, sprintf("%s %s you with %s %s.\n",
				aname, weapon_info[MSVBS_PASS][i], pos, wname),
	    victim);
    // Tell everyone else...
    message(MSG_COMBAT, sprintf("%s %s %s with %s %s.\n",
				aname, weapon_info[MSVBS_PASS][i], vname,
				pos, wname),
	    environment(attacker), ({ attacker, victim }));
  }
}
 
//Execute an attack with a bow.  Orig by Casper

void
execute_bow_attack(object victim, object attacker, mixed *weapon_info)
{
  mixed *new_weapon_info;
  object arrow;
  int j;
 
  if( !(j = weapon_info[WEAP_OBJ]->do_arm_bow()) )
  {
    execute_attack(victim, attacker,
		   attacker->query_unarmed(weapon_info[HAND_PAIR]),
		   -100, -10);
    return;
  }

  if( j != -1 )     // -1 = ready to fire
    return;

  arrow = weapon_info[WEAP_OBJ]->query_arrow();
  weapon_info[WEAP_OBJ]->bow_fired();   // Reset all info, dest the arrow, etc.
  new_weapon_info = arrow->query_weapon_info();
  new_weapon_info[DMG_BONUS] += weapon_info[DMG_BONUS];
  new_weapon_info[DMG_RANGE] += weapon_info[DMG_RANGE];
  new_weapon_info[TOHT_BONUS] += weapon_info[TOHT_BONUS];
  new_weapon_info[WEAP_NAMES] = weapon_info[WEAP_NAMES];
  execute_attack(victim, attacker, new_weapon_info);
}
 
// Start combat with person A against person B.  DO NOT CALL 
// DIRECTLY, LET kill_ob() and ONLY kill_ob() do this.  No exceptions.
// Orig by Casper
// No SUPER need to be efficent here.

void
init_combat(object a, object b)
{
  a->set_combating(1);
 
  if( !combatants[a] )                           // Not combatting anyone
  {
    combatants[a] = ({ b });
    weapon_info[a] = a->query_weapon_info();
    ac[a] = a->query_ac();
    num_attacks[a] = a->query_num_attacks();
  }
  else                                           // Combatting....
  {
    if( member_array(b, combatants[a]) == -1 )   // Not attacking b already
    {
      combatants[a] = ({ b }) + combatants[a];
    }
    else                                         // Already attacking b
    {
      combatants[a] -= ({ b });
      combatants[a] =  ({ b }) + combatants[a];
    }
  }
}
 
 
// Check for valid targets & init combat.  if already 
// fighting, the two will start slugging each other out, as 
// oposed to any other oponents they may have.  May want to change 
// it so that only the attacker starts slugging the other out.
// Orig by Casper
//
// Returns:
// 1 for non-living target
// 2 for attacking self
// 3 for unallowed combat
// 4 for victim not present
// 0 on success

int
kill_ob(object attacker, object victim)
{
  int foo = victim->query_object_class();
 
  if( !living(victim) )
    return 1;
  if( victim == attacker )
    return 2;
  if( (foo & OBJECT_NO_ATTACK) ||
     environment(victim)->query_object_class() & OBJECT_NO_ATTACK )
    return 3;
  if( environment(victim) != environment(attacker) )
    return 4;
  if( userp(victim) && !interactive(victim) )
    return 3;

  init_combat(attacker, victim);
  init_combat(victim, attacker);

  if( find_call_out(co_caattacks) < 0 )     // already called out...
    continue_all_attacks();

  return 0;
}
 
// These allow wield, wear, & stuff to update this info.  
// Actual updates are handled in the combat body.  Casper 10/14/95
// Use only if fighting (query_combating() !=0) because no checks 
// here are made.
 
void
update_ac(object tp, int *new_ac)
{
  ac[tp] = new_ac;
}
 
void
update_wc(object tp, mixed *new_wc)
{
  weapon_info[tp] = new_wc;
}
