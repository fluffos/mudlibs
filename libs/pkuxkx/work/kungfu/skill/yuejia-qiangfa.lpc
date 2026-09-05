// Modified by iszt@pkuxkx, 2007-04-07

inherit SKILL;

#include <ansi.h>
mapping *action = ({
([
	"action":
HIW"$N"+HIW"使出一招「气吞山河」，手中的$w"+HIW"画了数圈，又一个急转，向$n"+HIW"的$l刺来"NOR,
	"dodge" : 20,
	"force" : 100,
	"damage" : 150,
	"lvl" : 20,
	"skill_name" : "气吞山河",
	"damage_type" : "刺伤"
	]),
([
	"action":
HIW"$N"+HIW"手中的$w"+HIW"突然从手中跃起，一招「还我河山」，扫向$n"+HIW"的$l"NOR,
	"dodge" : 2,
	"force" : 150,
	"damage" : 200,
	"lvl" : 40,
	"skill_name" : "还我河山",
	"damage_type" : "刺伤"
]),
([
	"action":
HIW"$N"+HIW"把枪一竖，一招「运筹帷幄」，身形借枪之力腾空跃起，手中$w"+HIW"从天而降，指向$n"+HIW"的$l"NOR,
	"dodge":	200,
	"force" : 110,
	"damage" : 160,
	"lvl" : 80,
	"skill_name" : "运筹帷幄",
	"damage_type" : "刺伤"
]),
([
	"action":
HIW"$N"+HIW"将手中$w"+HIW"一横，身体一转,$w"HIW"又从跨下刺出,一招「万川归一」对准$n"+HIW"的面部袭来"NOR,
	"dodge" : 0,
	"force" : 250,
	"damage" : 300,
	"lvl" : 120,
	"skill_name" : "万川归一",
	"damage_type" : "刺伤"
]),
([
	"action":
HIW"$N"+HIW"枪势一收，仰天一声长啸，手中$w"+HIW"突然暴起，一招「仰天长啸」向$n"+HIW"刺去"NOR,
	"dodge" : 40,
	"force" : 300,
	"damage" : 350,
	"lvl" : 160,
	"skill_name" : "仰天长啸",
	"damage_type" : "刺伤"
	]),
([
	"action":
HIW"$N"+HIW"左手一反，右手单臂握$w"+HIW"，使出一招「怒发冲冠」直指向$n"+HIW"的$l"NOR,
	"dodge" : 300,
	"force" : 350,
	"damage" : 400,
	"lvl" : 200,
	"skill_name" : "怒发冲冠",
	"damage_type" : "刺伤"
]),
([
	"action":
HIW"$N"+HIW"手中$w"+HIW"轻轻一晃，$w"+HIW"化为一道电光，却不禁神色黯然的使出「潇潇雨歇」刺向$n"+HIW"的$l"NOR,
	"dodge" : 30,
	"force" : 450,
	"damage" : 500,
	"lvl" : 230,
	"skill_name" : "潇潇雨歇",
	"damage_type" : "刺伤"
]),
([
	"action":
HIW"$N"+HIW"突然想起岳王爷不由得悲从心头起，使出「岳家枪法」最厉害的一招「夺魄连环」，手中$w"+HIW"闪电般的直奔$n"+HIW"胸口而去"NOR,
	"dodge" : 60,
	"force" : 600,
	"damage" : 800,
	"lvl" : 250,
	"skill_name" : "夺魄连环",
	"damage_type" : "刺伤"
]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_neili") < 150 )
		return notify_fail("你的内力不够，没有办法练岳家枪法。\n");

	if( !(ob = me->query_temp("weapon"))
	||      (string)ob->query("skill_type") != "spear" )
		return notify_fail("你必须先找一杆枪才能练此枪法。\n");

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
        int i, level, actionnuma, actionnumb, maxnum;
		for( i=0 ; i < sizeof(action) ; i++ )
			if ( action[i]["lvl"] <= me->query_skill("yuejia-qiangfa",1) )
			{
			maxnum = i;
			}
		if ( me->query_temp("yuejia_lianhuan") > 2 )
		{
			actionnuma = me->query_temp("yuejia_lianhuan")-3;
			actionnumb = me->query_temp("yuejia_lianhuan")-2;
		}
		else
		{
			actionnuma = 0;
			actionnumb = 1;
		}
		if ( actionnuma > maxnum )
		{
			actionnuma = maxnum;
		}
		if ( actionnumb > maxnum )
		{
			actionnumb = maxnum;
		}
		if ( me->query_temp("yuejia_lianhuan_num") == 1 )
		{
			return action[actionnuma];
		}
		if ( me->query_temp("yuejia_lianhuan_num") == 2 )
		{
			return action[actionnumb];
		}
		else
	    {
			level = (int) me->query_skill("yuejia-qiangfa",1);
			for(i = sizeof(action); i > 0; i--)
				if (level > action[i-1]["lvl"])
				    return action[NewRandom(i, 20, level/5)];
		}
		
}

int valid_enable(string usage)
{
	return usage=="spear"|| usage == "parry" ;
}

int valid_combine(string combo) { return combo=="yuejia-qiangfa"; }

int practice_skill(object me)
{
	if( (int)me->query("qi") < 30
	||	(int)me->query("neili") < 50 )
		return  notify_fail("你的内力或气不够，没有办法练习岳家枪法。\n");
	if(me->query_skill("yuejia-qiangfa",1)>50)
		return notify_fail("你现在只能在岳王墓中观看墙壁才能继续提高岳家枪法。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -40);
	return 1;
}

string *parry_msg = ({
	HIR"$n"+HIR"以攻代守，$v"+HIR"直向$N"+HIR"刺去。$N"+HIR"吓的连退数步，撤回了攻势。"NOR,
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
	return __DIR__"yuejia-qiangfa/" + action;
}