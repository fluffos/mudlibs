// qingyi-jian  惊天一式

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int damage;

	if( !target ) target = offensive_target(me);
        
        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) )
		return notify_fail("「惊天一式」只能对战斗中的对手使用。\n");

        if((int)me->query_skill("qingyi-jian", 1) < 200)
                return notify_fail("你的此项武功等级不够』！\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		    || (string)weapon->query("skill_type") != "sword")
			return notify_fail("你使用的武器不对。\n");

	if((int)me->query_dex() < 30)
			return notify_fail("你的身法不够, 目前还不能使用这项绝技! \n");

	if((int)me->query_skill("dodge") < 100)
			return notify_fail("你的轻功修为不够, 不能使用惊天一式！\n");
 
	if((int)me->query_skill("sword") < 135)
			return notify_fail("你的剑法修为不够， 目前不能使用惊天一式! \n");

    	if( (int)me->query("neili") < 500 )
			return notify_fail("你的真气不够！\n");
			
   	msg = HIG"$N身形一变，一声朗笑，使出情义剑绝技「惊天一式」，将全身劲气\n运于剑上，" + weapon->name()+ "化作一道长虹，直惯$n而去！\n\n"NOR;

        if (random(me->query_skill("sword", 1)) > target->query_skill("sword", 1) / 2 )
	{
			damage = me->query_skill("qingyi-jian",1) + (int)me->query_skill("sword", 1)*2;
			damage = damage - random( target->query_skill("dodge")/3 );
//                      target->receive_wound("jing", random( damage/2 ));
			target->receive_damage("qi", 20 + random(damage));
			target->receive_wound("qi", 20 + damage);

			me->start_busy(2);

			msg += HIR"结果$n被$N的「惊天一式」剑透前心，眼前一黑，「哇」地吐出了一大口血！！\n"NOR;
			me->add("neili", -200);
	} else 
	{
		msg += CYN"可是$p猛地向前一跃,跳出了$P的攻击范围。\n"NOR;
		me->add("neili", -200);
		me->start_busy(4);
	}
	message_vision(msg, me, target);

   return 1;

}
