//开天剑法
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action":HIB"$N"+HIB"伸出手掌以气运剑，双手上下翻飞，$w"+HIB"已在一瞬间向$n"+HIB"攻出十几个剑招!。"NOR,
        "dodge" : 10,
        "damage": 6,
        "lvl" : 0,
        "weapon" : "左手手掌",
        "damage_type":  "刺伤"
]),
([      "action":HIR"$N"+HIR"将双手藏与袖中，以气御剑与无形！$w"+HIR"在$n"+HIR"面前分分合合，让$n"+HIR"难以捉摸!."NOR,
        "dodge" : 40,
        "damage": 8,
        "lvl" : 40,
	"weapon" : "右手",
        "damage_type":  "刺伤"
]),
([      "action":HIG"$w"+HIG"在"+"$N"+HIG"双手之间纵向旋转，而且越转越快，好像在蓄积能量一般！\n$n"+HIG"正在诧异，$w"+HIG"凌厉的剑锋突然向$n"+HIG"的$l重重刺去！"NOR,
       "dodge" : 55,
       "damage": 10,
        "lvl" : 80,
	"weapon" : "右手手掌",
        "damage_type":  "刺伤"
]),
([      "action":HIW"$N"+HIW"运起开天心法与剑合为一体，$w"+HIW"通体发出红色光芒，使出开天剑法的无上绝招－劈地开天！$w\n"+HIW"急射向$n"+HIW"的$l!"NOR,
        "dodge" : 80,
        "damage": 35,
        "lvl" : 100,
	"weapon" : "右手",
        "damage_type":  "刺伤"
]),
});


int valid_enable(string usage) 
{ 
    return usage == "sword" || usage == "parry"; 
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
        level   = (int) me->query_skill("kaitian-jianfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string perform_action_file(string action)
{
        return __DIR__"kaitian-jianfa/" + action;
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
return notify_fail("开天剑法只能用学(learn)的来增加熟练度。\n");
}

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}


