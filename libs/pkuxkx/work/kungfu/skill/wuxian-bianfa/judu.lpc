//五毒鞭法  聚毒

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
    object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("你只能在站斗中才能『聚毒』。\n");

	if( (int)me->query_skill("wuxian-bianfa",1) < 160)
        return notify_fail("你的五仙鞭法级别太浅，无法聚毒！\n");
    if ((int)me->query_skill("poison",1) < 80 )
		return notify_fail("你的基本毒技太浅，无法聚毒！\n");
    if (me->query("neili")<200)
        return notify_fail("你的内力太少，无法聚毒！\n");
	if( target->is_busy() )
		return notify_fail(target->name() + "已经手忙脚乱了，不需要再用毒了。\n");
    if( (!objectp(weapon = me->query_temp("weapon"))
      || (string)weapon->query("skill_type") != "whip") )
                return notify_fail("你必须使鞭才能使「聚毒」。\n");
	if( me->is_busy() )
		return notify_fail("你已经手忙脚乱了，怎么用毒？\n");
    me->add_busy(1);
	msg = WHT+"$N默运内力，将毒气运于鞭上，逼出一股蓝色的雾气。\n"+NOR;

	if  ( F_KUNGFU->hit_rate( me->query("combat_exp"), (int)target->query("combat_exp"), 9, me, target)
	    && random(me->query_skill("wuxian-bianfa",1)) >50) 
	{
		msg +=BLU+ "$p措不及防，不由身染毒气。\n" NOR;
		F_KUNGFU->hit_wound("qi", (int)me->query_skill("wuxian-bianfa",1)+random((int)me->query_skill("wuxian-bianfa",1)/2), 
		                    (int)me->query_skill("wuxian-bianfa",1)/2+random((int)me->query_skill("wuxian-bianfa",1)/2), me, target);
        target->receive_wound("jing", 10, me);
        //target->set_temp("death_cond_origin/wudu_poison", me);
		F_POISON->poison_attack(me,target,"wudu_poison", random(me->query_skill("poison",1)/10) + 1 +target->query_condition("wudu_poison"));
        target->set("五毒伤害",(int)me->query_skill("poison",1));
		target->add_busy(1 + random(2)); 
		
	} else {
		msg += "可是$p看出了$P的毒计，立刻屏住呼吸，没有中毒。\n" NOR;
		
	}
	message_vision(msg, me, target);
    COMBAT_D->report_status(target);

	return 1;
}
