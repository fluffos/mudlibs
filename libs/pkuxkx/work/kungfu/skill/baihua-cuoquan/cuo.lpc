// cuoluan.c 百花错乱
// by hubo 2008-4-27

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	int nsk, level, skill, i;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("错字难当只能对战斗中的对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用错字难当！\n");		
		
    if( (int)me->query_skill("baihua-cuoquan", 1) < 30 )
		return notify_fail("你的百花错拳不够娴熟，不会使用错字难当。\n");
		
    if( (int)me->query("neili", 1) < 100 )
		return notify_fail("你现在内力太弱，不能使用错字难当。\n");
	
	if( me->query_temp("bhcq/cuo") )
		return notify_fail("对方已经不能抵挡你的错字难当！\n");		
			
	msg = CYN "$N突然双手狂摆，使出错字难当，似是而非,出其不意,拳勢手法已全然难以看清，至於是何门何派招数，更是分辨不出了。\n"NOR;

	if (random(me->query_skill("cuff")) > target->query_skill("parry")/2)
	{
		message_vision(msg, me, target);

		me->start_busy(1);
		//target->start_busy(random(3));
		
		nsk=sizeof(me->query_skills());
		level = 5;
		skill = nsk*3;
		me->add_temp("apply/attack", skill);
        me->set_temp("bhcq/cuo", 1);

        me->set_temp("active_force_buffer/baihua-cuoquan.cuo/name", "错字难当");                                  //buff名称
        me->set_temp("active_force_buffer/baihua-cuoquan.cuo/last_time", time() + skill/level );              //持续时间
        me->set_temp("active_force_buffer/baihua-cuoquan.cuo/effect1", "攻击命中+"+(skill)+"级");       //效果描述1   
		
		for(i=0; i<(nsk/10)+1; i++) {
			COMBAT_D->do_attack(me,target);
			msg = CYN "错字难当第"+to_chinese(i)+"击\n"NOR;
			message_vision(msg, me, target);
			msg="";
		}
		me->add("neili", -10*nsk);
		
        me->start_call_out(__FILE__, "remove_effect", skill/level, me, skill/level);
		
	} else 
	{
		me->start_busy(1);
		msg += CYN"可是$p把眼一闭，不被乱拳所干扰。\n"NOR;
	}
	message_vision(msg, me, target);

	return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->delete_temp("bhcq/cuo");
        me->delete_temp("active_force_buffer/baihua-cuoquan.cuo");
        message_vision(HIY"$N全身真气缓缓平复。\n" NOR, me);
}
