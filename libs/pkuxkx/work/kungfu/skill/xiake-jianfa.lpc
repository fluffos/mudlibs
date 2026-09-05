#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action":HIB"$N"+HIB"身形一晃，一招“赵客缦胡缨，吴钩霜雪明”，剑法之中当隐含吴钩之势，圆转如意。"NOR,
        "force" : 120,
        "dodge" : 20,
        "damage": 150,
        "lvl" : 0,
        "weapon" : "左手手掌",
        "damage_type":  "刺伤"
]),
([      "action":HIR"$N"+HIR"口中吟道：“十步杀一人，千里不留行”，$w"+HIR"向"+"$n"+HIR"咽喉点去."NOR,
        "force" : 140,
        "dodge" : 20,
        "damage": 250,
        "lvl" : 40,
	"weapon" : "右手",
        "damage_type":  "刺伤"
]),
([      "action":HIG"$w"+HIG"在"+"$N"+HIG"胸前划过一道弧线，一招“闲过信陵饮，脱剑膝前横”，向"+"$n"+HIG"重重击去。"NOR,
       "force" : 260,
        "dodge" : 15,
       "damage": 300,
        "lvl" : 80,
	"weapon" : "右手手掌",
        "damage_type":  "刺伤"
]),
([      "action":HIW"突然间$N"+HIW"身形左右摇摆，似是站立不稳，一招“三杯吐然诺，五岳倒为轻”，$w"+HIW"由上而下急射向$n。"NOR,
        "force" : 300,
        "dodge" : 5,
        "damage": 320,
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
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	return 1;
}

           int valid_combine(string combo) { return combo=="xiake-daofa"; }
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
        level   = (int) me->query_skill("xiake-jianfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string perform_action_file(string action)
{
        return __DIR__"xiake-jianfa/" + action;
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
return notify_fail("侠客剑法只能用学(learn)的来增加熟练度。\n");
}

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}


