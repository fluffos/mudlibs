// tie@fengyun
// updated force->neili, force_factor->jiali (by xbd)

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
	extra = me->query_skill("houquan");
       if( (int)me->query_skill("houquan", 1) < 200 )
		return notify_fail("你的猴拳不够娴熟!\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「破釜沉舟」只能空手使用。\n");		
	if( (int)me->query("neili") < 800  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query_skill("yunlong-shengong", 1) < 100 )
		return notify_fail("你的云龙神功不够高。\n");


	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［破釜沉舟］只能对战斗中的对手使用。\n");
	me->add("jiali",extra/3);
	orforce = (int) me->query("force");
//	me->add("neili",extra/3*100);
	me->add_temp("apply/attack",80);
	me->add_temp("apply/damage",extra*2);

	weapon = me->query_temp("weapon");
	msg = HIY  "$N使出独步天下的［猴拳］，一招[破釜沉舟]打出了第一式！\n" NOR;
	message_vision(msg,me,target);
	msg = HIC  "第一拳------笑问七剑一指仙！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "第二拳------叶落枫舞二穿山！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "第三拳------袖里风云三点头！！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIC  "第四拳------回首太白四气刀！！！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIC "第五拳------化月孤心五看地！！！！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIC "第六拳------茫茫秋水六荒天！！！！！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIC "第七拳------笑问叶落看风云！！！！！！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIC "最后一拳------回首化月望秋水！！！！！！！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);me->start_busy(6);
        me->start_busy(3);
	me->set("jiali",0);
//	me->set("neili", orforce);
        me->add_temp("apply/attack",-80);
        me->add_temp("apply/damage",-extra*2);
	me->add("neili", -500);
	return 1;
}
