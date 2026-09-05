// neilisuck.c
// paladin
#include <ansi.h>

int exert(object me, object target)
{
        int sp, dp;

        if( !objectp(target) || target->query("id") == "mu ren" )
                return notify_fail("你要吸取谁的内力？\n");

        if ( me->query_temp("sucked") )
                return notify_fail("你刚刚吸取过内力！\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能施用北冥神功吸人内力！\n");

        if( !me->is_fighting() || !target->is_fighting())
                return notify_fail("你必须在战斗中才能吸取对方的内力！\n");

        if( (int)me->query_skill("beiming-shengong",1) < 40 )
                return notify_fail("你的北冥神功功力不够，不能吸取对方的内力！\n");

        if( (int)me->query("neili",1) < 20 )
                return notify_fail("你的内力不够，不能使用北冥神功。\n");

        if( (int)target->query("max_neili") <= 0 )
                return notify_fail( target->name() +
                        "没有任何内力！\n");

        if( (int)target->query("neili") < (int)target->query("max_neili") / 10 )
                return notify_fail( target->name() +
                        "已经内力涣散，你已经无法从他体内吸取任何内力了！\n");

        message_vision(
                HIR "$N突然伸出双手, 大拇指的少商穴与$n的手腕上穴道相触，这么一使力,\n
                $n全身一震，登时便感到内力外泄\n" NOR,
                me, target );

        if( !target->is_killing(me->query("id")) ) target->kill_ob(me);

        sp = me->query_skill("force") + me->query_skill("dodge") + me->query("kar");
        dp = target->query_skill("force") + target->query_skill("dodge") + me->query("kar");
		if (me->query("neili") > me->query("max_neili")*2)
		{
			if (me->query("max_neili") > 20*me->query_skill("force"))
				return notify_fail("你忽然觉得自己的内功有限，无法支持如此之高的内力。\n");
			else
			{
				tell_object(me,"你的内力增加了！\n");
				me->add("max_neili",1);
				me->set("neili",0);
			}
		}
		me->set_temp("sucked", 1);
        if( F_KUNGFU->hit_rate( sp, dp, 9, me, target) )
        {
                tell_object(target, HIR "你吓得魂飞魄散，拚命挥手，想摆脱$N \n
                的掌握，但给紧紧抓住了，说什么也摔不脱，越是用劲使力，内力越是\n
                飞快的散失\n" NOR);
                tell_object(me, HIG "你觉得" + target->name() + "的内力自手掌源
                源涌入身来, 便将涌到的内力储入膻中气海\n" NOR);
                target->add("neili", -1*(int)me->query_skill("beiming-shengong", 1));
                me->add("neili", (int)me->query_skill("beiming-shengong", 1) );

                if( target->query("combat_exp") >= me->query("combat_exp") ) {
   if( (int)me->query("potential") - (int)me->query("learned_points") < 300 )
                                me->add("potential", 1);
                        me->add("combat_exp", 1);
                        me->add("exp/suck",1); //增加suck的经验记录，跟踪是否利用此bug
                }

                me->start_busy(random(4));
                if (!target->is_busy()) target->start_busy(random(4));
                me->add("neili", -10);

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


