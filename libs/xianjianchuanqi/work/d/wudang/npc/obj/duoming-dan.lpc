// duoming-dan.c 

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
        set_name(HIW"白虎夺命丹"NOR, ({"duoming dan","dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗晶莹如珠的救命药丸。\n");
                set("value", 1000);
//                set("no_drop", "这样东西不能离开你。\n");
        }

        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
        return notify_fail("你要吃什么？\n");

        message_vision(HIW "$N吃下一颗白虎夺命丹，但觉一股暖流自丹田升起,随即遍布四肢,浑身说不出有多舒服！\n" NOR, me);
        me->reincarnate();
        me->set("qi", me->query("max_qi"));
        me->set("jing", me->query("max_jing"));
        me->set("jingli", me->query("eff_jingli"));
        me->set("neili", me->query("max_neili"));
        me->set("food", me->max_food_capacity());
        me->set("water", me->max_water_capacity());
        destruct(this_object());

        return 1;
}

