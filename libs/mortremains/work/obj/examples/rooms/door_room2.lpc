// Rewritten by Chronos to demonstrate his new door code. :D
#include <mudlib.h>

inherit DOORS;
inherit ROOM;

void create()
{
  ::create();
   // Inspiral fears Root euid.  94-08-18
  seteuid( 0 );
  set( "light", 1 );
   set("short", "On the west side of a door.") ;
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
You stand on the west side of a door, in an otherwise empty room.
EndText
  );
  set( "exits", ([
  "east" : "/doc/examples/rooms/door_room1",
  ]) );

  create_door("east", "west", "A solid iron door with a narrow slit.",
  "locked", "silver_key", 23 ) ;
}
