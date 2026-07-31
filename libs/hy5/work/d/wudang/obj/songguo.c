// songguo.c
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("野松果", ({ "song guo", "guo" }) );
        set_weight(150);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一颗松子饱满的野松果实。\n");
                set("unit", "枚");
                set("value", 80);
        }
        setup();
}

int init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg)) return notify_fail("你要吃什么？\n");
	if( me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");
	message_vision(HIG"$N吃下一颗" + name() + "，只觉得精神健旺。\n"NOR, me);
	if (me->query("eff_jing") < me->query("max_jing"))
		me->receive_curing("jing", (int)me->query("max_jing") / 20);
	me->start_busy(2);
	destruct(this_object());
	return 1;
}
