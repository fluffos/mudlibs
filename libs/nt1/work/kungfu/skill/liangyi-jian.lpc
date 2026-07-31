//liangyi-jian.c 两仪剑法

#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "name":   "法分玄素",
    "action" : "$N剑尖剑芒暴长，一招「法分玄素」，手中$w自左下大开大阖，
一剑向右上向$n的$l",
    "force" : 120,
    "dodge" : 20,
    "damage" : 300,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "道尽阴阳",
    "action" : "$N长剑圈转，一招"+(order[random(13)])+"「道尽阴阳」"NOR"，手中$w平展下矗唤Ｇ崆峄n的$l",
    "force" : 120,
    "dodge" : 20,
    "damage" : 280,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "渊临深浅",
    "action" : "$N长剑轻灵跳动，剑随身长，右手$w使出一式"+(order[random(13)])+"「渊临深浅」"NOR"刺向$n的
$l",
    "force" : 140,
    "dodge" : 15,
    "damage" : 350,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "水泛青黄",
    "action" : "$N长剑下指，剑意流转，一招"+(order[random(13)])+"「水泛青黄」"NOR"直取$n的$l",
    "force" : 150,
    "dodge" : 15,
    "damage" : 280,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "云含吞吐",
    "action" : "$N剑芒吞吐，幻若灵蛇，右手$w使出一式"+(order[random(13)])+"「云含吞吐」"NOR"，剑势曼妙,刺向$n的$l",
    "force" : 130,
    "dodge" : 25,
    "damage" : 300,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "梦醒蝶庄",
    "action" : "$N屈腕云剑，剑光如彩碟纷飞，幻出点点星光，右手$w使出一式
"+(order[random(13)])+"「梦醒蝶庄」"NOR"跃跃洒洒飘向$n的$l",
    "force" : 120,
    "dodge" : 125,
    "damage" : 320,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "人在遐迩",
    "action" : "$N挥剑分击，剑势自胸前跃出，右手$w一式"+(order[random(13)])+"「人在遐迩」"NOR"，毫无
留恋之势，刺向$n的$l",
    "force" : 110,
    "dodge" : 115,
    "lvl" : 0,
    "damage" : 400,
    "damage_type" : "刺伤"
]),
([      "name":   "情系短长",
    "action" : "$N退步，左手剑指划转，腰部一扭，右手$w一记"+(order[random(13)])+"「情系短长」"NOR"自下
而上刺向$n的$l",
    "force" : 150,
    "dodge" : 135,
    "damage" : 400,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry");}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 800)
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_skill("qinqi-shuhua", 1) < 100 && (int)me->query_skill("xuantian-wuji", 1)<150 )
                return notify_fail("你的本门内功火候太浅。\n");
        return 1;
}
 mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("liangyi-jian",1);
        if (random(level) > 240 && me->query_skill("force") > 200 && me->query("neili") >= 500)
         {
        return ([
        "action":HIC"$N神色凝重，手中$w"NOR+HIY"一顿，气随意转，$w"+HIY"上剑芒突盛，
                   心中默念剑诀，如暴风般地刺向$n的$l！"NOR,
        "force" : 500,
        "dodge" : 140,
        "parry" : 140,
        "damage": 900,
        "weapon": HIY"剑罡"NOR,
        "damage_type":  "刺伤"
]);
}
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
   return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
   return notify_fail("你的体力不够练两仪剑法。\n");
    me->receive_damage("qi", 40);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"liangyi-jian/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
       string msg;
       int j, k;
       j = me->query_skill("liangyi-jian", 1);
       k = me->query_skill("qinqi-shuhua",1);
       if( random(10) >= 5 
        && !me->is_busy() 
        && !victim->is_busy() 
        && j > 120
        && k > 120
        && me->query_skill_mapped("parry") == "liangyi-jian"
        && j > random(victim->query_skill("dodge",1))){
          switch(random(3)){
            case 0 :
               msg = HIW"$N施展开剑路，剑势浩荡起伏，犀利无比！\n"NOR;
               msg+= HIW"$n连连後退，全力招架，无力还招！\n"NOR;
               victim->start_busy(3);
               message_vision(msg, me, victim);
               COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 2);
               break;
            case 1 :
               msg = HIW"$N绕着$n飞快地旋转，一下子连刺出好几十剑！\n"NOR;
               msg+= HIW"$n根本分不清楚那一剑是虚，那一剑是实，好停下攻势，严守门户。\n"NOR;
               victim->start_busy(2);
               message_vision(msg, me, victim);
               COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 0);
               break;
            case 2 :
               msg = HIW"$N风驰电掣的绕著$n快跑，忽东忽西，简直像是足不点地的飞行一般！\n"NOR;
               msg+= HIW"$n随着$N转来转去，弄得眼花缭乱，摇摇欲坠。\n"NOR;
               victim->start_busy(3);
               message_vision(msg, me, victim);
               COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);
               break;
          }         
       }
}

