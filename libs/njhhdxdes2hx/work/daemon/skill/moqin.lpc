// moqin.c

inherit SKILL;

mapping *array_action= ({
		([		"action":
"$N1的$w1自上而下，$N2的$w2自下而上，组成了一道声网，罩向$n的$l",
				"dodge":		300,
				"parry":		300,
				"damage":		900,
				"damage_type":	"割伤",
		]),
});
mapping *action = ({
        ([      "action":               
"$N弹出「八音穿心」，琴声如急风一般卷向$n的$l",
                "dodge":                -20,
                "damage":               900,
                "damage_type":  "重伤"
        ]),
        ([      "action":               
"$N使出魔琴神功中的「夺命弦」，琴声如潮水般涌向$n的$l",
                "dodge":                -20,
                "damage":               900,
                "damage_type":  "重伤"
        ]),
        ([      "action":               
"$N的$w弹出「索命七弦」琴声如剑刺向$n的$l",
                "dodge":                20,
                "damage":               900,
                "damage_type":  "重伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够，没有办法练琴。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "music" )
                return notify_fail("你必须先找一把琴才能练魔琴神功。\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="music") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
mapping query_array_action(object me, object weapon)
{
        return array_action[random(sizeof(array_action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 300
        ||      (int)me->query("force") < 300 )
                return 
notify_fail("你的内力或气不够，没有办法练琴。\n");
        me->receive_damage("kee", 300);
        me->add("force", -3);
        write("你按著所学练了一遍琴。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("legend") + "/music/" + action;
}
 
int effective_level() { return 10;}

string *parry_msg = ({
        "$n弹出「百瀑飞泻」，琴声象一堵墙荡开了$N的$w。\n",
        "$n弹出「迷仙神音」，将$N的$w封于丈外。\n",
        "$n弹出「彩霞满天」，琴声化做漫天残照，荡开了$N的$w。\n",
        "$n手中的$v弹出「断臂弦」，一道白光向$N拿$w的手腕削去。\n",
});

string *unarmed_parry_msg = ({
        "$n将手中的$v弹得密不透风，弹出「百音绕梁」封住了$N的攻势。\n",
        "$n弹出「迷雾弦」，整个人消失在一团雾中。\n",
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

