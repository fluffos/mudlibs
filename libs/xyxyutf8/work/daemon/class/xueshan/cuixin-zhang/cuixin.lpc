#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
	string msg,str;
	
	if( me->query_level()<5 )
		return notify_fail("你的人物等级不够。\n");
	if( !target ) target = offensive_target(me);

        if( !target
         || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
		return notify_fail("你要对谁施展这一招摧心掌？\n");

	if( time()-(int)me->query_temp("xueshan_cuixin") < 5 )
		return notify_fail("绝招用多就不灵了！\n");

        if((int)me->query("force") < 300 )
		return notify_fail("你的内力不够！\n");
        if((int)me->query("kee") < 200 )
		return notify_fail("你的气血不足，没法子施用外功！\n");
        if((int)me->query_skill("cuixin-zhang", 1) < 50)
		return notify_fail("你的摧心掌级别还不够，使用这一招会有困难！\n");

	
	message_vision(HIB"$N"HIB"大喝一声“摧心掌”！\n", me);
	me->receive_damage("kee", 30);
	me->add("force", -50);
    	me->set_temp("xueshan_cuixin",time());
    		
	me->set_temp("cuixin_per", 5);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_PERFORM,0,0,0,30);
	me->delete_temp("cuixin_per");
	me->reset_action();
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：摧心掌
        外功所属：摧心掌
        外功效果：给予敌人带固定伤害的一击
                  使用后冷却5秒
        外功条件：
        	  人物等级 5 级
                  内力300点，消耗50点
                  气血200点，消耗30点
                  摧心掌 50 级
STR;
        me->start_more(str);
        return 1;
}