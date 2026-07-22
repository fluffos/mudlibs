#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("indigo robe","藏青长袍");
        add("id",({"robe"}) );
        set_short("藏青长袍");
        set_long(
"这是一件蓝青色的丝面棉里长袍，上面绣著一些花鸟。通常是一些文人雅士所穿，据"
"说冬暖夏凉。\n"
        );
        set( "unit", "件" );
        set( "weight", 150 );
        set( "type", "body" );
        set( "material","cloth" );
        set( "armor_class", 20 );
        set( "defense_bonus", 8 );
        set( "special_defense",( [ "fire":10,"cold":10 ] ));
        set( "value", ({ 150, "gold" }) );
}
