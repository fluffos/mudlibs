//fuxue.c 拈花拂穴
//nianhua-zhi的busy不能高，少林保留yizhi-chan为终极busy。jpei05112008
#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !objectp(target) ) return notify_fail("你要拂谁的穴。\n");

        if( (int)me->query_str() < 25)
                return notify_fail("你的臂力不够，无法施展拈花拂穴。\n");

        if( (int)me->query_skill("nianhua-zhi", 1) + (int)me->query_skill("finger", 1)/2 < 90 )
                return notify_fail("你的指法不够娴熟，不会使用拈花拂穴。\n");

        if( (int)me->query_skill("hunyuan-yiqi", 1) < 90 )
                return notify_fail("你的混元一气功等级不够，不能使用拈花拂穴。\n");

        if( (int)me->query("max_neili") < 300 || (int)me->query("neili") < 300 )
                return notify_fail("你的内力不足，无法使用拈花拂穴。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "已经自顾不暇，你就放胆进攻吧。\n");

        msg = HIY "$N忽地面带微笑，右手姆、食、中指伸出成拈花状，左手中指空屈欲弹浮尘，便在这意境无限间蕴涵禅机悠远。须臾只听哧的一声，$N的"HIC"拈花指"HIY"力已罩向$n"HIY"的胸口大穴。\n";

        me->add("neili", - 100);

			  if( F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), 9, me, target) ) {
                msg += HIY "$p已经沉醉在$P"HIC"拈花微笑"HIY"的无言境界中浑然不知闪躲，但觉胸前有力轻触，全身真气已然受制，连一根指头也动弹不得。\n" NOR;
                message_vision(msg, me, target);
                F_KUNGFU->hit_busy( "dianxue", (int)me->query_skill("nianhua-zhi")/30, target );
        } else {
                msg += HIW "$p深知佛理，对$P的谜题一笑置之，飘然避开迎面指力轻笑摇头唱道："HIG"本来无一物，何处惹尘埃？\n" NOR;
                message_vision(msg, me, target);
                me->start_busy(3);
        }

        if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
        if( !me->is_fight(target) ) me->fight_ob(target);
        return 1;
}

