/* Advent - Cavern with Waterfall -- Mateese, 20-Aug-96
 *
 * The magnificent Cavern with the Waterfall. South is the Giant Room,
 * west/south the Steep Incline leading to the Large Low Room.
 * The water will reappear in the Reservoir.
 * The Jeweled Trident is here.
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
  Set(P_INT_SHORT, "Cavern with Waterfall");
  Set(P_INT_LONG,
"You are in a magnificent cavern with a rushing stream, which cascades "
"over a sparkling waterfall into a roaring whirlpool which disappears "
"through a hole in the floor. Passages exit to the south and west.\n"
     );
  Set(P_BRIGHT, 0);
  Set(P_INT_NOISE, "The roar of the water falling down nearly deafens you.\n");

  // Exits
  AddExit("south", ADVENT("r/immpassage"));
  AddExit("west", ADVENT("r/steepincline"));
    
  // Details
  AddOrigDetail(({ "waterfall", "sparkling waterfall", "whirlpool" }),
"You wouldn't want to go down it in a barrel.\n"
	   );
    
  // Items
  AddItem(ADVENT("o/treasure"), REFRESH_REMOVE
	 , ([ P_SHORT: "a jeweled trident"
            , P_LONG: "The trident is encrusted with fabulous jewels.\n"
            , P_IDS: ({ "trident", ADV_TRIDENT })
            , P_ADS: ({ "jeweled", "encrusted" })
            , P_WEIGHT: 2500
            , P_VALUE: 800
            , P_TREASURE: F_TRIDENT
            , P_XP: 1600
            , ADV_TRIDENT: 1
           ])
	 );
  /* The water is here so the players can fill their bottles :-) */
  AddItem(ADVENT("o/water"), REFRESH_REMOVE
         , ([ P_LONG: 
"A whirlpool of cold water. It disappears through a hole in the floor.\n"
           ])
	 );
}

/*************************************************************************/
