
#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties( ([
    "light" : 2, "night light" : 0, "indoors" : 0, "water" : 1,
  ]) );
//  set_short("the middle of a lake");
  set_short("%^BOLD%^%^BLUE%^The lake of the Blue Dragon%^RESET%^");
  set_long(
    "%^BOLD%^%^BLUE%^The lake of the Blue Dragon%^RESET%^\n"
    "The center of the lake is a placid space. A large boulder pokes up "
    "a few feet out of the water in one spot. The sleek surface of the "
    "lake is unbroken by any leaf or twig, only the occaisonal swimmer. "
  );
  set_items( ([
    "lake" : "A clear lake nestled in the mountain. It is all around.",
    "boulder" : "The smooth boulder rises to a point, so it can't be "
      "used to rest on. There is a carving on the south face.",
    "carving" : "The carving shows a large dragon with its wings folded, "
      "as seen from above, surrounded by wavy marks.",
    ({ "water", "surface" }) : "The surface of the water is almost "
      "mirror-smooth, and allows one to see through the clear water almost "
      "to the bottom of the lake.",
    "bottom" : "It is quite far down, and just out of sight.",
  ]) );
  set_exits( ([
    "north" : DRAG_ROOMS+"lake3",
    "east" : DRAG_ROOMS+"lake5",
    "southeast" : DRAG_ROOMS+"lake7",
    "south" : DRAG_ROOMS+"lake6",
    "west" : DRAG_ROOMS+"lake4",
    "northwest" : DRAG_ROOMS+"lake2",
  ]) );
}

void reset() {
  int i = random(4);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("blue dragon "+i))) {
    ob = new(DRAG_MOBS+"bluedragon");
    ob->move(this_object());
  }

  if(!present("microphone")) {
    ob = new("/wizards/pyro/personal/microphone");
    if(ob) {
      ob->set_microphone_name(path_file(file_name(this_object()))[1]);
      ob->set_owner(DRAG_D);
      ob->set_invincible(1);
      ob->move(this_object());
    }
  }
}

