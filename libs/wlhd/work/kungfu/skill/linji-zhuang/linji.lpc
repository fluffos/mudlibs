#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

       if( target != me ) return notify_fail("你只能用临济十二庄提升自己的战斗力。\n");

        if( (int)me->query("neili") < 100 )     return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("wudu_pipip") ) return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("linji-zhuang",1)/3;

        me->add("force", -100);
 
        message_vision(
        HIW "$N运起临济十二庄之临济无边。头顶紫气蒸腾，面上顿时罩起一阵宝光。\n" NOR, me);

        me->add_temp("apply/armor", skill);
        me->add_temp("apply/unarmed", skill,1);
        me->add_temp("apply/attack", skill);
        me->set_temp("wudu_pipip", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/2 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
   if ( (int)me->query_temp("powerup") ) {
       me->add_temp("apply/unarmed", -amount*2);
       me->add_temp("apply/attack",-amount*2);
       me->add_temp("apply/armor",-amount*6);
       me->delete_temp("wudu_pipip");
      tell_object(me, "你的临济十二庄运行完毕，身体逐渐恢复正常。\n");}
}

