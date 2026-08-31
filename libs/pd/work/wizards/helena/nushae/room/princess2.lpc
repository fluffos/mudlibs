#include <std.h>
#include <nushae.h>

inherit ROOM;

void create() {
  ::create();
    set_properties((["light" : 2, "night light" : 2, "indoors" : 1]));
    set_short("Princess Tower");
    set_smell("default", "Perfume and Flowers are very strong here.");
    set_listen("default", "The high pitched voices of women is very noisy.");
    set_long("Further along this corridor, the colours have become brighter, and the amount of guards and knights lessen to make room for more servants. Princess Luti's bed chamber is at the very top of her tower, while her treasures are placed elsewhere up and down her tower.");
    set_items((["corridor" : "Covered from floor to ceiling with bright colours that blind the eye, its all very girly.", "floor" : "Soft as silk, yet bright enough to shock the numbest mind.", "colours" : "Pink, peach, sky blue, pine green, red, orange, and other girly colours can be seen here."]));
    set_exits( (["south" : ROOMS"princess1", "east" : ROOMS"princesstower5"]) );
}

void reset() {
  ::reset();
    if(!present("knight")) {
      new(MOB"merknight")->move(this_object()); }
    if(!present("servant")) {
      new(MOB"mmerserv")->move(this_object());
      new(MOB"merserv")->move(this_object());
    }
}
