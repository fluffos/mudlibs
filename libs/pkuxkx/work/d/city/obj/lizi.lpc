// 李子 Zine 9Sep2010

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
	set_name("李子", ({ "li zi"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一枚成熟的李子，看起来很好吃的样子。\n");
			set("unit", "枚");
		}
}

int do_eat(string arg)
{	
	object me = this_player();
	if (!id(arg)) return 0;
	if ( me->is_busy() || me->is_fighting()) return 0;
	else 
		{
			message_vision(HIR "$N吃下一枚李子，顿觉不是凡品。\n"NOR,me);
			me->add("qi", 200);
			me->add("jing", 200);
			me->add("jingli", 200);
			destruct(this_object());
			return 1;
		}
}

