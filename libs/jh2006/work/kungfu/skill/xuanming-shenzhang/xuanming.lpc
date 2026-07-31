#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("玄冥双掌只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("xuanming-shenzhang", 1) < 200 )
                return notify_fail("你的玄冥神掌不够娴熟，无法使用玄冥双掌。\n");
        if( (int)me->query_skill("force") < 350 )
                return notify_fail("你的内功不够娴熟，无法使用玄冥双掌。\n");

        if ( (int)me->query("max_neili") < 4000)
                return notify_fail("你的真气不够，无法使用玄冥双掌。\n");

        if ( (int)me->query("neili") < 7000)
                return notify_fail("你的内力不够，无法使用玄冥双掌。\n");
             if(me->query("jingli")<3000)
                  return notify_fail("你的精力不够，无法使用玄冥双掌。\n");
           if(me->query_skill_mapped("parry")!="xuanming-shenzhang"
         ||me->query_skill_mapped("strike")!="xuanming-shenzhang"
         ||me->query_skill_prepared("strike")!="xuanming-shenzhang")
                 return notify_fail("你并没有准备好使用“玄冥双掌”\n");

        msg = HIY"$N一掌击向$n，另一掌却无声无息的拍向$n的丹田！\n";
        if( random(me->query_dex()) > (int)target->query_dex()/2 ) {
                msg += HIR"$n躲闪不及，正中丹田！$n闷哼一声，似乎中了极重的内伤，内力流失极多！\n";
                target->add("max_neili",-(random(me->query_skill("xuanming-shenzhang",1)/50)+1));
                if (random(2)) {
                  target->set_skill("force", target->query_skill("force",1)-1);
                  msg += HBRED"$n的内功也受到了极大的伤害！\n"NOR;
                }
                target->set("neili",0);
                target->set("jiali",0);
                target->apply_condition("xuanmin_poison", 50+random(30));
                me->add("neili", -1500-random(1000));
                me->add("jingli", -1500-random(1000));
        } 
        else {
                msg += HIG"$n急忙抽手，向后跃开。\n" NOR;
        }
        message_vision(msg, me, target);
        me->start_busy(1+random(2));
        me->start_perform((4+random(2)), "玄冥双掌");
        return 1;
}


