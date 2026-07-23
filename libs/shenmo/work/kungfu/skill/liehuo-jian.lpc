// liehuo-jian.c 烈火剑

inherit SKILL;

mapping *action = ({
([      "action" : "$N一招「四海云飘」，$w似幻出片片白云，四面八方的罩向$n",
        "force" : 170,
        "dodge" : 15,
        "damage" : 120,
        "lvl" : 0,
        "skill_name" : "四海云飘",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「四通八达」，剑锋乱指，攻向$n，$n根本不能分辩$w的来路",
        "force" : 190,
        "dodge" : 10,
        "damage" : 130,
        "lvl" : 19,
        "skill_name" : "四通八达",
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出「在天一方」，$w幻一条飞练，带着一股寒气划向$n的$l",
        "force" : 110,
        "dodge" : 10,
        "damage" : 140,
        "lvl" : 29,
        "skill_name" : "在天一方",
        "damage_type" : "刺伤"
]),
([      "action" : "$N身子向上弹起，左手下指，一招「怪蟒翻身」，右手$w带着一团剑花，逼向$n的$l",
        "force" : 130,
        "dodge" : 5,
        "damage" : 150,
        "lvl" : 39,
        "skill_name" : "怪蟒翻身",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「飞瀑倒悬」，左脚跃步落地，右手$w幻成一条雪白的瀑布，扫向$n的$l",
        "force" : 150,
        "dodge" : 5,
        "damage" : 160,
        "lvl" : 59,
        "skill_name" : "飞瀑倒悬",
        "damage_type" : "刺伤"
]),
([      "action" : "$N右腿半屈般蹲，$w平指，一招「无声无色」，剑尖无声无色的慢慢的刺向$n的$l",
        "force" : 170,
        "dodge" : 15,
        "damage" : 170,
        "lvl" : 79,
        "skill_name" : "无声无色",
        "damage_type" : "刺伤"
]),
([  "action" : "$N一招「万川归海」，$w在$n的周身飞舞，令$n眼花缭乱，剑身在半空中突然停住刺向$n的$l",
        "force" : 300,
        "dodge" : 5,
        "damage" : 280,
        "lvl" : 99,
        "skill_name" : "万川归海",
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
                return notify_fail("你的九阳神功火侯太浅。\n");
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
        level   = (int) me->query_skill("liehuo-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("jing") < 50)
                return notify_fail("你的体力不够练烈火剑法。\n");
        me->receive_damage("jing", 30);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"liehuo-jian/" + action;
}
