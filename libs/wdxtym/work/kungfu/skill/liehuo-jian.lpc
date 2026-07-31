inherit SKILL;

mapping *action = ({
([      "action": "$N飞起一剑，手中$w颤动不已，直向$n席卷而去，攻势凌厉",
        "force" : 50,
        "attack": 70,
        "dodge" : 30,
        "damage": 30,
        "parry" : 70,
        "lvl"   : 0,
        "damage_type": "割伤"
]),
([      "action": "突然之间，$N凝神而立，$w凭空挑出一个火焰形状，猛然向$n身上划去",
        "force" : 70,
        "attack": 80,
        "dodge" : 33,
        "parry" : 79,
        "damage": 38,
        "lvl"   : 40,
        "damage_type": "割伤"
]),
([      "action": "$N欺身直进，左手持$w向$n飞刺过去，剑身红光隐隐，热气蒸腾",
        "force" : 90,
        "attack": 90,
        "dodge" : 41,
        "parry" : 85,
        "damage": 52,
        "lvl"   : 80,
        "damage_type": "割伤"
]),
([      "action": "$N往右跨出一步，手中那柄$w却向左横扫，夹带着炙人的热浪无孔不入的朝$n席卷而去",
        "force" : 110,
        "attack": 95,
        "dodge" : 45,
        "parry" : 92,
        "damage": 60,
        "lvl"   : 120,
        "damage_type": "割伤"
]),
([      "action": "$N二话不说，剑分三路，同时攻向$n的头、胸、腹，$n惊慌间，又感觉滚滚热浪扑面而来",
        "force" : 150,
        "attack": 97,
        "dodge" : 47,
        "parry" : 99,
        "damage": 72,
        "lvl"   : 160,
        "damage_type": "割伤"
]),
([      "action": "$N腾身而起，人与$w合而为一，状似一团熊熊燃烧的火球，直向$n飞扑而止",
        "force" : 200,
        "attack": 100,
        "dodge" : 50,
        "parry" : 100,
        "damage": 100,
        "lvl"   : 180,
        "damage_type": "割伤"
])
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("force") < 50)
                return notify_fail("你的内功火候不到，无法学习烈火剑法。\n");

        if (me->query_skill("force", 1) < me->query_skill("liehuo-jian", 1))
                return notify_fail("你的内功底子还不够，无法领会更高深的烈火剑法。\n");

        if (me->query_skill("sword", 1) < me->query_skill("liehuo-jian", 1))
                return notify_fail("你的基本剑法水平有限，无法领会更高深的烈火剑法。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("liehuo-jian", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon")) || 
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if ((int)me->query("qi") < 80)
                return notify_fail("你的体力不够练烈火剑法。\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("你的内力不够练烈火剑法。\n");

        me->receive_damage("qi", 30);
        me->add("neili", -20);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"liehuo-jian/" + action;
}


