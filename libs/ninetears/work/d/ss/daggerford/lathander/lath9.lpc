#include "path.h"
inherit "std/room";

setup()
{
set_light(100);
set_short("temple");
set_long("You are standing at the front of the temple, on the main aisle "+
        "which runs down the center.  To either side of you are rows of "+
        "wooden benches for use by parishoners.  A large glass window "+
        "dominates the eastern wall to the point where you are not sure "+
        "if there is a wall.  The aisle continues up a small set of steps "+
        "to the pulpit to the east of here.\n");

add_exit("north", ROOM+"lath8", "corridor");
add_exit("south", ROOM+"lath10", "corridor");
add_exit("west", ROOM+"lath6", "corridor");
add_exit("east", ROOM+"lath11", "corridor");
//modify_exit("east", ({"function", "go_east"}) );
add_alias("pew", "pews", "bench", "benches");
add_item("benches", "These are simple wooden benches.  They aren't "+
        "exceptionally comfortable, but the do provide a place to sit "+
        "during a service.\n");
add_item("window", "The glass seems to be of exceptional quality, "+
        "especially considering its size.  You wonder how they made such "+
        "a large piece of glass, as it seems to be one solid sheet, rather "+
        "than a number of separate panes.\n");
add_item(({"steps", "pulpit"}), "You can walk up the steps to have a closer "+
        "look at the pulpit.\n");
set_zone("lathander");
}

int go_east()
{
 object *obs;
 int c;

 obs = all_inventory(this_player());

 for(c=0; c<sizeof(obs); c++)
   if((string)obs[c]->query_short() == "Lathander robe" && obs[c]->query_worn())
       return 1;

 write("You take a step forward, but an intense flash of light forces you "+
       "to retreat.\n");
 say(this_player()->query_cap_name()+" tries to walk east, but is repelled by "+
    "an intense flash of light.\n");
 tell_room(this_object(), "A deep masculine voice booms:  You may not proceed "+
    "since you aren't properly attired !\n"); 
 notify_fail("Your vision clears from the flash.\n");
 return 0;
}
