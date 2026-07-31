// zhuguo.c
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
        if (!wizardp(this_player())) {
                set("no_get", "嘿嘿，做梦吧! \n");
                set("no_drop","朱果你都想扔？\n");
        }

        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIR "朱果" NOR, ({"zhu guo", "guo"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long",
"这是一颗朱果，通体鲜红，一望而知是不可多得的珍品。\n");
                set("value", 100000);
        }

        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
                return notify_fail("你要吃什么？\n");
//        me->set("eff_jing", (int)me->query("max_jing"));
//        me->set("jing", (int)me->query("max_jing"));
//        me->set("eff_qi", (int)me->query("max_qi"));
//        me->set("qi", (int)me->query("max_qi"));
        me->set("qi", (int)me->query("eff_qi"));
        me->set("neili", (int)me->query("max_neili"));
//        me->set("jingli", (int)me->query("max_jingli"));
//        me->set("food", (int)me->max_food_capacity());
//        me->set("water", (int)me->max_water_capacity());
          message_vision(HIR
 "$N吃下一颗朱果，只觉饥渴全消，一股暖流从丹田直冲上来。\n"NOR,me);

        destruct(this_object());
        return 1;
}
