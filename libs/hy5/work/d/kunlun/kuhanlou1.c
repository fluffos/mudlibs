// kuhanlou1.c (kunlun)
// Date: cck 6/6/97

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "苦寒楼一层");
	set("long", @LONG
这里是苦寒楼的底层。苦寒楼结构简单，四周为浓密的云杉包围。取名自
“梅花香自苦寒来”之意，乃是昆仑派前辈为了激励后进昆仑派弟子而建的，
往上看，长长的木楼梯盘绕而上，似乎永无尽头。青砖地相当洁净，看
来经常有人打扫。
LONG
	);

	set("exits", ([
		"up" : __DIR__"kuhanlou2",
		"out" : __DIR__"shanlin1",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
		if (dir == "up" ) me->set_temp("count", 1);
	else 			 me->add_temp("count", -1);

	return ::valid_leave(me, dir);
}


