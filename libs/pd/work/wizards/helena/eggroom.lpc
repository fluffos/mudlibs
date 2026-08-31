#include <std.h>

inherit ROOM;

void create() {
  ::create();
    set_properties( (["light" : 3, "night light" : 2, "indoors" : 1, "no attack" : 1, "no scry" : 1, "no steal" : 1, "no teleport" : 1, "no bump" : 1, "no magic" : 1]) );
    set_short("Egg Hunt Waiting Room");
    set_long("This is the egg hunt waiting room. This is the place one comes when they're about to go on an egg hunt, is this not exciting? There is a sign here for your viewing pleasure.");
    set_smell("default", "Does anyone smell chocolate?");
    set_listen("default", "A faint breeze passes your ears from somewhere.");
    set_exits( (["square" : "/d/nopk/tirun/square"]) );
}

void reset() {
  ::reset();
    if(!present("sign")) {
      new("/wizards/helena/sign")->move(this_object()); }
    if(!present("guy")) {
      new("/wizards/helena/guy")->move(this_object());
  }
}
