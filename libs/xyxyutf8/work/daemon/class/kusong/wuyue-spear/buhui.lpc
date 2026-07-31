#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
	int damage,p,fail=0;
	string msg,succ_msg;
	
	if( me->query_level()<20 )
		return notify_fail("你的人物等级不够。\n");
	if(me->query("family/family_name")!="火云洞" 
        && me->query("chushi/chushi_kusong")!="yes")
        	return notify_fail("你不能使用这项技能！\n"); 		
        if((int)me->query("force") < 300 )
                return notify_fail("你的内力不足！\n");
	if( me->query_skill_mapped("force")!="huomoforce" )
        	return notify_fail("此招必须配合火魔心法才能使用。\n");
	if( me->query_skill("huomoforce",1)<200 )
		return notify_fail("你的火魔心法等级不够。\n");
	weapon = me->query_temp("weapon");
	if( !weapon 
	 || ( weapon->query("skill_type")!="spear" && weapon->query("use_apply_skill")!="spear" ) )
		return notify_fail("你手里都没枪。\n");		
	if( me->query_skill("wuyue-spear",1)<200 
	 || me->query_skill_mapped("spear")!="wuyue-spear" )
		return notify_fail("你的五岳神枪太差了！\n");	 
	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
                return notify_fail("你要攻击谁？\n");

	me->add("force",-50);
	p = me->query_int()/3;
	me->add_temp("apply/attack",p);
	
	msg = HIM"$N"HIM"一挺手中$w"HIM"直刺$n"HIM"！\n"NOR;
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg);
	if( damage>0 )
		msg = HIM"\n$N"HIM"一枪刺中，又是一肘，击向$n"HIM"$l！\n"NOR;
	else	
	{
		msg = HIM"\n$N"HIM"一枪刺空，又是一肘，猛击$n"HIM"$l！\n"NOR;
		fail++;
	}
	succ_msg = HIR"结果「嗡」地一声$n"HIR"只觉得眼前一黑，双耳轰鸣不止！\n"NOR;
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg);
	me->set_temp("pfm_msg",0);
	
	if( damage>0 )
		msg = HIM"\n$N"HIM"一肘得手，但仍不收招，顺势一头撞向$n"HIM"！\n"NOR;
	else
	{
		msg = HIM"\n$N"HIM"一肘失手，但仍不收招，顺势一头撞向$n"HIM"！\n"NOR;
		fail++;
	}
	succ_msg = HIR"结果这一下「轰」地一声撞得$n"HIR"眼冒金星，差一点摔倒！\n"NOR;
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg);
	me->set_temp("pfm_msg",0);
	if( damage<1 )
		fail++;
	if( random(fail)>2 )
		message_combatd(HIW"\n$n"HIW"哈哈大笑：“只逞匹夫只勇又有何用？”，轻松避开。\n"NOR,me,target);	
	else
	{
		message_combatd(HIW"\n$n"HIW"也被这拼命的举动吓了一跳！\n"NOR,me,target);
		if( me->query("int")>=random(target->query_cps()) && !target->is_busy() )
			target->start_busy(3);
	}
	me->start_busy(2);	
	me->add_temp("apply/attack",-p);	
        return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：不见南山誓不回
        外功所属：五岳神枪
        外功效果：连续对对方进行三次带固定伤害的攻击
                  并可能使对方僵直3秒
                  使后自身busy 2 秒
        外功条件：
        	  火云洞(出师)弟子
        	  人物等级20级	
        	  内力300点，消耗50点
                  五岳神枪 200 级并激发
                  火魔心法 200 级
                  
STR;
        me->start_more(str);
        return 1;
}