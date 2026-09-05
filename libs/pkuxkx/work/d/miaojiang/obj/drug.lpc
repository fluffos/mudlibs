// drug

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
	set_name(BLU"苗人毒药"NOR, ({ "miaoren duyao","duyao","yao"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一瓶苗人的毒药。\n");
			set("unit", "瓶");
		}
    
}



int do_eat(string arg)
{	
	object me = this_player();
	if (!id(arg)) return 0;
	if ( me->is_busy() || me->is_fighting()) return 0;
    message_vision(HIR "$N吞下一瓶"	+this_object()->query("name")+HIR "，瞬间脸色惨白。\n"NOR,me);
	F_POISON->poison_attack(this_object(),me,"xxfog-poison", me->query_condition("xxfog-poison")+random(5));
    destruct(this_object());
    return 1;
		
}

