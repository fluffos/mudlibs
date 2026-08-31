#include <lodos.h>
#include <std.h>
inherit VAULT;

void view_door();

void create() {
 ::create();
   set_short("Within a dark prison");
   set_long("%^BOLD%^%^BLACK%^"
      "You find yourself within some sort of magical prison.. The only "
      "visable exit is to the south, but it has been blocked off by "
      "bars. The small door has been closed and locked. The walls "
      "close in about you.");
   set_items(([
      "bars" : "The bars are made of magical flame.",
      "door" : (: view_door() :),
      ({ "wall", "walls" }) : "The north wall shimmers."
   ]));
   set_exits(([ "south" : "To be determined" ]));
   set_door("door", "/d/standard/void", "south", "prison_key");
   set_locked("door", "prison_key");
   set_properties((["light" : 1, "night light" : 0]));
   set_properties((["town" : 1, "indoors" : 1, "building" : 1])); 
}

int query_quest_room() { return 1; }

int enter(string str) {
   if (!str || str != "wall") return 0;
   write("You walk through the wall.");
   this_player()->move_player(ROOMS"secret1", "north");
   return 1;
}

void init() {
 ::init();
   add_action("enter", "enter");
}

void view_door() {
   if (query_open("door")) write("It has been opened.");
   else write("The door in the bars is locked, preventing any exit.");
}

void reset() {
 ::reset();
   if (!present("prisoner"))
     make(MOB"prisoner");
}
