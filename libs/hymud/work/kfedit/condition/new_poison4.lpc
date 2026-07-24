// corpse_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;


string name() { return "new_poison4"; }

string chinese_name() { return "冰霜伤害"; }

int update_condition(object me, int duration)
{
int damage;
        if( duration < 1 ) return 0;

 message("vision", me->name() + BLU"身上冰霜一闪,冰霜伤害发作了。\n"NOR, environment(me), me);
tell_object(me, BLU"你身上冰霜一闪,冰霜伤害发作了。\n" NOR );
tell_object(me, BLU"你身上冰霜一闪,你被冰霜冻住了。\n" NOR );
if (!me->is_busy()) me->start_busy(6);
me->set_temp("apply/attack",-100);
tell_object(me, BLU"你被冰的全身麻痹,进攻慢了很多！\n" NOR );





        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}
