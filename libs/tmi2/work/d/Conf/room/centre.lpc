// Central gathering point.

#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());

  set( "light", 1 );
  set ("short", "The TMI-2 Conference Hall" ) ;
  set( "long", wrap(
"You are in a large, well lit dome.  This is the central gathering point."+
" The administrative lobby is to the south."+
" The bar is to the north."+
// " The voting room is to the east."+
" The spectator gallery is west."+
" The meeting rooms are in the four corners; A, B, C & D."+
  "" ) );
  set( "exits", ([
    "west" : "/d/Conf/room/gallery",
    "east" : "/d/Conf/room/conf_voting_room",
    "south" : "/d/TMI/adminrm",
    "north" : "/d/Conf/room/bar",
    "A" : "/d/Conf/room/room_A",
    "B" : "/d/Conf/room/room_B",
    "C" : "/d/Conf/room/room_C",
    "D" : "/d/Conf/room/room_D",
  ]) );
// if want can set an exit_msg
  
  call_other( "/d/Conf/boards/centre", "frog" );
}
