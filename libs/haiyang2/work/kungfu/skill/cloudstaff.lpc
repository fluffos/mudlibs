// cloudstaff.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N使一招「天光乍现」，手中$w扫向$n下盘！",
                "damage":               40,
                "dodge":                40,
                "parry":                -40,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N挥起$w，一招「雨後初晴」攻向$n$l！",
                "damage":               40,
                "dodge":                20,
                "parry":                60,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N横过手中$w，使出「浮云写意」击向$n$l！",
                "damage":               40,
                "dodge":                10,
                "parry":                40,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N使出一招「游龙穿云」，$w一挺撞向$n$l！",
                "damage":               40,
                "dodge":                10,
                "parry":                40,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
});

int valid_learn(object me)
{
        if( (int)me->query("str") + (int)me->query("max_neili") / 10 < 35 )
                return 
notify_fail("你的膂力还不够，也许该练一练内力来增强力量。\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="staff") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "staff" )
                return 
notify_fail("你必须先找一根木杖或者是类似的武器，才能练杖法。\n");

        if( (int)me->query("qi") < 60 )
                return 
notify_fail("你的体力不够练这门杖法，还是先休息休息吧。\n");
        me->receive_damage("qi", 60);
        return 1;
}
int effective_level() { return 20;}
 
string *parry_msg = ({
        "结果$n用手中的$v格开了$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
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
	return 20;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return 40;
}


string perform_action_file(string action)
{
        return __DIR__"cloudstaff/" + action;
}