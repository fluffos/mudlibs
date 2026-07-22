// mingwang-jian.c 不动明王剑
// by dubei 
inherit SKILL;

mapping *action = ({
([      "action" : "$N使出一式「大悲」，$N手中的$w已经迅捷无比的刺向$n的$l。  ",
        "skill_name" : "大悲",
        "force" : 100,
        "dodge" : -10,
        "lvl" : 0,
        "damage" : 30,
        "damage_type" : "刺伤",
]),
([      "action" : "$N使出一式「出剑」，简单而有效地往$n的$l刺去。",
        "skill_name" : "出剑",
        "force" : 120,
        "dodge" : 5,
        "lvl" : 20,
        "damage" : 30,
        "damage_type" : "刺伤",
]),
([      "action" : "$N使出一招「不动」，身形一转，反手一挥，手中$w刺向$n的$l。",
        "skill_name" : "不动",
        "force" : 100,
        "dodge" : -10,
        "lvl" : 40,
        "damage" : 40,
        "damage_type" : "割伤",
]),
([      "action" : "$N使出「初醒」，双脚点地，全身转出一团剑光滚向$n。",
        "skill_name" : "初醒",
        "force" : 170,
        "dodge" : 10,
        "lvl" : 60,
        "damage" : 48,
        "damage_type" : "刺伤",
]),
([      "action" : "$N使出一招「无涯」，全身劲气贯于$w中，一片剑光袭向$n的$l。",
        "skill_name" : "无涯",
        "force" : 250,
        "dodge" : 10,
        "lvl" : 70,
        "damage" : 54,
        "damage_type" : "刺伤",
]),
([      "action" : "$N剑锋忽转，一式「冲霄」，闪电般刺向$n的$l。",
        "skill_name" : "冲霄",
        "force" : 180,
        "dodge" : -15,
        "lvl" : 80,
        "damage" : 60,
        "damage_type" : "割伤",
]),
([      "action" : "$N使出一招「归宗」，手中$w狂风骤雨般地向$n的$l连攻数剑。",
        "skill_name" : "归宗",
        "force" : 200,
        "dodge" : 20,
        "lvl" : 90,
        "damage" : 66,
        "damage_type" : "割伤",
]),
([      "action" : "$N舞动$w发出逼人剑气刺去，一招「狂雷」，挟著闪闪剑光刺向$n的$l。",
        "skill_name" : "狂雷",
        "force" : 220,
        "dodge" : 25,
        "lvl" : 100,
        "damage" : 80,
        "damage_type" : "刺伤",
]),
});


int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
 

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("longxiang-gong", 1) <= 20 ) 
                   return notify_fail("你的龙象般若功火候太浅。\n");
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
	level   = (int) me->query_skill("mingwang-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("你的体力不够，练不了不动明王剑。\n");
	me->receive_damage("jing", 25);
	return 1;
}
