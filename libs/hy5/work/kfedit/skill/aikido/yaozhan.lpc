#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［腰斩］只能对战斗中的对手使用。\n");
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("腰斩必须空手。\n");
if( (int)me->query("max_neili") < 200 )
      return notify_fail("你的内力不够！\n");
	if( (int)me->query("neili") < 200  ) 
		return notify_fail("你的内力不够。\n");
    if ((int)me->query_skill("shayi-xinfa", 1) < 30)
   return notify_fail("你的杀意心法火候不够。\n");

	extra = me->query_skill("aikido",1)/10;
	if(extra <= 3 ) return notify_fail("你的［合气道］不够熟练！\n");
	msg = HIR "$N突然绕到$n身后，右膝猛然上顶，双手同时抓向$n，企图将$n的后腰磕断！" NOR;
        weapon = me->query_temp("weapon");
	me->add_temp("apply/damage",extra*4);
	me->add_temp("apply/attack",extra*2);
        message_combatd(msg, me, target);
	 msg =  RED  "「 右膝猛然上顶! 」！ " NOR;	
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  RED  "「 双手同时擒拿! 」！ " NOR;	
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  RED  "「 后腰磕断擒拿! 」！ " NOR;	
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/damage",-extra*4);
        me->add_temp("apply/attack",-extra*2);
        me->add("neili",-100);
	me->start_busy(2);
	return 1;
}
