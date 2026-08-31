#include <std.h>
#include <arlonpath.h>

inherit VIRTUALMAP;

void create() {
  set_mapfile(FARM1+"map");
  set_descfile(FARM1+"descs");
  set_compact(1);
  ::create();

set_special_exits("0,0,0", ([ "west" : "/d/nopk/tirun/beach/9,4,0" ]) );
set_special_exits("22,30,0", ([ "south" : "arlon_entrance" ]) );
}
