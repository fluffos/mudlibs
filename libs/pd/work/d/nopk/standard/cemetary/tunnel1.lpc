#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
   set_property("light", 0);
   set_short("A tunnel");
   set_long("The cold and damp air seems as though it is "
            "trying to suffocate you in this horrible place. "
            "The soil is thick down here and muffles every sound. "
            "It is too dark to make "
            "out where you are.");
   set_items(
	([
	  "soil" : "The cold, black soil is so thick, it could muffle "
                   "any scream.",
          "air" : "Cold and damp, it adds an eerie feel to the area.",
          "dirt" : "A horrible feeling comes over you.",
          "under" : "You are six feet under.",
	  "grave" : "The grave is horribly empty and sad."]));
    set_exits(([
                "south" : ROOMS"cemetary/tunnel2",
                "north" : ROOMS"cemetary/grave",
                ]));
}

int muffle() {
   write("Your screams are muffled by the thick soil!");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
      "'s screams are muffled by the thick soil!", ({ this_player() }));
   return 1;
}

void init() {
 ::init();
   add_action("muffle", "shout");
   add_action("muffle", "scream");
}

void reset() {
 ::reset();
   if (!present("spirit"))
      new(ROOMS"cemetary/mon/spirit2")->move(this_object());
}
