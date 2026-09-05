// sjg.c 水晶糕 by hubo

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("水晶糕", ({"shuijing gao", "gao"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一块精美的水晶糕\n");
                set("unit", "块");
                set("value", 200);
                set("food_remaining", 4);
               set("food_supply", 30);
        }
}