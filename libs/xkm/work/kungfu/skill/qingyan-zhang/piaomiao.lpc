//Cracked by Roath
//piaomiao.c  云烟飘渺
//update again at Jan/26/2002
//few change apply there
//降低命中率
//降低攻击力
//增加neili cose
//限制only player apply attacking 	if (userp(me)) me->add_temp("apply/attack", attack);
//fix callout bug
//mantian Jan/26/2002
#include <ansi.h>
#include <skill.h>
#include <combat.h>

inherit F_DBASE;
inherit F_SSERVER;

void force_finish(object me, int damage, int attack, int speed, int mem_damage, int mem_attack, int mem_speed);
void check_attack(object me, object target, int damage, int attack, int speed, int mem_damage, int mem_attack, int mem_speed);
void remove_effect(object me, int damage, int attack, int speed, int mem_damage, int mem_attack, int mem_speed);

int perform(object me, object target)
{
	object weapon, weapon1 ;
	string msg;
	int level, mem_speed, mem_attack, mem_damage, attack, damage, speed;
	object tester = find_player("mantian");

	if (!target) target = offensive_target(me);

	if (me->query("family/family_name")!="大理段家" && !wizardp(me))
		return notify_fail(HIW "你非大理弟子无法施展「云烟飘渺」！\n" NOR);

	if (me->query_skill_mapped("force") != "kurong-changong")
		return notify_fail(HIW "你所用的内功心法不对，无法聚集真气。\n" NOR);

	if (me->query_skill_mapped("dodge") != "duanshi-shenfa")
		return notify_fail(HIW "你所用的身法不对，挥洒「云烟飘渺」。\n" NOR);

	if (!target || !target->is_character() || !me->is_fighting(target))
		return notify_fail(HIW "「云烟飘渺」只能对战斗中的对手使用。\n" NOR);

	if (me->query_temp("yunyanpiao")) return notify_fail( HIW "你正在施展「云烟飘渺」！\n" NOR);

	if ((int)me->query_skill("kurong-changong", 1) < 140)
		return notify_fail(HIW "你的枯荣禅功修为未到，无法施展「云烟飘渺」。\n" NOR);

	if( me->query_skill("strike", 1) < 110 )
		return notify_fail(HIW "你对基本掌法的熟练程度尚未纯熟，无法意会「云烟飘渺」！\n" NOR); 

	if ((int)me->query_skill("qingyan-zhang", 1) < 150) 
		return notify_fail(HIW "你的五罗轻烟掌修为不足，尚未领悟到「云烟飘渺」的境意。\n" NOR); 

	if( me->query_skill("dodge") < 135 )
		return notify_fail(HIW "施展「云烟飘渺」需配合着熟练的轻功方能使出！\n" NOR);


	if( me->query_str() < 35 ) return notify_fail(HIW "你天生两臂无力，天赋不足，无法使出「云烟飘渺」！\n" NOR);
	if( me->query_con() < 35 ) return notify_fail(HIW "你气嘘体弱，体质太差，无法提气使出「云烟飘渺」！\n" NOR);
	if( me->query_dex() < 35 ) return notify_fail(HIW "你身形呆胖，无法体会「云烟飘渺」的境意！\n" NOR);

	if (me->query("max_neili") <= 1800)
		return notify_fail(HIW "你的内力修为不足，无发体会出「云烟飘渺」！\n" NOR);
	
	if ((int)me->query("neili", 1) < 1000)
		return notify_fail(HIW "你的内力不够，内劲不足以施展「云烟飘渺」！\n" NOR);

	if (me->query("jingli") <= 1500)
		return notify_fail(HIW "你没有足够的体力施展「云烟飘渺」！\n" NOR);

	if(me->is_busy()) return notify_fail(HIW "你正忙着呢,没办法施展云烟飘渺！\n" NOR);

	if(target->query("dalibandit")) return notify_fail(HIW "抓犯人你还想耍酷呀！\n" NOR);

	message_vision(HIB"$N运起枯荣心法，将真气凝聚运往手掌，顿时$N手掌反白，掌中泛起一阵"NOR HIW"白烟"NOR HIB"。\n" NOR, me);

	level = (int)me->query_skill("qingyan-zhang", 1); 
	mem_attack = (int)me->query_temp("apply/attack",1);
	mem_damage = (int)me->query_temp("apply/damage",1);
	mem_speed = (int)me->query_temp("apply/speed",1);
	speed = level/8 + random(level/5);
	attack = level/4 + random(level/3);
	damage = level/5 + random(level/4);
	me->add("neili", -500);
	me->add("jingli", -300);
	me->set_temp("yunyanpiao", 1);
	if (userp(me)) me->add_temp("apply/attack", attack);
	me->add_temp("apply/damage", damage);
	me->add_temp("apply/speed", speed);
	//检查用
	if (wizardp(me)) tell_object(me, sprintf(WHT"原本攻击力：%d，原本命中率：%d，原本速度：%d，增加攻击力：%d，增加命中率：%d，增加速度：%d。\n"NOR, mem_damage, mem_attack, mem_speed, damage, attack, speed));

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->set_temp("yunyanpiao", 2);
    me->start_call_out( (: call_other, __FILE__, "check_attack", me, target, damage, attack, speed, mem_damage, mem_attack, mem_speed :), 1);
	me->start_call_out( (: call_other, __FILE__, "force_finish", me, damage, attack, speed, mem_damage, mem_attack, mem_speed :), 14);
	return 1;
}
void force_finish(object me, int damage, int attack, int speed, int mem_damage, int mem_attack, int mem_speed)
{
	if (wizardp(me)) tell_object(me, "强迫停止\n");
	if (me->query_temp("yunyanpiao"))
	{
		tell_object(me,BLU "\n你长呼一口气，将内劲收回丹田。\n" NOR);
		me->delete_temp("yunyanpiao");
		me->add_temp("apply/speed", -speed);
		if (userp(me)) me->add_temp("apply/attack", -attack);
		me->add_temp("apply/damage", -damage);
		me->start_busy(1);
		tell_object(me, MAG "\n你将气息调节至原本的状态。\n\n"NOR);
		if (wizardp(me)) tell_object(me, sprintf(WHT "调节后：原本攻击力：%d，原本命中率：%d，原本速度：%d，目前攻击力：%d，目前命中率：%d，目前速度：%d。\n"NOR, mem_damage, mem_attack, mem_speed, me->query_temp("apply/damage"), me->query_temp("apply/attack"), me->query_temp("apply/speed")));
		if((int)me->query_temp("apply/speed",1) != mem_speed)
		{
			me->set_temp("apply/speed",mem_speed);
		}
		if((int)me->query_temp("apply/attack",1) != mem_attack)
		{
			me->set_temp("apply/attack",mem_attack);
		}
		if((int)me->query_temp("apply/damage",1) != mem_damage)
		{
			me->set_temp("apply/damage",mem_damage);
		}
		if (wizardp(me)) tell_object(me, sprintf(WHT "再调节：原本攻击力：%d，原本命中率：%d，原本速度：%d，目前攻击力：%d，目前命中率：%d，目前速度：%d。\n"NOR, mem_damage, mem_attack, mem_speed, me->query_temp("apply/damage"), me->query_temp("apply/attack"), me->query_temp("apply/speed")));
	}
}
void check_attack(object me, object target, int damage, int attack, int speed, int mem_damage, int mem_attack, int mem_speed)
{
	int used, max_use;
	max_use = 1 + (int)me->query_skill("qingyan-zhang", 1)/100;
	used = me->query_temp("yunyanpiao");

	if (!target || !me->is_fighting(target)) target = offensive_target(me);
	if (used > max_use || used > 6)
	{
		message_vision(BLU "\n$N长呼一口气，将内劲收回丹田。\n"NOR, me);
		remove_effect(me, damage, attack, speed, mem_damage, mem_attack, mem_speed);
		me->start_busy(1);
		tell_object(me, MAG "\n你将气息调节至原本的状态。\n\n"NOR);
		return;
	}
	if (!living(me) || me->is_ghost())
	{
		remove_effect(me, damage, attack, speed, mem_damage, mem_attack, mem_speed);
		return ;
	}
	if( !me->is_fighting() )
	{
		message_vision(HIM "\n$N纵身向后一跃，收起了聚起的内劲。\n"NOR, me);
		remove_effect(me, damage, attack, speed, mem_damage, mem_attack, mem_speed);
		tell_object(me, MAG "\n你将气息调节至原本的状态。\n\n"NOR);

		return;
	}
	if (me->query_skill_mapped("force") != "kurong-changong")
	{
		message_vision(WHT "\n$N中途转换内功心法，一口气提不起来。\n"NOR, me);
		message_vision(WHT "\n$N脸色突然转白，跟着口吐"NOR RED"鲜血"NOR WHT"。\n"NOR, me);
		me->receive_damage("qi", 800, "吐血身亡");
		me->receive_damage("jingli", 1000, "吐血身亡");
		me->add("eff_qi",-300);
		remove_effect(me, damage, attack, speed, mem_damage, mem_attack, mem_speed);
		return;
	}
	if (me->query_skill_prepared("strike") != "qingyan-zhang")
	{
		message_vision(WHT "\n$N感觉到气血不顺，只能收回掌力。\n"NOR, me);
		remove_effect(me, damage, attack, speed, mem_damage, mem_attack, mem_speed);
		return;
	}
	if (me->query_skill_mapped("dodge") != "duanshi-shenfa")
	{
		message_vision(WHT "\n$N脚步一个不稳，只感气血不顺，只好收回掌力。\n"NOR, me);
		remove_effect(me, damage, attack, speed, mem_damage, mem_attack, mem_speed);
		return;
	}
	if (me->query("neili") < 100)
	{
		message_vision(WHT "\n$N感觉到气血不顺，一口气提不起来，只好收回掌力。\n"NOR, me);
		remove_effect(me, damage, attack, speed, mem_damage, mem_attack, mem_speed);
		return;
	}
	if (!me->query_temp("yunyanpiao"))
	{
		remove_effect(me, damage, attack, speed, mem_damage, mem_attack, mem_speed);
		tell_object(me, HIM "\n你感觉到气血不顺，内劲回归体内。\n\n"NOR);
		return;
	}
	call_out("check_attack", 1, me, target, damage, attack, speed, mem_damage, mem_attack, mem_speed);
//	me->start_call_out( (: call_other, __FILE__, "check_attack", me, target, damage, attack, speed, mem_damage, mem_attack, mem_speed :), 1);
	return;
}       
void remove_effect(object me, int damage, int attack, int speed, int mem_damage, int mem_attack, int mem_speed)
{
	if (!me) return;
	me->delete_temp("yunyanpiao");
	me->add_temp("apply/speed", -speed);
	if (userp(me)) me->add_temp("apply/attack", -attack);
	me->add_temp("apply/damage", -damage);
	if (wizardp(me)) tell_object(me, sprintf(WHT "remove_effect：原本攻击力：%d，原本命中率：%d，原本速度：%d，目前攻击力：%d，目前命中率：%d，目前速度：%d。\n"NOR, mem_damage, mem_attack, mem_speed, me->query_temp("apply/damage"), me->query_temp("apply/attack"), me->query_temp("apply/speed")));
	if((int)me->query_temp("apply/speed",1) != mem_speed)
	{
		me->set_temp("apply/speed",mem_speed);
	}
	if((int)me->query_temp("apply/attack",1) != mem_attack)
	{
		me->set_temp("apply/attack",mem_attack);
	}
	if((int)me->query_temp("apply/damage",1) != mem_damage)
	{
		me->set_temp("apply/damage",mem_damage);
	}
	if (wizardp(me)) tell_object(me, sprintf(WHT "remove_effect再调节：原本攻击力：%d，原本命中率：%d，原本速度：%d，目前攻击力：%d，目前命中率：%d，目前速度：%d。\n"NOR, mem_damage, mem_attack, mem_speed, me->query_temp("apply/damage"), me->query_temp("apply/attack"), me->query_temp("apply/speed")));
	me->start_busy(1);
}
