//kaishan-zhang 开山掌

inherit SKILL;

mapping *action = ({
([      "action" : "$N合掌抱球，猛吸一口气，一式「曲径通幽」，双掌疾推向$n的肩头
",
        "force" : 200,
        "dodge" : 15,
        "damage" : 10,
        "lvl" : 0,
        "skill_name" : "曲径通幽",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使一招「白云出岫」，双手划了个半圈，按向$n的$l",
        "force" : 220,
        "dodge" : 15,
        "damage" : 5,
        "lvl" : 9,
        "skill_name" : "白云出岫",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左掌划一半圆，一式「冠盖五岳」，右掌斜穿而出，疾拍$n的胸前大穴",
        "force" : 240,
        "dodge" : 25,
        "damage" : 5,
        "lvl" : 19,
        "skill_name" : "冠盖五岳",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使一式「云断秦岭」，右掌上引，左掌由后而上一个甩劈，斩向$n的$l",
        "force" : 260,
        "dodge" : 10,
        "damage" : 40,
        "lvl" : 39,
        "skill_name" : "云断秦岭",
        "damage_type" : "瘀伤"
]),
([       "action" : "$N左手虚划，右手一记「青松翠翠」击向$n的$l",
        "force" : 300,
        "dodge" : 15,
        "damage" : 45,
        "lvl" : 49,
        "skill_name" : "青松翠翠",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N施出「群山环抱」，右手击向$n的$l，左手攻向$n的裆部",
        "force" : 320,
        "dodge" : 55,
        "damage" : 15,
        "lvl" : 69,
        "skill_name" : "群山环抱",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N全身越起，一招「力劈华山」，向$n的$l击去",
        "force" : 340,
        "dodge" : 60,
        "damage" : 20,
        "lvl" : 79,
        "skill_name" : "力劈华山",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N双手握拳，狂喉一声，一式「高山流水」奋力打向$n的$l",
        "force" : 350,
        "dodge" : 10,
        "damage" : 70,
        "lvl" : 89,
        "skill_name" : "高山流水",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左掌护胸，右拳凝劲后发，一式「开天辟地」，缓缓推向$n的$l",
        "force" : 380,
        "dodge" : 15,
        "damage" : 90,
        "lvl" : 99,
        "skill_name" : "开天辟地",
        "damage_type" : "瘀伤"
]),

});

int valid_enable(string usage) { return  usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="ryingzhua-gong"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练开山掌必须空手。\n");
        if ((int)me->query_skill("riyue-shengong", 1) < 20)
                return notify_fail("你的内功等级不够，无法学开山掌。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练开山掌。\n");
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
        level   = (int) me->query_skill("kaishan-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练开山掌。\n");
        me->receive_damage("qi", 25);
        me->add("neili", -5);
        return 1;
}

string *parry_msg = ({
        "$n一抖$v，手中的$v化作一条长虹，磕开了$N的$w。\n",
        "$n挥舞$v，手中的$v化做漫天雪影，荡开了$N的$w。\n",
        "$n手中的$v一抖，向$N的手腕削去。\n",
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
        "$n反手挥出$v，整个人消失在一团光芒之中。\n",
});

string *unarmed_parry_msg = ({
        "$n猛击$N的面门，逼得$N中途撤回$w。\n",
        "$n以守为攻，猛击$N的手腕。\n",
        "$n左手轻轻一托$N$w，引偏了$N$w。\n",
        "$n脚走阴阳，攻$N之必救。\n",
        "$n左拳击下，右拳自保，将$N封于尺外。\n",
        "$n双拳齐出，$N的功势入泥牛入海，消失得无影无踪。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
