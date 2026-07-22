#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name( "double-side axe", "双面大斧");
        add ("id",({ "axe" }) );
        set_short("双面大斧");
        set_long(
"一只其重无比的大斧，和一般斧头不同的是有两面斧锋，看走来极具杀伤力。\n"
        );
        set( "unit", "柄");
        set( "weapon_class", 40 );
        set( "type", "axe" );
        set( "min_damage", 25 );
        set( "max_damage", 45 );
        set( "weight", 250 );
        set( "value", ({ 3000, "silver" }) );
        set( "bleeding",15 );
        set( "nosecond", 1 );
}
