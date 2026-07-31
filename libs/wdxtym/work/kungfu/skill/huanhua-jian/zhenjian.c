// zhen.c 浣花剑法 之 乱红飞过秋千处
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
string query_name() { return "乱红飞过"ZJBR"秋千处"; }
int perform(object me, object target)
{
	int damage, ap, dp;
	object obj;
	string w_name;

	w_name = me->query("weapon/name");
	obj = me->query_temp("weapon");
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("“乱红飞过秋千去”只能对战斗中的对手使用。\n");
	if (me->is_busy()) 
		return notify_fail("你现在正忙着呢！\n");
	if ((int)me->query_skill("huanhua-jian", 1) < 450)
		return notify_fail("你的浣花剑法不够娴熟，不能运剑自如。\n");
	if ((int)me->query_skill("guiyuan-dafa", 1) < 300)
		return notify_fail("你的归元大法火侯太浅，无法震断手中长剑。\n");
	if (me->query_skill_mapped("force")!="guiyuan-dafa")
		return notify_fail("你的未使用归元大法，无法震断手中长剑。\n");	
	if ((int)me->query("neili",1) < 1000)
		return notify_fail("你的内力不够，无法震断手中长剑。。\n");
	if (! objectp(obj = me->query_temp("weapon")) || (string)obj->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对！\n");	
	if (me->query_skill_mapped("sword") != "huanhua-jian")
		return notify_fail("你没正确激发该技能 。\n");
	if (obj->query("weapon_prop/damage") < 10)
		return notify_fail("你使用的武器太渣渣了！\n");	
	
	message_vision( HIY "$N聚气于剑，默运内力，只听“铮”的一声，忽然间银光闪耀，$N手中长剑竟断为无数\n"
	                + "截，如漫天红云般向$n激射而出！\n"NOR, me, target );
	ap = me->query("xyzx_sys/level") + me->query_skill("huanhua-jian", 1) + me->query_skill("sword") + me->query_skill("force");
	dp = target->query("xyzx_sys/level") + target->query_skill("dodge") + target->query_skill("parry");
	if( random( ap ) > dp/3 )
	{
		damage = me->query_skill("huanhua-jian",1) + me->query_skill("force") + me->query_skill("sword",1) + obj->query("weapon_prop/damage")*2;
		damage = damage+random(damage);
		if(damage < 10 ) damage = 10; //2015.4 加入解决伤害为0
//		if( objectp(obj) && w_name!=obj->query("name") )	//这个是什么意思？
		if( objectp(obj) )	
		{
			target->receive_wound("jing", damage,me);
			target->receive_damage("qi", damage,me);
			target->receive_wound("qi", damage,me);
			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage +"，精神的内伤为"+ damage +"。\n" NOR);
		//	if (!target->is_busy()) target->start_busy(1 + random(5));
		}
		else
		{
			target->receive_wound("jing", damage/3,me);
			target->receive_damage("qi", damage/3,me);
			target->receive_wound("qi", damage/3,me);
			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage/3 +"，内伤为"+ damage/3 +"，精神的内伤为"+ damage/3 +"。\n" NOR);
		//	if (!target->is_busy()) target->start_busy(1 + random(2));
		}
		message_vision( HIM "泪眼问花花不语，乱红飞过秋千处，$N的长剑化成碎片，如落叶般散落一地！\n"NOR, me, target );
	}
	else
	{
		message_vision( HIY "可是$p晃动身形，迅速的闪过了剑雨。\n" NOR, me, target );
	}
//	if( !target->is_killing(me) ) target->kill_ob(me);
	me->add("neili", -200);
/*		//2017.4.20阿飞改，用一次pfm就碎一把武器，土豪也用不起啊
	if( objectp(obj) && w_name!=obj->query("name") )
	{
		me->set("weapon/make",0);
		destruct( obj );
		me->delete("weapon");		
		me->save();
	}
	else
	{
		destruct( obj );
	}	
	message_vision( HIM "泪眼问花花不语，乱红飞过秋千处，$N的长剑化成碎片，如落叶般散落一地！\n"NOR, me, target ); */
	me->start_busy(3);
	return 1;
}
