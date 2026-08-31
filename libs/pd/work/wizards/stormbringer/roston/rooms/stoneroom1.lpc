#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
  ::create();     

   set_name("stoneroom1");
   set_properties(([       "light" : 2,
                     "night light" : 1,
                            "town" : 1]));
   set_short("Stone storage area.");
   set_long("A great stack of blocks dominate the area, the stack of stone is made "
            "up of large <%^BOLD%^white granite blocks%^RESET%^. The ground here is dry, no snow is evindent in this "
            "area other than the snow capped mountain peaks. Other stacks of stone blocks are to "
            "the west and south, a path leads to the east.");
   set_items(([  "blocks" : "Large %^BOLD%^white granite blocks%^RESET%^ used for building.",
	         "mountain" : "Snow covered mountains tower over this valley.",
                 "ground" : "The ground underfoot is strangely void of all moisture.",
               "building" : "A small fortified castle."]));
   set_smell("default", "Dust clouds the smell of everything in this area.");
   set_listen("default", "The sound of clanging metal reverberates throughout this area.");

   set_exits( ([ "east" : ROOMS "roston25",
                "south" : ROOMS "stoneroom4",
                 "west" : ROOMS "stoneroom2" ]));
}                                                             
  void reset() {

     if(!present("miner"))
       {
       new(MOB "miner")->move(this_object()); 
       }

