// Modified by iszt@pkuxkx, 2007-04-07
//加入筋斗限制
inherit SKILL;

#include <ansi.h>
mapping *action = ({
([
	"action":"$N手腕抖动，手中的$w，嗡嗡嗡连刺三剑，一剑刺向$n头顶，一剑刺$n左颈，一剑刺$n右颈",
	"dodge" : 20,
	"force" : 100,
	"damage" : 220,
	"lvl" : 20,
	"skill_name" : "云气风涌",
	"damage_type" : "刺伤"
	]),
([
	"action":"$N左手一刀砍过，右手的$w倏地往$n的小腹上刺去",
	"dodge" : 2,
	"force" : 150,
	"damage" : 250,
	"lvl" : 40,
	"skill_name" : "左右逢源",
	"damage_type" : "刺伤"
]),
([
	"action":"$N左刀横斫，右剑斜刺，往$n袭来",
	"dodge":	200,
	"force" : 110,
	"damage" : 280,
	"lvl" : 80,
	"skill_name" : "横冲直撞",
	"damage_type" : "刺伤"
]),
([
	"action":"$N将手中$w刺向$n右腰，刀劈$n的项颈",
	"dodge" : 0,
	"force" : 250,
	"damage" : 300,
	"lvl" : 120,
	"skill_name" : "忽左忽右",
	"damage_type" : "刺伤"
]),
([
	"action":"$N猛地里左刀右攻，右剑左击",
	"dodge" : 300,
	"force" : 350,
	"damage" : 350,
	"lvl" : 200,
	"skill_name" : "合纵连横",
	"damage_type" : "刺伤"
]),
([
	"action":
HIW"当当当，$N"+HIW"手中$w挥动砍了三刀，左手刀却同时使了“定阳针”、“虚式分金” 、“荆轲刺秦”、“九品莲台”四招。这四手剑招飘逸流转，四剑夹在三刀之中"NOR,
	"dodge" : 30,
	"force" : 450,
	"damage" : 380,
	"lvl" : 230,
	"skill_name" : "两面三刀",
	"damage_type" : "刺伤"
]),
([
	"action":
HIW"$N"+HIW"这一刀当头直砍，招数似乎颇为呆滞，$n只须稍一侧身，便可轻易避过，然而$w所划剑圈却笼罩住了$n前後左右，令$n绝无闪避躲让之处。"NOR,
	"dodge" : 60,
	"force" : 600,
	"damage" : 420,
	"lvl" : 250,
	"skill_name" : "假痴不癫",
	"damage_type" : "刺伤"
]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("你的内力不够，没有办法练阴阳倒乱刃法。\n");

	if( !(ob = me->query_temp("weapon"))
	||      (string)ob->query("skill_type") != "sword" ||(string)ob->query("skill_type") != "blade")
		return notify_fail("你必须先找一把剑或者刀才能练此武功。\n");

	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level,damage,force;
	int no_weapon=0;
	mapping newaction=([]);
    if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		no_weapon=1;
	if (!objectp(weapon = me->query_temp("secondary_weapon")) || (string)weapon->query("skill_type") != "blade") 
        no_weapon=1;
	if (no_weapon == 1)
	{
		newaction=([
		"action" : HIR"你赤手空拳，无法继续使用倒乱刃，攻势也缓了下来。\n"NOR,
		"force"  : 100,
		"damage" : 30,
		"damage_type" : "刺伤",
		"skill_name" : "赤手空拳",	
		"dodge": random(30),
		]);
		i = me->query_temp("yinyang-daoluan/daoluan");
		if( i>0 ) 
		{
			me->delete_temp("apply/attack_speed", i);
			me->delete_temp("yiyang-daoluan/daoluan");
			me->delete_temp("active_buffer/yinyang-daoluan.daoluan");
		}
		return newaction;
	}
  if (me->query_temp("active_buffer/shenghuo-lingfa.jindou"))
  {
		newaction=([
		"action" : HIR"你胡乱使招，越打越乱!\n"NOR,
		"force"  : 100,
		"damage" : 30,
		"damage_type" : "刺伤",
		"skill_name" : "胡乱发招",	
		"dodge": random(30),
		]);
		return newaction;
  }

	 level   = (int) me->query_skill("yinyang-daoluan",1);
     damage = (level/150)*30+250+random(50);
	 if (damage > 650)
	 {
		 damage = 650;
	 }
	 force = level/8 + 250 + random(50);
	 if (force > 500)
	 {
		 force = 500;
	 }

	if(level >= 500 && me->query("qi")> 2000
		&& me->query("neili") > 2000 && random(40) > 37 )
	{
        me->add("neili",-50-random(50));
		newaction=([
		"action" : HIR"那料到$N手腕微震，黑剑斗地弯弯的绕了过去，剑尖正中$n下臂\n"NOR,
		"dodge": random(30),
		"force"  : force,
		"damage" : damage,
		"damage_type" : "刺伤",
		"skill_name" : "云山雾罩",
		]);
		return newaction;
	}
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int valid_enable(string usage)
{
	return usage=="sword"|| usage == "parry" || usage == "blade";
}

int valid_combine(string combo) { return combo=="yinyang-luanren"; }

int practice_skill(object me)
{
	if( (int)me->query("qi") < 30
	||	(int)me->query("neili") < 50 )
		return  notify_fail("你的内力或气不够，没有办法练习阴阳倒乱刃法。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -40);
	return 1;
}

string *parry_msg = ({
	HIR"$n"+HIR"一惊，举$v"+HIR"直向$N"+HIR"刺去。"NOR,
	HIR"$n"+HIR"连滚带爬勉强躲了开去。"NOR,
});

string *unarmed_parry_msg = ({
	HIR"$n"+HIR"将手中的$v"+HIR"连续刺出，挡住$N"+HIR"的全部攻势。"NOR,
});

string query_parry_msg(object weapon)
{
	if( weapon )
		return parry_msg[random(sizeof(parry_msg))];
	else
		return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string perform_action_file(string action)
{
	return __DIR__"yinyang-daoluan/" + action;
}