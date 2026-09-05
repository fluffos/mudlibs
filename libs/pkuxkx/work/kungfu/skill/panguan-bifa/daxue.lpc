//快笔打穴 by Zine
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
    object weapon;
    int busy_time;
	string *xd_weizhi=({"天突穴", "璇玑穴", "华盖穴", "紫宫穴", "玉堂穴", "膻中穴", "中庭穴", "巨阙穴", "上脘穴", "建里穴", "神阙穴", "气海穴" ,"关元穴","中极穴",});

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「快笔打穴」只能对战斗中的对手使用。\n");

    if ( target->is_busy() )
         return notify_fail("对手正忙着呢，不必施展「快笔打穴」。\n");

    if ( !objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword" )
         return notify_fail("「快笔打穴」必须用剑类武器才能施展。\n");

    if( (int)me->query_str() < 40 )
        return notify_fail("你的臂力不够，无法施展「快笔打穴」。\n");

    if( (int)me->query_dex() < 40 )
        return notify_fail("你的身法不够，无法施展「快笔打穴」。\n");

    if( (int)me->query_con() < 40 )
        return notify_fail("你的根骨不够，无法施展「快笔打穴」。\n");

    if( (int)me->query_int() < 40 )
        return notify_fail("你的悟性不够，无法施展「快笔打穴」。\n");

    if( (int)me->query_skill("panguan-bifa", 1) < 300 )
        return notify_fail("你的判官笔法不够娴熟，不会使用快笔打穴。\n");
    if( (int)me->query_skill("riyue-shengong", 1) < 300 )
        return notify_fail("你的日月神功等级不够，无法使用快笔打穴。\n");
    if( (int)me->query_skill("daguangming-xinfa", 1) < 300 )
        return notify_fail("你的大光明心法等级不够，不能使用快笔打穴。\n");
	if (me->query_skill("kuihua-shengong"))
		{
			return notify_fail("葵花神功与判官笔法并不能很好的相互支持。");
		}

/*    if( target->is_busy() ) 
            return notify_fail(target->name() + "已经自顾不暇，你就放胆进攻吧。\n"); */

    if( (int)me->query("max_neili") < 2000 || (int)me->query("neili") < 1000 )
        return notify_fail("你的内力不足，无法使用快笔打穴。\n"); 

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) && 
        me->query("family/family_name") != "日月神教")
       return notify_fail("你不是神教弟子，不得在江湖中施展快笔打穴！\n");

    if ( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) && 
        !me->query("riyuepfm/bi"))
        return notify_fail("你没有领悟出快笔打穴！\n");

    msg = HIC"\n$N大喝一声笔尖连环点出，$n看得目瞪口呆！\n" NOR;
    me->add("neili", -50);//一个一个打，消耗极小。
    if ( time()-me->query_temp("pgb_time")<2 ) //连续打出，内力消耗增加，避免一指禅那种bug一点点一排。
    {
        me->add("neili",-300);
        tell_object(me,"你因为连续使用「快笔打穴」，内力消耗加剧。\n");
    }
    //命中率B		    
    if( F_KUNGFU->hit_rate_sk(me->query_skill("panguan-bifa", 1), (int)target->query_skill("dodge", 1), 5, me, target) )
    {
        msg += HIR "结果$p"+xd_weizhi[random(14)]+"被$P笔尖点中，真气一滞，动弹不得。\n" NOR;
        busy_time = (int)me->query_skill("panguan-bifa", 1)/40;
        F_KUNGFU->hit_busy( "dianxue", busy_time, target );
        me->set_temp("pgb_time", time());
    }
    else 
    {
        msg += HIW "可是$p看破了$P的企图，身形一躲，避开了此招。\n" NOR; 
        busy_time = 4 - (int)me->query_skill("daguangming-xinfa", 1)/600;
        if (busy_time < 1) busy_time = 1;
        me->add_busy(busy_time);
    }
    message_vision(msg, me, target); 


//    if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
    if( !me->is_fight(target) ) me->fight_ob(target);
    return 1;
}

