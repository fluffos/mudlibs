//贵妃醉酒

#include <ansi.h>

inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}


int perform(object me, object target)
{
        string msg;
	int skill,limit,buffs;
    int coefficient;
if(me->query("zuiquanpf")!=1||me->query("gender")=="男性") return notify_fail("你不会这一招!\n");

        limit = (me->query("con") + (int)me->query("max_neili") / 50) * 2;

        if( !target ) target = offensive_target(me);
			

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("贵妃醉酒只能对战斗中的对手使用。\n");

        if( me->query_temp("zuiquan"))
                return notify_fail("你正在施展「贵妃醉酒」。\n");
        if( objectp(me->query_temp("weapon")) )
                 return notify_fail("使用「贵妃醉酒」,必须空手!\n");

        if( (int)me->query("max_neili") < 50 || (int)me->query("neili") < 50 )
                return notify_fail("你的内力不足，无法使用贵妃醉酒。\n");

        if( !(int)me->query_condition("drunk"))
       {
            msg = HIC"$N故作醉态，眼中却是春波流动，使出「贵妃醉酒」，手中却使出‘捻花指’向$n面门弹去!\n"NOR;
              coefficient=1;
             }
     else
        {
               msg = MAG"$N半醉半醒，面带桃花，不经意间就使出「贵妃醉酒」，手中却使出‘捻花指’向$n面门弹去!\n" NOR;
          coefficient=2;
          }

        me->add("neili", - 40);
        skill=(int)me->query_skill("zui-quan", 1);
        message_vision(msg, me, target);
        buffs=skill/6 + (int)me->query_condition("drunk")/ limit * 10*coefficient;

        me->add_temp("apply/strength", buffs);
        me->add_temp("apply/dexerity", buffs);
        if ( !me->query_temp("active_buffer/family") )
          me->set_temp("active_buffer/family","公共武学");
        me->set_temp("active_buffer/zui-quan.gfzj/name", "贵妃醉酒");                      //buff名称
        me->set_temp("active_buffer/zui-quan.gfzj/last_time", time() + skill/10 );         //持续时间
        me->set_temp("active_buffer/zui-quan.gfzj/effect1", "后天膂力+"+buffs+"点");       //效果描述1
        me->set_temp("active_buffer/zui-quan.gfzj/effect2", "后天身法+"+buffs+"点");       //效果描述1
        
        me->set_temp("zuiquan", 1);
//        remove_call_out("remove_effect");
        call_out("remove_effect",skill/10 , me, buffs);
  if(target->query("gender")=="男性"&&
     F_KUNGFU->hit_rate( me->query("combat_exp"), (int)target->query("combat_exp"), 9, me, target) )
  {
   message_vision(HIY"$n看到$N的醉态不禁出神,一不留神,却被$N的捻花指连中几招!\n"NOR,me,target);
   F_KUNGFU->hit_wound("qi", skill/6*coefficient, skill/10*coefficient, me, target);
  }

        return 1;
}

void remove_effect(object me, int amount)
{
        if ( !objectp(me) )
        	return;
        me->add_temp("apply/strength", - amount);
        me->add_temp("apply/dexerity", - amount);
        me->delete_temp("active_buffer/zui-quan.gfzj");
        me->delete_temp("zuiquan");
}
