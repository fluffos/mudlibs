// File         : mantou.c
// Created By   : iszt@pkuxkx, 2007-03-23

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("馒头", ({"man tou", "mantou", "man"}));
        set_weight(90);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个大白馒头。北方人喜面食，每餐馒头必不可少。\n");
                set("unit", "碗");
                set("value", 20);
                set("food_remaining", 4);
                set("food_supply", 20);
        }
}
