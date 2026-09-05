#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name(WHT"酥油茶"NOR, ({"suyou cha", "tea", "cha" }));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一碗混合着酥油，马奶和茶砖的酥油茶，是西藏地区的特产食品。\n");
                set("unit", "壶");
                set("base_unit", "碗");
                set("base_weight", 100);
                set("value", 1);
                set("drink_supply", 30);
                set("food_supply", 30);
        }
        set_amount(5);
}

void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        if (arg!="suyou cha" && arg!="tea" && arg!="cha") return 0;
        if (this_player()->is_busy())
                return notify_fail("你上一个动作还没有完成。\n");

        if ((int)this_player()->query("water")
                >= (int)this_player()->max_water_capacity() )
                return notify_fail("你已经喝得太多了，再也灌不下一滴水了。\n");
        if ((int)this_player()->query("food")
                >= (int)this_player()->max_food_capacity() )
                return notify_fail("你已经吃得太多了，再也撑不下任何东西了。\n");

        this_player()->add("water", (int)query("drink_supply"));
        this_player()->add("food", (int)query("food_supply"));

        if( this_player()->is_fighting() ) this_player()->start_busy(2);

        if (query_amount()>1 ) {
                message_vision("$N端起一碗"+WHT"酥油茶"+NOR"喝了一大口，长出了口气，满意的点了点头。\n",this_player());
        }
        else {
                message_vision("$N仰脖把剩下的"+WHT"酥油茶"+NOR"一饮而尽，顺手用衣袖在嘴边抹了抹。\n",this_player());
        }
        add_amount(-1);
        return 1;
}

