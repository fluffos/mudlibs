// xzhang.c 雪鸡肉

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("雪鸡肉", ({"xueji rou", "rou"}));
        set_weight(900);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一只又肥又白的雪鸡肉。\n");
                set("unit", "块");
                set("food_remaining", 3);
                set("food_supply", 40);
        }
}
