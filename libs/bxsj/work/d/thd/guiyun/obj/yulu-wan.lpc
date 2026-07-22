// yulu-wan.c 九花玉露丸
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
        set_name(HIG"九花玉露丸"NOR, ({"yulu wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", HIG"这是一颗发着淡淡光泽的小圆球。并不起眼。\n"NOR);
                set("value", 100);
                set("no_drop", 1);
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
                return notify_fail("你要吃什么？\n");
        if (me->query_skill_mapped("force") != "bihai-chaosheng")
        {
                me->add("max_neili", -10);
                message_vision(HIR "$N吃下一颗九花玉露丸，只觉得丹田有如刀割，原来所练内功不符，反而大损真元！\n" NOR, me);
                me->unconcious();
                destruct(this_object());
                return 1;
        }

        else {
                me->set("jingli", me->query("eff_jingli"));
                me->receive_curing("jing", 100);
                message_vision(HIG"$N吃下一颗九花玉露丸，精神看来好多了。\n"NOR, this_player());
        
        }
        destruct(this_object());
                return 1;
}

