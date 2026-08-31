#include <std.h>

inherit VIRTUALSERVER;

void create() {
    ::create();
    set_how_long(3);
    set_day_sentances( ({
      "The tunnels seem to go on forever.",
      "Some water drips quietly from the ceiling.",
      "Some rats scurry past you from the violation of there home.",
      "An old, rusted torch holder is stuck on the wall.",
      "A puddle of water covers the floor from the leaks in the ceiling.",
      "The walls are smooth and are cut from fine stone.  In some spots "
        "the occational pictograph is on the wall.",
      "The stone hallway is black.  It looks as if fire has ravaged though "
        "the tunnels recently."
      }) );
    set_night_sentances( ({
      "The tunnels seem to go on forever.",
      "Some water drips quietly from the ceiling.",
      "Some rats scurry past you from the violation of there home.",
      "An old, rusted torch holder is stuck on the wall.",
      "A puddle of water covers the floor from the leaks in the ceiling.",
      "The walls are smooth and are cut from fine stone.  In some spots "
        "the occational pictograph is on the wall.",
      "The stone hallway is black.  It looks as if fire has ravaged though "
        "the tunnels recently."
      }) ); 
    set_item_list(([ ({ "torch holder", "holder" }):"It is rusted.  There isnt a "
        "torch in it.",
      ]));
    set_properties( ([ "light" : 0,
        "night light" : 0,
        "indoors" : 1,
        "underground" : 1,
      ]) );
    set_short("large, underground tunnels");
}


