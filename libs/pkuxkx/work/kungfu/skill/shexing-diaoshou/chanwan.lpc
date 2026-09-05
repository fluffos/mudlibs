//chanwan.c

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
        int extra,rate,rate1;

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「金丝缠腕」只能对战斗中的对手使用。\n");

        if ( me->check_hand() >= 1 )
            return notify_fail("你双手不空，怎能发招！\n");

        if( ((int)me->query_skill("shexing-diaoshou",1)) < 100)
                return notify_fail("你的功夫太差了，无法用金丝缠腕。\n"); 

        if ((int)me->query_skill("hamagong", 1) < 100)
                return notify_fail("你的蛤蟆功修为还不够。\n");

        if( (int)me->query("max_neili") < 300 || (int)me->query("neili") < 300 )
                return notify_fail("你的内力不足，无法使用金丝缠腕。\n");
          
        //if( me->is_busy() ) return notify_fail("你正忙着呢，不能使用金丝缠腕。\n");

        if( target->is_busy() ) return notify_fail("对方正忙着呢，放心进攻吧。\n");
        
        msg = HIY "$N蹂身欺近，左手急扣$n右手脉腕，顺势按搭于自己右腕，同时右掌上翻，掌外缘由下而内旋拧卷压！\n";

        extra = me->query_skill("shexing-diaoshou")/30 + (int)me->query_skill("hamagong", 1)/60;
        if (extra>=40) extra = 40;

        me->add("neili",-100);
        me->start_busy(1+random(2));
//命中率级别是C-|E-=B-/2+C+/2        
        if( F_KUNGFU->hit_rate( me->query("combat_exp"), target->query("combat_exp"), 9, me, target)
         || F_KUNGFU->hit_rate( me->query_str(), (int)target->query_str(), 15, me, target) )  
        {
                msg += HIR"结果$n措不及防，但觉身后右臂曲扭疼痛，始知已为$N所制，登时动弹不得！\n" NOR;
                message_vision(msg, me, target);
                F_KUNGFU->hit_busy( "fenjin", extra, target );
        } else {
				
                msg += HIG"$n见势不妙，垂肘屈腕，右臂趁势外旋，已轻巧脱出$N的掌握！\n" NOR;
            //    message_vision(msg, me, target);
				if (me->query("safari_skill/bts1")&&me->query("family/family_name")=="白驼山")
				{
					rate1 = me->query_skill("hamagong",1);
					if (rate1 >= 1800)
					{
						rate = 8;
					}
					else
					{
						rate = 12 - (int)rate1/450;
					}
					
					if(F_KUNGFU->hit_rate(me->query_skill("hamagong",1), target->query_skill("force",1), rate, me, target))
					{
						msg += HIR"$N的手腕犹如灵蛇，突然从另外一个方向转了过来，$n意料之外，已为$N所制，动弹不得！\n" NOR;
			//			message_vision(msg, me, target);
						F_KUNGFU->hit_busy( "fenjin", extra, target );
					}
					else
					{
						msg += HIG"$N的手腕犹如灵蛇，突然从另外一个方向转了过来，$n却好像早有预料，转开了手臂！\n" NOR;
			//			message_vision(msg, me, target);
					}
				}
				message_vision(msg, me, target);
        }
        return 1;
}

