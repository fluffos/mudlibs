inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
    if( duration < 1 ) return 0;
    if( !living(me) ) 
    {
        message("vision", me->name() + "疼得哇哇大叫。\n", environment(me), me);
    }
    else 
    {
        tell_object(me, HIB "你只觉得浑身上下麻痒难耐，不自禁地用手乱挠起来！\n" NOR );
        message("vision", me->name() + "扭动着身子，双手在身上乱抓乱挠。\n",environment(me), me);
    }
	F_POISON->poison_eff(me,"bee_poison",(["qi":({1,25}),"jing":({1,10}),]),1); 
    me->apply_condition("bee_poison", duration - 1);
    return CND_CONTINUE;
}
