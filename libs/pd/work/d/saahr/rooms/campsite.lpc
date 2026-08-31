#include <std.h>
#include <saahr.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 1, "indoors" : 0, "forest" : 1]));
  set_short("A small campsite in the forest");
  set_day_long("Trees tower over you in all directions. There is a small "
    "clearing here. Most of the stray leaves have been brushed away, and a "
    "firepit is near the center. Sunlight shines down brightly from overhead.");
  set_night_long("Trees tower over you in all directions. There is a small "
    "clearing here. Most of the stray leaves have been brushed away, and a "
    "firepit is near the center. Moonlight illuminates the area.");
  set_items(([
    ({"tree","trees"}) : "Very tall and with thick leaves, more trees "
      "are visible as far as the eye can see.",
    "leaves" : "Thick, green, and roughly diamond-shaped leaves.",
    "clearing" : "A roughly oval area without trees, covered lightly "
      "by short grasses.",
    ({"grass","grasses"}) : "Small clumps of brown and green grass dot the area.",
    ({"pit","firepit","center","middle","stones","ring"}) : "The middle of "
      "the clearing is taken up by a ring of stones obviously meant to surround a fire.",
    "sunlight" : "The sun lights up the entire clearing.",
    "moonlight" : "The moons fill the clearing with an eerie pale light."
  ]));
  set_listen("default", "A light breeze blows through the treetops.");
  set_exits(([ "west" : VPROOMS "f21_7" ]));
}

void reset() {
  ::reset();
  if (!present("cloaked robber"))
    new(MOBS "robber1")->move(this_object());
  if (!present("fat robber"))
    new(MOBS "robber2")->move(this_object());
}
