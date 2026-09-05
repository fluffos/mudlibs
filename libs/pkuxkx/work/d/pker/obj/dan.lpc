// dan.c

#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("玄气丹", ({"dan",}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "玄气丹，又名九转腾龙丹，据传为当年秦始皇炼丹师所制，世间仅有七颗
,极为珍贵。\n");
		set("value", 500000);
	}
	setup();
}

int do_eat(string arg)
{
	int force_limit, neili_limit, force_skill, add_skill, improve;

	object me = this_player();

	force_limit = me->query_skill("force")*10;
	neili_limit = me->query("max_neili");
	force_skill = me->query_skill("force", 1);
	
	if (!id(arg))
	return notify_fail("你要吃什么？\n");


		me->add("max_neili", 200);
		me->add("neili", 200);

		message_vision(HIY "$N吃下一颗玄气丹，顿然间只觉四体轻盈，说不出的舒服...\n" NOR, this_player());
		
	

	
	destruct(this_object());
	return 1;
}

