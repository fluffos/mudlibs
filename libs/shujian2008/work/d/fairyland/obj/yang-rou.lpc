// yang-rou.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("羊肉", ({"yang rou", "rou"}));
        set_weight(900);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一块又肥又香的羊肉。\n");
                set("unit", "块");
                set("food_remaining", 3);
                set("food_supply", 40);
        }
}
