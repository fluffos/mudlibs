// shenghuo-quan.c 圣火拳

inherit SKILL;

mapping *action = ({
([      "action" : "$N使一招「凤凰长吟」，双手上下翻飞，击向$n的$l",
        "force" : 150,
        "dodge" : 30,
        "skill_name" : "凤凰长吟",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左手护住胸前，右手使一招「困虎云啸」，向$n的$l插去",
        "force" : 250,
        "dodge" : 25,
        "skill_name" : "困虎云啸",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N默运内力，全身骨骼暴响，一招「卧龙天翔」打向$n的$l",
        "force" : 300,
        "dodge" : 20,
        "skill_name" : "卧龙天翔",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左右手同时使出「卧龙天翔」,发出一道真气击向$n的$l",
        "force" : 500,
        "dodge" : 5,
        "skill_name" : "双飞龙",
        "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练圣火拳必须空手。\n");
        if ((int)me->query_skill("shenghuo-shengong", 1) < 20)
                return notify_fail("你的圣火神功火候不够，无法学圣火拳。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练圣火拳。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练圣火拳。\n");
        me->receive_damage("qi", 25);
        me->add("neili", -10);
        return 1;
}

