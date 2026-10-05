#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name( "golden needle", "金针");
        add ("id",({ "dagger","needle" }) );
        set_short("金针");
        set_long(
"这是一只五寸长的细长金针。\n"
        );
        set( "unit", "只");
        set( "weapon_class", 42 );
        set( "type", "dagger" );
        set( "min_damage", 25 );
        set( "max_damage", 45 );
        set( "weight", 20 );
        set( "value", ({ 500, "gold" }) );
        set( "no_sale",1 );
}
