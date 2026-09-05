//杀气纵横
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
if(me->query("zuiquanpf")!=4) return notify_fail("你不会这一招!\n");
            if( objectp(me->query_temp("weapon")) )
                 return notify_fail("使用杀气纵横,必须空手!\n");
        limit = (me->query("con") + (int)me->query("max_neili") / 50) * 2;

        if( !target ) target = offensive_target(me);
                        

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("杀气纵横只能对战斗中的对手使用。\n");
       if( (int)me->query("max_neili")< 400 || (int)me->query("neili") < 400 )
                return notify_fail("你的内力不足，无法使用杀气纵横。\n");
    if((int)me->query("shaqi")<1)  return notify_fail("你心中毫无杀气,如何使得出这一招?\n");
 me->kill_ob(target);
target->kill_ob(me);

        if( !(int)me->query_condition("drunk"))
       {
            msg = HIC"\n$N故作醉态,使出「杀气纵横」$N仰天狂笑一番,忽然间眼中布满血丝,双手从身下缓缓升起\n,$n已分不清$N是拳是掌抑或是爪,只见$N双手从不同的角度向自己袭来!\n\n"NOR;
              coefficient=1;
             }
     else
        {
            msg = HIC"\n$N拳借酒势,使出「杀气纵横」$N仰天狂笑一番,忽然间眼中布满血丝,双手从身下缓缓升起\n,$n已分不清$N是拳是掌抑或是爪,只见$N双手从不同的角度向自己袭来!\n\n"NOR;
              coefficient=2;
          }

        me->add("neili", - 400);
          skill=(int)me->query_skill("zui-quan", 1);
        message_vision(msg, me, target);
    if( F_KUNGFU->hit_rate( me->query("combat_exp"), (int)target->query("combat_exp"), 27-coefficient*9, me, target) )
    {
        message_vision(HIB"\n霎那间,$n感到周身全是$N的身影,已避无可避,被$N打得吐了一口鲜血!\n\n"NOR,me,target);
        damage=skill*(200+me->query_condition("drunk")*50/limit )/100;
        F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
        COMBAT_D->report_status(target);
        if(target->query("qi")<500)
        {
        target->receive_damage("qi", 0, me);
        target->die();
        me->start_busy(1);
        message_vision(HIR"\n$N看到对方的身影在自己眼前慢慢倒下去,忽然感到浑身松软\n\n"NOR,me);
        me->receive_damage("qi", 0, target);
        me->unconcious();
        return 1;
        }
    }
    else
    {
        message_vision(HIB"\n$n见势不对,一个就地十八滚,躲了开去!\n\n"NOR,me,target);
        me->start_busy(3);
        if ( !target->is_busy() )
        target->start_busy(random(5));
        return 1;
    }
    return 1;
}


