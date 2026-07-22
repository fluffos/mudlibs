// /d/tiezhang/gjfang.c

#include <ansi.h>
inherit ROOM;

void create()
{

	set("short","工具房");
	set("long", @LONG
这是一间工具房，房内显得有些破旧，墙的四角堆满了杂物，墙的一边放
着个工具架，工具架上放着各种工具，有些已经有些生锈了。房内弥漫着一股
难闻的气味，使你不仅微微皱了皱眉头。
LONG
);
	set("exits",([
		"west": __DIR__"zoulang-4",
	]));

	set("objects",([
		__DIR__"npc/xiaotong2":1,
	]));
	set("no_fight",1);
	set("no_sleep",1);
	setup();
}
