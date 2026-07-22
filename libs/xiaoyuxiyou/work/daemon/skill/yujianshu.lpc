inherit SKILL;
#include <ansi.h>
#include <combat.h>

mapping *action = ({
	([	
		"name" : "御剑生风",
		"action": "$N双脚一顿，笔直跃起，手中$w不停地颤抖着，笼罩住$n全身。这势"+HIC"「御剑生风」"NOR"果然是无孔不入。\n",
		"parry_msg" : "$n双脚一顿，笔直跃起，手中$w迎风飞涨，将$N攻势全部逼回。这势"+HIC"「御剑生风」"NOR"果然是泼水难进。\n",
		"dodge":		-10,
		"parry":		-10,
		"damage":		 65,
		"damage_type":		"刺伤"
	]),
	([	"name" : "御剑如虹",
		"action": "$N手中$w化作点点寒光，直射$n前胸大穴。$n正专心致志地对付着剑招，不料$w忽化长虹，迅捷直刺$n的$l。这势"+HIM"「御剑如虹」"NOR"亦真亦幻，实是难防。\n",
		"parry_msg" : "$n手中$w化作长虹，"+HIM"「御剑如虹」"NOR"一出，将$N的招式尽数挡住。\n",
		"dodge":		-5,
		"parry":		-10,
		"damage":		85,
		"damage_type":		"震伤"
	]),
	([	"name" : "御剑成龙",
		"action": "$N在$n四周游走，一招"+HIY"[御剑成龙]"NOR",手中$w迎风化作一条长龙，飘忽不定，只看得$n眼花缭乱，不觉间$w已向$n的$l疾挑。\n",
		"parry_msg" : "$n一招"+HIY"[御剑成龙]"NOR",手中$W迎风化作一条长龙，飘忽不定，只看得$N眼花缭乱，不觉间$w已被格开。\n",
		"dodge":		-5,
		"parry":		-5,
		"damage":		105,
		"damage_type":		"刺伤"
	]),
	([	"name" : "御剑行空",
		"action": "$N仗起手中$w，飞射点点寒光，罩住$n的胸腹，只等$n的破绽。这招"+HIR"「御剑行空」"NOR"直如细雨般紧密，$n实在不知$w将要指向自己身上何处。\n",
		"parry_msg" : "$n手中$W飞射点点寒光，这招"+HIR"「御剑行空」"NOR"直如细雨般紧密，将$N的攻势尽数逼回。\n",
		"dodge":		-15,
		"parry":		-15,
		"damage":		125,
		"damage_type":		"刺伤"
	]),
	([	"name" : "御剑无影",
		"action": "$N手中$w中宫直进，化作一道剑光疾速射向$n的前心。这招"+HIB"「御剑无影」"NOR"令人耳目一新。$n只觉浑身一紧，$l感觉阵阵寒意。\n",
		"parry_msg" : "$n手中$w化作一道剑光中宫直进，这招"+HIB"「御剑无影」"NOR"令人耳目一新。$N只觉浑身一紧，无奈撤招换势。\n",
		"dodge":		-15,
		"parry":		-10,
		"damage":		155,
		"damage_type":		"刺伤"
	]),
	([	"name" : "御剑飞腾",
		"action": "$N驾驭$w向$n的右手疾刺，但正当$n要招架时，$w却突然转向了$n的左足！这招"+HIG"「御剑飞腾」"NOR"确实神鬼莫测。\n",
		"parry_msg" : "$n驾驭$w，舞动如飞，轨迹难料！这招"+HIG"「御剑飞腾」"NOR"确实神鬼莫测，$N的攻击皆被架住。\n",
		"dodge":		-20,
		"parry":		-25,
		"damage":		200,
		"damage_type":		"刺伤"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力修为不够深，御剑术学了也没用。\n");
	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一柄剑才能练习剑法。\n");
	return 1;
}

varargs int practice_skill(object me,int flag)
{
	int dod=(int)me->query_skill("dodge");
	int swo=(int)me->query_skill("yujianshu");

	if (dod<swo/2)
		return notify_fail("你的身法跟不上剑法，练下去很可能会伤到自己。\n");
	if ((int)me->query("kee") < 30)
		return notify_fail("你体质欠佳，强练御剑术有害无益。\n");
	if ((int)me->query("force") < 5)
		return notify_fail("你内力不足，强练御剑术有走火入魔的危险。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
if ( flag )     message_vision("$N默默回忆了一会儿，然后练了一遍御剑术。\n", me);
	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
	int i;
	if( intp(i=me->query_temp("perform_YJS")) 
	 && i>0 )
	{
		if( i>6 ) i = 6;
		return action[i-1];
	}
     	i = me->query_skill("yujianshu",1)/60;
     	if( i>6 )
     		i = 6;
     	if( random(10)==1 )		
     		return action[random(sizeof(action))];
     	else	return action[random(i)];
}

string perform_action_file(string func)
{
	return CLASS_D("shushan") + "/yujianshu/"+func;
}

string query_parry_msg(object me,object target)
{
	mapping act;
	if( !me || !target )
		return 0;
	if( !me->query_temp("weapon") )
		return 0;
	act = query_action(me,me->query_temp("weapon"));
	return act["parry_msg"];
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	string msg;
	int ap,dp,damage;
	if( !me || !living(me) || !victim 
	 || !me->is_killing(victim->query("id"))
	 || !me->is_fighting(victim) )
		return 0;
	if( COMBAT_D->check_level(me,victim)==-1 
	 || me->query_level()<60 
	 || me->query("family/family_name")!="蜀山派"
	 || me->query_skill("yujianshu",1) < 600
	 || me->query_skill_mapped("sword") != "yujianshu" 
	 || me->query("force_factor")<1 
	 || me->query_temp("shushan_jianshen")<=0 )
        	return 0;
	ap = me->query_kar();
	dp = victim->query("kar");
	if( random(ap+dp)<dp )
		return 0;
	
	me->add_temp("shushan_jianshen",-1);
	if( me->query_temp("shushan_jianshen")<=0 )
	{
		message_vision(HIW"\n$N"HIW"头顶之上的白发老者虚像渐渐淡去。\n\n"NOR,me);
		me->set_temp("shushan_jianshen_end",time());
		return 0;
	}
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_PERFORM,0,0,0,1000,"kee");	
	me->delete_temp("pfm_msg");
	if( damage<1 )
		return 0;

	if( COMBAT_D->query_message_type(me,victim)==2 )
	{
		message_vision(HIR"剑神"NOR"对$n造成了"HIR+damage+NOR"点气血减少。\n",me,victim);
		return "";
	}
	else
	{
		msg = WHT"刹那间千万剑光从半空云霞中破空而来，劈头盖面的罩向$n"WHT"！\n"NOR;
		msg+= HIR"$n"HIR"一个不慎，$l已插了无数把光彩逼人的化形小剑！\n"NOR;
	}
	return msg;
}	