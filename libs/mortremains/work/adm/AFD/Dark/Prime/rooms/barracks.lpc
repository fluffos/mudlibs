#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  seteuid(getuid());  // need this line if your gonna clone anything.
  set( "light", 1 );
  set ("short", "Cyanide's Crack Factory");
  set( "long", @EndText
A room. Nuff said.
EndText
  );
  set ("author", "cyanide");
  set( "exits", ([
  ]) );
  ::create(); // this also resets the room! :)
  set ("item_desc", ([
   ]) );
}

