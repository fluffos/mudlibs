
// Room: milin3.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
	set("short", "密林");
	set("long", @LONG
这是一片茂密的松林，杂乱的生长在倾斜的山坡上。每棵松树都有三四
抱粗细，高达十几丈。树冠枝多叶密，将天空完全遮住，因此林内显得有些
昏暗。树木之间长着很多灌木杂草，使行走很艰难，据说人参就生长在这些
杂草之中，不知道搜索一下能否有所发现。
LONG	);
	set("exits", ([
              "northwest" : __DIR__"milin3",
              "eastup" : __DIR__"heifk",
        ]));

        set("outdoors", "changbai");
        set("cost", 4);

        set("count", random(3) + 1);
        set("beast", random(5) + 1);

	setup();
}
int valid_leave(object me,string dir)
{
     if(dir=="eastup"&&!userp(me))
    return notify_fail("NPC去那里干吗？!!\n");
    return ::valid_leave(me,dir);
}
