// xiqi.c for xixin-dafa

#include <ansi.h>

int exert(object me, object target)
{
        int sp, dp;

        if( !objectp(target) || target->query("id") == "mu ren" )
                return notify_fail("你要吸取谁的体力？\n");

        if ( me->query_temp("sucked") )
                return notify_fail("你刚刚吸取过气！\n");

        if( (int)me->query_skill("xixin-dafa",1) < 70 )
                return notify_fail("你的吸心大法功力不够，不能吸取对方的内力!\n");

        if( (int)me->query("neili",1) < 40 )
                return notify_fail("你的内力不够，不能使用吸心大法。\n");

        if( (int)target->query("max_neili") <= 0 )
                return notify_fail( target->name() +
                        "没有任何内力！\n");
     if( (int)target->query("neili") < (int)target->query("max_neili") / 10 )
                return notify_fail( target->name() +
                        "已经内力涣散，你已经无法从他体内吸取任何内力了！\n");

        message_vision(
                HIR "$N脸色一变，右掌突然指出，猛地对准$n的膻中大穴点了上去！\n\n" NOR,
                me, target );

        if( !target->is_killing(me) ) target->kill_ob(me);

     sp = me->query_skill("force") + me->query_skill("dodge") + me->query("kar");
        dp = target->query_skill("force") + target->query_skill("dodge") + me->query("kar");

        me->set_temp("sucked", 1);              

        if( random(sp) > random(dp) )
        {
                tell_object(target, HIR "你顿觉膻中微痛，如同被尖针刺了个小孔，全身气力飞泄而出！\n" NOR);
                tell_object(me, HIG "你觉得" + target->name() + "的气力自手掌源源不绝地流了进来。\n" NOR);

                target->add("qi", -1*(int)me->query_skill("xixin-dafa", 1) );
                me->add("qi", (int)me->query_skill("xixin-dafa", 1) );
              if( target->query("combat_exp") >= me->query("combat_exp") ) {             
                        if( (int)me->query("potential") - (int)me->query("learned_points") < 100 )
                                me->add("potential", 1);
                        me->add("combat_exp", 1);
                }

                me->start_busy(random(4));
                target->start_busy(random(4));
                me->add("neili", -60);

            call_out("del_sucked", 2, me);
        }
        else
        {       
                message_vision(HIY "可是$p看破了$P的企图，机灵地闪了开去。\n" NOR, me, target);
                me->start_busy(4);
                call_out("del_sucked", 4, me);
        }

        return 1;
}
void del_sucked(object me)
{
        if ( me->query_temp("sucked"))
        me->delete_temp("sucked");
}

