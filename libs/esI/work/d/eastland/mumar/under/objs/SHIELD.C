#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("highsteel shield","青钢大盾");
        add("id",({"shield"}) );
        set_short( "highsteel shield","青钢大盾");
        set_long(
"这是一面巨大的盾牌，是用青钢所制，看起来似乎可以挡住不少重击。\n"
        );
        set( "unit", "面" );
        set( "weight", 200 );
        set( "type", "shield" );
        set( "material", "heavy_matel" );
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "extra_skills",([ "block":5 ]));
        set( "value", ({ 1600 , "silver" }) );
}
