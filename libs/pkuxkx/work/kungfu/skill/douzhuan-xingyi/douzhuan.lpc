//『斗转星移』
//create by yhzzyahoo 2016/10/19
#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="self" ;
}

int perform(object me)
{
        int dur,cd_time;
		int sk_lv1,sk_lv2;

       if ( !me->is_fighting() ) return notify_fail("你只能在战斗中使用『斗转星移』。");

        if ( !me->query("safari_skill/mr_douzhuan") ) return 0;

		if(me->query("family/family_name")!="姑苏慕容") 
			return notify_fail("非姑苏慕容弟子无法使用『斗转星移』。\n");
        if ( time()< me->query_temp("no_zhen-douzhuan"))
                return notify_fail("你刚刚使用过『斗转星移』，气息还未平复。\n");

		sk_lv1 = me->query_skill("douzhuan-xingyi", 1);
		sk_lv2 = me->query_skill("shenyuan-gong", 1);
	

        if( (int)me->query_dex() < 40)
                return notify_fail("你的身法不够，无法施展『斗转星移』。\n");

        if( sk_lv1 < 400 )
                return notify_fail("你的斗转星移不够娴熟，不会使用『斗转星移』。\n");

        if( sk_lv2 < 400 )
                return notify_fail("你的神元功等级不够，不能使用『斗转星移』。\n");


        if( (int)me->query("max_neili") < 2000 || (int)me->query("neili") < 1000 )
                return notify_fail("你的内力不足，无法使用『斗转星移』。\n");

        message_vision(HIW"\n$N双手连摆，身形轻移，显得神秘莫测！\n" NOR,me);
        me->add("neili", -(200+(int)(sk_lv1/5)));
		if (sk_lv1>3000)
		{
			cd_time = 60;
		}
		else
		{
			cd_time = 120-sk_lv1/50;
		}
		if (me->query("chushi/done"))
		{
			cd_time *= 2;
		}
		if (me->query("betrayer"))
		{
			cd_time *= 2;
		}   
		me->set_temp("no_zhen-douzhuan",time()+cd_time);
		dur=(int)((sk_lv1-100)/300);
		if (me->query("dex")>40)
		{
			dur+=1;
		}
        me->set_temp("zhen-douzhuan",dur);//各类效果判定数值
   
		dur=(int)(sk_lv2/80)+10;
		if (dur>30)
		{
			dur = 30;
		}
		if (me->query("chushi/done"))
		{
			dur /= 2;
		}
		if (me->query("betrayer"))
		{
			dur /= 2;
		}
  
        me->set_temp("active_buffer/douzhuan-xingyi.douzhuan/name", "斗转星移");                  //buff名称
        me->set_temp("active_buffer/douzhuan-xingyi.douzhuan/last_time", time() + dur);               //持续时间
        me->set_temp("active_buffer/douzhuan-xingyi.douzhuan/effect1", "反弹偏移技能特效");             //效果描述1
        call_out("remove_effect", dur, me );
        return 1;
}

protected int remove_effect(object me)
{
        int skill;
        if (!me)	return 0;
		if (me->query_temp("zhen-douzhuan"))
		{
			me->delete_temp("zhen-douzhuan");
			me->delete_temp("active_buffer/douzhuan-xingyi.douzhuan");
		  if ( sizeof(me->query_temp("active_buffer"))==1 )
				me->delete_temp("active_buffer");
			if(living(me) && !me->is_ghost())
			  message_vision(GRN"$N一口气没有接上，身形慢了下来。\n"NOR, me);
		}

        return 0;
}
