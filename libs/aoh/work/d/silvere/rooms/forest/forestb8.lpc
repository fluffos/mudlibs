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
"This portion of the forest entirely consists of powerful oaks. "
"No other trees or bushes can be seen. All plantlife sacrificed "
"itself to give life to the oaks in the area. The grass here is "
"very dull, in the midst of the magnificent and noble trees. "
"Magic dances all around you, making you feel as if everything "
"is possible. Animals roam freely here, unafraid of visitors. "
"It is obvious the druids of this forest protect everything "
"within it. You can hear their singing and chanting to the "
"southeast. Beware, if you dare to enter their realm, you must "
"respect them. Danger will come to those who betray these mighty "
"magicians. They have incredible guards: the trees. \n");


AddDetail( ({"trees", "oaks"}),
"Where you once noticed glances from the trees, now you see smiles. "
"You do not feel threatened by them, as they are at peace. Almost "
"jealous of the druids for having such power, you desire to be like "
"them.\n");

AddDetail( ({"animals", "animal"}),
"The animals here are wild and free. You spy a squirrel and its "
"young, as well a few rabbits, and a bear cub. They pay no "
"attention to you, and live their merry lives in this safe haven.\n");

AddDetail( ({"rabbit", "rabbits"}),
"These little creatures hop and skip around, snacking on the grass "
"around them. They look content. One of them looks at you, and you "
"are almost positive it smiled at you.\n");

AddDetail("grass",
"The grass is short, but not stunted. It looks as if it's been chewed "
"quite a bit. Its color is a soft hue of green.\n");

AddDetail("magic",
"Magic entraps you in its maddening web.\n");

AddDetail("bear",
"A little bear cub tumbles through the forest. Though there is no "
"mother in sight, you can be sure she isn't too far behind "
"He chases at invisible bumblebees and falls on his nose.\n");


AddDetail("squirrels",
"These cute and cuddly creatures are searching for oak nuts for "
"their dinner.\n");
SetIntNoise ("The woodland animals talk to themselves. Chanting is "
"stronger than ever.\n");

AddNoise( ({"chanting","singing"}),
"Very loud, it sounds as if the druids are in front of you. Their "
"chanting seems to call out words. Taranis! Esus! Teutates! Are "
"these names? What could they be?\n");

AddSmell( ({"spices","herbs"}),
"Rich, strong and exotic smells haunt your being. These herbs and "
"spices are overwhelming.\n");

SetIntSmell (
"Herbs and spices become a part of you as they form fingers, "
"luring you to the southeast.\n");

Set(P_NOWAY_MSG,
    "The magic shimmers into a shield, stopping you.\n");

  AddDetail("forest",#'IntLong /*'*/);

  AddExit("west","./forestb7");
  AddExit("east","./forestb9");

}
