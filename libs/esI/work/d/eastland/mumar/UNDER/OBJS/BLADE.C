#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name( "nine-dragon blade", "九龙连环刀");
        add ("id",({ "blade" }) );
        set_short("九龙连环刀");
        set_long(
"这是一柄五尺长的沉重大刀，刀身上雕著一只栩栩如生的龙。\n"
        );
        set( "unit", "柄");
        set( "weapon_class", 35 );
        set( "type", "longblade" );
        set( "min_damage", 20 );
        set( "max_damage", 48 );
        set( "weight", 300 );
        set( "value", ({ 400, "gold" }) );
}
