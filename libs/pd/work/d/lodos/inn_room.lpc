// - Inferno -  The bread and board inn =) =) =)
// NOTE: add search for a book

#include <std.h>
#include <lodos.h>
inherit ROOM;

int found;

void create() {
 ::create();
   set_short("inside Lodos Inn");
   set_long("This is a small bedroom in the Lodos Inn.  A bed sits in the middle of the room covered "
     "in a flower bed cover.  A bedstand sits beside the bed holding a wash basin.  A small cloth lays "
     "beside the basin.  A window lets some light from the outside in, but most of the comes from a "
     "small lamp on another bedstand beside the bed.");
   set_exits(([
      "out" : ROOMS"west_stairs"
   ]));
   set_items(([
     "basin" : "The basin is full of murky water.",
     "water" : "The water is really murky, looks like someone just cleaned up in it.",
   ]));
}

void reset() {
   ::reset();
   if(!present("inn_man")) new("/d/lodos/obj/mon/inn_man")->move(this_object());
}

void init() {
   ::init();
   add_action("search_basin", "search");
}

int search_basin(string s) {
   if(s != "water" && s != "basin") return 0;
   if(random(5) == 3 && !found) {
     write("After running your hands through the water, you find a key.");
     say(this_player()->query_cap_name()+" finds a key in the basin.");
     new("/d/tombar/obj/key1")->move(this_player());
     found=1;
     return 1;
   }
   write("You run your hands through the water breifly, but find nothing.");
   return 1;
}

