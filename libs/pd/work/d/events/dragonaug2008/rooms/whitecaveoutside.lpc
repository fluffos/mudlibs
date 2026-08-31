
#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties( ([
    "light" : 2, "night light" : 0, "indoors" : 0, "mountain" : 1,
  ]) );
  set_short("a mountain");
  set_long(
    "This open area has been cleared of debris and is a place where "
    "dragons often seem to spend time. "
    "A large, inviting cave opens in the side of the mountain to the east. "
    "Some shade is provided by the clump of trees atop the mesa above. "
    "This is part of a wide open area which spreads out to the south."
  );
  set_items( ([
    "cave" : "The mouth of the cave is wide and smooth. It looks large enough "
      "to hold many dragons.",
    "mountain" : "The brownish stone of the mountain has been smoothed over "
      "time so few jagged areas remain.",
    "mesa" : "A raised, flat area of rock. A clump of trees grows on top.",
    ({ "trees", "clump" }) : "The trees have taken up every available "
      "bit of space on top of the mesa. They look like spruces.",
  ]) );
  set_listen("default", "A light breeze whistles around the mountain.");
  set_exits( ([
    "east" : DRAG_ROOMS+"whitecave",
    "southwest" : DRAG_ROOMS+"common1",
    "south" : DRAG_ROOMS+"common2",
    "southeast" : DRAG_ROOMS+"common3",
    "northwest" : DRAG_ROOMS+"dragnorth28",
  ]) );
}

void reset() {
  int i = random(4);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("white dragon "+i))) {
    ob = new(DRAG_MOBS+"whitedragon");
    ob->move(this_object());
  }
}

