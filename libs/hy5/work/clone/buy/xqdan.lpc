// shenliwan.c 福缘丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "邪气丹" NOR, ({ "xq wan", "wan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗七彩的邪气丹，据说吃了可以加邪气。\n");
                set("value", 10000);
		set("no_put",1);
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
        if (me->query("shen") < -29999999)
        {

                tell_object(me, "你觉得这药没啥味道，对你的福缘没有作用\n");
        } else
{
                tell_object(me, HIR "你觉得似乎自己的气息发生了变化。\n" NOR);
                me->add("shen", -500000);
}



        destruct(this_object());
	return 1;
}
