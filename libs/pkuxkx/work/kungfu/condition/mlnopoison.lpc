//避苗岭毒 zine Nov 1 2010
inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
   
   if( duration < 1 ) 
    {
       me->delete_temp("mlnopoison");
       return 0;
    }
   else
   {
       me->apply_condition("mlnopoison", duration - 1);
       return CND_CONTINUE;
   }
   
}
