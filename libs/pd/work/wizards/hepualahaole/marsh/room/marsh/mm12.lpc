#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
set_night_long(this_object()->query_night_long() + "This is an
additional sentance.");
    set_exits( ([
"south" : MARSH "mar9",
"north" : MARSH "mar17",
"northeast" : MARSH "mar18",
"east" : MARSH "mar15",
"west" : MARSH "mar13",
"southwest" : MARSH "mar8",
    ]) );
}
