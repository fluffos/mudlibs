// Last Modified by winder on Sep. 12 2001
// lian.c 落雁剑法「连」字诀

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "「连」字诀"
int perform(object me, object target)
{
	object weapon;
	string msg;
	int i, attack_time,sword_lvl;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];


	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

        if( me->query_skill("nei-bagua",1) <=50)
                 return notify_fail("内八卦等级不够。\n");
	bskill = "luoyan-jianfa";



	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，不会使用"+PNAME+"。\n");

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("你的内力修为不够！\n");

	if( (int)me->query("neili") < 400 )
		return notify_fail("你的真气不够！\n");

	me->add("neili", -200);

	msg = HIY"$N"HIY"使出落雁剑法「连」字诀，招式陡然变快，疯狂的扑向$n！\n"NOR;
	message_combatd(msg, me, target);
	if(random(me->query("combat_exp"))>(int)target->query("combat_exp")/20)
	{
		attack_time = random((int)me->query_skill(bskill, 1)/20);
		sword_lvl=(int)me->query_skill(bskill,1)/10;
		if(attack_time < 2) attack_time = 2;
		if(attack_time > 10) attack_time = 10;
		if(attack_time > 5) 
		{
			attack_time = attack_time - 4;
			attack_time = 5 + random(attack_time);
		}
if (random(3)==0) target->start_busy(2);
	 msg = YEL"结果$p被$P一轮急攻，毫无还手余裕。\n"NOR;
			me->add_temp("apply/damage",500);	
			me->add_temp("apply/attack",80);
		for(i = 0; i < attack_time; i++)
		{
			if (flag == 1) target = offensive_target(me);
			if (!objectp(target)) break;
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
		}
		me->add_temp("apply/damage",-500);
		me->add_temp("apply/attack",-80);
		me->start_busy(2);
		//target->start_busy(1);
	}
	else
	{
		msg = CYN"可是$p出手在先，一下就制住了$P的剑路。\n"NOR;
		me->start_busy(1);
	}
	message_combatd(msg, me, target);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		对敌人连续出手

	出手要求：
		落雁剑法120级
		内力修为500
		内力400
HELP
	);
	return 1;
}

