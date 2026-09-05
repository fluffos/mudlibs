// qimen.c by Jpei

#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me, object target, int count, int skill, int dex, int pflv);
protected void remove_target(object target,  int skill, int dex);

int exert(object me, object target)
{
        int skill,lev, ap, dp, dex, pflv;


        if( !target ) target = offensive_target(me);

        if( !objectp(target)
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("奇门迷阵只能对战斗中的对手使用。\n");
        if (me->query_temp("thd/mazed")) 
                return notify_fail("你正在陷入别人布的奇门迷阵中。\n");
        if( (int)me->query_skill("qimen-bagua",1) < 120 )
                return notify_fail("你的奇门八卦太低，不能布奇门迷阵。\n");                
        if( (int)me->query_skill("bihai-shengong",1) < 120 )
                return notify_fail("你的碧海神功修为不够，不能布奇门迷阵。\n");
        if( (int)me->query("neili") < 300  ) 
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("thd/maze") || (int)me->query_temp("active_buff/qimen-baguazhen.buzhen")) 
                return notify_fail(HIW"你已经布了一个奇门迷阵了。\n" NOR);
/*        if(target->is_busy() ||
        	 target->query_temp("thd/mazed") ) 
                return notify_fail("敌人已经忙不过来了，不要太欺负人！\n"); */
		if (time()<(int)me->query_temp("next_qimen"))
			return notify_fail("你才刚布置过一次奇门迷阵，还要过一段时间才能再次施展！\n");
				
		pflv = (int)me->query("purefamily/level");
		if (pflv>0 && me->query("purefamily/family_name") != "桃花岛")
			pflv = 0;
		
        skill = me->query_skill("qimen-bagua", 1) + me->query_skill("qimen-baguazhen", 1);
        lev=to_int(sqrt(to_float(me->query("level"))));
        lev=lev*2;
        if (me->query("level")>50)
        {
            lev=lev*3/2;
        }
        if (lev<1)
        {
            lev=1;
        }
        if (lev>35)
        {
            lev=35;
        }
        if (me->query("exp/taohuanewbie")<50000)//taohua newbie job impact By Zine
        {
            lev=0;
        }
        if (wizardp(me))
        {
            tell_object(me,"lev:"+lev+"。\n");
        }
        me->add("neili", -200);
        ap = (int)(me->query_int() + me->query_dex() + skill/10);
        dp = (int)(target->query_int() + target->query_dex() + target->query_skill("qimen-bagua", 1)/20);

        message_vision(HIY"$N突然跃起，左拍一掌，右挑一腿，将周围的石块、树枝移动了位置！\n" NOR, me, target);

        me->add_temp("apply/defense", 10+skill/15);
        me->set_temp("thd/maze", skill/5);
        
        me->set_temp("active_force_buffer/bihai-shengong.qimen/name", "奇门迷阵");                              //buff名称
        me->set_temp("active_force_buffer/bihai-shengong.qimen/last_time", time() + skill/20 );                 //持续时间
        me->set_temp("active_force_buffer/bihai-shengong.qimen/effect1", "防御躲闪+"+(10+skill/15)+"级");       //效果描述1   
		if (pflv>0)
		{
			me->add_temp("apply/kf_anti_hr", pflv);
			me->set_temp("exert_qimen_kf_hit", pflv);
			me->set_temp("active_force_buffer/bihai-shengong.qimen/effect2", "技能命中抗性+"+pflv+"级");       //效果描述1   
		}
        
        if( F_KUNGFU->hit_rate( ap, dp, 9, me, target) ) {
                message_vision(HIR"$n陷入迷阵中，登时手足无措。\n" NOR, me, target);
                target->set_temp("thd/dexerity", target->query_temp("apply/dexerity"));
                target->set_temp("thd/dodge", target->query_temp("apply/dodge"));
                target->set_temp("active_debuff/bihai-shengong.qimen/name", "奇门迷阵");                              //buff名称
                target->set_temp("active_debuff/bihai-shengong.qimen/last_time", time() + skill/20 );                 //持续时间
                if (skill/25+lev>=(int)target->query_dex())
                {
                    dex=target->query_dex();
                    target->add_temp("apply/dexerity", -target->query_dex());
                    target->set_temp("active_debuff/bihai-shengong.qimen/effect1", "后天身法-"+(target->query_dex())+"点");       //效果描述1
                }
                else
                {
                    dex=skill/25+lev;
                    target->add_temp("apply/dexerity", -(skill/25+lev));
                    target->set_temp("active_debuff/bihai-shengong.qimen/effect1", "后天身法-"+(skill/25+lev)+"点");  //效果描述1
                }
                target->add_temp("apply/damage", -(skill/3));
                target->add_temp("apply/dodge", -(skill/3));
                target->set_temp("thd/mazed", 1);
				if (target->query_busy()<10)
					F_KUNGFU->hit_busy( "confuse", 10+random(2), target );
                target->set_temp("active_debuff/bihai-shengong.qimen/effect2", "攻击伤害-"+(skill/3)+"点");      //效果描述2
                target->set_temp("active_debuff/bihai-shengong.qimen/effect3", "轻功技能-"+(skill/3)+"点");      //效果描述3
                me->set_temp("thd/maze_target", target);
        }
		else
			message_vision(HIY"$n见机不妙，急忙后退数步，在迷阵之外游走寻找机会。\n" NOR, me, target);
        me->start_busy(random(2));
        call_out("remove_effect", 1, me, target, skill/20, skill, dex, pflv);
        return 1;
}

void remove_effect(object me, object target, int count, int skill, int dex, int pflv)
{
		int i;
        if (objectp(me) && me->query_temp("thd/maze")){
                if (count-- > 0 && me->is_fighting(target)) {
					if (pflv>=4 && me->query_busy()>5 && me->query("safari_skill/thd_buzhen") && random(pflv-2))
					{
						message_vision( HIM"\n$N的身影一晃，轻轻巧巧地遁入迷阵，解除了被困状态。\n" NOR,me);
						me->start_busy(0);
						me->add_temp("qimen_removebusy", 1);
						count -= ( 5 + random(6) );
					}
                    call_out("remove_effect", 1, me, target, count, skill, dex, pflv);
                    return;
                }
                me->add_temp("apply/defense", - (10+skill/15));
                me->delete_temp("thd/maze");
                me->delete_temp("active_force_buffer/bihai-shengong.qimen");
				if ( i = (int)me->query_temp("exert_qimen_kf_hit") )
				{
					me->add_temp("apply/kf_anti_hr", -i);
					me->delete_temp("exert_qimen_kf_hit");
				}
                
                if (!target || target->is_ghost(1)) 
                {
                	remove_target(target, skill, dex);
                	return;
                }
                
                me->delete_temp("thd/maze");
                me->delete_temp("thd/maze_target");
				if ( i = (int)me->query_temp("qimen_removebusy"))
				{
					me->set_temp("next_qimen",time()+i*10);
					me->delete_temp("qimen_removebusy");
				}
                if (target && me->is_fighting(target)) {
                        tell_object(me, HIY "你布的迷阵已经被" + target->name() + HIY "破坏了。\n" NOR);
                        if (userp(target) && living(target))
                                tell_object(target, HIY + me->name() +  HIY "对你布的迷阵已经被你识破了。\n" NOR);
                }
                else {
                        tell_object(me, HIY "你布下的迷阵逐渐失效了。\n" NOR);
                }
        }

        remove_target(target, skill, dex);
}

protected void remove_target(object target,  int skill, int dex)
{
    if (!objectp(target) ||
    	  !target->query_temp("thd/mazed") )
    	return;   
    
    target->delete_temp("thd/mazed");
    target->add_temp("apply/dexerity", dex);
    target->add_temp("apply/dodge", skill/3);
    target->delete_temp("thd/dexerity");
    target->delete_temp("thd/dodge");
    target->add_temp("apply/damage", skill/3);
    target->delete_temp("active_debuff/bihai-shengong.qimen");
}