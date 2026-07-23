// sun-finger.c 一阳指 book: 一阳指诀

#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *xue_name = ({ 
"劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
"幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",}); 

mapping *action = ({
([	"action" : "$N一式"+(order[random(13)])+"「阳关三叠」"NOR"，真气自指间喷薄而出，连出三指，快如电
闪，点向$n的$l",
	"force" : 100,
	"dodge" : 25,
	"damage": 200,
	"lvl" : 0,
	"skill_name" : "阳关三叠",
	"damage_type" : "内伤"
]),
([	"action" : "$N身形一转，一步跨到$n身后。$n急忙转身，$N又如闪电般跃回，
一式"+(order[random(13)])+"「鲁阳返日」"NOR"，右手食指疾出，指向$n的$l",
	"force" : 120,
	"dodge" : 25,
	"damage": 200,
	"lvl" : 20,
	"skill_name" : "鲁阳返日",
	"damage_type" : "内伤"
]),
([	"action" : "$N向左踏出一步，左手轻扬，右手食指挟着雄浑内力疾点$n的$l，
招式光明坦荡，正是一式"+(order[random(13)])+"「阳春白雪」"NOR"",
	"force" : 160,
	"dodge" : 20,
	"damage": 140,
	"lvl" : 40,
	"skill_name" : "阳春白雪",
	"damage_type" : "内伤"
]),
([	"action" : "$N身影飘起，一式"+(order[random(13)])+"「阳钩挥天」"NOR"，自上而下，左脚弯曲如钩，踹
向$n的右肩，$n侧身相避，$N右手趁势点向$n的$l",
	"force" : 190,
	"dodge" : 30,
	"damage": 150,
	"lvl" : 60,
	"skill_name" : "阳钩挥天",
	"damage_type" : "内伤"
]),
([	"action" : "只见$N脸上忽地一红，左手一收，一式"+(order[random(13)])+"「烈日骄阳」"NOR"，右手食指
斜指，向$n的$l点去",
	"force" : 220,
	"dodge" : 30,
	"damage": 270,
	"lvl" : 70,
	"skill_name" : "烈日骄阳",
	"damage_type" : "内伤"
]),
([	"action" : "$N左掌斜削，突然间变掌为指，嗤的一声响，一式"+(order[random(13)])+"「丹凤朝阳」"NOR"，
使出一阳指力，疾点$n的$l",
	"force" : 250,
	"dodge" : 20,
	"damage": 280,
	"lvl" : 90,
	"skill_name" : "丹凤朝阳",
	"damage_type" : "内伤"
]),
([	"action" : "$N反身一跃，闪身到$n背后，左膝一屈，右手食指回身一式"+(order[random(13)])+"「阴
阳交错」"NOR"，射向$n的后脑",
	"force" : 280,                                                  
	"dodge" : 25,
	"damage": 200,
	"lvl" : 100,
	"skill_name" : "阴阳交错",
	"damage_type" : "内伤"
]),
([  "action" : "$N一声大吼, 一式"+(order[random(13)])+"「三阳开泰」"NOR"，用尽全力向$n的$l点去",
	"force" : 300,
	"dodge" : 10,
	"damage": 320,
	"lvl" : 130,
	"skill_name" : "三阳开泰",
	"damage_type" : "内伤"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_combine(string combo) { return combo=="haotian-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练一阳指必须空手。\n");
	if (me->query("gender") != "男性")
		return notify_fail("你阳气不足，无法学一阳指。\n");
	if ((int)me->query("max_neili") < 700)
		return notify_fail("你的内力太弱，无法练一阳指。\n");
	if ((int)me->query_skill("kurong-changong", 1) > 80 ||
	    (int)me->query_skill("xiantian-qigong", 1) > 80)
		return 1;
	else
		return notify_fail("你的本门内功火候不够，无法学一阳指。\n");
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
	level   = (int) me->query_skill("sun-finger", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("你的内力不够练一阳指!\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"sun-finger/" + action;
}
int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("kurong-changong",1);
        skill = me->query_skill("kurong-changong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "kurong-changong")
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;

if (me->query("qi") <= me->query("max_qi"))
{
me->add("qi",damage2);
}

if (me->query("eff_qi") <= me->query("max_qi"))
{
me->add("eff_qi",damage2);
}



msg = HIG"$N 深吸一口气！施展开一阳指诀，以纯阳指力遍布全身! 脸色红润多了。\n"NOR;
           if (!ob->is_busy() && random(3)==0)
{
msg += HIY"$n"+HIY+"被$N的纯阳指力反点! 结果点中了 "+ xue_name[random(sizeof(xue_name))] +NOR;
                ob->apply_condition("yyz_damage",30);
                ob->start_busy(3);  
}

//msg += "$n的力道被太极拳借力打力反击回来！\n",  
           message_vision(msg, me, ob);
           return j;
}      
}
