#include <../under.h>
inherit MONSTER;
 
void create ()
{
        ::create();
        set_level(1);
        set_name( "mob", "测试mob" );
        add ("id", ({ "mob", }) );
        set_short( "测试mob" );
        set_long( @C_LONG
你眼前是一个测试mob,因为正式的mob还没写...所以他在这充数。
C_LONG
        );
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "个" );
    set ("weight", 400);
}
