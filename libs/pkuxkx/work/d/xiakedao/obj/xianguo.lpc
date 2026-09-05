

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("鲜果", ({"xianguo", "guo"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一粒翠绿的鲜果。\n");
                set("unit", "粒");
                set("value", 40);
                set("food_remaining", 1);
                set("food_supply", 50);
        }
}

