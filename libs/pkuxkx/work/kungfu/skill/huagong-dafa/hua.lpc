//hua.c

#include <ansi.h>

int exert(object me, object target)
{
        int skill, level;
        string msg;

        if (!me->is_fighting())
                return notify_fail("你必须在战斗中才能运用化字大决。\n");

        if (me->query_temp("hua"))
                return notify_fail("你已在运用化字大决。\n");

        if (me->query_skill("huagong-dafa",1) < 180
            || me->query_skill("force",1) < 180
            || me->query_skill("poison",1) < 180 )
                return notify_fail("以你目前的修为来看，还不足以运用化字大决！\n");

        if (userp(me) && me->query_skill_mapped("force") != "huagong-dafa")
                return notify_fail("你的内功不对，根本不能使出化字大决。\n");   
               
        if (me->query("max_neili") < 1000)
                return notify_fail("你的内力修为不够运用化字大决所需！\n");
                
        if (me->query("neili") < 500)
                return notify_fail("你的内力不够运用化字大决所需！\n");

        skill = me->query_skill("force") + me->query_skill("poison", 1);
        level = 1;
        if ( (int)me->query_skill("poison",1) > 400) level = 3;
        else if ( (int)me->query_skill("poison",1) > 300) level = 2;
        else level = 1;
        
        message_vision(HIB "\n$N嘿嘿一笑，运起化工大法化字大决，浑身泛起一团黑气！\n" NOR, me);
        me->add_temp("hua", skill/10);
        call_out("checking", level, me, target, level);
        me->add("neili", -100);
        me->start_busy(1); 
        
        return 1;
}

void checking(object me, object target, int level)
{ 
        int skill = me->query_skill("force") + me->query_skill("poison", 1);        
        
        if ( !me ) return;
        else if (me->is_ghost() || !living(me)){
                me->delete_temp("hua");
        }        
        else if (!me->is_fighting() || me->query("neili") < 500 || me->query_temp("hua") <= 0 ) { 
                message_vision(HIB "\n$N散去黑气，浑身恢复正常。\n" NOR, me);                
                me->delete_temp("hua");
        }       // icer 加自己busy的判断，否则即使自己busy依然能出招
        else if( random(skill) > target->query_skill("force")/2 && target->query("neili") > skill/10 && !me->is_busy()){ 
                message_vision(HIB "\n$N伸手一探，一团黑气扫向$n！只见$n身子一怔，内力损失不少！\n" NOR, me, target);
                target->add("neili", -skill/10);
                if (!target->is_busy()) target->start_busy(level);
                me->add_temp("hua",-1);                
                call_out("checking", level, me, target, level);
        }        
        else call_out("checking", level, me, target, level);
        
        return;
}

