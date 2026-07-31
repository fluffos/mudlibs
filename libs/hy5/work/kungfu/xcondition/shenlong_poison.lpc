#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

string name() { return "shenlong_poison"; }

string chinese_name() { return "神龙豹筋散"; }

int update_condition(object me, int duration)
{
        if( duration < 1 ) return 0;

 message("vision", me->name() + HIY"胸中发痛，全身不住的颤抖，把吃的东西全部吐出来了。\n"NOR, environment(me), me);
                tell_object(me, HIY "胸中发痛，全身不住的颤抖，把吃的东西全部吐出来了!看来是神龙豹筋散发作了！\n" NOR );

        me->set("food",0);
        me->set("water",0);
        if (!me->is_busy())
        me->start_busy(8);
        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}
