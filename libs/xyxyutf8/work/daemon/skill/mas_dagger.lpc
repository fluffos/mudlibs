// Mas_dagger.c 大师匕首
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
              (["action":               HIW"$N一招「"+HIC"削苹果式"+HIW"」，身形陡然加快，手中$w斩向$n的$l"NOR,
                "dodge":                -60,
                "parry" :               -30,
                "damage" :              50,
                "damage_type":  "割伤"
                ]),
                (["action":             HIW"$N一式「"+HIC"见缝插针"+HIW"」，手中$w如一条银蛇般刺向$n的$l"NOR,
                "dodge":                -70,
                "parry" :               -40,
                "damage":               80,
                "damage_type":  "刺伤"
                ]),
                (["action":             HIW"$N使出「"+HIC"图穷见匕"+HIW"」，手中$w霍霍斩向$n"NOR,
                "dodge":                -80,
                "parry" :               -50,
                "damage" :              100,
                "damage_type":  "割伤"
                ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query_skill("add_dagger",1) < 200 )
        return notify_fail("你的匕首刺杀之术还没有一定的火候，无法学会大师匕首。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "dagger" )
                return notify_fail("你必须先找一把匕首才能练大师匕首。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="dagger" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
     	int i;
        i=me->query_temp("mas_d");
        if( !me->query_temp("mas_d") ) 
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
notify_fail("你的内力或气不够，没有办法练习大师匕首。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
          if ( flag )  write("你按著所学练了一遍大师匕首。\n");
        return 1;
}

string perform_action_file(string func)
{
return CLASS_D("firemagic") + "/mas_dagger/" + func;
}


