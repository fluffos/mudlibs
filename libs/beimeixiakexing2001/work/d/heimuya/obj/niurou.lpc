//Cracked by Roath
// turou.c 牛肉

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("牛肉", ({"niu rou", "rou", "niu"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一碟香喷喷的牛肉\n");
                set("unit", "碟");
                set("value", 100);
                set("food_remaining", 4);
                set("food_supply", 50);
        }
}
