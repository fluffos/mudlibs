#include "path.h"
inherit "/std/room";

void setup()
{
        set_short("The Store Room.");

        set_long("This is a smallish store room where various bit of equipment were "
                "stored when you were younger. Among the debris you see various sacks, "
                "bags etc. There is also a glint of metal in one corner. There is the faint "
                "scurrying of little feet..Damned them rats.\n");

        add_property("no_undead",1); set_light(70);

        add_item("glint", "These appear to be scattered arround the room. They seem to be coins which "
                "were left for future generations, should they start adventuring and need a small hand.\n");

        add_item("sacks", "These look suitable for holding smallish items..but they "
                "they are old and torn. They look like they are about to tear open.\n");

        add_item("bag", "This bag is your old grandma's.  She was very fond of "
                "it and you remember her saying that it should always stay "
                "in the family.\n");
        add_item("rats", "These are large diseased rodents with big teeth.\n");

        add_exit("east", PATH+"drow", "door");

        add_alias("sack", "sacks");
        add_alias("bags", "bag");
        add_alias("rat", "rats");
}
