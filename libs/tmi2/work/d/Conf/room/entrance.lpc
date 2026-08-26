// Entrance lobby

#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());

  set( "light", 1 );
  set( "short", "Conference entrance lobby" );
  set( "long", wrap(
"TMI welcomes you to the conference. "+
// "If you are new, type \"help conference\""+
" The central meeting point is just to the north."+
  "" ) );
  set( "exits", ([
    "out" : "/d/TMI/tower1",
    "north" : "/d/Conf/room/centre",
  ]) );
}
