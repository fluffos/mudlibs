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
"Ushered in by magical, invisible forces, you have entered the "
"the haunting Grove of the Druids. All druidic rituals occur "
"here, in the calming silence of nature. Surrounded by the "
"largest of all the oaks in the forest, a ring guards the "
"druids in safety. The trees are extremely protective of the "
"grove. When the light is too bright, the trees huddle together. "
"For those with evil intent, the trees prevent entry into the "
"sacred Grove. Known for their love of nature, the druids have "
"remained here for centuries in secret; creating, valuing, and "
"worshipping the earth. This place is the center of where all "
"life began. As a result, everything is in bloom here, from "
"the grass to flowers to bushes to trees. All is alive here "
"and glowing with a wondrous and fascinating sheen. Herbs "
"and spices are intensely odorous here, being ground and "
"prepared for spells. Chanting is overpowering and intimidating. "
"You could stand here in awe for days, just absorbing, with "
"all of your senses, the beauty of this enchanted place.\n"
"To the south, is the actual Guild of the Druids. There, if you "
"are truly dedicated and strong of the soul, you can learn the "
"ways of the druids and become one.\n");

  AddDetail("forest",#'IntLong /*'*/);


AddDetail( ({"trees", "tree"}),
"The trees that form the circle of this grove are large, ancient oaks. "
"These trees are rumored to have been here since the birth of the world. "
"Looking up, you stare off almost into the heavens before the trees end "
"their journeys.\n");

AddDetail( ({"oaks", "oak"}),
"Not an acorn hits the ground from these oak trees. They look petrified "
"in their state of perfection, rich and thriving. Their green leaves "
"reach out to tickle you. The trees smile at you, with wise eyes. Their "
"voices reach within your soul and massage it gently until you feel "
"inner peace. This is the way of the oaks. This is the way of the "
"druids. Walk with the oaks, and you walk with life.\n");

AddDetail( ({"ring", "fairy ring"}),
"The ring of trees around the Grove is very odd and breath-taking. "
"Some mystical forces must have prevented trees from growing in the "
"clearing. More than likely, it was the power of druidic magic. The "
"ring is full of flowers of every array.\n");

AddDetail("clearing",
"The clearing in the middle of the grove is where the druids meet "
"for ritual. It is heard that the druids form a circle and chant "
"until all magic is released into the air. Anyone who is not a "
"druid is forbidden to see such magic in performance, though. "
"The clearing, now, looks very inviting for a nap, or just a "
"rest to enjoy the beauty of the mysterious grove.\n");

AddDetail( ({"wildflowers", "flowers"}),
"It is as if a florist made a delivery here. Every form of posy, bud, "
"and bloom grows here, caressing the grass with its own charm. You "
"spy, in the middle of all of these amazing flowers, one that embraces "
"the beauty of all of them. Resembling an orchid, this flower at "
"first glance appears an ivory color. At second glance, though, it "
"bursts with a explosion of color.\n");

AddDetail("orchid",

"This beauteous and innocent flower flourishes with the life of all "
"flowers. You have an intense need to pluck it from its home, but "
"for the fear of destroying the peace of the garden and the life of "
"the blossom, you avoid the temptation.\n");

AddDetail("bushes",
"The bushes grow in my different sizes here, and they fill most of the "
"empty spaces below the oaks. They are the Helpers of the Guardians "
"and protect where the oaks are unable. Many of the bushes are boasting "
"delicious-looking berries. Do the druids use them in their practices?\n");

AddDetail("berries",
"The berries cover the bushes with their plentiful colors. Just looking "
"at them makes you hungry.\n");

AddDetail("grass",
"The thick, bushy grass is soft for the bare-footed druid. Your own feet "
"sink into its verdant pillows.\n");

AddDetail("south",
"To the south, you spy the Druid's Guild. If you are interested in "
"joining the group, that is the direction to travel.\n");

AddDetail("magic",
"The magic of this place is unique. It sends chills and bolts of "
"lightning down your back. Even as just a visitor, the magic steals "
"the heart and makes it its own, ravaging and enrapturing it. Still, "
"you realize this is only a partial fraction of what the true druid "
"must feel when spell-casting. As marvelous as it is miraculous, "
"magic has invaded your soul.\n");

AddDetail("aura",
"A cloud hangs around you, much like a blanket. This aura permeates "
"beyond the druid's grove, but in encompasses the grove like the "
"oaks encompass the forest. No one would miss the aura, but no one "
"can explain it either.\n");

SetIntNoise ("You hear chanting all around you, but see no one. "
"Teeming with life, the Grove is engulfed in the sounds of all the "
"animals of the forest.\n");

AddNoise("chanting",
"The pumping of the voices moving together throughout the Grove is not "
"only haunting, but unearthly. Looking around, searching for the voices, "
"you hear a singular voice. 'Search within your heart for the true "
"voice.' You swirl around, and no one is there.\n");

AddNoise("animals",
"All the animals of the wood create a symphony of life. From the "
"chirping of the birds, to the howling of wolves, each animal takes "
"part, with pride, in the music.\n");

AddNoise("voices",
"The voices of the oaks are calling to you. You can hear their own "
"chanting over the druids. It is in an ancient language only your "
"heart recognizes. Soaring within, you reach high to touch the "
"heavens.\n");

AddNoise("voice",
"A voice disregards the chanting of the grove to touch you. 'Reach "
"for the heavens, and you will find faith. Reach for the ground, "
"and you will find hope. Reach for your soul, and you will find "
"nature.'\n");

SetIntSmell(
"Pungent, rich herbs and spices nibble at you, while fragrant blossoms "
"flirt with your senses.\n");

AddSmell( ({"herbs","spices"}),
"Acrid to the normal traveller, these herbs and spices are as sweet "
"as candy to the druids. They largely participate in druidic magic "
"and often help, or harm, when ingested. The ones you smell now are "
"full of magic. It is even obvious to the normal creature they are "
"extremely powerful.\n");

AddSmell("blossoms",
"The flowers of the Grove are profoundly redolent. Just their scent "
"invokes a happy, joyous feeling within you. The magic of nature is "
"simple, but potent.\n");

Set(P_NOWAY_MSG,
    "The Guardian Oaks of this Grove bar your way.\n");

  AddExit("west","./forestb8");
  AddExit("south","./forestc9");

}
