#include <std.h>
#include <nushae.h>

inherit ROOM;

void create() {
  ::create();
    set_properties((["light" : 2, "night light" : 2, "indoors" : 1]));
    set_short("Princess Tower");
    set_smell("default", "Perfume and Flowers are very strong here.");
    set_listen("default", "The high pitched voices of women is very noisy.");
    set_long("Moving up the tower, the colours seem to become brighter, but it is just the added sunlight shining off the walls. The floors seem softer, and the amount of people here has increased. The higher up one goes, the closer one gets to Princess Luti's bed chamber.");
    set_items((["tower" : "The tower is elegantly decorated, pretty flowers and colours spread all over the walls.", "floor" : "Soft and comfy, all who walk these floors feel comfort beyond belief.", "colours" : "Even brighter than the lower floors, possibly even blinding, pink, orange and beige can just be made out."]));
    set_exits( (["up" : ROOMS"princesstower8", "down" : ROOMS"princesstower6"]) );
}

void reset() {
  ::reset();
    if(!present("guard")) {
      new(MOB"guard")->move(this_object());
      new(MOB"guard")->move(this_object()); }
    if(!present("knight")) {
      new(MOB"merknight")->move(this_object());
      new(MOB"merknight")->move(this_object()); }
    if(!present("servant")) {
      new(MOB"merserv")->move(this_object());
      new(MOB"mmerserv")->move(this_object());
  }
}
