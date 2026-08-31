
#include <std.h>
#include <saahr.h>

inherit LAKE_ROOM;

void create() {
  ::create();
  set_long(
    "The lake is still and clear, here in the middle. The smallest vestiges "
    "of surrounding trees can be seen in the distance in several directions. "
    "Trailing plants float just below the water's surface."
  );
  set_items( (query_items() || ([])) + ([
    "plants" : "Dark green, almost black. They have no flowers or obvious "
      "leaves. They float along slowly, spreading out to absorb as much "
      "sunlight as possible.",
  ]) );
  set_exits( ([
    "north" : VPROOMS+"lake17h_7h",
    "northeast" : VPROOMS+"lake18_7h",
    "east" : VPROOMS+"lake18_8",
    "south" : VPROOMS+"lake17h_8h",
    "southwest" : VPROOMS+"lake17_8h",
    "west" : VPROOMS+"lake17_8",
  ]) );
}

