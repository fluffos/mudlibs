// he.c 玉女剑-双剑合璧

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("双剑合璧只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if( (int)me->query_skill("yunv-xinfa", 1) < 80 )
                return notify_fail("你的玉女心法不够娴熟，不能使用双剑合璧。\n");

        if( (int)me->query_skill("yunv-jian", 1) < 80 )
                return notify_fail("你的玉女剑法不够娴熟，不能使用双剑合璧。\n");

        if( (int)me->query_skill("quanzhen-jian", 1) < 50 )
                return notify_fail("你的全真剑法不够娴熟，不能使用双剑合璧。\n");

        if( (int)me->query("neili", 1) < 400 )
                return notify_fail("你现在内力太弱，不能使用双剑合璧。\n");

        msg = YEL "$N左手以全真剑法剑意，右手化玉女剑法剑招，双剑合璧同时刺出。"NOR;

    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2
 ) {
    msg = HIC"结果$p只觉两眼一黑，不能破解这么怪的武功，招式大乱。\n" NOR;
        message_vision(msg, me, target);
 target->start_busy( (int)me->query_skill("yunv-jian") / 50 + 1);
     } 
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	
	me->start_busy(2);
        return 1;
}
