#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
    me->apply_condition("thcon", 2 );
    me->add( "th_exp", 45+random( 20 ) );
    me->improve_skill( "force", 20+random( 30 ) );
    me->improve_skill( "literate", 20+random(20) );
    return 1;
}

