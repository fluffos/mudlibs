// yangjia-qiang.c
// by ywt

inherit SKILL;

#include <ansi.h>
mapping *action = ({
([      "action": "$N一抖手中$w，枪头舞出一片枪花，刺向$n的$l",
        "dodge": 0,
        "damage": 40,
        "damage_type": "刺伤"
]),
([      "action": "$N手中$w一晃$n的面门，招术突变向$n的$l刺去",
        "dodge": 5,
        "damage": 45,
        "damage_type": "刺伤"
]),
([      "action": "$N运足精神，抖起$w，一招"+HIG"「拨草寻蛇」"NOR"刺向$n$l",
        "dodge": 5,
        "damage": 60,
        "damage_type": "刺伤"
]),
([      "action": "$N一个跨步，使一招"+BLINK""+HIC"「高山流水」"NOR"，手中$w势若飞瀑刺向$n的$l",
        "dodge": 5,
        "damage": 80,
        "damage_type": "刺伤"
]),
([      "action": "只见$N手腕一翻，手中$w从意想不到的角度刺向$n的$l。\n这一招"+BLINK""+HIB"「灵蛇出洞」"NOR"快若闪电，毒辣无比",
        "dodge": 5,
        "damage": 120,
        "damage_type": "刺伤"
]),
([      "action": "$N似欲退走，可是忽地一个转身，百忙中使出一招"+BLINK""+RED"「回马枪」"NOR"，$w一挺刺向$n$l",
        "dodge": 5,
        "damage": 200,
        "damage_type": "刺伤"
]),
});

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int valid_enable(string usage) { return (usage == "spear") || (usage == "parry"); }

int valid_learn(object me)
{
        return 1;
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "spear")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练「杨家枪法」。\n");
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
        return __DIR__"yangjia-qiang/" + action;
}

