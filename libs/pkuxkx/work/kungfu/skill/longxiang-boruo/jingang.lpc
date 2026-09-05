// jingang.c 龙象般若之金刚
//by yhzzyahoo @2015.7.26
/*
BUFF效果：不断尝试解除busy状态               
发动cd为： 战斗中exert 1-2秒后发动第一次，之后每(10-int((龙像般若等级-500)/250))+random(2+出师次数×2+判师次数×4))秒尝试一次； 
成功几率算法为： if (random(龙像般若enable等级)>对手enable内功等级×（5+最大可达到的人物等级-当前人物等级+出师次数×2+判师次数×5）/10
||（这里是或！！）random(2+出师次数×2+判师次数×2)=1) 则解除busy    
BUFF持续时间：龙像般若等级/(10+出师次数×4+判师次数×6)   
CD时间：250秒+出师次数×150秒+判师次数×150秒
*/
#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_SSERVER;

void remove_effect_jingang(object me, int amount);
void jingang_trigger(object me,int m_level,int reset_time,int fz_times);

int exert(object me, object target)
{
        int level;
		int bet_cnt=0,cs_cnt=0;//出师判师次数
		int need_lv;//需求等级
		int dur_time,cd_time,reset_time;//持续时间,cd时间,发动时间
		int id_level,id_m_level;//人物等级，人物可以达到的最大等级
		int fz_times,i_temp;
        if ( !me->query("safari_skill/dls1") ) 
			return 0;
  //     if ( !me->is_fighting() ) 
	//		return notify_fail("你只能在战斗中才能运用龙象般若功『金刚护体』。\n");
		if ( me->query("family/family_name")!="大轮寺" )
		{
			return notify_fail("你不是大轮寺弟子,不能运用龙象般若功『金刚护体』。\n");
		}
        if( target != me )
                return notify_fail("你只能对自身使用龙象般若功『金刚护体』。\n");
        if( (int)me->query("neili") < 2000  )
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("longxiang.jingang") )
                return notify_fail("你已经在运功中了。\n");
		cs_cnt=me->query("chushi/done");
		bet_cnt=me->query("betrayer");
		level=(int)me->query_skill("longxiang-boruo", 1);
		if (me->query("chushi/done")||me->query("betrayer"))
		{
			need_lv = 1001;
			cd_time=250+(cs_cnt+bet_cnt)*150;
		}
		else
		{
			need_lv=501;
			cd_time=250;
		}

        if( (time() - (int)me->query_temp("lxjingang_start_time")) < cd_time )
                return notify_fail("你的『金刚护体』刚刚运功完毕，气息尚未平复。\n");

        if ( level < need_lv)
                return notify_fail("你的龙象般若功等级不够，不能使用『金刚护体』。\n");
		i_temp=(int)((level-500)/250);
		if (i_temp>6)
		{
			i_temp=6;
		}
		reset_time=10-i_temp+random(cs_cnt*2+bet_cnt*4+2);
		message_vision(HIY "$N默运龙象般若护体大法，身形仿佛长大了一倍，宛如金刚转世，威猛无比！\n" NOR, me);
		dur_time=level/(10+cs_cnt*4+bet_cnt*6);
		if (dur_time>210)
		{
			dur_time=210;
		}

		fz_times=(int)dur_time/reset_time;
    //    message_vision(HIB "发动间隔："+NOR+reset_time+HIB+"秒,发动次数："+NOR+fz_times+HIB+"。\n"NOR, me);

		id_m_level=me->query_lv_limit();
        me->set_temp("longxiang.jingang", 1);
		me->set_temp("lxjingang_start_time",time());
        me->add("neili", -300);

        me->set_temp("active_force_buffer/longxiang.jingang/name", "金刚护体");                                  //buff名称
        me->set_temp("active_force_buffer/longxiang.jingang/last_time", time() + dur_time );              //持续时间
		
		i_temp=1+random(2);
		call_out("jingang_trigger", i_temp, me,id_m_level,reset_time,fz_times+1);
  
        return 1;
}


void jingang_trigger(object me,int m_level,int reset_time,int fz_times)
{
	object target;
	int bet_cnt=0,cs_cnt=0;//出师判师次数
	int lx_lv=(int)me->query_skill("longxiang-boruo", 1);//龙象等级
	int lx_f_lv,t_f_lv;
	int id_level;//人物等级，人物可以达到的最大等级
	//int i_temp0,i_temp1,i_temp2,i_temp3;

  //    message_vision(HIB "调用1次。总计"+NOR+(fz_times-1)+HIR+"次。\n"NOR, me);
	fz_times-=1;
    if( me->query_temp("longxiang.jingang")==0 || fz_times<1)
	{
		call_out("remove_effect_jingang", 1, me);
        return;
	}

    if(me->query_skill_mapped("force") != "longxiang-boruo")
	{
		call_out("remove_effect_jingang", 1, me);
		return;
	}

    if (!me->is_fighting() || !me->is_busy() ) 
	{
		call_out("jingang_trigger",reset_time,me,m_level,reset_time,fz_times);
		return;
	}
	if ((me->query("neili")<500)||(me->query("jingli")<500))
	{
	//	call_out("jingang_trigger",reset_time,me,m_level,reset_time,fz_times);
		call_out("remove_effect_jingang", 1, me);
		return;
	}

	cs_cnt=me->query("chushi/done");
	bet_cnt=me->query("betrayer");
	lx_f_lv=(int)me->query_skill("force");
	id_level=(int)me->query("level");
	target = offensive_target(me);
	t_f_lv=target->query_skill("force");
	//i_temp0=5 + m_level - id_level + cs_cnt*2 + bet_cnt*5;
	//i_temp1=t_f_lv*i_temp0/10;
	//i_temp2=random(lx_f_lv);
	//i_temp3=random(2+cs_cnt*2+bet_cnt*2);
    //message_vision(HIB HIW"原始数据分析："+NOR+t_f_lv+","+NOR+lx_f_lv+","+NOR+i_temp0+"。\n"NOR, me);
   // message_vision(HIB HIW"摆脱数据分析："+NOR+i_temp1+","+NOR+i_temp2+","+NOR+i_temp3+"。\n"NOR, me);
//	if ((i_temp2>i_temp1)||(i_temp3==1))
	if ((random(lx_f_lv)>t_f_lv*(5 + m_level - id_level + cs_cnt*2 + bet_cnt*5)/10) || (random(2+cs_cnt*2+bet_cnt*2)==1))
	{
        message_vision(HIW "$N" HIW "全身真气往返激荡，肌肤泛出淡金色，身上的奇经八脉一起运功，已经摆脱了束缚！\n" NOR, me);
        tell_object(me,HIR "你心神淡定，终于能够自由行动了！\n"NOR);
		me->start_busy(1+random(2));
	}
	else
	{
        message_vision(YEL "$N" YEL "全身真气激荡，企图摆脱控制，却始终无法运转如意！\n" NOR, me);
        tell_object(me,HIR "你心神不定，行动仍不灵便！\n"NOR);
	}
    me->add("neili", -100);
    me->add("jingli", -50);
	call_out("jingang_trigger",reset_time,me,m_level,reset_time,fz_times);
}

void remove_effect_jingang(object me, int amount)
{
		remove_call_out("jingang_trigger");
		remove_call_out("remove_effect_jingang");
        me->delete_temp("longxiang.jingang");
        me->delete_temp("active_force_buffer/longxiang.jingang");
        message_vision(HIB "$N的『金刚护体』运功完毕，身形也小了下来。\n"NOR, me);
/*		if (me->query_temp("longxiang.jingang"))
		{
	        me->delete_temp("longxiang.jingang");
		}
		if (me->query_temp("active_force_buffer/longxiang.jingang"))
		{
	        me->delete_temp("active_force_buffer/longxiang.jingang");
	        message_vision(HIB "$N的『金刚护体』运功完毕，身形也小了下来。\n"NOR, me);
		}
*/
		me->set_temp("jingang_lost_time",time());
}


