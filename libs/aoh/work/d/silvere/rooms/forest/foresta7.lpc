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
"This is the northeast region of the forest. The light in this area is "
"bright and cheerful. It is as if you have entered a fairy tale. "
"Rumors of this forest being haunted seem impossible now. Rather than "
"being frightened, you feel at peace. Proud trees stand everywhere, "
"protecting the wildflowers from the garish sun. Oaks are scattered "
"here and there, hinting there is possibly a Druid's grove nearby. "
"Bushes almost as fluffy as clouds sit comfortably here. Off to the "
"east, you can hear the soft humming of water. Instantly, thirst wells "
"in your throat. To the south, the aura of oaks intensifies.\n");

AddDetail( ({"trees", "tree"}),
"There is definitely magic in these trees. The way they stand reveals "
"their extraordinary personalities. The forest does not rule them. "
"They rule the forest. Their intense presence unnerves you, and you "
"feel the pressure to bow to their whims. In this portion of the forest "
"the oaks dominate the land.\n");

AddDetail( ({"oaks", "oak"}),
"The mighty oaks are the Fathers of the Forest, as well as of the Druid "
"Grove. They reign over the beeches, the maples, and all the other "
"trees in the forest. Their firm glances often frighten travelers away, "
"giving the forest many of its foul rumors. When you stare at them, "
"you feel awe and admiration for these great rulers.\n");

AddDetail( ({"wildflowers", "flowers",}),
"Not only are the trees magical, but the wildflowers that dance beneath "
"your feet glow with fiery enchant. Vibrant reds, oranges and yellows "
"strike matches at your glimpse.\n");

AddDetail("bushes",
"These bushes look incredibly soft. Pillows beckoning rest, they "
"reach out to you. Permanent dew shimmers on their gentle limbs.\n");

AddDetail("dew",
"The dew glistens on the bushes, giving them a very chimerical "
"quality.\n");

SetIntNoise ("When you stop and listen, a soft chanting can be heard. Is "
"this the group of revered Druids? Perhaps, if you listen harder to the "
"chanting, words will be deciphered.\n");

AddNoise("chanting","It is unmistakable. This chanting you were told "
"about as a child. The mystical, earthy druids are well known for "
"their gatherings in the sacred Grove. You cannot understand their "
"words though. But they must be nearby if you can hear them.\n");

AddNoise("water","The humming is probably from a water source nearby. "
"It trickles happily.\n");

SetIntSmell (
"A hint of spices leads further to the southeast.\n");

Set(P_NOWAY_MSG,
 "The fluffy bushes grow large and gruff, preventing your passage.\n");

  AddDetail("forest",#'IntLong /*'*/);

  AddExit("west","./foresta6");
  AddExit("south","./forestb7");

}
