 //by xiaolang
 //mimicat@fy4
#include <ansi.h> 
inherit F_SSERVER;
int perform(object me, object target)
{       
        object room;
        int marktime,extra;
        extra=me->query_skill("kwan-yin-spells",1);
        

        if(extra<120) return notify_fail("你的观音六字明咒不够熟练。\n");      
        if( (int)me->query("neili") < 100 )
                return notify_fail("你的法力不够。\n");                
        if (me->is_busy())
                return notify_fail("你现在正忙！\n");
        if( me->is_fighting() )
                return notify_fail("战斗中无法使用神游太虚！\n");
        if( me->is_ghost())
                return notify_fail("鬼魂无法使用神游太虚！\n");
        if (domain_file(file_name(environment(me)))=="eren2")
                return notify_fail("此地不能使用时空转换。\n");
        if(environment(me)->query("no_fly")||environment(me)->query("no_death_penalty")
                || environment(me)->query("no_fly"))
                return notify_fail("此地不能使用时空转换。\n");  

if( !environment(me)->query("no_fight"))
return notify_fail("只有安全地点才能使用时空转换。\n");  

if(environment(me)->query("short")==BLU"山洞"NOR
       ||environment(me)->query("short")==WHT"钟乳石洞"NOR
       ||environment(me)->query("short")==YEL"岩洞"NOR
       ||environment(me)->query("short")==RED"熔岩洞"NOR
       ||environment(me)->query("short")==CYN"石洞"NOR
       ||environment(me)->query("magicroom"))
return notify_fail("只有安全地点才能使用时空转换。\n");           
        me->add("neili", -50);
        me->start_busy(1);
        message_vision( HIR "$N轻闭双眼，双手合一，口呼佛号：“遁！”，一道佛光从$N掌间飞出，遁入地下。\n" NOR, me);
        room = environment(me);
        marktime=1500+random((me->query_skill("kwan-yin-spells",1)-80)*100);
        me->set_temp("timemark",base_name(room));
        me->set_temp("timemark_time",time()+marktime);
        return 1;
}   
