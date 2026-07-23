// xzhang.c 熊掌

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("熊掌", ({"xiong zhang", "xiong"}));
        set_weight(900);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一只又肥又大的大熊掌。\n");
                set("unit", "块");
                set("value", 10000);
                set("food_remaining", 6);
                set("food_supply", 60);
        }
}
