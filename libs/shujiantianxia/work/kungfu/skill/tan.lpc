// 神通  shentong.c

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string *xue_name = ({ 
"大锥穴","百会穴","志室穴","肩井穴","劳宫穴","内关穴","外关穴","会宗穴","曲池穴",
"冲阳穴","臂儒穴","白海穴","灵台穴","风府穴","神风穴","玉书穴","青门穴","商阳穴",
"丝空竹穴","气海穴","冲门穴","大椎穴","百里穴","槐阳穴",
});

string perform_name(){ return HIG"弹字诀"NOR; }

int perform(object me, object target)
{
	int ap, dp;
	object weapon;
	string msg, dodge_skill, xue_names;

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target)
	 || environment(target)!=environment(me))
		return notify_fail("弹指神通只能对战斗中的对手使用。\n");

	if(  me->query_skill("tanzhi-shentong", 1) < 150 )
		return notify_fail("你的弹指神通还未到火候，使不出来弹指神通。\n");

	if(  me->query_skill("bihai-chaosheng", 1) < 150)
		return notify_fail("你的碧海潮生功还未到火候。\n");

	if(  me->query_skill("throwing", 1) < 150 )
		return notify_fail("你的基本暗器还未到火候，使不出来弹指神通。\n");

	if(  me->query("max_neili", 1) < 1800 )
		return notify_fail("你的内功修为不足以使出弹指神通绝技。\n");

	if(  me->query("neili", 1) < 1000 )
		return notify_fail("你的内力不足以使出弹指神通绝技。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	 && (int)me->query_skill("tanzhi-shentong", 1) < 150)
		return notify_fail("你现在无法使用弹指神通。\n");

	if(weapon && (weapon->query("skill_type") != "throwing"
	 || me->query_skill_mapped("throwing") != "tanzhi-shentong"))
		return notify_fail("你现在的武器无法使用弹指神通。\n");

	if( me->query_skill_mapped("parry") != "tanzhi-shentong"
	 || me->query_skill_prepared("finger") != "tanzhi-shentong")
	 	return notify_fail("你现在无法使用弹指神通。\n");

	if ( target->is_busy())
		return notify_fail( target->name(1)+"正自顾不暇，你可以放胆攻击了。\n");

	xue_names = xue_name[random(sizeof(xue_name))];

	if(!weapon)
		msg = HIG"\n$N跃起在半空，身形开始急速晃动，只听“嗤嗤”之声，一道劲风袭向$n的「"+xue_names+"」！\n"NOR;
	else
		msg = HIG"\n$N跃起在半空，身形开始急速晃动，只听“嗤嗤”之声，一"+ weapon->query("unit") + weapon->name()+HIG"袭向$n的「"+xue_names+"」！\n"NOR;

	ap = me->query("combat_exp", 1) /1000 * me->query_skill("tanzhi-shentong", 1);
	dp = target->query("combat_exp", 1)/ 1000 * target->query_skill("dodge", 1);

	if ( me->query_skill("tanzhi-shentong", 1) >= 400 )
		ap += random(ap/2);

	if ( random( ap + dp ) > dp || target->query_temp("tzst_tan") >= 2) {
		target->add_busy(4 + random(4));
		if ( !weapon)
			msg += HIR"$n只觉得「"+xue_names+"」已被$N的指风点中，身形不由的缓慢下来！\n"NOR;
		else
			msg += HIR"$n只觉得「"+xue_names+"」已被$N的"+weapon->name()+HIR"点中，身形不由的缓慢下来！\n"NOR;

		target->delete_temp("tzst_tan");
		me->add("neili", -200);
		me->add("jingli", -100);
	}
	else {
		if ( !userp(target))
			target->add_temp("tzst_tan", 1);
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
	}
	message_vision(msg, me, target);
	me->add("neili", -150);
	me->add("jingli", -80);
	me->start_busy(random(2));
	me->start_perform(2, "弹字诀");
	return 1;
}

int help(object me)
{
        write(HIG"\n弹指神通之「弹字诀」："NOR"\n\n");
        write(@HELP
        要求：  最大内力 1800 以上；
                当前内力 1000 以上；
                碧海潮生功 150 级以上；
                基本暗器 150 级以上；
                弹指神通 150 级以上；
                基本指法 120 级以上；
                激发指法为弹指神通。
                激发招架为弹指神通。

HELP
        );
        return 1;
}
