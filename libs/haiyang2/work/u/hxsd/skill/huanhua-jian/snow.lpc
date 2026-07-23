// tie@fengyun

#include <ansi.h>

#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)

{

	string msg;

	int i, lmt, damage ;
	object weapon;

	

	if( (int)me->query_skill("sword") < 90 ||

	    me->query_skill_mapped("sword") != "huanhua-jian")

		return notify_fail(HIW "你的「浣花剑法」还不到家，无法使用「天下有雪」！\n"NOR);

	if( (int)me->query_skill("huanhua-jian", 1) < 150 )
		return notify_fail(HIW "你的「浣花剑法」还不到家，无法使用「天下有雪」！\n"NOR);


	if ((int)me->query("neili",1) < 200)

		return notify_fail("你的内力不够，无法使用「天下有雪」！\n");		

	if( !target ) target = offensive_target(me);

	if( !target

	||	!target->is_character()

	||	!me->is_fighting(target) )

		return notify_fail(HIW "「天下有雪」只能对战斗中的对手使用。\n"NOR);

	weapon = me->query_temp("weapon");

	msg = HIY  "$N长啸一声，剑招顿挟风云之式，剑气猛的暴涨三尺，手中的\n"+ weapon->name()+  "如狂风暴雨般地向$n卷来！\n\n" NOR;
	message_vision(msg,me,target);

        if( !target->is_killing(me) ) target->kill_ob(me);
		damage = me->query_skill("huanhua-jian",1) + (int)me->query_skill("guiyuan-dafa", 1);

		damage = damage - random( target->query_skill("dodge")/3 );



	lmt = random(5)+3;

	for(i=1;i<=lmt;i++)

	{

	msg =  HIW "$N大喝一声：接第"+chinese_number(i)+"剑！\n" NOR;

	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	}

//      target->receive_wound("jing", random( damage/20 ));
	target->receive_damage("qi", 20 + random(damage));

	target->receive_wound("qi", 20 + damage);

        me->add("neili", -30);

		

	me->start_busy(4);

	return 1;

}

