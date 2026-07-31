// jiaohua-ji.c 叫化鸡

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("叫化鸡", ({"jiaohua ji", "ji"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一只香喷喷的叫化鸡\n");
                set("unit", "只");
                set("value", 200);
                set("food_remaining", 4);
                set("food_supply", 50);
        }
}
