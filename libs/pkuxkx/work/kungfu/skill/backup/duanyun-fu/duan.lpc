//duan.c -夺命三斧之「断云斩」
// Modified by Venus Oct.1997
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
object weapon;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target||!target->is_character()||!me->is_fighting(target) )
    return notify_fail("你只能对战斗中的对手使用「断云斩」。\n");
    if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "axe")
                        return notify_fail("你使用的武器不对。\n");

    if( (int)me->query_skill("duanyun-fu",1) < 70)
    return notify_fail("你目前功力还使不出「断云斩」。\n");
    if( (int)me->query("neili") < 200 )
    return notify_fail("你的内力不够。\n");
    me->add("neili", -60);
msg = HIC"$N突然暴喝一声，将手中巨斧斜向上举起，然后在半空中划出一
道圆弧，随即径直斜下斩向$n！这一瞬间，$n只觉得呼吸都停止了！\n"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->start_busy(2);    
return 1;
}

