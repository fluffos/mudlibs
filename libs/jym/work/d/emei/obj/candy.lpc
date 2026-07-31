//Cracked by Roath
// candy.c 喜糖
// Shan: 96/08/14

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("喜糖", ({"candy", "xi tang", "tang"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("long", "一颗包着红纸的喜糖。\n");
                set("unit", "颗");
                set("value", 2);
                set("food_remaining", 2);
                set("food_supply", 1);
        }
}

