/* Advent - Rusty Door -- Mateese, 21-Aug-96
 *
 * The rusty door blocking the way north out of the Immense Passage.
 * To open/close it, it's hinges need to be oiled.
 * 
 * Properties:
 *   "AdvOiled": non-zero if the hinges are oiled.
 */

#include <config.h>
#include <properties.h>
#include <lock.h>
#include <search.h>
#include "advent.h"

inherit "/obj/door";

/*-----------------------------------------------------------------------*/
public string HingeDetail()
{
  if (Query(P_OILED))
    return "The hinges have been oiled and might be able to move.\n";
  return "The hinges are thoroughly rusted and won't budge.\n";
}

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  Set(P_SHORT, "a rusty door");
  Set(P_LONG, "It's just a big iron door.\n");
  Set(P_WEIGHT, 25000);
  AddAdjective(({ "rusty", "big", "iron" }));
  AddSubDetail(({"hinges", "hinge" }), #'HingeDetail);
}

/*-----------------------------------------------------------------------*/
public void init()
{
  ::init();
  add_action("fwater", "water");
  add_action("fwater", "oil");
}

/*-----------------------------------------------------------------------*/
public varargs int DoActionFor (int action, int type, object *keys, int kix)

/* Don't allow opening/closing of the door as long as the hinges are rusted.
 * This could by simulated by locking the door, but then the messages
 * would be misleading.
 */

{
  switch(action)
  {
  case LOCK_DO_OPEN:
  case LOCK_DO_CLOSE:
    if (!Query(P_OILED))
    {
      write("The hinges are quite thoroughly rusted and won't budge.\n");
      return 1;
    }
      write("The door "
	    +(type == LOCK_DO_OPEN ? "heaves open" : "falls shut" )
	    +" with a shower of rust.\n"
	   );
  }
  return ::DoActionFor(action, type, keys, kix);
}

/*-----------------------------------------------------------------------*/
public int fwater (string arg)

/* Water/Oil the door hinges.
 * Formats: 'water door/hinges'
 *          'water door/hinges with <...>'
 */
{
  string *args;
  string what, with;
  object obj;
  int i, volume;
    
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
    with = 0;
  }
  
  /* Is this object meant? */
  if (norm_id(what) != "hinges" && this_object() != wsearch_env(what))
  {
    notify_fail(capitalize(query_verb())+" what?\n", NOTIFY_NOT_OBJ);
    return 0;
  }

  /* Has the player something with her to water/oil the hinges? */
  obj = 0;
  if (with)
    obj = wsearch_inv(with);
  if (!obj)
    obj = wsearch_inv(query_verb());
  if (!obj)
  {
    notify_fail(capitalize(query_verb())+" the hinges with what?\n"
	       , NOTIFY_ILL_ARG);
    return 0;
  }

  /* Is it water or oil what the player meant? */
  if (!obj->id(query_verb()))
  {
    notify_fail(capitalize(obj->Short())+" is no "+query_verb()+".\n"
	       , NOTIFY_NOT_VALID);
    return 0;
  }
  
  /* Is it a /std/drink or something else?
   * Wish we had a /obj/bottle or similar...
   */
  volume = obj->QueryFull();
  if (volume) /* /std/drink or similar */
  {
    string * ads;
    if (volume < 50)
    {
      write("You don't have enough "+query_verb()+" with you.\n");
      return 1;
    }
    ads = obj->Query(P_ADS); /* /std/drink... *sigh* */
    obj->fill_vessel(volume-50);
    obj->Set(P_ADS, ads);
  }
  else
    obj->remove();

  write("You "+query_verb()+" the hinges.\n");
  show(this_player()->Query(P_NAME)+" "+query_verb()+"s the door hinges.\n");
  if ("oil" == query_verb())
  {
    if (Query(P_OILED))
      write("It doesn't help much.\n");
    else
      write(
"The oil has freed up the hinges so that the door will now move, although "
"it requires some effort.\n"
	   );
     Set(P_OILED, 1);
  }
  else
  {
    if (!Query(P_OILED))
      write("It doesn't help much.\n");
    else
      write(
"The hinges are quite thoroughly rusted now and won't budge.\n"
	   );
     Set(P_OILED, 0);
  }
  return 1;
}

/*************************************************************************/
