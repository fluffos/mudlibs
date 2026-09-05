// turou.c 狗肉 for wananta

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("生狗肉", ({"gou rou", "rou"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一块新鲜的狗肉。\n");
                set("unit", "块");
                set("value", 200);
                set("food_remaining", 4);
               set("food_supply", 30);
        }
}

