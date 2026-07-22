#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name("weapon", "测试用weapon");
        add ("id",({ "weapon" }) );
        set_short("测试用weapon");
        set_long(
            "这是测试用的weapon,因为正式的weapin还没写,所以先用它来充数。\n"
        );
        set( "unit", "把" );
        set( "weapon_class", 1 );
        set( "type", "thrusting" );
        set( "min_damage", 1 );
        set( "max_damage", 5 );
        set( "weight", 100 );
        set( "value", ({ 1, "silver" }) );
}
