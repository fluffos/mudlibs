// jiuxuebiyun-dan

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_fu", "fu");
}

void create()
{
	set_name(HIY"九雪碧云丹"NOR, ({"jiuxuebiyun dan","dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗晶莹剔透的丹药。\n");
		set("value", 10000);
		set("no_drop", "这样东西不能离开你。\n");
		set("no_give", "这样东西不能离开你。\n");
		set("no_get", "这样东西你捡不起来。\n");
	}
	set("wudu",1);
	setup();
}

int do_fu(string arg)
{
	object me = this_player();

	if (!id(arg))
		return notify_fail("你含吃什么？\n");
	message_vision(HIY "$N把一颗九雪碧云丹，轻轻咬碎含进嘴里，顿觉神明意朗，脸色红润。\n" NOR, me);	
	destruct(this_object());
	return 1;
} 
