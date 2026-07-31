#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        int lvl;
        object weapon;
                string msg;
        int extra;
        int i;
        
        lvl = me->query_skill("xuanyin-jian", 1)/2;
        if( !target ) target = offensive_target(me);
        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("你只能对战斗中的对手使用斩字诀。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("你使用的武器不对。\n");
        if( (int)me->query_skill("xuanyin-jian", 1) < 200 )
                return notify_fail("你的玄阴剑法不够娴熟，无法施展出斩字诀。\n");
        if ((int)me->query_skill("jiuyin-zhengong", 1) < 150)
                return notify_fail("你的九阴真功火候不够，无法施展出斩字诀。\n");
        if ((int)me->query_skill("jiuyin-shenfa", 1) < 200)
                return notify_fail("你的九阴身法火候不够，无法施展出斩字诀。\n");
        if ( (int)me->query("max_neili") < 2000)
                return notify_fail("你的内力不够，无法施展出斩字诀。\n");
        if ( (int)me->query("neili") < 900)
                return notify_fail("你的真气不够，无法施展出斩字诀。\n");

        extra = me->query_skill("xuanyin-jian",1) / 40;
        if (extra> 9) extra=9;
        if (extra< 5) extra=5;
        
        message_vision(HIB"$N使出九阴「斩字诀」，剑光一瞬间攻向$n！\n"NOR,me, target);

        me->add("neili", -100 );

        me->add_temp("apply/attack",200);
        me->add_temp("apply/damage",2800);

        msg = HIR  "$N倒踏［幻阴步法］，以迅雷不及掩耳之势使出［玄阴剑法］中的精髓！\n手中的"+ weapon->name() + HIR"划出一道长虹，闪电般的击向$n！" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "剑光一闪，消失．．．．\n" NOR;
        message_vision(msg, me, target);
        for(i=0;i<extra;i++)
        {
        msg = HIY "$N"+HIY"身形突转，御剑回飞！\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
        

	if (	random(me->query("combat_exp")) > target->query("combat_exp")/3	)
{
        message_vision(HIB"结果$N一招得手，$n的手腕居然被斩了下来！\n"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        target->apply_condition("broken_arm",180); 

}
        me->add_temp("apply/attack", -200);
        me->add_temp("apply/damage", -2800);
        me->start_busy(2);
        return 1;
}