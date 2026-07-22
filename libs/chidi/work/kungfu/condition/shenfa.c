#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int wxtime)
{ 
    if( wxtime < 1 ) 
   {
      me->add("dex", -me->query("shenfadan"));
       me->delete("sfdan", 1);
      me->delete("shenfadan", me->query("shenfadan"));
     tell_object(me, "你脑袋一阵发蒙，原来你的临时身法没有了。\n");
     return 0;}
    if( wxtime > 0 )
     { int sec;      
      sec=(int)(wxtime*10);    
     tell_object(me, HIG"你的临时身法还有大概"+chinese_number(sec)+"秒！\n" NOR );         
    }    
    me->apply_condition("shenfa", wxtime - 1);
    if( wxtime < 1 ) 
     {
        me->add("dex", -me->query("shenfadan"));
       me->delete("sfdan", 1);
      me->delete("shenfadan", me->query("shenfadan"));
     tell_object(me, "你脑袋一阵发蒙，原来你的临时身法没有了。\n");
     return 0;}
    return CND_CONTINUE;
}

