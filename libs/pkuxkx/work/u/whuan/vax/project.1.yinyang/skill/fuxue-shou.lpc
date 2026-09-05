// fuxue-shou.c -兰花拂穴手

inherit SKILL;

mapping *action = ({
([      "action" : "$N一式「回风拂柳」，双手齐发，往$n的面门点去。然后手臂忽弯，嗖地一撩，右手猛地向$n推出",
        "force" : 100,
        "dodge" : 5,
        "parry" : 5,
        "damage": 5,
        "lvl" : 0,
        "skill_name" : "回风拂柳",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N右手挥出，使一式「巧扣连环」，拇指与食指扣起，余下三指略张，手掌如一枝兰花般伸出，点向$n，姿式美妙已极",
        "force" : 120,
        "dodge" : 15,
        "parry" : 5,
        "damage": 5,
        "lvl" : 19,
        "skill_name" : "巧扣连环",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N扭过身躯，向右避过，一式「推窗望月」，左手望外穿出，右手疾向$n的肩头点下",
        "force" : 140,
        "dodge" : 10,
        "parry" : 5,
        "damage": 5,
        "lvl" : 29,
        "skill_name" : "推窗望月",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N忽地左掌变爪，一式「偷天换日」，随手勾出，已向$n的左腕点去",
        "force" : 160,
        "dodge" : 10,
        "parry" : 10,
        "damage": 10,
        "lvl" : 39,
        "skill_name" : "偷天换日",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N猱身直进，一式「三彻连环」，砰砰砰，往$n的腰里连推三手，回手一翻，又击在$n的头上",
        "force" : 180,
        "dodge" : 5,
        "parry" : 5,
        "damage": 15,
        "lvl" : 49,
        "skill_name" : "三彻连环",
        "damage_type" : "瘀伤"
]),
 ([      "action" : "$N一招「双手移山」，左臂横扫，蓬的一声,双手忽地打出，直取$n的胸口",
        "force" : 200,
        "dodge" : 15,
        "parry" : 10,
        "damage": 10,
        "lvl" : 59,
        "skill_name" : "双手移山",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N挺前挂开，飞起右腿，一式「微风寻穴」，乘势撩向$n的双手",
        "force" : 250,
        "dodge" : 20,
        "parry" : 5,
        "damage": 15,
        "lvl" : 69,
        "skill_name" : "微风寻穴",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N下盘不动，上盘不避，一式「双蛟出洞」，将腰向左一挪，斗然跃开半尺，右手送出，点向$n的胸口",
        "force" : 280,
        "dodge" : 10,
        "parry" : 20,
        "damage": 20,
        "lvl" : 89,
        "skill_name" : "双蛟出洞",
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_combine(string combo) { return combo=="tanzhi-shengong"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练兰花拂穴手必须空手。\n");
                 if ((int)me->query_skill("luoying-xinfa", 1) < 10)
                return notify_fail("你的落英心法火候不够，无法学兰花拂穴手。\n");
        if ((int)me->query("max_neili") < 50)
                return notify_fail("你的内力太弱，无法兰花拂穴手。\n");
        return 1;
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
        level   = (int) me->query_skill("fuxue-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练兰花拂穴手。\n");
        me->receive_damage("qi", 25);
        me->add("neili", -10);
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
        return __DIR__"fuxue-shou/" + action;
}

string query_yinyang()
{
	return "少阴";
}
