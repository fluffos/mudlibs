// powerup.c 太虚剑气加力

#include <ansi.h>

inherit F_CLEAN_UP;
string query_name() { return "太虚"ZJBR"剑心"; }
void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if (target != me)
                return notify_fail("你只能用太虚剑气来提升自己的战斗力。\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_temp("powerup"))
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");
        me->add("neili", -100);
        me->receive_damage("qi", 0);

        message_combatd(HIC "$N" HIC "心境融湖为止水，心境结冰为无尘，"
						"心冰透彻为明镜，心气无形为太虚\n" NOR, me);

        me->add_temp("apply/attack", skill );
        me->add_temp("apply/parry", skill );
        me->add_temp("apply/dodge", skill );
		me->add_temp("apply/sword", skill );
		me->add_temp("apply/unarmed_damage", skill );
		me->add_temp("apply/damage", skill );
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);

        if (me->is_fighting()) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        if ((int)me->query_temp("powerup"))
        {
                me->add_temp("apply/attack", - (amount ));
                me->add_temp("apply/parry", - (amount ));
                me->add_temp("apply/dodge", - (amount ));
				me->add_temp("apply/sword", -(amount ));
				me->add_temp("apply/unarmed_damage", -(amount ) );
				me->add_temp("apply/damage", -(amount ));
                me->delete_temp("powerup");
                tell_object(me, "你的太虚剑气运行完毕，将内力收回丹田。\n");
        }
}

