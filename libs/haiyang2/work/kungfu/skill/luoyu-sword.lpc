// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// qingxin
// 月夜随风
// 白驼山派第二代弟子
// 2932532
// 男性
// sword
// 落羽神恋曲





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N猛然洒出雪羽降尘袭向正前方扑来的三道红光，飞羽流星也在顷刻间刺破身后四道血红的虚影，但听见一阵细微的碎裂声，于红光中现出了$n破碎的身影",
"force" :60,
"damage" :40,
"damage_type": "刺伤",
"lvl" : 0,
"skill_name" : "禁断之章"
]),
// ZHAOSHI :1

([
"action" :"看似只刺出一剑，$N却在剑尖的微颤中瞬间划出四道「冷月无声」，一道袭向$n的前胸，一道袭向$n的膝盖，另外两道则分别向$n身体两侧划去",
"force" :90,
"damage" :60,
"damage_type": "刺伤",
"lvl" : 1,
"skill_name" : "冷月无声"
]),
// ZHAOSHI :2

([
"action" :"霎时一颗火红的光球浮现于$N的掌中，随著$N的手指轻灵的舞动，突然之间，竟化作一道璀璨的血色流星，直奔$n而去",
"force" :120,
"damage" :80,
"damage_type": "刺伤",
"lvl" : 2,
"skill_name" : "浮尘落羽"
]),
 });
// ZHAOSHI :3
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"落羽神恋曲"+"。\n");
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
    level = (int)me->query_skill("luoyu-sword",1);
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
