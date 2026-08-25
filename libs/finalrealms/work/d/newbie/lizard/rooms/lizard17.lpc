/* Added by Galvin 95-05-02 */
#include "path.h"
inherit ROOM+"baseroom";

void setup()  { my_setup();
set_short("Realm of the Lizard:  Musty Swamp");
set_light(60);
set_long("\nRealm of the Lizard:  Musty Swamp\n\n"
"     You have to move very slowly now. The mist is getting thicker and "
         "more humid by the moment. A wrong step and you might end up in a "
         "quicksand or worse. Not much can be seen through the mist except"
         " the nearest trees and the path you're following. \n\n");
add_property("no_undead",1);
add_item(({"tree","trees",}), "These gnarled trees are covered with the usual"
         " swampmoss that seems to grow everywhere and on everything. \n\n");
add_item("mist", "The mist is everywhere and distorts every sound and shape. "
         "You see strange shapes moving around you. \n\n");
add_item("shapes", "Some things are best left unknown. \n\n");
add_item("path", "The path is still visible for your trained eyes. Noone has "
         "used it for quite some time you decide. \n\n");
add_exit("east",SWAMP +"lizard18","room");
add_exit("southwest",SWAMP +"lizard21","room");
}
