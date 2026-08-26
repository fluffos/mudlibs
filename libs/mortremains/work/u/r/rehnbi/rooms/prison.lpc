#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
set( "light", 0);
set("short", "A Jail");
  set("long", @ENDTEXT
You cant find any exits!!!
ENDTEXT
);
  set( "exits", ([
  ]) );
  set("item_desc", ([
 ]) );
}


