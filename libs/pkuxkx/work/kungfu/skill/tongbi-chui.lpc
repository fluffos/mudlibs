//通臂锤
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action":HIB"$N"+HIB"深吸一口气提起$w"+HIB"以浑厚之力向前平平送出！$n"+HIB"顿觉一阵强劲之力向自己面部袭来。"NOR,
        "force" : 220,
        "dodge" : 0,
        "damage": 5,
        "lvl" : 0,
        "weapon" : "左手手掌",
        "damage_type":  "淤伤"
]),
([      "action":HIR"$N"+HIR"使足力气将$w"+HIR"在天空轮了一个圈，然后一侧身，$w"+HIR"便直奔$n"+HIR"太阳穴而去!"NOR,
        "force" : 240,
        "dodge" : 0,
        "damage": 5,
        "lvl" : 40,
	"weapon" : "右手",
        "damage_type":  "淤伤"
]),
([      "action":HIG"$N"+HIG"突然一声暴喝，$w"+HIG"在其手中越转越快，越转越怪，突然就向$n"+HIG"的腰部砸去!"NOR,
        "force" : 260,
        "dodge" : 0,
        "damage": 10,
        "lvl" : 80,
	"weapon" : "右手手掌",
        "damage_type":  "淤伤"
]),
([      "action":HIW"$N"+HIW"突然纵身跃起，手中$w"+HIW"却是快似流星，捷如闪电，朝$n"+HIW"当空砸下!"NOR,
        "force" : 500,
        "dodge" : 0,
        "damage": 15,
        "lvl" : 100,
	"weapon" : "右手",
        "damage_type":  "淤伤"
]),
});


int valid_enable(string usage) 
{ 
    return usage == "hammer" || usage == "parry"; 
}  

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	return 1;
}

   //          int valid_combine(string combo) { return combo=="xiake-jianfa"; }
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
        level   = (int) me->query_skill("tongbi-chui",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string perform_action_file(string action)
{
        return __DIR__"tongbi-chui/" + action;
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
return notify_fail("通臂锤法只能用学(learn)的来增加熟练度。\n");
}

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}


