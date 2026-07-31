
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是个山路。东边有一座山冈，翻过山冈，就可以到九江了。西
边是一条宽敞的大路。
LONG);

  set("exits", ([ 
 "east":__DIR__"shanlu1",
 "west":__DIR__"dalu1",
       ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

