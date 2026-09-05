//modified by iszt@pkuxkx, 2007-02-01

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",BLK"黑松岭"NOR);
	set("outdoors","xiangyang");
	set("long", @LONG
这里到处都是千年古松，枝繁叶茂，遮天蔽日。一阵阴风吹来，枝叶乱摇隆
隆作响，似乎每棵树后都有人在窥视着你。你后脊梁不禁一阵发凉，赶紧离开这
个是非之地罢。
LONG NOR);
	set("objects", ([
		__DIR__"npc/xiong" : 1,
	]));
	set("exits", ([
		"westdown" : __DIR__"chukou0"          
	]));
	setup();
}                                                         

void init()
{
	add_action("do_drink", "drink");
}

int do_drink(string arg)
{
	int current_water;
	int max_water;
	object me;
	me = this_player();
	if(arg)
		return 0;
	current_water = me->query("water");
	max_water = me->query("str")*10 + 100;
	if (current_water<max_water) {
		me->add("water", 20);
		message("vision", me->name()+"捧起一些溪水喝了下去。\n", environment(me), ({me}) );
		write("你从林间的小溪中捧起一些溪水喝了下去。\n");
	}
	else
		return notify_fail("你已经喝饱了。\n");

	return 1;
}