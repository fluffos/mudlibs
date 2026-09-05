// 五禽戏 
// 药师采药时候防身用的 zine 2014/7/17

#include <ansi.h>

inherit FORCE;

string check() { return "force"; }

mapping *action = ({
([      "action": "$N劲由心生，一记『挺身势』，双腿以不可思议的角度像$n踢出",
        "dodge": 15,
        "parry": 20,
        "force": 30,
        "lvl" : 0,
        "damage": 5,
        "damage_type": "内伤"
]),
([      "action":"$N猛喝一声，『撼运势』一出，双掌切向$n颈部",
        "parry": 15,
        "force": 20,
        "lvl" : 0,
        "damage": 5,
        "damage_type": "内伤"
]),
([      "action":"$N蹲下身子，又猛然跃起，正是『出洞势』，全身砸向$n",
        "dodge": 25,
        "force": 20,
        "lvl" : 0,
        "damage": 10,
        "damage_type": "内伤"
]),
([      "action":"$N飞身跃起，一招『摘桃势』，单拳击向$n",
        "dodge": 15,
        "force": 15,
        "lvl" : 0,
        "damage": 5,
        "damage_type": "瘀伤"
]),
([      "action":"$N高高跳起，双手手刀砍向$n太阳穴，好一个『亮翅势』",
        "dodge": 55,
        "force": 5,
        "lvl" : 0,
        "damage": 5,
        "damage_type": "内伤"
]),
});



mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
int valid_enable(string usage)
{
	return usage=="parry" || usage=="force" || usage=="strike" || usage=="hand" || usage=="dodge";
}

int valid_learn(object me)
{
	if (F_PRO->pro_class(me)!="alchemy")
	return notify_fail("只有药师才能练习五禽戏。\n");
	return 1;
}

int practice_skill(object me)
{
	if (F_PRO->pro_class(me)!="alchemy")
	return notify_fail("只有药师才能练习五禽戏。\n");
	if (me->query_temp("weapon")||me->query_temp("secondary_weapon"))
	return notify_fail("五禽戏只有空手练习。\n");
	if ((int)me->query("qi") < 50)
	return notify_fail("你的体力不够练习五禽戏。\n");
	me->receive_damage("qi", 5);
	return 1;
}
string *parry_msg = ({
	WHT+"$n"+WHT+"如熊样浑厚沉稳，笨重中寓轻灵，格开了$N"+WHT+"的"+WHT+"$w。\n"NOR,
	HIW+"$n"+HIW+"仿其昂然挺拔，悠然自得，格开了这一招。\n"NOR,
	HIY+"$n"+HIY+"目光炯炯，摇头摆尾，扑按，转斗，轻松地架住了这一招。\n"NOR,
	YEL+"$n"+YEL+"如鹿样心静体松，姿态舒展，卸去了这一招。\n"NOR,
	CYN+"$n"+CYN+"仿其敏捷好动，表现出纵山跳涧，攀树蹬枝，摘桃献果之神态，完全无视$N"+CYN+"的攻击。\n"NOR,
});