/* Advent - The Cave Bear -- Mateese, 26-Aug-96
 *
 * The Bear is chained in the Barren Room with the Golden Chain.
 * The Chain can be unlocked only if the bear had been tamed by feeding it.
 * The Bear can't cross the bridge above the chasm, it will crumble and
 * kill the bear.
 * He could scare away the troll, though :-)
 * 
 * Property:
 *   P_TAMER: the player who tamed the bear.
 */

#include <config.h>
#include <properties.h>
#include <living.h>
#include <moving.h>
#include <rooms.h>
#include <lock.h>
#include "advent.h"

inherit "/std/living";
inherit ADVENT("i/advlib");

/*-----------------------------------------------------------------------*/
public string BearExtraLong()
{
  string msg;
  object chain;
    
  if (Query(P_TAMER))
    msg = "but appears to be friendly.\n";
  else
    msg = "and seems quite ferocious.\n";
  chain = present(ADV_CHAIN, environment(this_object()));
  if (chain && LOCK_OPEN != chain->CheckLockstate())
    msg += "It is bound by a golden chain.\n";
  return msg;
}

/*-----------------------------------------------------------------------*/
public void create()
{
  if (::create()) /* Don't setup the blueprint */
    return;

  // Description
  SetInitLevel(20);
  Set(P_NAME, "Bear");
  Set(P_SHORT, "a large cave bear");
  Set(P_LONG, "The bear is extremely large ");
  SetExtraEntry("bear extra long", P_LONG, #'BearExtraLong);
  Set(P_WEIGHT, 300000);
  Set(P_VALUE, 0);
  Set(P_RACE, "bear");
  Set(P_GENDER, GENDER_NEUTER);
  Set(P_WIMPY, 10);
  Set(P_GO_CHANCE, 0);
  Set(P_MSGIN,   ({ "lumbers in", "lumbers in" }) );
  Set(P_MSGOUT,  ({ "lumbers", "lumbers out" }) );
  Set(P_MMSGIN,  ({ "plops in", "is here" }) );
  Set(P_MMSGOUT, ({ "fades away", "left" }) );
  Set(P_HANDS, ({ ({ "left claw", 0, 20 })
                , ({ "right claw", 0, 20 })
               })
     );
  Set(P_KILL_XP, 20000);
  Set(P_SHRUG_MSG, "This is a bear of very little brain\n"); /* Pooh :-) */
  Set(P_NOGET, "The bear nearly takes you instead!\n");
    /* the original killed the player upon this attempt */
  AddDefence(0, 20);

  AddId( ({ "bear", ADV_BEAR }) );
  AddAdjective( ({"large", "cave" }) );

  Set(ADV_BEAR, 1);		   
}

/*-----------------------------------------------------------------------*/
public void deep_remove()

/* Destruct the bear and all the inventory.
 */

{
  map_objects(deep_inventory(this_object()), "remove");
  map(deep_inventory(this_object()), #'destruct);
  remove();
}

/*-----------------------------------------------------------------------*/
public varargs int move (mixed dest, int method, mixed extra)

/* After each move, call BearOnBridge(<lastenv>) in news environment.
 * The bridge over the chasm will crumble on this and return 1 on the call.
 */

{
  object here;
  int rc;

  if (!this_object())
    return ME_DESTRUCTED_SELF;
  here = environment(this_object());
  rc = ::move(dest, method, extra);
  if (to_string(environment(this_object())) == ADVENT("r/volcano"))
    tell_room(environment(this_object()), "The bear roars in delight.\n");
  if (M_GO == method 
   && ME_OK == rc
   && environment(this_object())->BearOnBridge(here)
     )
  {
    deep_remove();
    rc = ME_DESTRUCTED_SELF;
  }
  return rc;
}

/*-----------------------------------------------------------------------*/
public void follow (mixed dest, int method, mixed extra)

/* The bear follows only M_GO movements.
 */
{
  if (method != M_GO)
  {
    show("The bear looks puzzled. After a while he lumbers away.\n");
    deep_remove();
  }
  ::follow(dest, method, extra);
}

/*-----------------------------------------------------------------------*/
public void Aloha (int flag)

/* Stop any following. And if the chain is nearby, make sure the bear
 * gets chained again.
 */

{
  object tamer;

  ::Aloha(flag);
  tamer = Query(P_TAMER);
  Set(P_TAMER, 0);
  if (tamer)
    tamer->RemoveFollower(this_object());
  tamer = present(ADV_CHAIN, environment(this_object()));
  if (tamer)
    tamer->Aloha(flag);
}

/*-----------------------------------------------------------------------*/
public void ScareTroll(object troll)

/* Scare any troll away.
 */

{
  if (troll)
  {
    show_room(environment(this_object()),
"The bear lumbers towards the troll, who lets out a startled shriek and "
"scurries away. The bear soon gives up the pursuit and wanders back.\n"
	     );
    troll->BearNearby();
  }
}

/*-----------------------------------------------------------------------*/
public void init()
{
  ::init();
  add_action("ffeed", "feed");

  if (Query(P_TAMER) && this_player() != Query(P_TAMER))
    write("There is a contented-looking bear wandering about nearby.\n");

  if (this_player()->Query(ADV_TROLL))
    call_out(#'ScareTroll, 1, this_player());
}

/*-----------------------------------------------------------------------*/
public void ChainOpen()

/* Called by the Golden Chain when it is opened. This sets the bear
 * free (and makes it possible to take the chain).
 */

{
  show(this_player()->Query(P_NAME)+" sets the bear free.\n");
  tell_object(this_player(), "You set the bear free.\n");
  if (this_player() == Query(P_TAMER))
    this_player()->AddFollower(this_object());
}

/*-----------------------------------------------------------------------*/
public void DevourFood(object tamer, object food)
{
  if (Query(P_TAMER))
  {
    show_room(environment(this_object()),
"The bear wolfs down "+food->Short()+".\n"
	     );
  }
  else
  {
    show_room(environment(this_object()),
"The bear eagerly wolfs down "+food->Short()+", after which he seems to "
"calm down considerably and even becomes rather friendly.\n"
	     );
    if (!QueryFlag(F_BEAR, tamer))
    {
      this_player()->AddXP(Query(P_KILL_XP)+5000);
      SetFlag(F_BEAR, tamer);
    }
    Set(P_TAMER, tamer);
  }
  food->remove();
}

/*-----------------------------------------------------------------------*/
public int ffeed (string arg)

/* Feed the bear with food.
 * Formats: 'feed bear
 *          'feed bear with <...>'
 */
{
  string *args;
  string what, with;
  object obj;
  int i;
    
  if (!arg)
  {
    notify_fail(capitalize(query_verb())+" what?\n", NOTIFY_NOT_CMD);
    return 0;
  }

  /* Extract the <what> and <with> from the args.
   */
  args = norm_id(arg, 1);
  i = member(args, "with");
  if (i != -1)
  {
    what = implode(args[0..i-1], " ");
    with = implode(args[i+1..], " ");
  }
  else
  {
    what = implode(args, " ");
    with = "food";
  }
  
  /* Is this object meant? */
  if (this_object() != wsearch_env(what))
  {
    notify_fail(capitalize(query_verb())+" what?\n", NOTIFY_NOT_OBJ);
    return 0;
  }

  /* Has the player something with her to feed me? */
  obj = 0;
  if (with)
    obj = wsearch_inv(with);
  if (!obj)
    obj = wsearch_inv(query_verb());
  if (!obj)
  {
    notify_fail(capitalize(query_verb())+" the bear with what?\n"
	       , NOTIFY_ILL_ARG);
    return 0;
  }

  /* Is it water or oil what the player meant? */
  if (!obj->id("food"))
  {
    notify_fail(capitalize(obj->Short())+" is nothing a bear would eat.\n"
	       , NOTIFY_NOT_VALID);
    return 0;
  }

  DevourFood(this_player(), obj);
  return 1;
}

/*-----------------------------------------------------------------------*/
public varargs int prevent_leave (mixed dest, int method, mixed extra)

/* Only the P_TAMER can take something from us.
 */

{
  if (M_GET == method && this_player() && this_player() == Query(P_TAMER))
    return ME_NO_PREVENT;
  return ::prevent_leave(dest, method, extra);
}

/*-----------------------------------------------------------------------*/
public varargs int allow_enter (int method, mixed extra)

/* Print a message if someone gives us something.
 * The handling is a bit crude, but for sake of compatibility with
 * the original...
 */

{
  if (M_GIVE == method)
  {
    if (!previous_object()->id("food"))
    {
      write("Uh-oh -- your offer only makes the bear angrier.\n");
      return 0;
    }
    if (Query(P_TAMER))
    {
      write("The bear doesn't seem very interested in your offer.\n");
      return 0;
    }
  }
  return ::allow_enter(method, extra);
}

/*-----------------------------------------------------------------------*/
public varargs void notify_enter (object olddest, int method, mixed extra)

/* Devour the little food.
 */
{
  ::notify_enter(olddest, method, extra);
  if (M_GIVE == method && previous_object()->id("food") && this_player())
    call_out(#'DevourFood, 1, this_player(), previous_object());
}

/*************************************************************************/
