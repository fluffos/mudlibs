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
  SetIntShort("A Forest");
  SetIntLong(
"As you move deeper into the forest, the bright scenery changes a bit. "
"Darkness strengthens, as does the strange, permeating mystical aura "
"around this area. The trees are more imposing, and there is a lack "
"of flowers. Bushes are rough and ragged, and nothing seems, even "
"for a forest, well taken care of. It is said that further to the "
"southeast is the Druid's sanctum. Many who believe they are bold "
"and wise enough dare attemp to join this group. Signs you are "
"growing closer is the special odor of herbs and spices.\n");

  AddDetail("forest",#'IntLong /*'*/);


AddDetail( ({"tree", "trees"}),
"The oaks still invade this area in great numbers. All trees appear "
"to stretch their branches to the Outerworld, welcoming spirits to "
"help the druids in their practice of earth magic.\n");

AddDetail( ({"flower", "flowers"}),
"The flowers here appear more to be budding herbs. They are not as "
"bright as others in the forest, but they do seem to have an eerie "
"glow to them.\n");

AddDetail( ({"bush", "bushes",}),
"The bushes are no longer soft. They look rough, as if something "
"attacked them. Try not to get too close. You make get scratched.\n");

AddDetail("aura",
"The magical intensity in this area is overwhelming. Almost like fog, "
"an aura protects the area from any undue harm.\n");

AddDetail("oaks",
"These oaks become more and more intimidating as you make your way "
"toward the Druid's Guild. Bid them your respect. They can make or "
"break your journey.\n");


SetIntNoise ("The ever-increasing chanting continues to the southeast.\n");

AddNoise("chanting",
"It is rhythmic and pumping, but still far off in the distance.\n");

SetIntSmell (
"The aroma of herbs and spices grow continually stronger to the "
"southeast.\n");

AddSmell("herbs",
"Known for their usage of herbs, the Druids need them for rituals, as "
"well as spells. They are both bitter and sweet, exotic. Your nostrils "
"burn at the new scent.\n");

Set(P_NOWAY_MSG,
    "Thunder rumbles as you try to pass.\n");

  AddExit("north","./foresta7");
  AddExit("south","./forestc7");
  AddExit("west","./forestb6");
  AddExit("east","./forestb8");

}
