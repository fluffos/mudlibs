//kuang.c -「狂风二十一式」
// Modified by Venus Oct.1997
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage, time;
    object weapon;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target||!target->is_character()||!me->is_fighting(target) )
    return notify_fail("你只能对战斗中的对手使用「狂风二十一式」。\n");
    if (!(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "blade")
    return notify_fail("你必须拿刀才能施展「狂风二十一式」。\n");
    if( (int)me->query_skill("kuangfeng-dao",1) < 180)
    return notify_fail("你目前功力还使不出「狂风二十一式」。\n");
    if( (int)me->query("neili") < 200 )
    return notify_fail("你的内力不够。\n");
    me->add("neili", - 200);
    msg = HIC"$N淡然一笑，本就快捷绝伦的刀法骤然变得更加凌厉！就在这一瞬之间，\n"+
    "$N已劈出二十一刀！刀夹杂着风，风里含着刀影！$n只觉得心跳都停止了！\n"NOR;
    me->start_busy(2);

    time = (int)me->query_skill("kuangfeng-dao") / 20;
    if (time > 10) time = 10;
    if( random(me->query("combat_exp")) >
      (int)target->query("combat_exp")/3 )
      {
      	if(!target->is_busy() && random(2) == 0)
    target->start_busy( time );
    damage = (int)me->query_skill("blade");
    damage = damage + random(damage);

	if (wizardp(me)) tell_object(me, "damage = " + damage +"\n");
    target->receive_damage("qi", damage, me);
    target->receive_wound("qi", damage/2, me);
    msg += RED"只见$n已被$N切得体无完肤，血如箭般由全身喷射而出！\n"NOR;
    } else
    {
    	msg += HIC "可是$p急忙抽身躲开，$P这招没有得逞。\n" NOR;
    	me->start_busy( time / 2 );
    }
    message_combatd(msg, me, target);

    return 1;
}

