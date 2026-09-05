// xrtt.c 鲜肉汤团 by hubo

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("鲜肉汤团", ({"xianrou tangtuan", "tangtuan"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一碗热气腾腾的鲜肉汤团\n");
                set("unit", "碗");
                set("value", 4000);
                set("food_remaining", 5);
               set("food_supply", 30);
        }
}