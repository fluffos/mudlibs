/* Advent - Bean stalk -- Mateese, 19-Aug-96
 *
 * The Beanstalk in the West Pit. It has to be watered to grow to full
 * size, so the player can climb up and reach the Narrow Passage.
 * The actual climb code is in the West Pit room.
 * The size (0..2) is stored as P_SIZE.
 */

#include <config.h>
#include <properties.h>
#include <rooms.h>
#include "advent.h"

inherit "/std/thing";
inherit ADVENT("i/advlib");

/*-----------------------------------------------------------------------*/
public void ChangeSize(int size)

/* Change the size and the descriptions of the plant.
 */

{
  Set(P_SIZE, size);
  switch(size)
  {
  case 0:
    Set(P_SHORT, "a tiny little plant");
    Set(P_LONG, "A tiny little beanstalk, murmuring 'Water, water...'\n");
    Set(P_NOISE, "It murmurs 'Water, water...'\n");
    break;
  case 1:
    Set(P_SHORT, "a 12-foot beanstalk");
    Set(P_LONG, "A 12-foot-tall beanstalk, bellowing 'Water!! Water!!'\n");
    Set(P_NOISE, "It bellows 'Water!! Wate!!'\n");
    break;
  case 2:
    Set(P_SHORT, "a gigantic beanstalk");
    Set(P_LONG, "A gigantic beanstalk, stretching up 25 feet or more.\n");
    Set(P_NOISE, "It is silent.\n");
    break;
  }
}

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  ChangeSize(0);
  AddId(({ "bean", "beanstalk", "plant", ADV_BEANSTALK }));
  AddAdjective(({ "little", "tiny", "tall", "gigantic" }));
  Set(P_NOGET, 
"The plant has exceptionally deep roots and cannot be pulled free.\n"
     );
  Set(ADV_BEANSTALK);
    
  // NIGHTFALL
  Set(P_HELP_MSG,
"Beans are plants which, when watered, can grow to impressive heights.\n"
     );
}

/*-----------------------------------------------------------------------*/
public void init()
{
  ::init();
  add_action("fwater", "water");
  add_action("fwater", "oil");
}

/*-----------------------------------------------------------------------*/
public int fwater (string arg)

/* Water/Oil the plant.
 * Formats: 'water plant'
 *          'water plant with <...>'
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
  if (this_object() != wsearch_env(what))
  {
    notify_fail(capitalize(query_verb())+" what?\n", NOTIFY_NOT_OBJ);
    return 0;
  }

  /* Has the player something with her to water/oil the plant? */
  obj = 0;
  if (with)
    obj = wsearch_inv(with);
  if (!obj)
    obj = wsearch_inv(query_verb());
  if (!obj)
  {
    notify_fail(capitalize(query_verb())+" the plant with what?\n"
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
    if (volume < 100)
    {
      write("You don't have enough "+query_verb()+" with you.\n");
      return 1;
    }
    ads = obj->Query(P_ADS); /* /std/drink... *sigh* */
    obj->fill_vessel(volume-100);
    obj->Set(P_ADS, ads);
  }
  else
    obj->remove();

  write("You "+query_verb()+" the plant.\n");
  show(this_player()->Query(P_NAME)+" "+query_verb()+"s the plant.\n");
  if ("oil" == query_verb())
  {
    show_room(environment(this_object()),
"The plant indignantly shakes off the oil off its leaves and asks 'Water?'\n"
	     );
  }
  else
  {
    i = Query(P_SIZE);
    switch (i)
    {
    case 0:
      show_room(environment(this_object())
               , "The plant spurts into furious growth for a few seconds.\n"
	       );
      break;
    case 1:
      show_room(environment(this_object())
      , "The plant grows explosively, almost filling the bottom of the pit.\n"
	       );
      break;
    case 2:
      show_room(environment(this_object())
             , "The plant got overwatered! It's shriveling up! It's, it's...\n"
	       );
      break;
    }
    if (i >= 2)
      remove();
    else
      ChangeSize(i+1);
  }
  return 1;
}

/*************************************************************************/
