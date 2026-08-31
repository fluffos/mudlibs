
#include <std.h>
#include <saahr.h>

inherit VAULT;

void create() {
  ::create();
  set_properties(([
    "light":2,
    "indoors":1,
    "town":1
  ]));
  set_short("inside a house");
  set_long(
    "The inside of this cabin is spacious, but warm. Opposite from the door, "
    "a wall reaches almost to the ceiling, dividing the sleeping area from "
    "the rest of the house. Along the west wall is a small bookshelf and a "
    "table with chairs. The cooking area comprises a large black cast-iron "
    "stove and several tiers of shelves, mostly full, which are spread along "
    "the east side. In the center of the cabin lies a thick fur rug."
  );
  set_items(([
    "door" : "The door is made of thick logs lashed together tightly.",
    "wall" : "There is a dividing wall, an east wall, and a west wall.",
    "dividing wall" : "Thinner than the outer walls, but thick enough "
      "to keep sleepers insulated from cold and noise.",
    "east wall" : "It is mostly covered by the cooking shelves and stove.",
    "west wall" : "A window lets in light for afternoon reading at the "
      "table situated beneath it.",
    "window" : "The windows in the west and south walls keep the house "
      "well-lit during the day.",
    "bookshelf" : "There are a couple dozen books lined up neatly along "
      "the bookshelf's two rows.",
    "books" : "Leatherbound volumes that appear to be mostly fiction, "
      "though there are a few books on cooking and housekeeping.",
    "table" : "A large, smooth wooden table for eating and gathering.",
    "chairs" : "The chairs appear to be handmade from wood.",
    "stove" : "It has a wide, flat top for cooking. Several small "
      "knobs and designs on the front serve as decoration, or for "
      "opening the fire door.",
    "shelves" : "The shelves in the cooking area are long and packed "
      "with spices and dried foods.",
    "rug" : "The rug has been expertly stitched together from several "
      "bear skins, creating a subtle shift of brown from one side to "
      "the other.",
  ]));
  set_exits(([
    "out":VPROOMS"town13_8"
  ]));
  load_object(query_exit("out"));
}

void reset() {
  ::reset();
  if (!present("nymph"))
    new(MOBS"nymph")->move(this_object());
  if (!present("satyr"))
    new(MOBS"satyr")->move(this_object());
}

