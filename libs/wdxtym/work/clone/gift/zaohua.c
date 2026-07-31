
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "造化丹" NOR, ({ "zaohua", "dan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗吃了会涨灵慧的丹药。\n");
                set("value", 100);
		set("unit", "颗");
		set("only_do_effect", 1);
                set("suit_point",500);
	}
}

int do_effect(object me)
{
        int effect;
	 mapping my;

        log_file("static/using", sprintf("%s(%s) eat 造化丹 at %s.\n",
                 me->name(1), me->query("id"), ctime(time())));

        effect = 0;
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);

        write(HIM "突然一阵内劲不受控制从身体爆发而出。"NOR"\n");
        
	me->add("magic_points", 1000 + random(1000));

	write(HIY "而后你觉得精神为之一振！"NOR"\n");
        destruct(this_object());
	return 1;
}

