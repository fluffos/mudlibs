//ephq
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N一式"HIC"「电闪雷动」"NOR"，剑走中锋，气势威严，将$n笼罩于重重剑气之中",
        "damage" : 30,
        "damage_type" : "刺伤"
]),
([      "action" : "$N双手持剑，将$w当做刀使，一招"HIR"「举火烧天」"NOR"，由身后向$n的前上方劈去",
        "damage" : 25,
        "damage_type" : "劈伤"
]),
([      "action":"$N手中$w一抖，一招"HIR"「日在九天」"NOR"，剑身像车轮一样旋转，同时反射日光，散发出
万道光芒，令$n难以视物，而剑光已闪电般的刺到",
        "damage": 40,
        "skill_name" : "日在九天",
        "damage_type":  "刺伤"
]),
([      "action":"$N一式"HIR"「火麟蚀日」"NOR"，剑网如虹，凌厉剑气利可断金，把$n周遭方圆两丈的土地悉
数切割至四分五裂，霎时间砂石乱飞，剑网俨如匹练，团团把$n紧裹其中",
        "damage": 25,
        "skill_name" : "火麟蚀日",
        "damage_type":  "刺伤"
]),
([      "action" : "$N向上高高跃起，一式"HIR"「炎破天地」"NOR"，举剑直刺，
在$n周围两丈之内，都是炙人的刀气，连空气都几乎要着火燃烧了",
        "damage_type" : "割伤",
        "damage": 25,
        "skill_name" : "炎破天地"
]),
([      "action":"$N错步上前，使出"HIC"「闪电惊虹」"NOR"，手中$w划出一道剑光劈向$n的$l",
        "damage": 30,
        "skill_name" : "闪电惊虹",
        "damage_type":  "割伤"
])
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        object ob;

       if( me->query("gender") != "男性" )  
                return notify_fail("雷炎剑只有男子能学。\n"); 
//       if (me->query("betray/count")) 
//            return notify_fail("你求学之心不专，无缘学雷炎剑。\n");
       if(me->query("family/family_name") != "娥眉")
            return notify_fail("这是仙家绝学,你是从什么地方偷学的呢?\n"); 
        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力不够，没有办法练雷炎剑法。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习雷炎剑法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍雷炎剑。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
string perform_action_file( string action)
{
return CLASS_D("emei") + "/leiyan-sword/" + action;
}
