/* 
   weituo-zhang.c 韦驮掌
   和如影随形腿(ruying-suixingtui)互备
   截自《少林拳法》，取其十一至十六，十九至二十二式。
   1/3/98 by snowman
*/

inherit SKILL;

mapping *action = ({
([	"action" : "$N将左脚伸直，成弓箭步站定，一招「迎手托架」，右手翻掌上架，左手顺势压掌下封",
	"force" : 50,
        "dodge" : 45,
	"lvl" : 0,
	"skill_name" : "迎手托架",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招「采压冲捶」，右脚原地跺步，使身体转正，接着左封掌下压，右掌向前直击$n",
	"force" : 60,
        "dodge" : 35,
	"lvl" : 0,
	"skill_name" : "采压冲捶",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N接着「转身拦截」，顺著身体右转之势，收右拳，撩左掌，双手交叉，向$n横劈而出",
	"force" : 70,
        "dodge" : 25,
	"lvl" : 20,
	"weapon" : "掌缘",
	"skill_name" : "转身拦截",
	"damage_type" : "割伤",
]),
([	"action" : "$N右脚向右踏出　使身体冲向右方，一招「进步冲捶」，收左手扣腰，右手化掌向$n圈封而出",
	"force" : 80,                                    
        "dodge" : 20,
	"lvl" : 20,
	"skill_name" : "进步冲捶",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一式「回马拉捶」，步法左转，成马步坐定，左手挑回扣住腰际，右掌顺势向$n$l击出",
	"force" : 100,
        "dodge" : 25,
	"lvl" : 40,
	"skill_name" : "回马拉捶",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N又一招「进步冲捶」，右手顺势向前圈采而出，步法随著右转之势，左手化掌向$n直击而出",
        "force" : 120,
        "dodge" : 15,
	"lvl" : 40,
	"skill_name" : "进步冲捶",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N右脚向右落步，以脚尖轻点地面，一招「跨步反砸」，左掌一直护肩不动，右掌向右反崩而出",
        "force" : 140,
        "dodge" : 15,
	"lvl" : 60,
	"skill_name" : "跨步反砸",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N双腿顺势转正，原地跺步，成弓箭步站定，一招「穿刁斜打」，右手化掌，向$n$l横切",
        "force" : 160,
        "dodge" : 30,
	"lvl" : 60,
	"weapon" : "右掌",
	"skill_name" : "穿刁斜打",
	"damage_type" : "割伤"
]),
([ 	"action" : "$N步法原地向下成马步坐定，一招「低马击砸」，右拳击砸於左膝前方，左掌则翻掌硬推",
        "force" : 180,
        "dodge" : 15,
	"lvl" : 80,
	"skill_name" : "低马击砸",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招「起胳托架」，将左脚撑直，成弓箭步站定，右拳顺势翻肘，向$n架出",
        "force" : 210,
        "dodge" : 20,
	"lvl" : 100,
	"skill_name" : "起胳托架",
	"damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_combine(string combo) { 
	if(this_player()->query_skill("weituo-zhang", 1) > 150
	   && this_player()->query_int() > 20)
   	         return combo=="shaolin-tantui"; 
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练韦驮掌必须空手。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 10)
		return notify_fail("你的本门内功火候不够，无法练韦驮掌。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练韦驮掌。\n");
	return 1;
}

string query_skill_name(int level)
{
	  int i;
	  for(i = sizeof(action)-1; i >= 0; i--)
		 if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("weituo-zhang",1);
	for(i = sizeof(action); i > 0; i--)
	  if(level > action[i-1]["lvl"])
	      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jing") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练韦驮掌。\n");
	me->receive_damage("jing", 25);
	me->add("neili", -5);
	return 1;
  }

