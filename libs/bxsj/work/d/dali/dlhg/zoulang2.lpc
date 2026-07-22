// Modify By River 98/12
inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
	set("short", "走廊");
	set("long", @LONG
这是一条走廊，两侧雕栏画砌，盘龙描凤。处处显示出这里不是寻常的地
方。北边有一条小河，河上有座小桥，似乎通向后宫。
LONG
	);

	set("exits", ([
		"north" : __DIR__"xiaoqiao",
		"south" : __DIR__"huating",
                "west" : __DIR__"dadian",
                "east" : __DIR__"xiangfang", 
	]));
	set("coor/x",-310);
  set("coor/y",-410);
   set("coor/z",-20);
   setup();
}
