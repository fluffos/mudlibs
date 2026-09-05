// /d/dali/kungfu/liumai-shenjian.c 六脉神剑
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : RED"   

   Ο       Ο    
   │++++ --│    
   │       │  
   │       │ "NOR,

        "force" : 200,
        "dodge" : 50,
        "damage" : 200,
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      "action" : RED"
	Ο       Ο    
        │++++ --│    
        │       │  
        │       │NOR ",
        "force" : 200,
        "dodge" : 50,
        "damage" : 200,
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      "action" : YEL"
   Ο       Ο    
   │++++ --│    
   │       │  
   │       │ "NOR,
        "force" : 200,
        "dodge" : 50,
        "damage" : 200,
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      "action" : YEL"
   Ο       Ο    
   │++++ --│    
   │       │  
   │       │ "NOR,
        "force" : 200,
        "dodge" : 50,
        "damage" : 200,
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      "action" : RED"
   Ο       Ο    
   │++++ --│    
   │       │  
   │       │ "NOR,
        "force" : 200,
        "dodge" : 50,
        "damage" : 200,
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      "action" : RED" 
   Ο       Ο    
   │++++ --│    
   │       │  
   │       │ "NOR,
        "force" : 300,
        "dodge" : 70,
        "damage" : 300,
        "lvl" : 50,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return usage == "sword"; }

int valid_learn(object me)
{

        if ((int)me->query("max_neili") < 300)
                return notify_fail("你的内力不够。\n");
        return 1;
}



mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("yuer-jian", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                          return action[NewRandom(i, 20, level/2)];

}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练剑法。\n");
	me->receive_damage("qi", 30);
	return 1;
}


string *parry_msg = ({
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
