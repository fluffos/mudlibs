
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西大街");
  set ("long", @LONG
这里是合肥的西大街。西边就是合肥的西门了。这里的行人较多。
北边是合肥的驿站，那里现在是官兵休息的地方，只见几个站岗的官兵
正在那里打盹。
LONG);

  set("exits", ([ 
  "east":__DIR__"xidajie2",
  "west":__DIR__"ximen",
  "north":__DIR__"yizhan",
 "south":__DIR__"yanju",
     ]));
        set("objects", ([
              "/clone/misc/dache" : 1,
        ]) );
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

