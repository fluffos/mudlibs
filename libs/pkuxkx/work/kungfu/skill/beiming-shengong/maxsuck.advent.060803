// maxsuck.c
// paladin
#include <ansi.h>

int exert(object me, object target)
{
        int sp, dp;
        int my_max, tg_max;

        my_max = me->query("max_neili");
        tg_max = target->query("max_neili");

        if (me == target)
                return notify_fail("你不能吸取自己的丹元！\n");

        if( !objectp(target) || target->query("id") == "mu ren" )
                return notify_fail("你要吸取谁的丹元？\n");

        if ( me->query_temp("sucked") )
                return notify_fail("你刚刚吸取过丹元！\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能施用北冥神功吸人丹元！\n");

        if( !me->is_fighting() || !target->is_fighting())
                return notify_fail("你必须在战斗中才能吸取对方的丹元！\n");

        if( (int)me->query_skill("beiming-shengong",1) < 80 )
                return notify_fail("你的北冥神功功力不够，不能吸取对方的丹元！\n");

        if( (int)me->query("neili",1) < 20 )
                return notify_fail("你的内力不够，不能使用北冥神功。\n");

        if( (int)target->query("max_neili") < 100 )
                return notify_fail( target->name() +
                        "丹元涣散，功力未聚，你无法从他体内吸取任何东西！\n");

        if( (int)target->query("combat_exp") < (int)me->query("combat_exp") )
                return notify_fail( target->name() +
                        "的内功修为远不如你，你无法从他体内吸取丹元！\n");

        message_vision(
                HIR "$N突然伸出双手, 大拇指的少商穴与$n的手腕上穴道相触，这么一使力,\n
                $n全身一震，登时便感到内力外泄\n"
 NOR,

                me, target );

        if( !target->is_killing(me->query("id")) ) target->kill_ob(me);

        sp = me->query_skill("force") + me->query_skill("dodge") + me->query("kar");
        dp = target->query_skill("force") + target->query_skill("dodge") + me->query("kar");

        me->set_temp("sucked", 1);

        if( random(sp) > random(dp) )
        {
                tell_object(target, HIR "你吓得魂飞魄散，拚命挥手，想摆脱$N \n
                的掌握，但给紧紧抓住了，说什么也摔不脱，越是用劲使力，内力越是\n
                飞快的散失\n" NOR);

                tell_object(me, HIG "你觉得" + target->name() + "的丹元自手掌源?                源涌入身来, 便将涌到的内力储入膻中气海\n" NOR);

                target->add("max_neili",  -1*(1+(me->query_skill("beiming-shengong",1)-90)/10) );
		if ( me->query("max_neili") < (me->query_skill("force")*me->query("con")/2) )
                	me->add("max_neili",       1*(1+(me->query_skill("beiming-shengong",1)-90)/10) );
	        if( (int)me->query("potential") - (int)me->query("learned_points") < 290 )
                	me->add("potential",  10);
                me->add("combat_exp", 10);

                me->start_busy(random(10));
                target->start_busy(random(10));
                me->add("neili", -20);

                call_out("del_sucked", 10, me);
        }
        else
        {
                message_vision(HIY "可是$p看破了$P的企图，机灵地溜了开去。\n" NOR, me, target);
                me->start_busy(10);
                call_out("del_sucked", 20, me);
        }

        return 1;
}

void del_sucked(object me)
{
        if ( me->query_temp("sucked") )
        me->delete_temp("sucked");
}

