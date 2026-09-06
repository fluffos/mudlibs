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

"Trees sway happily back and forth to the aromatic and calming air. Bushes "
"dance in unison with the trees, while the grass rests in the solitude of "
"the shade under the scattered beeches. Flowers grow in bunches. Herbs, "
"along with other rich vegetation also sprout. The sounds of water relax "
"you. Although peaceful tranquility reigns here, there is an eerie "
"feeling you can't shake.\n");

  AddDetail("forest",#'IntLong /*'*/);


AddDetail( ({"trees", "tree"}),
"If it is something in this part of the forest that calms you, it is "
"the gorgeous and bountiful trees present. They are not as large as "
"the oaks, but they are beautiful, their bark in shades of copper, "
"gold, and silver. Ginger like birches, strong like oaks, and magestic "
"like maples, the beeches inspire you to greater heights.\n");

AddDetail( ({"beech", "beeches"}),
"Brilliant shades of platinum garb the beeches in this area. They are "
"seductive and coy, and it appears they are winking at you. You turn "
"and look again, and they are swaying in peace, ignoring you. Could "
"your mind be playing tricks or are these trees truly human in form? "
"They moan softly in different tones, a symphonic poem for your "
"travels.\n");

AddDetail( ({"wildflowers", "flowers",}),
"You know it's absolutely impossible for flowers to uproot themselves, "
"so why does it appear these little bunches of beauty are dancing and "
"skipping around the beeches? Their hues swarm in your brain in myriads "
"of colors, moving in kaleidoscope form; reds swirl into magentas, "
"blues swirl into ceruleans, and yellows swirl into goldenrod. You sigh "
"at the loveliness of this sight and try to embed it into your memory.\n");

AddDetail( ({"bushes", "bush"}),
"Strange, but these bushes appear to be in the form of animals. There "
"is no sign of tampering; they have grown like this on their own. "
"One bush reaches out to you, a rabbit hopping away from the beeches.\n");


AddDetail("rabbit",
"This bush appears to be a rabbit. It hops up and down, as a rabbit "
"would, but it still has the features of a bush, including a rich "
"verdant color. Berries pose as eyes, which look at you with great "
"interest. Its mouth is also made of berries. It grins at you happily. "
"Spooky enough to frighten you out of the forest, you turn the other "
"way, hoping it will no longer be there when you turn back again.\n");
AddDetail("grass",
"The grass teases the herbs growing here. You can almost hear their taunts "
"in the breeze.\n");

AddNoise("breeze",
"Voices from the beeches intermingle with the warm breeze floating gently "
"through here.\n");


AddNoise( ({"moaning", "moans", "moan"}),
"An aria is being sung by the beeches. Their music is haunting and "
"awe-inspiring. You feel tears well up in your throat as you desire to "
"join in their quiet, but magical opera.\n");

SetIntNoise ("The cool sound of water rushes by to the west. Your throat "
"tickles in thirst, and your body yearns for a plunge into its soft "
"caresses.\n");

AddNoise("water",
"Incessant bubbling can be heard to the west. You hope there is a large "
"reservoir nearby. Maybe you could take a swim or rest from your "
"travels.\n");

SetIntSmell (
"Breathing in the tantalizing scent of playing wildflowers makes you "
"sigh with happiness. You can't inhale enough. One flower, in particular, "
"reaches out for you to breathe it in. It looks like a poppy.\n");

AddSmell("poppy",
"You blink twice before you realize the enticing aroma of the poppy is "
"making you sleepy. It is spell-binding and magical. It takes all your "
"strength to pull away and ignore it.\n");

Set(P_NOWAY_MSG,
"Suddenly, a group of poppies wills you to sleep, and you forget "
"where you were going.\n");

  AddExit("north","./foresta5");
  AddExit("east","./forestb6");
  AddExit("south","./forestc5");

}
