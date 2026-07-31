// shadan.c 熊胆

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIR"西洋参"NOR, ({"xiyang shen", "xiyangshen"}));
	set_weight(1000);
	set("vegetable", 16);
	set("value", 7000);
	set("nostrum", 2);
	set("unit", "颗");
	set("long", "这是一颗西洋参，看来可以入药。\n");
	set("pour_type", "1");set("yaocao",1);
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg)) return notify_fail("你要吃什么？\n");
	if(!present(this_object(), me))
		return notify_fail("你要吃什么？\n");
	if( me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");
  me->set("qi", this_player()->query("max_qi"));
	me->set("eff_qi", this_player()->query("max_qi"));
	message_vision("$N吃下一副西洋参，觉得精神好多了。\n", me);
	destruct(this_object());
	return 1;
}

