// liaoyuan-qiang.c
// by kuer

inherit SKILL;

mapping *action = ({
([      "action": "$N微一凝神，双手执$w，$w破空如电，直挑$n的$l",
        "dodge": -5,
        "parry": -5,
        "damage": 80,
        "force":  200,
        "damage_type": "刺伤"
]),
([      "action": "$N手中$w一晃$n的面门，招术突变向$n的$l刺去",
        "dodge": 0,
        "parry": 0,
        "damage": 90,
        "force":  300,
        "damage_type": "刺伤"
]),
([      "action": "$N一抖手中的$w，枪尖在空中划出一个浅浅的弧度,向$n的$l刺去",
        "dodge": 0,
        "parry": 5,
        "damage": 100,
        "force":  400,
        "damage_type": "刺伤"
]),
([      "action": "$N双手运枪，你忽觉满天枪影，分辨不出虚实，急忙后退数步",
        "dodge": 10,
        "parry": 10,
        "damage": 80,
        "force":  300,
        "damage_type": "刺伤"
]),
([      "action": "$N突然后退数步，转身之间反手出枪，长枪破空如电，毫无花巧的直刺你的前心",
        "dodge": 20,
        "parry": 20,
        "damage": 150,
        "force":  500,
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
                return notify_fail("你的体力不够练「燎原枪法」。\n");
        me->receive_damage("qi", 40);
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
