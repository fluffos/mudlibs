/* Advent - Top of Small Pit -- Mateese, 17-Aug-96
 *
 * At the top of the small pit. Below is the Hall of Mists.
 * If the player tries to climb down with the golden nugget in her
 * possessions, she'll fall and hurt herself (the original game killed
 * the player here, but this is too harsh for Nightfall).
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
public int UseExit(string verb, string arg, int method)

/* Overloading UseExit() allows us to implement the 'hurt if nugget'
 * feature without needing to implement the actual movement with all
 * its checks ourselves.
 */
{
  mixed uhoh;
  int rc;

  if ("down" == verb)
    uhoh = deep_present(ADV_NUGGET, this_player());
  if (uhoh)
    write(
"Following the steps down, the weight of the gold nugget throws you off "
"balance and you fall the remaining way down, hurting yourself.\n"
	 );
  rc = ::UseExit(verb, arg, method);
  if (uhoh && rc && environment(this_player()) != this_object())
    this_player()->DoDamage(20);
  return rc;
}

/*-----------------------------------------------------------------------*/
void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "Top of Small Pit");
  Set(P_INT_LONG,
"At your feet is a small pit breathing traces of white mist. An east passage "
"ends here except for a small crack leading on.\n"
"Rough stone steps lead down the pit.\n"
     );
  Set(P_BRIGHT, 0);
  Set(P_NODWARF, 1);

  // Exits
  AddExit("east", ADVENT("r/birdchamber"));
  AddExit("down", ADVENT("r/hallofmists"));
  AddNowayMsg(({ "west", "enter" })
	     , "The crack is far too small for you to follow.\n");

  // Details
  AddOrigDetail(({ "pit", "small pit" })
	   , "The pit is breathing traces of white mist.\n"
	   );
  AddOrigDetail(({ "crack", "small crack" })
	   , "The crack is very small -- far too small for you to follow.\n"
	   );
  AddOrigDetail(({ "mist", "wisps", "white mist", "white wisps" }),
"Mist is a white vapor, usually water, seen from time to time in caverns. "
"It can be found anywhere but is frequently a sign of a deep pit leading "
"down to water.\n"
	   );
  AddDetail(({"steps", "rough steps"})
           , "The steps lead down into the mist.\n"
	   );
  AddDetail(({"passage", "east passage" })
, "A good passage leads off east, to the west it narrows into a small crack.\n"
	   );
}

/*************************************************************************/
