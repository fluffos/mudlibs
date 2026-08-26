#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
set("short", "Shya's Bedroom")
set("long", @EndText
 This room is Shya's private domain.  Everything that is said and done in here stays.
On one wall you see an Ansel Adams hanging in a black frame.
On another wall there is a large picture window overlooking her winter wonderland.
Shya's bed is a king size waterbed.
There is plenty of room for fun and games among all those pillows stacked everywhere.
A vanity stands alone by the walk in closet.  Walk in and you might disappear.
EndText
  );
  set( "exits", ([
 "start" :"/d/Prime/Central/room/startroom"
workroom" : "/u/s/shya/workroom.c
  ]) );
}
