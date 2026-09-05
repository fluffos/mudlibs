// gehu-ji 格虎戟
// Zine 2013

inherit SKILL;
#include <ansi.h>
#include <combat.h>
mapping *action = ({
([      "action": "$N一抖手中$w，连成一片，兜向$n的$l",
        "dodge": -50,
        "damage": 140,
        "parry":  100,
        "damage_type": "砸伤"
]),
([      "action": "$N手中$w一晃$n的面门，招术突变向$n的下腹刺去",
        "dodge": -50,
        "damage": 180,
        "parry":  150,
        "damage_type": "刺伤"
]),
([      "action": "$N手中$w虚晃，从一个腋下反刺向$n的$l",
        "dodge": -50,
        "damage": 240,
        "parry":  200,
        "damage_type": "刺伤"
]),
([      "action": "$N一跃而起，$w直劈，从空中直挑$n的$l",
        "dodge": -50,
        "damage": 280,
        "parry":  250,
        "damage_type": "劈伤"
]),
});

mapping query_action(object me, object weapon)
{
	mapping ran_action;
	int level = me->query_skill("gehu-ji",1);
	if (objectp(weapon = me->query_temp("weapon"))&&(string)weapon->query("skill_type") == "axe")
	{
		if (level > 100) level = 100;
		if (me->query_temp("sum_power"))
		return 
		([  "action": "$N将斧缓缓提到胸前，神色沉重地施出「"+RED+"雷霆震天"+NOR+"」劈向$n的$l",
                    "damage": level*6,
                    "attack": level*2,
                    "dodge": 0 - 5 * level,
                    "damage_type": "劈伤",
        ]);
		else
		{
			ran_action=action[random(sizeof(action))];
			ran_action["dodge"]= 0 - level;
			ran_action["damage"]= level;
			ran_action["attack"]= level/2;
			ran_action["post_action"]=(: call_other, WEAPON_D, "bash_weapon" :);
		}
		return ran_action;
	}
	else
	return action[random(sizeof(action))];

}

int valid_enable(string usage) { return (usage == "halberd") || (usage == "parry")||(usage=="axe"); }

int valid_learn(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || ((string)weapon->query("skill_type") != "halberd"&&(string)weapon->query("skill_type") != "axe"))
                return notify_fail("你使用的武器不对。\n");
        return 1;
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || ((string)weapon->query("skill_type") != "halberd"&&(string)weapon->query("skill_type") != "axe"))
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                 return notify_fail("你的体力不够练「格虎戟法」。\n");
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
string perform_action_file(string action)
{
                return __DIR__"gehu-ji/" + action;
}
