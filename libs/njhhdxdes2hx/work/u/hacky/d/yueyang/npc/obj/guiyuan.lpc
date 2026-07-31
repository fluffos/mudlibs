// guiyuan.c 归元丹
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	int i ;

	i = random (3);
	if ( i == 0 ) 
		set("long", "这是一颗莹白溜圆的归元丹.\n");
	else {
		set("long", "这是一颗莹白溜圆的归元丹。\n");
		i = 1;
	}
	add_action("do_eat"+i, "eat");
}

void create()
{
	set_name("归元丹", ({"guiyuan dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("value", 10000);
	}
	setup();
}

int do_eat1(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("你要吃什么？\n");


	if ( (int)me->query_condition("yao_drug" ) > 0 )
	{
		me->add("force", -1);
 		message_vision(HIR "$N吃下一颗归元丹，只觉得头重脚轻，摇摇欲倒，原来服食太急太多，药效适得其反！\n" NOR, me);
	}
	else
	{
		this_player()->add("force", 200);
        message_vision(YEL "$N吃下一颗归元丹，只觉得四肢百骸真气充盈无比 !\n" NOR, this_player());
	}

	me->apply_condition("yao_drug", 60);
	
	destruct(this_object());
	return 1;
}

int do_eat0(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("你要吃什么？\n");
	me->add("max_force", -1);
	message_vision(HIR "$N吃下一颗归元丹，只觉得肝肠寸断，胸闷欲呕，霎时就人事不醒了\n" NOR, me);
	me->unconcious();
	destruct(this_object());
	return 1;
