/*  /kungfu/vast/perform_model_multiple.c
*
* 自创武功领悟技能模版
* from tianyu-qijian/fenfei.c 主要来自天羽奇剑 天羽纷飞
*
* deWolf(vax)@pkuxkx <deWolf_maTri_X@msn.com> 2005.11.09
*/

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
    object weapon;
	object victim_obj;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("多重功击只能对战斗中的对手使用。\n");

	if ("SKILL_BASE_NAME"=="sword" || "SKILL_BASE_NAME"=="blade" 
		|| "SKILL_BASE_NAME"=="whip" || "SKILL_BASE_NAME"=="staff" || "SKILL_BASE_NAME"=="spear")
	{
		if (!objectp(weapon = me->query_temp("weapon"))
			|| (string)weapon->query("skill_type") != "SKILL_BASE_NAME")
		{
			if (!objectp(weapon = me->query_temp("secondary_weapon"))
				|| (string)weapon->query("skill_type") != "SKILL_BASE_NAME")
			{
				return notify_fail("使用多重功击需要合适的兵器!\n");
			}
		}
	}
	else
	{
		if (objectp(weapon = me->query_temp("weapon")) 
			&& objectp(weapon = me->query_temp("secondary_weapon")))
		{
			return notify_fail("使用多重功击需要空出一只手来!\n");
		}
	}
	if( (time() - me->query_temp("multiple_end")) < 20 )
		return notify_fail("你刚刚使用过多重攻击！\n");
	if( (int)me->query_skill("SKILL_EN_NAME", 1) < PERFORM_NEED_LEVEL )
		return notify_fail("你的功夫不够娴熟，不会使用「PERFORM_CH_NAME」。\n");
	if( me->query("neili") <= 2*PERFORM_NEED_NEILI )
		return notify_fail("你的内力不够使用「PERFORM_CH_NAME」！\n");
	if( me->query("jingli") <= 2*PERFORM_NEED_JINGLI )
		return notify_fail("你的精力不够使用「PERFORM_CH_NAME」！\n");
	
	me->add("neili", -PERFORM_NEED_NEILI);
    me->add("jingli", -PERFORM_NEED_JINGLI);	
	msg = "PERFORM_ACTION！\n";
	
	me->start_busy(1);
	me->set_temp("multiple_end",time());
    if( random(me->query_dex()+me->query_int())+10 > (target->query_dex() + target->query_int()/2)/2 )
	{
		if (PERFORM_NEED_LEVEL>=50)
		{
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		}
		if (PERFORM_NEED_LEVEL>=150 && random(10)<8)
		{			
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		}
		if (PERFORM_NEED_LEVEL>=250 && random(10)<6)
		{			
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		}
    }
	else
	{
		me->start_busy(random( 5 ));
		msg += HIG "\n$N刚刚想要提升身法，就被$n找到了这一非常的时机，一招直奔要害而去！\n" NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
