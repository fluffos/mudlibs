#include <ansi.h>;
inherit SKILL;

mapping *action = ({
([  "action" : "\n$N一记勾拳，勾向$n的$l。\n",
        "force" : 420,
        "dodge" : 1000,
        "damage": 200,
        "damage_type" : "抓伤",
]),
([      "action" : "$N一记直拳，直捣$n的$l。",
        "force" : 420,
        "dodge" : 1000,
        "damage": 200,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一记摆拳，直摆$n的$l。",
        "force" : 420,
        "dodge" : 1000,
        "damage": 200,
        "damage_type" : "瘀伤"
]),
([      "action" : "\n$N一记重拳，击向$n的$l。",
        "force" : 420,
        "dodge" : 1000,
        "damage": 200,
                "damage_type" : "内伤"
]),
([      "action" : "$N一套组合拳，直攻$n的要害部位。",
        "force" : 420,
        "dodge" : 1000,
        "damage": 200,
        "damage_type" : "瘀伤",
]),
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"|| usage=="hand"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练拳击必须空手。\n");
        if ((int)me->query("max_force") < 200)
                return notify_fail("你的内力太弱，无法练拳击。\n");
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
        level = (int)me->query_skill("boxing", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("force") < 10)
                return notify_fail("你的内力不够练拳击。\n");
        me->receive_damage("kee", 15);
        me->add("force", -5);
        return 1;
}


mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        if( damage_bonus > 100 ) 
{
        victim->receive_wound("qi", damage_bonus );	
        victim->receive_wound("qi", damage_bonus );
        return HIR "光速拳!!一阵拳影！！！一股鲜血从$n的身子喷出\n" NOR;	
}
        if( damage_bonus < 75 ) 
{
        victim->receive_wound("qi", damage_bonus );	
        victim->receive_wound("qi", damage_bonus );	
        return YEL "光速拳!!一阵拳影！！！$n闷哼一声,身子晃了两晃！\n" NOR;
}
else
{       
        victim->receive_wound("qi", damage_bonus );	
        victim->receive_wound("qi", damage_bonus );	
        return HIM "光速拳!!一阵拳影！！！你听到「嗤啦」一声轻响，脸上竟溅到一些血滴！\n" NOR;
}

}
