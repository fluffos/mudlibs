// dan.c
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
        if (!wizardp(this_player())) {
                set("no_get", "嘿嘿，做梦吧! \n");
                set("no_drop","这么宝贵的仙丹，哪能乱扔! \n");
        }
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIG "仙丹" NOR, ({"dan"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("long",
"这是一枚仙丹，看上去就像一只小小的金葫芦。");
                set("value", 100000);
        }

        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
                return notify_fail("你要吃什么？\n");
        me->set("water", (int)me->max_water_capacity());
        me->set("food", (int)me->max_food_capacity());
        message_vision(HIG
 "$N吃下一粒仙丹，只觉得精神健旺，气血充盈，好爽，太爽了! \n"NOR, me);

        destruct(this_object());
        return 1;
}

