// niaodan.c  鸟蛋
// hongdou 98.10.04

#include <ansi.h>

inherit ITEM;

inherit F_FOOD;

void create()
{
   set_name("鸟蛋"NOR,({"niao dan","dan"}));
   set_weight(100);
   if(clonep() )
     set_default_object(__FILE__);
   else{
   	set("long","一枚海鸟下的蛋。\n");
	set("unit","枚");
   	set("value",500);
	set("food_remaining", 1);
        set("food_supply", 50);
     }
}

