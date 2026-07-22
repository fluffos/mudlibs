#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int damage;
	
	if( me->query_level()<8 )
		return notify_fail("你的人物等级不够。\n");
	if( !target ) target = offensive_target(me);

        if( !target
         || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
		return notify_fail("你要对谁施展这一招「冰爪锁心」？\n");

	if( me->query("family/family_name")!="大雪山"
	 && me->query("chushi/chushi_xueshan")!="yes" )
	 	return notify_fail("此乃雪山秘技。\n");
	 	
        if((int)me->query("force") < 500 )
		return notify_fail("你的内力不够！\n");
        if((int)me->query("kee") < 300 )
		return notify_fail("你的气血不足，没法子施用外功！\n");
        if((int)me->query_skill("cuixin-zhang", 1) < 60)
		return notify_fail("你的摧心掌级别还不够，使用这一招会有困难！\n");
        if((int)me->query_skill("cuixin-zhang", 1) < 60)
		return notify_fail("你的摧心掌级别还不够，使用这一招会有困难！\n");
	if( me->query_skill("ningxie-force",1)<60 )
		return notify_fail("你的冰谷凝血功级别还不够，使用这一招会有困难！\n");
	if( me->query_skill_mapped("force")!="ningxie-force" )
		return notify_fail("你必须依靠冰谷凝血功压制寒毒。\n");
	if( me->query_skill_mapped("unarmed")!="cuixin-zhang" )
		return notify_fail("这是摧心掌绝技。\n");
	weapon = me->query_temp("weapon");
	if( weapon && weapon->query("use_apply_skill")!="unarmed"
	 && weapon->query("skill_type")!="unarmed" )
		return notify_fail("这是摧心掌绝技。\n");
	
	msg = HIW"$N"HIW"运转冰谷凝血功，将雪山寒毒催至";
	if( !weapon )
		msg+= "掌中";
	else	msg+= "$w"HIW"上";
	msg+= "，空气顿时传来丝丝凉气，$N"HIW"闷喝一声，双手中寒气顿时化作一对寒冰巨爪，狠狠抓向$n"HIW"$l！\n"NOR;

	me->receive_damage("kee", 50);
	me->add("force", -60);
	me->set_temp("pfm_msg",1);	
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg);
	me->set_temp("pfm_msg",0);
	damage+= me->query_skill("ningxie-force")/5;
	if( target && me->is_killing(target->query("id")) )
	{
		target->set_temp("IceSuoxin",me);
		if( target->query_condition("ice_suoxin") )
			target->apply_condition("ice_suoxin",1+damage/5);
		else	target->apply_condition("ice_suoxin",damage);		
	}
	me->start_busy(1+random(2));	
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：冰爪锁心
        外功所属：摧心掌
        外功效果：对敌进行攻击，并使对方身中寒冰锁心之苦
                  使后自身busy 1-2 秒
        外功条件：
                  雪山(出师)弟子
        	  人物等级 8 级
                  内力500点，消耗60点
                  气血300点，消耗50点
                  摧心掌 60 级
                  冰谷凝血功 60 级
STR;
        me->start_more(str);
        return 1;
}