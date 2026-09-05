// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "山路"+NOR);
	set("long", @LONG
这里是西天目山西侧的一段山间小道。
LONG
	);
        set("outdoors", "xitianmu");

	set("exits", ([
		"westdown" : __DIR__"shanluw3",
		"southeast" : __DIR__"shanluw1",
		//"northeast" : __DIR__"wall1",
		//"eastdown" : __DIR__"fengshu",
	]));
	set("stay_time",3);
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
	if (member_array(dir,keys(query("exits")))!=-1&&
	time()-me->query_temp("xitianmu/xiaoxi_stay")<query("stay_time"))
	return notify_fail("你沿着"+query("short")+"，一步一步地慢慢前行。\n");
	return ::valid_leave(me,dir);
}