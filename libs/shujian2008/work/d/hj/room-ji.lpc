// room-ji.c 草棚

inherit ROOM;
#include <wanted.h>
void create()
{
	set("short", "草棚");
	set("long", @LONG
这是在部族东北部孤零零的一座草棚。这棚屋土墙草顶，形式宛如内地汉
人的砖屋，只是甚为简陋，旁边有一个小水漕。你悄悄的掩向小屋后面，正想
探头从窗子向屋内张望，哪知窗内有张脸同时探了上来。北去就是大戈壁了。
LONG
	);
	set("exits", ([
		"enter" : __DIR__"room-ji1",
		"south" : __DIR__"road2",
		"northwest" : __DIR__"gebi1",
		"southeast" : __DIR__"caoyuan6",
	]));

	set("indoors", "草原");

	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "northwest") {
		if (!userp(me))
			return 0;
		if (is_wanted(me))
			return 0;
	}
	return ::valid_leave(me, dir);
}
