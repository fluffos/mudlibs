

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("密瓜", ({"migua", "gua", "melon"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一颗香甜的密瓜。\n");
                set("unit", "颗");
                set("value", 40);
                set("food_remaining", 1);
                set("food_supply", 50);
        }
}

