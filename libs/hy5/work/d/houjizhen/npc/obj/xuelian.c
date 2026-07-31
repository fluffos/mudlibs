// xuelian.c
// by dicky

#include <ansi.h>;
inherit ITEM;

void create()
{
        set_name("天山雪莲", ({ "tianshan xuelian"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
		set("long", "天山雪莲\n");
		set("unit", "朵");
		set("value", 3000);
	}
}

void init()
{
	if (present(this_object(), this_player())) {
		add_action("do_eat", "eat");
	}
}

int do_eat(string arg)
{	
	object me = this_player();
	mapping skills;
	skills = me->query_skills();
	skills = 0;
	
	message_vision(HIG "$N小心地吃下一颗"
		+this_object()->query("name")+
          HIG "，顿时觉得头脑清爽，精神为之一振。。\n"
		NOR,me);

        me->set("jing", me->query("max_jing"));
        me->set("qi", me->query("max_qi"));
        me->set("neili", me->query("max_neili"));
        me->set("food", me->max_food_capacity());
        me->set("water", me->max_water_capacity());
       	destruct(this_object());
	return 1;
}

