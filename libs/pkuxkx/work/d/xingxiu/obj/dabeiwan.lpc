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
	set_name(HIY"大悲丸"NOR, ({ "dabei wan","wan"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一枚大悲丸，专门克制极乐刺的毒性。\n");
			set("unit", "枚");
		}
}

int do_eat(string arg)
{	
	object me = this_player();
	if (!id(arg)) return 0;
	if ( me->is_busy() || me->is_fighting()) return 0;
    message_vision(HIR "$N吃下一枚"	+this_object()->query("name")+HIR "，瞬间心如刀绞。\n"NOR,me);
    me->receive_damage("qi", me->query("max_qi")/10);
    me->set_temp("dabeiwan",1);
    me->apply_condition("dabei",1000);
    destruct(this_object());
    return 1;
		
}

