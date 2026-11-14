/* Advent - Bedquilt -- Mateese, 18-Aug-96
 *
 * The middle of the three vital junctions in the lower cave.
 * East is the Complex Junction, west the Swiss Cheese Room.
 * The exits up and north are randomized in their destination.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
public int ExitRandom (string arg)
{
  string dest;
    
  if (arg)
    return 0;
  
  if ("north" == query_verb())
  {
    dest = random(100) <= 60 ? 0 : ADVENT("r/threejunct");
    if (random(100) <= 75)
      dest = ADVENT("r/lowroom");
  }
  if ("up" == query_verb())
  {
    dest = random(100) <= 80 ? 0 : ADVENT("r/dustyrocks");
    if (random(100) <= 50)
      dest = ADVENT("r/s-nscanyon1");
  }
  if (!dest)
  {
    notify_fail(Query(P_NOWAY_MSG));
    return 0;
  }
  if (ME_OK != this_player()->move(dest, M_GO))
    raise_error("Move to "+dest+" failed.\n");
  return 1;
}

/*-----------------------------------------------------------------------*/
public int CheckAction (string action, string verb, string arg, int method)
{
  if ("exit" == action && "south" == verb && random(100) <= 80)
    return 0;
  return ::CheckAction(action, verb, arg, method);
}

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "Bedquilt");
  Set(P_INT_LONG,
"You are in bedquilt, a long east/west passage with holes everywhere.\n"
"To explore at random select north, south, up or down.\n"
     );
  Set(P_BRIGHT, 0);
    
  // Exits
  AddExit("north", #'ExitRandom);
  AddExit("east", ADVENT("r/complexjunct"));
  AddExit("west", ADVENT("r/swisscheese"));
  AddExit("south", ADVENT("r/slabroom"));
  AddExit("up", #'ExitRandom);
  AddExit("down", ADVENT("r/anteroom"));
  CheckExit("south", DACT_CHECK);

  Set(P_NOWAY_MSG, 
"You have crawled around in some little holes and wound up back in the main "
"passage.\n"
     );
}

/*************************************************************************/
