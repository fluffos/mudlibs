// ill_dongshang.c


#include <condition.h>

inherit ILLNESS;

string name() { return "ill_dongshang"; }

int min_qi_needed() { return 10; }

int update_condition(object me, int duration)
{
	if( duration < 1 ) return 0;

	message("vision", HIG + me->name() + "的肢体僵直青肿，看来被冻伤了。"NOR"\n",environment(me), me);

	if( !living(me) && me->query("qi") < 1 ) {
		me->set_temp("die_reason", "被活活冻死了");
		me->die();
		return 0;
	}
	else
		tell_object(me, HIB "你觉得肢体末端一阵僵直，看来是被冻伤了！"NOR"\n" );

	if(me->query("qi")>1)
		me->receive_damage("qi", 1);
	if(me->query("eff_qi")>1)
		me->receive_wound("qi", 1);
	me->apply_condition(name(), duration - 1);

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}
