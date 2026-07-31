// hunyuandan.c 混元丹 
#include <ansi.h>

inherit COMBINED_ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(YEL"混元丹"NOR, ({"hunyuan dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "些");
                set("base_unit", "颗");
                set("long", "一颗略带香气的药丸．\n");
set("value", 600);
                                set("drug_type", "良药");
        }
     set_amount(1);
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("你要吃什么药？\n");
        else {
                this_player()->receive_curing("jing", 40);
                message_vision("$N吃下一颗混元丹，脸色看起来好多了．\n",
this_player());
         add_amount(-1);
                return 1;
        }
}
