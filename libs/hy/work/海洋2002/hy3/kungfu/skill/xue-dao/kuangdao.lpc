//kuang.c -血刀「血祭」
// Modified by Venus Oct.1997
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int extra;
	object weapon;
    string msg;
	extra=me->query_skill("xue-dao",1);
    if( !target ) target = offensive_target(me);
    if( !target||!target->is_character()||!me->is_fighting(target) )
    return notify_fail("你只能对战斗中的对手使用「血祭」。\n");
    if( (int)me->query_skill("xue-dao",1) < 120)
    return notify_fail("你目前功力还使不出「血祭」。\n");
    	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
			return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("neili") < 500 )
    return notify_fail("你的内力不够。\n");
    me->add("neili", -100);
    msg = HIC"$N手中的刀，血光一闪！你只觉眼前一红"NOR;
        message_vision(msg, me, target);                
	msg = RED  "<<<>>>血光一现！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED  "<<<<<>>>>>刀山血海！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED  "<<<<<<>>>>>>血海深仇！！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED  "<<<<<<<>>>>>>>血流成河！！！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED  "<<<<<<<<>>>>>>>>以血祭刀！!!!!" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	me->start_busy(4);


    return 1;
}

