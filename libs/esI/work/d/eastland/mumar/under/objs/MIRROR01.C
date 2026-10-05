#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("Wu-Ley mirror","五雷掩心镜");
        add("id",({"mirror"}) );
        set_short("五雷掩心镜");
        set_long(
"这是一面表面画满了咒文的掩心镜，镜的外围镶著一条五爪金龙。\n"
        );
        set( "unit", "面" );
        set( "weight",70 );
        set( "type", "misc" );
        set( "material","heavy_metal" );
        set( "armor_class", 0 );
        set( "defense_bonus", 8 );
        set( "special_defense",( [ "electric":20 ] ));
        set( "value", ({ 200, "gold" }) );
        set( "no_sale",1 );
}
