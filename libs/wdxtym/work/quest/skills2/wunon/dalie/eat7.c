// Ã«Ëñ /clone/eat/food/mao_sun.c
// by lala, 1997-12-16

#include <ansi.h>

inherit ITEM;

inherit F_FOOD;

void create()
{
    set_name(CYN"ÉßÈâ"NOR, ({"liewu7"}));
    set_weight(50000);
		if( clonep() )
		set_default_object(__FILE__);
	else {
    set("long", "Ò»¿éÉßÈâ£¡\n");


        set( "unit", "¸ö" );
        set( "value", 700 + random( 500 ) );
        set( "food_remaining", 5 );
        set( "food_supply", 25 );
	}
}
