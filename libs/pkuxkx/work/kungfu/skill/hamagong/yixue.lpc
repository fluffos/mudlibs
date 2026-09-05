// reserve.c 蛤蟆功经脉倒转 免疫点穴类busy 
//by picewolf 

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me);

int exert(object me, object target)
{
        object weapon;
        
        string msg;
        int skill;    
        if( target != me ) 
                return notify_fail("你只能使自己的经脉倒转。\n");
        if( (int)me->query_skill("hamagong", 1) < 300 )
                return notify_fail("你的蛤蟆功不够娴熟，不会经脉倒转。\n");
        if( (int)me->query("neili") < 500  ) 
				        return notify_fail("你的内力不够。\n");
		    if( (int)me->query_temp("hmg_yixue") ) 
                return notify_fail("你的穴位已经移动了。\n");
		    if (time()-me->query("hmg_time")<60)
			          return notify_fail("经常逆转经脉是要死人的。\n");
 
        message_vision(HIB "$N暗运蛤蟆功，强使穴位移位片刻。\n"NOR, me);  
		    me->add("neili",-500);
		    me->set("hmg_time",time());
		    me->set_temp("hmg_yixue",1);
		    me->set_temp("apply/cant_busy_dianxue",1);
        me->set_temp("active_force_buffer/hamagong.yixue/name", "移穴");                              //buff名称
        me->set_temp("active_force_buffer/hamagong.yixue/last_time", time() + 20 );                   //持续时间
        me->set_temp("active_force_buffer/hamagong.yixue/effect1", "点穴免疫");                       //效果描述1
        me->start_call_out(__FILE__, "remove_effect", 20, me);

        if( me->is_fighting() )  me->start_busy(2);

        return 1;
}

void remove_effect(object me)
{    
        me->delete_temp("hmg_yixue");
		    me->delete_temp("apply/cant_busy_dianxue");
		    me->delete_temp("active_force_buffer/hamagong.yixue");
		    me->start_busy(1);
        tell_object(me, HIY "你忽觉内功一滞，身体穴位恢复如常。\n"NOR);
}