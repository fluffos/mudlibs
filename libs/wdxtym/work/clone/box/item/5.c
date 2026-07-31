//wuchangdan.c
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
        set_name(HIR"无常丹"NOR, ({"wuchang dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗晶莹火红的无常丹，经桃花岛主精心练制，
有起死回生之功。\n");
                set("value", 5000);
        }
        setup();
}

int do_eat(string arg)
{
        int fw;
        int force_limit, neili_limit, force_skill, add_skill, improve;

        object me = this_player();

        force_limit = me->query_skill("force")*10;
        neili_limit = me->query("max_neili");
        force_skill = me->query_skill("force", 1);

        if (!id(arg))
        return notify_fail("你要吃什么？\n");
        me->set("jing",me->query("max_jing"));
        me->set("eff_jing",me->query("max_jing"));
        me->set("qi",me->query("max_qi"));
        me->set("eff_qi",me->query("max_qi"));
        me->set("neili",me->query("max_neili"));
        message_vision(HIR"$N吃下一颗无常丹，顿时全身充满力量！\n"NOR,me);
        destruct(this_object());
        return 1;
}
