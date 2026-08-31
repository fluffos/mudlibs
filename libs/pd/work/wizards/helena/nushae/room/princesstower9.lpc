#include <std.h>
#include <nushae.h>

inherit ROOM;

void create() {
  ::create();
    set_properties((["light" : 3, "night light" : 2, "indoors" : 1]));
    set_short("Princess Tower");
    set_smell("default", "The fragrance of flowers and perfume is overwhelming.");
    set_listen("default", "The noise caused by people chatting is intense.");
    set_long("This is the room just below Princess Luti's bed chamber. Princess Luti herself rarely leaves her bed chamber, so many people come and go from the room above. Only an exclusive few are allowed in, so Luti has special guards for her room. The walls are still colourful, and the atmosphere crowded.");
    set_items((["tower" : "The tower is elegantly decorated, pretty flowers and colours spread all over the walls.", "floor" : "Soft and comfy, all who walk these floors feel comfort beyond belief.", "colours" : "Even brighter than the lower floors, possibly even blinding, pink, orange and beige can just be made out."]));
    set_exits( (["up" : ROOMS"princesstower10", "down" : ROOMS"princesstower8"]) );
}

void reset() {
  ::reset();
    if(!present("knight")) {
      new(MOB"lutimerknight")->move(this_object()); }
    if(!present("servant")) {
      new(MOB"merserv")->move(this_object());
      new(MOB"merserv")->move(this_object()); }
    if(!present("mermaid")) {
      new(MOB"mermaid")->move(this_object());
      new(MOB"mermaid")->move(this_object());
  }
}
