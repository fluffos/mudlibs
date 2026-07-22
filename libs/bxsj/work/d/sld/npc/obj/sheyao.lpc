// sheyao.c

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
        set_name(HIG "蛇药" NOR, ({"sheyao","yao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
                "这是一颗用来解蛇毒的蛇药。\n");
		set("unit", "颗");
		set("medicine", "drug");
		//set("no_get", 1);
//                set("no_drop", 1);
	}
}

int do_eat(string arg)
{
	object me = this_player();
       int cs;

	if (!living(me)) return notify_fail("想当机吗？\n");
	if (!id(arg)) return 0;
	message_vision(HIG "$N吃下一颗"
	+this_object()->query("name")+
	HIG "，顿时觉得全身发热。\n"
	NOR,me);
       cs=me->query_condition("snake_poison",1);
       if(cs<10)
                cs=0;
            else
                cs-=10;
       me->apply_condition("snake_poison",cs);
       destruct(this_object());
	return 1;
}
