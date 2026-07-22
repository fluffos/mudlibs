#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name("scissors", "破坏剪");
        add ("id",({ "scissors" }) );
        set_short("破坏剪");
        set_long(
"一只破坏剪，可以用来剪断(scissor)线，甚至铁丝。\n"
        );
        set( "unit", "把" );
        set( "weapon_class", 5 );
        set( "type", "shortblade" );
        set( "min_damage", 5 );
        set( "max_damage", 10 );
        set( "weight", 80 );
        set( "value", ({ 200, "silver" }) );
}
