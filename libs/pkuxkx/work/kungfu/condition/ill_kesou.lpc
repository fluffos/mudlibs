// ill_kesou.c

inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>


int update_condition(object me, int duration)
{
   object obj,ob,* inv;
   int i;

   inv=all_inventory(environment(me));

   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + "嘶哑着嗓子咳了两声，看来是病了。\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "你嘶哑着嗓子咳了两声，然后又连续咳了好一阵，看来是病了不轻！\n" NOR );
      message("vision", me->name() + "的身子弓着身子晃了两晃，嘶哑着嗓子咳了两声，看来是病了。\n",
            environment(me), me);
   }

   for(i=0;i<sizeof(inv);i++)
   { 
        obj=inv[i];
        if(!(!obj->is_character() || userp(obj)))
                continue;                        
        if(obj == me)
                continue;
          if(obj->query("max_neili")>500)
                continue;
		if(obj->query_condition("ill_kesou")>0)
				 continue;
		if(random(5)>3)
	   {        
		tell_object(obj, HIB "突然你感觉嗓子发紧，咳了两声，看来你被咳嗽传染了！\n" NOR );
		 obj->apply_condition("ill_kesou", 20);
		}
      }

   me->receive_wound("qi", 2);
   me->receive_damage("qi", 2);
   me->apply_condition("ill_kesou", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
