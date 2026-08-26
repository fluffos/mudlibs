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
  set( "short", "The famous Quad" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
This is the famous TMI-2 quad reincarnated.
It's a temporary zone from where people can work to various
board rooms.
to the south is the network room, where network related
topics like Intermud-3 are discussed. To the north is the
MudOS room, where driver problems can be discussed. To
the east is the Tmi-2 mudlib bug room, where you can complain
about bugs in this mudlib..
Down is Fooland.......
EndText
  );
  set( "exits", ([
   "down" : "/d/Fooland/hall",
 "east" : "/d/TMI/rooms/bugroom",
 "north" : "/d/TMI/rooms/driverroom",
  "south" : "/d/TMI/rooms/networkroom",
  "west" : "/d/TMI/rooms/archiveroom",
    "void"  : VOID,
  ]) );

call_other("/d/TMI/boards/generalboard","dsfjkdgfjksf");
reset();
}
