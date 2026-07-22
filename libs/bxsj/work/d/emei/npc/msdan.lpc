// msdan.c
//蟒蛇胆

#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("蟒蛇胆", ({"mangshe dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗黑色的蟒蛇胆。\n");
		set("value", 10000);
	}
	setup();
}

int do_eat(string arg)
{	
// int max;
	object me = this_player();

	if (!id(arg))
	return notify_fail("你要吃什么？\n");
	if( !random(2) ) {
message_vision(HIM "$N张口轻轻一咬，蛇胆外皮便即破裂，登觉满口苦汁，腥极苦极，结果$N把自己吃的东西都吐了出来。\n" NOR, me);
this_player()->set("food",10);
	destruct(this_object());
	return 1;
	}
// max = (int)me->query("eff_jingli");
 me->add("jingli", 1);
 me->add("eff_jingli", 1);
 me->add("max_jingli", 1);
//   me->set("jingli", max);
message_vision(HIM "$N张口轻轻一咬，蛇胆外皮便即破裂，登觉满口苦汁，腥极苦极，几乎要呕将出来。\n" NOR, me);
message_vision(HIM "可稍过片刻，$N只觉呼吸顺畅，耳清目明，精神爽利，力气大增。\n" NOR, me);
	destruct(this_object());
	return 1;
}

