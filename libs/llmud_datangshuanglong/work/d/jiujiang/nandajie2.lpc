
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","南大街");
  set ("long", @LONG
这里是南大街。东边是九江的衙门。现在是战乱时候，衙门也是形
同虚设，几乎没有人去那里。南边就是九江的南门了，有几个官兵正在
那里检查来往的行人。
LONG);

  set("exits", ([ 

  "south":__DIR__"nanmen",
  "north":__DIR__"nandajie1",
  "east":__DIR__"yamen",
         ]));
  set("objects",([
    __DIR__"npc/dufuwei":1,
    ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

