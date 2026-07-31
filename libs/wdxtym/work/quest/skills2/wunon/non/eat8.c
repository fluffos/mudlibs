// 毛笋 /clone/eat/food/mao_sun.c
// by lala, 1997-12-16

#include <ansi.h>

inherit ITEM;

inherit F_FOOD;

void create()
{
    set_name(HIM"桃子"NOR, ({"tao zi", "taozi","peach"}));
    set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
    set("long", "一个大大的歪着嘴笑的大胖桃");


    set("unit", "个");
        set( "value", 700 + random( 600 ) );
        set( "food_remaining", 5 );
        set( "food_supply", 25 );
	}
}

