// dagou-bang.c
// write by Xiang
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": "$N使出一招「棒打双犬」，手中$w化作两道青光砸向$n的$l",
	"force":  20,
        "dodge":  10,
        "damage": 50,
        "damage_type": "挫伤"
]),
([      "action": "$N手中$w左右晃动，一招「拨草寻蛇」向$n的$l攻去",
        "force":  40,
        "dodge":  20,
        "damage": 60,
        "damage_type": "挫伤"
]),
([      "action": "$N举起$w，居高临下使一招「打草惊蛇」敲向$n的$l",
        "force":  40,
        "dodge": 30,
        "damage": 80,
        "damage_type": "挫伤"
]),
([      "action": "$N施出「拨狗朝天」，$w由下往上向$n撩去",
	"force":  60,
        "dodge": 20,
        "damage": 100,
        "damage_type": "挫伤"
]),
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if (me->query("family/master_id") != "hong qigong")
            return notify_fail("你不是洪七公的弟子，无法学习打狗棒法。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        if (random(me->query_skill("staff")) > 60 &&
            me->query_skill("force") > 60 &&
            me->query("neili") > 100 &&
            (string)weapon->query("id") == "yuzhu zhang" ) {
                me->add("neili", -100);
                return ([
                "action": HIG"$N眼中射出一道青芒，手中玉竹杖使出「天下无狗」，劈天盖地般攻向$n"NOR,
                "dodge":40,
                "damage": 500,
                "damage_type": "挫伤"]);
        }
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
                return notify_fail("你使用的武器不对。\n");
        if (me->query("family/master_id") != "hong qigong")
            return notify_fail("你不是洪七公的弟子，无法学习打狗棒法。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练打狗棒法。\n");
        me->receive_damage("qi", 40);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"dagou-bang/" + action;
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

string query_yinyang()
{
	return "太阳";
}