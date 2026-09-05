// chan.c 日月鞭法「缠绕」诀

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        object weapon;
		int busy_rate;
		int time_rate;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("牵制攻击只能对战斗中的对手使用。\n");
        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");
        if(!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对。\n"); 
        if( (int)me->query("neili") < 400  ) 
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_skill("whip") < 100  ) 
                return notify_fail("你的鞭法不够熟练。\n");                
	      msg = WHT "$N" WHT "喝道：“接我这招「秋云锁龙」如何！？”" + weapon->name() +
              WHT"如蛟龙出水，如影随形，织出如风如云的鞭势，缠向$n"  WHT "防不胜防之处。\n" NOR;

        me->start_busy(2);
//命中率级别D+级

   //门派大招影响
	if (me->query_temp("active_force_buffer/cangming-gong.zhengqi") && me->query_temp("cmg/zhengqi/times") < me->query_temp("cmg/zhengqi/point")&& !me->query_temp("cmg_zq_buff"))
	{
		busy_rate=1;
		time_rate=50;
		me->add_temp("cmg/zhengqi/times",1);
		me->set_temp("cmg_zq_buff",1);
		me->add("neili",-900);
		msg += HIR "$N大气凛然，临战神勇！\n" NOR;
	//	message_vision(msg,me,target);
	}
	else
	{
		busy_rate=10;
		time_rate=40;
	}

        if ( F_KUNGFU->hit_rate( me->query_skill("whip"), target->query_skill("parry"), busy_rate, me, target ) ) 
        {
					msg += HIY "结果$p" HIY "如龙入浅滩，顿时被$P" HIY "鞭势牢牢锁住，"+"攻得全然没了招式，手脚慌乱，连连叫苦！\n" NOR;
					F_KUNGFU->hit_busy( "body", (int)me->query_skill("whip") / time_rate + 1, target );
				} 
				else
        {
					msg += CYN "可是$p" CYN "身形一变，跳出了$P" CYN "的天罗地网，潇洒地落在你身"+"前。\n" NOR;
				}
				me->add("neili", -100);
	if (me->query_temp("cmg_zq_buff"))
	{
		me->delete_temp("cmg_zq_buff");
	}

        message_vision(msg, me, target);

        return 1;
}

