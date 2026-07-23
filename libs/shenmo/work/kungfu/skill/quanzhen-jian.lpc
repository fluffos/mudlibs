// quanzhen-jian.c 全真剑法
#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action":"$N使一式"+(order[random(13)])+"「探海屠龙」"NOR"，手中$w由左至右横扫向向$n的$l",
        "force" : 120,
        "dodge" : 0,
        "damage": 130,
        "lvl" : 0,
        "skill_name" : "探海屠龙",
        "damage_type":  "割伤"
]),
([      "action":"$N踏上一步，"+(order[random(13)])+"「罡风扫叶」"NOR"，手中$w盘旋飞舞出一道剑光劈向$n的$l",
        "force" : 140,
            "dodge" : 10,
        "damage": 150,
        "lvl" : 9,
        "skill_name" : "罡风扫叶",
        "damage_type":  "割伤"
]),
([      "action":"$N手中$w一抖，一招"+(order[random(13)])+"「顺水推舟」"NOR"，斜斜一剑反腕撩出，攻向$n的$l",
        "force" : 160,
           "dodge" : 5,
        "damage": 170,
        "lvl" : 18,
        "skill_name" : "顺水推舟",
        "damage_type":  "割伤"
]),
([      "action":"$N手中$w连绕数个大圈，一式"+(order[random(13)])+"「星弛电闪」"NOR"，一道剑光飞向$n的$l",
        "force" : 180,
        "dodge" : 10,
        "damage": 195,
        "lvl" : 27,
        "skill_name" : "星弛电闪",
        "damage_type":  "刺伤"
]),
([      "action":"$N一式"+(order[random(13)])+"「白鹤亮翅」"NOR"，左手伸展，右手$w挥向$n的$l",
        "force" : 220,
        "dodge" : 15,
        "damage": 210,
        "lvl" : 36,
        "skill_name" : "白鹤亮翅",
        "damage_type":  "割伤"
]),
([      "action":"$N手中$w斜指苍天，一式"+(order[random(13)])+"「横行漠北」"NOR"，对准$n的$l斜斜击出",
        "force" : 260,
        "dodge" : 5,
        "damage": 220,
        "lvl" : 44,
        "skill_name" : "横行漠北",
        "damage_type":  "刺伤"
]),
([      "action":"$N一式"+(order[random(13)])+"「马蹴落花」"NOR"，手腕急抖，挥洒出万点金光，刺向$n的$l",
        "force" : 320,
        "dodge" : 5,
        "damage": 245,
        "lvl" : 52,
        "skill_name" : "马蹴落花",
        "damage_type":  "刺伤"
]),
([      "action":"$N一式"+(order[random(13)])+"「九品莲台」"NOR"，$w飞斩盘旋，如疾电般射向$n的胸口",
        "force" : 380,
        "dodge" : 5,
        "damage": 265,
        "lvl" : 60,
        "skill_name" : "九品莲台",
        "damage_type":  "刺伤"
]),
([      "action":"$N使一式"+(order[random(13)])+"「荆轲刺秦」"NOR"，手中$w合身疾刺$n的胸口，威不可当",
        "force" : 380,
        "dodge" : 115,
        "damage": 285,
        "lvl" : 70,
        "skill_name" : "荆轲刺秦",
        "damage_type":  "刺伤"
]),
([      "action":"$N手中$w划出一道长长的弧线，刺向$n的$l，却是一招"+(order[random(13)])+"「箫史乘龙」"NOR"",
        "force" : 380,
        "dodge" : 115,
        "damage": 300,
        "lvl" : 80,
        "skill_name" : "箫史乘龙",
        "damage_type":  "刺伤"
]),
([      "action":"$N回剑自守，使一式"+(order[random(13)])+"「深藏若虚」"NOR"，蓦地手中$w向$n击出",
        "force" : 380,
        "dodge" : 115,
        "damage": 320,
        "lvl" : 90,
        "skill_name" : "深藏若虚",
        "damage_type":  "刺伤"
]),
([      "action":"$N左足踢起，一式"+(order[random(13)])+"「魁星踢斗」"NOR"，$w从不可思议的角度刺向$n",
        "force" : 380,
        "dodge" : 115,
        "damage": 340,
        "lvl" : 114,
        "skill_name" : "魁星踢斗",
        "damage_type":  "刺伤"
]),
([      "action":"$N一式"+(order[random(13)])+"「紫电穿云」"NOR"，$w突然从天而降，一片金光围掠$n全身",
        "force" : 380,
        "dodge" : 115,
        "damage": 265,
        "lvl" : 129,
        "skill_name" : "紫电穿云",
        "damage_type":  "刺伤"
]),
([	"action":"$N晃动$w，踏奇门，走偏锋，剑尖颤了几颤，一招巧妙无比的"+(order[random(13)])+"「分花拂柳」"NOR"，似左实右，已点在$n$l",
	"force" : 150,
		  "dodge" : 5,
	"parry" : 5,
	"damage": 215,
	"lvl" : 105,
	"skill_name" : "分花拂柳",
	"damage_type":	"刺伤"
]),
([	"action":"$N使一招"+(order[random(13)])+"「琴心三叠」"NOR"，身形向上飘起，手中$w虚虚实实幻出三点寒光射向$n$l",
	"force" : 180,
		  "dodge" : 5,
	"parry" : 5,
	"damage": 225,
	"lvl" : 109,
	"skill_name" : "琴心三叠",
	"damage_type":	"刺伤"
]),
([	"action":"$N身形绕$n一转，猛然一式"+(order[random(13)])+"「罡风扫叶」"NOR"，将$w舞出满天剑影，挟着劲风向$n扫去",
	"force" : 250,
	 "dodge" : 10,
	"parry" : 10,
	"damage": 260,
	"lvl" : 125,
	"skill_name" : "罡风扫叶",
	"damage_type":	"割伤"
]),
([	"action":"$N忽然身形高高跃起，使出"+(order[random(13)])+"「浪迹天涯」"NOR"，$w幻出漫天花瓣，迅如雷霆射向$n的$l",
	"force" : 450,
	 "dodge" : 20,
	"parry" : 20,
	"damage": 200,
	"lvl" : 135,
	"skill_name" : "浪迹天涯",
	"damage_type":	"刺伤"
]),
([	"action":"$N左手捏着剑诀，右足踏开一招"+(order[random(13)])+"“定阳针”"NOR"向上斜刺，$w锵然跃出倏的化作几点星光射向$n的$l",
	"force" : 420,
	 "dodge" : 8,
	"parry" : 8,
	"damage": 320,
	"lvl" : 145,
	"skill_name" : "定阳针",
	"damage_type":	"刺伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
        if ((int)me->query_skill("yunv-xinfa", 1) < 15 &&
            (int)me->query_skill("xiantian-qigong", 1) < 15)
                return notify_fail("你的内功心法火候不到，无法学习全真剑法。\n");

        if ((int)me->query_skill("xiantian-qigong", 1) >  1 &&
            (int)me->query_skill("qixing-jian", 1) < 80 )
                return notify_fail("你的七星剑法火候不到，无法学习全真剑法。\n");

        if ((int)me->query_skill("xiantian-qigong", 1) >  1 &&
            (int)me->query_skill("qixing-shou", 1) < 80 )
                return notify_fail("你的七星分天手火候不到，无法学习全真剑法。\n");

        if ((int)me->query_skill("xiantian-qigong", 1) >  1 &&
            (int)me->query_skill("haotian-zhang", 1) < 80 )
                return notify_fail("你的昊天掌火候不到，无法学习全真剑法。\n");

        if ((int)me->query_skill("xiantian-qigong", 1) >  1 &&
            (int)me->query_skill("jinyan-gong", 1) < 80 )
                return notify_fail("你的金雁功火候不到，无法学习全真剑法。\n");
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
        level   = (int) me->query_skill("quanzhen-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if ((int)me->query_skill("yunv-xinfa", 1) < 15 &&
            (int)me->query_skill("xiantian-qigong", 1) < 15)
                return notify_fail("你的内功心法火候不到，无法学习全真剑法。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        
        if ((int)me->query_skill("xiantian-qigong", 1) >  1 &&
            (int)me->query_skill("qixing-jian", 1) < 80 )
                return notify_fail("你的七星剑法火候不到，无法学习全真剑法。\n");

        if ((int)me->query_skill("xiantian-qigong", 1) >  1 &&
            (int)me->query_skill("qixing-shou", 1) < 80 )
                return notify_fail("你的七星分天手火候不到，无法学习全真剑法。\n");

        if ((int)me->query_skill("xiantian-qigong", 1) >  1 &&
            (int)me->query_skill("haotian-zhang", 1) < 80 )
                return notify_fail("你的昊天掌火候不到，无法学习全真剑法。\n");

        if ((int)me->query_skill("xiantian-qigong", 1) >  1 &&
            (int)me->query_skill("jinyan-gong", 1) < 80 )
                return notify_fail("你的金雁功火候不到，无法学习全真剑法。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练全真剑法。\n");
        me->receive_damage("qi", 45);
        return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2,damage;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("qixing-array",1);
        level2= (int) me->query_skill("xiantian-qigong",1);


if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "xiantian-qigong")
{

	victim->start_busy(3);
	return HIR"$N踏奇门，走偏锋,$n双眼一花,不知如何应对!\n"NOR;
}
}
int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("qixing-array",1);
        level2= (int) me->query_skill("xiantian-qigong",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "xiantian-qigong")
{

	ob->start_busy(3);

msg = HIG"$N七星移位，走偏锋,$n双眼一花,不知如何应对!\n"NOR;

           message_vision(msg, me, ob);
           return j;
}       
}
string perform_action_file(string action)
{
        return __DIR__"quanzhen-jian/" + action;
}
