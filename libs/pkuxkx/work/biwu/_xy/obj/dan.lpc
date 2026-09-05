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
	string * danname=({"灵芝","人参","何首乌",});
	set_name(danname[random(sizeof(danname))], ({ "dan"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一种神奇的药物，似乎有一些奇特的功效。\n");
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
			message_vision(HIR "$N吃下一枚"	+this_object()->query("name")+HIR "，顿时觉得一阵清凉的气息从顶心灌入，内息运转自如。\n"NOR,me);
			me->set("qi", me->query("max_qi"));
			me->set("jing", me->query("max_jing"));
			me->set("jingli", me->query("eff_jingli"));
			destruct(this_object());
			return 1;
		}
}

