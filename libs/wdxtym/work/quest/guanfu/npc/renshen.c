// shanshen.c 老山叁

#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("老山参", ({"laoshan shen", "shen"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "株");
		set("long", "这是一株沾满山泥的长白老山参。\n");
		set("value", 10000);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	if (me->query_condition("medicine")) {
        	me->set("qi", 0);
        	me->set("jing", 0);

		message_vision(
			HIR "$N吃下一株老山参，只觉得头重脚轻，摇摇欲倒，\n"
			"原来服食太急太多，药效适得其反！\n" NOR, this_player());
	}  
               switch(random(3)) {
                case 0:
                message_vision(
                      HIG "$N吃下一株老山参，只觉嘴里甜甜的很是好吃！\n" NOR, me);
                break;
                case 1:
	        me->set("eff_qi", me->query("max_qi"));
	        me->set("qi", me->query("max_qi"));
	        me->set("eff_jing", me->query("max_jing"));
	        me->set("jing", me->query("max_jing"));
	        me->set("neili", me->query("max_neili"));
                message_vision(
			HIG "$N吃下一株老山参，只觉得浑身一股热气兜底冒了上来！\n" NOR, me);
		me->apply_condition("medicine", 30);
                break;
                case 2:
                     message_vision(
                      HIG "$N吃下一株老山参，只觉嘴里微微有点发苦，丹田似乎有股热流在鼓动！\n" NOR, me);
                me->set("neili", me->query("max_neili"));
                break;
	}
	destruct(this_object());
	return 1;
}
