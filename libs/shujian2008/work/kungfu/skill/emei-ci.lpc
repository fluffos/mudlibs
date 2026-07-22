// emei-ci.c 峨嵋刺
// created by Godhelpu 2001-02-07

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
        "action" : "$N脚下倒踩莲花，左手虚按，一招「文姬挥笔」，右手$w直刺$n的$l",
        "force" : 80,
        "dodge" : 20,   
        "damage" : 70,
        "lvl" : 0,
        "skill_name" : "文姬挥笔",
        "damage_type" : "刺伤"
]),
([
        "action" : "$N面露微笑，神态祥和，一招「西子洗面」，双手缓缓划圆，守势中蕴藏着极为凌厉的杀着",
        "force" : 100,
        "dodge" : 5,
        "parry" : 60,
        "damage" : 75,
        "lvl" : 20,
        "skill_name" : "西子洗面",
        "damage_type" : "刺伤"
]),
([
        "action" : "$N右手起处，$w一式「分花拂柳」，泛起层层光影，向左右推开，一缕精芒，直奔$n",
        "force" : 130,
        "dodge" : 25,   
        "damage" : 90,
        "lvl" : 40,
        "skill_name" : "分花拂柳",
        "damage_type" : "刺伤"
]),
([
        "action" : "只听「嗤」的一声，$N毫不理会$n的进手招数，$w化为「金针渡劫」，径取$n的$l",
        "force" : 200,
        "dodge" : -20,
        "damage" : 110,
        "lvl" : 60,
        "skill_name" : "金针渡劫",
        "damage_type" : "刺伤"
]),
([
        "action" : "$N脚下一幌，闪到$n身侧，身形交错中，$w一招「玉带围腰」，连攻$n前右后三个方位",
        "force" : 145,
        "dodge" : 40,   
        "damage" : 120,
        "lvl" : 80,
        "skill_name" : "玉带围腰",
        "damage_type" : "刺伤"
]),
([
        "action" : "$N身形半转，突然间右腕陡振，电光火石间接连向$n攻出几招，正是一式「素女掸尘」",
        "force" : 180,
        "dodge" : 50,   
        "damage" : 145,
        "lvl" : 100,
        "skill_name" : "素女掸尘",
        "damage_type" : "刺伤"
]),
([
        "action" : "$N微一躬身，$w突交左手，一招「越女追魂」，反手疾刺，$n微一错愕间，寒气已至身前",
        "force" : 240,
        "dodge" : 65,   
        "damage" : 170,
        "lvl": 120,
        "skill_name" : "越女追魂",
        "damage_type" : "刺伤"
]),
([
        "action" : "$N一声清啸，斜行而前，$w横削直击，迅捷无比，白光闪烁中，已向$n连刺七下",
        "force" : 280,
        "dodge" : 70,   
        "damage" : 200,
        "lvl" : 150,
        "skill_name" : "七星聚会",
        "damage_type" : "刺伤"
]),
});

int valid_enable(string usage) 
{
    return usage == "dagger" || usage == "parry" || usage == "dodge"; 
}

int valid_learn(object me)
{
       if ((int)me->query("max_neili") < 2000)
               return notify_fail("你的内力修为不够。\n");
       if ((int)me->query_skill("linji-zhuang", 1) < 150)
               return notify_fail("你的临济十二庄火候太浅。\n");
       if ((int)me->query_skill("parry", 1) < 150)
                return notify_fail("你的基本招架火候太浅。\n");
       if ((int)me->query_skill("dodge", 1) < 150)
                return notify_fail("你的基本轻功火候太浅。\n");
       return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"]) return action[i]["skill_name"];
}

mapping query_action(object me,object target)
{
        int i, level;
        level = (int) me->query_skill("emei-ci",1);
        for(i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 15, level/4)];
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{                
        object weapon = me->query_temp("weapon");

        if (!weapon) return;
        if ((string)weapon->query("id")!="emei ci" && (string)weapon->query("id")!="yunv zan") return;
        if (random(me->query_str())>victim->query_con()/2)
                victim->receive_wound("qi", victim->query("max_qi")/100+random(100));
}

int practice_skill(object me)
{
        object weapon;
        weapon = me->query_temp("weapon");
        
        if ( !objectp(weapon) || (string)weapon->query("skill_type") != "dagger" )
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("jingli") < 50) return notify_fail("你的精力不够。\n");
        if ((int)me->query("neili") < 20) return notify_fail("你的内力不够。\n");
        me->receive_damage("jingli", 30);
        me->receive_damage("neili", 10);
        return 1;
}

int double_attack(object me)
{       
        if ( me->query_skill("emei-ci", 1) >= 100
        && me->query_skill_mapped("dagger") == "emei-ci"
        && me->query("class") == "bonze" && me->query("gender") == "女性"
        && me->query("family/family_name") == "峨嵋派" )
                return 1;
}

string perform_action_file(string action)
{
        return __DIR__"emei-ci/" + action;
}

int help(object me)
{
        write(WHT"\n峨嵋刺："NOR"\n\n");
        write(@HELP        
武功名称：
        峨嵋刺(emei-ci)
        
要求：
        最大内力 2000;
        临济十二庄 150级;
        基本轻功 150级;
        基本招架 150级;

特殊攻击：
        残虹绝技(Perform canhong)。

HELP
        );
        return 1;
}
