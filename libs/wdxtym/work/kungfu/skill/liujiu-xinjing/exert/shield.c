
#include <ansi.h>

inherit F_CLEAN_UP;
string query_name() { return "金身"ZJBR"护体"; }
void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if (target != me)
                return notify_fail("你只能用六九心经来提升自己的战斗力。\n");

        if( me->query_temp("shield") )
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");

        message_combatd(HIR "$N" HIR "默念六九心经，周身气势不可揣测。\n" NOR, me);

        // 打通BREAKUP后的效果增加翻倍
        if (me->query("breakup"))
        {    
                me->add_temp("apply/armor", skill * 2);
			//	me->add_temp("apply/parry", skill);
                me->set_temp("shield", 1);
        }
        else
        {
                me->add_temp("apply/armor", skill);
			//	me->add_temp("apply/parry", skill/2);
                me->set_temp("shield", 1);
        }

        me->start_call_out((: call_other, __FILE__, "remove_effect",
                              me, skill :), skill );

        if (me->is_fighting()) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        if ((int)me->query_temp("powerup"))
        {
                if (me->query("breakup"))
                {
                        me->add_temp("apply/armor", - (amount * 2 ));
					//	me->add_temp("apply/parry", -(amount));
                }
                else
                {
                        me->add_temp("apply/armor", - amount);
					//	me->add_temp("apply/parry", -amount/2);
                }

                me->delete_temp("shield");
                tell_object(me, HIW "你的六九心经「金身护体」运行完毕，将内力收回丹田。\n" NOR);
        }


}