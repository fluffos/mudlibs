/* Advent - West Side Chamber -- Mateese, 18-Aug-96
 *
 * The west chamber of the Hall of the Mountan King.
 * The rare coins are here.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "West Side Chamber");
  Set(P_INT_LONG,
"You are in the west side chamber of the hall of the mountain king.\n"
"A passage continues west and up here.\n"
     );
  Set(P_BRIGHT, 0);
    
  // Exits
  AddExit("east", ADVENT("r/hallmtking"));
  AddExit( ({"west", "up" }), ADVENT("r/crossover"));
  HideExit("up", HIDE_ALWAYS);
    
  // Items
  AddItem(ADVENT("o/treasure"), REFRESH_REMOVE
	 , ([ P_SHORT: "rare coins"
            , P_LONG: "They're a numismatist's dream.\n"
            , P_IDS: ({ "coins" })
            , P_ADS: ({ "rare" })
            , P_WEIGHT: 50
            , P_VALUE: 245
            , P_TREASURE: F_COINS /* Default XP */
           ])
	 );
}

/*************************************************************************/
