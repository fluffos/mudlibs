// drunk.c
// modified by iszt@pkuxkx, 2007-02-07
inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

string query_type(object me) { return "poison"; }

int update_condition(object me, int duration)
{
	int limit;

    limit = (me->query("con") + (int)me->query_skill("force") / 14 + me->query("neili") / 100) * 2;

    if( !duration ) return 0;

	if( duration > limit && living(me) )
	{
        tell_object(me, "你觉得脑中昏昏沉沉，心中空荡荡的，直想躺下来睡一觉。\n");
        message("vision", me->name() + "摇头晃脑地站都站不稳，显然是蒙汗药的药力发作了。\n",
            environment(me), me);
        if (objectp(me->query_temp("death_cond_origin/slumber_drug")))
        {
            me->set_temp("last_damage_from", me->query_temp("death_cond_origin/slumber_drug"));
            me->set_temp("last_damage_time", time());
        }
		me->unconcious();
		return 0;
	} 
    else if( duration > limit/2 ) 
    {
		tell_object(me, "你觉得脑中昏昏沉沉，心中空荡荡的，直想躺下来睡一觉。\n");
		message("vision", me->name() + "摇头晃脑地站都站不稳，显然是蒙汗药的药力发作了。\n",
			environment(me), me);
			F_POISON->poison_eff(me,"slumber_drug",(["busy":({4,5}),]),1); 
	}
	else {
		tell_object(me, "你察觉到中了蒙汗药，连忙不动声色的暗中运气，所幸并无大碍。\n");
	}

	me->apply_condition("slumber_drug", duration - 1);

	return CND_CONTINUE;
}