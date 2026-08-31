
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
    "Large windows take up most of the eastern and western walls, allowing "
    "easy viewing of both the town and surrounding forest. A long rack of "
    "hunting knives, bows, and filled quivers sits next to the door. Two "
    "low pallet beds lie along the southern wall. In the center of the room, "
    "a table sits alone."
  );
  set_items(([
    "windows" : "The windows let in light at all times of the day.",
    "rack" : "The rack is obviously handmade, but there is no ornamentation.",
    ({ "knives", "bows", "quivers" }) : "The equipment all seems to be for "
      "hunting.",
    "beds" : "The beds are quite plain, grass-stuffed mattresses raised "
      "off the ground for protection from cold and wet.",
    "table" : "The table has several compartments made into it. Most are "
      "closed, but one open one seems to have some dried berries in it. "
      "Food storage, apparently."
  ]));
  set_exits(([
    "out":VPROOMS"town15_8"
  ]));
  load_object(query_exit("out"));
  set_inventory( ([
    MOBS"satyr" : 2,
  ]) );
}

void reset() {
  ::reset();
}
