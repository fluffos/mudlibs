//Cracked by Roath
// d/murong/obj/ling2.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(MAG"白菱"NOR, ({"hong ling", "ling" }));
        set_weight(180);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是太湖特产的白菱,既能解渴又能充饥。\n");
                set("unit", "只");
                set("value", 120);
                set("remaining", 3);
                set("drink_supply", 20);
                set("food_supply", 20);
        }
}

void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        if (arg!="hong ling" && arg!="ling") return 0;
        if (this_player()->is_busy())
                return notify_fail("你上一个动作还没有完成。\n");

        if ((int)this_player()->query("water")
                >= (int)this_player()->max_water_capacity() )
                return notify_fail("你已经喝得太多了，再也灌不下一滴水了。\n");
        if ((int)this_player()->query("food")
                >= (int)this_player()->max_food_capacity() )
                return notify_fail("你已经吃得太多了，再也撑不下任何东西了。\n");

        set("value", 0);
        this_player()->add("water", (int)query("drink_supply"));
        this_player()->add("food", (int)query("food_supply"));

        if( this_player()->is_fighting() ) this_player()->start_busy(2);

        add("remaining", -1);
        if (query("remaining")) {
                message_vision("$N拿起只白菱,大口大口吃了起来。\n",this_player());
        }
        else {
                message_vision("$N一口就将剩下的白菱吞下肚。\n",this_player());
                destruct(this_object());
        }
        return 1;
}
