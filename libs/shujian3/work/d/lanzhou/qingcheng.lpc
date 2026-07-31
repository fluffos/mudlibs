// By River@SJ

#include <room.h>
#include <wanted.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"青城"NOR);
	set("long", @LONG
青城位于靖远以南三百二十里，西北八十里就是兰州，名为青城，其实只
是个小镇，因为地处北去西夏的要冲，许多往来西夏和大宋的商旅都必须经过
这儿，人来人往很是热闹。
LONG );
	set("exits", ([
		"northeast" : __DIR__"shamo",
		"northwest"  : "/d/group/entry/lzsroad3",
		"south" : "/d/chengdu/road1",
	]));

	set("outdoors", "成都");
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "northeast" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}
