#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
   set_property("light", 0);
   set_short("A tunnel");
   set_long("The cold and damp air seems as though it is "
            "trying to suffocate you in this horrible place. "
            "Things squirm in the walls and floor, and a dim light "
            "glows from up ahead. The tunnel is eerily claustrophobic.");
   set_items(
	([
	  "soil" : "The cold, black soil is so thick, it could muffle "
                   "any scream.",
          "air" : "Cold and damp, it adds an eerie feel to the area.",
          "dirt" : "A horrible feeling comes over you.",
          "under" : "You are six feet under.",
	  "floor" : "Squirming things burrow up through the soft dirt.",
	  "grave" : "The grave is horribly empty and sad."]));
    set_listen("default", "Faint whispers fill the air.");
    set_listen("whispers", "The words are incomprehensible, but unmistakably demonic...");
    set_exits(([
                "east" : "/d/nopk/tirun/clergy/kataan/kataan_join",
                "north" : ROOMS"cemetary/tunnel1",
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
      new(ROOMS"cemetary/mon/spirit1")->move(this_object());
}
