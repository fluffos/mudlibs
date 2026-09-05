// jinyu-quan.c 金玉拳

inherit SKILL;

mapping *action = ({
([      "action" : "$N一招「金光灿烂」，双拳一上一下,一张一阖, 向$n挥去",
        "force"  : 120,
        "dodge"  : 10,
        "damage" : 20,
        "lvl"    : 0,
        "skill_name" : "金光灿烂",
        "damage_type" : "瘀伤"

]),
([      "action" : "$N一招「削金断玉」，幻出一片拳影，霸气荡荡，击向$n的头部",
        "force"  : 140,
        "dodge"  : 20,
        "damage" : 30,
        "lvl"    : 20,
        "skill_name" : "削金断玉",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左掌画了个圈圈，右掌推出，一招「蓝田美玉」击向$n$l",
        "force"  : 150,
        "dodge"  : 20,
        "damage" : 45,
        "lvl"    : 40,
        "skill_name" : "蓝田美玉",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一招「金玉其外」，凌空跃起，冷不防在落地前对准$n的$l招呼过去.",
        "force"  : 160,
        "dodge"  : 25,
        "damage" : 30,
        "lvl"    : 60,
        "skill_name" : "金玉其外",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N绕着$n一转，满场游走，拳出如风，不绝击向$n，正是一招
「金玉满堂」",
        "force"  : 170,
        "dodge"  : 30,
        "damage" : 40,
        "lvl"    : 80,
        "skill_name" : "金玉满堂",
        "damage_type" : "瘀伤"
]),
([      "action" : "只见$N一个侧身退步，左手虚晃，突然猛跨两步，已到$n面前，
右拳陡出，事先绝无征兆，迅如崩雷，一招「点石成金」击向$n的前胸",
        "force"  : 180,
        "dodge"  : 35,
        "damage" : 50,
        "lvl"    : 100,

        "skill_name" : "点石成金",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一招「众口铄金」，扑向$n，似乎$n的全身都被拳影笼罩",
        "force"  : 280,
        "dodge"  : 30,
        "damage" : 60,
        "lvl"    : 120,
        "skill_name" : "众口铄金",
        "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_combine(string combo) { return combo=="qingyan-zhang"; }

int valid_learn(object me)
{
    if ((int)me->query_skill("duanjia-xinfa",1) < 20)
                return notify_fail("你的段家心法火候不够，无法练金玉拳。\n");
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练金玉拳必须空手。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练金玉拳。\n");
        return 1;

}
mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("jinyu-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练金玉拳。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -5);
        return 1;
}



