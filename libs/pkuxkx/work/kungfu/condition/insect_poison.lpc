// iszt@pkuxkx, 2007-02-07
inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + "在昏迷中呻吟着。\n", environment(me), me);
   }
   else {
      tell_object(me, YEL "你身上突然一阵麻痒，接着便是万针攒刺般的疼痛！\n" NOR );
      message("vision", me->name() + "突然一皱眉，似是在忍受莫大的痛苦。\n",
            environment(me), me);
   }
	F_POISON->poison_eff(me,"insect_poison",(["qi":({0,25}),"jing":({1,30}),]),1); 
      me->apply_condition("insect_poison", duration - 1);
   return CND_CONTINUE;
}
