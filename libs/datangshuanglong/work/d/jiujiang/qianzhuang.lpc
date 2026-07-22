
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","钱庄");
  set ("long", @LONG
这里是九江著名的钱庄。这个钱庄历史悠久，信誉极高。很多人都
把钱存到这里。钱庄老板在那里热情地招呼着客人。
LONG);

  set("exits", ([ 

  "south":__DIR__"xidajie1",
        ]));
 set("objects",([
	 __DIR__"npc/qian":1,
	 ]));
  set("valid_startroom", 1);
  setup();
 
}

