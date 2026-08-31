
#include <std.h>
#include <saahr.h>

inherit LAKE_ROOM;
inherit PERIODIC;

void create() {
  lake_inheritable::create();
  periodic::create();
  set_day_long(
    "The lake opens up to the east. Blue water sparkles in the sun, "
    "reflecting the sky and trees in flowing colors. An occaisonal "
    "small wave pushes past, carrying bits of debris."
  );
  set_night_long(
    "The lake opens up to the east. Black water is lit by ghostly moonlight, "
    "reflecting the moons in eerie wavering shapes. An occaisonal "
    "small wave pushes past, carrying bits of debris."
  );
  set_exits( ([
    "northeast" : VPROOMS+"lake17_8",
    "east" : VPROOMS+"lake17_8h",
    "southeast" : VPROOMS+"lake17_9",
    "west" : VPROOMS+"river16_8h",
  ]) );
  set_period(6);
}

int periodic() {
  object *ai = all_inventory();
  ai = filter(ai, (: $1->is_monster() :) );
  foreach (object ob in ai) {
    if (random(500) < 130) {
      message("emote", ob->query_cap_name()+" swims off.",
        this_object() );
      ob->remove();
    }
  }
  return sizeof(ai ? 1 : 0);
}

