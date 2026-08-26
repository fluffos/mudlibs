/*
// A blank room, take it to make new rooms.
*/

#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
   seteuid(getuid());
   set( "light", 1 );
   set("short","A blank room");
   set( "long", @EndText
Just a blank template room.
EndText
  );
  set( "exits", ([
  ]) );
  set( "item_desc", ([
  ]) );
}
