#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        me->apply_condition("qx_snake_poison", duration - 1);

    if (! duration%5){
    me->receive_wound("qi", 50);
    me->receive_damage("jing", 50);
        message_vision(BLU"$N的身体发出诡异色的蓝光，混身经脉疼痛欲裂,扭结成怪异的肉筋.\n"NOR, this_player());
        tell_object(me, HIR "你中的七修蛇毒发作了！\n" NOR );
    }
    me->set_temp("die_for","中七修蛇毒");
    me->delete_temp("last_damage_from");
        if( duration < 1 ) return 0;
  return CND_CONTINUE;
}   
