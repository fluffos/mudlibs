// shanshen.c 老山叁
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	int i ;

	i = random (3);
	if ( i == 0 ) 
		set("long", "这是一株沾满山泥的长白老山叁.\n");
	else {
		set("long", "这是一株沾满山泥的长白老山叁。\n");
		i = 1;
	}
	add_action("do_eat"+i, "eat");
}

void create()
{
	set_name("老山叁", ({"laoshan shen", "shen"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "株");
		set("long", "这是一株沾满山泥的长白老山叁.\n");
		set("value", 10000);
	}
	setup();
}

int do_eat1
(string arg)
{
    object me = this_player();
	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	if ( (int)me->query_condition("yao_drug" ) > 0 ) {
		me->add("force", -1);
 		message_vision(HIR "$N吃下一颗老山参，只觉得头重脚轻，摇摇欲倒，原来服食太急太多，药效适得其反！\n" NOR, me);
	}
	else {
		me->set("eff_qi", (int)me->query("max_kee"));
		write("你吃下一株老山叁，只觉得浑身一股热气兜底冒了上来 !\n");
		write("你觉得伤势顿时好多了。\n");
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
	message_vision(HIR "$N吃下一颗老山参，只觉得肝肠寸断，胸闷欲呕，霎时就人事不醒了\n" NOR, me);
	me->unconcious();
	destruct(this_object());
	return 1;
}

