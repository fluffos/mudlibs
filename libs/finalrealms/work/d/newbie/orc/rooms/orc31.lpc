#include "path.h"
inherit "/std/outside";

void setup()
{
   add_property("no_undead",1);
set_short("Realm of the Orc:  Mountain Base");
set_light(40);
   set_long("\n   Realm of the Orc:  Mountain Base.\n\n"
            "     You are standing at the base of a small, rocky "
            "mountain.  There is a pathway that winds its way upward "
            "towards the small castle that is built at the top of "
            "the small mountain.  The small trail leads up here and "
            "returns to the valley to the southwest.  "
            "\n\n");
add_item("mountain", "\n"
"  It looks treacherous to climb. Thank the gods you have a path up.\n");
add_item("path", " The path looks MUCH safer then the rocky slopes of the mountain side.\n");
add_item("castle", "\n"
"   It looks like it is actually 'part' of the mountain. "
"It is obvious that the designers and craftmen built the "
"castle out of the surrounding rock.\n");
add_exit("southwest",CASTLE +"orc33","path");
add_exit("up",CASTLE +"orc34","path");
}
