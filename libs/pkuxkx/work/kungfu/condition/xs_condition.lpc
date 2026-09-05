inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>



int update_condition(object me, int duration)
{
	tell_object(me, HIW "一阵淡淡的幽香缠绕着你，那感觉又真实又虚幻，象做梦一般......\n" NOR );
      	message("vision", HIW + "一阵淡淡的幽香飘了过来，你不禁用力闻了闻，好舒服呀！\n转头一看，发现" + me->name() + "站在一旁，幽香环绕，清纯可人。你不禁痴了....\n" + NOR,
            environment(me), me);
        if (me->query("per") < 60)
        {
        	if (random(3) == 1)
        	{
        		me->add("per",1);
        		tell_object(me,HIC "你发现身边的人都在偷偷看你，并听到他们小声议论：哇！" + me->name() + "什么时候变得这么漂亮了也！\n" + NOR);
        	}
        }
      	me->apply_condition("xs_condition", duration - 1);
   	if( duration < 1 ) return 0;
   		return CND_CONTINUE;
}
