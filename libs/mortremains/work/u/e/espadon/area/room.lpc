
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
set( "short", "Entry to barracks" );
  set( "long", @EndText
You have entered an empty army barracks. There are several makes
of weapon hanging on the walls. A shelf below the weapons has
a tiny, glowing object.
EndText
  );
  set( "exits", ([
    "start" : START,
    "void"  : VOID,
    "workroom"  : ~/area/workroom.c,
    "workroom"  : ~/area/workroom.c
  ]) );
}
