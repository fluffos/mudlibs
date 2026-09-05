// cixue.c 辟邪剑刺穴
//added by bing

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object armor;
	string msg;
	int pp,damage,mm,tt, kar, level;;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("刺穴只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword"
        || weapon->query("id") != "xiuhua zhen")
                return notify_fail("你没有拿绣花针，怎么刺别人穴道？\n");
	if( !objectp(armor = me->query_temp("armor/boots")) || armor->query("id") != "flower shoes")
                return notify_fail("你没穿绣花小鞋，使不出刺穴一式。\n");
	if( !objectp(armor = me->query_temp("armor/cloth")) || armor->query("id") != "pink cloth")
                return notify_fail("你没穿粉红绸衫，使不出刺穴一式。\n");
	if( !objectp(armor = me->query_temp("armor/finger")) || armor->query("id") != "golden ring")
                return notify_fail("你没戴金戒指，使不出刺穴一式。\n");
	if( !objectp(armor = me->query_temp("armor/neck")) || armor->query("id") != "golden necklace")
                return notify_fail("你没戴金项链，使不出刺穴一式。\n");

	if(level = (me->query_skill("pixie-jian",1)) < 200)
		return notify_fail("你辟邪剑法不太熟练，不能刺人穴道。\n");
	if(me->query("neili") < 200)
		return notify_fail("你内力不够，不能使出「刺穴」一式。\n");

	msg = HIR "$n只觉眼前有一团粉红色的物事一闪，似乎$N的身子动了一动。\n";

        kar = me->query("kar") / 10;
        damage = level * 2;
        level = level / 20;

        me->start_busy(3);
	target->kill_ob(me);

        if(random(me->query("combat_exp")) > (int)target->query("combat_exp") * 7 / 2  )
        {
		msg += "听得铛的一声响，$p的眉心、左右太阳穴、鼻下人中四处大穴上，都是有一个细小红点，微微
有血渗出，显是$P用手中的绣花针所刺。\n";
        	if (random(100) < 1 + kar + level)
        	{//特效：流血
			msg += "$p手腕歪在一旁，显是已经断了。\n" NOR;
			if (!target->query_condition("cixue_bleeding"))
			{
				target->delete("cixue");
				target->apply_condition("cixue_bleeding", 5 + random(5));
				target->add("cixue/bonus", 1);
				target->set("cixue/killer", me);
			}
			else
			{
				target->apply_condition("cixue_bleeding", 5 + target->query_condition("cixue_bleeding"));
				target->add("cixue/bonus", 1);
				target->set("cixue/killer", me);
			}
		}
		else
		msg += "$p喷出一口鲜血，看来受伤不轻。\n" NOR;
                target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage, me);
	}
	else
	msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
	message_vision(msg, me, target);
    	me->add("neili",-300);
	return 1;
}
