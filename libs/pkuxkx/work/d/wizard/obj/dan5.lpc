// xierou.c 蟹肉
// hongdou 98.09.20

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("十兆年火龙丹", ({"iszt dan", "dan"}));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一颗火龙的内丹。\n");
                set("unit", "块");
                set("value", 200);
                set("food_remaining", 4);
                set("food_supply", 4);
        }
}

