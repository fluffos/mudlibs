//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "康亲王书房");
	set("long", @LONG
这里是康亲王书房，房中书架上整整齐齐地堆放着很多书。不过书上
积了一些灰尘，显然是很久没有动过了。而书橱里的几件精巧玉器却更显
得玲珑剔透，光彩照人。
LONG );
	set("exits", ([
		"south" : __DIR__"neitang",
	]));
	set("objects", ([
		"/d/city2/npc/kang" : 1,
	]));

	setup();
	replace_program(ROOM);
}

