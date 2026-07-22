// Room: /d/chengdu/guandim.c 关帝庙
// Build by Lklv@SJ 2001.9.28

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"关帝庙"NOR);
	set("long", @LONG
这是一座破败的关帝庙，以前曾经香火很盛，后来因为天灾人祸渐渐地破
败了，再没有什么人来上香。后来不知道从那里来了一群叫化子，把这里做为
夜晚休息的安身之所。最近这里成了丐帮的大智分舵。门外是一条宽阔的青石
大道，通往城外。
LONG
	);
        set("outdoors", "成都");

	set("exits", ([
		"south" : __DIR__"xidajie2",
		"north" : __DIR__"houyuan",
	]));

        set("objects", ([
                CLASS_D("gaibang/qnqigai") : 1,
                CLASS_D("gaibang/quan") : 1,
                CLASS_D("gaibang/lichunlai") : 1,
        ]));

	set("incity",1);
	setup();
}
