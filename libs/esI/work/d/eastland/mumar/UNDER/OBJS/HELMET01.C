#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("invincible helmet","战神盔");
        add("id",({"helmet"}) );
        set_short("战神盔");
        set_long(
"这是一顶看起来并不起眼的黑色金属头盔，但是却不像一般金属质料那麽冰冷。\n"
        );
        set( "unit", "顶" );
        set( "weight", 100 );
        set( "type", "head" );
        set( "material","light_metal" );
        set( "armor_class", 8 );
        set( "defense_bonus", 2 );
        set( "special_defense",(["mental":20,"electric":20,"none":20]));
        set( "value", ({ 250, "gold" }) );
        set( "no_sale",1 );
}
