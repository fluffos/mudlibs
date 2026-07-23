// by snowman

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(RED"鹤顶红"NOR, ({"heding hong", "hong", "heding"}));
	set_weight(2000);
	if (clonep()) {
		set_default_object(__FILE__);
    		call_out("dest", 600);
	} else {
		set("unit", "个");
		set("long", RED"这是一个新鲜的鹤顶红，还散发着阵阵热气。\n"NOR);
		set("value", 50000);
	}
	setup();
}

int init()
{
	if (environment() == this_player())
   		add_action("do_eat", "fu"); 
}

int do_eat(string arg)
{
   	object me = this_player();
	int i;

   	if (!id(arg))
       		return notify_fail("你要服什么？\n");

   	message_vision("$N服下一个" + name() + "。\n", me);  
   	tell_object(me, MAG "你感觉腹中一股巨疼传来，瞬间全身火热滚烫！\n" NOR);

	i = me->query("max_qi") + me->query_temp("apply/qi");
   	me->receive_wound("qi", i / 4 + random(i), "服食剧毒而");

   	if ((int)me->query_condition("hb_poison") > 1)
		me->apply_condition("hb_poison", 1);
	
   	else if ((int)me->query_condition("cold_poison") > 1)
		me->apply_condition("cold_poison", 1);

	else if( me->query_skill("hamagong", 1)) {
		if( me->query("max_neili") < me->query_skill("force") * 10 + me->query("age")*20 + me->query("combat_exp")/1000 + me->query("query_neili") )
			me->add("max_neili", 2);
		else {
			tell_object(me, "你感觉胃口好多了！\n");
			if( me->query("food") < me->max_food_capacity() )
				me->add("food", 50+random(100));
		}
	}
   	else me->add_condition("hot_poison", 70); 

   	destruct(this_object());
   	return 1;
}

void dest()
{
	message_vision(HIR "鹤顶红的热气散尽，慢慢干枯了。\n"NOR, this_object());
	destruct(this_object());
}
