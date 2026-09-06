/**
 * This file is the generic weapon attack action, and is intended as a
 * model for all future attack actions. When writing your own actions,
 * try to follow the same pattern, ok? Ok. - Al (May 20, 2003)
 *
 * First things first, you need to include battle.h. This gives you all
 * of the macros and constants that you will need for standard actions.
 *
 * The BATTLE_ACTION macro saves you a -bunch- of time by writing the
 * main() method for you. All you need to give it is the readiness
 * requirement and an array of forms that it is valid with. It will take
 * care of the rest, and will call on_action() when the player is ready.
 */
#include <battle.h>

BATTLE_ACTION( 1000, ({ "sword", "knife", "polearm" }) )

/**
 * This method is kind of brain-dead, but since I'm commenting the heck
 * out of everything, I may as well be complete. This method is called
 * by the ready meter and action lists in order to display the correct
 * name of the action to the player.
 *
 * So, if your action is in a file called monkeypunch.c, you could
 * have query_action_name() return "Punch of the Monkey" or whatever you
 * want the player to see in action lists.
 */
string query_action_name() {
   return "Slash";
}

/**
 * Ok, this method is where all of the real code goes. It is called by
 * the BATTLE_ACTION macro whenever the player is ready to actually
 * perform the action.
 *
 * My calling the target 'victim' is just out of tradition ;)
 */
void on_action( object victim ) {
   mixed result;    // This array is used to contain the results of a
                    //   call to BATTLE_DAEMON->()
   mapping wc;      // Weapon Class of the attack
   int damage;      // Actual damage (in % of hp) taken by the victim
   object weapon, *weapons; // Used when determining what weapon to use
   string buf = ""; // Buffer where I store the results for messaging
   string bp;       // Body Part struck by the attack.

   // First off, subtract the readiness cost of the action. Doing this
   // actually doing anything else prevents us from looping forever.
   this_player()->add_readiness(-500);

   // Make sure that the target is in the same room, etc...
   if( !BATTLE_DAEMON->check_legal_melee(victim, "slash") )
      return;

   /*** OLD ***
    * This block of code is obsolete, and is the first thing that
    * should be changed in all old actions. We have changed the way
    * that endurance and readiness work together. Readiness regen is
    * now tied to your endurance %, so there is no reason for all of
    * this mess. In stead, just subtract a (very) small amount of
    * endurance for all actions without checking for anything else.

   if (this_player()->query_endurance())
      this_player()->add_endurance(-1);
   else {
      msg("~CWRNYou are too tired to fight any more!~CDEF");
      this_player()->add_readiness(-1000);
      return;
   }
    *** OLD ***/
   this_player()->add_endurance(-1);


   // There has got to be a better way to do this. However, I can't
   // think of one at the moment. Right now, what happens is we
   // pick a weapon at random from those they have wielded and use
   // it to attack with. If the weapon winds up being illegal under
   // their current form then they'll switch forms and the action
   // should stop.
   if (weapons = BATTLE_DAEMON->query_wielded_weapons(this_player(),
       (this_player()->query_form_object())->query_weapon_types()))
     weapon = weapons[random(sizeof(weapons))];
   else {
     msg("You are not wielding an appropriate weapon.");
     this_player()->adopt_best_form();
     return;
   }

   // Making a copy of the WC is *VERY* important. If you do not
   // copy it... you will actually edit the weapon every time it is
   // used in combat, which is an incredibly bad thing.
   wc = copy(weapon->query_wc());
   // Throw out broken weapons.
   if (!mappingp(wc)) {
     debug((string)weapon+" does not have a valid wc mapping.");
     return;
   }

   /*** OLD ***
    * The old way of doing things involved a lot of random math and
    * direct tweaks to WC. This should be avoided in almost every
    * case now. You should now only add their str_wc except in the
    * most extreme of situations, and you should only add it to one
    * damage type (prefferably a physical one).

   wc["edged"] += this_player()->query_str_wc() +
                  this_player()->query_attitude("offense");
    *** OLD ***/
   wc["edged"] += this_player()->query_str_wc();

   // execute_melee() does the work of actually swinging the weapon,
   // giving the defender a chance to react, inflicting damage, and
   // practicing the generic weapon skill. The parameters are:
   //   object - the weapon being used (this_player() for unarmed)
   //   mapping - weapon class of the attack (often different than
   //             that of the weapon itself)
   //   object - the target of the attack
   //   int - the speed of the attack (1-20, normal attacks should
   //         not be faster than 10, with 2-5 being average)
   //   int - bitmask of special flags (ATT_xxx) that determines what
   //         sorts of reactions are allowed. leave this zero in most
   //         cases
   result = BATTLE_DAEMON->execute_melee(weapon, wc, victim, 2, 0);

   // Grab the damage % dealt by the attack
   damage = result[RESULT_MOD];

   /*** NEW ***
    * This code will extract the name of the body part struck from the
    * result array.
    */
   if (sizeof(result) > 3)
     bp = victim->query_bp_name(result[RESULT_BP]);
   /*** NEW ***/

   // Make messaging different, depending on the type of result returned.
   // Generally, we will ignore the difference between anything that isn't
   // an outright miss because the reaction verb itself usually comes up
   // with an appropriate message.
   switch (result[RESULT_TYPE]) {
     case "miss":
       buf = "~[130~Name ~verbmiss ~targ with a wild slash!";
       break;

     /*** OLD ***
      * This change is big. It is now possible to make the messages much
      * more descriptive (now that blows actually strike specific body
      * parts).
      *
      * It is also important to note that damage is now a % of the victim's
      * current hp in stead of actual hp inflicted. That way dealing 10
      * points of damage to something with 150 hp doesn't get the same
      * message as when that same hit lands on someone with only 12 hp left.

     case "block":
     case "parry":
     case "dodge":
       if (damage)
         buf = "~[130~Targ almost ~vert"+result[RESULT_TYPE]+" ~npos punch, but not quite.";
       else
         buf = "~[130~Targ ~vert"+result[RESULT_TYPE]+" ~npos punch!";
       break;

     case "hit":
     case "counter":
     default:
       if (damage >= 10)
         buf = "~[090~Name ~verbslash ~targ hard!";
       else if (damage > 0)
         buf = "~[090~Name ~verbcut ~targ.";
       else
         buf = "~[130~Name barely ~verbnick ~targ with ~poss "+weapon->query_name()+".";
       break;
      *** OLD ***/

     // At a bare minimum, you should have these 4 variations in messaging
     // (ie 100%, >=40%, >=5%, <5%). Of course you can add more.
     default:
	   // sound
	   AUDIO_DAEMON->sfx_room(environment(victim),"slice.wav");
	
	   if( damage == 100 )
	     buf = "~[090~Name ~verbslash ~targ viciously with ~poss "+weapon->query_name()+
	           ", killing ~objt.";
	   else if (damage >= 40)
	     buf = "~[090~Name ~verbcut deep into ~npot "+bp+" with ~poss "+weapon->query_name()+".";
	   else if (damage >= 5) {
	     if (result[RESULT_ARMOUR])
	        buf = "~[090~Name ~verbslash ~targ hard in the "+bp+", but ~post "+result[RESULT_ARMOUR]->query_name()+" absorbs some of the blow.";
	     else
	        buf = "~[090~Name ~verbslash ~targ hard in the "+bp+" with ~poss "+weapon->query_name()+".";
	   } else {
	     if (result[RESULT_ARMOUR])
	        buf = "~[090~Name ~verbslash ~npot "+bp+", but ~post "+result[RESULT_ARMOUR]->query_name()+" absorbs most of the blow.";
	     else
	        buf = "~[090~Name ~verbslash ~npot "+bp+", but the blow seems to have little effect.";
	   }
       break;
   }

   // Tack on the results of any reaction by the victim.
   if (result[RESULT_MSG])
     buf += "~[060 "+result[RESULT_MSG];

   // Display the message.
   this_player()->msg_local(buf+"~CDEF");
}
