// zhixin.c     之心庄，采日月之灵气以补气  
// Rewrote by iszt@pkuxkx, 2007-05-19
// 增加悟性

#include <ansi.h>
#include "linjizhuang.h";

void end_linji(object me, int pflv);
void remove_effect(object me, int count, int pflv);

int exert(object me, string arg)
{
        string linji = "之心庄";

		int pflv;
		string* ljz;
		ljz = linji_zhuang_count(me);
		pflv = (int)me->query("purefamily/level");
		if (pflv>0 && me->query("purefamily/family_name") != "峨嵋派")  pflv=0;

		if (buff_full(pflv, ljz))
			return notify_fail("你已经运行了"+show_buff(ljz)+"，无法再运行"+linji+"。\n");
//        if(me->query_temp("linji"))
//                return notify_fail("你正在运行"+me->query_temp("linji")+"，无法运行"+linji+"。\n");
        if(me->is_busy())
                return notify_fail("你现在正忙着呢。\n");
        if( me->is_fighting() )
                return notify_fail("战斗中运气练功，好象只有神仙才能做到。\n");
        if( me->query("class") != "bonze" && me->query("chushi/last_family")!="峨嵋派")
                return notify_fail("你尘心未灭，无法运行临济十二庄"+linji+"。\n");
        if((int)me->query("neili") < 500 )
                return notify_fail("你的真气不够。\n");
        if((int)me->query_skill("linji-zhuang",1) < 90)
                return notify_fail("你的临济十二庄修为太低，无法运行"+linji+"。\n");

//        me->set_temp("linji", linji);
        me->set_temp("linji_zhuang/"+linji, 1);
        me->start_busy(2);
        me->add("neili", - 150);
        tell_object(me,MAG"\n你微一凝神，运动之心两庄，去浊气出体外，收清气入心中，只觉灵台清明，领悟力有所增加。\n"NOR);
        call_out("end_linji", 2, me, pflv);
        return 1;
}

void end_linji(object me, int pflv)
{
	int count;
        message_vision(HIW"\n只见$N微一凝神，吞吐几口长气，一对眼眸灵动晶亮，神采弈弈。\n\n"NOR, me);
        me->add_temp("apply/intelligence", (int)me->query("int"));
        me->set_temp("active_force_buffer/linji-zhuang.zhixin/name", "之心庄");                        //buff名称
        if ( me->query_skill("literate", 1) > 80 )
			count = time() + me->query_skill("literate", 1)/4+21 ;              //持续时间
        else
			count = time() + me->query_skill("literate", 1)/2+1 ;               //持续时间
		me->set_temp("active_force_buffer/linji-zhuang.zhixin/last_time", count);
        me->set_temp("active_force_buffer/linji-zhuang.zhixin/effect1", "后天悟性+"+me->query("int")+"点");         //效果描述1   
		if (pflv>0)
		{
			me->set_temp("linjizhuang/zhixin_benefit", pflv);
			me->set_temp("active_force_buffer/linji-zhuang.zhixin/effect2", "提高学习领悟能力");         //效果描述2
		}
        call_out("remove_effect", 1, me, count, pflv);
        return;
}

void remove_effect(object me, int count, int pflv)
{
        if(!me || !me->query_temp("linji_zhuang/之心庄"))
                return;
        if( (me->is_fighting() && pflv<4) || count < time())
        {
                me->add_temp("apply/intelligence", -(int)me->query("int"));
                me->delete_temp("linji_zhuang/之心庄");
                me->delete_temp("linjizhuang/zhixin_benefit");
                me->delete_temp("active_force_buffer/linji-zhuang.zhixin");
                tell_object(me, HIR"你之心庄行功已久，体内已积过多浊气，又归于寻常。\n"NOR);
                return;
        }
        call_out("remove_effect", 1, me, count, pflv);
}
