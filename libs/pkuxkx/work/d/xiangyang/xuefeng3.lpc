#include <room.h>
inherit ROOM;
void create()
{
        set("short", "雪峰山顶");
set("outdoors","xiangyang");
	set("long", @LONG
这里雪峰的山顶,陡峭的岩石又冷又滑,连手攀的地方都没有,一阵寒风吹来,
你查点没掉下去!好险好险!岩石上有一个岩洞,虽然在高峰之颠,但洞里又暖有安全,
有两只小雕在等着父母喂食.云中的大雕看见你,呼啸一声冲了下来.

LONG
	);
	set("exits", ([
		"down" : __DIR__"xuefeng2",
		]));
	set("objects", ([
                __DIR__"npc/baidiao" : 2,
		__DIR__"npc/obj/xiaodiao" : 1,
	]));

	setup();
	replace_program(ROOM);
}

