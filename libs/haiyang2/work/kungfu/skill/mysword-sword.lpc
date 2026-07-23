// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// mylove
// 西红柿蛋汤
// 唐门第九代弟子
// 24763463
// 男性
// sword
// 穿心透骨剑





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N忽然身形一变，手中的长剑划出无数道剑影，分别袭向$n的要穴！第一剑：幽门穴",
"force" :60,
"damage" :40,
"damage_type": "刺伤",
"lvl" : 0,
"skill_name" : "穿心透骨剑"
]),
// ZHAOSHI :1

([
"action" :"$N忽然身形一变，手中的长剑划出无数道剑影，分别袭向$n的要穴！第一剑：承浆穴",
"force" :90,
"damage" :60,
"damage_type": "刺伤",
"lvl" : 1,
"skill_name" : "穿心透骨剑二"
]),
// ZHAOSHI :2

([
"action" :"$N忽然身形一变，手中的长剑划出无数道剑影，分别袭向$n的要穴！第一剑：膻中穴",
"force" :120,
"damage" :80,
"damage_type": "刺伤",
"lvl" : 2,
"skill_name" : "穿心透骨剑三"
]),
// ZHAOSHI :3

([
"action" :"$N忽然身形一变，手中的长剑划出无数道剑影，分别袭向$n的要穴！第四剑：章门穴",
"force" :150,
"damage" :100,
"damage_type": "刺伤",
"lvl" : 3,
"skill_name" : "穿心透骨剑四"
]),
// ZHAOSHI :4

([
"action" :"$N忽然身形一变，手中的长剑划出无数道剑影，分别袭向$n的要穴！第五剑：紫宫穴",
"force" :180,
"damage" :120,
"damage_type": "刺伤",
"lvl" : 4,
"skill_name" : "穿心透骨剑五"
]),
// ZHAOSHI :5

([
"action" :"$N忽然身形一变，手中的长剑划出无数道剑影，分别袭向星星的要穴！第六剑：银星如雨！",
"force" :210,
"damage" :140,
"damage_type": "刺伤",
"lvl" : 5,
"skill_name" : "穿心透骨剑六"
]),
 });
// ZHAOSHI :6
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"穿心透骨剑"+"。\n");
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
    level = (int)me->query_skill("mysword-sword",1);
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
