// fyfy-zhang.c（翻云覆雨掌）

inherit SKILL;

mapping *action = ({
([      "action" : "$N使一招「大风起兮」，双手协隐隐风声，按向$n的$l。",
        "force" : 150,
        "dodge" : 30,
        "skill_name" : "大风起兮",
        "damage_type" : "外伤"
]),
([      "action" : "$N左手虚按$n的$l，忽的「风云突变」，灌足内力向$n的$l插去。",
        "force" : 250,
        "dodge" : 25,
        "skill_name" : "风云突变",
        "damage_type" : "外伤"
]),
([      "action" : "$N双手握拳，向前后分别划弧，一招「雷电焦作」打向$n的两肋。",
        "force" : 300,
        "dodge" : 50,
        "skill_name" : "雷电焦作",
        "damage_type" : "外伤"
]),
([      "action" : "$N左手虚划，右手单掌「翻手为云」击向$n的$n。",
        "force" : 320,
        "dodge" : 30,
        "skill_name" : "翻手为云",
        "damage_type" : "外伤"
]),
([      "action" : "$N施出「覆手为雨」，双手向下一压，运足真力，击向$n的$l。",
        "force" : 400,
        "dodge" : 45,
        "skill_name" : "覆手为雨",
        "damage_type" : "外伤"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("zhenfeng-xinfa", 1) < 10)
                return notify_fail("你的「震风心法」火候不够，无法学「翻云覆雨掌」。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练「翻云覆雨掌」必须空手。\n");
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练「翻云覆雨掌」。\n");
        me->receive_damage("qi", 25);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"fyfy-zhang/" + action;
}

