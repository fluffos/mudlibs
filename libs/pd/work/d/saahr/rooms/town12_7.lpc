
#include <std.h>
#include <damage.h>
#include <damage_types.h>
#include <saahr.h>

inherit ROOM;

int thorns_hurt();

void create() {
  ::create();
  set_properties(([
    "light":2,
    "night light":1,
    "indoors":0,
    "town":1
  ]));
  set_short("a small town");
  set_long(
    "This is a small open area with wisps of grass growing here and there. "
    "Most of the ground is packed hard from many footfalls. A path leads "
    "south toward the town center."
    "\nLong bushes spread out across the north."
  );
  set_items(([
    "bushes" : "Easily eight feet tall, they spread out to the east and west.",
    "grass" : "Scraggly bits of grass that have been stepped on often.",
    "ground" : "It is very firm dirt.",
    "path" : "A well-worn dirt road.",
  ]));
  set_exits(([
    "east":VPROOMS"town13_7",
    "south":VPROOMS"town12_8",
    "west":VPROOMS"town11_7",
    "north":VPROOMS"f12_6"
  ]));
  add_invis_exit("north");
  add_pre_exit_function("north", "thorns_hurt");
}

int thorns_hurt() {
  object tp=this_player();
  int d;
  if (!tp) return 0;
  d = tp->do_damage("none", 10+random(20), DAMAGE_PHYSICAL | DAMAGE_PIERCE,
                    DAMAGE_BYPASS_ARMOUR | DAMAGE_NONLETHAL, "thorns");
  if (d) {
    message("move", "%^GREEN%^Thorns %^RED%^cut you%^GREEN%^ "
                    "as you pass through the bushes.", tp);
  }
  return 1;
}

