// rose_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	F_POISON->poison_eff(me,"rose_poison",(["qi":({0,10}),"jing":({1,20}),]),1); 
	me->apply_condition("rose_poison", duration - 1);
	tell_object(me, HIG "你中的" HIR "火玫瑰毒" HIG "发作了！\n" NOR );
	if( duration < 1 ) return 0;
	return 1;
}
