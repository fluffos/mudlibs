#include <std.h>
#include <nushae.h>

inherit ROOM;

void create() {
  ::create();
    set_properties((["light" : 2, "night light" : 2, "indoors" : 1]));
    set_short("Princess Tower");
    set_smell("default", "Perfume and Flowers are very strong here.");
    set_listen("default", "The high pitched voices of women is very noisy.");
    set_long("Entering the tower of Princess Luti, nothing is different from the corridor except the exits are up and down. The colours are still bright and obviously chosen by a woman, while servants are ever present, ready to answer the loud calls of Princess Luti.");
    set_items((["tower" : "This is an elegantly decorated tower, with girly colours and features. Fit for a princess, really.", "colours" : "Pink, peach, sky blue, pine green, red, orange, and other girly colours can be seen here."]));
    set_exits( (["up" : ROOMS"princesstower5", "down" : ROOMS"princesstower3"]) );
}

void reset() {
  ::reset();
    if(!present("guard")) {
      new(MOB"guard")->move(this_object()); }
    if(!present("knight")) {
      new(MOB"merknight")->move(this_object()); }
    if(!present("servant")) {
      new(MOB"mmerserv")->move(this_object());
  }
}
