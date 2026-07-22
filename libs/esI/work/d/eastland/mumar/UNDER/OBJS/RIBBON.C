#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("indigo ribbon","藏青发带");
        add("id",({"ribbon"}) );
        set_short("藏青发带");
        set_long(
"这是一条细长的藏青色丝质发带，是用上好的青蚕丝制成的。\n"
        );
        set( "unit", "条" );
        set( "weight", 80 );
        set( "type", "head" );
        set( "material","cloth" );
        set( "armor_class", 3 );
        set( "defense_bonus", 4 );
        set( "value", ({ 2000, "silver" }) );
}
