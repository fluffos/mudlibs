#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
string query_name() { return "吹雪"ZJBR"连诀"; }

int perform(object me, object target)
{
        object weapon;
        string msg;
        int i, attack_time;

        if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("寒天吹雪剑法「连」只能对战斗中的对手使用。\n");

        if((int)me->query_skill("chuixue-jian", 1) < 80)
                return notify_fail("你的寒天吹雪剑法等级不够，无法使用『天外飞仙』！\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        msg = HIY "$N使出寒天吹雪剑法「连」字诀，招式陡然变快。\n";
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);

        if( random(me->query("combat_exp")) >(int)target->query("combat_exp")/3 )
        {
                attack_time = random((int)me->query_skill("chuixue-jian", 1) / 25);
                if(attack_time < 1)
                        attack_time = 1;
                        attack_time = attack_time + 1;

                msg += CYN " 结果$p被$P攻了个措手不及！\n" NOR;
                for(i = 0; i < attack_time; i++){
         msg = HIY "$N在漫漫雪花中，一剑又刺了出来！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
                        }

                me->start_busy(4);
                me->add("neili", -400);
        }
        else
        {

                msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
                me->add("neili", -400);
                me->start_busy(4);
        }
        message_vision(msg, me, target);

        return 1;
}

