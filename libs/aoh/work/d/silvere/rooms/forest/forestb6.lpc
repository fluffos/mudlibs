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
"As you move further away from the southeastern portion of the forest, "
"you leave the eerie druidic atmosphere and enter one of solitude. "
"Oaks begin to leave room for beautiful copper beeches which preen their "
"leaves like peacocks. Larger rocks litter the ground, possibly some "
"sort of ritualistic creation of the Druids. The ground is damp, and "
"you hear water flowing somewhere to the west. Everything in this area "
"is soft in sight and touch. Sunlight reaches for you from the west, "
"while the darkness of the east pushes you away.\n");

  AddDetail("forest",#'IntLong /*'*/);


AddDetail( ({"trees", "tree"}),
"Dabbling between oaks and beeches, the wood delights itself with much "
"mischief. Some are large and expansive, while others just delicately "
"stand, facing the sun.\n");

AddDetail( ({"oaks", "oak"}),
"They stand taller than the beeches, making them impeding and awesome. "
"They steal your breath away, enveloping you in their magic. Their "
"leaves shake themselves as a warning to you.\n");

AddDetail( ({"beech", "beeches",}),
"They are delicate and very well-groomed. Almost like sirens, they "
"bend toward you, calling you, trying to win your heart. As seductive "
"as they are shy, they moan in ecstasy and pain. Listening to the moan "
"haunts you within.\n");

AddDetail("bushes",
"The bushes disappear, leaving you only to stare at the gorgeous "
"beeches, beckoning to you.\n");

AddDetail("grass",
"The grass sways back and forth to an unheard song.\n");

SetIntNoise ("The beeches and oaks harmonize together, a seductive "
"melody, with haunting undertones. The two work beautifully together.\n");

AddNoise("moaning",
"The beeches moan constantly in this portion of the woods. Whether it "
"be that of pain or of ecstasy, it is unknown. Their strange, delicate "
"beauty charges you to hope it is pure enrapturement.\n");

AddNoise("water",
"The water is moving somewhere to the west. The water is trickling "
"faster than a stream would allow, so perhaps it is a river.\n");

SetIntSmell (
"You inhale the sweet scent of broken acorns and damp grass.\n");

Set(P_NOWAY_MSG,
    "The oaks and beeches intertwine into a wall.\n");
  AddExit("north","./foresta6");
  AddExit("south","./forestc6");
  AddExit("east","./forestb7");
  AddExit("west","./forestb5");

}
