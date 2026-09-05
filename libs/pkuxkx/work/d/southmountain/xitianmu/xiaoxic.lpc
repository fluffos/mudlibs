// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "溪边");
	set("long", @LONG
这里是从西天目山中山涧流淌下来的一条小溪的岸边，水却不深，也许你可
以涉水(sheshui)到对岸。
LONG
	);
        set("outdoors", "xitianmu");

	set("exits", ([
		"northwest" : __DIR__"xiaoxie",
		"south" : __DIR__"xiaoxid",
		//"northeast" : __DIR__"wall1",
		//"west" : __DIR__"wall1",
	]));
	set("xiaoxi_dir",({"south","northwest"}));
	set("stay_time",2);
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	setup();
}


int valid_leave(object me,string dir)
{
	if (member_array(dir,query("xiaoxi_dir"))!=-1&&
	time()-me->query_temp("xitianmu/xiaoxi_stay")<query("stay_time"))
	return notify_fail("你沿着溪边，一步一步地离去。\n");
	return ::valid_leave(me,dir);
}
	


void init()
{
	this_player()->set_temp("xitianmu/xiaoxi_stay",time());
	add_action("do_ss","sheshui");
}

int do_ss()
{
	object me=this_player();
	if (me->is_busy()||me->is_fighting())
	return notify_fail("你正忙着呢。\n");
	message_vision(HIC+"$N"+HIC+"踏入小溪，向着东面走去。\n"+NOR,me);
	me->move("/d/southmountain/dongtianmu/xiaoxib");
	me->add_busy(2);
	return 1;
}

