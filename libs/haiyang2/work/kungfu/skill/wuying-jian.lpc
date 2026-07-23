//wuying-jian 少林无影剑
#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$N握紧手中$w一招"+(order[random(13)])+"「来去自如」"NOR"点向$n的$l",
        "force" : 280,
        "dodge" : 40,
        "damage" : 280,
        "lvl"    : 0,
        "skill_name" : "来去自如", 
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招"+(order[random(13)])+"「日月无光」"NOR"，无数$w上下刺出，直向$n逼去",
        "force" : 280,
        "dodge" : 10,
        "damage" : 280,
        "lvl"    : 20,
        "skill_name" : "日月无光",
        "damage_type" : "刺伤"
]),
([      "action" : "$N向前跨上一步，手中$w使出"+(order[random(13)])+"「剑气封喉」"NOR"直刺$n的喉部",
        "force" : 300,
        "dodge" : 80,
        "damage" : 300,
        "lvl"    : 40,
        "skill_name" : "剑气封喉",
        "damage_type" : "刺伤"
]),
([      "action" : "$N虚恍一步，使出"+(order[random(13)])+"「心境如水」"NOR"手中$w直刺$n的要害",
        "force" : 290,
        "dodge" : 60,
        "damage" : 280,
        "lvl"    : 60,
        "skill_name" : "心境如水",
        "damage_type" : "刺伤"
]),
([      "action" : "只见$N抡起手中的$w，使出"+(order[random(13)])+"「佛光普照」"NOR"万点金光直射$n",
        "force" : 390,
        "dodge" : 70,
        "damage" : 280,
        "lvl"    : 80,
        "skill_name" : "佛光普照",
        "damage_type" : "刺伤"
]),
([      "action" : "$N抡起手中的$w，使出"+(order[random(13)])+"「风行叶落」"NOR"无数剑光直射$n",
        "force" : 390,
        "dodge" : 60,
        "damage" : 290,
        "lvl"    : 100,
        "skill_name" : "风行叶落", 
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出"+(order[random(13)])+"「声东击西」"NOR"，手中$w如刮起狂风一般闪烁不定，刺向$n",
        "force" : 300,
        "dodge" : 80,
        "damage" : 340,
        "lvl"    : 220,
        "skill_name" : "声东击西",
        "damage_type" : "刺伤"
]),
([      "action" : "$N随手使出剑法之奥义"+(order[random(13)])+"「无影无踪」"NOR"，手中$w如鬼魅一般铺天盖地的刺向$n",
        "force" : 500,
        "dodge" : 90,
        "damage" : 450,
        "lvl"    : 150,
        "skill_name" : "「无影无踪」",
        "damage_type" : "刺伤"
]),
([      "action" : HIY"$N使出无影剑法之最终绝技[1;36m「蛟龙出水」[0m,[1;33m手中$w犹如蛟龙一般刺向$n[0m"NOR,
        "force" : 500,
        "dodge" : 100,
        "damage" : 800,
        "lvl"    : 220,
        "skill_name" : "HIY「剑气合一」"NOR,
        "damage_type" : "刺伤"
]),



});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query_skill("hunyuan-yiqi", 1) < 150)
                return notify_fail("你的「混元一气」火候不够，无法学「无影剑法」。\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 150)
       return notify_fail("你的混元一气功火候太浅。\n");
         if ((int)me->query_skill("yijinjing", 1) < 160)
                return notify_fail("你的易筋经内功火候太浅。\n");
    if ((int)me->query_skill("riyue-bian", 1) < 150)
       return notify_fail("你的日月鞭法火候太浅。\n");
    if ((int)me->query_skill("damo-jian", 1) < 150)
       return notify_fail("你的达摩剑火候太浅。\n");

         if((int)me->query_skill("shaolin-shenfa",1) <120)
      		return notify_fail("你的少林身法火候不足，难以领悟「无影剑法」。\n");              
        if ((int)me->query("max_neili") < 300)
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
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 150)
       return notify_fail("你的混元一气功火候太浅。\n");
         if ((int)me->query_skill("yijinjing", 1) < 160)
                return notify_fail("你的易筋经内功火候太浅。\n");
    if ((int)me->query_skill("riyue-bian", 1) < 150)
       return notify_fail("你的日月鞭法火候太浅。\n");
    if ((int)me->query_skill("damo-jian", 1) < 150)
       return notify_fail("你的达摩剑火候太浅。\n");
         if((int)me->query_skill("shaolin-shenfa",1) <120)
      		return notify_fail("你的少林身法火候不足，难以领悟「无影剑法」。\n");              
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练「无影剑法」。\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("你的内力不够练「无影剑法」。\n");
        me->receive_damage("qi", 40);
        me->add("neili",-15);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"wuying-jian/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	int level, jiali, time,level2,damage;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("yijinjing",1);
damage= (int) me->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "yijinjing")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
	return HIR"只见$n$l闷哼一声，吐出一口鲜血，已被易筋经的护体真气给击伤!\n"NOR;
}
        if( damage_bonus < 50 ) return 0;
        if( random(5)==0) {
                victim->add("qi", -damage_bonus);
                victim->receive_wound("qi", (damage_bonus - 20) / 2 );
                return HIR "你听到「哧」一声轻响一道霸气扑天而来，忽然间$n血冒三丈，被$N剑气所伤！\n";
        }
        else if( random(damage_bonus/2) > victim->query_str() ) {
                victim->add("qi", -damage_bonus);
                victim->receive_wound("qi", (damage_bonus - 20) / 2 );
                return HIR "你听到「哧」一声轻响一道霸气扑天而来，忽然间$n血冒三丈，被$N剑气所伤！\n";
        }
}


