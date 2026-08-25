#include "path.h"
inherit ROOM+"baseroom";

void setup() {
set_short("Realm of the Lizard:  Musty Swamp");
set_light(60);
set_long("\nRealm of the Lizard:  Musty Swamp\n\n"
	 "     This is a dank and nasty swamp, Hard to believe "
	 "that you live here. A look around reveals nothing "
	 "but marshlands and swamp as far as the eye can see. "
	 "There are few trees and shrubs but a lot of water. There are a "
	 "couple of trails that leave here but just disappear "
	 "into the weeds. You should watch your step around here "
	 "there's no telling what kind of evil inhabits "
	 "these woods in search of souls to steal. \n\n");
add_property("no_undead",1);
add_item("tree", "Trees are almost non existant, after all it's "
	 "a swamp not a rain forest. There are some creepy looking "
	 "vines around here though, almost like they, naa, they "
	 "couldn't be alive. \n\n");
add_item("water", "The water here is nearly ankle deep everywhere. "
	 "It makes the ground soggy and soft. Who knows what lives "
	 "in the water here. \n\n");
add_item("weeds","These weeds are quite a long ways off in the distance.  As "
	 "you look closer, there are trails that lead into them.\n");
add_item("trail", "This trail is quite run down, maybe there has "
	 "been a lot of traffic here lately. \n\n");
add_exit("east",SWAMP +"lizard02","room");
add_exit("southeast",SWAMP +"lizard05","room");
}
