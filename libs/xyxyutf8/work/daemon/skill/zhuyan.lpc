// zhuyan.c
#include <ansi.h>
inherit SKILL;

void skill_improved(object me)
{
	int s;

	s = me->query_skill("zhuyan", 1);
        if( s%10==0 && (int)me->query("per") < s/5) 
        {
        	if( me->query("skill_mark/zhuyan_ad")<s )
        	{
        		me->set("skill_mark/zhuyan_ad",s);
			tell_object(me, HIW "由於你勤于驻颜，你的魅力提高了。\n" NOR);
			me->add("per", 2);
		}	
	}
}