/* Advent - Outside the Entrance Grate -- Mateese, 14-Aug-96
 *
 * Here the grate blocking the entrance to the Cave is located. It can be
 * unlocked using the keys from r/subtwell.
 * This mimicks the original room Outside Grate.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
public string DetailBars()

/* Hint to true Spelunkers that they can pass the grate without
 * unlocking.
 * This description is a replication from o/grate.
 */

{
  if (!QueryFlag(F_SOLVED, this_player()))
    return
"The bars of the grate are tightly spaced and firm. A sign has been affixed "
"to them.\n"
    ;
  return
"The bars of the grate are tightly spaced, but look immaterial. "
"A sign has been affixed to them.\n"
  ;
}

/*-----------------------------------------------------------------------*/
void create()
{
  string msg;
    
  ::create();

  // Main description
  Set(P_INT_SHORT, "Outside Grate");
  Set(P_INT_LONG,
"You are in a low subterranean tunnel with a dry streambed leading south.\n"
     );
  Set(P_BRIGHT, 0);
  Set(P_NODWARF, 1);
  Set(P_NOORIG, 1);

  // Exits
  AddExit("north", ADVENT("r/subtslit"));
  AddDoor("south", ADVENT("r/aftergrate"), ([]), ADVENT("o/grate"));

  // Details
  AddDetail(({ "bed", "streambed", "rocky bed", "rocky streambed" }),
"A rocky bed for a stream to tumble along.\n"
	   );

  /* Replicated from o/grate: */
  AddDetail( ({ "bar", "bars" }), #'DetailBars);
  msg = "The sign on the grate reads:\n"
        "\n"
        "    +-----------------------+\n"
        "    |       Warning!        |\n"
        "    | Uncharted Cave ahead. |\n"
        "    |  Enter at own risk.   |\n"
        "    +-----------------------+\n"
        "\n"
        "  Biontic Magics & Excavations\n"
        "\n"
        ;
  AddDetail("sign", msg);
  AddReadMsg("sign", msg);
}

/*************************************************************************/
