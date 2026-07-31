//Cracked by Roath
// chunjuan.c 春卷

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("春卷", ({"chun juan", "eggroll"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一碟炸的金黄的春卷。\n");
                set("unit", "碟");
                set("value", 10);
                set("food_remaining", 3);
                set("food_supply", 15);
        }
}
