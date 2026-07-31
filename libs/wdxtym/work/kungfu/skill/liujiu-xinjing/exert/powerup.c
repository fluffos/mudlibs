#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);
string query_name() { return "六十门"ZJBR"真气"; }
int exert(object me, object target)
{
        int skill;

        if (target != me)
                return notify_fail("你只能用六十九心经来提升自己的战斗力。\n");

        if( me->query_temp("powerup") )
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");

        message_combatd(HIG "\n$N" HIG "轻念，六九无声，六九无邪，六九无攻。\n" NOR, me);

        // 打通BREAKUP后的效果增加20%
                if (me->query("breakup"))
        {    
                me->add_temp("apply/attack", skill * 2);
				me->add_temp("apply/damage", skill*2);
				me->add_temp("apply/parry", skill);
				me->add_temp("apply/dodge", skill);
                me->set_temp("powerup", 1);
        }
        else
        {
                me->add_temp("apply/attack", skill);
				me->add_temp("apply/damage", skill);
                me->set_temp("powerup", 1);
        }

        me->start_call_out((: call_other, __FILE__, "remove_effect",
                              me, skill :), skill);
      
        return 1;
}

void remove_effect(object me, int amount)
{
        if ((int)me->query_temp("powerup"))
        {
                if (me->query("breakup"))
                {
                        me->add_temp("apply/attack", - (amount * 2));
						me->add_temp("apply/damage", -(amount)*2);
						me->add_temp("apply/parry",  - amount);
						me->add_temp("apply/dodge",  - amount);
                }
                else
                {
                        me->add_temp("apply/attack", - amount);
						me->add_temp("apply/damage", -amount);
                }
                me->delete_temp("powerup");
                tell_object(me, HIY "你的六九心经[六十门真气]运行完毕，将内力收回丹田。\n" NOR);
        }


}