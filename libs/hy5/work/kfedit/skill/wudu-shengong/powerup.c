// powerup.c 化蛇大法

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

       if( target != me ) return notify_fail("你只能用五毒神功提升自己的战斗力。\n");

	if( (int)me->query("neili") < 220 )	return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("liuyun") ) 
                return notify_fail(HIG"你已经在默运流云水袖神功了。\n");

        if( (int)me->query_temp("qzj_tong") ) 
                return notify_fail("你已经在运同归剑了。\n");
      if( me->query_temp("fumo")   )
      return notify_fail("你正在使用大金刚拳的特殊攻击「金刚伏魔」！\n");
      if( me->query_temp("jingang")   )
      return notify_fail("你正在使用大金刚拳的特殊攻击「大金刚神通」！\n");
      if( me->query_temp("fanzhen")   )
                return notify_fail("你正在运用「金刚不坏体神功」！\n");
        if( (int)me->query_temp("jiuyin/powerup") )
        	return notify_fail("你已经在运九阴真功中了。\n");
        if( (int)me->query_temp("hslj/powerup") )
        	return notify_fail("你已经在运万法归宗中了。\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("你正在运用「凤凰天舞」心法！\n");

        if((int)me->query_temp("tzzf") ) 
                return notify_fail("你已经在掌刀的运功中。\n");

       if( me->query_temp("powerup") ) return notify_fail("你已经在运功中了。\n");

          skill = me->query_skill("wudu-shengong",1)/2;
        if (skill > 200) skill=200;
	me->add("neili", -200);
 
	message_vision(
        BLU "$N运起五毒神功,头顶黑气蒸腾，全身肌肤坟起黑色的鳞甲，双目凶光四射！\n" NOR, me);

	me->add_temp("apply/damage", skill*3);
	me->add_temp("apply/armor", skill*3);
	me->add_temp("apply/unarmed", skill);
        me->add_temp("apply/attack",skill);
	me->add_temp("apply/defense",skill);
	me->set_temp("powerup", 1);
me->set_temp("wdpowerup", 1);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);

	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int amount)
{
	int skill;
        skill = me->query_skill("wudu-shengong",1)/2;
        if (skill > 200) skill=200;
	me->add_temp("apply/damage", -skill*3);
	me->add_temp("apply/armor", -skill*3);
	me->add_temp("apply/unarmed", -skill);
        me->add_temp("apply/attack",-skill);
	me->add_temp("apply/defense",-skill);
        me->delete_temp("wdpowerup", 1);
	me->delete_temp("wdpowerup");
	me->delete_temp("powerup");
      tell_object(me, "你的五毒神功运行完毕，身体逐渐恢复正常。\n");
}
