inherit SKILL;

mapping *action = ({
([      "action": "$N单腿点地，向上拔出丈余，$w飞舞幻出无数刀影将
$n罩住，口中大喝一声[旱天雷]，只听刀带风声呜呜作响向$n的$1劈去",
        "damage":410,
    "damage_type": "劈伤"
]),
([      "action": "$N冷笑连连，单刀向外一拨身体顺势急转，突然急停向
$n的身前跃去，口中长啸「风云变」刀锋横扫$n的$l",     
        "damage":420,
    "damage_type": "割伤"
]),
([      "action": "$N双目精光暴长，神情怒不可遏，一式[冲冠怒]单掌变拳
直击$n的$l不待$n做出反应，$w竟然毫无章法似的向$n全身乱劈过去，速度极
快$n只觉眼前尽是刀影而不见人",
        "damage":440,
    "damage_type": "砍伤"
]),

});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 500)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("force", 1) < 150)
                return notify_fail("你的「基本内功」火候太浅。\n");
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
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("kee") < 50)
                return notify_fail("你的体力不够练「霹雳三式」。\n");
        me->receive_damage("kee", 25);
        return 1;
}

string perform_action_file(string action)
{
return "/daemon/class/yandang/pili-sanshi/" + action;
}
int power_point()       {       return 1.75;     }
int hard_point()        {       return 3;       }

