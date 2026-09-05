// pomo-jianfa 泼墨披麻剑法

inherit SKILL;

mapping *action = ({

([      "action" : "$N一招「春风杨柳」，似乎没见他脚步移动，$w已向$n劈砍下去",
        "force" : 140,
        "dodge": 10,
        "damage" : 50,
        "damage_type" : "刺伤"
]),
([      "action" : "$N向前跨上一步，手中$w使出「白虹贯日」直刺$n的$l",
        "damage" : 60,
        "force" : 160,
        "dodge" : 10,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中的$w一晃，使出「腾蛟起凤」直刺$n的$l",
       "force" : 200,
        "dodge" : 10,
        "damage" : 80,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("riyue-shengong", 1) < 20 )
                return notify_fail("你的内功等级不够。\n");
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
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练泼墨披麻剑法。\n");
        me->receive_damage("qi", 20);
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
        return __DIR__"pomo-jianfa/" + action;
}
