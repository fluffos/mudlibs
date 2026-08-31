
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
    "The four walls of this little one-room house are decorated "
    "with pictures and hangings. A large stove sits in the middle "
    "of one wall with shelves on either side. In a corner opposite, "
    "a modest bed stands a good ways off the floor."
  );
  set_items(([
    "walls" : "They're plain wood decorated with pictures and hangings.",
    "pictures" : "Paintings, really, they depict various nature scenes:\n"
      "A sunny valley, a grassy plain, and a thick copse of trees.",
    "hangings" : "There are two long hangings covering different walls. "
      "One has a woven scene of birds and squirrels, the other is just "
      "a colorful pattern of green and yellow.",
    "stove" : "A black cast-iron stove.",
    "shelves" : "Full of various spices, a fair amount of salt, and "
      "some food.",
    "corner" : "The corner is taken up by the bed.",
    "bed" : "A modest bed with a wooden frame and a green blanket.",
    "floor" : "The floor is just planks of wood."
  ]));
  set_exits(([
    "out":VPROOMS"town9_8"
  ]));
  load_object(query_exit("out"));
}

void reset() {
  ::reset();
  if (!present("nymph"))
    new(MOBS"nymph")->move(this_object());
}

