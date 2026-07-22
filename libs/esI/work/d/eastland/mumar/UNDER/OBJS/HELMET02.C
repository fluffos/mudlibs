#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("highsteel helmet","青钢盔");
        add("id",({"helmet"}) );
        set_short("青钢盔");
        set_long(
"这是一顶用青钢铸成的金属头盔，看起来相当沉重。\n"
        );
        set( "unit", "顶" );
        set( "weight", 150 );
        set( "type", "head" );
        set( "material","heavy_metal" );
        set( "armor_class", 7 );
        set( "defense_bonus", 0 );
        set( "value", ({ 850, "silver" }) );
}
