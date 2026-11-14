/* Advent - Little Bird -- Mateese, 04-Aug-96
 *
 * The Little Bird found in the Bird Chamber.
 * When released in the Hall of the Mt. King, it will drive the snake
 * away. However, released against the dragon won't help much.
 */

#include <config.h>
#include <properties.h>
#include <rooms.h>
#include <living.h>
#include <lock.h>
#include <moving.h>
#include "advent.h"

inherit "/std/living";
inherit ADVENT("i/advlib");

/*-----------------------------------------------------------------------*/
public void create()
{
  if (::create()) /* Don't setup the blueprint */
    return;

  // Description
  SetInitLevel(1);
  Set(P_NAME, "Bird");
  Set(P_SHORT, "a little bird");
  /* P_LONG are hardcoded */
  Set(P_WEIGHT, 50);
  Set(P_VALUE, 0);
  Set(P_RACE, "bird");
  Set(P_GENDER, GENDER_NEUTER);
  Set(P_WIMPY, Query(P_MAX_HP)-10);
  Set(P_GO_CHANCE, 0);
  Set(P_MSGIN,   ({ "flutters in", "flutters in" }) );
  Set(P_MSGOUT,  ({ "flutters", "flutters out" }) );
  Set(P_MMSGIN,  ({ "plops in", "is here" }) );
  Set(P_MMSGOUT, ({ "fades away", "left" }) );
  Set(P_HANDS, ({ ({ "left wing", 0, 2 })
                , ({ "right wing", 0, 2 })
               })
     );
  Set(P_SHRUG_MSG, "Cheep!  Chirp!\n");
  Set(P_NOGET, 0);
  Set(P_DEX, 5);

  AddId(({ "bird", ADV_LITTLEBIRD }));
  AddAdjective("little");
    
  Set(ADV_LITTLEBIRD, 1);
}

/*-----------------------------------------------------------------------*/
public void init()
{
  ::init();
  AddHeart("bird_heartbeat");
  add_action("ffeed", "feed");
  add_action("fcatch", "catch");
}

/*-----------------------------------------------------------------------*/
public void BirdAttack (object owner, int goterror)

/* If the snake or the dragon is in the room, we are set free to shoo
 * them away. React accordingly.
 */

{
  object enemy, *known;
    
  if (goterror)
    return;

  /* Check for the snake */
  enemy = present(ADV_SNAKE, environment(this_object()));
  if (enemy)
  {
    known = enemy->Query(P_KNOWNBIRDS);
    if (!sizeof(known) || -1 == member(known, this_object()))
    {
      show_room(environment(this_object()),
"The little bird attacks the green snake and in an astounding flurry "
"drives the snake away.\n"
               );
      if (!QueryFlag(F_SNAKE, owner))
      {
        SetFlag(F_SNAKE, owner);
        owner->AddXP(enemy->Query(P_KILL_XP)+5000);
      }
      enemy->remove();
    }
  }
    
  /* Check for the dragon */
  enemy = present(ADV_DRAGON, environment(this_object()));
  if (enemy)
  {
    show_room(environment(this_object()),
"The little bird attacks the dragon and in an astounding flurry "
"gets burnt to a cinder. The ashes blow away.\n"
             );
    remove();
  }
    
}

/*-----------------------------------------------------------------------*/
public varargs int move (mixed dest, int method, mixed extra)

/* Prior to a move, remember the current owner.
 * If it is a get, set a proper P_NOGET (dynamic P_NOGETs are not possible
 * with the current implementation).
 * After the move, do the check for special attacks.
 */

{
  object *env, owner;
  int rc;

  /* Determine owner, if any */
  env = filter_objects(all_environments(this_object()), "Query", P_IS_LIVING);
  if (sizeof(env))
    owner = env[<1];
  else
    owner = 0;
  AddHeart("bird_heartbeat");
  if (M_GET == method)
  {
    Set(P_NOGET, 0);
    if (deep_present(ADV_BLACKROD, this_player()))
      Set(P_NOGET, 
"The bird was unafraid when you entered, but as you approach it becomes "
"and you cannot catch it.\n"
	 );
    else if (this_player()->UseStat(P_DEX, (CLASS_SCALE * Query(P_DEX))) < 0)
      Set(P_NOGET, "The bird is too quick for you.\n");
  }
  rc = ::move(dest, method, extra);
  Set(P_NOGET, 0);
  if (this_player() && ME_OK == rc && owner)
    this_player()->RegisterCmdFun("BirdAttack", owner);
  return rc;
}

/*-----------------------------------------------------------------------*/
public int IsTrapped()

/* Return 1 if the bird is in some sort of captivity, but can flutter
 * away, return -1 if the bird can't flutter away.
 * Return 0 if the bird is free.
 */

{
  object * env;
  env = all_environments(this_object());
  if (sizeof(env) < 2)
    return 0;
  if (env[0]->Query(P_LOCKSTATE) != LOCK_OPEN)
    return -1;
  return 1;
}

/*-----------------------------------------------------------------------*/
public string QueryLong()
{
  if (IsTrapped() >= 0)
    return "A cheerful little bird, sitting here singing.\n";
  return "A rather unhappy little bird.\n";
}

/*-----------------------------------------------------------------------*/
public string QueryNoise()
{
  if (IsTrapped() >= 0)
    return "The little bird sings cheerfully.\n";
  return "The little bird chirps unhappily.\n";
}

/*-----------------------------------------------------------------------*/
public void bird_heartbeat()
{
  int trapped, rc;
  object env;

  env = environment(this_object());
  if (!env)
    return 0;

  trapped = IsTrapped();

  // If trapped, try to flutter away (about once in 10 seconds).
  if (trapped > 0 && environment(env) && !random(5))
  {
    rc = move(environment(env), M_SPECIAL
	      , ({ "flutters away", "flutters in", "flutter away" })
	      );
     if (ME_OK == rc)
       trapped = IsTrapped();
  }
    
  // If not trapped and in an outdoors room, maybe fly away.
  if (!trapped 
   && !env->Query(P_INDOORS)
   && !random(5)
     )
  {
    show("The little bird flies away.\n");
    remove();
    return 0;
  }
  
  // If not trapped and nobody is here to watch, stop the heart.
  if (!trapped
   && !sizeof(filter_objects(all_inventory(env)
			    , "Query", P_IS_PLAYER))
     )
    return 0;

  return 1;
}

/*-----------------------------------------------------------------------*/
public int ffeed (string arg)

/* Print a message if someone tries to feed us.
 */

{
  if (!arg || -1 == strstr(arg, "bird"))
  {
    notify_fail("Feed whom?\n");
    return 0;
  }
  write(
"It is not hungry. (It's merely pinin' for the fjords). Besides, it propably "
"prefers bird seed.\n"
       );
  return 1;
}

/*-----------------------------------------------------------------------*/
public int fcatch (string arg)

/* Don't catch the bird with bare hands... hey, it's a puzzle!
 */

{
  int i;
  object obj;
    
  notify_fail("Catch what?\n", NOTIFY_NOT_CMD);
  if (!arg)
    return 0;
  arg = norm_id(arg);
  if (!strlen(arg))
    return 0;
    
  /* Look for the object to catch. */
  obj = search_env_inv(arg);
  if (obj == this_object())
    notify_fail("The little bird is too quick for your bare hands.\n", NOTIFY_NOT_VALID);

  return 0;
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
    write(
"It is not hungry. (It's merely pinin' for the fjords). Besides, it propably "
"prefers bird seed.\n"
         );
    return 0;
  }
  return ::allow_enter(method, extra);
}

/*************************************************************************/
