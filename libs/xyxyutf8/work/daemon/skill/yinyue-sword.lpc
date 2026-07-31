// yinyue-sword.c
//not used, set to default first.

#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "阴月狂舞",
                "action":
"$N使一招「阴月狂舞」，手中$w狂风骤雨般地向$n的$l连攻数剑",
                "dodge":                0,
                "damage":               20,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "天魔附身",
                "action":               "$N身形一转，一招「天魔附身」$w斩向$n的$l",
                "dodge":                0,
                "damage":               20,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "直冲云霄",
                "action":
"$N舞动$w，一招「直冲云霄」挟着闪闪剑光刺向$n的$l",
                "dodge":                0,
                "damage":               20,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "六道入魔",
                "action":
"$N手中$w一抖，使出「六道入魔」往$n的$l刺出一剑",
                "dodge":                0,
                "damage":               20,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "魔影幢幢",
                "action":
"$N手中$w剑光暴长，一招「魔影幢幢」往$n$l刺去",
                "dodge":                0,
                "damage":               20,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "阴月剑典",
                "action":
"$N手中$w直指$n$l，一招「阴月剑典」发出逼人剑气刺去",
                "dodge":                0,
                "damage":               20,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 1000 )
                return notify_fail("你的内力不够，没有办法练阴月魔魂剑。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练阴月魔魂剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

varargs int practice_skill(object me,int flag)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习阴月魔魂剑法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -100);
if ( flag )        write("你按着所学练了一遍阴月魔魂剑法。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
        if( (int)me->query_skill("six-chaos-sword", 1)  % 10 == 0 ) {
                tell_object(me,
                        RED "\n你突然觉得一股恶气冲上心头，只觉得想杀人....\n\n" NOR);
                me->add("bellicosity", 300);
        } else
                me->add("bellicosity", 50);
}
string perform_action_file(string func)
{
return CLASS_D("shushan") + "/yinyue-sword/" + func;
}

