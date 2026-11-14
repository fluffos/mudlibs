/* Advent - Wicker Cage -- Mateese, 15-Aug-96
 *
 * The cage to catch the bird in the Bird Chamber (r/birdchamber).
 * It is found in the Cobble Crawl (r/cobblecrawl).
 * The cage is a standard chest, extended by the 'catch' and 'free' commands.
 */

#include <config.h>
#include <properties.h>
#include <lock.h>
#include <moving.h>
#include <search.h>
#include <combat.h>
#include "advent.h"

inherit "/obj/chest";

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  Set(P_SHORT, "a small wicker cage");
  Set(P_LONG, 
"A small wicker cage, usable to hold birds or other small animals.\n"
     );
  Set(P_INT_SHORT, "inside a small wicker cage");
  Set(P_INT_LONG, "A small wicker cage.\n");
  Set(P_VALUE, 100);
  Set(P_WEIGHT, 1000);
  Set(P_MAX_WEIGHT, 1500);
  Set(P_TRANSPARENCY, 900);
  Set(P_LOCKSTATE, LOCK_OPEN);
  RemoveId("chest");
  AddId("cage");
  AddAdjective(({ "small", "wicker" }));
}

/*-----------------------------------------------------------------------*/
public void init()
{
  ::init();
  add_action("ffree", "free");
  add_action("fcatch", "catch");
  add_action("fenter", "enter");
}

/*-----------------------------------------------------------------------*/
public int ffree (string arg)

/* Free any contained thing. It is not necessary to explicitely open
 * the cage. Allowed forms are:
 *   free <thing>
 *   free <thing> from <cage_id>
 */

{
  int i, j;
  mixed *rc;
  mapping found;
  object *objs, *objs2;
  string msg;
    
  notify_fail("Free what?\n", NOTIFY_NOT_CMD);
  if (!arg)
    return 0;
  arg = norm_id(arg);
  if (!strlen(arg))
    return 0;
    
  /* Check for 'from <cage_id>" */
  i = strstr(arg, " from ");
  if (i > 0)
  {
    if (id(arg[i+6..]))
      arg = arg[0..i-1];
    else
    {
      notify_fail("Free "+arg[0..i-1]+" from where?\n", NOTIFY_NOT_OBJ);
      return 0;
    }
  }
  
  /* Look for the object(s) to free. */
  found = sort_findings(searchm(this_object(), arg, SM_LOCATE|SM_CMULTI|SM_IGNLIGHT));
			
  if (sizeof(found[FOUND_IDS]))
    msg = implode_list(found[FOUND_IDS], "You don't find ", " in the cage.");
  else
    msg = "";
  
  objs = found[FOUND_SINGLE];

  /* If there is nothing to free, stop */
  if (!sizeof(objs))
  {
    notify_fail(!strlen(msg) ? "You find nothing to free.\n" : msg, NOTIFY_ILL_ARG);
    return 0;      
  }

  if (strlen(msg))
    write(msg);

  /* Try to move everything into the player's environment */
  j = Query(P_LOCKSTATE);
  Set(P_LOCKSTATE, LOCK_OPEN);
  rc = map_objects(objs, "move", environment(this_player()), M_SILENT);
  Set(P_LOCKSTATE, j);

  /* Construct the messages */
  objs2 = allocate(sizeof(objs));
  for (i = 0; i < sizeof(objs); i++)
    if (ME_OK == rc[i])
    {
      objs2[i] = objs[i];
      objs[i] = 0;
      tell_object(objs2[i], this_player()->Query(P_NAME)+" released you.\n");
    }
  objs -= ({ 0 });
  objs2 -= ({ 0 });

  if (sizeof(objs2))
  {
    rc = fold_objlist(objs2);
    write(implode_list(rc, "You set ", " free."));
    show(implode_list(rc, this_player()->Query(P_NAME)+" sets ", " free."));
  }
  if (sizeof(objs))
  {
    rc = fold_objlist(objs2);
    write(implode_list(rc, "", " won't leave the cage."));
  }

  return 1;
}

/*-----------------------------------------------------------------------*/
public int fcatch (string arg)

/* Catch a thing with the cage (just one thing at a time).
 * It is not necessary to explicitely open the cage, but however, this
 * closes the cage.
 * Allowed forms are:
 *   catch <thing>
 *   catch <thing> with <cage_id>
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
    
  /* Check for 'with <cage_id>" */
  i = strstr(arg, " with ");
  if (i > 0)
  {
    if (id(arg[i+6..]))
      arg = arg[0..i-1];
    else
    {
      notify_fail("Catch "+arg[0..i-1]+" with what?\n", NOTIFY_NOT_OBJ);
      return 0;
    }
  }
  
  /* Look for the object to catch. */
  obj = wsearch_env_inv(arg);
  if (!obj || (obj->Query(P_IS_LIVING) && !this_player()->CanSeeLiving(obj)))
  {
    notify_fail("You don't find "+arg+".\n", NOTIFY_NOT_VALID);
    return 0;
  }

  /* Give the victim a chance to escape */
  if (this_player()->UseStat(P_DEX, (CLASS_SCALE*obj->Query(P_DEX))-75) <= 0)
  {
    tell_object(obj, this_player()->QueryName()+" tries to trap you in a cage, but you can escape.\n");
    notify_fail("You aren't quick enough.\n", NOTIFY_NOT_VALID);
    return 0;
  }

  /* Special for Advent: one can't catch the small bird while one carries
   * the black rod.
   */
  if (deep_present(ADV_BLACKROD, this_player()) && obj->id(ADV_LITTLEBIRD))
  {
    write(
"The bird was unafraid when you entered, but as you approach it becomes "
"disturbed and you cannot catch it.\n"
	 );
    return 1;
  }
    
  /* Try to move the object into the cage */
  Set(P_LOCKSTATE, LOCK_OPEN);
  i = obj->move(this_object(), M_SILENT);
  Set(P_LOCKSTATE, LOCK_CLOSED);

  if (ME_OK == i)
  {
    write("You catch "+obj->Short()+" in the cage.\n");
    show(this_player()->QueryName()+" traps "+obj->Short()+" in a cage.\n");
    tell_object(obj, this_player()->QueryName()+" traps you in a cage.\n");
  }
  else
    write(capitalize(obj->Short())+" doesn't fit into the cage.\n");
  
  return 1;
}

/*-----------------------------------------------------------------------*/
public int fenter (string arg)

/* Do not enter the cage *sigh*.
 * Do people ever read the descriptions?
 */

{
  object obj;
    
  notify_fail("Enter what?\n", NOTIFY_NOT_CMD);
  if (!arg)
    return 0;
    
  /* Look for the object to enter. */
  obj = wsearch_env_inv(arg);
  if (!obj || (obj->Query(P_IS_LIVING) && !this_player()->CanSeeLiving(obj)))
  {
    notify_fail("You don't find "+arg+".\n", NOTIFY_NOT_VALID);
    return 0;
  }

  /* Enter this cage? */
  if (obj != this_object())
    return 0;
    
  write("You're much to big for the small cage.\nBe serious.\n");
  return 1;
}

/*************************************************************************/
