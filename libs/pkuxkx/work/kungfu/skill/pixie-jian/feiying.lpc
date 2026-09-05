// feiying.c 葵花飞影术
// Jpei added for pixie-jian 04052008

#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="self" ;
}

void remove_effect(object me, int amount);

string* valid_weapon() 
{
    return ({ "all" });
}

int perform(object me, object target)
{
    int skill;

    if( !me->is_fighting() )
        return notify_fail("「葵花飞影术」只能在战斗中使用。\n");
    
    if( (int)me->query("neili") < 500  ) 
            return notify_fail("你的内力不够。\n");

    if( (int)me->query("jingli") < 200  ) 
            return notify_fail("你的精力不够。\n");

    if( (int)me->query_temp("feiying") ) 
            return notify_fail("你已经在运用「葵花飞影术」了。\n");

    if( (int)me->query_skill("pixie-jian", 1) < 120 )
            return notify_fail("你的辟邪剑法还没练成，无法使用「葵花飞影术」。\n");

    if( (int)me->query_dex() < 30  )
            return notify_fail("你的身法太低，不能使用「葵花飞影术」。\n");     

    skill = me->query_skill("dodge", "pixie-jian")/3;
    skill = skill + me->query_skill("pixie-jian");
    me->add("neili", -200);
    me->receive_damage("qi", 50);
    message_vision(
    MAG "只见$N眼中青光一闪，凭空飞升离地尺余，身形飘浮不定，就如影子一般。\n" NOR, me);
    tell_object(me, MAG "你默运葵花飞影术，内劲外泄，将身体凭空抬了起来。\n" NOR);

    me->add_temp("apply/dodge", skill);
    me->set_temp("feiying", 1);

    me->set_temp("active_buffer/family","日月神教");
    me->set_temp("active_buffer/pixie-jian.feiying/name", "葵花飞影术");                    //buff名称
    me->set_temp("active_buffer/pixie-jian.feiying/last_time", time() + skill );            //持续时间
    me->set_temp("active_buffer/pixie-jian.feiying/effect1", "轻功技能+"+skill+"级");       //效果描述1

    me->start_call_out( __FILE__, "remove_effect", skill, me, skill);

    me->start_busy(2);

    return 1;
}

void remove_effect(object me, int amount)
{
    if( !objectp(me) ) return;
    me->add_temp("apply/dodge", - amount);
    me->delete_temp("feiying");
    me->delete_temp("active_buffer/pixie-jian.feiying");
    if ( sizeof(me->query_temp("active_buffer"))==1 )
      me->delete_temp("active_buffer");
    tell_object(me, MAG "你一遍葵花飞影术已经使完，身法又恢复正常。\n" NOR);
}

