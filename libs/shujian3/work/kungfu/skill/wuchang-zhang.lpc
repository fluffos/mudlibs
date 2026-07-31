// wuchang-zhang.c 无常杖法

inherit SKILL;

mapping *action = ({
([
	"action":"$N微一躬身，一招「庸人自扰」，$w带着刺耳的吱吱声，擦地扫向$n的脚踝",
	"lvl" : 0,
	"skill_name" : "庸人自扰",
	"damage_type":"挫伤"
]),
([
	"action":"$N一招「想入非非」，右手托住杖端，左掌居中一击，令其凭惯性倒向$n的肩头",
	"lvl" : 20,
	"skill_name" : "想入非非",
	"damage_type":"挫伤"
]),
([
	"action":"$N一招「六神不安」，举起$w乒乒乓乓地满地乱敲，让$n左闪右避，狼狈不堪",
	"lvl" : 40,
	"skill_name" : "六神不安",
	"damage_type":"挫伤"
]),
([
	"action":"$N一招「面无人色」，举起$w，呆呆地盯了一会，突然猛地一杖打向$n的$l",
	"lvl" : 50,
	"skill_name" : "面无人色",
	"damage_type":"挫伤"
]),
([
	"action":"$N将$w顶住自己的胸膛，一端指向$n，一招「心惊肉跳」，大声叫喊着冲向$n",
	"lvl" : 60,
	"skill_name" : "心惊肉跳",
	"damage_type":"挫伤"
]),
([
	"action":"$N一招「行尸走肉」，全身僵直，蹦跳着持杖前行，冷不防举杖拦腰向$n劈去",
	"lvl" : 80,
	"skill_name" : "行尸走肉",
	"damage_type":"挫伤"
]),
([
	"action":"$N面带戚色，一招「饮恨吞声」，趁$n说话间，一杖向$n张大的嘴巴捅了过去",
	"lvl" : 90,
	"skill_name" : "饮恨吞声",
	"damage_type":"挫伤"
]),
([
	"action":"$N一招「力不从心」，假意将$w摔落地上，待$n行来，一脚勾起，击向$n的$l",
	"lvl" : 100,
	"skill_name" : "力不从心",
	"damage_type":"挫伤"
]),
([
	"action":"$N伏地装死，一招「穷途没路」，一个翻滚，身下$w往横里打出，挥向$n的裆部",
	"lvl" : 110,
	"skill_name" : "穷途没路",
	"damage_type":"挫伤"
]),
([
	"action":"$N一招「呆若木鸡」，身不动，脚不移，$w却直飞半空，不偏不倚地砸向$n的$l",
	"lvl" : 120,
	"skill_name" : "呆若木鸡",
	"damage_type":"挫伤"
]),
([
	"action":"$N高举$w，一招「人鬼殊途」，身形如鬼魅般飘出，对准$n的天灵盖一杖打下",
	"lvl" : 130,
	"skill_name" : "人鬼殊途",
	"damage_type":"挫伤"
]),
([
	"action":"$N一招「我入地狱」，单腿独立，$w舞成千百根相似，根根砸向$n全身各处要害",
	"lvl" : 150,
	"skill_name" : "我入地狱",
	"damage_type":"挫伤"
]),
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");
	if ( me->query("max_neili") < 800)
		return notify_fail("你的内力不够。\n");
	if ( me->query_skill("yijin-jing", 1) < 80)
		return notify_fail("你的易筋经内功火候太浅。\n");
	if ( me->query_skill("pudu-zhang",1) <=100)
		return notify_fail("你的普渡杖法的基本功欠佳，无法学习无常杖法。\n");
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
	int i, level, j;
	level   = (int) me->query_skill("wuchang-zhang",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"damage_type": action[j]["damage_type"],
				"lvl": action[j]["lvl"],
				"force": 150 + random(300),
				"dodge": random(30),
				"damage": 60 + random(100),
				"parry": random(30),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("wuchang-zhang", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 40 || me->query("neili") < 20)
		return notify_fail("你的体力不够练无常杖法。\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}
