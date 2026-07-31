#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIM "天丹" NOR, ({ "zixiao"}) );
	set_weight(200);
    set("suit_point", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "仙力凝聚成的丹药，能增加10万虚内\n");
        set("xy_money", 100);
	set("no_put", 1);
	set("base_value", 10000);
	set("no_sun", 1);
	set("base_weight", 10);
    set("no_give",1);
    set("no_sell",1);
    set("no_drop",1);
    set("no_get",1);
    set("no_sell", 1);
	set("only_do_effect", 1);
	set("yuanbao", 1);
	set("unit", "颗");
	}
}

int do_effect(object me)
{
        message_vision("$N张开嘴一口吞下了" + this_object()->name() +
                       "。\n", me);
        if (me->query("combat_exp") > 1000000)
        {
            message_vision("$N眨眨眼。\n", me);
			me->start_busy(0);

            tell_object(me, "内力没消耗完不需要吃丹药。\n");
        return 0;
        }	
        if (me->query("neili") < 100000)
        {

            me->add("neili", 100000);
            write("\n "+HIR+"你舔了舔天丹，内力增加。 "+NOR);

            me->start_busy(0);

        return 0;

        }else
        if (me->query("sen") < 200)
        {

            me->add("sen", 50000);
            write("\n "+HIR+"你舔了舔天丹，内力增加。 "+NOR);

			me->start_busy(0);

        return 0;

        }else
        {
                tell_object(me, "内气还没消耗完不需要吃丹药。\n");
        }
       // destruct(this_object());
	return 1;
}
