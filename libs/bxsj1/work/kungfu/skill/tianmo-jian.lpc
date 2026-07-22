// tianmo-jian 天魔剑
inherit SKILL;

mapping *action = ({
([      "action":"$N使一式「风兮破地」，手中$w带出一股猛烈气旋攻向$n",
        "force" : 120,
        "dodge" : -10,
        "damage": 15,
        "lvl" : 0,
        "skill_name" : "风兮破地",
        "damage_type":  "刺伤"
]),
([      "action":"$N错步上前，使出「水兮滔天」，只见漫天剑影有如排山倒海般的向$n压去",
        "force" : 140,
        "dodge" : -10,
        "damage": 20,
        "lvl" : 9,
        "skill_name" : "水兮滔天",
        "damage_type":  "割伤"
]),
([      "action":"$N一式「火兮焚野」，猛地运发剑气，手中$w如火龙般向$n卷噬而下",
        "force" : 160,
        "dodge" : 5,
        "damage": 30,
        "lvl" : 18,
        "skill_name" : "火兮焚野",
        "damage_type":  "割伤"
]),
([      "action":"$N催动内力，一式「山兮鬼神惊」，剑势挟带着如山般的巨大力量压向$n",
        "force" : 180,
        "dodge" : 10,
        "damage": 35,
        "lvl" : 27,
        "skill_name" : "山兮鬼神惊",
        "damage_type":  "刺伤"
]),
([      "action":"$N仰天长啸，一式「雷兮天地碎」，天上骇然显现出无数的剑影如雷球般向$n电击而下",
        "force" : 220,
        "dodge" : 15,
        "damage": 40,
        "lvl" : 36,
        "skill_name" : "雷兮天地碎",
        "damage_type":  "刺伤"
]),
([      "action":"$N手中$w现出剑芒万丈，一式「天罗魔罟」，漫天交缠着的剑芒将$n重重围住",
        "force" : 260,
        "dodge" : 5,
        "damage": 45,
        "lvl" : 44,
        "skill_name" : "天罗魔罟",
        "damage_type":  "刺伤"
]),
([      "action":"$N一跃而起，一式「魔动九天」，$w发出耀眼光茫，剑身幻成万道金光罩向$n的全身",
        "force" : 380,
        "dodge" : 5,
        "damage": 60,
        "lvl" : 60,
        "skill_name" : "魔动九天",
        "damage_type":  "刺伤"
]),
([      "action":"$N使出天魔剑终极境界「人剑合一」，人与剑彼此连成一体，化作一道光芒射向$n",
        "force" : 480,
        "dodge" : 5,
        "damage": 80,
        "lvl" : 80,
        "skill_name" : "人剑合一",
        "damage_type":  "刺伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if (userp(me))
                return notify_fail("你的内力不够。\n");
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
        level   = (int) me->query_skill("tianmo-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if(userp(me))           
                return notify_fail("你无法练天魔剑法。\n");
        return 1;
}