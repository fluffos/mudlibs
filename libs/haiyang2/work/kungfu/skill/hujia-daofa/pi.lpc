// pi.c 开天辟地

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon,weapon2;
	int damage,i;
	string msg,str;
        int ap, dp;

        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }
	if (! target || ! me->is_fighting(target))
		return notify_fail("「开天辟地」只能对战斗中的对手使用。\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "blade")
		return notify_fail("运用「开天劈地」手中必须有刀！\n");

	if ((int)me->query_skill("hujia-daofa", 1) < 90)
		return notify_fail("你的胡家刀法不够娴熟，不会使用「开天辟地」。\n");
	                        
	if ((int)me->query_skill("force") < 250)
		return notify_fail("你的内功修为不够高。\n");
			
	if( (int)me->query("neili") < 800 )
		return notify_fail("你现在内力太弱，不能使用「开天劈地」。\n");
			
	msg = HIC "$N" HIC "一声长笑，双手紧握" + weapon->name() +
              HIC "刀柄，长吸一口气，全力向$n" HIC "迅猛劈去！\n\n"NOR;

	if (me->query_temp("hu/freeze") || random(3)==0)
	{
		msg += HIW + weapon->name() +
                HIW "寒气逼人，刀身撕裂空气，片片雪花飘落，刀未至气先及，$n" HIW "眉毛都蒙上了薄薄白霜！\n\n"NOR;
	}

        ap = me->query_skill("blade") + me->query_skill("force");
        if (living(target))
                 dp = target->query_skill("force") + target->query_skill("parry");
        else     dp = 0;

        if (ap / 2 + random(ap) > dp)
	{
		damage = ap + random(ap);
                damage += me->query("jiali");
                me->add("neili", -500);
		if (!objectp(weapon2 = target->query_temp("weapon")))
		{	
			target->receive_damage("qi",damage,me);
                        target->receive_wound("qi",damage/2 + random(damage/2),me);
			msg += HIR "只见$n" HIR "一声惨叫，胸口给"
                        	"劈开一个巨大的口子，鲜血汹涌喷出！\n"NOR;
			if (me->query_temp("hu/freeze")  || random(3)==0)
			{
				damage /= 3;
				target->receive_damage("qi",damage,me);
                                target->receive_wound("qi",damage/2 + random(damage/2),me);
				msg += HIR "\n$n" HIR "身形摇晃间，感觉到"
                        		+ weapon->name() + HIR + 
                                        "上一阵刺骨的寒气侵入体内，复又喷出一口鲜血！\n" NOR;
			}
		} else
		{
			msg += HIR "$n" HIR "见状不妙，连忙举起" + weapon2->name() + HIR + 
                                "抵挡，在$N这霸气无边的一招下，" + weapon2->name() + HIR +
                                "给震成碎片！\n" NOR;
			for (i = 0;i < 2 + random(5);i++)
			{
				msg += HIB "碎片四散飞溅，射中了$n的身体！\n" NOR;
				target->receive_damage("qi",damage/7,me);
                                        target->receive_wound("qi",damage/15 + random(damage/15),me);
			}
			msg += HIR + weapon->name() + HIR "余势未尽，又劈入了$n" + HIR + 
                                "的胸口，$n遭此重创，鲜血狂喷而出！\n" NOR;

			weapon2->set_name("碎裂的" + weapon2->query("name"));
                        weapon2->move(environment(target));
			weapon2->set("value", 0);
			weapon2->set("weapon_prop", 0);
			target->reset_action();
			target->receive_damage("qi",damage/2,me);
                                        target->receive_wound("qi",damage/4 + random(damage/4),me);

			if (me->query_temp("hu/freeze")  || random(3)==0)
			{
				damage /= 4;
				target->receive_damage("qi",damage,me);
				target->receive_wound("qi",random(damage),me);
				msg += HIR "\n$n" HIR "身形摇晃间，感觉到"
                        		+ weapon->name() + HIR + 
                                        "上一阵刺骨的寒气侵入体内，复又喷出一口鲜血！\n" NOR;
			}
		}
		str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		msg += "( $n"+str+" )\n";
		me->start_busy(3);
		target->start_busy(2);
	} else 
	{
		msg += HIY "$n" HIY "见势不妙，抽身急退，险险避过$N"
                       HIY "的这记开天辟地，尘土飞扬中，地上裂开了一道大口子！\n"NOR;
                me->add("neili", -100);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);

	return 1;
}
