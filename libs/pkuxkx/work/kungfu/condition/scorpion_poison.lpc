// scorpion_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	F_POISON->poison_eff(me,"scorpion_poison",(["qi":({0,10}),"jing":({1,10}),]),1); 
    me->apply_condition("scorpion_poison", duration - 1);
    tell_object(me, HIG "你感到呼吸困难，四肢渐渐肿了起来。\n" NOR );
	if( duration < 1 ) return 0;
	return 1;
}
