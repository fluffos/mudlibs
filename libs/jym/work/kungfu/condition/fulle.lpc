#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
    me->apply_condition("fulle", 2 );
    me->add( "combat_exp", 20+random(10) );
    me->add( "combat_exp_last", 20+random(10) );
    me->improve_skill( "force", 20+random( 30 ) );
    me->improve_skill( "literate", 20+random(20) );
    return 1;
}

