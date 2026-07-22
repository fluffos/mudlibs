// fyhouyuan.c 府衙后院
// Looklove 2000/10/16

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "府衙后院");
	set("long", @LONG
这里是府衙后院，有几个衙役无所事事地靠在墙角，边晒太阳边聊天。看
见你进来，他们立刻不说话了，纷纷用眼角的余光上下打量着你。一旁的几只
大狼狗不怀好意地靠进你的身边闻了闻。
LONG
	);

	set("exits", ([
		"northdown" : __DIR__"dilao",
		"southeast" : __DIR__"ymzhengting",
	
	]));
        set("objects", ([
                 "clone/animal/langgou" : 4,
                __DIR__"npc/yayi" : 2,
        ]));
   	set("incity",1);
	setup();
}
