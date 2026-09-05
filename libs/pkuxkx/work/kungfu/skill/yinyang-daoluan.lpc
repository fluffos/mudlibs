// Modified by iszt@pkuxkx, 2007-04-07

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
	"lvl" : 140,
	"skill_name" : "左右逢源",
	"damage_type" : "刺伤"
]),
([
	"action":"$N左刀横斫，右剑斜刺，往$n袭来",
	"dodge":	200,
	"force" : 110,
	"damage" : 280,
	"lvl" : 380,
	"skill_name" : "横冲直撞",
	"damage_type" : "刺伤"
]),
([
	"action":"$N将手中$w刺向$n右腰，刀劈$n的项颈",
	"dodge" : 0,
	"force" : 250,
	"damage" : 300,
	"lvl" : 420,
	"skill_name" : "忽左忽右",
	"damage_type" : "刺伤"
]),
([
	"action":"$N猛地里左刀右攻，右剑左击",
	"dodge" : 300,
	"force" : 350,
	"damage" : 350,
	"lvl" : 600,
	"skill_name" : "合纵连横",
	"damage_type" : "刺伤"
]),
([
	"action":HIW"当当当，$N"+HIW"手中$w挥动砍了三刀，左手刀却同时使了“定阳针”、“虚式分金” 、“荆轲刺秦”、“九品莲台”四招。这四手剑招飘逸流转，四剑夹在三刀之中"NOR,
	"dodge" : 30,
	"force" : 400,
	"damage" : 380,
	"lvl" : 730,
	"skill_name" : "两面三刀",
	"damage_type" : "刺伤"
]),
([
	"action":HIW"$N"+HIW"这一刀当头直砍，招数似乎颇为呆滞，$n只须稍一侧身，便可轻易避过，然而$w所划剑圈却笼罩住了$n前後左右，令$n绝无闪避躲让之处。"NOR,
	"dodge" : 60,
	"force" : 450,
	"damage" : 420,
	"lvl" : 850,
	"skill_name" : "假痴不癫",
	"damage_type" : "刺伤"
]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("你的内力不够，没有办法练阴阳倒乱刃法。\n");

	if( !(ob = me->query_temp("weapon"))||(((string)ob->query("skill_type") != "sword" )&&((string)ob->query("skill_type") != "blade" )))
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
//	int no_weapon=0;
	mapping newaction=([]);
    /*if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		no_weapon=1;
	if (!objectp(weapon = me->query_temp("secondary_weapon")) || (string)weapon->query("skill_type") != "blade") 
        no_weapon=1;*/
	if (me->query_temp("active_buffer/shenghuo-lingfa.jindou")||me->query("zyhb")||me->query_temp("can_zyhb"))
	{
		newaction=([
		"action" : HIR"忽然$N心神大乱，也许是倒乱刃与其他功夫产生了冲突，一时之间只能胡乱劈砍数下"NOR,
		"force"  : 100,
		"damage" : 30,
		"damage_type" : "刺伤",
		"skill_name" : "乱七八糟",	
		"dodge": random(30),
		]);
		return newaction;
	}
	 level   = (int) me->query_skill("yinyang-daoluan",1);
     damage = (level/150)*30+250+random(50);
	 if (damage > 580)
	 {
		 damage = 580;
	 }
	 force = level/8 + 250 + random(50);
	 if (force > 400)
	 {
		 force = 400;
	 }

	if(level >= 600 && me->query("qi")> 2000
		&& me->query("neili") > 2000 && random(40) > 35 )
	{
        me->add("neili",-50-random(50));
		newaction=([
		"action" : HIR"那料到$N手腕微震，$w斗地弯弯的绕了过去，锋刃直指$n下臂"NOR,
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

int valid_combine(string combo) { return combo=="yinyang-daoluan"; }

int practice_skill(object me)
{
	/*if (me->query("zyhb")||(me->query("hubo")))
	{
		if (me->query_skill("yinyang-douluan")>300)
		{
			 return notify_fail("你会左右互搏，心思就别用在这上面了。\n");
		}
	}*/
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