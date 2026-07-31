// dongyang-dao 神谷活心流
#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *action = ({
([  "action": "$N大喝一声，一式"+(order[random(13)])+"「 唐竹」"NOR"手中$w直劈下来，带起一阵风",
    "force" : 40,
    "attack": 30,
    "dodge" : 10,
    "lvl"   : 0,
    "damage": 95,
    "skill_name" : "唐竹",
    "damage_type" : "割伤"
]),
([  "action": "$N突然横切，一式"+(order[random(13)])+"「 袈裟斩」"NOR"划向$n的$l",
    "force" : 80,
    "attack": 35,
    "dodge" : 10,
    "damage": 110,
    "lvl"   : 10,
    "skill_name" : "袈裟斩",
    "damage_type" : "割伤"
]),
([  "action": "$N手中的$w连续变换几个方向，一式"+(order[random(13)])+"「 左刺」"NOR"最后突然直刺$n的$l",
    "force" : 110,
    "attack": 40,
    "dodge" : 15,
    "damage": 110,
    "lvl"   : 30,
    "skill_name" : "左刺",
    "damage_type" : "刺伤"
]),
([  "action": "$N手中的$w猛然旋转，一式"+(order[random(13)])+"「 右刺」"NOR"舞起一团刀影，直逼$n",
    "force" : 130,
    "attack": 45,
    "dodge" : 25,
    "damage": 125,
    "lvl"   : 50,
    "skill_name" : "右刺",
    "damage_type" : "割伤"
]),
([  "action": "$N手中$w一沉，一式"+(order[random(13)])+"「 左切上」"NOR"双手持刃拦腰反切，砍向$n的$l",
    "force" : 140,
    "attack": 40,
    "dodge" : 20,
    "damage": 125,
    "lvl"   : 80,
    "skill_name" : "左切上",
    "damage_type" : "割伤"
]),
([  "action": "$N长啸一声，一式"+(order[random(13)])+"「 右切上」"NOR"手中的$w不住的晃动，宛若三把刀劈向$n",
    "force" : 180,
    "attack": 45,
    "dodge" : 25,
    "damage": 135,
    "lvl"   : 100,
    "skill_name" : "右切上",
    "damage_type" : "割伤"
]),
([  "action": "$N一转身，一式"+(order[random(13)])+"「 逆风」"NOR"把背后全被卖给$n，突然双手一转，$w从$N腰侧刺了出来",
    "force" : 200,
    "attack": 45,
    "dodge" : 15,
    "damage": 140,
    "lvl"   : 120,
    "skill_name" : "逆风",
    "damage_type" : "刺伤"
]),
([  "action": "$N猛然前袭，一式"+(order[random(13)])+"「 刺突剑」"NOR"手中$w化作一道刀芒闪电般的刺向$n",
    "force" : 210,
    "attack": 50,
    "dodge" : 30,
    "damage": 160,
    "lvl"   : 150,
    "skill_name" : "刺突剑",
    "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; } 

int valid_learn(object me)
{
object ob;
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力不够。\n");

    if ((int)me->query_skill("force") < 30)
        return notify_fail("你的内功火候不够。\n");

    if ((int)me->query_skill("blade", 1) < (int)me->query_skill("huoxinliu-jianfa", 1))
        return notify_fail("你的基本刀法水平有限，无法领会更高深的神谷活心流。\n");

   if( (string)me->query_skill_mapped("force")!= "shayi-xinfa")
        return notify_fail("神谷活心流必须配合杀意心法才能练。\n");
    if( !(ob = me->query_temp("weapon"))
    ||      (string)ob->query("skill_type") != "blade" )
        return notify_fail("你必须先找一把刀才能练神谷活心流。\n");

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
        object target;

        level   = (int) me->query_skill("huoxinliu-jianfa",1);
        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(6)==1 && random(level) > 180)
	{
		return ([
		"action": RED""+(order[random(13)])+"「  牙突一式! 」"NOR""+HIY"$N突然加速！刺出后水平横扫,追击躲闪的$n!"NOR,
		"force" : 550+random(200),
                "attack" : 50,
		"dodge" : 50,
		"damage": 550+random(200),
	        "skill_name" : "牙突一式!",
		"damage_type" : "刺伤" ]);
	}
	if( random(6)==1 && random(level) > 190)
	{
		return ([
		"action": HIR""+(order[random(13)])+"「  牙突二式! 」"NOR""+HIY"$N突然加速！刀举头上,刺出后向$n运动劈下! "NOR,
		"force" : 550+random(200),
                "attack" : 50,
		"dodge" : 70,
		"damage": 550+random(200),
	        "skill_name" : "牙突二式!",
		"damage_type" : "刺伤" ]);
	}
	if( random(6)==1 && random(level) > 200)
	{
		return ([
		"action": HIM""+(order[random(13)])+"「  牙突三式! 」"NOR""+HIY"$N突然加速！由下刺上,对跃起的$n使出牙突,这是是对空的招式！"NOR,
		"force" : 550+random(200),
                "attack" : 90,
		"dodge" : 50,
		"damage": 550+random(200),
	        "skill_name" : "牙突一式!",
		"damage_type" : "刺伤" ]);
	}
	if( random(6)==1 && random(level) > 240)
	{
		return ([
		"action": HIW""+(order[random(13)])+"「  牙突零式! 」"NOR""+HIY"$N在离$n极近距离猛的将刀刺出,威力巨大,这乃是一招必杀技 ！"NOR,
		"force" : 650+random(200),
                "attack" : 120,
		"dodge" : 50,
		"damage": 650+random(200),
	        "skill_name" : "牙突一式!",
		"damage_type" : "刺伤" ]);
	}
 
  
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("你使用的武器不对。\n");

    if ((int)me->query("qi") <750)
        return notify_fail("你的体力不够练神谷活心流。\n");

    if ((int)me->query("neili") < 55)
        return notify_fail("你的内力不够练神谷活心流。\n");

    me->receive_damage("qi", 60);
    me->add("neili", -42);

    return 1;
}
string perform_action_file(string action)
{
        return __DIR__"huoxinliu-jianfa/" + action;
}
