#include <rooms.h>
#include <regions.h>
#include <properties.h>
#include <coordinates.h>
#include <moving.h>
#include <skills.h>
#include <herbs.h>
#include <nightday.h>
#include <msgclass.h>
#include "forest.h"

inherit FORESTROOM;

varargs void create()
{
  ::create();
  SetIntShort("A forest");
  SetIntLong(
"Huge stones are covering the ground which itself is planted with lots of "
"grass. The stones seem to have been tumbled here by huge avalanches from the "
"stony hills far to the east. A small path leads east to the hills and south "
"into a deep forest. Huge trees are swifting softly in the air\n");

SetIntNoise ("Many eerie sounds can be heard at the entrance to the wood. "
"The cawing of birds startles you, but the whittling of crickets is "
"calming. You also hear noises coming from the trees. An odd creaking "
"emanates from the oak trees.\n");

AddNoise("oak trees", "The creaking of the oaks is very disorienting. You can't "
"help but stop and listen to their sounds. It is said that the trees speak "
"to Druids. Are the trees trying to speak to you?\n");


SetIntSmell (
"Taking a deep breath, a musty scent enters your nostrils. This forest has "
"a long, dark history. Another breath entices you to discover this history. "
"The desire to enter is almost overwhelming.\n");

// --- Added with Softbyte's Detailmaker by Aldrana
// Last update: Aldrana at Wed Mar 25 22:36:04 1998
  AddDetail( ({"hills"}),
    "The hills roll up and down like ocean waves.\n");
  AddDetail( ({"grass"}),
    "The grass is mashed underneath the stones' heavy weight. \n");
  AddDetail( ({"oaks"}),
    "They sway back and forth, but not like normal trees. Is it possible that\n"
    "these trees are possessed by Outerworldly spirits?\n");
  AddDetail( ({"trees"}),
    "These large oaks span over the the entry of the forest, revealing their \n"
  "guardianship of the wood. Their sounds are almost haunting.\n");
  AddDetail( ({"stones"}),
    "These stones are not like the marble ones to the west. Because of erosion\n"
    "and the excessive avalanches, they are cracked and broken.\n");
  AddDetail("forest",#'IntLong /*'*/);

  AddExit("west","./foresta5");
  AddExit("east","./foresta7");
  AddExit("south","./forestb6");

Set(P_NOWAY_MSG,
   "The oaks bar your way.\n");
}
