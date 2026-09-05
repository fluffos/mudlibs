// xierou.c 蟹肉
// hongdou 98.09.20

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("蟹肉", ({"xie rou", "rou"}));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "纯白、甘美、营养丰富的海蟹肉\n");
                set("unit", "块");
                set("value", 200);
                set("food_remaining", 4);
                set("food_supply", 10);
        }
}

