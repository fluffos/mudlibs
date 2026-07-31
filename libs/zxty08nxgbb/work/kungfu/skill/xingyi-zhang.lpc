// xingyi-zhang.c 斗转星移掌

inherit SKILL;

mapping *action = ({
([      "action" : "$N使一招「幻形变影」，双手划了个半圈，按向$n的$l",
        "force" : 160,
        "dodge" : 10,
        "lvl" : 0,
        "damage" : 14,
        "skill_name" : "幻形变影",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左手虚按，右手使一招「星星点点」，向$n的$l推去",
        "force" : 250,
        "dodge" : 5,
        "lvl" : 15,
        "damage" : 30,
        "skill_name" : "星星点点",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N双手握拳，向前向后划弧，一招「漫天星斗」打向$n的$l",
        "force" : 340,
        "dodge" : 10,
        "lvl" : 30,
        "damage" : 50,
        "skill_name" : "漫天星斗",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左手虚划，右手一记「五斗星辰」击向$n的腰部",
        "force" : 430,
        "dodge" : 15,
        "lvl" : 45,
        "damage" : 70,
        "skill_name" : "五斗星辰",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N施出「北斗七星」，右手击向$n的$l，左手攻向$n的裆部",
        "force" : 520,
        "dodge" : 10,
        "lvl" : 60,
        "damage" : 90,
        "skill_name" : "北斗七星",
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int valid_combine(string combo) { return combo=="canhe-zhi"; }
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练斗转星移掌必须空手。\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 15)
                return notify_fail("你的神元功火候不够，无法学斗转星移掌。\n");
        if ((int)me->query("max_neili") < 50)
                return notify_fail("你的内力太弱，无法练斗转星移掌。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
          if ((int)me->query("jing") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练斗转星移掌。\n");
         me->receive_damage("jing", 25);
        me->add("neili", -7);
        return 1;
}
