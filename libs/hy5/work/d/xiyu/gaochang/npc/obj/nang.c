// nang.c
//hydra 
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name("馕", ({"nang"}));
    set_weight(100);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "一种饼，象石头一样硬\n");
        set("unit", "个");
        set("value", 50);
        set("food_remaining", 4);
        set("food_supply", 50);
    }
}

