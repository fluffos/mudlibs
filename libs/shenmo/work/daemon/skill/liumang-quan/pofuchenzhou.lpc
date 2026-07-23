// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int orforce;
	object weapon;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
        extra = me->query_skill("liumang-quan",1);
	if ( extra < 190) return notify_fail("你的流氓神拳还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［破釜沉舟］只能对战斗中的对手使用。\n");
    if( (int)me->query("neili", 1) < 600 )
		return notify_fail("你现在内力不足，不能使用！\n");	
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("这个武功只能空手使用。\n");		
		
	orforce = (int) me->query("neili");
	me->add("neili",extra);
extra=extra/3;
if (extra> 200) extra=200;
	me->add_temp("apply/attack",extra);
if (random(3)==0) target->start_busy(3);
	weapon = me->query_temp("weapon");
        msg = HIY  "$N使出独步天下的流氓神拳，一招[破釜沉舟]略带一丝惋惜之色向$n攻出！\n" NOR;
	message_vision(msg,me,target);
        msg = HIC "第一拳------笑问七剑一指仙！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "第二拳------叶落凤舞二穿山！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "第三拳------袖里风云三点头！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "第四拳------回首太白四气刀！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "第五拳------化月孤心五看地！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "第六拳------茫茫秋水六荒天！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "第七拳------笑问叶落看风云！！！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "最后一拳----回首化月望秋水！！！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->start_busy(3);

        me->add_temp("apply/attack",-extra);

	return 1;
}
