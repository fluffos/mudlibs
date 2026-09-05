// jingsuck.c


#include <ansi.h>

int exert(object me, object target)
{
        int sp, dp;

        if( !objectp(target) || target->query("id") == "mu ren" )
                return notify_fail("你要吸取谁的精神？\n");

if( !target->is_character() )
return notify_fail("看清楚一点，那并不是生物。\n");
        if ( me->query_temp("sucked") )
                return notify_fail("你刚刚吸取过精神！\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能施用北冥神功吸人精力！\n");


        if( (int)me->query_skill("beiming-shengong",1) < 30 )
                return notify_fail("你的北冥神功功力不够，不能吸取对方的精神。\n
");

        if( (int)me->query("neili",1) < 10 )
                return notify_fail("你的内力不够，不能使用北冥神功。\n");

        if( (int)target->query("jing") < (int)target->query("max_jing") / 5 )
                return notify_fail( target->name() +
                        "已经精神涣散，你已经无法从他体内吸取精力了！\n");

        message_vision(
                HIR "$N突然神秘的一笑，双掌一前一後对准$n的太阳穴拍了过来！\n"
 NOR,
                me, target );

        if( !target->is_killing(me->query("id")) ) target->kill_ob(me);

        sp = me->query_skill("force") + me->query_skill("dodge") + me->query("ka
r");
        dp = target->query_skill("force") + target->query_skill("dodge") + me->query("kar");

        me->set_temp("sucked", 1);
//C-
        if( F_KUNGFU->hit_rate( sp, dp, 9, me, target) )
        {
                tell_object(target, HIR "你猛觉额角两侧如针刺般剧痛，神志迷困\n" NOR);
                tell_object(me, HIG "你觉得" + target->name() + "的精力自手掌源?
                源涌入身来\n" NOR);

        target->receive_damage("jing", (int)me->query_skill("beiming-shengong", 1), me);
                me->add("jing", (int)me->query_skill("beiming-shengong", 1) );

                if( target->query("combat_exp") >= me->query("combat_exp") ) {
       if( (int)me->query("potential") - (int)me->query("learned_points") < 300
)
                                me->add("potential", 1);
                }

                me->start_busy(random(3));
                if (!target->is_busy()) target->start_busy(random(3));
                me->add("neili", -5);

                call_out("del_sucked", 2, me);
        }
        else
        {
                message_vision(HIY "可是$p看破了$P的企图，机灵地闪了开去。\n" NOR, me, target);
                me->start_busy(3);
                call_out("del_sucked", 4, me);
        }

        return 1;
}

void del_sucked(object me)
{
        if ( me->query_temp("sucked") )
        me->delete_temp("sucked");
}


