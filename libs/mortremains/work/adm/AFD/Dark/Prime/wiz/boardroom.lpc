#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set ("short", "The Receiving Hall of the Palace of the Dark Ones");
  set("long", @ENDLONG
You are inside the receiving hall of the Palace of the Dark Ones. 
Great basalt arches support a gigantic domed ceiling, which is in turn
tiled in intricate murals depictng ancient, black-robed beings in the
process of creation and destruction, their faces hidden in the mists
of obscurity. Hundreds of blood-colored spheres of light hover
menacingly overhead, each one emitting some fragment of an unholy
chorus - with the whole being unnerving enough to unsettle Bravery
himself.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "out" : BOARDS(domains),
  "down" : WIZ(necro_room),
  ]) );
  call_other(OBJ(dark_board), "frog");
  ::create();
  reset();
}
