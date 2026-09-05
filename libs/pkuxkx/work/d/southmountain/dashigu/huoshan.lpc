// 大石谷，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include "/d/menggu/entry_migong.h"
#include <ansi.h>
void create()
{
	set("short", "碎石"+NOR);
	set("long", @LONG
这里只有一地碎石，根本就没有好好的路可走了。
LONG
	);
        set("outdoors", "dashigu");

	set("exits", ([
		"northup" : __DIR__"huoshan2",
		"southdown" : __DIR__"huoshankou",
		//"northwest" : __DIR__"taohua",
		//"eastdown" : __DIR__"xiaoxic",
	]));
	set("stay_time",1);
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	set("valid_startroom", 1);
	set("entry_direction","southdown");
    set("migong","/d/southmountain/dashigu/dashigu");
    set("migong_posi","north");
    set("look_refuse_msg","大石谷刚刚火山喷发过，现在什么都看不清。\n");
    set("enter_refuse_msg","大石谷刚刚火山喷发过，稍凉一点再进谷吧。\n");
	setup();
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