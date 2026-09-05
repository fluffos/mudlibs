// yeguo.c 
// by paladin

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("野果", ({"ye guo", "guo"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一枚青红色的野果，咬一口，入口甚是酸涩.\n");
                set("unit", "颗");
                set("value", 80);
                set("food_remaining", 10);
                set("food_supply", 50);
        }
}
