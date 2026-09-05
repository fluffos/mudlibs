// fuxue.c 拈花指 「拈花点穴」

#include <ansi.h>

inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
	string msg;
	int pflv, t;

	if( !target ) target = offensive_target(me);

	if( !target ||  !target->is_character() ||  !me->is_fighting(target) )
		return notify_fail("「拈花点穴」只能在战斗中使用。\n");

	if((int)me->query_str() < 25)
		return notify_fail("你臂力不够,不能使用这一绝技!\n");

	if((int)me->query_skill("canhe-zhi",1) < 60)
		return notify_fail("你参合指的功力不够不能使用拈花点穴!\n");

	if((int)me->query_skill("finger",1) < 60)
		return notify_fail("你的指法修为不够,目前还不能使用拈花点穴绝技!\n");

	if((int)me->query("neili") < 300)
		return notify_fail("你内力现在不够, 不能使用拈花点穴! \n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");

	msg = HIG "$N"HIG"使出参合指「拈花点穴」的绝技，伸出食指，朝着$n"HIG"胸口要穴「嗤嗤嗤」地凌虚点了三下。\n";
	
	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "姑苏慕容") 
		pflv=0;
	if (pflv>5) pflv=5;

	if( F_KUNGFU->hit_rate(me->query_skill("finger","canhe-zhi"), (int)target->query_skill("dodge"), 6, me, target) )
	{
		msg +=  HIG "$p"HIG"被$P"HIG"的指风点中，胸口一麻，便即摔倒在地，动弹不得! \n" NOR;
		t = (int)me->query_skill("canhe-zhi",1) / 50 + 2;
		if (pflv>=3) t += t * (pflv-2) / 5;
		F_KUNGFU->hit_busy( "dianxue", t, target );
		me->add("neili", -100);
	}
	else
	{
		msg += HIM "可是$p"HIM"看破了$P"HIM"的企图，身影一晃，当即避开。\n" NOR;
		if (pflv == 3) t = 2;
		else if (pflv >=4) t = 1 + random(2);
		else t = 3;		
		me->start_busy(t);
	}
	message_combatd(msg, me, target);

	return 1;
}
