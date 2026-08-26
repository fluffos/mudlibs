#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set ("short", "The Cabal of Necromancy Board Room");
  set("long", @ENDLONG
The Necromancer's Board Room. Feel free to post.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "up" : WIZ(boardroom),
    "west" : "/d/guild/necromancers/rooms/guild",
  ]) );
  call_other(OBJ(necro_board), "frog");
  ::create();
  reset();
}
