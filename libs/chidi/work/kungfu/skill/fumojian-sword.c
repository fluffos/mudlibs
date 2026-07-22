// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// hammer
// 锤子
// 普通百姓
// 10000248
// 女性
// sword
// 伏魔剑





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N一剑戳向$n的颈部，结果$n的颈部被$N戳了一个大洞。结果看见了对面的太阳。",
"force" :50,
"dodge" :20,
"damage_type": "刺伤",
"lvl" : 0,
"skill_name" : "起手式"
]),
// ZHAOSHI :1

([
"action" :"只见$N手上的剑芒飞闪，忽然之间一股冲天剑气直奔$n的面门。结果在$n的面门留下了一道深可见骨的伤口！！！！",
"force" :80,
"dodge" :10,
"damage_type": "刺伤",
"lvl" : 12,
"skill_name" : "必杀式"
]),
 });
// ZHAOSHI :2
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"伏魔剑"+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
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
    level = (int)me->query_skill("fumojian-sword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword") return notify_fail("你使用的武器不对。\n");	if( (int)me->query("qi") < 25 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("你的内力不够了，休息一下再练吧。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!
