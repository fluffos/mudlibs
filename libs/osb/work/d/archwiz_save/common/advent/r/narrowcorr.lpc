/* Advent - Narrow Corridor -- Mateese, 20-Aug-96
 *
 * Above the West End of Twopit Room, this is the entrance to the Giant
 * Room and the Waterfall.
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
public string IntLongExtra()
{
  if (BeanstalkSize() < 2)
    return "At the eastern end is a hole.\n";
  return 
"At the eastern end is a hole through which you can see a profusion of leaves.\n"
  ;
}

public string HoleDetail()
{
  if (BeanstalkSize() < 2)
    return "A hole leading down. If you go down, you may not be able to go back up again.\n";
  return "A large beanstalk pokes up through the hole.\n";
}

public string BeanstalkDetail()
{
  if (BeanstalkSize() < 2)
    return "There is no such thing here.\n";
  return "The large beanstalk is strong enough to hold your weight.\n";
}

/*-----------------------------------------------------------------------*/
public int ExitClimb (string arg)

/* If the players tries to climb/jump up down, transform it silently into
 * an 'down' movement.
 * If the beanstalk is not there and the player jumped, hurt her (the
 * original killed her).
 */

{
  int rc;

  if (!arg)
  {
    notify_fail(capitalize(query_verb())+" what or where?\n");
    return 0;
  }

  if (!sizeof(norm_id(arg, 1) & ({ "down", "bean", "beanstalk" }) ) )
  {
    notify_fail("That won't help.\n");
    return 0;
  }

  rc = UseExit("down", 0, M_GO);
  
  if (rc && "jump" == query_verb() && BeanstalkSize() < 2)
  {
    write("The floor was deeper than you expected and gave you a hard landing.\n");
    this_player()->DoDamage(5);
  }

  return rc;
}

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "Narrow Corridor");
  Set(P_INT_LONG,
"You are in a long, narrow corridor stretching out of sight to the west.\n"
     );
  Set(P_BRIGHT, 0);
  SetExtraEntry("beanstalkextra", P_INT_LONG, #'IntLongExtra);

  // Exits
  AddExit("west", ADVENT("r/giantroom"));
  AddExit(({ "east", "down" }), ADVENT("r/westpit"));
  AddExit(({ "climb", "jump" }), #'ExitClimb);
  HideExit(({ "climb", "jump" }), HIDE_ALWAYS);
 
  // Details
  AddOrigDetail(({ "beanstalk", "bean", "bean stalk", "leaves" })
	   , #'BeanstalkDetail);
  AddOrigDetail(({ "hole", "large hole" }), #'HoleDetail);
}

/*************************************************************************/
