// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", WHT+"打铁铺"+NOR);
	set("long", @LONG
这里是一间打铁铺，一进来就热气蒸腾，也代为出售一些武器，盔甲。
LONG
	);
        //set("outdoors", "xitianmu");

	set("exits", ([
		//"northwest" : __DIR__"westgc",
		"east" : __DIR__"xiaolu3",
		"enter" : __DIR__"datie2",
		//"south" : __DIR__"jiuguan",
	]));

	set("objects", ([
		__DIR__"npc/tielaoban" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	setup();
}

int valid_leave(object me,string dir)
{
	object rm;
	if (dir=="enter")
	{
		if (me->is_busy()||me->is_fighting())
		return notify_fail("你正忙着呢。\n");
		if(time() - me->query("killer/time") < 900)
		return notify_fail("你刚刚杀了人，别想躲进打铁铺里。\n");
        rm=new(__DIR__"datie2");
		message_vision("$N和老板打过招呼后，向打铁铺的打铁炉走去。\n",me);
		me->move(rm);
		rm->set("user",me->query("id"));
		return notify_fail("你来到了一间热气蒸腾的房间，里面只能放下一个打铁炉。\n");
	}
	return ::valid_leave(me,dir);
}
