#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *action = ({
([      "action": "$N向前斜跨一步，一招"+(order[random(13)])+"「剑气封喉」"NOR"，手中$w直刺$n的喉部",
        "force" : 126,
        "parry" : 3,
        "dodge" : 5,
        "damage": 221,
        "lvl"   : 0,
        "skill_name" : "剑气封喉",
        "damage_type":  "刺伤"
]),
([      "action": "$N错步上前，一招"+(order[random(13)])+"「明月千里」"NOR"，剑意若有若无，$w淡淡地向$n的$l挥去",
        "force" : 149,
        "parry" : 13,
        "dodge" : 10,
        "damage": 225,
        "lvl"   : 30,
        "skill_name" : "明月千里",
        "damage_type":  "割伤"
]),
([      "action": "$N一式"+(order[random(13)])+"「怀中抱月」"NOR"，纵身飘开数尺，运发剑气，手中$w遥摇指向$n的$l",
        "force" : 167,
        "parry" : 12,
        "dodge" : 15,
        "damage": 231,
        "lvl"   : 50,
        "skill_name" : "怀中抱月",
        "damage_type":  "刺伤"
]),
([      "action": "$N纵身轻轻跃起，一式"+(order[random(13)])+"「大风起兮」"NOR"，剑光如水，一泻千里，洒向$n全身",
        "force" : 187,
        "parry" : 23,
        "dodge" : 19,
        "damage": 245,
        "lvl"   : 70,
        "skill_name" : "大风起兮",
        "damage_type":  "割伤"
]),
([      "action":"$N错步上前，一招"+(order[random(13)])+"「明月千里」"NOR"，剑意若有若无，$w淡淡地向$n的$l挥去",
        "force" : 197,
        "parry" : 31,
        "dodge" : 27,
        "damage": 256,
        "lvl"   : 90,
        "skill_name" : "明月千里",
        "damage_type":  "割伤"
]),
([      "action":"$N手中$w中宫直进，一式"+(order[random(13)])+"「定天一针」"NOR"，无声无息地对准$n的$l刺出一剑",
        "force" : 218,
        "parry" : 49,
        "dodge" : 35,
        "damage": 263,
        "lvl"   : 110,
        "skill_name" : "定天一针",
        "damage_type":  "刺伤"
]),
([      "action":"$N手中$w一沉，一式"+(order[random(13)])+"「星归月向」"NOR"，无声无息地滑向$n的$l",
        "force" : 239,
        "parry" : 52,
        "dodge" : 45,
        "damage": 272,
        "lvl"   : 130,
        "skill_name" : "星归月向",
        "damage_type":  "刺伤"
]),
([      "action":"$N手中$w斜指苍天，剑芒吞吐，一式"+(order[random(13)])+"「映月无声」"NOR"，对准$n的$l斜斜击出",
        "force" : 257,
        "parry" : 55,
        "dodge" : 51,
        "damage": 288,
        "lvl"   : 150,
        "skill_name" : "映月无声",
        "damage_type":  "刺伤"
]),
([      "action":"$N左指凌空虚点，右手$w逼出丈许雪亮剑芒，一式"+(order[random(13)])+"「情连航慈」"NOR"刺向$n的咽喉",
        "force" : 282,
        "parry" : 63,
        "dodge" : 55,
        "damage": 205,
        "lvl"   : 170,
        "skill_name" : "情连航慈",
        "damage_type":  "刺伤"
]),
([      "action":"$N合掌跌坐，一式"+(order[random(13)])+"「影玉徵辉」"NOR"，$w自怀中跃出，如疾电般射向$n的胸口",
        "force" : 331,
        "parry" : 76,
        "dodge" : 65,
        "damage": 222,
        "lvl"   : 190,
        "skill_name" : "影玉徵辉",
        "damage_type":  "刺伤"
])
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if (me->query_skill("force") < 120)
                return notify_fail("你的内功火候不够，不能学习流月剑舞。\n");

        if (me->query_skill("sword", 1) < 80)
                return notify_fail("你的基本剑法火候不够，不能学习流月剑舞。\n");

        if (me->query("max_neili") < 1000)
                return notify_fail("你的内力不够，不能学习流月剑舞。\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("liuyue-jian", 1))
                return notify_fail("你的基本剑法水平有限，无法领会更高深的流月剑舞。\n");

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
        level = (int) me->query_skill("liuyue-jian",1);
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

        if ((int)me->query("qi") < 80)
                return notify_fail("你的体力不够练流月剑舞。\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("你的内力不够练流月剑舞。\n");

        me->receive_damage("qi", 60);
        me->add("neili", -60);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"liuyue-jian/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("beiming-shengong",1);
        level2= (int) me->query_skill("beiming-shengong",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "beiming-shengong")
{

if (victim->query("neili") >= damage2)
{
victim->add("neili",-damage2);
me->add("neili",damage2);
}
	return HIW"$N突然使出北冥神功,$n全身内力如流水般源源不绝地流入$N的身体!\n"NOR;
}

        lvl  = me->query_skill("tianyu-qijian", 1);
        flvl = me->query("jiali");

if (me->query_skill_mapped("force") != "beiming-shengong")
                return;
        if (lvl < 80 || ! damage_bonus ||
            me->query("neili") < 300)
                return;
flvl=random(lvl)+50;
        if (random(6)==0)
        {
if (victim->query("qi") > flvl)
{
victim->add("qi",-flvl);
victim->add("eff_qi",-flvl);
victim->apply_condition("ss_poison", 10 +
		victim->query_condition("ss_poison"));
}
                return HIW "$n" HIW "身上中了几道生死符!!\n" NOR;
        }

        else if (random(5)==0)
        {
flvl=random(lvl)+50;
        if (random(5)==0)
        {
if (victim->query("qi") > flvl)
{
victim->add("qi",-flvl);
victim->add("eff_qi",-flvl);
}
                return HIG "$n" HIG "被一剑划过要害，鲜血飞出!!\n" NOR;

}                        }
	if( random(damage_bonus/2) > victim->query_str() ) {
		victim->receive_wound("qi", (damage_bonus - 10) / 2 );
		return  HIG "$n" HIG "被北冥神功一震，吐出一大口鲜血!!\n" NOR;
	}
}