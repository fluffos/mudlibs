// 毛笋 /clone/eat/food/mao_sun.c
// by lala, 1997-12-16

#include <ansi.h>

inherit ITEM;

inherit F_FOOD;

void create()
{
    set_name(HIC"海鳝"NOR, ({"yu6"}));
    set_weight(30000);
    if ( clonep() )
            set_default_object( __FILE__ );
    else {
    set("long", "一条海鳝\n");
        set( "unit", "条" );

        set( "value", 1 );
        set( "food_remaining", 5 );
        set( "food_supply", 25 );
	}
}
