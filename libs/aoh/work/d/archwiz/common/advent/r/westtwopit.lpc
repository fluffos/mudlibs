/* Advent - West End of Twopit Room -- Mateese, 19-Aug-96
 *
 * The west end of the twopit room.
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
  object room, bean;
  int size;
    
  room = find_object(ADVENT("r/westpit"));
  if (room)
    bean = present(ADV_BEANSTALK, room);
  if (bean)
    size = bean->Query(P_SIZE);
  return size;
}

/*-----------------------------------------------------------------------*/
public string BeanstalkDescription()
{
  int size;
    
  size = BeanstalkSize();
  if (!size)
    return 0;
  if (size < 2)
    return 
      "The top of a 12-foot-tall beanstalk is poking out of the west pit.\n"
    ;
  return 
    "There is a huge beanstalk growing out of the west pit up to the hole.\n"
  ;
}

/*-----------------------------------------------------------------------*/
public string BeanstalkExtra()
{
  return BeanstalkDescription() || "";
}

public string BeanstalkDetail()
{
  return BeanstalkDescription() || "You see no beanstalk here.\n";
}

/*-----------------------------------------------------------------------*/
public int CheckAction (string action, string verb, string arg, int method)

/* We interfere with the movement if the player tries to go up the dome
 * with the nugget. Note that this way we don't need to do the movement
 * with all its checks ourselves.
 */
{
  if ("exit" == action && "up" == verb && BeanstalkSize() < 2)
  {
    notify_fail("The hole is too far up for you reach.\n");
    return 0;
  }
  return ::CheckAction(action, verb, arg, method);
}

/*-----------------------------------------------------------------------*/
public int ExitClimb (string arg)

/* If the players tries to climb up the beanstalk, transform it silently into
 * an 'up' movement.
 */

{
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
  return UseExit("up", 0, M_GO);
}

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "West End of Twopit Room");
  Set(P_INT_LONG,
"You are at the west end of the twopit room. There is a large hole "
"in the wall above the pit at this end of the room.\n"
     );
  Set(P_BRIGHT, 0);
  SetExtraEntry("beanstalkextra", P_INT_LONG, #'BeanstalkExtra);

  // Exits
  AddExit("east", ADVENT("r/easttwopit"));
  AddExit("west", ADVENT("r/slabroom"));
  AddExit("down", ADVENT("r/westpit"));
  AddExit("up", ADVENT("r/narrowcorr"));
  AddExit("climb", #'ExitClimb);
  HideExit("climb", HIDE_ALWAYS);
  CheckExit("up", DACT_CHECK);
 
  // Details
  AddOrigDetail(({ "beanstalk", "bean", "bean stalk" }), #'BeanstalkDetail);
  AddOrigDetail(({ "hole", "large hole" }),
"The hole is in the wall above the pit at this end of the room.\n"
           );
}

/*************************************************************************/
