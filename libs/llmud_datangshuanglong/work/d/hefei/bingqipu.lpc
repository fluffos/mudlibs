
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","兵器铺");
  set ("long", @LONG
这里是一家兵器铺。由于是战乱年代，所以这里的生意一直很好。
铁匠在那里忙个不停。
LONG);

  set("exits", ([ 
	  "north":__DIR__"dongdajie3",
    ]));

  set("objects",([
	  __DIR__"npc/tiejiang":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

