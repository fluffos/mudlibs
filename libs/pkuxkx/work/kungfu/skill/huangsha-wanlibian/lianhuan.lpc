//shawei.c 杀威棍棒

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int skill,extra;
        object weapon;

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("连环诀只能对战斗中的对手使用。\n");
                
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对。\n");

        if( (int)me->query_str() < 40)
                return notify_fail("你的臂力不够，无法施展连环诀。\n"); 
        if (me->query_temp("hswlbpfm"))
        {
            return notify_fail("你刚刚用过，不能马上使用连环诀。\n");
        }
        if( (int)me->query_skill("huangsha-wanlibian", 1)  < 300 )
                return notify_fail("你的黄沙万里鞭不够娴熟，不会使用连环诀。\n");

        if( (int)me->query_skill("force", 1) < 300 )
                return notify_fail("没有内功支持，不能使用连环诀。\n");

        if( (int)me->query("max_neili") < 2500 || (int)me->query("neili") < 1500 )
                return notify_fail("你的内力不足，无法使用连环诀。\n");

        msg = YEL"$N招数连变，手下毫不停歇，对着$n一声尖啸，鞭影连环不绝！\n"NOR;
        message_vision(msg, me, target);            
        me->add("neili", -200);
        
        me->set_temp("hswlbpfm",1);
        skill=(int)me->query_skill("huangsha-wanlibian", 1);
        extra = (int)skill/5;
        if( (int)me->query("pin") == 1) extra += extra;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        if( !target->is_busy() ) target->start_busy(1);
        msg = HIR"黄河捧土尚可塞\n"NOR;
        if( me->is_fighting(target) )  COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
        msg = HIR"欲渡黄河冰塞川\n"NOR;
        if( me->is_fighting(target) )  COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
        msg = HIR"将登太行雪暗天\n"NOR;
        if( me->is_fighting(target) )  COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR, msg);
        me->add_temp("apply/attack", -extra);    
        me->add_temp("apply/damage", -extra);
        if((int)me->query("neili") < 0) me->set("neili", 0);
        me->start_busy(3+random(2));
        call_out("removehswlb", 8,me);
        return 1;
}

int removehswlb(object me)
{
    me->delete_temp("hswlbpfm");
    return 1;
}