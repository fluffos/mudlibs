/* Advent - The Bridge Troll -- Mateese, 25-Aug-96
 *
 * The troll guards the rickety bridge on the SW Side of Chasm.
 * Though a sign says that he must be paid, he will deem nothing worthy
 * enough. The trick is to give him the Nest of Golden Eggs and then
 * heat it up using the magic formula. The troll will drop it and run away.
 * As a hint, after lots of given objects the player will be told that
 * nothing is really enough for this troll.
 * 
 * Properties:
 *   "AdventTollsGiven": number of things a player already gave to the troll.
 *                       Stored in the player.
 */

#include <config.h>
#include <properties.h>
#include <living.h>
#include <moving.h>
#include <search.h>
#include "advent.h"

inherit "/std/living";
inherit ADVENT("i/advlib");

#define P_TOLLS_GIVEN "AdventTollsGiven"

/*-----------------------------------------------------------------------*/
public void create()
{
  if (::create()) /* Don't setup the blueprint */
    return;

  // Description
  SetInitLevel(40);
  Set(P_NAME, "Troll");
  Set(P_SHORT, "a burly troll");
  Set(P_LONG, 
"Trolls are close relatives with rocks and have skin as tough as that of "
"a rhinoceros.\n"
     );
  Set(P_WEIGHT, 300000);
  Set(P_VALUE, 0);
  Set(P_RACE, "troll");
  Set(P_GENDER, GENDER_NEUTER);
  Set(P_WIMPY, 10);
  Set(P_GO_CHANCE, 0);
  Set(P_MSGIN,   ({ "stomps in", "stomps in" }) );
  Set(P_MSGOUT,  ({ "stomps", "stomps out" }) );
  Set(P_MMSGIN,  ({ "raises from the ground", "is here" }) );
  Set(P_MMSGOUT, ({ "crumbles away", "left" }) );
  Set(P_HANDS, ({ ({ "left hand", 0, 35 })
                , ({ "right hand", 0, 35 })
               })
     );
  Set(P_KILL_XP, 27000);
  Set(P_SHRUG_MSG, "Trolls make poor conversations.\n");
  Set(P_NOGET, "The troll nearly takes you instead!\n");
    /* the original killed the player upon this attempt */
  AddDefence(0, 30);
  AddDefence(DT_SLASH, -5);
  AddDefence(DT_BLUDGEON, 5);
  AddDefence(DT_PIERCE, -5);
  AddDefence(DT_FIRE, -15);

  AddId( ({ "burly", ADV_TROLL }) );
  AddAdjective( ({"burly" }) );
    
  Set(ADV_TROLL, 1);
}

/*-----------------------------------------------------------------------*/
public void init()
{
  ::init();
  add_action("ffeed", "feed");
  add_action("fpay", "pay");

  if (QueryFlag(F_TROLL))
    write("The troll respectfully backs away from you.\n");
  else
    write("A troll steps out from beneath the bridge and blocks you way!\n");
}

/*-----------------------------------------------------------------------*/
public void NestHeated()

/* Called by the Nest of Golden Eggs when it heats up, after it
 * has been dropped.
 */

{
  show_room(environment(this_object()),
"The troll shrieks in pain and runs away.\n"
	   );
  if (!QueryFlag(F_TROLL, this_player()))
    this_player()->AddXP(Query(P_KILL_XP)+5000);
  SetFlag(F_TROLL, this_player());
    
  map_objects(deep_inventory(this_object()), "remove");
  map(deep_inventory(this_object()), #'destruct);
  remove();
}

/*-----------------------------------------------------------------------*/
public void BearNearby()

/* Called by the Bear when it enters the vicinity.
 */

{
  map_objects(deep_inventory(this_object()), "remove");
  map(deep_inventory(this_object()), #'destruct);
  remove();
}

/*-----------------------------------------------------------------------*/
public int ffeed (string arg)

/* Print a message if someone tries to feed us.
 */

{
  if (!arg || -1 == strstr(arg, "troll"))
  {
    notify_fail("Feed whom?\n");
    return 0;
  }
  write("There is nothing here it wants to eat (not even you).\n");
  return 1;
}

/*-----------------------------------------------------------------------*/
public int fpay (string arg)

/* Handle that someone tries to pay us.
 */

{
  int pos;
  object obj;
    
  if (!arg)
  {
    notify_fail("Pay what?\n");
    return 0;
  }
  if (-1 != strstr(arg, "toll") 
   || this_object() == search_env(arg)
     )
  {
    notify_fail("Great idea. What exactly do you want to pay?\n");
    return 0;
  }
  if (QueryFlag(F_TROLL))
  {
    write("The troll doesn't want to be paid by you anymore.\n");
    return 1;
  }
  pos = strstr(arg, " to");
  if (pos != -1)
    arg = arg[0..pos-1];
  obj = search_inv(arg);
  if (!obj)
  {
    notify_fail("You have no "+arg+".\n");
    return 0;
  }
  this_player()->Give(obj, this_object());
  /* The notify_enter() does the rest */
  return 1;
}

/*-----------------------------------------------------------------------*/
public void NotEnough (object obj, object giver)

{
  int nr;
    
  show_room(environment(this_object()), 
"The troll inspects "+obj->Short()+" and grumbles, 'Not enough.'\n"
	   );
  if (giver)
  {
    nr = giver->Query(P_TOLLS_GIVEN)+1;
    giver->Set(P_TOLLS_GIVEN, nr);
    if (!(nr % (2+random(3))))
      tell_object(giver
		 , "You have the impression that nothing is enough "
		   "for this one.\n"
		 );
  }
}

/*-----------------------------------------------------------------------*/
public varargs void notify_enter (object olddest, int method, mixed extra)

/* Give a message that the troll considers nothing to be enough.
 */
{
  ::notify_enter(olddest, method, extra);
  if (M_GIVE == method)
    call_out(#'NotEnough, 1, previous_object(), this_player());
}

/*************************************************************************/
