//Edit by cloth 2000-09-19
//diabio by kuangwu
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
		int flag;
        object weapon;
		extra = me->query_skill("tianyu-qijian",1);
        if ( extra < 1000) return notify_fail("你的天羽奇剑还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
		||      !me->is_fighting(target) )
                return notify_fail("［天羽狂舞］只能对战斗中的对手使用。\n");

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你使用的武器不对。\n");

    if (me->query("gender")!="女性" || me->query("family/family_name")!="灵鹫宫")
        return notify_fail("天羽奇剑非灵鹫宫弟子不能使用！\n");

	if((int)me->query_dex() < 40)
		return notify_fail("你身法不够,不能使用这一绝技!\n");

	if((int)me->query("neili") < 800)
		return notify_fail("你内力现在不够, 不能使用天羽狂舞! \n");
    me->add("neili",-250);
	weapon = me->query_temp("weapon");
	message_vision(HIM"$N使出天羽奇剑中的绝招［天羽狂舞］，一招连环六剑，手中的"+weapon->name()+"闪电般向$n攻出第一剑！\n\n" NOR,me,target);        
	if (random((int)me->query_skill("dodge", 1))>random((int)target->query_skill("dodge")/2 ) )
	{
		flag = 0;
		if( target->is_busy() )
		{
			flag = 1;
			me->add_temp("fight/dodge", extra*2);
			me->add_temp("fight/parry", extra*2);
		}
        COMBAT_D->do_attack(me,target, weapon); 
        message_vision(HIY"第二剑！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon); 
        message_vision(HIY"第三剑！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon); 
        message_vision(HIY"第四剑！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon); 
        message_vision(HIY"第五剑！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon); 
        message_vision(HIY"最后一剑！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(WHT"$N连出六剑，$n眼前犹如阵阵惊虹闪过，全身已被刺了无数血洞！\n" NOR,me,target);
        me->start_busy(4);

		if( flag == 1 )
		{
			me->add_temp("fight/dodge", -extra*2);
			me->add_temp("fight/parry", -extra*2);
		}
	}
	else
	{ 
		message_vision(HIC"可是$n面色平静拆开$N的招式,趁机发动猛烈的进攻！\n" NOR,me,target);
		me->start_busy(2);
	}        
	return 1;
}
