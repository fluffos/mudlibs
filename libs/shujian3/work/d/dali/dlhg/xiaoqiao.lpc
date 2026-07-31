// Modify By River 98/12
inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
	set("short", "小桥");
	set("long", @LONG
这是一座很别致小石桥，桥上是缓缓的流水，水看上去很清，使人有跳下
去游泳的冲动。这里是通往后宫的必经之路。
LONG
	);

	set("exits", ([
		"north" : __DIR__"houyuan",
		"south" : __DIR__"zoulang2",
                "northwest" : __DIR__"chitang",
	]));
	set("outdoors", "大理");
	set("coor/x",-310);
  set("coor/y",-400);
   set("coor/z",-20);
   setup();
}
