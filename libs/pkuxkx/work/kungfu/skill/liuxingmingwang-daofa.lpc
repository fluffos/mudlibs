//流星冥王刀法
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action":HIB"$N"+HIB"将内力输入$w"+HIB"!刀风如流星般向$n"+HIB"各个方向急射而去!让人无法避开。"NOR,
        "damage": 6,
        "lvl" : 0,
        "weapon" : "左手手掌",
        "damage_type":  "刺伤"
]),
([      "action":HIR"$N"+HIR"将双手背于身后！闭住双眼以霸气御刀！$w"+HIR"在$n"+HIR"周身布下无数刀影！."NOR,
        "damage": 8,
        "lvl" : 40,
	"weapon" : "右手",
        "damage_type":  "刺伤"
]),
([      "action":HIG"$w"+HIG"突然如通灵一般，不随$N"+HIG"控制！\n刀身好像被某种神秘力量附了身一般，使出一招奇怪霸道的刀法，向$n"+HIG"的$l重重砍去!"NOR,
       "damage": 20,
        "lvl" : 80,
	"weapon" : "右手手掌",
        "damage_type":  "刺伤"
]),
([      "action":HIW"$N"+HIW"运起刀法之中的心法与刀魔合为一体，突然丧失心智!使出一招极其骇人的刀法不顾一切的向$n"+HIW"砍去!"NOR,
        "damage": 25,
        "lvl" : 100,
	"weapon" : "右手",
        "damage_type":  "刺伤"
]),
});


int valid_enable(string usage) 
{ 
    return usage == "blade" || usage == "parry"; 
}  

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力不够。\n");
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
        level   = (int) me->query_skill("liuxingmingwang-daofa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string perform_action_file(string action)
{
        return __DIR__"liuxingmingwang-daofa/" + action;
}
string *parry_msg = ({
        "只见$n将手中$v舞成一片，顿时格开了$N的$w。\n",
        "$n身子一侧，用手中$v轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
});

string *unarmed_parry_msg = ({
        "但是$n身子一侧，用左手轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
        "$n左手轻轻推出，拍向$N的$w，然后脚下一滑，身体向右一侧，避过了攻击。\n",
});

int practice_skill(object me)
{
return notify_fail("流星冥王刀法只能用学(learn)的来增加熟练度。\n");
}

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}


