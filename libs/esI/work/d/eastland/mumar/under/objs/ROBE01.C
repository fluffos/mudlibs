#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("golden robe","金\缕\战袍");
        add("id",({"robe"}) );
        set_short("金\缕\战袍");
        set_long(
"这是一件用金线缝制的战袍，是赵子扬的家传之宝。整件战袍发出亮眼的金黄色\n"
"泽，让人不能直视。\n"
        );
        set( "unit", "件" );
        set( "weight", 170 );
        set( "type", "body" );
        set( "material","light_metal" );
        set( "armor_class", 35 );
        set( "defense_bonus", 4 );
        set( "special_defense",( [ "fire":20,"evil":20 ] ));
        set( "value", ({ 500, "gold" }) );
        set( "no_sale",1 );
}
