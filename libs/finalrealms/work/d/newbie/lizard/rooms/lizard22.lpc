/* Added by Galvin 95-06-18 */
#include "path.h"
inherit ROOM+"baseroom";

void setup()  { my_setup();
set_short("Realm of the Lizard:  Small Clearing");
set_light(60);
set_long("\nRealm of the Lizard:  Small Clearing\n\n"
	 "     This is a small clearing surrounded by a few trees. Paths "
         "lead southward to the twin gates of Backwater and farther "
         "into the swamp to the northeast. A wooden palisade is built "
         "around the small village and a building can be seen to the "
         "south. You can't help but admire the palisade, knowing that "
         "good building material are very scarce in these parts. \n\n");
add_property("no_undead",1);
add_item("trees", "Twisted trees covered in swampmoss. \n\n");
add_item("paths", "These paths are well-used except the one to the "
         "northeast which leads deeper into the dark swamp. Only the "
         "strong can survive in those parts. Are you strong enough?\n\n");
add_item("gates", "Two identical gates can be seen to the south. Move "
         "closer if you want to get a better look. \n\n");
add_item("palisade", "It's made of strong wood and as high as two "
         "lizard-men together. More than one raid from hostile "
         "lizard-men tribes have been repelled thanks to this palisade.\n\n");
add_item("building", "The building is in fact some kind of watchtower. "
         "Even though you can't see anyone in there, rest assured that "
         "you have been watched for a long time already. \n\n");
add_exit("southwest",SWAMP +"lizard24","room");
add_exit("northeast",SWAMP +"lizard19","room");
add_exit("southeast",SWAMP +"lizard25","room");
}
