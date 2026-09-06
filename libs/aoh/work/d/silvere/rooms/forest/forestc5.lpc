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

"Rumors have circulated about this wood more times than the wind has "
"breathed its sweet air through the trees. These rumors can be heard, "
"whispered thousands of times in between the leaves of the beeches in "
"this quiet, and at the same time, deafening place. It is said that an "
"ancient druidic temple hides in this wood, though no one alive has had "
"the chance to brag about. Looking around, even the forest is hiding its "
"secret. The flowers duck and blush, while the grass grows wild. "
"Shrubberies grow defensive, blocking exits, and the beeches, who are "
"known for their peaceful and bewitching music, cry softly.\n");

  AddDetail("forest",#'IntLong /*'*/);


AddDetail( ({"trees", "tree"}),
"The trees close their mouths, preventing themselves from revealing the "
"secret. They turn away from your glares. Could it be they are sensitive "
"to your advances? Or are you just too nervous in this supposedly "
"haunted forest?\n");

AddDetail( ({"beeches", "beech"}),
"Their shimmering arms and legs withdraw from your reach when you move "
"toward them. No coy smiles or catty winks come from these trees, and "
"you wonder what could make them so withdrawn. Their leaves, though "
"almost golden in the light, retract to their own hiding places in the "
"wood, afraid of some unknown source of magic.\n");

AddDetail( ({"wildflowers", "flowers",}),
"Wild are these flowers not, as they duck away from your plucking hands. "
"Bewitched by unknown forces, the beauty of the wildflowers is lacking. "
"They shudder when the sun fades away, and when light is streaming "
"through this part of the wood, they only sigh in worry. How is it that "
"an adventurer like yourself would sense all this? Could the temple "
"be sending you these messages?\n");

AddDetail("bushes",
"You can almost hear the bushes growl as you walk by. They are tattered "
"and appear to be have chomped by fierce creatures in the forest. Are "
"there fierce creatures? Standing by the bushes is making you nervous.\n");

AddDetail("grass",
"Grass stands restlessly tall here. Waving to and fro, and up and down, "
"it dances to a rhythmic beat, different from that of the druids. Its "
"color is drab, but the act of the dance is so attracting, it's hard "
"to stop staring.\n");

SetIntNoise ("Silence is deafening, and you find yourself whistling just "
"to make a sound. A few birds crack the glass of the air by screeching.\n");

AddNoise( ({"birds", "screeching"}),
"Birds overhead screech at the trees. Their sounds are startling in the "
"silence of the wood. An uneasy feeling emanates from their calls and "
"danger seems apparent.\n");

AddNoise( ({"cries", "crying"}),
"The normally seductive beeches cry softly in this portion of the forest. "
"Their sad songs cause the passerby to weep from the heart. Haunting you, "
"you wish to press on.\n");

SetIntSmell (
"The air is unsettling and stagnant here. Almost difficult to inhale, "
"you can understand why the beeches do not want to sing their beautiful "
"tales.\n");

Set(P_NOWAY_MSG,
"The agonizing screeches of birds are heard whenever you move in this "
"direction. You can't bear to go any further.\n");

  AddExit("north","./forestb5");
  AddExit("south","./forestd5");
  AddExit("west","./forestc4");
  AddExit("east","./forestc6");

}
