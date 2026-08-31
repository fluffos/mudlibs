#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "west" : VPROOMS "p23_16",
    "east" : VPROOMS "p25_16"
  ]));
}

void reset() {
  ::reset();
  if (!sizeof(children(MOBS+"meanbunny")))
    new(MOBS+"meanbunny")->move(this_object());
}

