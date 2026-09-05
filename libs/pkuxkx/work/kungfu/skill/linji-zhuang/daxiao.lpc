// daxiao.c     大小庄，大小随我心（增加内功）
// Modified by iszt@pkuxkx, 2007-04-03, added set_temp("linji")
// Rewrote by iszt@pkuxkx, 2007-05-19
// 平时疗伤

#include <ansi.h>
#include "linjizhuang.h"

int exert(object me, object target)
{
        string linji = "大小庄";
        object *em1, *em2;
        int team,skill;

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
	      
	      if( !objectp(target) || target== me )
		            return notify_fail( linji+"只能给他人疗伤！\n" );

        if( !target->is_character() )
                return notify_fail("看清楚一点，那并不是生物。\n");
        
        if( target->is_fighting() != me->is_fighting() )
        	      return notify_fail("你和被疗伤的人要么共同战斗，要么都处于空闲状态才能使用"+linji+"为对方疗伤。\n");
        
        if ( target->is_fighting() &&
        	   me->is_fighting() )
        {
          em1=target->query_enemy();
          em2=me->query_enemy();
          team=0;
          for(int lp=0;lp<sizeof(em1);lp++)
          {
          	if ( member_array(em1[lp],em2)>=0 )
          	{
          		team=1;
          		break;
          	}
          }
          
          if ( !team )
          	return notify_fail("你和被疗伤的人要么共同战斗，要么都处于空闲状态才能使用"+linji+"为对方疗伤。\n");
        }
                
        if( me->query("class") != "bonze" && me->query("chushi/last_family")!="峨嵋派")
                return notify_fail("你尘心未灭，无法运行临济十二庄"+linji+"。\n");
                
        if(!( target->query("eff_jing") < target->query("max_jing")
           || target->query("eff_qi") < target->query("max_qi")) )
                return notify_fail(target->name()+"没有受伤，不必运功疗伤。\n");
                
        if((int)me->query("neili") < 200 )
                return notify_fail("你的真气不够。\n");
                
        if((int)me->query_skill("linji-zhuang",1) < 30)
                return notify_fail("你的临济十二庄修为太低，无法运行"+linji+"。\n");

        skill = me->query_skill("force", "linji-zhuang")/2;
        skill = skill + random(skill);
        if (me->query_skill("emei-jiuyanggong",1)>11)
        {
			if (me->is_realuser()&&me->query("chushi/done")==0)
			{
		        skill=skill*11/10;
			}
			else
			{
				skill = skill * 14/10;
			}

          write(HIR"关键时分，峨嵋九阳功也发挥的淋漓尽致......\n"NOR);
        }
//        me->set_temp("linji", linji);
        me->set_temp("linji_zhuang/"+linji, 1);
		if (pflv>=3) skill = skill * pflv / 2;
        target->receive_curing("jing", skill);
        target->receive_curing("qi", skill);
        target->receive_heal("jing", skill*5);
        target->receive_heal("qi", skill*5);
        me->add("neili",-150);
        me->start_busy(2);
		
		if (me->is_fighting())
			message_vision(HIY"\n$N运起临济十二庄真气，临空嗤嗤连点$n身上数处大穴，伤口流血立止。\n"NOR, me, target);
		else
			message_vision(HIY"\n$N盘膝坐下，运行临济十二庄"+linji+"开始给$n疗伤。\n"NOR, me, target);
        call_out("end", 10, me, linji);

        return 1;
}

int end(object me, string linji)
{
	      if ( !objectp(me) )
	      	return 1;
        message_vision(HIG"\n$N长吸了一口气，大小庄运行完毕，真气回归丹田。\n"NOR,me);
        me->delete_temp("linji_zhuang/"+linji, 1);
        return 1;
}
