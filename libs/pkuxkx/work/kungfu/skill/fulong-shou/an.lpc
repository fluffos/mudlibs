
#include <ansi.h>

inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
    string msg;
    int level,bs;
	int busy_rate;

    if( target->is_busy() )
        return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

    if( me->query_skill("hand", "fulong-shou") < 100 )
        return notify_fail("乾坤伏龙手逆鳞按穴需要有效手法 100 级。\n");
    if( me->query("neili") < 100 )
        return notify_fail("乾坤伏龙手逆鳞按穴需要内力 100 以上。\n");
        
    msg = HIY "$N使出乾坤伏龙手绝技「逆鳞按穴」，罩住了$n的全身要穴。\n";
    me->add("neili", - 100);
    level=me->query_skill("fulong-shou",1);
    bs=level/100;
    if ( bs > 15 )
    	bs=15;
   //门派大招影响
	if (me->query_temp("active_force_buffer/cangming-gong.zhengqi") && me->query_temp("cmg/zhengqi/times") < me->query_temp("cmg/zhengqi/point")&& !me->query_temp("cmg_zq_buff"))
	{
		busy_rate=1;
		me->add_temp("cmg/zhengqi/times",1);
		me->set_temp("cmg_zq_buff",1);
		me->add("neili",-800);
		msg += HIR "$N大气凛然，临战神勇！\n" NOR;
	}
	else
	{
		busy_rate=9;
	}

    if( F_KUNGFU->hit_rate( me->query("combat_exp"), target->query("combat_exp"), busy_rate, me, target) )
    {
        msg += "$P的手以逆鳞的霸气之势游走于$p各大要穴，$p的身形顿时缓了下来。\n" NOR;
        F_KUNGFU->hit_busy( "dianxue", 5 + bs + random(6), target );
    }
    else
    {
        me->start_busy(4);
        msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
    }
	if (me->query_temp("cmg_zq_buff"))
	{
		me->delete_temp("cmg_zq_buff");
	}

    message_vision(msg, me, target);
    // 最后再叫杀，使得信息显示更合理
    if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
    if( !me->is_fight(target) ) me->fight_ob(target);
    
    return 1;
}
