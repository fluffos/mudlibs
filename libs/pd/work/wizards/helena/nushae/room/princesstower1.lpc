#include <std.h>
#include <nushae.h>

inherit ROOM;

void create() {
  ::create();
    set_properties((["light" : 1, "night light" : 1, "indoors" : 1]));
    set_short("Princess Tower");
    set_smell("default", "Old air and stale flowers stain this place.");
    set_listen("default", "The voices have faded into the oppressing silence.");
    set_long("This is the very bottom of Princess Luti's tower. Not many are sure what happens down here, not even the Princess herself. It is rumoured servants who did not meet her satisfaction were sent down here until she called them back...if she called them back.");
    set_items((["tower" : "Everything is old, gray and dusty here. No hope is present at all.", "walls" : "Bare, gray and depressing.", "floor" : "Inch thick with dust, as if it has not been cleaned in years."]));
    set_exits( (["up" : ROOMS"princesstower2"]) );
}

void reset() {
  ::reset();
    if(!present("servant")) {
      new(MOB"oldmerserv")->move(this_object());
      new(MOB"mmerserv")->move(this_object());
      new(MOB"merserv")->move(this_object());
  }
}
