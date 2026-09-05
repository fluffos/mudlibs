// panguan-bifa 判官笔法

inherit SKILL;

mapping *action = ({

([      "action" : "$N$w一起，向$n左颊连点三点，正是那“裴”字的起首三笔",
        "force" : 140,
        "dodge": 10,
        "damage" : 50,
        "damage_type" : "刺伤"
]),
([      "action" : "$N$w虚点，自右上角至左下角弯曲而下，劲力充沛，笔尖所划是个“如”字的草书，直刺$n的$l",
        "damage" : 60,
        "force" : 160,
        "dodge" : 10,
        "damage_type" : "刺伤"
]),
([      "action" : "$N劲贯中锋，笔致凝重，但锋芒角出，剑拔弩张，大有磊落波磔意态。乃是蜀汉大将张飞所书的《八蒙山铭》",
        "damage" : 70,
        "force" : 180,
        "dodge" : 10,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中的$w一晃，大书《怀素自叙帖》中的草书，纵横飘忽，流转无方",
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
                return notify_fail("你的体力不够练判官笔法。\n");
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
        return __DIR__"panguan-bifa/" + action;
}
