// lujia-ji.c
// modified by vast, hehe, 随便找了首诗

inherit SKILL;

mapping *action = ({
([      "action": "$N一抖手中$w，戟头舞成一片，一招「前不见古人」刺向$n的$l",
        "dodge": -50,
        "damage": 140,
        "parry":  100,
	"skill_name" : "前不见古人",
        "damage_type": "刺伤"
]),
([      "action": "$N手中$w一晃$n的面门，使出「后不见来者」，招术突变向$n的下腹刺去",
        "dodge": -50,
        "damage": 180,
        "parry":  150,
	"skill_name" : "后不见来者",
        "damage_type": "刺伤"
]),
([      "action": "$N手中$w虚晃，一招「念天地之悠悠」，从一个不可思议的角度刺向$n的$l",
        "dodge": -50,
        "damage": 240,
        "parry":  200,
	"skill_name" : "念天地之悠悠",
        "damage_type": "刺伤"
]),
([      "action": "$N一跃而起，一招「独怆然而涕下」$w从空中直指$n的$l",
        "dodge": -50,
        "damage": 280,
        "parry":  250,
	"skill_name" : "独怆然而涕下",
        "damage_type": "刺伤"
]),
});

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int valid_enable(string usage) { return (usage == "halberd") || (usage == "parry"); }

int valid_learn(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "halberd")
                return notify_fail("你使用的武器不对。\n");
        return 1;
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "halberd")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                 return notify_fail("你的体力不够练「吕家戟法」。\n");
        me->receive_damage("qi", 25);
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
