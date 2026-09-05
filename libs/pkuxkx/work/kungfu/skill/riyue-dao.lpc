//riyue-dao 日月刀法

inherit SKILL;

mapping *action = ({
([      "action" : "$N展身虚步，提腰跃落，一招「浩月当空」，刀锋一提，向$n的脑袋直斩下来",
        "force" : 140,
        "dodge" : -5,
        "damage" : 55,
         "lvl" : 0,
        "skill_name" : "浩月当空",
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「阳春三月」，$w左右纷飞，斜斜地劈向$n",
        "force" : 160,
        "dodge" : 5,
        "damage" : 80,
        "lvl" : 24,
        "skill_name" : "阳春三月",
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「斗转星移」，$w飘飘乎乎，让$n把握不住去向，突然刀势一变，砍向$n的胸口",
        "force" : 180,
        "dodge" : 10,
        "damage" : 135,
        "lvl" : 33,
        "skill_name" : "斗转星移",
        "damage_type" : "割伤"
]),
([      "action" : "$N挥舞$w，使出一招「天地乍合」，上劈下撩，左挡右开，齐齐罩向$n",
        "force" : 210,
        "dodge" : 15,
        "damage" : 145,
        "lvl" : 42,
        "skill_name" : "天地乍合",
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「霜色满地」，左膝微屈，$w顺势下撩，挟风声劈向$n的$l",
        "force" : 240,
        "dodge" : 5,
        "damage" : 160,
        "lvl" : 51,
        "skill_name" : "霜色满地",
        "damage_type" : "割伤"
]),
([      "action" : "$N就地盘身一转，一招「阳光普照」，挥出一片流光般的刀影，向$n的全身涌去",
        "force" : 280,
        "dodge" : 20,
        "damage" : 180,
        "lvl" : 60,
        "skill_name" : "阳光普照",
        "damage_type" : "割伤"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_combine(string combo) { return combo=="riyue-jian"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 50)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("riyue-shengong", 1) < 10)
                return notify_fail("你的日月神功火候太浅。\n");
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
        level   = (int) me->query_skill("riyue-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if ((string)me->query("family/family_name") != "日月神教" &&(string)me->query("chushi/last_family") != "日月神教")
		return notify_fail("你不是日月神教弟子，不能练日月刀法。\n");
	if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练日月刀法。\n");
        me->receive_damage("qi", 25);
        if ((int)me->query_skill("riyue-dao",1)>1000&&me->query("riyuepfm/dao"))
        {
            me->add("neili",-35);
        }
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"riyue-dao/" + action;
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

