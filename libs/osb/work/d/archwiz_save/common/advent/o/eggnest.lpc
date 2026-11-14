/* Advent - Nest of Golden Eggs -- Mateese, 20-Aug-96
 *
 * The Nest of Golden Eggs, found in the Giant Room.
 * If the magic formula 'fee fie foe foo' is recited, it heats up
 * for a moment (this is caused by the room calling DoFoo()).
 * This is to be used to scare the Troll away from the rickety bridge.
 * For this, the function NestHeated() is called in the current environment.
 * 
 * Properties:
 *   "AdvNestHeat": 0: cold
 *                  1: warm
 */

#include <config.h>
#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("o/treasure");

#define P_HEAT  "AdvNestHeat"

/*-----------------------------------------------------------------------*/
/* To add the extra description for the warm nest, we overload the
 * existing extra desciption for the treasure.
 */

public string LongExtra()
{
  string msg;
  
  msg = "";
  if (Query(P_HEAT))
    msg = "It feels warm.\n";
  return msg+::LongExtra();
}

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  Set(P_SHORT, "a nest of golden eggs");
  Set(P_LONG, "The nest is filled with beautiful golden eggs.\n");
  Set(P_WEIGHT, 1000);
  Set(P_VALUE, 400);
  AddId(({ "eggs", "nest", ADV_NEST }));
  AddAdjective(({ "nest", "nest of", "golden" }));
  Set(P_TREASURE, F_NEST);
  Set(P_XP, 1600);
  Set(ADV_NEST, 1);
}

/*-----------------------------------------------------------------------*/
public object DoFoo ()

/* Heat up and perform some actions thereupon. Result is a living which
 * dropped the nest, or 0 if something else happened.
 * Then be warm for 10 seconds, the cold again.
 */

{
  object env;
  object rc;
    
  while(remove_call_out("Set") >= 0) /* skip */ ;

  env = environment(this_object());
  if (!env)
    return 0;
    
  if (!env->Query(P_IS_LIVING))
  {
    object env2;
    show_room(env, "A short, fierce hiss erupts from a nest of golden eggs.\n");
    /* If we are carried by a living, give it a warm feeling. */
    env2 = environment(env);
    if (env2 && env2->Query(P_IS_LIVING))
      tell_object(env2, "You feel something warm in your pack.\n");
    /* TODO: If we are in a bag, burn it? */
  }
  else /* Force the living to drop us */
  {
    rc = env;
    tell_object(env,
"The nest of golden eggs suddenly becomes very hot -- too hot...\n"
"You drop the nest.\n"
	       );
    if (ME_OK != move(environment(env), M_SILENT))
      raise_error("Move into "+to_string(environment(env))+" failed.\n");
    show_room(environment(env)
	     , env->Query(P_NAME)+" drops a nest of golden eggs as if burned.\n"
	     , ({ env })
	     );
    env->NestHeated(); /* The troll will react on this */
  }
  Set(P_HEAT, 1);
  call_out("Set", 10, P_HEAT, 0);
  return rc;
}

/*************************************************************************/
