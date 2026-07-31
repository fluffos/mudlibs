// Add_dagger.c 进阶匕首
// Cracked by 凌惊雪 6-1-2003

#include <ansi.h>
inherit SKILL;

mapping *action = ({
                (["action":             "$N身形一转，手中的$w从左肋下向$n的$l戳了过去",
                "dodge":                -20,
                "parry" :               -20,
                "damage":               70,
                "damage_type":  "刺伤"
                ]),
                (["action":             "$N手中$w寒光暴长，如千年蛇蝎往$n$l咬去",
                "dodge":                -30,
                "parry" :               -20,
                "damage":               100,
                "damage_type":  "割伤"
                ]),
                (["action":             "$N手中的$w以无法形容的速度直射$n的$l",
                "dodge":                -20,
                "parry" :               -30,
                "damage":               80,
                "damage_type":  "刺伤"
                ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 200 )
        return notify_fail("你的内力不够，没有办法练进阶匕首。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "dagger" )
                return notify_fail("你必须先找一把匕首才能练进阶匕首。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="dagger" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
     int i;
        i=me->query_temp("add_d");
        if( !me->query_temp("add_d") ) 
        {
        	return action[random(sizeof(action))];
        }
        else {
        return action[i];
        }
}

varargs int practice_skill(object me,int flag)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return 
notify_fail("你的内力或气不够，没有办法练习进阶匕首。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
         if ( flag ) write("你按著所学练了一遍进阶匕首。\n");
        return 1;
}

string perform_action_file(string func)
{
return CLASS_D("firemagic") + "/add_dagger/" + func;
}


