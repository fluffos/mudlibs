// Room: pool2.c
// zine 26 aug 2010

inherit "/biwu/biwuroom1";
#include <room.h>
#include <ansi.h>
void create()
{
	set("short", "池底");
	set("long", @LONG
		池塘的底部，一只大鳄鱼不怀好意的大量着你，有吃的送上门了。
LONG
);
	set("exits", ([ /* sizeof() == 3 */
		"out" : __DIR__"pool",
	]));
	set("objects", ([
       ("/biwu/xy/npc/croc") : 1+random(2),
    ]));
	setup();
}

int valid_leave(object me, string dir)
{  
	if ( dir == "out" && present("croc", environment(me)) )
	return notify_fail("大鳄鱼转身拦住了你，显然并不愿送上门的晚餐跑掉。\n");
	return ::valid_leave(me, dir);
}
