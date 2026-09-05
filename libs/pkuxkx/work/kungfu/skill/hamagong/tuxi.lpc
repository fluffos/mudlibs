//『蛤蟆吐息』
// Zine 天龙八部jiumozhi使用
//修改到20s cd，15s持续，测试用by yhzzyahoo 2015/2/15
#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="self" ;
}

int perform(object me)
{
        int dur;

        if ( !me->is_fighting() ) return notify_fail("你只能在战斗中使用『蛤蟆吐息』。");

        if ( !me->query("safari_skill/bts1") ) return 0;

		if(me->query("family/family_name")!="白驼山") 
			return notify_fail("非白驼弟子无法使用『蛤蟆吐息』。\n");

        if ( time()- me->query_temp("no_hamatuxi")<=30 )
                return notify_fail("你刚刚使用过『蛤蟆吐息』，气息还未平复。\n");

        if( (int)me->query_str() < 50)
                return notify_fail("你的臂力不够，无法施展『蛤蟆吐息』。\n");

        if( (int)me->query_skill("strike", 1) < 400 )
                return notify_fail("你的基本掌法不够娴熟，不会使用『蛤蟆吐息』。\n");

        if( (int)me->query_skill("hamagong", 1) < 400 )
                return notify_fail("你的蛤蟆功等级不够，不能使用『蛤蟆吐息』。\n");

        if( (int)me->query_skill("poison", 1) < 350 )
                return notify_fail("你的基本毒技等级不够，不能使用『蛤蟆吐息』。\n");

        if( (int)me->query("max_neili") < 2000 || (int)me->query("neili") < 1000 )
                return notify_fail("你的内力不足，无法使用『蛤蟆吐息』。\n");

        message_vision(HIW"\n$N上身俯倒，头向前弹出，嘴里发出呱呱之声！\n" NOR,me);
        me->add("neili", -400);
        me->set_temp("no_hamatuxi",time());
        me->set_temp("hamatuxi",1);
		//tuxi自我buff，不算入增益buff
     //   me->set_temp("active_buffer/family","白驼山");
		dur=10+me->query_skill("hamagong", 1)/200;
        me->set_temp("active_buffer/hamagong.tuxi/name", "蛤蟆吐息");                  //buff名称
        me->set_temp("active_buffer/hamagong.tuxi/last_time", time() + dur);               //持续时间
        me->set_temp("active_buffer/hamagong.tuxi/effect1", "增强蛤蟆功效果");             //效果描述1
		me->start_busy(1);
        call_out("remove_effect", dur, me );
        return 1;
}

protected int remove_effect(object me)
{
        if (!me)	return 0;

        me->delete_temp("hamatuxi");
        me->delete_temp("active_buffer/hamagong.tuxi");
         if(living(me) && !me->is_ghost())
          message_vision(GRN"良久，$N所使『蛤蟆吐息』效果在慢慢减弱。\n"NOR, me);
        return 0;
}
