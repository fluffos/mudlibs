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
	int extra;

    if( !target ) target = offensive_target(me);
    if( !target||!target->is_character()||!me->is_fighting(target) )
    return notify_fail("你只能对战斗中的对手使用「断云斩」。\n");
extra = me->query_skill("duanyun-fu",1);

    if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "axe")
                        return notify_fail("你使用的武器不对。\n");

    if( (int)me->query_skill("guiyuan-tunafa", 1) < 50 )
	return notify_fail("你的本门内功还未练成，不能使用！\n");

    if( (int)me->query_skill("duanyun-fu",1) < 70)
    return notify_fail("你目前功力还使不出「断云斩」。\n");
    if( (int)me->query("neili") < 400 )
    return notify_fail("你的内力不够。\n");
    me->add("neili", -100);
msg = HIC"$N突然暴喝一声，将手中巨斧斜向上举起，然后在半空中划出一
道圆弧，随即径直斜下斩向$n！这一瞬间，$n只觉得呼吸都停止了！\n"NOR;
        me->add_temp("apply/attack", 80);    
        me->add_temp("apply/damage", 500);
if (random(2)==0) target->start_busy(2);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = HIC"$N跳起将手中巨斧斜向上举起，在半空中划出一
道圆弧，随即径直斜下斩向$n！\n"NOR;

	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = HIC"$N转身将手中巨斧斜向上举起，在半空中划出一
道圆弧，随即径直斜下斩向$n！\n"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -80);    
        me->add_temp("apply/damage", -500);
	me->start_busy(2);    
return 1;
}

