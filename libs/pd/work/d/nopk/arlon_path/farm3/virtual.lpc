#include <std.h>
#include <arlonpath.h>

inherit VIRTUALMAP;

void create() {
  set_mapfile(FARM3+"map");
  set_descfile(FARM3+"descs");
  set_compact(1);
  ::create();

set_special_exits("0,0,0", ([ "west" : FARM3+"room/farmyard" ]) );
}
