// shenliwan.c 福缘丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR "品质石" NOR, ({ "pz shi", "pzshi"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一块七彩的锻炼石，据说用(use)可以在干将处升级武器品质(levelup)。\n");
                set("value", 10000);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
		set("no_put",1);
		set("unit", "块");
	}
}

void init()
{
	add_action("do_eat", "use");
}

int do_eat(string arg)
{
	object me;

        if (! id(arg))
                return notify_fail("你要用什么？\n");

        me = this_player();

	if ( me->query_temp("lvsjok"))
		return notify_fail("你已经用过了，请先升级装备吧。\n");

        message_vision("$N把" + this_object()->name() +
                       "拿出打碎成粉。\n", me);

                tell_object(me, HIR "用这些粉，下线前，可以升级一次装备的品质。。\n" NOR);
                me->set_temp("lvsjok",1);

        destruct(this_object());
	return 1;
}
