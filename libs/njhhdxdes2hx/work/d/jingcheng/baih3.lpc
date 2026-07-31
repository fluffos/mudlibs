// Room: /d/jingcheng/baih3.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m白虎大街[2;37;0m");
	set("long", @LONG
  这里是青龙大街的北段，西边是一家武馆，隔着墙也能听到里面哼
哈的练拳。南方是青龙大街和玄武大街的十字路口。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qinshi" : 1,
]));
	set("outdoors", "city");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"xw7",
  "east" : __DIR__"mzh3",
]));

	setup();
}
