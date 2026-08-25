#include "path.h"
inherit ROOM+"baseroom";

void setup()  { my_setup();
set_short("Realm of the Lizard:  Musty Swamp");
set_light(60);
set_long("\nRealm of the Lizard:  Musty Swamp\n\n"
	 "     You have ventured deeper into the swamp. This is kind of "
	 "evil looking place. Why would you want to be here? "
	 "The path that was once visable is now becoming less and less "
	 "noticeable. You might want to turn back now. Who knows "
	 "what lies ahead. This place is known for it's strange "
	 "plant life. These plants don't look too bad, but it's "
	 "so dark and dank here you can't tell what's just around the "
	 "bend. You go east now or back the way you came. \n\n");
add_property("no_undead",1);
add_item("plants", "The plants here are evil looking, not the "
	 "kind of vegetation that somone would want to mess "
	 "with. \n\n");
add_item("path", "The path has almost completly diappeared now. "
	 "\n\n");
add_exit("south",SWAMP +"lizard07","room");
add_exit("east",SWAMP +"lizard04","room");
}
