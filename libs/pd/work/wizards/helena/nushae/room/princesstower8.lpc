#include <std.h>
#include <nushae.h>

inherit ROOM;

void create() {
  ::create();
    set_properties((["light" : 2, "night light" : 2, "indoors" : 1]));
    set_short("Princess Tower");
    set_smell("default", "The fragrance of flowers and perfume is overwhelming.");
    set_listen("default", "The noise caused by people chatting is intense.");
    set_long("Women gather here in the halls, anticipating their time with the Princess Luti. A guard or two are her, but mainly they head to the lower levels of the tower, away from the noise. The colours on the walls are bright and dazzling, yet tolerable. The only exits are up towards Luti's bed chamber, or back down the tower.");
    set_items((["tower" : "The tower is elegantly decorated, pretty flowers and colours spread all over the walls.", "floor" : "Soft and comfy, all who walk these floors feel comfort beyond belief.", "colours" : "Even brighter than the lower floors, possibly even blinding, pink, orange and beige can just be made out."]));
    set_exits( (["up" : ROOMS"princesstower9", "down" : ROOMS"princesstower7"]) );
}

void reset() {
  ::reset();
    if(!present("knight")) {
      new(MOB"merknight")->move(this_object()); }
    if(!present("mermaid")) {
      new(MOB"mermaid")->move(this_object());
      new(MOB"mermaid")->move(this_object());
      new(MOB"mermaid")->move(this_object());
      new(MOB"mermaid")->move(this_object());
  }
}
