// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit STD(wg_room) ;

void create() {
  seteuid(getuid());
  set("short", "On the ramparts.") ;
  set("long", @ENDLONG
You are on the ramparts of the castle wall.
ENDLONG
  );
  set_outside("Light") ;
  set("exits", ([
  "north" : ROOMS(rampart-5),
  "south" : ROOMS(swtower2),
  ]) );
  set("item_desc", ([
  ]) );
  set("objects", ([
 ]) );
  ::create();
}
