//醉生梦死
#include <ansi.h>
inherit F_SSERVER;
// by male/mudy

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
        string msg;
    int skill,limit;
    int damage;
    int coefficient;
if(me->query("zuiquanpf")!=2) return notify_fail("你不会这一招!\n");
            if( objectp(me->query_temp("weapon")) )
                 return notify_fail("使用醉生梦死,必须空手!\n");
        limit = (me->query("con") + (int)me->query("max_neili") / 50) * 2;

        if( !target ) target = offensive_target(me);                        

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("醉生梦死只能对战斗中的对手使用。\n");
       if( (int)me->query("max_neili")< 200 || (int)me->query("neili") < 200 )
                return notify_fail("你的内力不足，无法使用醉生梦死。\n");

        if( !(int)me->query_condition("drunk"))
       {
            msg = HIC"$N故作醉态使出「醉生梦死」,一侧身,以肘部袭人!\n"NOR;
              coefficient=1;
             }
     else
        {
               msg = HIC"$N拳借酒势，使出「醉生梦死」,一侧身,以肘部袭人!\n"NOR;
              coefficient=2;
          }

        me->add("neili", - 200);
         skill=(int)me->query_skill("zui-quan", 1);
        message_vision(msg, me, target);
    //B-/A        
    if( F_KUNGFU->hit_rate( me->query("combat_exp"), (int)target->query("combat_exp"), 10-coefficient*4, me, target) )
    {
        message_vision(HIB"\n$n哪里见过这种怪招?纳闷之时已中了一招!\n\n"NOR,me,target);
        damage=skill*(100+me->query_condition("drunk")*100/ limit)/200;
        F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
        COMBAT_D->report_status(target);
    }
    else
    {
        message_vision(HIB"\n$n双手平推,推开了$N的肘部!\n\n"NOR,me,target);
        me->start_busy(3);
        if (!target->is_busy()) target->start_busy(random(5));
        return 1;
    }
    return 1;
}


