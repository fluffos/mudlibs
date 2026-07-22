#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if( !living(me) ) {
                message("vision", me->name() + "喘着粗气，面色赤红。\n", environment(me), me);
        }
        else {
                tell_object(me, RED "你只觉浑身燥热难耐，似乎被放在火炉中一样，极为难受！\n" NOR );
                message("vision", me->name() + "突然面色一红，浑身一抖，自头部到手臂隐约可见斑斑红点，极为恐怖。\n",
                        environment(me), me);
        }
        me->receive_damage("qi", 25);
        me->receive_wound("jing", 20);
        me->set_temp("last_damage_from", "热毒发作");
        me->apply_condition("warm_poison", duration - 1);
        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}

string query_type(object me)
{
        return "poison";
}
