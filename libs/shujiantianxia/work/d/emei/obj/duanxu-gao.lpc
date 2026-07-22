// lianzi-wan.c

inherit ITEM;
#include <ansi.h>
void setup()
{}

void init()
{
        add_action("do_fu", "fu");
}

void create()
{
        set_name(MAG"天香断续膏"NOR, ({"tianxiang duanxugao", "duanxugao", "gao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "副");
                set("long", "这是一副峨嵋派的灵丹妙药，在受伤的时候敷上可以很快复原。但药性猛烈，敷用后会在一段时间内不能做任何事情。\n");
                set("no_drop", 1);
                set("no_give", 1);
                set("value", 5000);
                set("no_get", "这样东西你拿不了。\n");
        }
        setup();
}

int do_fu(string arg)
{
//      int nv;
//      nv = ((int)this_player()->query("max_qi") - (int)this_player()->query("eff_qi")) * 8 / 10;
        object me=this_player();
        if (!id(arg))
                return notify_fail("你要敷什么药？\n");

        if ( me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢。\n");

        if( me->query_condition("bonze_drug"))
                return notify_fail("你不是刚吃过药，怎麽又来吃了？ 灵药多吃有害无宜，过段时间再吃吧。\n");

        if ((int)me->query("eff_qi") == (int)me->query("max_qi"))
                return notify_fail("你现在不需要用天香断续膏。\n");

        else {
                me->set("eff_qi", this_player()->query("max_qi"));
                me->set("qi", this_player()->query("max_qi"));
                message_vision("$N在伤口敷上一副天香断续膏，气色看起来好多了。\n", this_player());
                me->set("eff_jing", me->query("max_jing") );
                me->set("jing", me->query("eff_jing") );
                me->set("qi", me->query("eff_qi") );
                me->set("jingli", me->query("eff_jingli") );
                me->set("neili", me->query("max_neili")/10);
                me->start_busy(2);
                me->apply_condition("bonze_drug", 30);
                destruct(this_object());
                return 1;
        }
}
