// zhuihunduoming-jian.c 追魂夺命剑
// by hubo 2008-4-27

inherit SKILL;

mapping *action = ({
([      "action" : "$N使出一招“无常抖索”，所刺之出令人出乎意料。",

        "force" : 100,
        "dodge" : 30,
        "damage" : 200,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N向前跨上一步，一招“煞神当道”，令$n难以招架。",
        "force" : 150,
        "dodge" : 50,
        "damage" : 240,
        "lvl" : 9,
        "damage_type" : "刺伤"
]),
([      "action" : "$N转手使出一招“怨魂缠足”，挥剑砍向$n。",
        "force" : 180,
        "dodge" : 60,
        "damage" : 300,
        "lvl" : 29,
        "damage_type" : "砍伤"
]),
([      "action" : "$N又一招“庸医下药”，直刺$n的要害大穴。",
        "force" : 200,
        "dodge" : 70,
        "damage" : 300,
        "lvl" : 49,
        "damage_type" : "刺伤"
]),
([      "action" : "$N突然将$w抛向空中，来了一招“闯王掷笔”，直向对方刺去。",
        "force" : 240,
        "dodge" : 70,
        "damage" : 400,
        "lvl" : 69,
        "damage_type" : "刺伤"
]),
([      "action" : "$N身形急转，一招“勇者无惧”，$w从一个不可思意的角度刺向$n的$l",
        "force" : 280,
        "dodge" : 70,
        "damage" : 400,
        "lvl" : 89,
        "damage_type" : "刺伤"
]),
([  "action" : "$N回身拧腰，右手虚抱，一招“夺命追魂”，$w中宫直进，刺向$n的$l",
        "force" : 400,
        "dodge" : 70,
        "damage" : 500,
        "lvl" : 99,
        "damage_type" : "刺伤"
                             ]),
});


int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("zhuihunduoming-jian",1);
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
        if ((int)me->query("qi") < 50)
                 return notify_fail("你的体力不够练追魂夺命剑。\n");
        me->receive_damage("qi", 30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"zhuihunduoming-jian/" + action;
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

