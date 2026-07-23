// shedu-qiqiao.c
#include <ansi.h>;
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$N左指挥出，一式"+(order[random(13)])+"「青蛇挺身」"NOR"，削向$n的掌缘",
        "force" : 80,
        "damage" : 80,
        "dodge" : 5,
        "lvl" : 0,
        "skill_name" : "青蛇挺身",
        "damage_type" : "刺伤"
]),
([      "action" : "$N全身之力聚于一指，一式"+(order[random(13)])+"「银蛇吐信」"NOR"，指向$n的胸前",
        "force" : 100,
        "damage" : 80,
        "dodge" : 5,
        "lvl" : 15,
        "damage" : 25,
        "skill_name" : "银蛇吐信",
        "damage_type" : "刺伤"
]),
([      "action" : "$N左掌贴于神道穴，右手一式"+(order[random(13)])+"「金蛇摆尾」"NOR"，向$n的$l划过",
        "force" : 120,
        "damage" : 80,
        "dodge" : 8,
        "lvl" : 25,
        "damage" : 55,
        "skill_name" : "金蛇摆尾",
        "damage_type" : "刺伤"
]),
([      "action" : "$N双目怒视，一式"+(order[random(13)])+"「蝮蛇捕食」"NOR"，双指拂向$n的额、颈、肩、臂、胸、背",
        "force" : 150,
        "dodge" : 5,
        "damage" : 80,
        "damage": 65,
        "lvl" : 45,
        "skill_name" : "蝮蛇捕食",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一式"+(order[random(13)])+"「待机而行」"NOR"，左掌掌心向外，右指蓄势点向$n的$l",
        "force" : 180,
        "dodge" : 15,
        "damage" : 80,
        "damage": 80,
        "lvl" : 60,
        "skill_name" : "待机而行",
        "damage_type" : "刺伤"
]),
([      "action" : "$N右手伸出，十指叉开，一式"+(order[random(13)])+"「猛蛇出洞」"NOR"，小指拂向$n的太渊穴",
        "force" : 200,
        "dodge" : 20,
        "damage": 100,
        "lvl" : 70,
        "skill_name" : "猛蛇出洞",
        "damage_type" : "刺伤"
]),
([      "action" : "$N双迸出无数道劲气，一式"+(order[random(13)])+"「千蛇缠身」"NOR"射向$n的全身",
        "force" : 220,
        "dodge" : 25,
        "damage": 220,
        "lvl" : 80,
        "skill_name" : "千蛇缠身",
        "damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }


int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练蛇毒奇巧必须空手。\n");

        if ((int)me->query_skill("force") < 80)
                return notify_fail("你的内功火候不够，无法学蛇毒奇巧。\n");

        if ((int)me->query("max_neili") < 350)
                return notify_fail("你的内力太弱，无法练蛇毒奇巧。\n");

        if ((int)me->query_skill("poison") < 30)
                return notify_fail("你的基本毒技火候不够，无法学蛇毒奇巧。\n");

        if ((int)me->query_skill("finger")*3 < (int)me->query_skill("shedu-qiqiao"))
                return notify_fail("你的基本指法水平有限，无法领会更高深的蛇毒奇巧。\n");

        if ((int)me->query_skill("poison")*2 < (int)me->query_skill("shedu-qiqiao"))
                return notify_fail("你的基本毒技水平有限，无法领会更高深的蛇毒奇巧。\n");

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
        level   = (int) me->query_skill("shedu-qiqiao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70)
                return notify_fail("你的体力太低了。\n");

        if ((int)me->query("neili") < 55)
                return notify_fail("你的内力不够练蛇毒奇巧。\n");

        me->receive_damage("qi", 52);
        me->add("neili", -44);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shedu-qiqiao/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
       int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	       int neili, neili2;
 
	object weapon;
object target;

        level = (int) me->query_skill("wudu-shengong",1);
        level2= (int) me->query_skill("wudu-shengong",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "wudu-shengong")
{
if (!victim->is_busy()) victim->start_busy(3);	
if (me->query("qi") <= me->query("max_qi")*2) me->add("qi",damage2);
if (me->query("eff_qi") <= me->query("max_qi")*2) me->add("eff_qi",damage2);
 return HIG "$N使出五毒神功！舔了舔$n流出的鲜血，全身的伤好像好了很多！!\n";
}
}