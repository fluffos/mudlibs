// meng.c 碧叶随风舞「万毒」

#include <ansi.h>

inherit F_SSERVER;
string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"sanpoison",
"scorpion_poison",
"qx_snake_poison",
});

int perform(object me, object target)
{
	string msg;
int level;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
            return notify_fail("「"+HIR"万毒"NOR+"」只能对战斗中的对手使用。\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("这里不能攻击别人! \n");

//	if( !userp(target) || wizardp(target) )
//		return notify_fail("施毒只能对玩家使用。\n");


	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用「万毒」！\n");		

	if( (int)me->query_skill("biye-wu", 1) < 40 )
		return notify_fail("你的碧叶随风舞不够娴熟，不会使用「万毒」。\n");

	if( (int)me->query_skill("biyun-xinfa", 1) < 30 )
		return notify_fail("你的碧云心法不够高，不能用来万毒伤敌。\n");

	if( (int)me->query("neili", 1) < 500 )
		return notify_fail("你现在内力太弱，不能使用「万毒」。\n");

        level=(int)me->query_skill("biye-wu", 1);
if (!level) level=10;
	if( (int)me->query("neili") < 500 )
		return notify_fail("你现在的内力不够！\n");

	msg = HIW "$N突然收掌，然后迅速发掌! 掌中尽然有毒砂，这掌风尽然是五颜六色的！！\n";

	me->start_busy(1);
	if( random( (int)me->query("combat_exp",1))+ level*200
          > target->query("combat_exp")/2  ) {
		msg += HIR"$n硬起头皮，以掌硬接！！结果身中巨毒！\n" NOR;
            me->add("neili",-300);
		me->start_busy(2);
            target->receive_damage("qi",20);
            target->receive_wound("qi",15 + random(10));
            target->apply_condition(du[random(sizeof(du))], 5);
            target->apply_condition(du[random(sizeof(du))], 5);
            target->apply_condition(du[random(sizeof(du))], 5);
            target->start_busy(1 + random(2));
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
	} else {
		msg += "$p急提内力奋力一震，将$N撒出的毒粉卸在了身旁!\n" NOR;
		me->start_busy(3);
            me->add("neili",-300);
		message_combatd(msg, me, target);
	}
	return 1;
}
