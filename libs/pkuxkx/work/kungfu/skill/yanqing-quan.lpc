// yanqing-quan 燕青拳 Zine Dec 9 2010

inherit SKILL;
#include <ansi.h>
mapping *action = ({
([	"action" : "$N挥洒自如，一式「脱靴转身」，用后背撞向$n的$l",
	"force" : 130,
    "dodge" : 10,
	"lvl" : 0,
	"skill_name" : "脱靴转身",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N踏前一步，右肘上扬，一招「上步进肘掴身拳」，打向$n空门",
	"force" : 150,
        "dodge" : 20,
	"lvl" : 66,
	"skill_name" : "上步进肘掴身拳",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双手连环抢攻，使一招「迎面抢快打三拳」，双手不停不歇地向$n的$l攻去",
	"force" : 170,
        "dodge" : 30,
	"lvl" : 77,
	"skill_name" : "迎面抢快打三拳",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N指东打西，潇洒无比，一招「左右跨打」打向$n的$l",
	"force" : 210,
        "dodge" : 35,
	"lvl" : 88,
	"skill_name" : "左右跨打",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N使一招「反身裁锤」，猛然一个回身，双肘以不可思议地方向击向$n的$l",
	"force" : 240,
        "dodge" : 45,
	"lvl" : 99,
	"skill_name" : "反身裁锤",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N倒踢魁星，一记「踢腿撩阴十字拳」，十分阴毒地踢向$n的下阴",
	"force" : 290,
        "dodge" : 55,
	"lvl" : 120,
	"skill_name" : "踢腿撩阴十字拳",
        "damage_type" : "瘀伤"
]),
});



int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
    int level,i;
    
	    level   = (int) me->query_skill("yanqing-quan");
        for(i = sizeof(action); i > 0; i--)
        if(level > action[i-1]["lvl"])
        return action[NewRandom(i, 20, level/5)];
    
}



int practice_skill(object me)
{
    if ((int)me->query("qi") < 200)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 100)
		return notify_fail("你的内力不够练燕青拳。\n");
	me->receive_damage("qi", 20);
	me->add("neili", -5);
	return 1;
}

string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
});

string *unarmed_parry_msg = ({
        "但是被$p格开了。\n",
        "结果被$p挡开了。\n",
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
  return __DIR__"yanqing-quan/" + action;
}