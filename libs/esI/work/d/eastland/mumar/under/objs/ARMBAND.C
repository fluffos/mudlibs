#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("cross armband","十字臂章");
        add("id",({"armband"}) );
        set_short("十字臂章");
        set_long(
"这是一个用白色纱布制成的臂章，上面用朱砂绘上了一个象徵医者的红色十字。\n"
        );
        set( "unit", "个" );
        set( "weight", 30 );
        set( "type", "arms" );
        set( "material", "healer" );
        set( "armor_class", 1 );
        set( "defense_bonus", 4 );
        set( "extra_skills",([ "clot":5,"aid":5,"operation":5 ]));
        set( "value", ({ 1000, "silver" }) );
}
