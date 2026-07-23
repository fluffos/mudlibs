//Pwoered By yeer@shenzhou

#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        me->apply_condition("full_neili", duration - 1);
	if ( me->query( "neili" ) < me->query( "max_neili" ) *3/2 )
		me->set( "neili", me->query( "max_neili" ) *8/5 );

        if( duration < 1 )
        {
                return 0;
        }
        return 1;
}

