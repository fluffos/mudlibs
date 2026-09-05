// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "溪边");
	set("long", @LONG
这里是西天目山脚下的一条小溪，清澈见底。
LONG
	);
        set("outdoors", "xitianmu");

	set("exits", ([
		//"north" : __DIR__"xiaoxic",
		"southeast" : __DIR__"xiaoxic",
		//"northeast" : __DIR__"wall1",
		"westup" : __DIR__"fengshu",
	]));

	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	set("xiaoxi_dir",({"southeast"}));
	set("stay_time",2);
	setup();
}
void init()
{
	this_player()->set_temp("xitianmu/xiaoxi_stay",time());
}
int valid_leave(object me,string dir)
{
	if (member_array(dir,query("xiaoxi_dir"))!=-1&&
	time()-me->query_temp("xitianmu/xiaoxi_stay")<query("stay_time"))
	return notify_fail("你沿着溪边，一步一步地离去。\n");
	return ::valid_leave(me,dir);
}
	

