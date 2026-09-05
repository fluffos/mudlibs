// /u/hacky/gumu/obj/jiang.c
// by sulante

#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_drink", "drink");
}
void create()
{
        set_name("玉蜂浆", ({"yufeng jiang", "jiang"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "瓶");
                set("long", GRN"这是古墓派采集无数玉蜂蜜而制成的营养圣品\n"NOR);
                set("value", 100);
        }
        setup();
}
int do_drink(string arg)
{
        object me=this_player();
        if (!id(arg))
                return notify_fail("你要喝什么？\n");
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi", me->query("max_qi"));   
        me->add("max_jingli",random(7)-1);

message_vision(HIY"$N喝下一瓶玉蜂浆，感到精神百倍，份外有力 !\n" NOR, me)
;
        destruct(this_object());
        return 1;
}
