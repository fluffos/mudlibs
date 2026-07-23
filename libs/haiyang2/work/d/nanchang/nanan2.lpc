
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","鄱阳湖南岸");
  set ("long", @LONG
这里是鄱阳湖的南岸。这里有一座桥，可以到鄱阳湖的东岸。桥上有很
多游人在上面欣赏鄱阳湖的风光。
LONG);

  set("exits", ([ 
 "east":__DIR__"nanan1",
"northeast":__DIR__"hupao",
 "northup":__DIR__"qiao",
 "west":__DIR__"xiaolu1",
 "northeast":__DIR__"hupao",
        ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

