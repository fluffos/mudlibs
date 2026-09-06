/* Angry Fuzzball  (Mateese, 16-Dec-92)
**
** A huge example for /std/npc.
** This is a huge aggressive monster. Almost everything is adjusted.
*/

#include <config.h>
#include <properties.h>   /* for the property names */
#include <living.h>
#include <moving.h>
#include <attributes.h>   /* Physical attributes of livings*/
#include <combat.h>       /* For weapons and armours */
#include <rooms.h>        /* For AddItem() */

inherit "/std/npc";

/*-------------------------------------------------------------------------
** Initialize us.
*/

create () {
  object ob;
  int i,j;

    /* We will clone us some weapons and armours, so
    ** we need a euid. Fortunately, std/living/life will set it.
    */

  if (::create()) return; /* Ignore the blueprint */

    /* Initialize Name = Short and Long description */
  Set(P_NAME, "Parch");
  Set(P_LONG,
 "A huge example monster. (/d/archwiz/common/lpc/exm/xnpc2.c).\n"
 "A great angry monster, with big teeth and two claws and "
 "two large hands. You better stay away!\n"
         );

    /* Set the physical attributes */
  Set(P_RACE, "fuzzball");
  Set(P_GENDER, GENDER_MALE); /* male */
  Set(P_WEIGHT, 100000);      /* 100 kg */
  Set(P_MAX_FOOD, 230);       /* Can eat a lot */
  Set(P_FOOD, 180);           /* is quite satiated */
  Set(P_MAX_DRINK, 212);      /* Can drink a lot */
  Set(P_DRINK, 150);          /* is quite soaked */
  Set(P_MAX_ALCOHOL, 42);     /* Can't drink much booze */
  Set(P_ALCOHOL, 5);          /* is nearly dry */
  Set(P_MSGIN, "stomps in");  /* Movement messages */
  Set(P_MSGOUT, "stomps away");
  Set(P_MMSGIN, "rises from the dirt");
  Set(P_MMSGOUT, "growls and vanishes in the ground");
  Set(P_GO_CHANCE, 0);        /* it doesn't move */

    /* Set the default stats/AC/WC/XP/HP/SP for a level-21-monster 
    ** (Remember: level 21 is 'Seer' level - this is no monster
    **  for Newbies!)
    */
  Set(P_LEVEL, 21);

    /* The not-so-physical stuff */
  Set(P_ALIGN, -2001);        /* EEEEEVIL! */
  Set(P_AGGRESSIVE, 1);      /* Aggressive ! */
  Set(P_ATTACK_CHANCE, 300); /* but attacks with a chance of 300/1000 */

    /* To make things interesting, this is not just another level-21-monster
    ** for mindless slaughter...
    */
                          /* XP varies from lvl-21 up to lvl-22 */
  AddXP(random(RACEMASTER->XPfromLevel(22) - QueryXP()));
  Set(P_MAX_HP, 380);         /* A very hard enemy (about lvl 42) */
  Set(P_HP, 342);            /* but a bit weak yet */
  Set(P_MAX_SP, 47);          /* No brain, just instinct (about lvl 1) */
  Set(P_SP, 35);             /* and not much in use so far*/

    /* If some special thing just asks for Con/Int instead of MaxHP/SP... 
    ** These have no effect on std/npc itself.
    */
  Set(P_CON, 42);             /* A hard enemy */
  Set(P_INT, 1);             /* No brain, just instinct */

    /* Parch does it's on checks on who is a friend and who isn't.
    ** The checking object can be set with
    **    SetFriendObj (checker)
    ** but in this case we use builtin function.
    */

    /* Weaponry.
    ** Remember, we have four arms: two hands to wield weapons,
    ** and two dangerous claws!
    ** So we equip one hand with one dangerous sword, leave the other
    ** hand empty, and make the claws dangerous alone.
    */

    /* Set the hands */
  Set(P_HANDS, ({ ({ "right hand", 0, WEAPON_CLASS_OF_HANDS })
                , ({ "left hand", 0, WEAPON_CLASS_OF_HANDS })
                , ({ "right claw", 0, 2*WEAPON_CLASS_OF_HANDS })
                , ({ "left claw", 0, 2*WEAPON_CLASS_OF_HANDS })
               })
     );

    /* Create the weapon (on the fly) and wield it */
  AddItem("/std/weapon", REFRESH_REMOVE|REFRESH_FUNC
         , ([ P_SHORT: "a stained sword"
            , P_LONG: "This is a generic weapon, created on the fly.\n"
                      "A long sword, dark stained with dried blood.\n"
            , P_VALUE: 10000
            , P_WEIGHT: 3000
            , P_ADS: ({ "stained" })
            , P_WEAPON_TYPE: WT_SWORD
            , P_DAM_TYPE: DT_SLASH
            , P_WC: 15
            , P_NUMBER_HANDS: 1
           ])
         , #'wieldme
         );

    /* Give Parch a hard skin */
  Set(P_DEFENCES, ({ 5 }) );

    /* Create an armour (on the fly) and wear it */
  AddItem("/std/armour", REFRESH_REMOVE|REFRESH_FUNC
         , ([ P_SHORT: "a battered mail"
            , P_LONG: "This is a generic armour, created on the fly.\n"
                      "A heavy battered chain mail.\n"
            , P_VALUE: 5000
            , P_WEIGHT: 3000
            , P_ADS: ({ "battered", "chain" })
            , P_IDS: ({ "armour", "mail" })
            , P_ARMOUR_TYPE: AT_MAIL
            , P_AC: 6
           ])
         , #'wearme
         );

    /* The normal chats: we give a couple of strings and
    ** a common chance (here 1%) per heart_beat.
    */
  InitChats (1, ({
  "You feel uncomfortable standing near this huge fuzzball.\n"
, "Parch growls and looks hungrily at you.\n"
, "Hey, didn't Parch move a bit closer ... ?!\n"
                })
           );

    /* The attack chats: we give a couple of strings and
    ** a common chance (here 20%) per attack round.
    */
  InitAChats (20, ({
  "The fuzzball howls angrily and rises to its full height of 3 meters.\n"
, "Parch growls: \"I'll rip your guts off and have them for dinner!\"\n"
, "Parch howls: \"Scalps? I'm taking heads!\"\n"
                      })
                 );

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
    ** All fun's are called in a special 'talk_ob' - here it happens
    ** to be ourself.
    ** The parch shall react on any laughing in the room, and likes
    ** being hugged.
    */
  InitMatch (
       ({ "_catch_laugh", "_catch_hug", "_catch_hug" }),  /* Function        */
       ({ "laugh"       , "hugs"      , "hugs"       }),  /* type            */
       ({ 0             , " you"      , " Parch"     })   /* match (0 == "") */
           );
}

/*-------------------------------------------------------------------------
** There are a lot of functions which might be overloaded to give
** a nice monster, e.g. (args omitted):
**   Attack()   : called for another round of combat
**   Defend()   : called by an enemy, trying to damage us
**   Kill()     : starts a combat
**   DoDamage(): lowers out HPs as result of a weapon hit
**   Die()      : creates a corpse and calls Death().
**   Death()    : destructs ourselves if there is no lfun second_life()
**                or if a call to this lfun returns 0.
**
** Here we just use Die() and second_life() for a final scream.
*/

Die() {
  tell_room( environment(this_object()),
 "YEEEEAAAARGH!\n"
+"Parch receives the final, the deadly hit!\n"
+"The earth shakes as he collapses on the ground.\n"
           );
  ::Die(); /* This now tells all: 'Parch died.' */
}

second_life() {
  tell_room( environment(this_object()),
 "Slowly the shaking earth comes to a rest.\n"
           );
  return 0;  /* No second life :-) */
}

/*-------------------------------------------------------------------------
** The funs for handling the catched tells.
** We get the catched string as argument.
*/

_catch_laugh (string str) {
  tell_room (environment(), "Fuzzballs like only slaughter!\n");
}

_catch_hug (string str) {
  string who, foo;
  object pl;

  sscanf (str, "%s hug%s", who, foo);
  if (pl = present (lower_case(who), environment())) { /* Don't get fooled. */
    tell_room ( environment(), "Parch moans and smiles at ");
    tell_room ( environment(), pl->QueryName()+".\n", ({ pl }) );
    tell_object (pl, "you.\n");
  } 
}

/*-------------------------------------------------------------------------
** This function is called whenever the Parch sees a new living and tries
** to decide whether to attack it or not (see the SetFriendObj() in the 
** create()).
** If the function returns non-zero, <victim> won't be attacked.
**
** The only friends of Parch are other fuzzballs, and Araech.
** Even npcs are attacked!
*/

int IsFriend (object victim) {
  return    (string) victim->Query(P_RACE) == "fuzzball" 
         || (string) victim->Query(P_NAME) == "Araech";
}

/*************************************************************************/
