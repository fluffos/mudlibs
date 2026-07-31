// fire_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;


string name() { return "fire_poison"; }

string chinese_name() { return "星宿毒焰"; }

int update_condition(object me, int duration)
{
int damage,damage1;
        if( duration < 1 ) return 0;

 message("vision", me->name() + HIR"一声惨嚎，全身竟燃起了" HIG "碧绿色"
               HIR "的火焰。\n"NOR, environment(me), me);
                tell_object(me, HIY "只觉全身灼热无比，身体上燃起的" HIG "碧焰"
               HIR "直焚心髓。！\n" NOR );
damage=me->query("qi")/8+10;
if (damage>8000) damage=8000;
        me->receive_wound("qi", damage);
        me->receive_damage("qi", damage);
        if (!me->is_busy())
        me->start_busy(3);
        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}
