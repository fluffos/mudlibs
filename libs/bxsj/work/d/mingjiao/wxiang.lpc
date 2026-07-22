// wxiang.c 西厢房
// Modify By River@SJ 99.06

#include <ansi.h>
inherit ROOM;

void create()
{
       set("short",HIM"西厢房"NOR);
       set("long", @LONG
这里似一间大户人家小姐的闺房。靠窗边的是一张梳张台，台上点着两只
高高的红蜡烛，照得房中花团锦簇，堂皇富丽，靠墙摆放着一张牙床，床头上
罗帐(zhang)低垂，西边墙上是一块挂毯。
LONG);
	set("exits", ([
		"east" : __DIR__"yuanzi",
	]));
	set("item_desc", ([
		"zhang" : "这是一条低垂的罗帐，但好象有人在内面睡觉。\n"
	]));
	set("objects",([
		CLASS_D("mingjiao") + "/yang1" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_xian","xian");
	add_action("do_tang","tang");
}

int do_xian(string arg)
{
	object me=this_player();

	if (arg !="zhang" || me->is_busy()) return 0;

	tell_object(me,"你掀开罗帐，突然发现罗帐内面有一张大牙床，你忍不住想躺(tang)下来美美的睡上一觉。\n");
	me->set_temp("marks/掀1", 1);
	return 1;
}

int do_tang(string arg)
{
	object me=this_player();

	if (me->is_busy())
		return 0;
	if (me->query_temp("marks/掀1")){
		tell_object(me,"你慢慢的向床上躺去，突然床板一侧，将你摔了下去。\n");
		message("vision", me->name() + "慢慢的向床上躺去，突然床板一侧，"+me->name()+"摔了下去。\n", environment(me), ({me}));
		me->move(__DIR__"didao/bidao1");
		message("vision", me->name() + "突然间从上面摔了下来。\n", environment(me), ({me}) );
		me->delete_temp("marks/掀1");
		return 1;
	}
}
