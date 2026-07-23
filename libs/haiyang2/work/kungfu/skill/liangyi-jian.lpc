//liangyi-jian.c 两仪剑法
// modified by Venus Oct.1997

#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "name":   "法分玄素",
    "action" : "$N剑尖剑芒暴长，一招"+(order[random(13)])+"「法分玄素」"NOR"，手中$w自左下大开大阖，
一剑向右上向$n的$l",
    "force" : 120,
    "dodge" : 120,
    "damage" : 300,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "道尽阴阳",
    "action" : "$N长剑圈转，一招"+(order[random(13)])+"「道尽阴阳」"NOR"，手中$w平展下刺，一剑轻轻划
过$n的$l",
    "force" : 120,
    "dodge" : 120,
    "damage" : 280,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "渊临深浅",
    "action" : "$N长剑轻灵跳动，剑随身长，右手$w使出一式"+(order[random(13)])+"「渊临深浅」"NOR"刺向$n的
$l",
    "force" : 140,
    "dodge" : 115,
    "damage" : 350,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "水泛青黄",
    "action" : "$N长剑下指，剑意流转，一招"+(order[random(13)])+"「水泛青黄」"NOR"直取$n的$l",
    "force" : 150,
    "dodge" : 115,
    "damage" : 280,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "云含吞吐",
    "action" : "$N剑芒吞吐，幻若灵蛇，右手$w使出一式"+(order[random(13)])+"「云含吞吐」"NOR"，剑势曼妙，
刺向$n的$l",
    "force" : 130,
    "dodge" : 125,
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
        if( (int)me->query_skill("xuantian-wuji", 1) < 100)
                return notify_fail("你的玄天无极功的修为不够，不能使用流云水袖! \n");
        if( (int)me->query_skill("xunlei-jian", 1) < 100 )
                return notify_fail("你的迅雷剑法还不到家，无法使用流云水袖！\n");
   if(me->query_skill_mapped("force") != "xuantian-wuji" )
	return notify_fail("你没有用玄天无极。\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 20 && (int)me->query_skill("xuantian-wuji", 1)<20 )
		return notify_fail("你的本门内功火候太浅。\n");
	return 1;
}
mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("liangyi-jian",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
     return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
    object weapon;
        if( (int)me->query_skill("xuantian-wuji", 1) < 100)
                return notify_fail("你的玄天无极功的修为不够，不能使用流云水袖! \n");
        if( (int)me->query_skill("xunlei-jian", 1) < 100 )
                return notify_fail("你的迅雷剑法还不到家，无法使用流云水袖！\n");
   if(me->query_skill_mapped("force") != "xuantian-wuji" )
	return notify_fail("你没有用玄天无极。\n");
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
   return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
   return notify_fail("你的体力不够练两仪剑法。\n");
    me->receive_damage("qi", 10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"liangyi-jian/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2,damage;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("xuantian-wuji",1);
        level2= (int) me->query_skill("xuantian-wuji",1);


if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "xuantian-wuji")
{
        victim->receive_damage("qi",level*2+300);
        victim->receive_wound("qi",level*3+300);
	return HIB"$N脚踏八卦步,手捏太乙决,$N一声长啸，$n双眼一黑，吐出一口鲜血!\n"NOR;
}
}