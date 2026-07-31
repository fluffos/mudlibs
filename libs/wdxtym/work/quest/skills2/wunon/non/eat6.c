// 毛笋 /clone/eat/food/mao_sun.c
// by lala, 1997-12-16

#include <ansi.h>

inherit ITEM;

inherit F_FOOD;

void create()
{
    set_name(HIY"鸭梨"NOR, ({"ya li","yali","pear"}));
    set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
    set("long", "一个大大的脆生生黄澄澄的鸭梨");


        set( "unit", "个" );
        set( "value", 500 + random( 500 ) );
        set( "food_remaining", 5 );
        set( "food_supply", 25 );
	}
}
