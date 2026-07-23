// jujing-dan.c 结气丸

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIY"延年聚精丹"NOR, ({"jujing dan","dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗药香怡人的延年聚精丹。\n");
                set("value", 10000);
//                set("no_drop", "这样东西不能离开你。\n");
        }

        set("wudang",1);
        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
        return notify_fail("你要吃什么？\n");

        if ( me->query_skill_mapped("force") != "yinyun-ziqi" )
        {
                me->add("max_jingli", -5);
                me->add("eff_jingli", -5);
                message_vision(HIR "$N吃下一颗延年聚精丹，只觉得头胀欲裂，原来所练内功不符，反而大损真元！\n" NOR, me);
                me->unconcious();
                destruct(this_object());
                return 1;
        }

 if ( me->query("eff_jingli") < 200 )
        {
me->add("eff_jingli", -1);
me->add("max_jingli", -1);
                message_vision(HIR "$N吃下一颗延年聚精丹，只觉得头重脚轻，摇摇欲倒，原来精力不够，药效适得其反！\n" NOR, me);
        }
        else if ( (int)me->query_condition("bonze_drug" ) > 0 )
        {
me->add("eff_jingli", -1);
me->add("max_jingli", -1);
                message_vision(HIR "$N吃下一颗延年聚精丹，只觉得头重脚轻，摇摇欲倒，原来服食太急太多，药效适得其反！\n" NOR, me);
        }
        else
        {
me->add("eff_jingli", 1);
me->add("max_jingli", 1);
                message_vision(HIY"$N吃下一颗延年聚精丹，只觉得身体飘飘欲仙，顿感精神百倍！\n" NOR, me);
        me->apply_condition("bonze_drug", 30);
        }
        
        destruct(this_object());
        return 1;
}
