// shenliwan.c 福缘丹

#include <ansi.h>

inherit ITEM;

void create()
{
set_name(HIG "仙豆" NOR, ({ "xian dou", "dou"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                  set("long", "一颗仙界的仙豆，据说吃了可以一星期都不吃东西。\n");
                set("value", 10000);
		set("unit", "颗");
	}
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me;

        if (! id(arg))
                return notify_fail("你要吃什么？\n");

        me = this_player();
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);
        tell_object(me, HIR "你刚才饥饿的感觉消失的无影无踪\n" NOR);
                  me->add("water", 5000);
                     me->add("food", 5000);
        destruct(this_object());
	return 1;
}
