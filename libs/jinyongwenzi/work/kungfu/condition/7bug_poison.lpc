// 七虫软筋散.7bug_poison.c
// created by olives@SJ 5/1/2001
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
       if(duration>30)
	   duration = 30;
       message_vision(HIR"$N浑身酸麻，浑身抖个不停，好象一点用不上劲。\n"NOR, me);
       if(random(me->query_skill("force")*2+me->query("neili"))>me->query("neili"))
       {
				me->add("str",-1);
				me->add("dec/str",1);
       }
       me->add_busy(1);
       me->apply_condition("7bug_poison", --duration);
       if( duration < 1 )
       {
	   me->add("str",me->query("dec/str"));
	   me->delete("dec/str");
	   return 0;
       }
       return CND_CONTINUE;
}

string query_type(object me)
{
       return "poison";
}
