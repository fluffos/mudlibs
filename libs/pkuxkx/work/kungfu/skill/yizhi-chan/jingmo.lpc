//jingmo 惊魔一指
//modified by jpei-05112008 调整busy敌我时间。少林逐步调整空手，加强多样性选择。
//非少林弟子，不能适用此特殊攻击。
//准备更新下看看
#include <ansi.h>
#include <char.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        string msg;
        int busy_time;

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("惊魔一指只能对战斗中的对手使用。\n");

        if( (int)me->query_str() < 40)
                return notify_fail("你的臂力不够，无法施展惊魔一指。\n");

        if( (int)me->query_skill("yizhi-chan", 1) < 120 )
                return notify_fail("你的一指禅不够娴熟，不会使用惊魔一指。\n");

        if( (int)me->query_skill("hunyuan-yiqi", 1) < 120 )
                return notify_fail("你的混元一气功等级不够，不能使用惊魔一指。\n");

        if( (int)me->query_skill("buddhism", 1) < 120 )
                return notify_fail("你的禅宗心法功等级不够，不能使用惊魔一指。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "已经自顾不暇，你就放胆进攻吧。\n");

        if( (int)me->query("max_neili") < 2000 || (int)me->query("neili") < 1000 )
                return notify_fail("你的内力不足，无法使用惊魔一指。\n");

        if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) && 
            (string)me->query("family/family_name") != "少林派" )
                return notify_fail("你不是佛门弟子，怎能怀慈悲之心！\n");

        msg = HIC"\n$N面露慈笑，曲指对着$n轻轻一弹，只听嗤的一声一股劲气从$P手指激射而出，窜向$p胸前大穴！\n" NOR;
    
		me->add("neili", -200);

		    if( F_KUNGFU->hit_rate_sk(me->query_skill("finger", "yizhi-chan"), (int)target->query_skill("dodge"), 6, me, target) )

				{
	
                msg += HIR "结果$p胸前大穴被$P指力点中，全身动弹不得。\n" NOR;
  
					message_vision(msg, me, target);
	
                busy_time = (int)me->query_skill("yizhi-chan", 1)/20;
 
					F_KUNGFU->hit_busy( "dianxue", busy_time, target );

				}
	
		else
		
		{

					msg += HIW "可是$p看破了$P的企图，侧身避过指力。\n" NOR;

					if (me->query_temp("dazhi-wuding")&&F_KUNGFU->hit_rate_sk(me->query_skill("yizhi-chan", 1), (int)target->query_skill("parry", 1), 9, me, target) )
		
                {
		
                    msg+=HIR"岂料指劲一波一波传递而来，终于防不胜防，被指风拂过。\n"NOR;

							busy_time = (int)me->query_skill("yizhi-chan",1)/40;

							F_KUNGFU->hit_busy( "dianxue", busy_time, target );

						}

			//设置busy自己的时候和buddhism等级挂钩。
			        busy_time = 4 - (int)me->query_skill("buddhism", 1)/500;
					if (busy_time < 1) busy_time = 1;
	                me->start_busy(busy_time);
		            message_vision(msg, me, target);
				}

        // 是否叫杀，于buddhism等级挂钩。 modified by jpei from 500->400 level
        if( me->query_skill("buddhism", 1) < 400){
               if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
               if( !me->is_fight(target) ) me->fight_ob(target);
        }
        return 1;
}

