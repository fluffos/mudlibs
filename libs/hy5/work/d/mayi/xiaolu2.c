
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里条小路。一阵风吹来，卷起阵阵尘土。不时有人骑着马从你的
身旁驰过。向南望去，可以隐约看见一条宽阔的大驿道。
LONG);

  set("exits", ([
 "northwest":__DIR__"xiaolu1",
 "south":"/d/taiyuan/road6",
        ]));
  set("outdoors","mayi");

  set("valid_startroom", 1);
  setup();

}

