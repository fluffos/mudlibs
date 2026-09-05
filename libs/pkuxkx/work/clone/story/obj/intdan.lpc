#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC "含笑半步颠" NOR, ({ "dan", "laugh dan", "laughdan" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一颗黑不溜秋的丹药，不知道有什么用。\n");
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
        if (random(5) == 0)
        {
                tell_object(me, "不过你觉得好像没什么作用。\n");
        } else
        {
                message("vision", "你似乎听见" + me->name() + "的脑子在嗡嗡直响。\n",
                                  environment(me), ({ me }));
                tell_object(me, HIY "你整个头嗡嗡响个不停，可把你吓坏了，"
                                "好在一会儿就停了下来，似乎脑子比平时灵活了些。\n" NOR);
                me->add_temp("apply/intelligence",5);
                 
        }
        destruct(this_object());
                                return 1;
}
