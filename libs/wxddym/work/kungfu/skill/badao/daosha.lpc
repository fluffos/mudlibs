#include <ansi.h>

inherit F_CLEAN_UP;
string query_name() { return "刀煞"; }
void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int skill;
        object weapon;

        if( me->query("neili")<600 )
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_skill("badao", 1) < 300)
                return notify_fail("你的霸刀修为不够。\n");

        if (me->query_skill_mapped("blade") != "badao")
                return notify_fail("你还没有激发霸刀呢。\n");

        if( me->query_temp("badao-dasha") )
                return notify_fail("你已经施展起刀煞了。\n");

        if( !objectp(weapon=me->query_temp("weapon")) ||
            weapon->query("skill_type") != "blade" )
                return notify_fail("你使用的武器不对！\n");

        skill = me->query_skill("badao", 1);
        me->add("neili", -500);

        message_combatd(HIY "$N挥动起手中" + weapon->name() + HIY "，一股强劲的气流自全身涌向" + weapon->name() +
                        HIY "，顿时，刀气四溢，杀气腾腾。\n" NOR, me);

        me->add_temp("apply/damage", skill/2);
        me->set_temp("badao-dasha", 1);

        me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill :), skill);

        if (me->is_fighting()) me->start_busy(2);

        return 1;
}

void remove_effect(object me, int amount)
{
        if( me->query_temp("badao-dasha") )
        {
                me->add_temp("apply/damage", -(amount/2));
                me->delete_temp("badao-dasha");
                tell_object(me, "你的霸刀运行完毕，将内力收回丹田。\n");
        }
}