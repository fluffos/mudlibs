// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// danyingzi
// 丹奇风
// 桃花岛第二代弟子
// 7722248
// 男性
// strike
// 万象手剑





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N化掌为剑，使出一式「追风」，身随掌走，其势迅猛，其速如风，对$n的招式竟是不闪不避，径直削向周颠的小腹！",
"force" :60,
"damage" :40,
"damage_type": "内伤",
"lvl" : 0,
"skill_name" : "追风"
]),
// ZHAOSHI :1

([
"action" :"$N腾空飞起，从空而降，一式「落日」，双掌如剑，两剑齐出，令$n无可躲藏，直攻向$n面门",
"force" :90,
"damage" :60,
"damage_type": "内伤",
"lvl" : 1,
"skill_name" : "落日"
]),
// ZHAOSHI :2

([
"action" :"$N指尖一挺，丹田中提一口真气，一式「逐月」，以通臂之势，手剑由下往上，掌劲气直逼$n小腹而去！",
"force" :120,
"damage" :80,
"damage_type": "内伤",
"lvl" : 2,
"skill_name" : "逐月"
]),
// ZHAOSHI :3

([
"action" :"$N一式「摘星」，掌如利剑闪动点$n的全身三十六道要穴！",
"force" :150,
"damage" :100,
"damage_type": "内伤",
"lvl" : 3,
"skill_name" : "摘星"
]),
// ZHAOSHI :4

([
"action" :"$N身子滴溜溜的打了半个圈子，手臂一挺，丹田中提一口真气，掌上所附真力递增，青芒犹似长蛇般伸缩不定，蓦地掌风突盛，一式「长歌」刺向$n的小腹！！",
"force" :180,
"damage" :120,
"damage_type": "内伤",
"lvl" : 4,
"skill_name" : "长歌"
]),
// ZHAOSHI :5

([
"action" :"$N施展出「朗月」，手握钢剑面色阴沉，$n只看得一惊，却见一道剑影犹如龙游般袭向自己的胸口，而自己却没看清$N何时出的手！！！",
"force" :210,
"damage" :140,
"damage_type": "内伤",
"lvl" : 5,
"skill_name" : "朗月"
]),
// ZHAOSHI :6

([
"action" :"$N舞动双掌，一招「虎啸」，如飞星人如闪电，人剑合一，扑向$n的腰间！",
"force" :240,
"damage" :160,
"damage_type": "内伤",
"lvl" : 6,
"skill_name" : "虎啸"
]),
// ZHAOSHI :7

([
"action" :"$N两掌化剑，一招「狼嚎」，掌风如云，笼罩了杨逍的胸口，令人不知手剑来自何方！",
"force" :270,
"damage" :180,
"damage_type": "内伤",
"lvl" : 7,
"skill_name" : "狼嚎"
]),
// ZHAOSHI :8

([
"action" :"$N脚步踉踉跄跄，看似已摇摇欲坠，实则足踩九宫，一招「龙吟」，平平淡淡，若有若无地刺向$n的左脚！",
"force" :300,
"damage" :200,
"damage_type": "内伤",
"lvl" : 8,
"skill_name" : "龙吟"
]),
// ZHAOSHI :9

([
"action" :"$N一啸冲天，施展绝技「飘雪」，$n眼前仿佛突然出现了满天的$N，一掌即出，后浪推前浪，两波劲力合击$N！$n已经分不清$N使的是剑是掌！",
"force" :330,
"damage" :220,
"damage_type": "内伤",
"lvl" : 9,
"skill_name" : "飘雪"
]),
 });
// ZHAOSHI :10
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"万象手剑"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"万象手剑"+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage== "strike" || usage=="parry"; }
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
    level = (int)me->query_skill("wanxiang-strike",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 25 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("你的内力不够了，休息一下再练吧。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!
