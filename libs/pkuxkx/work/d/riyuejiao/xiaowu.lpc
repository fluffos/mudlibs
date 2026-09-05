//xiaowu.c	小石屋
//by bing
#include <room.h>
inherit ROOM;

void create()
{
	set("short","小石屋");
	set("long",@LONG 
这是一个空荡荡的小石屋，只是左首墙壁(wall)颜色和别的有稍许不同。
LONG
	);
	set("exits", ([
		"out" : __DIR__"xicedian",
	]));
        set("no_task",1);
	setup();
}

void init()
{
	add_action("do_push","push");
}

int do_push(string arg)
{
	object me = this_player();

	if (!arg || arg != "wall")
		return notify_fail("你要推什么？\n");

		message_vision("$N伸手一推，那墙原来是活的，露出一道门户。\n",me);
		set("exits/enter",__DIR__"hmydidao1");
	return 1;
}		

int valid_leave(object me, string dir)
{
        if (dir == "enter" )
		if ( me->query_encumbrance() * 100 / me->query_max_encumbrance() > 30)
			return notify_fail("你身上背的东西太多，地道里狭窄，进不去。\n");
	
        return ::valid_leave(me, dir);

}
