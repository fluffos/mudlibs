// yuxiao-jianfa.c 玉箫剑法
// llx 23/10/97

inherit SKILL;

mapping *action = ({
([	"action" : "$N斗然间拧腰纵臂，回身出剑，一招「青龙取水」，手中$w直刺$n的$l",
	"force" : 120,
	"dodge" : 20,
	"damage" : 30,
        "lvl" : 0,
	"damage_type" : "刺伤"
]),
([	"action" : "$N斜身移步，右手$w使出一式「春雷怒震」，剑尖起处，圆圆一团银花，剑尖上一点寒光直点$n的$l",
	"force" : 140,
	"dodge" : 15,
	"damage" : 40,
        "lvl" : 0,
	"damage_type" : "刺伤"
]),
([	"action" : "$N抽出长剑，一招「风卷残云」，径向$n的$l点去",
	"force" : 170,
	"dodge" : 15,
	"damage" : 50,
        "lvl" : 9,
	"damage_type" : "刺伤"
]),
([	"action" : "$N当即剑交左手，一招「铁锁横江」，剑光闪闪，招招指向$n的$l",
	"force" : 190,
	"dodge" : 10,
	"damage" : 60,
        "lvl" : 19,
	"damage_type" : "刺伤"
]),
([	"action" : "$N左足绕前避过，使出「白露横江」，回锋下插，进攻$n的下盘",
	"force" : 240,
	"dodge" : 10,
	"damage" : 75,
        "lvl" : 29,
	"damage_type" : "刺伤"
]),
([	"action" : "$N忽然跃起，飞身半空，头上脚下，一剑快似一剑，一招「电照长空」，右手$w直逼$n的$l",
	"force" : 280,
	"dodge" : 5,
	"damage" : 85,
        "lvl" : 39,
	"damage_type" : "刺伤"
]),
([	"action" : "$N向左跃开数尺，避开了$n的进攻，一招「凤点头」，疾往$n的面门点去",
	"force" : 300,
	"dodge" : 5,
	"damage" : 95,
        "lvl" : 59,
	"damage_type" : "刺伤"
]),
([  "action" : "$N左膝一低，曲肘竖肱，一招「起凤腾蛟」，刷的一声，剑尖猛撩$n的$l",
	"force" : 380,
	"dodge" : -5,
	"damage" : 135,
        "lvl" : 99,
	"damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("bihai-shengong", 1) < 20)
		return notify_fail("你的碧海神功火候太浅。\n");
		return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
          level  = (int)me->query_skill("yuxiao-jianfa",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
return action[0];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 35)
		return notify_fail("你的体力不够练玉箫剑法。\n");
	me->receive_damage("qi", 25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yuxiao-jian/" + action;
}

string *parry_msg = ({
        "只见$n双手横劈，将手中$v舞得飕飕风响，顿时格开了$N的$w。\n",
        "$n使出玉箫剑法「卸」字诀，$v轻轻一点，$N的$w好象打在棉絮中，对$n毫无伤害。\n",
        "$n侧身闪避，双足急点，跃在半空，手中$v立时回撤，迅即挑出，$N的$w一下就偏了出去。\n",
        "$n左手往右手贯劲，左手随发之际，右手往回带撤，用手中$v架开。\n",
        "但是$n身子稍侧，左臂反过来就是一剑，用手中$v格开。\n",
});

string *unarmed_parry_msg = ({
        "但是$n身子一侧，忽的后跃，用左手轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
        "$n向后跃开，然后蹑足上前，顺势后拉，$N就象打在一团棉絮中，对$n毫无伤害。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                  return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
