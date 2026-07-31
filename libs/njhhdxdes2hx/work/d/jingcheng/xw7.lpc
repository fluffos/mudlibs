// Room: /d/jingcheng/xw7.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[30m玄武大街丁字路口[2;37;0m");
	set("long", @LONG
这里是玄武大街和白虎大街的丁字路口。向南走一段可以看到一座
龙王庙。京城的娱乐场所大多聚集在白虎大街的南端。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"baih3",
  "south" : __DIR__"baih2",
  "west" : __DIR__"xw6",
]));
	set("no_clean_up", 0);
	set("outdoors", "city");

	setup();
	replace_program(ROOM);
}
