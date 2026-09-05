//bleeding流血

#include <ansi.h>

int update_condition(object me, int duration)
{
	int damage = 200;
   	if( !living(me) )
   	message("vision", HIR + me->name() + HIR"手腕已断，鲜血汩汩而流。\n"NOR, environment(me), ({me}));
	else
	{
      		tell_object(me, HIR"你的手腕不停的流血，看来支撑不了多久了！\n" NOR );
      		message("vision", HIR + me->name() + HIR"的手腕不停的流血，身体微微晃动已经站立不稳。\n", environment(me), ({me}));
      	}
	me->receive_wound("qi", damage * me->query("cixue/bonus"), me->query("cixue/killer"));
	if (me->query("eff_qi") < 500) me->unconcious();
	me->apply_condition("cixue_bleeding", duration - 1);
   	if( duration < 1 )
   	{
   		me->delete("cixue");
   		tell_object(me,HIW"你的伤口终于愈合不再流血了。\n"NOR);
   		return 0;
   	}
   	return CND_CONTINUE;
}
