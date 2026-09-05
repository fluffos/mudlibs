// 大石谷，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "青瓦院落"+NOR);
	set("long", @LONG
这里是一户人家，青瓦的房顶，整齐的院落，奇异的是火山的热浪似乎全被
挡在这里之外了。
LONG
	);
        set("outdoors", "dashigu");

	set("exits", ([
		"west" : __DIR__"yujia2",
		"east" : __DIR__"huoshankou",
		//"northwest" : __DIR__"taohua",
		//"eastdown" : __DIR__"xiaoxic",
	]));
	set("stay_time",1);
	set("valid_startroom", 1);
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		__DIR__"npc/yuren" : 1,
        ]));
	setup();
}

int valid_leave(object me,string dir)
{
	if (dir=="west"&&!me->query("tianmuQuests/dashigu/gather")) 
	return notify_fail("你被这里的主人一把拦住。\n不要随便乱闯人家家的后院。\n");
	return ::valid_leave(me,dir);
}
void init()
{
	object me=this_player();
	if (me->query("tianmuQuests/dashigu/gather"))
	{
		me->set("startroom", base_name(this_object()));
		me->set_temp("revive_room",base_name(this_object()));
	}
}