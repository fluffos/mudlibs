// wulong-quan.c
// 乌龙拳

inherit SKILL;

mapping *action = ({
([      "action"    :"$N坐马拉弓，击出一拳，正是一招乌龙拳中的「乌龙出水」",
	"force" : 120,
	"dodge" : 20,
	"lvl" : 0,
	"damage": 50,
	"skill_name" : "乌龙出水",
	"damage_type" : "瘀伤"
]),
([      "action"    :"$N双掌一错，使出「乌龙夺珠」，对准$n的$l连续拍出三掌",
	"force" : 240,
	"dodge" : 40,
	"lvl" : 30,
	"damage": 75,
	"skill_name" : "乌龙夺珠",
	"damage_type" : "瘀伤"
]),
([      "action"    :"$N吐气扬声，一招「乌龙吸水」，双手奔$n的头颈抢去",
	"force" : 360,
	"dodge" : 60,
	"lvl" : 60,
	"damage": 100,
	"skill_name" : "乌龙吸水",
	"damage_type" : "瘀伤"
]),
([      "action"    :"$N一招「乌龙翻云」,起手向$n$l拍去...",
	"force" : 480,
	"dodge" : 80,
	"lvl" : 90,
	"damage": 125,
	"skill_name" : "乌龙翻云",
	"damage_type" : "内伤"
]),
([      "action"    :"$N左掌一翻，右掌推出，一招「乌龙翻江」击向$n$l",
	"force" : 560,
	"dodge" : 100,
	"lvl" : 120,
	"damage": 150,
	"skill_name" : "乌龙翻江",
	"damage_type" : "瘀伤"
]),
([      "action"    :"$N使出一招「乌龙摆尾」，脚踩七星步，一拳向$n$l击去",
	"force" : 480,
	"dodge" : 150,
	"lvl" : 150,
	"damage": 125,
	"skill_name" : "乌龙摆尾",
	"damage_type" : "瘀伤"
]),
([      "action"    :"$N使出一招「乌龙入洞」，左掌虚按，右拳下击，直奔$n的$l而去",
	"force" : 420,
	"dodge" : 180,
	"lvl" : 180,
	"damage": 100,
	"skill_name" : "乌龙入洞",
	"damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_combine(string combo) { return combo=="shizi-zhan"; }

    
int valid_learn(object me)
{
    if ( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练『乌龙拳』必须空手。\n");
	if ((int)me->query("max_neili") < 300)
		return notify_fail("你的内力太弱，无法学习『乌龙拳』。\n");
	if ((int)me->query_skill("cuff", 1) < 40)
		return notify_fail("你的基本掌法火候不够，无法学习『乌龙拳』。\n");
		
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
        level   = (int) me->query_skill("wulong-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]) return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练『乌龙拳』必须空手。\n");
   if( (int)me->query("jing") < 30)
     return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
   if( (int)me->query("qi") < 40 )
     return notify_fail("你现在手足酸软，休息一下再练吧。\n");
   if( (int)me->query("neili") < 20 )
     return notify_fail("你的内力不够了。\n");

   me->receive_damage("qi", 40);
   me->add("neili", -10);
	return 1;
}