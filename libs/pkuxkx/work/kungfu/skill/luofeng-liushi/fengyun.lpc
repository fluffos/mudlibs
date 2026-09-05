// fengyun.c

#include <ansi.h>
inherit F_SSERVER;

string* valid_weapon() 
{
    return ({ "all" });
}

int perform(object me, object target)
{
        string msg;
        int time;

        if( !target ) target = offensive_target(me);
        	
        time = me->query_skill("luofeng-liushi") / 40;
        if(time >= 8) time = 8;

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『风卷残云』只能对战斗中的对手使用。\n");
        if( target->is_busy() )
                return notify_fail(target->name() + "已经被你迷惑了，放心攻击吧。ⅵ\n");                
        if ((int)me->query_skill("luofeng-liushi",1) < 80)
                return notify_fail("你的落风六式不够娴熟，不会使用『风卷残云』。\n");
        if( (int)me->query("neili") < 400  ) 
                return notify_fail("你的内力不够。\n");
                
        msg =HIY"$N右腿在地上一卷,扬起一片沙尘，欲将$n笼罩其中!\n\n" NOR; 

        me->start_busy(random(3));
        
        if( random(me->query("combat_exp")) > (target->query("combat_exp")/2)) 
        {
                msg += HIM "$p在漫天沙尘中什么也看不见，不禁有些手忙脚乱！\n\n" NOR;

           target->start_busy( 2 + time );
        } 
        else 
        {
                msg += HIC"$p运起轻功，跳出满天沙尘，似乎根本没有受到影响。$P心中一惊，竟有些乱了方寸。\n\n" NOR;
                
                me->start_busy(3);
        }
        
        message_vision(msg, me, target);

        return 1;
}