/* Added by Galvin 95-06-18 */
#include "path.h"
inherit ROOM+"baseroom";

void setup()  { my_setup();
set_short("Realm of the Lizard:  Town");
set_light(60);
set_long("\nRealm of the Lizard:  Town\n\n"
	 "     You're walking on the road that serves as main street in "
         "this village. To the south you spot a grey stone structure."
         " Laughter and singing can be heard out and quite a "
         "big crowd seem to enjoy themselves inside. A group of "
         "buildings can be seen farther down the road to the west. "
         "The wooden palisade surrounding the village follows the road "
         "towards one of the gates. A few lizard-men walk around, most "
         "of them entering the building or leaving it. \n\n");
add_property("no_undead",1);
add_item("gate", "The gate lies embedded in the palisade. It's hard to "
         "discern any details from this distance. \n\n");
add_item("building","This building is a large grey building along the edge of"
	 " the street.  Inside people look like they're having a good time.\n");
add_item("palisade", "An impressive wooden fortification that "
         "completely surrounds the village. \n\n");
add_item("road", "The road is nothing more than hard-packed mud. \n\n");
add_item("lizard-men", "They walk around minding their own business. "
         "The building to the south seem to be a very popular place judging "
         "by the traffic in and out of the building. \n\n");
add_item(({"structure","tavern"}), "A large stone building with no "
         "windows. A small sign shows that this is the High Spirits "
         "Tavern. \n\n");
add_item("buildings", "A group of stone buildings stand to the west. You have"
         " to move closer to get a better look. \n\n");
add_exit("west",SWAMP +"lizard26","room");
add_exit("northeast",SWAMP +"lizard25","room");
}

void init() {
::init();
add_action("do_enter", "enter");
}
int do_enter(string str) {
   if(!str) {
	write("Enter what?\n");
	return 1;
   }
   if(str == "building") {
write("You try to enter the building, but the lizard-men at the door throw "
      "you back out into the street.\n\n");
tell_room(environment(this_player()), this_player()->query_cap_name()+" tries "
	 "to enter the building, but is thrown back into the street by the "
	 "lizard-men at the door.\n", this_player());
return 1;
}
}
