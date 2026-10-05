#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name("spade", "圆锹");
        add ("id",({ "spade" }) );
        set_short("圆锹");
        set_long(
"一把圆锹，应该可以用来挖(dig)土。\n"
        );
        set( "unit", "把" );
        set( "weapon_class", 5 );
        set( "type", "axe" );
        set( "min_damage", 6 );
        set( "max_damage", 12 );
        set( "weight", 100 );
        set( "value", ({ 200, "silver" }) );
}
