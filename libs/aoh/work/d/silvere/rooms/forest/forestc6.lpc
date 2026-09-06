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
"The 'interracial' interactions between the oaks and the beeches here "
"is amazing and breath-taking. They dance together, combining the stalky "
"and rough oaks' stance with the languid, saltry sway of the beeches. "
"The oaks lean instinctively to the sunlight of the north, being nurtured "
"by the strength of the druids, while the beeches reach for the somber "
"solitude of the west. Flowers and grass sprout in unusual places. "
"Acorns roll around on the ground, while strangely round and smooth stones "
"sit quietly, awaiting command. This forest is alive with magic "
"everywhere you go.\n");

  AddDetail("forest",#'IntLong /*'*/);


AddDetail( ({"trees", "tree"}),
"It doesn't matter where you go, the trees in this forest definitely "
"create a mystical ambience. You feel nervous standing under these "
"mighty oaks, while entranced by the beeches. So many rumors about "
"this wood almost prevented you from coming. Could any of them be true?\n");

AddDetail( ({"oaks", "oak"}),
"The oaks are alway an indication of where the druids are. For centuries, "
"the druids have utilized these mighty fortresses for anything from "
"protection to healing agents to magical components. Gazing at them, "
"you wonder what their magical use could possibly be. The acorns scattered "
"beneath them look appetizing for neighboring animals.\n");

AddDetail("acorns",
"The acorns scatter themselves all over the ground underneath the massive "
"oak trees. Unusually large, some are actually the size of small apples. "
"You notice a squirrel dart by and grab one and run off. One acorn appears "
"to be glowing.\n");

AddDetail( ({"glowing","acorn", "glowing acorn"}),
"There is an acorn here which glows with the magic of the moon and shines "
"with the light of the sun. Your first instinct is to chomp right into "
"it for a snack, but you think better of it and stop to stare at it more. "
"What could be its usage?\n");

AddDetail( ({"wildflowers", "flowers",}),
"The flowers here don't appear to grow out of the ground, but rather "
"to grace it. They stretch out in comfortable positions, sighing and "
"whispering to each other. You swear you heard one of them speak of "
"a hidden temple in the area, but when you lean in to listen closer, "
"the source of the sound, a peach rose, stops and looks the other way.\n");

AddDetail( ({"roses", "peach",}),
"There is only really one rose here, and its beauty surpasses most of "
"the other flowers. Its significant trait is the strange hue of peach "
"it bears, and plucking it is out of the question. It looks like it's "
"staring at you expectantly.\n");



AddDetail("bushes",
"There are no bushes in the part of the forest, except for very small "
"shrubbery. Lively and green, it creates the underbrush.\n");

AddDetail("dew",
"Glimmering on just the solitary peach rose, it creates the effect of "
"diamonds crying from its eyes. Could it be upset?\n");

SetIntNoise ("Chanting can be heard from the northeast, while woodland "
"creatures chatter with the plantlife under the shade of the trees.\n");

AddNoise( ({"creatures", "chatter", "chattering"}),
"Small animals can be heard in this area of the forest. You wonder what "
"they are saying and hope it's not about you.\n");

AddNoise("chanting",
"It is unmistakable; this chanting you were told "
"about as a child. The mystical, earthy druids are well known for "
"their gatherings in the sacred Grove. You cannot understand their "
"words though.\n");

AddNoise( ({"whispering","whispers"}),
"The beautiful rose seems to be whispering about a hidden temple in the "
"forest. No one searching for it has ever returned. When you lean in "
"to listen to its exact whereabouts, all of the flowers huddle together "
"and ignore you.\n");

AddNoise("moaning",
"The beeches moan seductively to the oaks in higher tones and pitches. "
"Their songs bring you to tears, while the oaks' bellowing wakes you "
"from the bewitching.\n");

AddNoise("bellowing",
"Almost like rowdy laughter, the oaks cover the lower baritones of the "
"forest. They create a 'samesong' to compliment the cooing of the "
"beeches, which are becoming more and more enrapturing.\n");

SetIntSmell (
"There is a hint of spices in the air to the northeast. The bloom of "
"flowers also catches your attention. Is that a rose you smell?\n");

AddSmell ("rose",
"This is one of the most incredible roses you have ever smelled. Its "
"fragrance is as powerful as a lilac and as soft as talcum. The intensity "
"of the rose is magical and surreal. You wish you could breathe it in all "
"day.\n");

AddSmell ("spices",
"The spices are very pungent and your eyes water at their scent.\n");

Set(P_NOWAY_MSG,
    "The trees' frenzied dance catches your attention and you forget "
"your desire to move on.\n");

  AddExit("north","./forestb6");
  AddExit("south","./forestd6");
  AddExit("west","./forestc5");
  AddExit("east","./forestc7");

}
