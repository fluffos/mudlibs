// powerup.c 九阳神功加力

#include <ansi.h>
#include "/kungfu/skill/shenghuo-lingfa/shenghuo.h"
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill,amount;

        if( target != me )
                return notify_fail("你只能使用光明圣火功来提升自己的战斗力。\n");

        if( (int)me->query("neili") < 100  )
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") )
              return notify_fail("你已经在运功中了。\n");
        if ((int)me->query_skill("guangming-shenghuogong", 1) < 40)
                return notify_fail("你的光明圣火功等级不够，不能提升战斗力。\n");
		
        skill = me->query_skill("force");
        me->add("neili", -100);
        me->receive_damage("qi", 0);
		if (custom_color(me)!=NOR)
		message_vision(custom_color(me)+"$N"+custom_color(me)+"曼声吟其光明圣火歌诀，真气从丹田处绵然不绝地流入四肢百骸。\n" NOR, me);
		else
		message_vision(HIR "$N曼声吟其光明圣火歌诀，真气从丹田处绵然不绝地流入四肢百骸。\n" NOR, me);

//增强九阴和九阳
		amount=skill/3*pure_degree(me)/100;//纯门派加强
        me->add_temp("apply/attack", amount);
        me->add_temp("apply/dodge", amount);
        me->set_temp("powerup", 1);

        me->set_temp("active_force_buffer/jiuyang-shengong.powerup/name", "加力");                              //buff名称
        me->set_temp("active_force_buffer/jiuyang-shengong.powerup/last_time", time() + skill );                //持续时间
        me->set_temp("active_force_buffer/jiuyang-shengong.powerup/effect1", "攻击命中+"+(amount)+"级");       //效果描述1   
        me->set_temp("active_force_buffer/jiuyang-shengong.powerup/effect2", "轻功技能+"+(amount)+"级");       //效果描述2

        me->start_call_out(__FILE__, "remove_effect", skill, me, amount);

          if( me->is_fighting() ) me->start_busy(1)
;

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        me->delete_temp("active_force_buffer/jiuyang-shengong.powerup");
        message_vision(HIR+"$N的光明圣火功运行完毕，一切归为平常。\n"+NOR,me);
}

