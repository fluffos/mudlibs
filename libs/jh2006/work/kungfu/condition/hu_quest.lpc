#include <ansi.h>
int update_condition(object me, int duration)
{                                        
        object bing;
        if (duration < 5) {
            tell_object(me, HBRED"突然一个元兵跳出来向你攻击！\n"NOR);
            tell_object(me, HBRED"想必发现了你的铁焰令，认为你是叛军了。\n"NOR);
            bing = new("/d/xiangyang/npc/bing");
            bing->move(environment(me));
            bing->kill_ob(me);
            bing->set_leader(me);
            return 0;        
        }
        me->apply_condition("hu_quest", duration - 1);
        return 1;
}

