//zuida 八仙醉打
#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        string msg;
        int skill, extra;
        object weapon;

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「八仙醉打」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || ((string)weapon->query("skill_type") != "club" && (string)weapon->query("skill_type") != "staff"))
                return notify_fail("你使用的武器不对。\n");

        if( !(int)me->query_condition("drunk"))
                return notify_fail("你没有喝醉，如何使用「八仙醉打」呀？\n");

        if(me->query_temp("ranmu"))
                return notify_fail("你现在正在使用「焚心」绝技。\n");

        if( me->query_temp("zuida"))
                return notify_fail("你正在施展「八仙醉打」。\n");

        if( (int)me->query_str() < 25)
                return notify_fail("你的臂力不够，无法施展「八仙醉打」。\n");

        if( (int)me->query_skill("zui-gun", 1)< 100 )
                return notify_fail("你的棍法不够娴熟，不会使用「八仙醉打」。\n");

        if( (int)me->query_skill("hunyuan-yiqi", 1) < 80 )
                return notify_fail("你的混元一气功等级不够，不能使用「八仙醉打」。\n");

        if( (int)me->query("max_neili") < 500 || (int)me->query("neili") < 500 )
                return notify_fail("你的内力不足，无法使用「八仙醉打」。\n");

        skill = (int)me->query_skill("zui-gun", 1);
        extra = skill/10 + (int)me->query_condition("drunk")/(me->query("con")*30);
        me->add("neili", - 300);
        me->set_temp("zuida", 1);
        msg = CYN "$N摇头晃脑显出喝醉的样子，身子轻飘飘地，使出「八仙醉打」。\n" NOR;
        message_vision(msg, me, target);
        me->add_temp("apply/strength", extra);
        me->add_temp("apply/dexerity", extra);
        me->set_temp("active_buffer/family","少林派");
        me->set_temp("active_buffer/zui-gun.zuida/name", "八仙醉打");                    //buff名称
        me->set_temp("active_buffer/zui-gun.zuida/last_time", time() + skill/10 );       //持续时间
        me->set_temp("active_buffer/zui-gun.zuida/effect1", "后天身法+"+extra+"点");     //效果描述1
        me->set_temp("active_buffer/zui-gun.zuida/effect2", "后天膂力+"+extra+"点");     //效果描述2
        call_out("remove_effect", skill/10 , me, extra);

        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me)  return;
        tell_object(me,HIY"一阵凉风吹过，你感觉酒意已去。\n"NOR);
        me->add_temp("apply/strength", - amount);
        me->add_temp("apply/dexerity", - amount);
        me->delete_temp("zuida");
        me->delete_temp("active_buffer/zui-gun.zuida");
        if ( sizeof(me->query_temp("active_buffer"))==1 )
        	me->delete_temp("active_buffer");
}

