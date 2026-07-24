// Room: /dream/zhulin.c
// HEM 1998/9/18
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "竹林");
	set("long", @LONG
	这是一片郁郁葱葱的竹林，蜀中水土很适合竹类的生长，这片竹林中竹子种类
繁多，细细看来，有状若罗汉肚的罗汉竹，有隐隐红点的湘妃竹，有笔直粗壮的楠竹..
竹叶的清香，令人置其中，心旷神怡。竹林东南，有一条青石砌成的小路。
LONG
	);
        set("outdoors", "tangmen");
	set("exits", ([
		"north" : __DIR__ "chapu",
                "southeast" : __DIR__ "feicui",
	]));
        set("objects", ([
                "/clone/misc/dache": 1,
	]));	
create_door("north", "竹门", "south", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}

