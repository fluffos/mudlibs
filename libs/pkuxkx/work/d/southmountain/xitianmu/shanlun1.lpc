// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIG+"山间小道"+NOR);
	set("long", @LONG
这里是一段山间的小道，郁郁葱葱，北面通向龙王山。
LONG
	);
        set("outdoors", "xitianmu");

	set("exits", ([
		"northwest" : "/d/southmountain/dashigu/wupu",
		"southeast" : __DIR__"fengshu",
		//"northeast" : __DIR__"wall1",
		//"eastdown" : __DIR__"xiaoxic",
	]));
	set("stay_time",1);
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	setup();
}
void init()
{
	this_player()->set_temp("xitianmu/xiaoxi_stay",time());
}
int valid_leave(object me,string dir)
{
	if (dir!="southeast"&&!userp(me)) return notify_fail("");
	if (member_array(dir,keys(query("exits")))!=-1&&
	time()-me->query_temp("xitianmu/xiaoxi_stay")<query("stay_time"))
	return notify_fail("你沿着"+query("short")+"，一步一步地慢慢前行。\n");
	return ::valid_leave(me,dir);
}