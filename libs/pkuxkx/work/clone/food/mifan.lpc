// File         : mifan.c
// Created By   : iszt@pkuxkx, 2007-03-23

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("米饭", ({"mi fan", "fan", "rice"}));
        set_weight(150);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一碗大米饭，最是顶饱。\n");
                set("unit", "碗");
                set("value", 20);
                set("food_remaining", 4);
                set("food_supply", 30);
        }
}
