// Ã«Ëñ /clone/eat/food/mao_sun.c
// by lala, 1997-12-16

#include <ansi.h>

inherit ITEM;

inherit F_FOOD;

void create()
{
    set_name(HIC"Å£Èâ"NOR, ({"liewu6"}));
    set_weight(50000);
    set("long", "Ò»¿éÅ£Èâ");

		set("no_get",1);
		set("no_give",1);
		set("no_steal",1);

		set("no_put",1);

        set( "unit", "¿é" );
        set( "value", 600 + random( 500 ) );
        set( "food_remaining", 5 );
        set( "food_supply", 25 );
}
