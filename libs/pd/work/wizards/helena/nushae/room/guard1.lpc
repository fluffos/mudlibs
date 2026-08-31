#include <std.h>
#include <nushae.h>

inherit ROOM;

void create() {
  ::create();
    set_properties((["light" : 2, "night light" : 1, "indoors" : 1]));
    set_short("Guard Tower");
    set_smell("default", "The smell of armour and sweat is strong here.");
    set_listen("default", "The shuffle of armour when a guard moves can barely be heard.");
    set_long("The guard tower is obviously a place of work, not rest or play, as there are no tables, chairs, or even floor mats here. Only four wide windows allowing the viewer to see in all directions and a large bell are here.");
    set_items((["window" : "All of NuShae can be seen from these windows, from the farms to the mines to the beds. Even the four towers of the Palace can be clearly viewed from here.", "bell" : "The bell is a warning bell for when NuShae used to be the enemies of many people. It is now so old it will not ring."]));
    set_exits( (["down" : ROOMS"pentrance"]) );
}

void reset() {
  ::reset();
    if(!present("guard")) {
      new(MOB"guard")->move(this_object());
  }
}

void init() {
  ::init();
    add_action("ring", "ring");
}

int ring(string str) {
  if(str)
  if(str != "bell") return 0;
    write("You try to ring the bell, but nothing happens.");
    return 1;
}
