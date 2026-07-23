// sanqing.c 一剑化三清

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg, string1;
        int count;
 	if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        return notify_fail("「一剑化三清」只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("「一剑化三清」开始时必须拿着一把剑！\n");

        if( (int)me->query("neili") < 300 )
                return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("quanzhen-jian",1) < 135 )
                return notify_fail("你的全真剑法还不到家，无法使用「一剑化三清」！\n");

        if( (int)me->query_skill("xiantian-qigong",1) < 60 )
                return notify_fail("你的先天神功火候不够，无法使用「一剑化三清」！\n");
    if(me->query_skill_mapped("force") != "xiantian-qigong" )
        return notify_fail("你要把先天神功做为内功才能用。\n");

        msg = YEL "$N使出全真派绝技「一剑化三清」，身法陡然加快,手握剑柄晃成三条白龙！" NOR;
        message_vision(msg, me);

        me->add_temp("apply/attack", (int)me->query_skill("quanzhen-jian",1)/2);
        me->add_temp("apply/damage", (int)me->query_skill("quanzhen-jian",1)/3);

       msg = WHT  "赤血白龙！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = WHT  "化血白龙！" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = WHT "怒血白龙！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (me->query_skill("qixing-array",1)>80)
{
        msg = HIG "回形天罡！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -80);
}
        if (me->query_skill("qixing-array",1)>150)
{
        msg = HIG "七星移位！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -80);
}
        if (me->query_skill("qixing-array",1)>200)
{
        if (random(me->query("combat_exp")) > target->query("combat_exp")/2 )
        {
        message_vision(HIW"\n$N脚走七星,围着$n连走数个圈，$n只觉一阵眼花！\n"NOR,me,target);
//         msg = HIY "$N脚走七星,围着$n连走数个圈，$n只觉一阵眼花！" NOR;              
  if( !target->is_busy() )
{
         target->start_busy(2);
}
}

}

        me->add_temp("apply/attack", - (int)me->query_skill("quanzhen-jian",1)/2);
        me->add_temp("apply/damage", - (int)me->query_skill("quanzhen-jian",1)/3);
        me->add("neili", -250);
        me->start_busy(2);

        return 1;
}

