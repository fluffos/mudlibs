// jhtzj.c 叫花童子鸡 by hubo

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("叫花童子鸡", ({"tongzi ji", "ji"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一只热气腾腾，香气扑鼻的叫花童子鸡\n");
                set("unit", "只");
                set("value", 4000);
                set("food_remaining", 5);
               set("food_supply", 30);
        }
}