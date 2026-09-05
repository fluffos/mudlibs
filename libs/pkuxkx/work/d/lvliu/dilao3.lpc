#include <ansi.h>
#include <room.h>
#include "nodie.h"
inherit ROOM;

int do_swim(string arg);

void create()
{
	set("short", CYN"五行牢狱·水牢"NOR);
	set("long", CYN"一间阴暗的地牢。四周石壁上长满了滑腻腻的青苔，整间牢狱里全
是水，浅的地方及腰，深的地方可以没顶。这水也不知道沉积了多长时
间，黑黝黝，臭烘烘的，任凭是谁泡久了都得变成烂肉。你泡在水里，
觉得浑身都不舒服，还是赶快游出去(swim)吧。\n"NOR);
	set("exits", ([
	  "east" : __DIR__"path3",
	]));
	set("item_desc", ([
		"east" : "前面黑乎乎的，啥也看不见。\n",
	]));
	set("no_sleep_room",1);
	setup();
}

void init()
{
	object me = this_player();
	object npc, here = this_object();

	add_action("do_swim", "swim");

	if (!objectp(me) || !userp(me)) return;
	
	me->delete_temp("lvliu_swim");
	npc = present("jiguan ren", here);
	if (!objectp(npc) || userp(npc))
	{
		npc=new(__DIR__"npc/jiguanren3");
		if (objectp(npc))
		{
			npc->move(here);
			message_vision(YEL"黑暗中缓缓站起了一个机关人，巨大的身躯挡在了$N的面前。\n"NOR, me);
		}
		return;
	}
	message_vision(YEL"黑暗中缓缓站起了一个机关人，巨大的身躯挡在了$N的面前。\n"NOR, me);
}

int do_swim(string arg)
{
	object me = this_player();
	int count;
	if (!arg)
		return notify_fail("你要朝哪个方向游？\n");
	if (me->is_busy())
		return notify_fail("你正忙着呢，腾不出手来划水。\n");
	if (arg!="east" && arg!="e")
		return notify_fail("这个方向是石壁，没有出口，你要游过去撞墙吗？\n");
	tell_object(me, HIC"你四肢并用，向着通道的方向死命游去。\n"NOR);
	if (random(me->query_kar()) <= random(15))
	{
		tell_object(me, MAG"你一不小心，咕咚一下呛了一口臭水……这什么味道？太恶心了！\n呕……你吐得翻江倒海，苦胆汁都吐出来了。\n"NOR);
		me->receive_wound("qi", me->query("max_qi")/20, "呛水");
        COMBAT_D->report_status(me);
		me->start_busy(5);
	}
	else me->start_busy(3);
	me->add_temp("lvliu_swim", 1);
	count = me->query_temp("lvliu_swim");
	if (count>9 || (count>5 && !random(3)))
	{
		me->delete_temp("lvliu_swim");
		me->move(__DIR__"path3");
		message_vision(HIC"伴着一阵哗啦哗啦的水响，$N艰难地游了过来。\n"NOR, me);
	}
	else if (count>5) tell_object(me, HIY"快游到了，你已经看到出口了，加油！\n"NOR);
	return 1;
}

int valid_leave(object me, string dir)
{
    if ( objectp(present("jiguan ren", environment(me))))
        return notify_fail("机关人巨大的身躯挡住了出口，在把它解决掉之前你根本出不去。\n");
	tell_object(me, HIC"你四肢并用，向着通道的方向死命游去。\n"NOR);
    return ::valid_leave(me, dir);
}

