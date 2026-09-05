//罗汉醉卧

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
if(me->query("zuiquanpf")!=1||me->query("gender")!="男性") return notify_fail("你不会这一招!\n");

        limit = (me->query("con") + (int)me->query("max_neili") / 50) * 2;

        if( !target ) target = offensive_target(me);
			

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("罗汉醉酒只能对战斗中的对手使用。\n");

        if( me->query_temp("zuiquan"))
                return notify_fail("你正在施展「罗汉醉酒」。\n");
        if( objectp(me->query_temp("weapon")) )
                 return notify_fail("使用「罗汉醉酒」,必须空手!\n");




        if( (int)me->query("max_neili") < 100 || (int)me->query("neili") < 100 )
                return notify_fail("你的内力不足，无法使用罗汉醉酒。\n");

        if( !(int)me->query_condition("drunk"))
       {
            msg = HIC"$N故作醉态使出「罗汉醉酒」，身体跃起，向$n压过来!\n"NOR;
              coefficient=1;
             }
     else
        {
               msg = HIC"$N拳借酒势，使出「罗汉醉酒」，身体跃起，向$n压过来!\n" NOR;
          coefficient=2;
          }

        me->add("neili", - 100);
        skill=(int)me->query_skill("zui-quan", 1);
        message_vision(msg, me, target);
        buffs=skill/5 + (int)me->query_condition("drunk")/ limit * 10*coefficient;

        me->add_temp("apply/strength", buffs);
        me->add_temp("apply/dexerity", buffs);
        me->set_temp("zuiquan", 1);
        if ( !me->query_temp("active_buffer/family") )
          me->set_temp("active_buffer/family","公共武学");
        me->set_temp("active_buffer/zui-quan.lhzj/name", "罗汉醉酒");                      //buff名称
        me->set_temp("active_buffer/zui-quan.lhzj/last_time", time() + skill/10 );         //持续时间
        me->set_temp("active_buffer/zui-quan.lhzj/effect1", "后天膂力+"+buffs+"点");       //效果描述1
        me->set_temp("active_buffer/zui-quan.lhzj/effect2", "后天身法+"+buffs+"点");       //效果描述1
        call_out("remove_effect",skill/10 , me, buffs);

        return 1;
}

void remove_effect(object me, int amount)
{
	if (objectp(me))
	{
        me->add_temp("apply/strength", - amount);
        me->add_temp("apply/dexerity", - amount);
        me->delete_temp("zuiquan");
        me->delete_temp("active_buffer/zui-quan.lhzj");
	}
}
