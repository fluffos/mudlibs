 //mimicat@fy4
#include <ansi.h> 
inherit F_SSERVER;
int perform(object me, object target)
{       
	string roomname;
        object room;
        int mana,extra;
        
        mana=me->query("neili");
        extra=me->query_skill("kwan-yin-spells",1);
        

        if(extra<120) return notify_fail("你的观音六字明咒不够熟练。\n");      
        if( (int)me->query("neili") < 100 )
                return notify_fail("你的法力不够。\n");                
        if (me->is_busy())
                return notify_fail("你现在正忙！\n");
        if( me->is_fighting() )
                return notify_fail("战斗中无法使用般若波罗密咒！\n");
        if( me->is_ghost())
                return notify_fail("鬼魂无法使用般若波罗密咒！\n");
        if( !(roomname=me->query_temp("timemark")))
                return notify_fail("你没有设定遁入点。\n");
        if( time()>me->query_temp("timemark_time"))
                return notify_fail("你设定的遁入点已经失效了。\n");
        if (domain_file(file_name(environment(me)))=="eren2")
                return notify_fail("此地不能使用般若波罗密咒。\n");
        if(environment(me)->query("no_fly")||environment(me)->query("no_death_penalty")
                || environment(me)->query("no_fly"))
                return notify_fail("此地不能使用般若波罗密咒。\n");  
         
        me->add("neili", -50);
        if( random(mana/5+extra*2) <100)      {
        message_vision( HIR "$N紧闭双眼，屈膝而坐，但是由于心怀杂念，什么都没有发生。\n" NOR, me);
                 return notify_fail("你的［般若波罗密咒］失败了。\n");      
                }
        message_vision( HIR "$N抛开杂念，口念佛号“般若波罗蜜”，突然之间，$N竟然消失不见踪影。\n" NOR, me);
        room = load_object(roomname);
        me->move(room);
        message( "vision", HIR "\n忽然天空一片佛光，"+me->query("name")+"驾云而至！\n\n" NOR,
                room, ({ me }) );
        return 1;
}   
