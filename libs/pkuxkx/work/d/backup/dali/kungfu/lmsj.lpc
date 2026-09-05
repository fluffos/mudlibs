// /d/dali/kungfu/liumai-shenjian.c 六脉神剑

inherit SKILL;

mapping *action = ({
([      "action" : "$N使出一招少泽剑, 左手小指向$n的$l一指，一条气流从少冲穴中激射线而出刺出一剑，所刺之出令人出乎意料。",

        "force" : 200,
        "dodge" : 50,
        "damage" : 100,
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出一招中冲剑, 左手中指一竖, 中冲剑向前刺向$n的$l",
        "force" : 200,
        "dodge" : 50,
        "damage" : 100,
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      "action" : "$N食指伸处，使出一招商阳剑, 一转向$n的$l挥去。",
        "force" : 200,
        "dodge" : 50,
        "damage" : 100,
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      "action" : "$N小指一弹，使出一招和冲剑，直刺$n的$l",
        "force" : 200,
        "dodge" : 50,
        "damage" : 100,
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出一招关冲剑，剑锋直向$n的$l刺去。",
        "force" : 200,
        "dodge" : 50,
        "damage" : 100,
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      "action" : "$N反过手来，双手拇指同时捺出，使出一招少商剑, 嗤嗤两声急响，分别刺向$n的右胸左肩",
        "force" : 300,
        "dodge" : 70,
        "damage" : 120,
        "lvl" : 40,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return usage == "finger" || usage == "parry"; }

int valid_learn(object me)
{
//        if ((string)me->query("family/master_id")!="feng qingyang")
//                return notify_fail("独孤九剑只能向风清扬学。\n");
        if ((int)me->query("max_neili") < 300)
                return notify_fail("你的内力不够。\n");
        return 1;
}



mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("liumai-shenjian", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                          return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "finger")
                return notify_fail("你必需空手。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够。\n");
        me->receive_damage("qi", 30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"liumai-shenjian/" + action;
}

string *parry_msg = ({
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
