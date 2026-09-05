// zhixin.c     风云庄，风云际会（增加内力）  
// Rewrote by iszt@pkuxkx, 2007-05-19
// 战斗时增加身法

#include <ansi.h>
#include "linjizhuang.h"

void remove_effect(object me, int count, int pot);

int exert(object me, string arg)
{
        string linji = "风云庄";

		int pflv, count, pot;
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
        if( !me->is_fighting() )
                return notify_fail("你只能在战斗中运行"+linji+"。\n");
        if( me->query("class") != "bonze" && me->query("chushi/last_family")!="峨嵋派")
                return notify_fail("你尘心未灭，无法运行临济十二庄"+linji+"。\n");
        if((int)me->query("neili") < 1000 )
                return notify_fail("你的真气不够。\n");
        if((int)me->query_skill("linji-zhuang",1) < 60)
                return notify_fail("你的临济十二庄修为太低，无法运行"+linji+"。\n");

//        me->set_temp("linji", linji);
        me->set_temp("linji_zhuang/"+linji, 1);
        me->start_busy(2);

        tell_object(me,MAG"\n你暗运风云两庄，心思浮云飘空之悠闲缓慢，默想狂风荡地之迅速紧急，\n"
                "一股丹田热气分注四肢百骸，但觉身手敏捷了许多。\n"NOR, me);
        tell_room(environment(me), MAG"只见"+me->name()+"微闭双眼，身旁凝起一圈白雾，"
                "瞬息间一股旋风卷过，身形又复清晰。\n"NOR, ({ me }));
		pot = (int)me->query("dex") + ((pflv>=2)?pflv*5:0);
        me->add_temp("apply/dexerity", pot);
        me->add("neili", - 150);
        me->set_temp("active_force_buffer/linji-zhuang.fengyun/name", "风云庄");                        //buff名称
        if ( me->query_skill("dodge", 1) > 80 )
			count = time() + me->query_skill("dodge", 1)/4+21 ;              //持续时间
        else
        	count = time() + me->query_skill("dodge", 1)/2+1 ;               //持续时间
		me->set_temp("active_force_buffer/linji-zhuang.fengyun/last_time", count);
        me->set_temp("active_force_buffer/linji-zhuang.fengyun/effect1", "后天身法+"+pot+"点");         //效果描述1   
        call_out("remove_effect", 1, me, count, pot);
        return 1;
}

void remove_effect(object me, int count, int pot)
{
        if(!me || !me->query_temp("linji_zhuang/风云庄"))
                return;
        if(!me->is_fighting() || count < time())
        {
                me->add_temp("apply/dexerity", - pot);
//                me->delete_temp("linji");
				me->delete_temp("linji_zhuang/风云庄", 1);
                me->delete_temp("active_force_buffer/linji-zhuang.fengyun");
                tell_object(me, HIR"你风云庄行功已久，略觉步履沉重了一些。\n"NOR);
                return;
        }
        call_out("remove_effect", 1, me, count, pot);
}
