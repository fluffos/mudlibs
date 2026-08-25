/*** By Wonderflug ***/
/*** Doing yet more domain work ***/
/*** Sojourn comforts Wonderflug ***/
/***** Taniwha just looks unbelieving *****/
#include "path.h"
inherit "/std/outside";

void setup()
{
   add_property("no_undead",1);
set_short("Realm of the Orc:  Mountain Path");
set_long("\n   Realm of the Orc:  Mountain Path.\n\n"
         "     The path widens here slightly, leading into a shallow "
         "basin to the "
  "northwest, and narrowing as it climbs back down the mountain "
  "steeply.  You can make out some more detail of "
  "multi-spired tower at the top of the mountain from here.  "
  "There appears to be a red, glowing light from the highest "
  "spire.  The reflection it makes turns the "
  "rocks around you a pale reddish color, much like blood.  Looking closer you "
  "notice that some of them are indeed covered with old dried "
  "bloodstains.  There also appear to be some dark slashes "
  "on the rocks, where deep gouges have been cut out of them, perhaps by "
  "the claws of some creature.\n\n");
 
add_item(({"rock", "rocks"}),
" \n"
"  Its rather apparent that some kind of battle occurred here. "
"Deep chips and cracks permeate the surrounding rocks. "
"But what is more baffling is the grim reddish cast to the rocks. "
"The blood of the dead and dying should have left these rocks "
"long ago but yet the rocks still appear red.\n\n");


add_item("mountain", " \n"
"  The mountain is not terribly tall but massively long. With "
"broad slopes and lacking in any form of vegetation, the "
"mountain resembles a desert of rock turned on its side."
" \n\n");

add_item(({"slashess","cracks","chip","crack","gouges"}),
"  \n"
"   On closer inspection, the red cast is actually moss. Moss grew in the "
"moist cracks and absorbed the blood as a nutrient and thus "
"giving it a 'reddish' tent.\n"
" Geezzz, aren't you a smart orc *grin of sarcasm*\n\n");
add_item("tower", " You see a multi-spired tower set on a scenic "
"mountain side over looking a town.\n");

add_item(({"spire","light"}),
" \n"
"   Looks interesting, maybe you should go check it out??\n");
set_light(40);
add_exit("northwest",CASTLE +"orc36","path");
add_exit("down",CASTLE +"orc39","path");
}
