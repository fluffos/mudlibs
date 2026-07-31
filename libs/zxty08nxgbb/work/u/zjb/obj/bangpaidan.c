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
        set_name(HIW"返身丹"NOR, ({"fanshen dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("value", 50000);
        }
        setup();
}

int do_eat(string arg)
{
       
        if (!id(arg))
        return notify_fail("你要吃什么？\n");
         {
               this_player()->delete("banghui");
           this_player()->delete("bh_rank");
this_player()->delete("rank_lv");
                 message_vision(HIR "$N吃下一颗返身单，从此不管帮派内的事了!\n" NOR, this_player());
         }

        destruct(this_object());
        return 1;
}

