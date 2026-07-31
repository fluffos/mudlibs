// jiuhuawan.c 九花玉露丸
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
        set_name("九花玉露丸", ({"jiuhuayulu wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗发着淡淡光泽的小圆球。并不起眼。\n");
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
        if ((int)this_player()->query("eff_qi") ==
            (int)this_player()->query("max_qi"))
                return notify_fail("你现在不需要用药物。\n");
        
if (this_player()->is_busy() || this_player()->is_fighting())
        return notify_fail("你正忙着呢。\n");


 if (me->query_skill_mapped("force") != "bihai-chaosheng")
        {
                me->add("max_neili", -10);
                message_vision(HIR "$N吃下一颗九花玉露丸，只觉得丹田有如刀割，原来所练内功不符，反而大损真元！\n" NOR, me);
                me->unconcious();
                destruct(this_object());
                return 1;
        }

        else {
                me->receive_curing("qi", 500);
                message_vision("$N吃下一颗九花玉露丸，伤势大为好转。\n", this_player());
        
        }
        destruct(this_object());
                return 1;
}

