// powerup.c 太乙神功加力
// 2009.8.17 finished by zgbl

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill, level;

	    if ((int)me->query("family"))
		  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");

	    if (me->query("betrayer") > 0)
		  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");

	    if (me->query("family") || me->query("chushi/last_family"))
		  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");

        if( target != me )
                return notify_fail("你只能用太乙神功来提升自己的战斗力。\n");

	    if (me->query_skill("hunyuan-yiqi",1) > 0)
		  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
//有门派或者有过门派都无法使用，纯百姓技能

        if( (int)me->query("neili") < 100  )
                return notify_fail("你的内力不够。\n");

        if( (int)me->query_temp("powerup") )
             return notify_fail("你已经在运功中了。\n");

        if ((int)me->query_skill("taiyi-shengong", 1) < 60)
                return notify_fail("你的太乙神功等级不够，不能提升战斗力。\n");

        skill = me->query_skill("force");
        level = 5;
        if ( (int)me->query_skill("taiyi-shengong",1) > 500 ) level = 3;

        message_vision(HIC "$N太乙神功运转，衣袂飘飞中，顶心隐隐现出三朵青色莲花，精气神已全然抟作一处。\n" NOR, me);

        me->add_temp("apply/attack", skill/level);
        me->add_temp("apply/dodge", skill/level);
        me->set_temp("powerup", 1); 
        me->add("neili", -100);
        
        me->set_temp("active_force_buffer/taiyi-shengong.powerup/name", "加力");                                  //buff名称
        me->set_temp("active_force_buffer/taiyi-shengong.powerup/last_time", time() + skill/level );              //持续时间
        me->set_temp("active_force_buffer/taiyi-shengong.powerup/effect1", "攻击命中+"+(skill/level)+"级");       //效果描述1   
        me->set_temp("active_force_buffer/taiyi-shengong.powerup/effect2", "轻功技能+"+(skill/level)+"级");       //效果描述2
        
        me->start_call_out(__FILE__, "remove_effect", skill/level, me, skill/level);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
//太乙神功500级以下，powerup系数为1/5，500以上为1/3
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        me->delete_temp("active_force_buffer/taiyi-shengong.powerup");
        tell_object(me,HIC "你的太乙神功运行完毕，飘飞衣袂渐渐回落，顶心三花隐去，内力缓缓收回丹田。\n"NOR);
}

