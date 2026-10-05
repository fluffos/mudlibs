#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("golden shoulder","黄金肩甲");
        add("id",({"shoulder"}) );
        set_short("黄金肩甲");
        set_long(
"这是一对黄金肩甲，上面雕著一对凤凰，据说是东方大国当今皇上因战功赐给赵\n"
"子扬的护甲。\n"
        );
        set( "unit", "对" );
        set( "weight", 200 );
        set( "type", "arms" );
        set( "material","heavy_metal" );
        set( "armor_class", 4 );
        set( "defense_bonus", 4 );
        set( "special_defense",( [ "acid":20 ] ));
        set( "value", ({ 200, "gold" }) );
        set( "no_sale",1 );
}
