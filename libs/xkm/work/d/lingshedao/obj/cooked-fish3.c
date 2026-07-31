//Cracked by Roath
//fear 2002 1 31
// /d/lingshedao/obj/cooked-fish3.c
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(RED"红辣椒爆炒鳝片"NOR, ({"baochao shanpian", "shanpian"}));
        set_weight(1500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盘红辣椒爆炒鳝片。鳝鱼肉嫩而味鲜美，据古方记载，还可去湿毒，并有点补血作用。\n");
                set("unit", "盘");
                set("value", 350);
                set("food_remaining", 4);
                set("food_supply", 66);
        }
}
