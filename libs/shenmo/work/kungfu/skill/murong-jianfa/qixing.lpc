// qixing.c /kungfu/skill/murong-jianfa/qixing.c 剑转七星
// update by beyond 97.9.2

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
	string msg;
        object weapon;
	int extra;
	weapon = me->query_temp("weapon");
        extra = (int)me->query_skill("murong-jianfa",1);
	if( !target ) target = offensive_target(me);

	if( !target
	    ||  !target->is_character()
	    ||  !me->is_fighting(target) )
		return notify_fail("剑转七星只能对战斗中的对手使用。\n");

	if( (int)me->query_skill("murong-jianfa", 1) < 100 )
		return notify_fail("你的剑转七星还未练成，不能使用！\n");

        if (me->query_skill("shenyuan-gong", 1)<70)
                return notify_fail("你的本门内功火候未到，！\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("你现在内力不足，不能使用剑转七星！\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");


	if( (int)me->query_skill("sword", 1) < 100 )
		return notify_fail("你的基本剑法不够娴熟，不能使用剑转七星。\n");
//if( (int)me->query_skill("murong-jianfa", 1) < 300 )
//{
	msg = HIY "\n$N忽然剑锋一转，将内力传至剑锋，只见七朵剑花绽开，分别袭向$n的" +
		  "七大要穴！\n"NOR;

	if ( random(me->query("dex")) > (int)target->query("dex")*2/3 )
	{
		msg += HIR"\n$p只觉得全身受到内力震荡，钻心般巨痛，一口鲜血喷出，身上多\n" +
			"出七个血肉模糊的血窟窿。\n" NOR;
		message_vision(msg, me, target);
		me->add("neili", -100);
	}

	else
	{
		msg += HIG"\n$p情急之中双脚跋地而起，空中身行一闪，狼狈地躲过这一照，脸色变的苍白。\n" NOR;
		message_vision(msg, me, target);
		me->start_busy(2);
	}
	if (random(me->query_skill("parry")) > target->query_skill("parry")/2 )
	{
		me->start_busy(2);

		damage = (int)me->query_skill("shenyuan-gong", 1);

		damage = damage*5/2 + random(damage);
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		target->add("neili", -random(damage));
		me->add("neili", -100);
		if( damage < 300 ) msg += HIC"\n结果$n脸色变得惨白，踉踉跄跄退了好几步！\n"NOR;
		else if( damage < 400 ) msg += HIM"\n结果重重地击中，$n「哇」地一声吐出一口鲜血！\n"NOR;
		else if( damage < 500 ) msg += RED"\n结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
		else msg += HIR"\n结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n"NOR;

	}
	else
	{
		me->start_busy(2);
		msg += HIG"\n$p情急之中双脚跋地而起，空中身行一闪，狼狈地躲过这一照，脸色变的苍白。\n" NOR;
	}
//}
        if(!(int)me->query_temp("lianhuan"))
{
if( (int)me->query_skill("murong-jianfa", 1) > 249 )
{
	me->add_temp("apply/attack", extra/10);	
	me->add_temp("apply/damage", extra/2);
message_vision(HIG"\n$N忽然剑锋再转，只见七朵剑花再次绽开，分别袭向$n的七大要穴！\n"NOR,me,target);
//message_vision(HIW"星转一斗："WHT"〖"HIY"天枢星"WHT"〗\n\n"HIG"只见$N手中之剑势一抖，笔直刺入$n的身体，$n只觉身上一痛，随即"HIC"『天门穴』"HIG"传来无法形容的剧烈疼痛！\n"NOR,me,target);        
msg = HIW"星转一斗："WHT"〖"HIY"天枢星"WHT"〗\n\n"HIG"只见$N手中之剑势一抖，笔直刺入$n的身体，$n只觉身上一痛，随即"HIC"『天门穴』"HIG"传来无法形容的剧烈疼痛！\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = HIM"星斗又见："WHT"〖"HIY"天眩星"WHT"〗\n\n"HIG"只见$N剑势再抖，笔直刺入$n的肩头，$n只觉身上一痛，随即"HIC"『肩井穴』"HIG"传来一阵剧烈刺痛！\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = MAG"转星见斗："WHT"〖"HIY"天机星"WHT"〗\n\n"HIG"只见$N剑随势上，三剑又出，竟然绝不可能的刺入$n的足底！$n只觉轻微一痛，随即"HIC"『涌泉穴』"HIG"传来一阵剧烈疼痛！\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = YEL"星转四斗："WHT"〖"HIY"天权星"WHT"〗\n\n"HIG"只见$N剑抖四星，笔直刺入$n的身体，$n只觉身上被一阵乱刺，随即感到"HIC"『任脉四穴』"HIG"传来一阵剧烈疼痛！\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = HIB"五星在中："WHT"〖"HIY"玉衡星"WHT"〗\n\n"HIG"只见$N剑走偏锋，笔直刺入$n的腰侧，$n只觉腰上一痒，随即"HIC"『齐门穴』"HIG"竟然喷出血花！\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = RED"星聚遇斗："WHT"〖"HIY"开阳星"WHT"〗\n\n"HIG"只见$N抖剑而上，由上而下刺入$n的头顶，$n突然觉得全身真力不续，随即重穴"HIC"『百汇穴』"HIG"竟然疼痛无比！" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = HIR"斗转星移："WHT"〖"HIY"谣光星"WHT"〗\n\n"HIG"只见$N剑花连抖，如众星捧剑，任$n奋力闪躲，亦将$n的第一重穴"HIC"『太阳穴』"HIG"刺了两道血迹！\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
message_vision(WHT"\n$N祭完七星，收剑挺立场中，一代王者风范凛然而出！仿佛毫不在意$n的存在。\n"NOR,me,target);        
	me->add_temp("apply/attack", -extra/10);	
	me->add_temp("apply/damage", -extra/2);

        me->add("neili", -300);
        me->start_busy(3);
        return 1;
}
}
message_vision(msg, me, target);

	return 1;
}
