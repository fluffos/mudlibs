#include "path.h"
inherit "/std/room";

void setup()
{
        set_short("The Store Room.");

        set_long("This is a smallish store room where various bit of equipment is "
                "stored. Although there is alot in here, the "
                "area is still tidy and in order..even after all these years. "
                "Among the piles are various items such as sacks,shoes etc. "
                "The only bad part in here is the number of dead rats, "
                "due to the fact that the old natural poisons are still working.\n");

        add_property("no_undead",1); set_light(50);


        add_item("sacks", "These look suitable for holding smallish items..but they "
                "they are old and torn. They look like they are about to tear open.\n");

        add_item("bag", "This bag is your old grandma's  she was very fond of "
                "it and you remember her saying that it should allways stay "
                "in the family.\n");
        add_item("rats", "These are large dead diseased rodents with big teeth.\n");

        add_exit("east", PATH+"half-elf", "door");

        add_alias("sack", "sacks");
        add_alias("bags", "bag");
        add_alias("rat", "rats");
}
