// zhizhu_poison.c
// by star  98.12.4
#include <ansi.h>

int update_condition(object me, int duration)
{
	if(me->query_temp("nopoison")) return 0;
	if( duration < 1 ) return 0;
    F_POISON->poison_eff(me,"zhizhu_poison",(["qi":({1,15+random(50)}),"jing":({0,15+random(40)}),"busy":({4,random(3)})]),1);    
	me->apply_condition("zhizhu_poison", duration - 1);
    //  if(environment(me)==find_object("/d/city/wumiao") 
    //  ||environment(me)==find_object("/d/city/wujiaochang"))
    //	me->apply_condition("zhizhu_poison", duration);
	tell_object(me, HIG "你中的蜘蛛毒发作了！\n" NOR );
	return 1;
}
