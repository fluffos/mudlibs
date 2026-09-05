//人参
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
        set_name(HIG"千年人参"NOR, ({"ren shen", "shen", "renshen"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "产自长白山的千年人参，能使人恢复内力。\n");
                set("value", 100000);
        }
        setup();
}

int do_eat(string arg)
{
        if (arg!="ren shen" && arg!="shen"&& arg!="renshen")
                return notify_fail("你要吃什么药？\n");
                this_player()->set("neili", this_player()->query("max_neili")+random(100));
                message_vision("$N吃下一只人参，顿时你觉得气息充足。\n", this_player());
                destruct(this_object());
                return 1;
}
