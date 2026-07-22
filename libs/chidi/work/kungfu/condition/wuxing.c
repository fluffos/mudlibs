#include <ansi.h>
#define PERIOD  3600
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int wxtime)
{ 
    if( wxtime < 1 ) 
   {
      me->add("int", -me->query("wuxingdan"));
       me->delete("wxdan", 1);
      me->delete("wuxingdan", me->query("wuxingdan"));
     tell_object(me, "你脑袋一阵发蒙，原来你的临时悟性没有了1。\n");
     return 0;}

    if( wxtime > 0 )
     { int min;
      
      min=(int)(wxtime/6);
    
     tell_object(me, HIG"你的临时悟性还有大概"+chinese_number(min)+"分钟！\n" NOR );
         
    }    
    me->apply_condition("wuxing", wxtime - 1);
    if( wxtime < 1 ) 
     {
       me->add("int", -me->query("wuxingdan"));
     me->delete("wxdan", 1);
     me->delete("wuxingdan", me->query("wuxingdan"));
     tell_object(me, "你脑袋一阵发蒙，原来你的临时悟性没有了。\n");
     return 0;}
    return CND_CONTINUE;
}

