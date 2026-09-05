// 大石谷，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIG"静水潭"+NOR);
	set("long", @LONG
这里是静水潭，瀑布冲下的水流在这里趋于平缓，碧绿的水面十分宁静。
LONG
	);
        set("outdoors", "dashigu");

	set("exits", ([
		"southup" : __DIR__"wanshi",
		//"northdown" : __DIR__"jingshui",
		//"northwest" : __DIR__"taohua",
		//"eastdown" : __DIR__"xiaoxic",
	]));
	set("stay_time",1);
	set("valid_startroom", 1);
	set("objects", ([
		__DIR__"npc/monkey" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	setup();
}
void init()
{
	object me=this_player();
	me->set_temp("xitianmu/xiaoxi_stay",time());
	if (me->query("tianmuQuests/dashigu/gather"))
	{
		me->set("startroom", base_name(this_object()));
		me->set_temp("revive_room",base_name(this_object()));
	}
}
int valid_leave(object me,string dir)
{
	object *monkey=all_inventory(environment(me));
	for (int i=0;i<sizeof(monkey);i++)
	if (monkey[i]->query("dashigu_houzi")&&dir!="southup"&&userp(me)&&!me->query("tianmuQuests/dashigu/monkey"))
	{
		return notify_fail(monkey[i]->query("name")+"拦住了你的路，伸手想跟你要点什么。\n");
	}
	if (member_array(dir,keys(query("exits")))!=-1&&
	time()-me->query_temp("xitianmu/xiaoxi_stay")<query("stay_time"))
	return notify_fail("你观赏着"+query("short")+NOR+"风光，一步一步慢慢前行。\n");
	return ::valid_leave(me,dir);
}