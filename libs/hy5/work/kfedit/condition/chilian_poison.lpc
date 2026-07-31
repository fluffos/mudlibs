//Cracked by Kafei
//May 10th Modified by haowen to enforce poison
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
int damage,damage1;	
   if( !living(me) ) {
      message("vision", me->name() + "痛苦地哼了一声。\n", environment(me), me);
   }
   else {
      tell_object(me, HIR "忽然一阵晕旋使你急欲作呕，你中的赤炼掌毒发作了！\n" NOR );
if (environment(me) && me)
{
      message("vision", me->name() + "头重脚轻，身子突然晃了两晃。\n",
            environment(me), me);
}
   }
   damage= random(me->query("qi"))/5+1;
   damage1= random(me->query("jing"))/5+1;
      if (damage>15000) damage=15000;
      if (damage1>15000) damage1=15000;
      me->receive_damage("qi",damage);
      me->receive_damage("jing", damage1);
      me->apply_condition("chilian_poison", duration - 1);
	
   if( duration == 1) me->delete("poisoner");

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
