
inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N使一招「飘飘步履九疑峰」，手中$w如一风一般卷向$n的$l",
                "dodge":                -20,
                "damage":               90,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N使出碧月剑中的「烟细浮蓝径不封」，剑光向残照般洒向$n的$l",
                "dodge":                -20,
                "damage":               90,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N一招「指点林霏非近市」，手中$w默默的削向$n的$l",
                "dodge":                -30,
                "damage":               80,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w一式「分明仙艳好寻踪」对准$n的$l一连刺出七剑",
                "damage":                90,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N的$w凭空一指，一招「为怜香断笼纱浅」刺向$n的$l",
                "dodge":                20,
                "damage":               50,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手中$w向外一分，使一招「小障春寒着月浓」反手对准$n$l一剑刺去",
                "dodge":                -20,
                "damage":               70,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练碧月剑法。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 5 )
                return 
notify_fail("你的内力或气不够，没有办法练习碧月剑法。\n");
        me->receive_damage("kee", 50);
        me->add("force", -5);
        write("你按著所学练了一遍碧月剑法。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("legend") + "/deisword/" + action;
}
 
int effective_level() { return 10;}

string *parry_msg = ({
        "$n使出一招「领袖仲芳清韵远」，手中的$v荡开了$N的$w。\n",
        "$n使出「回看九点百花丛」，将$N的$w封于丈外。\n",
        "$n使出一招「轻黄淡白总含羞」，手中的$v化做漫天残照，荡开了$N的$w。\n",
        "$n手中的$v一抖，一招「量空金栗知难买」，向$N拿$w的手腕削去。\n",
});

string *unarmed_parry_msg = ({
        "$n将手中的$v舞得密不透风，一招「击碎珊瑚惜未收」封住了$N的攻势。\n",
        "$n反手一招「仙友自传丹灶术」，整个人消失在一团剑光之中。\n",
        "$n使出一招「状元须作锦衣游」，$v直刺$N的双手。\n",
        "$n将手中的$v一抖，一招招「一枝拟向嫦娥乞」，迫得$N连连后退。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
	return 10;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return 20;
}

