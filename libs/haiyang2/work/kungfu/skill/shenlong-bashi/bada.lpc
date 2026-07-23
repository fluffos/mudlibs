// bada.c 龙形八打 
// 星星lywin 2000/6/12
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill,damage;

	me->clean_up_enemy();
	target = me->select_opponent();
	skill = me->query_skill("shenlong-bashi",1);

	if( !(me->is_fighting() ))
		return notify_fail(HIR"龙形八打" + NOR + "只能对战斗中的对手使用。\n");
 
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("只有空手才能使出" + HIR + "龙形八打。\n" NOR);

	if (!objectp(weapon2 = target->query_temp("weapon")))
	   return notify_fail("对方没有兵刃，你用不上龙形八打。\n");

        if ((int)me->query_skill("shenlong-bashi", 1) < 60 )
		return notify_fail("你的神龙八式等级不够, 不能用此绝招！\n");

        if ((int)me->query_skill("shenlong-xinfa", 1) < 60 )
        return notify_fail(RED"你神龙心法火候不够，使不出「龙形八打」。\n"NOR);

	if( me->query("neili") < 50 )
		return notify_fail("你的内力不够，无法使用此绝招！\n");
 
 	msg = HIY"$N突然纵身上前，使出神龙八式中的绝招神龙八打。
只见$N的一双手勾、挑、撩、切、捺、推、带、摔，舞出漫天手影！\n"NOR;
	message_combatd(msg, me);

	if( random(me->query("combat_exp")) > (target->query("combat_exp") / 2) )
	{
		if(userp(me))
		msg = HIR "结果$n大吃一惊，手中兵器不由得脱手飞出。\n" NOR;
		me->add("neili",-50);
		weapon2->move(environment(target));
		if (weapon2->query("ownmake")==1)
		{
			weapon2->move(target);
			msg += HIG "那可是$n的随身家伙！$n手一伸将它捡回来。\n" NOR;
		}
		me->start_busy(1);
	}
	if( random(me->query("combat_exp")) > (target->query("combat_exp") / 2) )
	{
		if(userp(me))
		msg = HIC "结果$n大吃一惊，一阵忙乱不知所措!\n" NOR;
	target->apply_condition("ill_fashao",60);
	target->apply_condition("ill_kesou",60);
	target->apply_condition("ill_shanghan",60);
	target->apply_condition("ill_zhongshu",60);
	target->apply_condition("ill_dongshang",60);
                target->start_busy(random(6)+2);
	}

	else
	{
		msg = HIR"可惜$n经验丰富，不为所动，$N自己却乱了阵脚。\n"NOR;
		me->start_busy(4);
	}
	message_combatd(msg, me, target);
//	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
