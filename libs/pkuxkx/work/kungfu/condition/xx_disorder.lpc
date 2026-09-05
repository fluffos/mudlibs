
inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
   int pc, pflv, add;
   if( duration < 1 ) 
    {
       pc = (int)me->query_temp("xx_disorder/percent");
	   if (pc>0) 
	   {
	     if ((int)me->query_temp("apply/disorder_percent")<pc)
		   me->set_temp("apply/disorder_percent", 0);
	     else 
		   me->add_temp("apply/disorder_percent", -pc);
         message_vision(HIC"$N长长吐出一口浊气，将体内混乱的内息收拢归元！\n"NOR,me);
	   }
	   me->delete_temp("xx_disorder");
       return 0;
    }
   else
   {
       if (!me->query_temp("xx_disorder/percent"))
	   {
			pflv = (int)me->query_temp("xx_disorder/pflv");
			pc = 10 + (pflv>=4?(pflv*20-30):(pflv*10));
			me->set_temp("xx_disorder/percent", pc);
			me->add_temp("apply/disorder_percent", pc);
			if (pflv<=0) duration = 1;
			tell_object(me, HIM "突然你的丹田中一阵剧痛，体内的内息乱成一团，不受控制地四处游走！\n" NOR );
			message("vision", HIM + me->name() + HIM "突然捂住小腹痛哼一声，脸上涌起一阵异样的潮红色。\n" NOR,
				environment(me), me);
	   }
	   else {
			pflv = (int)me->query_temp("xx_disorder/pflv");
			pc = 10 + (pflv>=4?(pflv*20-30):(pflv*10));
			pc -= (int)me->query_temp("xx_disorder/percent");
			if (pc>0)
			{
				me->add_temp("xx_disorder/percent", pc);
				me->add_temp("apply/disorder_percent", pc);
			}
			tell_object(me, HIM "你的丹田传来阵阵剧痛，体内不受控制的内息在持续四处游走！\n" NOR );
			message("vision", HIM + me->name() + HIM "捂着小腹痛哼一声，脸上涌起一阵异样的潮红色。\n" NOR,
				environment(me), me);
	   }
       me->apply_condition("xx_disorder", duration - 1);
       return CND_CONTINUE;
   }
   
}
