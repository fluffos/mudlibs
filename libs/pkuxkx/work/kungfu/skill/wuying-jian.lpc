//wuying-jian 少林无影剑 
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N握紧手中$w一招「来去自如」点向$n的$l",
        "force" : 50,
        "dodge" : 40,
        "damage" : 20,
        "lvl"    : 0,
        "skill_name" : "来去自如", 
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「日月无光」，无数$w上下刺出，直向$n逼去",
        "force" : 70,
        "dodge" : 10,
        "damage" : 30,
        "lvl"    : 20,
        "skill_name" : "日月无光",
        "damage_type" : "刺伤"
]),
([      "action" : "$N向前跨上一步，手中$w使出「剑气封喉」直刺$n的喉部",
        "force" : 90,
        "dodge" : 30,
        "damage" : 50,
        "lvl"    : 60,
        "skill_name" : "剑气封喉",
        "damage_type" : "刺伤"
]),
([      "action" : "$N虚恍一步，使出「心境如水」手中$w直刺$n的要害",
        "force" : 90,
        "dodge" : 30,
        "damage" : 80,
        "lvl"    : 100,
        "skill_name" : "心境如水",
        "damage_type" : "刺伤"
]),
([      "action" : "只见$N抡起手中的$w，使出「佛光普照」万点金光直射$n",
        "force" : 90,
        "dodge" : 50,
        "damage" : 110,
        "lvl"    : 140,
        "skill_name" : "佛光普照",
        "damage_type" : "刺伤"
]),
([      "action" : "$N抡起手中的$w，使出「风行叶落」无数剑光直射$n",
        "force" : 120,
        "dodge" : 60,
        "damage" : 120,
        "lvl"    : 180,
        "skill_name" : "风行叶落", 
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出「声东击西」，手中$w如刮起狂风一般闪烁不定，刺向$n",
        "force" : 200,
        "dodge" : 50,
        "damage" : 140,
        "lvl"    : 220,
        "skill_name" : "声东击西",
        "damage_type" : "刺伤"
]),
([      "action" : "$N随手使出剑法之奥义「无影无踪」，手中$w如鬼魅一般铺天盖地的刺向$n",
        "force" : 300,
        "dodge" : 50,
        "damage" : 200,
        "lvl"    : 240,
        "skill_name" : "「无影无踪」",
        "damage_type" : "刺伤"
]),
([      "action" : HIY"$N"HIY"使出无影剑法之最终绝技「蛟龙出水」,手中$w"HIY"犹如蛟龙一般刺向$n"NOR,
        "force" : 400,
        "dodge" : 50,
        "damage" : 300,
        "lvl"    : 300,
        "skill_name" : "HIY「剑气合一」"NOR,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query_skill("ranmu-daofa",1) || (int)me->query_skill("riyue-bian",1))
                return notify_fail("无影剑法、燃木刀法、日月鞭法你只能练得其一。\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < 250)
                return notify_fail("你的「混元一气」火候不够，无法学「无影剑法」。\n");
        if ((int)me->query_skill("yijin-jing", 1) < 250)
                return notify_fail("你的「易筋经」火候不够，无法学「无影剑法」。\n");
        if ((int)me->query("max_neili") < 1000)
                return notify_fail("你的内力太弱，无法练「无影剑法」。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("wuying-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/4)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("你的体力不够练「无影剑法」。\n");
        if ((int)me->query("jing") < 100)
                return notify_fail("你的体力不够练「无影剑法」。\n");
        if ((int)me->query("neili") < 200)
                return notify_fail("你的内力不够练「无影剑法」。\n");
        if (me->query("family/family_name") != "少林派" && me->query("chushi/last_family")!="少林派")
                return notify_fail("非少林弟子不能练无影剑法！\n");
        if ((int)me->query_skill("ranmu-daofa",1) || (int)me->query_skill("riyue-bian",1))
                return notify_fail("无影剑法、燃木刀法、日月鞭法你只能练得其一。\n");
               
        me->receive_damage("qi", 40);
        me->receive_damage("jing", 40);
        me->add("neili",-15);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"wuying-jian/" + action;
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( me->query_temp("zuida") || damage_bonus<100 ) return 0;
        if( random(me->query_str()) > victim->query_str()*3/4 )
        { 
                victim->receive_wound("qi", (damage_bonus-100)/2, me );
                return HIR "你听到「哧」一声轻响一道霸气扑天而来，忽然间$n血冒三丈，被$N剑气所伤！\n"NOR;
        }
}
string query_parry_msg(object weapon)
{
        if (!weapon) 
               return "但是被$n挡开了。\n";
        if (weapon->query("skill_type") == "sword")
               return "但是被$n格开了！\n";
}


