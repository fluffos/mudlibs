inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("鹿肉", ({"lu rou", "rou"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一块肥嫩的鹿肉。\n");
                set("unit", "块");
                set("value", 200);
                set("food_remaining", 8);
                set("food_supply", 50);
        }
}