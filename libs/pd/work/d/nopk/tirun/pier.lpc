#include <std.h>
#include <tirun.h>

inherit ROOM;

void create()
{
 ::create();
 set_short("Tirun Docks");
 set_long("The pier extends out to the ocean. There are many ships "
                  "docked below the pier. The pier creaks from the waves. "
                "There is a small shack to the west with a sign on the door."
                " A small stairway leads down to the beach.");

 set_night_long("The pier extends out to the ocean. There are many ships "
                             "docked below the pier. The pier creaks from the waves. "
    "There is a small shack to the west with a sign upon it's door.");

 set_listen("default", "The breeze blows on you lightly.");
 set_smell("default", "The strong smell of salt water fills the air.");

set_exits( ([ "down" :  "/d/nopk/tirun/beach/0,0,0",
               "enter boat shop" : ROOMS "boatstore",
               "south" : ROOMS "pier1",
               "north" : ROOMS "sgate" ]) );
add_exit_alias("enter boat shop", "boat shop");
add_exit_alias("enter boat shop", "boat");
add_exit_alias("enter boat shop", "shop");
add_exit_alias("enter boat shop", "w");
 set_items( ([ "sign" : "We sell boats for cheap!",
	       "shack" : "It looks almost like an old poker shack." ]) );
}

int go_west() {
   if(!wizardp(this_player())) {
     write("A sign blocks the entrance to the warehouse, saying:  Closed for Repairs.\n");
     return 0;
   }
   return 1;
}
