//古刺客匕法
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action":HIB"$N"+HIB"身形一晃，已到$n"+HIB"身前！手中$w"+HIB"已经向$n"+HIB"的$l狠狠地刺了过去！"NOR,
        "dodge" : 10,
        "damage": 5,
        "lvl" : 0,
        "weapon" : "左手手掌",
        "damage_type":  "刺伤"
]),
([      "action":HIR"$N"+HIR"惨然一笑，反守为攻，$w"+HIR"顺势向"+"$n"+HIR"咽喉滑去."NOR,
        "dodge" : 40,
        "damage": 5,
        "lvl" : 40,
	"weapon" : "右手",
        "damage_type":  "刺伤"
]),
([      "action":HIG"$N"+HIG"口中吟道：“风萧萧兮易水寒！”整个身体突然向$n"+HIG"扑去，手中$w"+HIG"直插$n"+HIG"的$l!"NOR,
        "dodge" : 55,
       "damage": 20,
        "lvl" : 80,
	"weapon" : "右手手掌",
        "damage_type":  "刺伤"
]),
([      "action":HIW"突然间$N"+HIW"手中$w"+HIW"在空中急画了一个弧线，加杂着浑厚的内力向$n"+HIW"刺去。"NOR,
        "dodge" : 8,
        "damage": 25,
        "lvl" : 100,
	"weapon" : "右手",
        "damage_type":  "刺伤"
]),
});


int valid_enable(string usage) 
{ 
    return usage == "dagger" || usage == "parry"; 
}  

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	return 1;
}

  //         int valid_combine(string combo) { return combo=="xiake-daofa"; }
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
        level   = (int) me->query_skill("cike-bi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string perform_action_file(string action)
{
        return __DIR__"cike-bi/" + action;
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
return notify_fail("古刺客匕法只能用学(learn)的来增加熟练度。\n");
}

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}


