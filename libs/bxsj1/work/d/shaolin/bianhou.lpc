// Room: /d/shaolin/lhtang.c
// Date: by zqb

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "匾后");
	set("long", @LONG
这里就是罗汉堂匾额之后，黑漆漆的什么都看不清楚。
LONG
	);
	set("indoors", "shaolin");
	set("objects",([
		__DIR__"obj/baitie" : 1,   
	]));
	setup();
}

void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object me=this_player();  

	if (arg!="down") return 0;
	if (me->is_busy()) return 0;
	message_vision("$N一纵身，跳了下去。\n", me);
	me->move(__DIR__"lhtang");
	tell_room(environment(me), me->name()+"从匾额上跳了过来。\n", me);
	return 1;
}
