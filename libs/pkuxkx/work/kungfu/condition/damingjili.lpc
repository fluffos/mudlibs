//大明特技激励 Zine

#include <ansi.h>

int update_condition(object me, int duration)
{
    int ap,dp;
    ap=me->query_temp("mingspecial/jiliap");
    dp=me->query_temp("mingspecial/jilidp");
	if (duration < 1) 
        {
                tell_object(me,"良久，鼓舞的效果消逝了。\n");
                me->add_temp("apply/attack", -ap);
                me->add_temp("apply/damage", -ap);
                me->add_temp("apply/armor",  -dp);
                me->add_temp("apply/parry",  -dp);
                me->delete_temp("mingspecial/jiligot");
                me->delete_temp("mingspecial/jiliap");
                me->delete_temp("mingspecial/jilidp");
		        return 0;
	    }
        me->apply_condition("damingjili", duration - 1);
	    return 1;
}
