
#include <ansi.h>

inherit F_CLEAN_UP;

string query_name() { return "太玄"ZJBR"战气"; }
string *pfm_type() { return ({ "force", }); }

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        //int skill, amount;
        int skill;

        if (target != me)
                return notify_fail("你只能用太玄功来提升自己的战斗力。\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_temp("powerup"))
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");
        me->add("neili", -100);
        me->receive_damage("qi", 0);

        message_combatd(HIW "$N" HIW "默运太玄功，将内力积聚于周身经脉，顿觉全身浑然有力，坚不可摧。\n" NOR, me);
        //打通任督二脉的效果
        
        if (me->query("breakup"))
        {    
                me->add_temp("apply/attack", skill * 2 / 3);
				me->add_temp("apply/unarmed_damage", skill/4);
                me->set_temp("powerup", 1);
        }
        else
        {
                me->add_temp("apply/attack", skill / 3);
				me->add_temp("apply/unarmed_damage", skill/6);
                me->set_temp("powerup", 1);
        }
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);

        if (me->is_fighting()) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        if ((int)me->query_temp("powerup"))
        {
                if (me->query("breakup"))
                {
                        me->add_temp("apply/attack", - (amount * 2 / 3));
						me->add_temp("apply/unarmed_damage", -amount/4);
                }
                else
                {
                        me->add_temp("apply/attack", - (amount / 3));
						me->add_temp("apply/unarmed_damage", -amount/6);
                }
                me->delete_temp("powerup");
                tell_object(me, "你的太玄功运行完毕，将内力收回丹田。\n");
        }

}


