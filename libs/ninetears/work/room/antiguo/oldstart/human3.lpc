#include "path.h"
inherit "/std/room";

void setup()
{
        set_short("Storeroom");

        set_long("This is a Small, Low ceilinged storeroom. In one corner "
                "you see a small sack, although if you will ever get to it "
                "through all the debris will be a suprise. Among the debris "
                "various shiny items, but you do not know exactly what.\n");
                                                       
        add_property("no_undead",1); set_light(80); 

        add_item("Ceiling", "This is darkened due to it's old age.\n");

        add_item("Sack", "This is a small sack which looks old but strong.\n");

        add_item("Debris", "This is dirty dust, what did you expect ?.\n");

        add_item("Shiny items", "These are apparently equipment, but a search "
                " would take a while you think.\n");
                                                    
        add_exit("east", PATH+"human", "door");
}
