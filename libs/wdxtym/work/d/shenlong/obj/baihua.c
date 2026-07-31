#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_use", "use");
}

void create()
{
	set_name("百花腹蛇膏", ({"baihua gao", "gao","baihua"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("long", "这是一枚珍贵的百花腹蛇膏。\n");
		set("value", 20000);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	if (me->improve_neili(30 + random(30)))
	{
		me->set("neili", me->query("max_neili"));
		message_vision(HIY "$N" HIY "吃下一枚百花腹蛇膏，顿然间只"
			       "觉一股清凉之气直沁心肺..."NOR"\n", this_player());
	}
	else
		message_vision(HIY "$N" HIY "吃下一枚百花腹蛇膏，但是好象"
			       "没什么用。"NOR"\n", this_player());

	destruct(this_object());
	return 1;
}

int do_use(string arg)
{

	object obj, weapon;
	object me = this_player();
	
	if (! arg || ! id(arg))
		return notify_fail("你要用什么？\n");

	if (! objectp(weapon = me->query_temp("weapon")))
		return notify_fail("不用武器恐怕不行吧！\n");

	message_vision(HIY "$N取出一枚百花腹蛇膏，将它抹在兵刃及手掌之上。"NOR"\n", me);
	message_vision(HIY "$N使用的百花腹蛇膏药效开始发作."NOR"\n", me);
	obj = new("/d/shenlong/obj/usedgao");
	obj->move(me, 1);
	destruct(this_object());
	return 1;
}
