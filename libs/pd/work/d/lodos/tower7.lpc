#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("At the top of the tower");
   set_long("The twisting staircase ends suddenly in this room. You have "
      "reached the top of the tower, and what a view! You can see all of "
      "Lodos and several other towers, too. There are windows all over "
      "the place, letting light flow into the room.");
   set_items(([ "staircase" : "It leads down, back through the tower.",
      "towers" : "You can see a few other towers through the windows.",
      "windows" : "Windows line all sides of the walls",
      "tower" : "You are at the top of the tower"
   ]));
   set_exits(([ "down" : ROOMS"tower6" ]));
   set_properties((["light" : 3, "night light" : 2]));
   set_properties((["town" : 1, "indoors" : 1, "building" : 1])); 
}

void reset() {
 ::reset();
   if (!present("soldier")) {
     new(MOB"soldier2")->move(this_object());
     new(MOB"soldier")->move(this_object());
     new(MOB"soldier2")->move(this_object());
   }
}
