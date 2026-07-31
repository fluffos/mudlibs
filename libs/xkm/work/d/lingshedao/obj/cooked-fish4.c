//Cracked by Roath
//fear 2002 1 31
// /d/lingshedao/obj/cooked-fish4.c
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(CYN"ÇåÌÀÓãÍè"NOR, ({"qingtang yuwan", "yuwan"}));
        set_weight(1500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»ÍëÇåÌÀÓãÍè¡£ÌÀÇå¡¢Î¶ÏÊ¡¢»¬ÄÛ¡¢½à°×¡£\n");
                set("unit", "Íë");
                set("value", 200);
                set("food_remaining", 4);
                set("food_supply", 56);
        }
}
