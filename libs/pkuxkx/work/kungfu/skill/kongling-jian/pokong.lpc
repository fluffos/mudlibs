// pokong.c 破空一击 by Vast

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object armor;
	string msg;
	object weapon;
	int pp,damage,mm,tt, kar, level;;
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『破空一击』只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你没有拿剑，如何施展『破空一击』？\n");

	if( me->is_busy() )
	return notify_fail("你自顾不暇，哪有功夫施展绝技！\n");
	
	if(me->query_temp("pfm_pokong"))
		return notify_fail("你刚使完绝招，身体尚未恢复最佳状态，暂时不能施展『破空一击』。\n");
	
	level = me->query_skill("kongling-jian",1);
		
	if(level < 150)
		return notify_fail("你『空灵剑法』不太熟练，不能使用『破空一击』。\n");
	if(me->query("neili") < 200)
		return notify_fail("你内力不够，不能使出『破空一击』一式。\n");

	msg = HIR "$N暗运内力，毕生功力积于剑尖，向$n猛的一剑刺去。\n"NOR;

        kar = me->query("kar") / 5;
        damage = level * 2;
        level = level / 15;

 				me->add("neili",-300);
       
//				target->kill_ob(me);

if(random(me->query("combat_exp")) > (int)target->query("combat_exp") * 2 / 7  )
  {
				msg += RED "只听得“噗”的一声响，$p的胸口竟被$P一剑贯穿……\n"NOR;
        me->start_busy(5);
      if (random(100) < 1 + kar + level)
      {//特效：流血
       		me->set_temp("pfm_pokong", 1);		
					msg += RED"$p鲜血喷涌而出，伤势似乎很严重。\n" NOR;
    			if (!target->query_condition("bleeding"))
    			{
    				target->delete("pokong");
    				target->apply_condition("bleeding", 5 + random(5));
    				target->add("pokong/bonus", 1);
    				target->set("pokong/killer", me);
    			}
    			else
    			{
    				target->apply_condition("bleeding", 5 + target->query_condition("bleeding"));
    				target->add("pokong/bonus", 1);
    				target->set("pokong/killer", me);
    			}
			    	call_out("remove_effect", 8, me);
			}
		else
			{
					msg += HIC"$p喷出一口鲜血，看来受伤不轻。\n" NOR;
          target->receive_damage("qi", damage, me);
					target->receive_wound("qi", damage, me);
			}
	}
	else
		{
				msg += HIY"可是$p看破了$P的企图，并没有上当。\n" NOR;
				me->start_busy(3);
		}
 				message_vision(msg, me, target);
 				    	
	return 1;
}

void remove_effect(object me)
{
		me->delete_temp("pfm_pokong");

		tell_object(me, HIG"你感到气力有所恢复，又能施展绝招了。\n"NOR);
}