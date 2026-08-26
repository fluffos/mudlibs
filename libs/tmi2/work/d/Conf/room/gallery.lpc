// The spectator gallery.
// Written by Mobydick@TMI-2
// 2-1-93

#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
   set ("short", "The observation gallery") ;
   set ("long",
"This is the hallway leading to the observations rooms. The four exits are\n"+
"A, B, C, and D, and lead to rooms where you can observe the meeting room\n"+
"of the same letter.\n") ;
  set( "exits", ([
    "east" : "/d/Conf/room/centre",
    "A" : "/d/Conf/room/spec_roomA",
    "B" : "/d/Conf/room/spec_roomB",
    "C" : "/d/Conf/room/spec_roomC",
    "D" : "/d/Conf/room/spec_roomD",
  ]) );
}
