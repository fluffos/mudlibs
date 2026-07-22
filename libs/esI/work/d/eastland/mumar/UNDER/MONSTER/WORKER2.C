#include <../under.h>
inherit MONSTER;
 
void create ()
{
        ::create();
        set_level(10);
        set_name( "worker soldier", "工兵" );
        add ("id", ({ "worker","soldier" }) );
        set_short( "工兵" );
        set_long( @C_LONG
你看到一个身体健壮的工兵，正在这儿努力地工作著。
C_LONG
        );
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "个" );
    set ("weight", 400);
    wield_weapon(OBJS"scissors");
}
