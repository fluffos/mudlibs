// 大石谷，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "后院"+NOR);
	set("long", @LONG
这里是后院，整齐的放着一些器具(qiju)。
LONG
	);
        set("outdoors", "dashigu");
	set("item_desc",(["qiju":"你可以借助这些器具修理(repair)药锄。\n"]));
	set("exits", ([
		//"west" : __DIR__"yujia2",
		"east" : __DIR__"yujia",
		//"northwest" : __DIR__"taohua",
		//"eastdown" : __DIR__"xiaoxic",
	]));
	set("stay_time",1);
	set("valid_startroom", 1);
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		__DIR__"obj/yaochu" : 1,
        ]));
	setup();
}
void init()
{
	object me=this_player();
	add_action("do_repair","repair");
	if (me->query("tianmuQuests/dashigu/gather"))
	{
		me->set("startroom", base_name(this_object()));
		me->set_temp("revive_room",base_name(this_object()));
	}
}
int do_repair(string arg)
{
	object me=this_player(),chu;
	if (me->is_busy())
	return notify_fail("你正忙着呢。\n");
	if (!arg||!chu=present(arg,me))
	return notify_fail("你要修什么？\n");
	if (!chu->is_DrugHoe())
	return notify_fail("这里的主人只同意你修理药锄。\n");
	if (chu->query("worn")>50)
	return notify_fail("现在没有必要修理"+chu->query("name")+"。\n");
	chu->set("worn",200);
	message_vision("$N努力修好了"+chu->query("name")+"。\n",me);
	me->add_busy(2);
	return 1;
}
