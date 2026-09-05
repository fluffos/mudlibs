//taiyi-jian.c	太乙神剑
//by zoom
//2003.4.6

inherit SKILL;

mapping *action = ({
([     "action" : "$N身子往下一矮身，同时一挥手中$w，一招「太乙无痕」，向$n的$l横劈而出",
       "force" : 120,
       "dodge" : 20,
       "damage" : 5,
        "lvl" : 9,
        "damage_type":  "割伤"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query_skill("taiyi-jian", 1) > 20)
		return notify_fail("你的太乙神剑已经无法再提高了。\n");
       return 1;
}

mapping query_action(object me, object weapon)
{
       return action[random(sizeof(action))];
}

int practice_skill(object me)
{
       object weapon;
       if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "sword")
               return notify_fail("你使用的武器不对。\n");
	if ((int)me->query_skill("taiyi-jian", 1) > 20)
		return notify_fail("你的太乙神剑已经无法再提高了。\n");
       if ((int)me->query("jingli") < 10)
               return notify_fail("你的精力不够练太乙神剑。\n");
       me->receive_damage("jingli", 5);
       return 1;
}
