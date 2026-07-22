#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;  
int update_condition(object me,int duration)
{
   if ( duration < 1 ) return 0;

   if ( duration == 9 )
     message_vision(HIM"$N忽然间微微一笑，神情颇为诡秘，"
             +"似乎有点不怀好意。\n"NOR,me);
   else if (duration == 6 )
     message_vision(HIM"$N突然间微微一笑，神色古怪，不知"
            +"又在打什么坏主意。\n"NOR,me);    
   else if (duration <= 3 )
   {
     message_vision(HIM"$N忽然张口哈哈一笑，可是又笑不出"
            +"来，脸上僵硬的笑容诡秘之极。\n" NOR,me);

     me->apply_condition("xys_poison",0);
     message("channel:rumor", HIM"【江湖传闻】据说"+me->query("name")
            +"被人用三笑逍遥散毒死了。\n"NOR,users());
     me->die();
     return 0;
   }
   me->apply_condition("xys_poison", duration - 1);
   return CND_CONTINUE;      
}



