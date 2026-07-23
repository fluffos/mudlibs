// jieqi-wan.c 结气丸

#include <ansi.h>

inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIR"九转结气丸"NOR, ({"jieqi wan","wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗正发出阵阵芳香的九转结气丸。乃武当派独门仙丹,有固本培元的奇效!\n");
                set("value", 10000);
                set("no_drop", "这样东西不能离开你。\n");
        	set("wudang",1);
        }
	set_weight(100);

        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
        return notify_fail("你要吃什么？\n");

        if ( me->query_skill_mapped("force") != "yinyun-ziqi" )
        {
                me->add("max_neili", -10);
                message_vision(HIR "$N吃下一颗九转结气丸，只觉得丹田有如刀割，原来所练内功不符，反而大损真元！\n" NOR, me);
                me->unconcious();
                destruct(this_object());
                return 1;
        }

        if ( me->query("max_neili") < 400 )
        {
                me->add("max_neili", -1);
                message_vision(HIR "$N吃下一颗九转结气丸，只觉得周身真气乱窜，难过异常，原来功力不够，药效适得其反！\n" NOR, me);
        }
         else if ( (int)me->query_condition("medicine") > 0 )
        {
                        me->add("max_neili", -10);
                message_vision(HIR "$N吃下一颗九转结气丸，只觉得头重脚轻，摇摇欲倒，原来服食太急太多，药效适得其反！\n" NOR, me);
        }
        else
        {
                me->add("max_neili", 1);
                message_vision(HIY "$N吃下一颗九转结气丸，只觉得体内真力源源滋生，过百汇，入丹田，遍走奇筋八脉，全身功力顿然提高！\n" NOR, me);
                  me->apply_condition("medicine", 120);
        }

        destruct(this_object());
        return 1;
}

