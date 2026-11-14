/* Advent - West Pit -- Mateese, 19-Aug-96
 *
 * The west pit in the Twopit Room, housing the beanstalk
 * In the pit here is the beanstalk which, when watered, gives access
 * to the hole and the Narrow Corridor above.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
public int BeanstalkSize()
{
  object bean;
    
  bean = present(ADV_BEANSTALK, this_object());
  if (!bean)
    return -1;
  return bean->Query(P_SIZE);
}

/*-----------------------------------------------------------------------*/
public string BeanstalkExtra()
{
  int size;
    
  size = BeanstalkSize();
  if (size < 0)
    return "";
  if (!size)
    return "There is a tiny little plant here, murmuring 'Water, water...'.\n";
  if (size == 1)
    return 
"There is a 12-foot-tall beanstalk stretching up out of the pit,\n"
"bellowing 'Water!! Water!!'.\n"
    ;
  return 
"There is a gigantic beanstalk stretching all the up to the hole.\n"
  ;
}

/*-----------------------------------------------------------------------*/
public string BeanstalkNoise()
{
  int size;
    
  size = BeanstalkSize();
  if (size < 0)
    return "";
  if (!size)
    return "You hear the tiny little plant murmuring 'Water, water...'\n";
  if (size == 1)
    return "You hear the beanstalk bellowing 'Water!! Water!!'\n";
  return "It is silent.\n";
}

/*-----------------------------------------------------------------------*/
public int ExitClimb (string arg)

/* If the players tries to climb up the beanstalk, either disallow it
 * or move the player into the Narrow Passage.
 * This code could also be put into the Beanstalk itself.
 */

{
  int rc;

  if (!arg)
  {
    notify_fail("Climb what or where?\n");
    return 0;
  }

  if (!sizeof(norm_id(arg, 1) & ({ "up", "bean", "beanstalk" }) ) )
  {
    notify_fail("That won't help.\n");
    return 0;
  }

  switch(BeanstalkSize())
  {
   case 0:
     write("It's just a little plant.\n");
     rc = 1;
     break;
   case 1:
     write("You have climbed up the plant and out of the pit.\n");
     rc = UseExit("up", 0, M_GO);
     break;
   case 2:
     write("You clamber up the plant and scurry through the hole at the top.\n");
     if (ME_OK != this_player()->move(ADVENT("r/narrowcorr"), M_GO))
       raise_error("Move into "+ADVENT("r/narrowcorr")+" failed.\n");
     rc = 1;
     break;
   default:
     write("There is nothing to climb up here.\n");
     rc = 1;
     break;
  }
  return rc;
}

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "West Pit");
  Set(P_INT_LONG,
"You are at the bottom of the western pitin the twopit room. There is "
"a large hole in the wall about 25 feet above you.\n"
     );
  Set(P_BRIGHT, 0);
  Set(P_NODWARF, 1);
  SetExtraEntry("beanstalkextra", P_INT_LONG, #'BeanstalkExtra);

  // Exits
  AddExit("up", ADVENT("r/westtwopit"));
  AddExit("climb", #'ExitClimb);
  HideExit("climb", HIDE_ALWAYS);
 
  // Details
  AddOrigDetail(({ "hole", "large hole" }),
"The hole is in the wall above the pit at this end of the room.\n"
           );
 
  // Items
  AddItem(ADVENT("o/beanstalk"), REFRESH_REMOVE);
}

/*************************************************************************/
