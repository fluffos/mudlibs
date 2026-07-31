//houyuan.c
//Csl 2000.04.26

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "后院");
        set("long",@LONG
这里是薛府的後院，打扫的非常干净，错落有序的放着几把藤椅。北边是
一个花园，种植着各种花草，南边是侧廊。
LONG
        );
	set("outdoors", "襄阳");
        set("exits",([
		"north"   :  __DIR__"huayuan",
		"south"   :  __DIR__"chelang2",
	]));

	setup();
}
