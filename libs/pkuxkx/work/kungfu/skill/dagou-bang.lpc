// dagou-bang.c
// write by Xiang
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": "$N使出一招「棒打双犬」，手中$w化作两道青光砸向$n的$l",
	"force" : 40,
	"dodge" : 30,
        "damage" : 70+random(100),
        "damage_type": "挫伤"
]),
([      "action": "$N手中$w左右晃动，一招「拨草寻蛇」向$n的$l攻去",
	"force" : 60,
	"dodge" : 40,
        "damage" : 80+random(100),
        "damage_type": "挫伤"
]),
([      "action": "$N举起$w，居高临下使一招「打草惊蛇」敲向$n的$l",
	"force": 60,
	"dodge" : 50,
        "damage" : 100+random(100),
        "damage_type": "挫伤"
]),
([      "action": "$N施出「拨狗朝天」，$w由下往上向$n撩去",
	"force" : 80,
	"dodge" : 40,
        "damage" : 120+random(80),
        "damage_type": "挫伤"
]),
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if (me->query("family/master_id") != "hong qigong" && me->query("chushi/last_family")!="丐帮")
            return notify_fail("你不是洪七公的弟子，无法学习打狗棒法。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        if (random(me->query_skill("staff")) > 80 && random(10) == 0 &&
            me->query_skill("force") > 60 &&
            me->query("neili") > 100 &&
            (int)weapon->query("weapon_prop/damage") >=100 ) {
                me->add("neili", -50+random(50));
                return ([
                "action": HIG"$N"HIG"眼中青芒闪烁，手中$w"HIG"使出三十六路打狗棒法最后一招最后一变「天下无狗」\n只见铺天盖地都是$w"HIG"的影子，四面八方攻向$n，简直避无可避，挡无可挡！",
                "dodge":40,
                "damage": 300,
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
