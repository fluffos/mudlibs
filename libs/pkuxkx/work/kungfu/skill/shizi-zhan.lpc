// shizi-zhan.c
// 十字战

inherit SKILL;

mapping *action = ({
([      "action"    :"$N坐马拉弓，击出一拳，正是一招「混元手」..",
	"force" : 120,
	"dodge" : 30,
	"lvl" : 0,
	"damage": 25,
	"skill_name" : "混元手",
	"damage_type" : "瘀伤"
]),
([      "action"    :"$N双掌一错，使出「虚式冲天炮」，对准$n的$l连续拍出三掌",
	"force" : 180,
	"dodge" : 50,
	"lvl" : 20,
	"damage": 25,
	"skill_name" : "虚式冲天炮",
	"damage_type" : "瘀伤"
]),
([      "action"    :"$N吐气扬声，一招「狮子大张口」双手奔$n的头颈抢去",
	"force" : 240,
	"dodge" : 80,
	"lvl" : 50,
		"damage": 50,
	"skill_name" : "狮子大张口",
	"damage_type" : "内伤"
]),
([      "action"    :"$N一招「擂拳寸腿」,起手向$n$l拍去...",
	"force" : 300,
	"dodge" : 120,
	"lvl" : 80,
		"damage": 50,
	"skill_name" : "擂拳寸腿",
	"damage_type" : "瘀伤"
]),
([      "action"    :"$N左掌一翻，右掌推出，一个「劈锤」击向$n$l",
	"force" : 400,
	"dodge" : 150,
	"lvl" : 100,
		"damage": 100,
	"skill_name" : "劈锤",
	"damage_type" : "瘀伤"
]),
([      "action"    :"$N使出一招「插腿」，脚踩七星步，一拳向$n$l击去",
	"force" : 480,
	"dodge" : 180,
	"lvl" : 120,
		"damage": 100,
	"skill_name" : "插腿",
	"damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="wulong-quan"; }

    
int valid_learn(object me)
{
    if ( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练『十字战』必须空手。\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力太弱，无法学习『十字战』。\n");
	if ((int)me->query_skill("strike", 1) < 40)
		return notify_fail("你的基本掌法火候不够，无法学习『十字战』。\n");
		
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
        level   = (int) me->query_skill("shizi-zhan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]) return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练『十字战』必须空手。\n");
   if( (int)me->query("jing") < 30)
     return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
   if( (int)me->query("qi") < 30 )
     return notify_fail("你现在手足酸软，休息一下再练吧。\n");
   if( (int)me->query("neili") < 10 )
     return notify_fail("你的内力不够了。\n");

   me->receive_damage("qi", 30);
   me->add("neili", -5);
	return 1;
}