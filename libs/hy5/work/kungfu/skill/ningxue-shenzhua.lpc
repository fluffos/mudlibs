// ningxue-shenzhua.c 凝血神抓

#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action": "$N双掌平平提到胸前，神色沉重的缓缓施出"+(order[random(13)])+"「苍龙探爪」"NOR"抓向$n的$l",
        "dodge": 10,
        "parry": 50,
        "force": 100,
        "damage": 100,
        "lvl" : 0,
        "damage_type": "瘀伤"
]),
([      "action": "$N突然身形飞起，双手居高临下一招"+(order[random(13)])+"「飞鹰拨兔」"NOR"抓向$n的$l",
        "dodge": 15,
        "parry": 50,
        "force": 150,
        "damage": 200,
        "lvl" : 20,
        "damage_type": "瘀伤"
]),
([      "action": "$N右手一招"+(order[random(13)])+"「黑虎掏心」"NOR"，迅捷无比地抓向$n的$l",
        "dodge": 10,
        "parry": 50,
        "force": 200,
        "damage": 300,
        "lvl" : 40,
        "damage_type": "瘀伤"
]),
([      "action": "$N双手施出一招"+(order[random(13)])+"「泰山压顶」"NOR"，隐隐带着风声抓向$n的$l",
        "dodge": 10,
        "parry": 50,
        "force": 200,
        "damage": 400,
        "lvl" : 100,
        "damage_type": "瘀伤"
]),
([      "action": "$N左手聚成虎爪状，右手一招"+(order[random(13)])+"「凝血神抓」"NOR"缓缓抓向$n的$l",
        "dodge": 10,
        "parry": 50,
        "force": 300,
        "damage": 400,
        "lvl" : 200,
        "damage_type": "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry" ||  usage=="unarmed"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练凝血神抓必须空手。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练凝血神抓。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("jing") < 100)
                return notify_fail("你的精力不够练此武功。\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("你的体力不够练此武功。\n");
        if ((int)me->query("neili") < 100)
                return notify_fail("你的内力不够练此武功。\n");
        me->receive_damage("qi", 50);
        me->receive_damage("jing", 50);
        me->add("neili", -50);

        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"ningxue-shenzhua/" + action;
}

string *parry_msg = ({
        "只听见"+(order[random(13)])+"「锵」"NOR"一声，被$p格开了。\n",
        "结果"+(order[random(13)])+"「当」"NOR"地一声被$p挡开了。\n",
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

