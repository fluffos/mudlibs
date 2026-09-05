//beiming.c

#include <ansi.h>

int exert(object me, object target)
{
        int skill, level;
        string msg;

        if (!me->is_fighting())
                return notify_fail("你必须在战斗中才能运用北冥神功。\n");

        if (me->query_temp("beiming"))
                return notify_fail("你已在运用北冥神功。\n");

        if (me->query_skill("beiming-shengong",1) < 200
            || me->query_skill("force",1) < 200)
                return notify_fail("以你目前的修为来看，还不足以运用北冥神功！\n");

        if (userp(me) && me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("你的内功不对，根本不能使出北冥神功。\n");   
               
        if (me->query("max_neili") < 1000)
                return notify_fail("你的内力修为不够运用北冥神功所需！\n");
                
        if (me->query("neili") < 500)
                return notify_fail("你的内力不够运用北冥神功所需！\n");

        skill = me->query_skill("force");
        level = 1;
        if ( (int)me->query_skill("beiming-shengong",1) > 600) level = 3;
        else if ( (int)me->query_skill("beiming-shengong",1) > 400) level = 2;
        else level = 1;
        
        message_vision(HIC "\n$N仰身长笑，运起北冥神功，丹田渐空！\n" NOR, me);
        me->add_temp("beiming", skill/10);
        call_out("checking", level, me, target, level);
        me->add("neili", -100);
        me->start_busy(1); 
        
        return 1;
}

void checking(object me, object target, int level)
{ 
        int skill = me->query_skill("force");        
        
        if ( !me ) return;
        else if (me->is_ghost() || !living(me)){
                me->delete_temp("beiming");
        }        
        else if (!me->is_fighting() || me->query("neili") < 500 || me->query_temp("beiming") <= 0 || !target) { 
                message_vision(MAG "\n$N运用北冥神功完毕，浑身恢复正常。\n" NOR, me);                
                me->delete_temp("beiming");
        }
        //命中率C+       
        else if( F_KUNGFU->hit_rate( skill, target->query_skill("force"), 7, me, target) &&
        	       target->query("neili") > skill/10) { 
                message_vision(HIR "\n$N随手按住$n大穴，$n一怔，内力源源流入$N丹田！\n" NOR, me, target);
                target->add("neili", -skill/10);
				if ( me->query("neili") < me->query("max_neili")*2 )
					me->add("neili", skill/10);
                if (!target->is_busy()) target->start_busy(level);
                me->add_temp("beiming",-1);                
                call_out("checking", level, me, target, level);
        }
        else call_out("checking", level, me, target, level);
        
        return;
}

