
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
    "One entire wall of this house has been converted into shelving. "
    "The bottom shelves are completely full of lemons, while the ones "
    "on top hold a few tarts and glasses of lemonade. Behind the door, "
    "two big stoves sit side by side. Kettles sit atop each stove. "
    "In the far back corner is a bed with a chair and table beside it."
  );
  set_items(([
    ({ "shelves", "shelving" }) : "Very long shelves, there are five of "
      "them spaced evenly from floor to ceiling.",
    ({ "tarts", "glasses", "lemonade" }) : "They could be leftovers, "
      "or they could just be waiting to go outside.",
    "lemons" : "Uncountable numbers of lemons fill the two bottom shelves.",
    "door" : "A large door that swings inward. Both sides are painted yellow.",
    "stoves" : "Large black stoves with wide mouths and cooktops.",
    "kettles" : "Each one is the same size as the stovetop it sits on. "
      "One steams lightly.",
    ({ "corner", "bed", "chair", "table" }) : "It looks like the living "
      "space has been reduced to make room for cooking.",
  ]));
  set_touch( ({ "kettle", "kettles" }),
    "One is very hot, the other is cool to the touch.");
  set_smell("default", "A light citrus smell fills the room.");
  set_smell( ({ "kettle", "kettles" }),
    "One kettle smells like brewed tea, the other like lemonade.");
  set_exits(([
    "out":VPROOMS"town12_9"
  ]));
  load_object(query_exit("out"));
}

void reset() {
  object ob;
  ::reset();
  ob = present("lenna");
  if (query_night() && !ob &&
      !(ob = present("lenna", load_object(query_exit("out")))) )
	new(MOBS"lenna")->move(this_object());
}

