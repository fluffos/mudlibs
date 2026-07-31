// juehu-shou.c -三阴绝户手

inherit SKILL;

mapping *action = ({
([      "action" : "$N一式「老牛拉车」，以掌化爪，五指如钩，两眼瞪得通红，直逼$n的裆部",
        "force" : 180,
        "dodge" : 6,
        "lvl" : 0,
        "skill_name" : "老牛拉车",
        "damage_type" : "抓伤"
]),
([      "action" : "$N四肢贴地，头部底垂，看似已无力进攻，突然四肢用力一扒已窜到$n跨下，两手猛的上戳，好一式「精疲力尽」",
        "force" : 220,
        "dodge" : 10,
        "lvl" : 20,
        "skill_name" : "精疲力尽",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N两手高高举起，运掌如风，一式「壮士断腕」，闭眼就朝$n的下体砍去",
        "force" : 260,
        "dodge" : 15,
        "lvl" : 35,
        "skill_name" : "壮士断腕",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一跃而起，直往$n的双肩落下，双腿盘住$n的颈部，一扭腰，双手成关门之势，往$n的裆部狠狠拍去，正是一式「落叶归根」",
        "force" : 300,
        "dodge" : 19,
        "lvl" : 48,
        "skill_name" : "落叶归根",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使一式「空前绝后」，身形一分为二，四只手掌有如熊掌般朝$n的后腰和裆部拍去",
        "force" : 360,
        "dodge" : 22,
        "lvl" : 56,
        "skill_name" : "空前绝后",
        "damage_type" : "内伤"
]),
([      "action" : "$N全身关节啪啪作响，面如白纸，一式「断子绝孙」，无数鹰爪抓向$n全身要害，瞬间无数鹰爪又合为一爪直往$n的裆部抓落",
        "force" : 440,
        "dodge" : 25,
        "lvl" : 80,
        "skill_name" : "断子绝孙",
        "damage_type" : "抓伤"
])
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_combine(string combo) { return combo=="wudang-quan"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练三阴绝户手必须空手。\n");
        if ((int)me->query_skill("yinyun-ziqi", 1) < 40)
                return notify_fail("你的氤氲紫气火候不够，无法学三阴绝户手。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练三阴绝户手。\n");
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
        level   = (int) me->query_skill("juehu-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练三阴绝户手。\n");
        me->receive_damage("jingli", 25);
        me->add("shen", -10);
        me->add("neili", -10);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"juehu-shou/" + action;
}
