// niurou.c 红烧牛肉

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("红烧牛肉", ({"hongshao niurou", "rou", "niurou" }));
        set_weight(4000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一块香喷喷的红烧牛肉。\n");
                set("unit", "块");
                set("value", 2000);
                set("food_remaining", 15);
               set("food_supply", 80);
        }
}

