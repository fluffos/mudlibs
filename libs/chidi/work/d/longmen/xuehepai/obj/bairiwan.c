
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
        add_action("do_eat", "fu");
}

void create()
{
        set_name(HIB"百日十龙丸"NOR, ({"bairi wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "此丹通过毒药来反常规的提高功力，霸道无比。\n");
                set("value", 10000);
                set("no_drop",1);
        }
        setup();
}

int do_eat(string arg)
{
        int neili,neili_limit;

        object me = this_player();

        if (arg!="丸" || arg!="wan")
                return notify_fail("你要吃什么？\n");

        if( me->is_busy() )
                return notify_fail("别急，慢慢吃，丢不了。\n");

        me->start_busy(2);
        me->set_temp("neili_save",(int)me->query("max_neili"));
        message_vision(HIG "$N吃下一颗百日十龙丸，只觉得辛辣无比。\n" NOR, me);
        

        me->apply_condition("bairi-du", 100);
        
        destruct(this_object());
        return 1;
}

