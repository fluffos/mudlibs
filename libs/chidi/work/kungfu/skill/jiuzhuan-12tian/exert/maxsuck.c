#include <ansi.h>
inherit F_SSERVER;
int exert(object me, object target)
{
    int sp, dp,max_suck,skill,top_limit;
    if ( target == me )
        target = offensive_target(me);
    if( !objectp(target) || environment(me)!=environment(target)||target->query("id") == "mu ren"|| target->query("id") == "tong ren")
        return notify_fail("你要吸谁的内力？\n");
    
    //if ( me->query_temp("sucked") )
    //    return notify_fail("你刚刚吸取过内力，真气未能回转。\n");
    if (target->query("age") < 18)
        return notify_fail("小孩子能有什么内力?\n");
    if (objectp(me->query_temp("weapon")) )
        return notify_fail("你必须空手才能施用！\n");

	skill=(int)me->query_skill("jiuzhuan-12tian",1);
	if (skill > 10000) skill = 10000;
	if (skill < 50 || (int)me->query("max_neili") > skill*5000 )
		return notify_fail("你的阴阳九转十二重天功力不够，不能吸取对方的内力！\n");
	if( (int)me->query("neili",1) < 100 )
		return notify_fail("你的内力不够，不能使用阴阳九转十二重天。\n");
	if( (int)target->query("max_neili") < 60  || !living(target))
		return notify_fail( target->name() + "已经内力涣散，你已经无法从他体内吸取任何内力了！\n");
	if(me->is_busy()) return notify_fail("你现在正忙着吸取内力！\n");

    if (!me->query_condition("maxsuckcond"))
    {
		message_vision(HIM "$N使出"NOR+HIY"阴阳九转十二重天"HIM"猛地对准$n的膻中大穴按了上去！\n" NOR, me, target );
	}
	else
	{
		message_vision(HIM "$N使出"NOR+HIB"阴阳九转十二重天的<吸阳大法>"HIM"猛地对准$n的膻中大穴按了上去！\n" NOR, me, target );
	}

	if ( userp(target)){
		if ( !(me->is_att_killing(target)) )
			me->att_kill_ob(target);
	}  
	if ( living(target) ){
		target->kill_ob(me);
		me->kill_ob(target);
	}
	if((int)target->query("no_suck"))
		return notify_fail( target->name() + "没有任何内力！\n");
	if( (int)target->query("max_neili") <= 0 )
		return notify_fail( target->name() + "没有任何内力！\n");
	sp = me->query_skill("force") + me->query_skill("jiuzhuan-12tian",1);
	dp = target->query_skill("force") + target->query_skill("dodge",1);
	//top_limit = (int)me->query("max_neili") / (int)target->query("max_neili");

	if (( random(sp) > random(dp) ) )
	{
		tell_object(target, HIY "你顿觉全身内力如水银般循孔飞泄而出！\n" NOR);
        tell_object(me, HIG "你觉得" + target->name() + "的内力自手掌源源不绝地流了进来。\n" NOR);

		skill=(int)me->query_skill("jiuzhuan-12tian",1);
		max_suck	= skill / 2;
		if ( target->query("max_neili") < (int)me->query("max_neili") )
			max_suck	= max_suck / ((me->query("max_neili") / target->query("max_neili")) + 1);

		if( max_suck < 1)
			max_suck	= 1;
		if (max_suck > 2200 )
            max_suck=5000;

		if( max_suck < 2000)
			tell_object(me, HIY + target->name() + "已经内力涣散！\n" NOR);

		if (!me->query_condition("maxsuckcond"))
		{
			if ( target->query("max_neili") < max_suck )
				max_suck	= target->query("max_neili");
			target->add("max_neili",  -max_suck);
			me->add("neili", -100);
			me->add("max_neili",  max_suck );

			me->start_busy(1);
			target->start_busy(random(3)+1);
		}
		else
		{
			max_suck	= max_suck * 2;
			if ( target->query("max_neili") < max_suck )
				max_suck	=target->query("max_neili");
			target->add("max_neili",  -max_suck);
			me->add("neili", -100);
			me->add("max_neili",  max_suck );

			me->start_busy(random(1));
			target->start_busy(random(1));
		}
    }
    else
    {   
        message_vision(HIY "可是$p看破了$P的企图，机灵地闪了开去。\n" NOR, me, target);
        me->start_busy(1);
    }
	me->set_temp("sucked", 1);

	if (!me->query_condition("maxsuckcond"))
		call_out("del_sucked", 3, me);
	else
		call_out("del_sucked", 1, me);

    return 1;
}
void del_sucked(object me)
{
    if (!me)    return;
    if ( me->query_temp("sucked"))
        me->delete_temp("sucked");
}
