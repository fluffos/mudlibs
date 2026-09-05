inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
         message("vision", me->name() + "脸色青白，象是走火入魔了。\n", environment(me), me);
   }
   else {
      tell_object(me, MAG "你只觉得气血翻涌，再也控制不住经脉运行！\n你的气力和精力在一点点流逝...\n" NOR );
      message("vision", me->name() + "双眼发红，象是要杀几个人才舒服。\n",
            environment(me), me);
   }
	F_POISON->poison_eff(me,"qishang",(["qi":({0,250}),"jing":({0,60}),]),1); 
      me->apply_condition("qishang", duration - 1);
   return CND_CONTINUE;
}
