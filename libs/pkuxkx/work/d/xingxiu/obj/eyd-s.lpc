// jmd.c

#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "chi");
	add_action("do_eat", "yan");
	add_action("do_eat", "tun");
}

void create()
{
	set_name(HIY"鳄鱼内丹"NOR, ({ "dan"}));
	set_weight(200);
	set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一枚鳄鱼的内丹，似乎有一些奇特的功效。\n");
			set("unit", "枚");
		}
}

int do_eat(string arg)
{	
	object me = this_player();
	if (!id(arg)) return 0;
	if ( me->is_busy() || me->is_fighting()) return 0;
    message_vision(HIR "$N吃下一枚"	+this_object()->query("name")+HIR "，顿时觉得一阵清凉的气息从顶心灌入，内息运转自如。\n"NOR,me);
    me->add("combat_exp",8888);
    destruct(this_object());
    return 1;
}

