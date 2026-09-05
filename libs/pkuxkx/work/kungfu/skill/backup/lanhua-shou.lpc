// lanhua-shou.c -兰花拂穴手

inherit SKILL;

mapping *action = ({
([      "action" : "$N五指张开，手形及其美妙，拂向$n的$l",
        "force" : 200,
        "dodge" : 30,
        "parry" : 30,
        "damage": 30,
        "lvl" : 100,
        "skill_name" : "试剑式",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N侧身一晃，左手五指向天，轻轻撩向$n的$l",
        "force" : 180,
        "dodge" : 10,
        "parry" : 15,
        "damage": 20,
        "lvl" : 60,
        "skill_name" : "弹指式",
        "damage_type" : "瘀伤"
]),
 ([      "action" : "$N步态轻盈，双手好似兰花，轻向$n的$l拂去",
        "force" : 160,
        "dodge" : 15,
        "parry" : 20,
        "damage": 15,
        "lvl" : 50,
        "skill_name" : "清音式",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N身行一晃，错步飘出，打向$n的$l",
        "force" : 100,
        "dodge" : 10,
        "parry" : 15,
        "damage": 5,
        "lvl" : 0,
        "skill_name" : "抚竹式",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左手好似拈花，右手缓缓飘向$n的$l",
        "force" : 120,
        "dodge" : 30,
        "parry" : 20,
        "damage": 10,
        "lvl" : 40,
        "skill_name" : "落花式",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N五指微张，错步闪身，双手齐向$n的$l掠去",
        "force" : 140,
        "dodge" : 10,
        "parry" : 5,
        "damage": 10,
        "lvl" : 30,
        "skill_name" : "问莲式",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N双手翻飞，指端迸出无数道劲气，射向$n的全身",
        "force" : 100,
        "dodge" : 5,
        "parry" : 10,
        "damage": 5,
        "lvl" : 20,
        "skill_name" : "听涛式",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左手虚晃，步履飘飘，右手好似不经意地拍向$n的$l",
        "force" : 80,
        "dodge" : 10,
        "parry" : 5,
        "damage": 0,
        "lvl" : 10,
        "skill_name" : "拈叶式",
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_combine(string combo) { return combo=="luoying-zhang"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练兰花拂穴手必须空手。\n");
        if ((int)me->query_skill("taohua-force", 1) < 15)
                return notify_fail("你的桃花内功功力不够，无法学兰花拂穴手。\n");
        if ((int)me->query("max_neili") < 70)
                return notify_fail("你的内力太弱，无法练兰花拂穴手。\n");
        return 1;
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
        level   = (int) me->query_skill("lanhua-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练兰花拂穴手。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -10);
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
string perform_action_file(string action)
{
        return __DIR__"lanhua-shou/" + action;
}

