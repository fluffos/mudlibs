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
  set( "short", "The MudOS driver room" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
This is the driver room where problems with MudOS (Or other drivers)
can be discussed. If you can't find the answer here, you
might want to try the Idea Exchange at imaginary.com 7890
EndText
  );
  set( "exits", ([
  "south" : "/d/TMI/rooms/quad"
  ]) );
 call_other("/d/TMI/boards/driverboard","dummy");
}
