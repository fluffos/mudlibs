// need_energy.c

#include <condition.h>
#include <ansi.h>

int dispel() { return 0; }

int update_condition(object me, int duration)
{
        object ob;
        
        if (me->query("food") > 0 && me->query("water") > 0)
                return 0;

        if (! environment(me) ||
            environment(me)->is_chat_room())
                return CND_CONTINUE;

        if (duration == 4)
        {
                if (objectp(ob = find_player(me->query("owner"))))
                        tell_object(ob, HIR "你的神兽(" + me->query("name") + HIR + ")快要饿死了！\n" NOR); 
                        
                message_vision(HIY "$N" HIY "看起来又饥又渴，已经疲惫不堪。\n" NOR, me);
        }
        else
        if (duration == 7)
        {
                if (objectp(ob = find_player(me->query("owner"))))
                        tell_object(ob, HIR "你的神兽(" + me->query("name") + HIR + ")快要饿死了！\n" NOR); 
                                        
                message_vision(HIY "$N" HIY "看起来又饥又渴，处于死亡的边缘。\n" NOR, me);
        }
        else
        if (duration >= 21)
        {
                if (objectp(ob = find_player(me->query("owner"))))
                        tell_object(ob, HIY "你的神兽(" + me->query("name") + HIY + ")已经饿死了！\n" NOR); 
                
                me->receive_damage("qi", 0);
                me->unconcious();
                return 0;
        } 
                                              
        me->apply_condition("need_energy", duration + 1);
        return CND_CONTINUE;
}

