//Cracked by Roath
// jianbing.c 煎饼

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("煎饼", ({"jian bing", "pancake"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一碟焦香的煎饼。\n");
                set("unit", "碟");
                set("value", 10);
                set("food_remaining", 3);
                set("food_supply", 15);
        }
}
