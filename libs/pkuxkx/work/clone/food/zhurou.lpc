// File         : zhurou.c
// Created By   : iszt@pkuxkx, 2007-03-10

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("猪肉", ({"zhu rou", "rou", "meat", "pork"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一块热腾腾、香喷喷的猪肉。\n");
                set("unit", "块");
                set("value", 100);
                set("food_remaining", 4);
                set("food_supply", 40);
        }
}
