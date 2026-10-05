#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("hexagon plate","六方甲");
        add("id",({"plate","armor"}) );
        set_short("六方甲");
        set_long(
"这是东方大国正在研发中的新式战甲，看起来十分笨重和坚硬，似乎有相当不错\n"
"的防护力。\n"
        );
        set( "unit", "副" );
        set( "weight", 300 );
        set( "type", "body" );
        set( "material","heavy_metal" );
        set( "armor_class", 30 );
        set( "defense_bonus", 2 );
        set( "extra_skills",([ "defend":10 ]));
        set( "value", ({ 300, "gold" }) );
        set( "no_sale",1 );
}
