// peanut.c 花生
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("果汁橡皮糖", ({"xone suger", "suger"}));
        set_weight(60);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一颗美味可口的,果汁橡皮糖 。\n");
                set("unit", "颗");
                set("value", 30);
                set("food_remaining", 1);
                set("food_supply", 30);
        }
}

