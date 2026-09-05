// guiyuan.c 先天功五气归元
//by yhzzyahoo @2015.4.21
/*
立即恢复的气血：先天功等级x2；
立即治疗的气血：先天功等级；
气血恢复速度:先天功等级x2；
精神恢复速度：先天功等级x2 ；
气血治疗速度 先天功等级/10；
精神治疗速度 先天功等级/10；
内力恢复速度：先天功等级/5；
有出师判师，上述效果减半；
持续时间为：先天功等级/(25*(1+出师次数+判师次数))
*/
#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int level;
		int bet_cnt,bet_xs;//出师判师影响系数
		int need_lv;//需求等级
		int dur_time,cd_time;//持续时间,cd时间
		int qi_recover_now,qi_cure_now;//各种增益数据
		int i_temp;
        if ( !me->query("safari_skill/qz1") ) 
			return 0;
       if ( !me->is_fighting() ) 
			return notify_fail("你只能在战斗中才能进入先天功『五气归元,生生不息』的至高境界。\n");
		if ( me->query("family/family_name")!="全真派" )
		{
			return notify_fail("你不是全真弟子,不能体会先天功五气归元,生生不息的高深境界。\n");
		}
        if( target != me )
                return notify_fail("你只能对自身使用五气归元效果。\n");
        if( (int)me->query("neili") < 200  )
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("guiyuan") )
                return notify_fail("你已经在运功中了。\n");
		need_lv=501;
		bet_cnt=2;
		bet_xs=1;
		cd_time=60;
		if (me->query("chushi/done"))
		{
			need_lv = 1001;
			bet_cnt = 1;
			bet_xs = bet_xs+1;
			cd_time=120;
		}
		if (me->query("betrayer"))
		{
			need_lv = 1001;
			bet_cnt = 1;
			bet_xs = bet_xs + me->query("betrayer");
			cd_time=120;
		}
        if( (time() - (int)me->query_temp("guiyuan_lost_time")) < cd_time )
                return notify_fail("你刚刚五气归元完毕，气息尚未平复。\n");

		level=(int)me->query_skill("xiantian-gong", 1);
        if ( level < need_lv)
                return notify_fail("你的先天功等级不够，不能进入五气归元的状态。\n");
		qi_recover_now = level*bet_cnt;
		qi_cure_now = qi_recover_now/2;
		dur_time = level/(25*bet_xs);
		message_vision(HIR "$N长啸一声，内家真气源源不断的由丹田涌出，竟有越战越勇之势！。\n" NOR, me);
		i_temp= me->query("eff_qi") + qi_cure_now;
		if (i_temp > me->query("max_qi"))
		{
			me->set("eff_qi", me->query("max_qi"));
		}
		else
		{
			me->add("eff_qi",qi_cure_now);
		}
		i_temp= me->query("qi") + qi_recover_now;
		if (i_temp > me->query("eff_qi"))
		{
			me->set("qi",me->query("eff_qi"));
		}
		else
		{
			me->add("qi",qi_recover_now);
		}
        me->add_temp("apply/qi_recover", qi_recover_now);
        me->add_temp("apply/qi_cure", qi_recover_now/20);
        me->add_temp("apply/jing_recover", qi_recover_now);
        me->add_temp("apply/jing_cure", qi_recover_now/20);
        me->add_temp("apply/neili_recover", qi_recover_now/10);
        me->set_temp("guiyuan", 1);
		me->set_temp("guiyuan_cd",1);
        me->add("neili", -100);

        me->set_temp("active_force_buffer/xiantian-gong.guiyuan/name", "五气归元");                                  //buff名称
        me->set_temp("active_force_buffer/xiantian-gong.guiyuan/last_time", time() + dur_time );              //持续时间
   //     me->set_temp("active_force_buffer/xiantian-gong.guiyuan/effect1", "回复速度增加:"+qi_recover_now);	//buff效果1
     //   me->set_temp("active_force_buffer/xiantian-gong.guiyuan/effect2", "治疗速度增加:"+qi_recover_now/20);	//buff效果1
       // me->set_temp("active_force_buffer/xiantian-gong.guiyuan/effect3", "内力回复增加:"+qi_recover_now/10);	//buff效果1

		me->start_call_out(__FILE__, "remove_effect", dur_time, me, qi_recover_now);

     //   if( me->is_fighting() ) me->start_busy(1);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/qi_recover", -amount);
        me->add_temp("apply/qi_cure", -amount/20);
        me->add_temp("apply/jing_recover", -amount);
        me->add_temp("apply/jing_cure", -amount/20);
        me->add_temp("apply/neili_recover", -amount/10);
        me->delete_temp("guiyuan");
        me->delete_temp("active_force_buffer/xiantian-gong.guiyuan");
        message_vision(HIB "$N的先天功运行完毕，低啸一声，延绵不绝，不能再维持五气归元的至高境界了。\n"NOR, me);
        me->set_temp("guiyuan_lost_time",time());
}


