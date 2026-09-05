//『大智无定指』
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

        if ( !me->is_fighting() ) return notify_fail("你只能在战斗中使用『大智无定指』。");

        if ( !me->query("tqt_sl_skill1") ) return 0;

		if(me->query("family/family_name")!="少林派") 
			return notify_fail("非少林弟子无法使用『大智无定指』。\n");

        if ( time()- me->query_temp("no_dazhi-wuding")<=20 )
                return notify_fail("你刚刚使用过『大智无定指』，气息还未平复。\n");

        if( (int)me->query_str() < 40)
                return notify_fail("你的臂力不够，无法施展『大智无定指』。\n");

        if( (int)me->query_skill("yizhi-chan", 1) < 100 )
                return notify_fail("你的一指禅不够娴熟，不会使用『大智无定指』。\n");

        if( (int)me->query_skill("hunyuan-yiqi", 1) < 100 )
                return notify_fail("你的混元一气功等级不够，不能使用『大智无定指』。\n");

        if( (int)me->query_skill("buddhism", 1) < 150 )
                return notify_fail("你的禅宗心法功等级不够，不能使用『大智无定指』。\n");

        if( (int)me->query("max_neili") < 2000 || (int)me->query("neili") < 1000 )
                return notify_fail("你的内力不足，无法使用『大智无定指』。\n");

        message_vision(HIW"\n$N神态自若，连弹数指，却是封住自己身上要穴！\n" NOR,me);
        me->add("neili", -400);
        me->set_temp("no_dazhi-wuding",time());
        me->set_temp("dazhi-wuding",1);
		//去掉大智的buff标记 by pkuxkx.yhzzyahoo
     //   me->set_temp("active_buffer/family","少林派");
    if ((me->query("family/family_name")=="少林派") && (!me->query("chushi/done")) && (!me->query("betrayer")))
	{
		dur=16;
	}
	else
	{
		dur=12;
	}
        me->set_temp("active_buffer/yizhi-chan.dazhi/name", "大智无定指");                  //buff名称
        me->set_temp("active_buffer/yizhi-chan.dazhi/last_time", time() + dur);               //持续时间
        me->set_temp("active_buffer/yizhi-chan.dazhi/effect1", "免疫技能特效");             //效果描述1
        call_out("remove_effect", dur, me );
        return 1;
}

protected int remove_effect(object me)
{
        int skill;
        if (!me)	return 0;

        me->delete_temp("dazhi-wuding");
        me->delete_temp("active_buffer/yizhi-chan.dazhi");
        if ( sizeof(me->query_temp("active_buffer"))==1 )
        	me->delete_temp("active_buffer");
        if(living(me) && !me->is_ghost())
          message_vision(GRN"良久，$N所使『大智无定指』效果在慢慢减弱。\n"NOR, me);
        return 0;
}
