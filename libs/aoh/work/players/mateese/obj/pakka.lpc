/* Pakka - my pet oglon.
**
** Oglons are 'cat-eagle's, normally very aggressive. Pakka is nice, though,
** but has heavy 'natural' weapons and defences.
**
**  23-Sep-92 
*/

#include <properties.h>
#include <attributes.h>
#include <combat.h>

inherit "/std/npc";

/*-------------------------------------------------------------------------
** Initialize us.
*/

create () {
  object ob;

  if (::create()) return; /* Ignore the blueprint */

  SetName ("Pakka");
  SetLong (
 "Pakka is a small friendly oglon (and therefore a rarity!).\n"
+"It's cat-like body is completely covered with cosy fur, and on its back\n"
+"you see a pair of wings. Pakka looks charming, but you sense the strong\n"
+"muscles and the sharp claws under the agreeable skin.\n"
          );

    /* Set the physical attributes */
  SetRace ("oglon");
  SetGender (1);                  /* male */
  SetWeight (30000);
  SetMaxWeight (100000); /* may carry 70 kg */
  SetMaxFood (100);
  SetFood (100);
  SetMaxDrink (100);
  SetDrink (100);
  SetMaxAlcohol (40);
  SetAlcohol (20);
  SetMsgIn ("sneaks in");
  SetMsgOut ("sneaks away");
  SetMMsgIn ("glides in");
  SetMMsgOut ("flies away");
  SetGoChance (300);

  SetXP (2246430);
  SetMaxHP (630);
  SetHP (572);
  SetMaxSP (200);
  SetSP (180);
  SetAttribute (AT_STR, 20);
  SetAttribute (AT_DEX, 18);
  SetAttribute (AT_CON, 15);
  SetAttribute (AT_INT, 20);
  SetAbility (AB_IVISION, -10);
  SetAlign(2002);
  SetAggressive (0);

  Set(P_HANDS, ({
            ({ "right hand", 0, 30 }),
            ({ "left hand", 0, 30 }),
	    })
           );
  ob->SetAC(25); /* No special defences */

  SetChats (0, ({ }) );

  SetAttackChats (0, ({ }) );

    /* The monster may react more differentiated on what is said
    ** in its environment. For that, we give a series of 'type's and
    ** and 'matches', and for each of the pairs we specify which function
    ** shall be called with a matching string. 
    ** The strings from catch_tell are matched as:
    **      '%s <type><match> %s'
    **   or '%s <type><match>'
    **   or '%s <type><match>%s'
    **   or '%s <type> <match>'
    **   or '%s <type> <match> %s'
    */
/*
  SetMatch (this_object(), ({ funs }), ({ types }), ({ matches }) );
  vgl. Harry.
*/

}

/*-------------------------------------------------------------------------
** There are a lot of functions which might be overloaded to give
** a nice monster, e.g. (args omitted):
**   Attack()   : called for another round of combat
**   Defend()   : called by an enemy, trying to damage us
**   Kill()     : starts a combat
**   do_damage(): lowers out HPs as result of a weapon hit
**   die()      : creates a corpse and destructs us.
** die() destructs ourselves only, if a call to the lfun second_life()
**  returns a zero (which is the case if there's no second_life() at all).
** Overloading of die() with something non-destructive replaces the old
**  dead_ob-mechanism.
** Also, overloading of heart_beat() and Attack() could replace the
** chat mechanism, but this will (should) be implemented in the
** future.
*/

/*************************************************************************/

