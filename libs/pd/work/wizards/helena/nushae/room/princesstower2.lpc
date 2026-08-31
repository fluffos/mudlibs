#include <std.h>
#include <nushae.h>

inherit ROOM;

void create() {
  ::create();
    set_properties((["light" : 2, "night light" : 2, "indoors" : 1]));
    set_short("Princess Tower");
    set_smell("default", "Perfume and flowers accompanied by a musky smell.");
    set_listen("default", "The voices of chatting women starts to fade, replaced by silence.");
    set_long("Moving deeper into the basement of this tower, it is obvious that Princess Luti rarely visits here, preferring her bed chamber on the top floor. Guards and Knights love it here, however, as it is away from the chatty noise of the women.");
    set_items((["tower" : "The colour here begins to fade, the walls not repainted in a very long time.", "colours" : "Only purple, pink and blue can be seen fading on the gray stone walls."]));
    set_exits( (["up" : ROOMS"princesstower3", "down" : ROOMS"princesstower1"]) );
}

void reset() {
  ::reset();
    if(!present("knight")) {
      new(MOB"merknight")->move(this_object());
      new(MOB"merknight")->move(this_object());
      new(MOB"merknight")->move(this_object());
      new(MOB"merknight")->move(this_object());
      new(MOB"merknight")->move(this_object());
  }
}
