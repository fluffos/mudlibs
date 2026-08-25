/* Added by Galvin 95-05-06 */
#include "path.h"
inherit ROOM+"baseroom";

void setup()  { my_setup();
set_short("Realm of the Lizard:  Musty Swamp");
set_light(60);
set_long("\nRealm of the Lizard:  Musty Swamp\n\n"
	 "     You stumble through the thick vegetation, having a hard time to "
         "follow the almost non-existant path. Twisted trees flank the path "
         "on both sides and nasty vines hanging from the trees tries to "
         "entangle you. The dense mist is all around you, making it a lot "
         "harder to proceed than it really is. \n\n");
add_property("no_undead",1);
add_item("trees", "The trees are clad in swampmoss and twisted vines are "
         "hanging from them in multitude. \n\n");
add_item("vines", "Nasty vines hang from the trees in great numbers. They "
         "seem to be moving but it must be a trick of the light. \n\n");
add_item("mist", "It continues to harass your sight and hearing. \n\n");
add_item("path", "The path disappears and when you're about to give up "
         "looking for it, you find it again. \n\n");
add_item("vegetation", "The usual roots, shrubs and weed that grows "
         "everywhere and on everything. \n\n");
add_exit("north",SWAMP +"lizard09","room");
add_exit("southeast",SWAMP +"lizard16","room");
}
