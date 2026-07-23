// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// danyingzi
// 丹奇风
// 桃花岛第二代弟子
// 7313837
// 男性
// sword
// 万象剑法





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N凌空一跃，以风一样的速度攻向$n，一式「追风」，剑尖直指$n心口",
"force" :60,
"damage" :40,
"damage_type": "刺伤",
"lvl" : 0,
"skill_name" : "追风"
]),
// ZHAOSHI :1

([
"action" :"$N忽然高高跃起，从天而降攻向$n，一式「落日」，剑尖直指$n脑门",
"force" :90,
"damage" :60,
"damage_type": "刺伤",
"lvl" : 1,
"skill_name" : "落日"
]),
// ZHAOSHI :2

([
"action" :"$N钢剑一挺，丹田中提一口真气，一式「逐月」，以通臂之势，剑花由下往上，剑气直逼$n小腹而去！",
"force" :120,
"damage" :80,
"damage_type": "刺伤",
"lvl" : 2,
"skill_name" : "逐月"
]),
 });
// ZHAOSHI :3
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"万象剑法"+"。\n");
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
    level = (int)me->query_skill("wanxiangjian-sword",1);
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
