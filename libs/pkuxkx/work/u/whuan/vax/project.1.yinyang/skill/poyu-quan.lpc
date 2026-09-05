// poyu-quan.c -劈石破玉拳

inherit SKILL;

mapping *action = ({
([      "action" : "$N双手握拳，狂喉一声，一式「石破天惊」奋力打向$n的$l",
        "force" : 300,
        "dodge" : 20,
        "damage" : 150,
        "lvl" : 79,
        "skill_name" : "石破天惊",
        "damage_type" : "瘀伤"
 ]),
([      "action" : "$N双手狂舞，使出「粉石碎玉」，向$n的$l锤去",
        "force" : 320,
        "dodge" : 15,
        "damage" : 160,
        "lvl" : 89,
        "skill_name" : "粉石碎玉",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使一招「傍花拂柳」，双手划了个半圈，按向$n的$l",
        "force" : 150,
        "dodge" : 30,
        "damage" : 70,
        "lvl" : 9,
        "skill_name" : "傍花拂柳",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左手虚按，右手使一招「起手式」，向$n的$l插去",
        "force" : 100,
        "dodge" : 25,
        "damage" : 50,
        "lvl" : 0,
        "skill_name" : "起手式",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N双手握拳，向前向后划弧，一招「铁闩横门」打向$n的$l",
        "force" : 150,
        "dodge" : 20,
        "damage" : 90,
        "lvl" : 19,
        "skill_name" : "铁闩横门",
        "damage_type" : "瘀伤"
]),
([       "action" : "$N左手虚划，右手一记「金刚挚尾」击向$n的$l",
        "force" : 250,
        "dodge" : 15,
        "damage" : 120,
        "skill_name" : "金刚挚尾",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N施出「封闭手」，右手击向$n的$l，左手攻向$n的裆部",
        "force" : 270,
        "dodge" : 10,
        "damage" : 140,
      "lvl" : 49,
        "skill_name" : "封闭手",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N全身跃起，一招「千斤坠地」，向$n的$l击去",
        "force" : 300,
        "dodge" : 25,
        "damage" : 180,
        "lvl" : 69,
        "skill_name" : "千斤坠地",
        "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_combine(string combo) { return combo=="hunyuan-zhang"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练劈石破玉拳必须空手。\n");
//        if ((int)me->query_skill("huashan-neigong", 1) < 10 && (int)me->query_skill("zixia-shengong", 1) < 10)
//                return notify_fail("你的内功等级不够，无法学劈石破玉拳。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练劈石破玉拳。\n");
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
        level   = (int) me->query_skill("poyu-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练劈石破玉拳。\n");
        me->receive_damage("qi", 30);
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

string query_yinyang()
{
	return "纯阳";
}