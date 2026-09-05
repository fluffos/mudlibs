//yihun.c 移魂大法

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;

int exert(object me, object target)
{
    int coe1=(int)me->query("jiuyin_1");
    if( (int)me->query_skill("jiuyin-shengong",1) <80 )
        return notify_fail("九阴神功 80 级以上才能施加移魂大法。\n");

    if( (int)me->query("neili",1) < 50 )
        return notify_fail("你的内力不到 50，不能使用移魂大法。\n");

    if( target->is_busy() )
        return notify_fail("你的移魂大法还在" + target->name() + "身上发挥着效力，放胆攻击吧！\n");

    message_vision(HIR"\n$N"HIR"突然神秘的一笑，双眼紧叮着$n"HIR"，象要把$n"HIR"的魂摄下来。\n\n" NOR, me, target );

    me->add("neili", -50);
//命中率级别C-
    if( F_KUNGFU->hit_rate(me->query("combat_exp")+me->query_skill("force")*900, target->query("combat_exp"), 9, me, target) )
    {
        if (me->query("jiuyin_1")) //铜雀台九阴
        {
            tell_object(target, HIR "你恍恍忽忽，不由跟随着"+me->name()+"的动作，整个人成了木偶一般。\n" NOR);
            message_vision(HIW "只见$n"HIW"乱蹦乱舞，拳脚向自己身上招呼过去。\n" NOR, me, target);
            target->add_temp("apply/attack", coe1*me->query_skill("jiuyin-shengong",1)/8);
            target->add_temp("apply/damage", coe1*me->query_skill("jiuyin-shengong",1)/8);
            target->add_temp("apply/parry", -coe1*me->query_skill("jiuyin-shengong",1)/8);
            target->add_temp("apply/dodge", -coe1*me->query_skill("jiuyin-shengong",1)/8);
            COMBAT_D->do_attack(target, target, target->query_temp("weapon"), TYPE_REGULAR);
            COMBAT_D->do_attack(target, target, target->query_temp("weapon"), TYPE_REGULAR);
            if (random(100)>85)
            {
                COMBAT_D->do_attack(target, target, target->query_temp("weapon"), TYPE_REGULAR);
            }
            target->add_temp("apply/attack", -coe1*me->query_skill("jiuyin-shengong",1)/8);
            target->add_temp("apply/damage", -coe1*me->query_skill("jiuyin-shengong",1)/8);
            target->add_temp("apply/parry", coe1*me->query_skill("jiuyin-shengong",1)/8);
            target->add_temp("apply/dodge", coe1*me->query_skill("jiuyin-shengong",1)/8);
            target->add_busy(2+random(2));
            return 1;
        }
        tell_object(target, HIR "你恍恍忽忽，乱蹦乱舞，不知道自己在做什么。\n" NOR);
        message_vision(HIG "只见$n"HIG"乱蹦乱舞，象一只无头苍蝇一样地到处转。\n" NOR, me, target);
        F_KUNGFU->hit_busy( "confuse", 5+random(6), target );
    }
    else
    {   
        message_vision(HIY "可是$p"HIY"看破了$P"HIY"的企图，继续攻击。\n" NOR, me, target);
        me->start_busy(2);
    }
    return 1;
}
