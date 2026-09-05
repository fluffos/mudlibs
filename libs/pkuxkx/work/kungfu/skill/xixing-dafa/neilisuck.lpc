// neilisuck.c

#include <ansi.h>

int exert(object me, object target)
{
	int sp, dp;
	
    if ( me == target )
        return notify_fail("你不能吸取自己的内力！\n");
	if( !objectp(target) )
		return notify_fail("你要吸取谁的内力？\n");
	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过内力！\n");
	if( (int)me->query_skill("xixing-dafa",1) < 100 )
		return notify_fail("你的吸星大法功力不够，不能吸取对方的内力！n");
	if( (int)me->query("neili",1) < 50 )
		return notify_fail("你的内力不够，不能使用吸星大法。\n");
	if( (int)target->query("max_neili") <= 0 )
		return notify_fail( target->name() +
		"没有任何内力！\n");
    if (target->query("neili")<10)
        return notify_fail( target->name() +"体内内力空空如也！\n");
	message_vision(
		HIR "$N右掌突然伸出，牢牢扣住了$n的手腕！\n\n" NOR,
		me, target );
	if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
	sp = me->query_skill("force",1) + me->query_skill("dodge",1) + me->query_skill("xixing-dafa",1);
	dp = target->query_skill("force",1) + target->query_skill("dodge",1) + me->query("kar",1);
	me->set_temp("sucked", 1);		
	if( F_KUNGFU->hit_rate( sp, dp, 9, me, target) )
	{
        if (me->query("neili") > me->query("max_neili")*3)
        {
            call_out("del_sucked", 4, me);
            tell_object(me,"你忽然觉得已经达到自己的内力支持的上限。\n");
            return 1;
        }
        else
        {
            tell_object(target, HIR "你猛觉右腕“内关”“外关”两处穴道中内力源源外泄!\n" NOR);
            tell_object(me, HIG "你觉得" + target->name() + "的内力自手掌源源不绝地流了进来。\n" NOR);
            target->add("neili", -1*sp/3 );
            me->add("neili", sp/3 );
            me->start_busy(random(4));
            me->add("neili", -10);
            call_out("goonexert", 4, me,target);
            return 1;
        }
		/*if (target->query("neili")<0)
		{
			tell_object(target,HIR "你内力已尽，身子一软，便晕了过去。\n" NOR);
			tell_object(me,HIG "" + target->name() + "的内力已经被你吸完了！\n" NOR);
			target->set("neili",0);
			//target->unconcious();
			call_out("del_sucked",4,me);
		}
		if (me->query("neili") > me->query("max_neili")*3)
		{
			if (me->query("max_neili") > 10*me->query_skill("force"))
				tell_object(me,"你忽然觉得自己的内功有限，无法支持如此之高的内力。\n");//之前吸都吸过了，再tell_object一下有用吗？Zine
			else
			{
				tell_object(me,"你的内力增加了！\n");
				me->add("max_neili",1);
				me->set("neili",0);
			}
		}*/
		
	}
	else
	{	
		message_vision(HIY "可是$p看破了$P的企图，轻轻一甩，躲过了$P的进攻。\n" NOR, me, target);
		me->start_busy(4);
		call_out("del_sucked", 4, me);
        return 1;
	}
	
	
}

void del_sucked(object me)
{
        if (!me) return;
	if ( me->query_temp("sucked"))
		me->delete_temp("sucked");
}

void goonexert(object me,object target)
{
	int sp,dp,i;
	object *enemy;
        if (!me) return;
	enemy = me->query_enemy() - ({ 0 });
	for(i=0; i<sizeof(enemy); i++)
	{
		if(enemy[i] == target)
		{
			sp = me->query_skill("force",1) + me->query_skill("dodge",1) + me->query_skill("xixing-dafa",1);
			dp = target->query_skill("force",1) + target->query_skill("dodge",1) + me->query("kar",1);
			me->set_temp("sucked", 1);		
			
			if( F_KUNGFU->hit_rate( sp, dp, 9, me, target) )
			{
				tell_object(target, HIR "你猛觉右腕“内关”“外关”两处穴道中内力源源外泄!\n" NOR);
				tell_object(me, HIG "你觉得" + target->name() + "的内力自手掌源源不绝地流了进来。\n" NOR);
				
				target->add("neili", -1*sp/3 );
				me->add("neili", sp/3 );
				if (me->query("neili") > me->query("max_neili")*2)
				{
					if (me->query("max_neili") > 10*me->query_skill("force"))
						tell_object(me,"你忽然觉得自己的内功有限，无法支持如此之高的内力。\n");
					else
					{
						tell_object(me,"你的内力增加了！\n");
						me->add("max_neili",1);
						me->set("neili",5);
					}
				}
				me->start_busy(random(4));
				me->add("neili", -5);
				if (target->query("neili")<0)
				{
					tell_object(target,HIR "你内力已尽，身子一软，便晕了过去。\n" NOR);
					tell_object(me,HIG "" + target->name() + "的内力已经被你吸完了！\n" NOR);
					target->set("neili",0);
//					target->unconcious();
					call_out("del_sucked",4,me);
				}
				else
				{
					call_out("goonexert", 4, me,target);
				}
			}
			else
			{	
				message_vision(HIY "可是$p看破了$P的企图，轻轻一甩，躲过了$P的进攻。\n" NOR, me, target);
				me->start_busy(4);
				call_out("del_sucked", 4, me);
			}
		}
	}
	call_out("del_sucked",1,me);
}

