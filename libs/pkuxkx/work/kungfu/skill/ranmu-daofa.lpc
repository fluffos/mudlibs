// ranmu-daofa.c 燃木刀法

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N面带微笑，一招「烈火烧身」，举$w对着$n连环砍了八八六十四刀，刀气纵横，宛如烈火般扑向$p，迅雷不可挡",
        "force" : 200,
        "dodge" : 5,
        "parry" : 0,         
        "damage" : 85,
        "lvl" : 0,
        "skill_name" : "烈火烧身",
        "damage_type" : "割伤"
]),
([      "action" : "$N运起内功一招「点木生火」，在$w上带出火红的无比劲气，迅速划了一个大弧，从上而下劈向$n的$l",
        "force" : 300,
        "dodge" : 0,
        "parry" : -5,
        "damage" : 115,
        "lvl" : 20,
        "skill_name" : "点木生火",
        "damage_type" : "割伤"
]),
([      "action" : "$N手臂一沉一拉，使出「张弓望月」，双手持着$w划出一道雪亮刀光，就在$n躲避之时猛地拦腰反切，劈向$n的$l",
        "force" : 250,
        "dodge" : -5,
        "parry" : -10,
        "damage" : 125,
        "lvl" : 40,
        "skill_name" : "张弓望月",
        "damage_type" : "割伤"
]),
([      "action" : "$N挥舞$w上劈下撩，左挡右开，使出一招「烈火腾云」，卷起阵阵刀风，每一圈都都划出不同的气流，齐齐罩向$n",
        "force" : 280,
        "dodge" : -10,
        "parry" : -15,
        "damage" : 145,
        "lvl" : 60,
        "skill_name" : "烈火腾云",
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「火中取栗」，划个大圈后左脚跃步落地，手中$w往前直伸，刀走剑势，挟着炙热的风声点向$n的$l",
        "force" : 320,
        "dodge" : -15,
        "parry" : -20,
        "damage" : 160,
        "lvl" : 90,
        "skill_name" : "火中取栗",
        "damage_type" : "刺伤"
]),
([      "action" : "$N腾空而起，半空中一招「玉石俱焚」猛烈扑下，手中$w迅速连劈，满天流光般的刀影排山倒海般地向$n的全身卷去",
        "force" : 300,
        "parry" : -15,
        "dodge" : -15,
        "damage" : 175,
        "lvl" :100,
        "skill_name" : "玉石俱焚",
        "damage_type" : "割伤"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("wuying-jian",1) || (int)me->query_skill("riyue-bian",1))
                return notify_fail("无影剑法、燃木刀法、日月鞭法你只能学得其一。\n"); 
        if (!me->query("family") || me->query("family/family_name")!="少林派" )
                return notify_fail("你不是少林弟子，如何能用这燃木刀法？\n");
        if ((int)me->query("max_neili") < 2000)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("yijin-jing", 1) < 180)
                return notify_fail("你的易筋神功火候太浅。\n");
        if ((int)me->query_skill("ranmu-daofa",1) <= 200
         &&(int)me->query_skill("xiuluo-dao",1) <= 120)
                return notify_fail("你的修罗刀火候不够，领悟不了燃木刀。\n");
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
        level   = (int) me->query_skill("ranmu-daofa",1);

        if ( me->query_temp("fenwo_hit")){
                return ([
                  "action": HIR "$N双掌夹刀合十，手中的"+weapon->name()+HIR"顿时升起一团火焰将自己包围，$P"HIR"猛宣一声佛号，一刀直劈向$n！" NOR,
                  "damage": 350,
                  "dodge" : 100,
                  "damage_type": "割伤"]);
        }

        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

//        if ((int)me->query_skill("wuying-jian",1) || (int)me->query_skill("riyue-bian",1))
//                return notify_fail("无影剑法、燃木刀法、日月鞭法你只能练得其一。\n"); 
        if ((int)me->query_skill("wuying-jian",1) || (int)me->query_skill("riyue-bian",1)
        	||(int)me->query_skill("daweituo-chu",1))
                return notify_fail("大韦陀杵、燃木刀法、日月鞭法你只能学得其一。\n"); 
        if (!me->query("family") || me->query("family/family_name")!="少林派" )
                return notify_fail("你不是少林弟子，如何能用这燃木刀法？\n");
        if (!objectp(weapon = me->query_temp("weapon"))
         ||(string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 40 )
                return notify_fail("你的气血不够练燃木刀法。\n");
        if ((int)me->query("neili") < 20 )
                return notify_fail("你的内力不够练燃木刀法。\n");
        me->receive_damage("qi", 30);
        if((int)me->query_skill("ranmu-daofa",1) > 200)
                me->add("neili",-10);
           
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"ranmu-daofa/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{                
        if (userp(me) && me->query_temp("fenwo_hit") 
         && victim->query("combat_exp") >= me->query("combat_exp")/2
         && me->query("fenwo") < me->query_skill("blade"))
                me->add("fenwo", 1); // for rmd's fenwo pfm
}

