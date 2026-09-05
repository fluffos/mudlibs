// dashou-yin.c 密宗大手印
//  by iceland

inherit SKILL;

mapping *action = ({
([      "action" : "$N使出一招「莲花合掌印」，双掌合十，直直撞向$n的前胸",
        "skill_name" : "莲花合掌印",
        "force" : 100,
        "dodge" : 0,
        "parry" : 0,
        "lvl" : 0,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「合掌观音印」，飞身跃起，双手如勾，抓向$n的$l",
        "skill_name" : "合掌观音印",
        "force" : 150,
        "dodge" : 10,
        "parry" : 5,
        "lvl" : 8,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「准提佛母印」，运力于指，直取$n的$l",
        "skill_name" : "准提佛母印",
        "force" : 210,
        "dodge" : 15,
        "parry" : -5,
        "lvl" : 16,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「红阎婆罗印」，怒吼一声，一掌当头拍向$n的$l",
        "skill_name" : "红阎婆罗印",
        "force" : 260,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 24,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「药师佛根本印」，猛冲向前，掌如游龙般攻向$n",
        "skill_name" : "药师佛根本印",
        "force" : 300,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 32,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「威德金刚印」，伏身疾进，双掌自下扫向$n的$l",
        "skill_name" : "威德金刚印",
        "force" : 340,
        "dodge" : 8,
        "parry" : 0,
        "lvl" : 40,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「上乐金刚印」，飞身横跃，双掌前后击出，抓向$n的咽喉",
        "skill_name" : "上乐金刚印",
        "force" : 390,
        "dodge" : 10,
        "parry" : 5,
        "lvl" : 48,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「六臂智慧印」，顿时劲气弥漫，天空中出现无数掌影打向$n的$l",
        "skill_name" : "六臂智慧印",
        "force" : 450,
        "dodge" : 5,
        "lvl" : 56,
        "damage_type" : "瘀伤",
]),
});


int valid_enable(string usage) { return usage == "hand" || usage == "parry"; }

//int valid_combine(string combo) { return combo=="tianwang-zhua"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练密宗大手印必须空手。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱了，练不了密宗大手印。\n");
        if ((int)me->query_skill("longxiang-boruo", 1) < 20)
                return notify_fail("你的龙象般若功火候太浅，不能学密宗大手印。\n");
        if ((int)me->query_skill("force", 1) < 20)
                return notify_fail("你的基本内功火候太浅，不能学密宗大手印。\n");
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
        level   = (int) me->query_skill("dashou-yin",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
//      object weapon;

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练密宗大手印必须空手。\n");
        if ((int)me->query("qi") < 40)
                return notify_fail("你的体力不够，练不了密宗大手印。\n");
        if ((int)me->query("neili") < 40)
                return notify_fail("你的内力不够，练不了密宗大手印。\n");
        me->receive_damage("qi", 20);
        me->add("neili", -5);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"dashou-yin/" + action;
}



