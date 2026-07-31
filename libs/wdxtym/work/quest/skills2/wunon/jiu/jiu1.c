// puti-zi.c 菩提子

#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void init()
{
	add_action("do_eat", "drink");
}

void create()
{
	set_name("绿豆酒", ({"lvdou jiu",}));
	set_weight(30);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用来装酒的大酒袋，大概装得八、九升的酒。\n");
		set("unit", "壶");
		set("value", 500);
		set("max_liquid", 15);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "绿豆酒",
		"remaining": 15,
		"drunk_supply": 6,
	]));
}

int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg))
		return notify_fail("你要喝什么？\n");
	if(!present(this_object(), me))
		return notify_fail("你要喝什么？\n");
	if( me->is_busy() )
		return notify_fail("你现在没空喝酒。\n");

	if ( me->query("drunk") == 100)
	{
		message_vision(HIR "$N喝酒太多，醉得不醒人事。\n" NOR, me);
		me->unconcious();
	}
	if ( (int)me->query_condition("a_jiu1" ) > 0 )
	{
		me->add("drunk", 5);
		message_vision(HIR "$N拿起绿豆酒就喝了起来,醉意增加了几分！\n" NOR, me);
	}
	else
	{
		me->add_temp("apply/dex",10);
		me->add_temp("apply/str",10);
		me->add("drunk", 5);
		message_vision(HIY "$N喝了口绿豆酒，整个人感觉轻飘飘的！\n" NOR, this_player());
		me->apply_condition("a_jiu1", 60);
	}
	destruct(this_object());
	return 1;
}

