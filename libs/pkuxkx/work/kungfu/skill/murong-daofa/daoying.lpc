#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me,object target)
{
        int d=me->query_skill("yanling-shenfa",1)/5;
        int j=me->query_skill("murong-daofa", 1)/5;
        int i=me->query_skill("xingyi-zhang", 1)/5;
        object weapon = me->query_temp("weapon");
        string msg;
        if(!target)
                target = offensive_target(me);
        if(!weapon)
                return notify_fail("你没有拿刀作为主要武器，不能使用刀影掌！\n");

        if( (int)me->query_skill("shenyuan-gong", 1) < 100 )
                return notify_fail("你的内功还未练成，不能使用刀影掌！\n");
        if( (int)me->query_skill("murong-daofa", 1) < 100 )
                return notify_fail("你的刀法还未练成，不能使用刀影掌！\n");
        if((int)me->query_skill("xingyi-zhang", 1) < 100 )
                return notify_fail("你的掌法还未练成，不能使用刀影掌！\n");

        if((int)me->query("neili") < 600 )
                return notify_fail("你现在内力不足，不能使用刀影掌！\n");
        if((int)me->query_skill("blade", 1) < 100 )
                return notify_fail("你的基本刀法不够娴熟，不能在刀招中夹杂使用刀影掌。\n");
        if((int)me->query_skill("strike", 1) < 100 )
                return notify_fail("你的基本掌法不够娴熟，不能在刀招中夹杂使用刀影掌。\n");
        if(me->query_temp("busy_daoying")>time())
                return notify_fail("绝招用多了就不灵了。\n");
        me->set_temp("busy_daoying",time()+6+random(4));
               
        msg = HIR"\n$N"HIR"大吼一声使出慕容绝学「刀影掌」，掌随刀走，刀光中夹杂着阵阵掌风一起奔向$n！\n"NOR ;
        me->add("neili", -200);
        me->add("jing", -100);
        me->add_temp("apply/dodge", d);
        me->add_temp("apply/attack", (i+j)/2);
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR);
        weapon->unequip();
        msg = YEL"$N"YEL"弃刀换掌，身形飞转！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR);
        weapon->wield();
        msg = YEL"$N"YEL"收掌拿刀，身形飞转！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR);

        me->add_temp("apply/attack", -((i+j)/2));
        me->add_temp("apply/dodge", -d);
        if ( F_KUNGFU->hit_rate( me->query("combat_exp"), (int)target->query("combat_exp"), 9, me, target) )
        {
                msg = YEL"$N"YEL"余意未尽，又是一刀！\n"NOR;
                message_vision(msg, me, target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR);
                me->add("neili", -100);
        }

        return 1;
}
