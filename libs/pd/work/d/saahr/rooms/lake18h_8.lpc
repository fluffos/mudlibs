
#include <std.h>
#include <saahr.h>

inherit LAKE_ROOM;

void create() {
  ::create();
  set_day_long(
    "A small boulder peeks above the water's surface. "
    "It is smooth on top and just barely large enough for a person to hold "
    "while resting from swimming. Around it, the lake flows gently."
  );
  set_night_long(
    "Something rounded peeks up from the water here, causing waves to "
    "ripple around it. The surface of the lake is dark and there is "
    "nothing else to be seen."
  );
  set_items( (query_items() || ([])) + ([
    ({ "boulder", "something", "rounded", "something rounded" }) :
      "A small boulder that extends deep underwater, presumably to the "
      "lakebed. The top is smoothed from untold years of erosion. "
      "It peeks just inches above the water.",
  ]) );
  set_exits( ([
    "north" : VPROOMS+"lake18h_7h",
    "east" : VPROOMS+"lake19_8",
    "west" : VPROOMS+"lake18_8",
    "northwest" : VPROOMS+"lake18_7h",
  ]) );
}

