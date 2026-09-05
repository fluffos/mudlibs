//bleeding流血

#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
	int damage = 300;
	int ratio;
	
	ratio = me->query("pokong/bonus");
	if(ratio > 10) ratio = 10;//考虑群体作战时的上限
	
   	if( !living(me) )
   	message("vision", HIR + me->name() + HIR"身受重伤，鲜血汩汩而流。\n"NOR, environment(me), ({me}));
	else
	{
      		tell_object(me, HIR"你不停的流血，看来支撑不了多久了！\n" NOR );
           message("vision", HIR + me->name() + HIR"不停的流血，身体微微晃动已经站立不稳。\n"NOR, environment(me), ({me}));
      	}
	me->receive_wound("qi", damage * ratio, me->query("pokong/killer"));
    COMBAT_D->report_status(me);
	if (me->query("eff_qi") < 500) me->unconcious();
	me->apply_condition("bleeding", duration - 1);
   	if( duration < 1 )
   	{
   		me->delete("pokong");
   		tell_object(me,HIW"你的伤口终于愈合不再流血了。\n"NOR);
   		return 0;
   	}
   	return CND_CONTINUE;
}
