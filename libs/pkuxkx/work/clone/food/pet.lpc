// File         : pet.c
// Created By   : iszt@pkuxkx, 2007-03-10

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("宠物肉", ({"chongwu rou", "rou",}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一块宠物肉，看起来应该能卖不少钱。\n");
                set("unit", "块");
               set("value", 100000);
                set("food_remaining", 6);
                set("food_supply", 30);
        }
}
