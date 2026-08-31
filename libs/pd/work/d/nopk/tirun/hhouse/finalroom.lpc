#include <std.h>
#include <tirun.h>

inherit ROOM;

void create() {
    ::create();
    set_smell("default", "The stench of fungus and mildew permeates the room.");
    set_listen("default", "Water drips from the ceiling of this hole.");
    set_properties((["light":1, "no teleport":1, "indoors":1]));
    set_short("Haunted House");
    set_long(
        "This tiny room contains nothing but small bones of rats, and other scraps of would-be "
        "food.  There are scratching into the the stone walls, which could be writing, but it "
        "is illegible.  Sitting in the corner is the hunched figure of what could have been a "
        "man.  Something is different about him though.");
    set_items(
        ([({"walls", "corners", "holes"}) : "The walls have small chips in them, along with tiny holes where dripping water has eroded the stone away.",
          "passage" : "The passage leads into a small, smelly room.",
          ({"writing", "scratching"}) : "It seems to be an old form of Selunian."]) );
    set_exits( ([ "east" : ROOMS"hhouse/bottom"]) );
}

void reset() {
  ::reset();
  if(!present("lomack", this_object()))
    new(ROOMS"hhouse/lomack")->move(this_object());
}
