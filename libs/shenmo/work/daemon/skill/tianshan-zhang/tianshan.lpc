// jianzhang.c  天山奇峰
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob;
        string msg, string1;
        int count,extra;
  if( !target ) target = offensive_target(me);

	if( !me->is_fighting() )
		return notify_fail("「天山奇峰」只能在战斗中使用。\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
            return notify_fail("你使用的武器不对。\n");

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「天山奇峰」只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("huagong-dafa",1) < 60 )
                return notify_fail("你的化功大法功力不够！\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真气不够！\n");

	if( (int)me->query_skill("staff",1) < 200 ||
	    me->query_skill_mapped("staff") != "tianshan-zhang")
		return notify_fail("你的天山杖法还不到家，无法使用天山奇峰！\n");

	msg = HIY "$N使出天山派绝技「天山奇峰」，身法陡然加快。万岳朝宗！" NOR;
	
        extra = me->query_skill("tianshan-zhang",1) / 10;
        extra += me->query_skill("huagong-dafa",1) /10;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra*2);
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  HIB  "        ^^玉进天池！^^       " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  RED  "      ^^^^山风凛冽！^^^^  " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  HIM  "    ^^^^^^开门见山！^^^^^ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIC  "^^^^^^^^^^^天山雪崩！^^^^^^^^^^^ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra);    
        me->add_temp("apply/damage", -extra*2);
        if (me->query_skill("tianshan-zhang",1) > 250)
        {
        message_vision(HIY"$N的杖头，冒出了绿光$n被绿光扫中，全身不由一震!\n"NOR,me,target);
        target->apply_condition("xx_poison",60);
        target->apply_condition("corpse_poison",60);
	 msg =  HIR  "「腐尸毒」" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        target->apply_condition("x2_sandu",60);
	 msg =  HIR  "「毒砂掌」" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        target->apply_condition("sanpoison",60);
	 msg =  HIR  "「无形毒」" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -150);
        if (random(me->query("combat_exp")) >target->query("combat_exp")/2)
        {
       	 msg =  HIR  "「三笑逍遥散」" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"$N突然怪异的一笑，$n尽然跟着笑了笑!\n"NOR,me,target);
        target->apply_condition("sanxiao_poison",6);
        me->add("neili", -50);
        }
}
	me->add("neili", -250);
	me->start_busy(2);
	return 1;
}
