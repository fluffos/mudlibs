// jianzhang.c  
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob;
        string msg, string1;
        int count;
int extra;
  if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「桃花飞舞」只能在战斗中使用。\n");

        if( me->query_skill("bibo-shengong",1) < 150)
            return notify_fail("你的碧波神功等级不够, 不能使用「桃花飞舞」！\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你使用的武器不对。\n");

        if( me->query_skill("yuxiao-jian",1) < 150)
            return notify_fail("你的玉箫剑法等级不够, 不能使用「桃花飞舞」！\n");

        if( me->query("neili") < 400 )
            return notify_fail("你的内力不够，无法运用「桃花飞舞」！\n");
	extra = me->query_skill("yuxiao-jian",1) / 20;
	extra += me->query_skill("bibo-shengong",1) /10;

	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);

	msg = HIY "$N使出桃花岛绝技「桃花飞舞」，身法陡然加快。落英缤纷！" NOR;
	
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  YEL  "人面桃花！ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  RED  "万花齐落！ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  BLU  "漫天花雨！ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIC  "落花无意！ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);	
	me->add_temp("apply/damage", -extra);

if ( me->query_skill("yuxiao-jian",1) >230)
{
        msg = HIG 
HIG"$N一声清啸，剑发琴音，深吸一口气，剑附内力，一式「天外清音」，"+weapon->name()
+"闪动不止，剑影如夜幕般扑向$n。\n"NOR;

	extra = me->query_skill("yuxiao-jian",1) / 5;
	extra += me->query_skill("bibo-shengong",1) /5;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", 2*extra);

       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);	
	me->add_temp("apply/damage", -2*extra);
	me->add("neili", -150);
	me->start_busy(1);

}
	me->add("neili", -220);
	me->start_busy(2);
	return 1;
}
