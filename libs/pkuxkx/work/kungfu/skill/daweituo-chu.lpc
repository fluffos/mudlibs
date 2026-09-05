//daweituo-chu 大韦陀杵
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N垂目低首，一式「离相寂灭」，手中$w不着丝毫风声，悄然攻向$n的$l",
        "force" : 50,
        "dodge" : 40,
        "damage" : 20,
        "lvl"    : 0,
        "skill_name" : "离相寂灭", 
        "damage_type" : "挫伤"
]),
([      "action" : "$N浑然不顾对方的攻势，手一振使出「究竟无我」，$w径直砸向$n",
        "force" : 70,
        "dodge" : 10,
        "damage" : 30,
        "lvl"    : 20,
        "skill_name" : "究竟无我",
        "damage_type" : "挫伤"
]),
([      "action" : "$N一招「离色离相」，$w以一个匪夷所思的角度攻向$n的喉部",
        "force" : 90,
        "dodge" : 30,
        "damage" : 50,
        "lvl"    : 60,
        "skill_name" : "离色离相",
        "damage_type" : "挫伤"
]),
([      "action" : "$N使出「无断无灭」，内力灌处，$w以不可抵挡的势头直直劈向$n的要害",
        "force" : 90,
        "dodge" : 30,
        "damage" : 80,
        "lvl"    : 100,
        "skill_name" : "无断无灭",
        "damage_type" : "挫伤"
]),
([      "action" : "只见$N一式「应化非真」，$w看似直击，转眼却不知如何绕向了$n的$l",
        "force" : 90,
        "dodge" : 50,
        "damage" : 110,
        "lvl"    : 140,
        "skill_name" : "应化非真",
        "damage_type" : "挫伤"
]),
([      "action" : "$N抡起手中的$w，使出「法会因由」，巧妙的逆着对方的攻势，硬碰硬地朝$n砸去",
        "force" : 120,
        "dodge" : 60,
        "damage" : 120,
        "lvl"    : 180,
        "skill_name" : "法会因由", 
        "damage_type" : "挫伤"
]),
([      "action" : "$N使出「妙行无住」，手中$w如刮起狂风一般闪烁不定，砸向$n",
        "force" : 200,
        "dodge" : 50,
        "damage" : 140,
        "lvl"    : 220,
        "skill_name" : "妙行无住",
        "damage_type" : "挫伤"
]),
([      "action" : "$N随手使出杖法之奥义「能净业障」，手中$w如鬼魅一般铺天盖地的砸向$n",
        "force" : 300,
        "dodge" : 50,
        "damage" : 200,
        "lvl"    : 240,
        "skill_name" : "「能净业障」",
        "damage_type" : "挫伤"
]),
([      "action" : HIY"$N"HIY"使出大韦陀杵之最终绝技「法身非相」,仿佛幻化出两条影子，一袭左一袭右，本身却径直攻向$n"NOR,
        "force" : 400,
        "dodge" : 50,
        "damage" : 300,
        "lvl"    : 300,
        "skill_name" : "HIY「法身非相」"NOR,
        "damage_type" : "挫伤"
]),
});


int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query_skill("ranmu-daofa",1) || (int)me->query_skill("riyue-bian",1))
                return notify_fail("大韦陀杵、燃木刀法、日月鞭法你只能练得其一。\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < 250)
                return notify_fail("你的「混元一气」火候不够，无法学「大韦陀杵」。\n");
        if ((int)me->query_skill("yijin-jing", 1) < 250)
                return notify_fail("你的「易筋经」火候不够，无法学「大韦陀杵」。\n");
        if ((int)me->query("max_neili") < 1000)
                return notify_fail("你的内力太弱，无法练「大韦陀杵」。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("daweituo-chu",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/4)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("你的体力不够练「大韦陀杵」。\n");
        if ((int)me->query("jing") < 100)
                return notify_fail("你的体力不够练「大韦陀杵」。\n");
        if ((int)me->query("neili") < 200)
                return notify_fail("你的内力不够练「大韦陀杵」。\n");
        if (me->query("family/family_name") != "少林派" && me->query("chushi/last_family")!="少林派")
                return notify_fail("非少林弟子不能练大韦陀杵！\n");
        if ((int)me->query_skill("ranmu-daofa",1) || (int)me->query_skill("riyue-bian",1))
                return notify_fail("大韦陀杵、燃木刀法、日月鞭法你只能练得其一。\n");
               
        me->receive_damage("qi", 40);
        me->receive_damage("jing", 40);
        me->add("neili",-15);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"daweituo-chu/" + action;
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( me->query_temp("zuida") || damage_bonus<100 ) return 0;
        if( F_KUNGFU->hit_rate( me->query_str(), victim->query_str(), 14, me, victim) )
        { 
                F_KUNGFU->hit_wound("qi", (damage_bonus-100)/2, 0, me, victim);
                return HIR "只听得「呼」一声浊音一道罡气扑面而来，忽然间$n"+HIR"口吐鲜血，显被$N"+HIR"罡气震伤！\n"NOR;
        }
}
string query_parry_msg(object weapon)
{
        if (!weapon) 
               return "但是被$n挡开了。\n";
        if (weapon->query("skill_type") == "staff")
               return "但是被$n格开了！\n";
}


