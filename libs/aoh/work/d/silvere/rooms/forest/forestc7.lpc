#include <rooms.h>

/* 			This file was created by Aldrana.	*/
/*				    5/21/98 			*/
/*  If you have any questions, please mail Aldrana or Softbyte. */
/***	   Remember, courtesy is the key to creativity!       ***/
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

"As you move further away from the Druid's guild, you find the forest "
"more peaceful, as well as charming. The oak trees no longer stand "
"at attention, and all the flowers seem to tease the bushes, by "
"dancing in circles. Never have you seen a place more alive. There "
"still remains a mystical aura, but it is not strong or dangerous. It is "
"soothing, promising you the chance to rest from your weary "
"journeys. Do not stray from your path, though. True, the forest does "
"glow with serenity, but it hides its sharp edges from you to lure you "
"in. Remembering this, you notice a circle of stones on the ground, "
"amidst the wavy grass and pungent flowers.\n");
  AddDetail("forest",#'IntLong /*'*/);


AddDetail( ({"trees", "tree"}),
"The trees stand lazily, relaxing in the bright sun. "
"When the darkness falls, and the platinum flecks open in the "
"sky, the trees glow with an equal radiance, which almost "
"surpasses the beauty of its sister. The branches stretch for a "
"fleeting moment, yawning for simplicity. The oaks do not "
"seem magical here, but restful.\n");

AddDetail( ({"oaks", "oak"}),
"When oak trees are not emanating their regal or impeding "
"status, they are swaying to music only heard in the forest. "
"Straining your ears to hear this music, you almost miss "
"the oaks fading into naps. How could trees grow tired like "
"those who roam the streets of Silvere?\n");

AddDetail( ({"wildflowers", "flowers",}),
"As always, the flowers appear to be enjoying themselves "
"more than any other creature or plant life could. They dance "
"and giggle constantly, drawing you in. Some are a vivid violet, "
"such a royal and appropriate color for the flowers. Others are "
"a pale whitewash, made only for those who are more refined. "
"The most significant beauties here, though, whisp themselves "
"with swirls of periwinkle, cornflower, and a vibrant yellow. "
"You have never seen them before and instantly reach over to "
"breathe them in.\n");

AddDetail("bushes",
"How peculiar! One of these bushes is in the shape of an arrow! "
"It seems to be pointing south. As you wonder what could "
"possibly be south, another bush forms into a word. As you "
"squint to make the word out, 'H-E-A-L-E-R' pops into your "
"mind. If the presence of magic did not make itself known yet, "
"it certainly did in this instance!\n");

AddDetail("dew",
"Dew twinkles on the dancing flowers, creating a magical effect.\n");

AddDetail("aura",
"Stronger now than before, you sense and almost see a transparent "
"film covering the forest. The aura protects the place from harm and "
"often is the topic of many rumors. Those who do not understand its "
"power, and that is a lot, create stories from it, making most "
"adventurers afraid to enter its domain. However, the aura, for those "
"who can see it, is breath-taking, and absolutely beautiful.\n");

AddDetail("grass",
"More plush and green than in the rest of the forest, the "
"grass gives you a wonderful place to sit and think. "
"Its long, soft blades tickle you.\n");

AddDetail(  ({"periwinkle", "cornflower", "yellow"}),
"Not so much defined for its duty as a flower, this plant is "
"truly detailed by its colors. The boundaries of a 'flower' make "
"it beautiful, which it is, fragrant, which it is, but also limit "
"it to being just a plant. From the energy coming from the "
"little group, it could be ventured to say that these were "
"mystical beings. Leading the dance of the flowers, they "
"don't dance, but breathe. With each inhale, they bloom, "
"and when they exhale, they close up and create another "
"type of bud. Your utmost desire is to touch them, as they "
"look like a rare form of silk, though breathing them in "
"is just as tempting.\n");

AddDetail( ({"stones", "circle"}),
"This set of round and smooth stones is very out of place "
"in the forest. As if it had been placed there, centuries ago, "
"The flowers and grass grow around it, but never touch its "
"cold exterior. What could be the meaning, the origin of this?\n");

SetIntNoise(
"The sounds of the Druids to the northeast actually dissipate from here. "
"The most significant things you hear are actually the sounds of nature. "
"The wind whisks it way through the trees, which follow along in sway. "
"Flowers giggle, while the birds chirp right back. Animals of every walk "
"flock here. With all the sounds you hear, it's amazing you can "
"differentiate between them.\n");

AddNoise("giggling",
"If you never thought you would ever hear a flower laughing, then "
"perhaps a sanity check is crossing your mind. But it's true! The little, "
"bright buds are giggling at this very moment. You look around to see "
"what they're laughing at, hoping it's not you.\n");

AddNoise("birds",
"*Chirp!* *Chirp!* *Chirp!*\n");

AddNoise("animals",
"You can hear them, but you really can't see them. You wonder if you're "
"being watched by some of the most ferocious animals in Silvere, and "
"they're just waiting for the right time to jump for the kill.\n");

AddNoise("nature",
"Are you serious? You want to listen to nature? Well . . .  I "
"guess you could.\n");

AddNoise("wind",
"The answer, my friend, is blowing in the wind. . .  "
"The answer is blowing in the wind.\n");

SetIntSmell (
"Ah, the fragrance of the gorgeous flowers pleases you, "
"while the soft scent of grass makes you sigh with contentment. "
"Ultimately, there is nothing but comfort in what you take in.\n");

Set(P_NOWAY_MSG,
 "Trees and flowers alike invite you to stay and enjoy their company. "
"In other words, you're not leaving that way.\n");



AddExit("north","/forestb7");
  AddExit("south","./forestd7");
  AddExit("west","./forestc6");

}
