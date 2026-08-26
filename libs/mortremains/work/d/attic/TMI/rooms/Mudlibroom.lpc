// config.h only included here for the defines of START and VOID
// it doesn't need to be included in most rooms.
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
  set( "short", "The Mudlib room" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
This is the Mudlib room. Post any questions related to mudlib
issues here.
EndText
  );
  set( "exits", ([
  "north" : "/d/TMI/rooms/quad"
  ]) );
 call_other("/d/TMI/boards/Mudlibboard","dummy");
}
