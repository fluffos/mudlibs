/* Advent - The Fierce Green Snake -- Mateese, 04-Aug-96
 *
 * The snake found in the hall of the Mountain King, guarding the exits.
 * It can be scared away by the little bird from the Bird Chamber (code
 * is in o/bird), unless the bird was present upon her arrival.
 * 
 * Property:
 *   "Active"    : set when the Snake became active (by the call to Aloha()).
 *   P_KNOWNBIRDS: list of birds the Snake doesn't fear.
 */

#include <config.h>
#include <properties.h>
#include <living.h>
#include <moving.h>
#include "advent.h"

inherit "/std/living";
inherit ADVENT("i/advlib");

#define P_ACTIVE      "SnakeActive"

/*-----------------------------------------------------------------------*/
public void create()
{
  if (::create()) /* Don't setup the blueprint */
    return;

  // Description
  SetInitLevel(30);
  Set(P_NAME, "Snake");
  Set(P_SHORT, "a fierce green snake");
  Set(P_LONG, "A huge fierce green snake. Nothing to mess with.\n");
  Set(P_WEIGHT, 20000);
  Set(P_VALUE, 0);
  Set(P_RACE, "snake");
  Set(P_GENDER, GENDER_NEUTER);
  Set(P_WIMPY, 10);
  Set(P_GO_CHANCE, 0);
  Set(P_MSGIN,   ({ "slides in", "slides in" }) );
  Set(P_MSGOUT,  ({ "slides", "slides out" }) );
  Set(P_MMSGIN,  ({ "plops in", "is here" }) );
  Set(P_MMSGOUT, ({ "fades away", "left" }) );
  Set(P_HANDS, ({ ({ "tail", 0, 20 })
                , ({ "mouth", 0, 50 })
               })
     );
  Set(P_KILL_XP, 25000);
  Set(P_SHRUG_MSG, "Hiss!\n");
  Set(P_NOGET, "It nearly takes you instead!\n");
    /* the original killed the player upon this attempt */
  AddDefence(0, 20);
  AddDefence(DT_SLASH, 5);
  AddDefence(DT_BLUDGEON, 0);
  AddDefence(DT_PIERCE, -5);
  AddDefence(DT_COLD, -5);

  Set(P_KNOWNBIRDS, ({ }));

  AddId( ({ "snake", ADV_SNAKE }) );
  AddAdjective( ({"huge", "green", "fierce" }) );
    
  Set(ADV_SNAKE, 1);
}

/*-----------------------------------------------------------------------*/
public void reset()
{
  object * birds;
    
  ::reset();
  birds = Query(P_KNOWNBIRDS);
  if (sizeof(birds))
    Set(P_KNOWNBIRDS, birds - ({ 0 }));
}

/*-----------------------------------------------------------------------*/
public void init()
{
  object *birds;

  ::init();
  add_action("ffeed", "feed");

  if (QueryFlag(F_SNAKE))
    write("The snake respectfully backs away from you.\n");
  else
    write("A huge green fierce snake bars your way!\n");
 
  birds = Query(P_KNOWNBIRDS) - ({ 0 });
  if (!Query(P_ACTIVE)
   && this_player()->Query(ADV_LITTLEBIRD) 
   && -1 == member(birds, this_player())
     )
    birds += ({ this_player() });
  Set(P_KNOWNBIRDS, birds);
}

/*-----------------------------------------------------------------------*/
public void Aloha (int flag)
{
  Set(P_ACTIVE, 1);
  ::Aloha(flag);
}

/*-----------------------------------------------------------------------*/
public void DevourBird()

/* Devour any bird carried.
 */

{
  object * birds;
    
  birds = filter_objects(all_inventory(this_object()), "Query", ADV_LITTLEBIRD);
  if (sizeof(birds))
  {
    show_room(environment(this_object())
	     , "The snake devours the little bird.\n");
    map_objects(birds, "remove");
  }
}

/*-----------------------------------------------------------------------*/
public int ffeed (string arg)

/* Print a message if someone tries to feed us.
 */

{
  if (!arg || -1 == strstr(arg, "snake"))
  {
    notify_fail("Feed whom?\n");
    return 0;
  }
  write("There is nothing here it wants to eat (except perhaps you).\n");
  return 1;
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
    if (!previous_object()->Query(ADV_LITTLEBIRD))
    {
      write("There is nothing here it wants to eat (except perhaps you).\n");
      return 0;
    }
    else
      return ME_OK;
  }
  return ::allow_enter(method, extra);
}

/*-----------------------------------------------------------------------*/
public varargs void notify_enter (object olddest, int method, mixed extra)

/* Devour the little bird.
 */
{
  ::notify_enter(olddest, method, extra);
  if (M_GIVE == method && previous_object()->Query(ADV_LITTLEBIRD))
    call_out(#'DevourBird, 1);
}

/*************************************************************************/
