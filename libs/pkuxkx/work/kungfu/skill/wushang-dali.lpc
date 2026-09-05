// wushang-dali.c 无上大力杵法
// by iceland

inherit SKILL;

mapping *action = ({
([  "action": "$N高举$w, 凝全身之力，一招「崩天柱」，照着$n劈头盖脸砸了下来，声势惊人！",
        "skill_name" : "崩天柱",        
        "force":160,
        "dodge": -8,
        "parry" : -10,
        "damage": 45,
        "lvl" : 0,
        "damage_type": "挫伤"
]),

([  "action": "$N使出一招「扳山式」,左手握住$w头回拉，右手在$w中间外推，呼的一声$w平扫向$n的$l",
        "skill_name" : "扳山式", 
        "force":200,
        "dodge": -5,
        "parry" : -5,
        "damage": 75,
        "lvl" : 29,
        "damage_type": "挫伤"
]),

([  "action": "$N奋平生之力，将$w舞的犹如屏风一般，密不透风，一招「荡乾坤」，慢慢向$n挤压过去。",
        "skill_name" : "荡乾坤", 
        "force":280,
        "dodge": -10,
        "parry" : 0,
        "damage": 100,
        "lvl" : 49,
        "damage_type": "淤伤"
]),

([  "action": "$N大吼一声“死！”，一招「风卷残云」,双手抱住$w一端，腰间发力抡了起来，将$n淹没在一片金光中。",
        "skill_name" : "风卷残云", 
        "force":380,
        "dodge": -10,
        "parry" : 5,
        "damage": 130,
        "lvl" : 69,
        "damage_type": "淤伤"
]),
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry")||(usage=="stick"); }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 200)
        return notify_fail("你的内力太弱，不能学习无上大力杵法。\n");
    if ((int)me->query("str") < 25)
        return notify_fail("你的膂力太低，不适合学习无上大力杵法。\n");
    if ((int)me->query_skill("longxiang-boruo", 1) < 35)
        return notify_fail("你的龙象般若功火候太浅。\n");    
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
        level   = (int) me->query_skill("wushang-dali",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        int lvl = me->query_skill("wushang-dali", 1);
        int i = sizeof(action);

        while (i--) if (lvl == action[i]["lvl"]) return 0;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
        return notify_fail("你练习着无上大力杵法，却感到武器太不对劲。\n");
        if ((int)me->query("qi") < 60)
        return notify_fail("你太累了，歇口气再练吧。\n");
              me->receive_damage("qi", 30);

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
