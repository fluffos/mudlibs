#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name("highsteel javelin", "青钢长戈");
        add ("id",({ "javelin" }) );
        set_short("青钢长戈");
        set_long(
            "一把青钢制的长戈，锋芒处闪著青色的寒光，看来也十分锐利。\n"
        );
        set( "unit", "把" );
        set( "weapon_class", 35 );
        set( "type", "thrusting" );
        set( "min_damage", 20 );
        set( "max_damage", 35 );
        set( "weight", 250 );
        set( "value", ({ 850, "silver" }) );
}
